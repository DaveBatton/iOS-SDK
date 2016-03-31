//
//  TCAppDelegate.m
//  LifePics Demo
//
//  Copyright (c) 2014 Taylor Corp. All rights reserved.
//

#import "TCAppDelegate.h"
#import "TCDevTools.h"

#import <Crashlytics/Crashlytics.h>
#import <Foundation/NSKeyedArchiver.h>
#import <FBSDKCoreKit/FBSDKCoreKit.h>

#import <LifePics/NSBundle+LPFAdditions.h>
#import <LifePics/LPFMenuViewController.h>
#import <LifePics/PureLayout.h>

@interface TCAppDelegate ()

@property (nonatomic) BOOL isRestoring;

@end


@implementation TCAppDelegate

#pragma mark - UIApplicationDelegate
- (void)applicationWillResignActive:(UIApplication *)application
{
    LPFOrderViewController* orderController = self.orderViewController;
    orderController = orderController?orderController : [LPFOrderViewController sharedInstance];
    if (orderController) {
        [orderController saveCartPlist];
    }
}

- (BOOL)application:(UIApplication *)application willFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    [UIApplication sharedApplication].statusBarHidden = NO;
    [self.window makeKeyAndVisible];
    self.isRestoring = NO;
    [self setSlideMenuController];
    return YES;
}


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    [[FBSDKApplicationDelegate sharedInstance] application:application
                             didFinishLaunchingWithOptions:launchOptions];
    int forStaging = [[[[NSBundle mainBundle] infoDictionary] objectForKey:@"ForStaging"] intValue];
    [LPFSessionManager sharedManager].useStagingServer = forStaging==0? NO:YES;
    
    // If no main storyboard is specified, add a window for the restoration process to use.
    if (self.window == nil) {
        self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
        self.orderViewController = [[LPFOrderViewController alloc] init];
        self.slideMenuController.contentViewController = self.orderViewController;
        self.window.rootViewController = self.slideMenuController;
        [self.window makeKeyAndVisible];
    }
    
#if TARGET_IPHONE_SIMULATOR
    [TCDevTools offerToAddTestPhotos];
#endif
    
#ifndef DEBUG
    [Crashlytics startWithAPIKey:@"65adba999dd811077ed451dfdb405b965c5a21bb"];
#endif
    
    [LPFOrderViewController prefetchImages];
    
    // If no main storyboard is specified, start with the LifePics order view controller.
    BOOL displayOrderViewAtLaunch = [[[NSBundle mainBundle] objectForInfoDictionaryKey:@"TCDisplayOrderViewAtLaunch"] boolValue];
    
    if (self.isRestoring == NO) {
        if (displayOrderViewAtLaunch) {
            self.orderViewController = [[LPFOrderViewController alloc] init];
            self.orderViewController.shouldDisplayCancelButton = !displayOrderViewAtLaunch;
            self.slideMenuController.contentViewController = self.orderViewController;
            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)((0.0f) * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                
                self.window.rootViewController = self.slideMenuController;
            });
        }
        
    }
    
    return YES;
}

- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation
{
    // Instagram handling
    NSString *instagramKey = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"LPFInstagramKey"];
    NSString *instagramUrlPrefix = [NSString stringWithFormat:@"ig%@://", instagramKey];
    if ([[url absoluteString] hasPrefix:instagramUrlPrefix]) {
        return [LPFOrderViewController openURL:url sourceApplication:sourceApplication];
    }
    
    // Facebook handling
    NSString *facebookKey = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"FacebookAppID"];
    NSString *facebookUrlPrefix = [NSString stringWithFormat:@"fb%@://", facebookKey];
    if ([[url absoluteString] hasPrefix:facebookUrlPrefix]) {
        return [[FBSDKApplicationDelegate sharedInstance] application:application
                                                              openURL:url
                                                    sourceApplication:sourceApplication
                                                           annotation:annotation
                ];
    }
    
    // Flickr handling
    NSString *flickrKey = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"LPFFlickrKey"];
    NSString *flickrUrlPrefix = [NSString stringWithFormat:@"flickr%@://", flickrKey];
    if ([[url absoluteString] hasPrefix:flickrUrlPrefix]) {
        return [LPFOrderViewController openURL:url sourceApplication:sourceApplication];
    }
    
    return NO;
}


- (BOOL)application:(UIApplication *)application shouldSaveApplicationState:(NSCoder *)coder
{
    return NO;
}


- (BOOL)application:(UIApplication *)application shouldRestoreApplicationState:(NSCoder *)coder
{
    BOOL shouldRestore = NO;
    self.isRestoring = shouldRestore;
    return shouldRestore;
}


- (UIViewController *)application:(UIApplication *)application viewControllerWithRestorationIdentifierPath:(NSArray *)identifierComponents coder:(NSCoder *)coder
{
    return nil;
}


#pragma mark - Private
- (void)setSlideMenuController
{
    APLSlideMenuViewController *slideMenuController = [[APLSlideMenuViewController alloc] init];
    [LPFOrderViewController setSlideMenuController: slideMenuController];
    slideMenuController.bouncing = YES;
    slideMenuController.gestureSupport = APLSlideMenuGestureSupportDrag;
    slideMenuController.separatorColor = [UIColor grayColor];
    if ([LPFOrderViewController sharedInstance]!=nil) {
        self.orderViewController = [LPFOrderViewController sharedInstance];
        slideMenuController.contentViewController = self.orderViewController;
    }
    UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"LPFMenu" bundle:[NSBundle lpfBundle]];
    LPFMenuViewController *vc = [storyboard instantiateViewControllerWithIdentifier:@"LPFMenuViewController"];
    slideMenuController.leftMenuViewController = vc;
    slideMenuController.slideDelegate = vc;
    self.slideMenuController = slideMenuController;
}



@end
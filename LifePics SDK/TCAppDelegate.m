//
//  TCAppDelegate.m
//  LifePics Demo
//
//  Copyright (c) 2014 Taylor Corp. All rights reserved.
//

#import "TCAppDelegate.h"
#import "TCDevTools.h"
#import <LifePics/LifePics.h>

@implementation TCAppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    #if TARGET_IPHONE_SIMULATOR
        [TCDevTools offerToAddTestPhotos];
    #endif

    return YES;
}


- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation
{
    // Instagramhandling
    NSString *instagramKey = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"LPFInstagramKey"];
    NSString *instagramUrlPrefix = [NSString stringWithFormat:@"ig%@://", instagramKey];
    if ([[url absoluteString] hasPrefix:instagramUrlPrefix]) {
        return [LPFOrderViewController openURL:url sourceApplication:sourceApplication];
    }

    // facebook handling
    NSString *facebookKey = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"FacebookAppID"];
    NSString *facebookUrlPrefix = [NSString stringWithFormat:@"fb%@://", facebookKey];
    if ([[url absoluteString] hasPrefix:facebookUrlPrefix]) {
        return [LPFOrderViewController openURL:url sourceApplication:sourceApplication];
    }

    // flickr handling
    NSString *flickrKey = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"LPFFlickrKey"];
    NSString *flickrUrlPrefix = [NSString stringWithFormat:@"flickr%@://", flickrKey];
    if ([[url absoluteString] hasPrefix:flickrUrlPrefix]) {
        return [LPFOrderViewController openURL:url sourceApplication:sourceApplication];
    }

    return NO;
}


@end

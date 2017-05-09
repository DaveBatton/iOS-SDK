//
//  LPFViewController.h
//  LifePics
//
//  Created by Dave Batton on 3/14/14.
//  Copyright (c) 2014 Taylor Corp. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <LifePics/LifePics.h>
#import "UIFont+LPFAdditions.h"
#import "GAI.h"
#import "GAIDictionaryBuilder.h"
#import "GAIFields.h"
#import "LPFGoogleAnalyticsHelper.h"

@class LPFProgressMessageView;

@interface LPFViewController : UIViewController

@property (nonatomic, strong) IBOutlet UIScrollView *contentView;  // Automatically resized when the keyboard appears. Automatically added to the view.
@property (nonatomic, weak) IBOutlet NSLayoutConstraint *contentViewWidthConstraint;

@property (nonatomic, readonly) LPFOrderViewController *orderViewController;
@property (nonatomic, readonly) LPFImageSelectionGroup *selectedImagesGroup;
@property (strong, nonatomic, readonly) NSBundle *resourceBundle;
@property (strong, nonatomic, readonly) NSString *resourceName;
@property (strong, nonatomic) UIView *popoverView;
@property (nonatomic, weak) id<LPFNavigationItemsCustomInSideDelegate> navigationItemsCustomInSideDelegate;
@property (strong, nonatomic) NSString *screenName;

//hxliu from NL added for bug #4087
@property (nonatomic, strong) UIActivityIndicatorView *activity;

- (void)showActivity;
- (void)hideActivity;
- (void)displayProgressMessage:(NSString *)message;
- (void)dismissProgressMessage;
- (void)handleError:(NSError *)error;
- (NSString *)goForwardButtonTitle;
- (UIImage *)goForwardButtonImage;
- (BOOL)inverseForwardButtonColors;
- (BOOL)canGoForward;
- (void)goForward;
- (BOOL)shouldGoBack;
- (BOOL)shouldShowBackOnNavBar;
- (void)hidePopoverView;
- (void)showPopoverViewWithView:(UIView* )view;

- (void)presentInfoView:(UIView *)view inViewController:(UIViewController *)viewController;
- (void)presentInfoView:(UIView *)view inViewController:(UIViewController *)viewController withFixFrame:(CGRect)rect;

- (BOOL)supportAPLSlideMenuGestureSupportDrag;
-(void)login:(void (^)()) acceptedBlock  deniedBlock:(void (^)()) deniedBlock;
@end

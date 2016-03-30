//
//  TCAppDelegate.h
//  LifePics Demo
//
//  Copyright (c) 2014 Taylor Corp. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <LifePics/LifePics.h>
#import <LifePics/APLSlideMenuViewController.h>

@interface TCAppDelegate : UIResponder <UIApplicationDelegate>

@property (nonatomic, strong) LPFOrderViewController *orderViewController;
@property (strong, nonatomic) UIWindow *window;
@property (nonatomic, strong) APLSlideMenuViewController *slideMenuController;

@end

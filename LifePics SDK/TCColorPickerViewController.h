//
//  TCColorPickerViewController.h
//  LifePics SDK
//
//  Copyright (c) 2014 Taylor Corp. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol TCColorPickerViewControllerDelegate;

@interface TCColorPickerViewController : UIViewController

@property (nonatomic, weak) id<TCColorPickerViewControllerDelegate> delegate;
@property (nonatomic, copy) UIColor *color;
@property (nonatomic, copy) NSDictionary *userInfo;

@end


@protocol TCColorPickerViewControllerDelegate <NSObject>

@optional
- (void)colorPickerViewController:(TCColorPickerViewController *)viewController didSelectColor:(UIColor *)color;

@end
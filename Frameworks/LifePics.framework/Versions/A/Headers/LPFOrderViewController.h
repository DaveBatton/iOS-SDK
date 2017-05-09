//
//  LPFOrderViewController.h
//  LifePics
//
//  Created by Dave Batton on 2/28/14.
//  Copyright (c) 2014 Taylor Corp. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <LifePics/LifePics.h>
#import "BufferedNavigationController.h"  // Fixes the "Unbalanced calls to begin/end appearance transitions..." crashing bug.
#import "LPFCartItem.h"
#import "APLSlideMenuViewController.h"

extern NSString * const LPFOrderViewControllerDidUpdateProductGroupsNotification;
extern NSString * const LPFOrderViewControllerProductGroupsKey;
extern NSString * const LPFCanvasProductGroupsKey;

@protocol LPFImageDataSource;
@class LPFFloatingNavigationView;
@class LPFStore;
@class LPFImageSelectionGroup;
@class LPFSizeQuantityViewController;
@class LPFPaymentManager;
@class LPFProductGroup;
@class LPFCanvasConfigureViewController;
@class LPFCartItem;
@class LPFProduct;

@protocol LPFOrderViewControllerDelegate;

@interface LPFOrderViewController : BufferedNavigationController

@property (nonatomic, weak) id<LPFOrderViewControllerDelegate> delegate;
@property (nonatomic, strong) LPFFloatingNavigationView *floatingNavigationView;
@property (nonatomic, strong) LPFProductGroup *selectedProductGroup;
@property (nonatomic, strong) LPFProduct *selectedProduct;
@property (nonatomic, readonly) LPFCart *cart;
@property (nonatomic, strong) LPFImageSelectionGroup *selectedImagesGroup;
@property (nonatomic, readonly) UIEdgeInsets suggestedContentInset;
@property (nonatomic, readonly) UIEdgeInsets suggestedLowerContentInset;
@property (nonatomic, copy) UIColor *primaryColor;  // Default is green. Set to nil to restore default.
@property (nonatomic, copy) UIColor *secondaryColor;  // Default is orange. Set to nil to restore default.
@property (nonatomic, copy) UIColor *titleBarBackgroundColor;
@property (nonatomic, copy) UIColor *titleBarTitleColor;
@property (nonatomic, readonly) LPFStore *genericStore;
@property (nonatomic, readonly) LPFStore *shipToHomeStore;
@property (nonatomic, readonly) LPFStore *pickupInStore;
@property (nonatomic, strong) NSString *pickuppayNowNote;
@property (nonatomic, readonly) LPFPaymentManager *paymentManager;
@property (nonatomic, readonly) BOOL canShipToHome;
@property (nonatomic, readonly) BOOL canPickupLocally;
@property (nonatomic, weak) id<LPFOrderViewControllerDelegate> orderDelegate;
@property (nonatomic, readonly) NSArray *productGroups;
@property (nonatomic) BOOL shouldDisplayCancelButton;

+ (void)prefetchImages;
+ (BOOL)openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication;
+ (LPFOrderViewController*)sharedInstance;
+ (void)setSlideMenuController:(APLSlideMenuViewController*)controller;
+ (APLSlideMenuViewController*)slideMenuController;
+ (BOOL)displayPayOption;
+ (BOOL)forceToUsePayNow;
+ (NSString *)configGroupKey;

- (void)addRightBarItems:(UIViewController *)controller;
- (void)addLeftBarItems:(UIViewController*)controller;
- (void)addBasicLeftBarItems:(UIViewController*)controller;


- (void)saveCartPlist;
- (void)readCartPlist;
- (void)dealWithUserDataByUserDataVersion;
- (BOOL)setGroupForItem:(LPFCartItem*)item;

- (void)updateFloatingNavigationView;
- (void)pushToOrderHistoryViewController:(BOOL)animated;
- (void)pushToCartViewController:(BOOL)animated;
- (LPFSizeQuantityViewController *)popToSizeQuantityViewControllerAnimated:(BOOL)animated;
- (LPFCanvasConfigureViewController *)popToCanvasConfigureViewControllerAnimated:(BOOL)animated;
- (void)popToContinueShoppingViewControllerAnimated:(BOOL)animated;
- (void)popToMyPhotosViewControllerAnimated:(BOOL)animated;
- (void)popToFeedbackControllerAnimated:(BOOL)animated;
- (void)popToSettingsAnimated:(BOOL)animated;
- (instancetype)initWithImageDataSource:(id<LPFImageDataSource>)imageDataSource;
- (BOOL)isReadyToSubmit;
- (void)submitOrderWithProgress:(void (^)(NSString *message, float progress))progressBlock completion:(void (^)(NSError *error))completionBlock;
- (void)resetCart;
- (void)cancel;
- (void)loadConfiguration:(BOOL)onlyReadCategories;
- (void)GAIonPurchaseCompleted;
- (void)makeCanvasTheInitialScreenWithImage:(UIImage *) image;

@end


@protocol LPFOrderViewControllerDelegate <NSObject>

@optional
- (void)orderViewController:(LPFOrderViewController *)orderViewController didSubmitOrderWithCart:(LPFCart *)cart;
- (BOOL)orderViewControllerShouldCancel:(LPFOrderViewController *)orderViewController;
- (void)orderViewControllerDidCancel:(LPFOrderViewController *)orderViewController;

@end


@protocol LPFNavigationItemsCustomInSideDelegate <NSObject>

@required
- (BOOL)customLeftItemsInside;
- (BOOL)customRightItemsInside;

@optional
- (void)customLeftItems;
- (void)customRightItems;

@end


//
//  LPFCart.h
//  LifePics
//
//  Created by Dave Batton on 2/13/14.
//  Copyright (c) 2014 Taylor Corp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <LifePics/LifePics.h>

@class LPFSessionManager;
@class LPFCartItem;
@class LPFProduct;
@class LPFImage;
@class LPFShippingMethod;
@class LPFAddress;


static NSDictionary *cartInfoDic;
@interface LPFCart : NSObject <NSCopying, NSCoding>
@property (nonatomic, copy) NSString *cartID;  // nil until assigned by the server.
@property (nonatomic) BOOL needsUpload;
@property (nonatomic, copy) NSString *merchantOrderID;  // nil until submitted.
@property (nonatomic, strong, readonly) LPFStore *store;
@property (nonatomic, strong, readonly) NSArray *items;  // LPFCartItems.
@property NSUInteger itemsSummaryCount;
@property (nonatomic, readonly) NSUInteger quantity;
@property (nonatomic, readonly) NSString *itemsDescription;
@property (nonatomic, strong) NSArray *availableShipMethods;  // LPFCartShipMethods.
@property (nonatomic, strong) LPFShippingMethod *shippingMethod;
@property (nonatomic, strong) LPFAddress *shippingAddress;
@property (nonatomic, strong) LPFAddress *billingAddress;
@property (nonatomic, copy) NSString *emailAddress;
@property (nonatomic, copy) NSString *discountCode;
@property (nonatomic, copy) NSDecimalNumber *subtotal;  // Provided by the server after the cart is uploaded. We guess at it before that happens.
@property (nonatomic, copy) NSDecimalNumber *discount;  // Provided by the server after the cart is uploaded.
@property (nonatomic, copy) NSDecimalNumber *taxRate;  // Provided by the server after the cart is uploaded.
@property (nonatomic, copy) NSDecimalNumber *tax;  // Provided by the server after the cart is uploaded.
@property (nonatomic, copy) NSDecimalNumber *total;  // Provided by the server after the cart is uploaded. We guess at it before that happens.
@property (nonatomic, copy) NSDecimalNumber *minimumOrderFee;

- (void)setStore:(LPFStore *)newStore itemsRemovedFromCart:(NSArray **)removedItems;
- (void)emptyCart;
- (LPFCartItem *)addItemWithProduct:(LPFProduct *)product quantity:(NSUInteger)quantity attributes:(NSArray *)attributes images:(NSArray *)images;
- (void)removeItem:(LPFCartItem *)item;
- (void)findCompatibleStoresWithPostalCode:(NSString *)postalCode completion:(void (^)(NSArray *stores, NSError *error))completion;  // Pass a nil postalCode to use current location.
- (BOOL)mustUploadCartToLoadShipMethods;
- (void)loadAvailableShipMethods:(void (^)(NSError *error))completion;
- (BOOL)acceptsDiscountCode;
- (void)applyDiscountCode:(void (^)(NSError *error))completion;
- (void)updateTotals:(void (^)(NSError *error))completion;
- (void)updateWithDictionary:(NSDictionary *)dictionary;
- (BOOL)isReadyToSubmit;
- (BOOL)isShipToHome;
- (void)setItems:(NSArray *)items;
- (void)addItems:(NSArray*)items;
+ (NSDecimalNumber *)caculateSubtotalInLocal:(NSArray*)cartItems;
@end

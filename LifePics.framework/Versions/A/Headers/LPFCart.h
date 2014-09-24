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

@interface LPFCart : NSObject

@property (nonatomic, strong) NSString *orderNumber;  // nil until submitted.
@property (nonatomic, strong, readonly) LPFStore *store;
@property (nonatomic, strong, readonly) NSArray *items;  // LPFCartItems.
@property (nonatomic, readonly) NSUInteger quantity;
@property (nonatomic, readonly) NSDecimalNumber *subtotal;
@property (nonatomic, readonly) NSString *itemsDescription;
@property (nonatomic, copy) NSString *emailAddress;

- (void)setStore:(LPFStore *)newStore itemsRemovedFromCart:(NSArray **)removedItems;
- (void)emptyCart;
- (void)addItemWithProduct:(LPFProduct *)product quantity:(NSUInteger)quantity finish:(LPFFinish)finish images:(NSArray *)images;
- (void)removeItem:(LPFCartItem *)item;
- (void)findCompatibleStoresWithPostalCode:(NSString *)postalCode completion:(void (^)(NSArray *stores, NSError *error))completion;  // Pass a nil postalCode to use current location.

@end

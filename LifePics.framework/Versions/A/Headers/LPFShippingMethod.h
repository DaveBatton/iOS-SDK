//
//  LPFShippingMethod.h
//  LifePics
//
//  Created by Dave Batton on 5/2/14.
//  Copyright (c) 2014 Taylor Corp. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LPFShippingMethod : NSObject <NSCopying>

@property (nonatomic, copy) NSString *shippingMethodID;  // ShippingMethodID - The shipping method's reference number.
@property (nonatomic, copy) NSString *shippingMethodMerchantRelID;  // ShippingMethodMerchantRelID - The merchant specific shipping method reference number.
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *displayName;
@property (nonatomic, copy) NSDecimalNumber *price;
@property (nonatomic, getter = isAvailableForAllProducts) BOOL availableForAllProducts;

+ (instancetype)shippingMethodWithDictionary:(NSDictionary *)dictionary;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end

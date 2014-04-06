//
//  LPFCartItem.h
//  LifePics
//
//  Created by Dave Batton on 2/13/14.
//  Copyright (c) 2014 Taylor Corp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <LifePics/LifePics.h>

@class LPFImage;

@interface LPFCartItem : NSObject

@property (nonatomic, strong) LPFProduct *product;
@property (nonatomic) NSUInteger quantity;
@property (nonatomic, strong) NSArray *images;  // LPFImage objects.
@property (nonatomic) LPFFinish finish;
@property (nonatomic, readonly) NSDecimalNumber *subtotal;
@property (nonatomic, readonly) NSString *itemDescription;  // ie: 8 Prints - 4"x6" Matte

+ (LPFCartItem *)itemWithProduct:(LPFProduct *)product quantity:(NSUInteger)quantity finish:(LPFFinish)finish image:(NSArray *)images;

@end

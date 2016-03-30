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
@class LPFProduct;

@interface LPFCartItem : NSObject <NSCopying, NSCoding>

@property (nonatomic, strong) NSUUID *identifier;  // Local.
@property (nonatomic, copy) NSString *cartItemID;  // From the LifePics API.
@property (nonatomic, strong) LPFProduct *product;
@property (nonatomic) NSUInteger quantity;
@property (nonatomic, strong) NSArray *selectedAttributes;
@property (nonatomic, strong) NSArray *images;  // LPFImage objects.
@property (nonatomic, strong) NSDecimalNumber *subtotal;
@property (nonatomic, readonly) NSString *itemDescription;  // ie: 8 Prints - 4"x6" Matte
@property BOOL changed;

+ (LPFCartItem *)itemWithProduct:(LPFProduct *)product quantity:(NSUInteger)quantity attributes:(NSArray *)attributes image:(NSArray *)images;

- (NSString *)imagesXML;
- (NSString *)attributesXML;
- (NSArray *)imageIDs;
- (NSArray *)attributeIDs;
- (NSComparisonResult)caseInsensitiveCompare:(LPFCartItem *)anotherCartItem;

@end

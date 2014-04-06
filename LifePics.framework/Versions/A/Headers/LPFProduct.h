//
//  AlbumDetails.h
//  LifePics
//
//  Created by Christian Beach on 5/21/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LPFImage.h"

@class LPFProductAttribute;

@interface LPFProduct : NSObject

// Original properties (fixed).
@property (nonatomic, copy) NSString *productID;
@property (nonatomic, copy) NSString *sku;
@property (nonatomic, copy) NSString *description;
@property (nonatomic, copy) NSString *basePrice;
@property (nonatomic, copy) NSString *widthString;
@property (nonatomic, copy) NSString *heightString;
@property (nonatomic, copy) NSString *widthResolution;
@property (nonatomic, copy) NSString *lengthResolution;
@property (nonatomic, copy) NSString *categoryID;
@property (nonatomic, copy) NSString *categoryName;
@property (nonatomic, copy) NSString *previewImage;
@property (nonatomic, copy) NSString *previewText;
@property (nonatomic) BOOL hasMatteFinish;
@property (nonatomic, copy) NSString *matteFinishID;
@property (nonatomic) BOOL hasGlossyFinish;
@property (nonatomic, copy) NSString *glossyFinishID;
@property (nonatomic) NSInteger defaultFinish;
@property (nonatomic, strong) NSMutableArray *attributeIDs;
@property (nonatomic, strong) NSMutableDictionary *attributes;

// New properties.
@property (nonatomic) double width;
@property (nonatomic) double height;
@property (nonatomic, readonly) NSDecimalNumber *basePriceNumber;
@property (nonatomic) LPFImageOrientation imageOrientation;
@property (nonatomic, copy) NSDecimalNumber *matteFinishPriceOffset;
@property (nonatomic, copy) NSDecimalNumber *glossyFinishPriceOffset;

- (void)resetAttributeArrays;
- (NSUInteger)countOfAttributes;
- (LPFProductAttribute *)attributeAtIndex:(unsigned)theIndex;
- (LPFProductAttribute *)attributeWithID:(NSString *)attributeID;
- (void)addAttribute:(LPFProductAttribute *)newAttribute;

//@property (nonatomic, weak) LPFSessionManager *sessionManager;
//@property (nonatomic, readonly) NSString *identifier;
//@property (nonatomic, strong) NSString *productDescription;
//@property (nonatomic, readonly) NSDecimalNumber *price;  // Will be nil if the session has no associated store. May vary depending on selected store.

// Class Methods
+ (LPFProduct *)printProductWithWidth:(double)width height:(double)length;


@end

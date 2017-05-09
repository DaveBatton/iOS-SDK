//
//  LPFStore.h
//  LifePics
//
//  Created by Christian Beach on 5/21/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>

extern NSString * const LPFStoreDidLoadProductsNotification;

@class LPFProduct;
@class LPFCart;
@class LPFProductAttribute;
@class LPFCartItem;

@interface LPFStore : NSObject <NSCoding, MKAnnotation>

@property (nonatomic, copy) NSString *locationID;
@property (nonatomic, copy) NSString *merchantID;
@property (nonatomic, copy) NSString *merchantLogo;
@property (nonatomic, copy) NSString *merchantName;
@property (nonatomic, copy) NSString *storeName;
@property (nonatomic, copy) NSString *address1;
@property (nonatomic, copy) NSString *address2;
@property (nonatomic, copy) NSString *city;
@property (nonatomic, copy) NSString *state;
@property (nonatomic, copy) NSString *postalCode;
@property (nonatomic, copy) NSString *country;
@property (nonatomic, copy) NSString *phoneNumber;
@property (nonatomic, copy) NSString *distance;
@property (nonatomic, copy) NSString *latitude;
@property (nonatomic, copy) NSString *longitude;
@property (nonatomic, copy) NSString *payAtDealerMaxAmount;
@property (nonatomic, copy) NSString *minimumOrderAmount;
@property (nonatomic, copy) NSString *productCategoryID;
@property (nonatomic) BOOL singleFinishOnly;
@property (nonatomic, strong) NSArray *products;  // nil until -loadProducts: is called.
@property (nonatomic, readonly) UIImage *betterMerchantLogo;
@property BOOL isDefaultShipToHomeStore;
@property BOOL isDefaultPickupStore;
// MKAnnotation
@property (nonatomic, readonly) CLLocationCoordinate2D coordinate;
@property (nonatomic, readonly, copy) NSString *title;
@property (nonatomic, readonly, copy) NSString *subtitle;

//it not a value from server,  exists in client only
@property (nonatomic) BOOL isFetchingProducts;

- (void)loadProducts:(void (^)(NSError *error))completionBlock;
//For development only
- (void)loadProductsForMerchantID:(NSString *)merchantID andProductCategoryID:(NSString *)productCategoryID completionBlock:(void (^)(NSError *error))completionBlock;
- (NSString *)fullAddress;
- (NSString *)fullAddressSingleLine;
- (void)call;
- (void)openInMaps;
- (LPFProduct *)productSimilarTo:(LPFProduct *)product;
- (LPFProduct *)productSimilarTo:(LPFProduct *)product attribute:(LPFProductAttribute*)attribute;
- (LPFProduct *)productEqualTo:(LPFProduct *)productToMatch;
- (BOOL)storeCanFulfillCart:(LPFCart *)cart;
- (BOOL)genericStoreCanFulfillCart:(LPFCart *)cart;//only for generic app when searching store.
- (LPFProduct*)canFulfillItemForGenericApp:(LPFCartItem*)item;//only for generic app when searching store.
- (NSDecimalNumber *)subtotalForCart:(LPFCart *)cart;


+ (NSString*)getRadiusInMiles;

@end

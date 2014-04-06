//
//  LPFStore.h
//  LifePics
//
//  Created by Christian Beach on 5/21/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>

@class LPFProduct;
@class LPFCart;

@interface LPFStore : NSObject <MKAnnotation>

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
@property (nonatomic) BOOL singleFinishOnly;
@property (nonatomic, strong) NSArray *products;  // nil until -loadProducts: is called.
@property (nonatomic, readonly) UIImage *betterMerchantLogo;

// MKAnnotation
@property (nonatomic, readonly) CLLocationCoordinate2D coordinate;
@property (nonatomic, readonly, copy) NSString *title;
@property (nonatomic, readonly, copy) NSString *subtitle;

- (void)loadProducts:(void (^)(NSError *error))completionBlock;
- (NSString *)fullAddress;
- (NSString *)fullAddressSingleLine;
- (void)call;
- (void)openInMaps;
- (LPFProduct *)productSimilarTo:(LPFProduct *)product;
- (BOOL)storeCanFulfillCart:(LPFCart *)cart;
- (NSDecimalNumber *)subtotalForCart:(LPFCart *)cart;


@end

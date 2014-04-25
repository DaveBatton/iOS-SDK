//
//  LPFSessionManager.h
//  LifePics
//
//  Created by Dave Batton on 2/12/14.
//  Copyright (c) 2014 Taylor Corp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class LPFCart;
@class LPFStore;
@class LifePicsServices;
@class LPFMSActiveConfig;

@interface LPFSessionManager : NSObject

@property (nonatomic, readonly) NSString *sessionID;
@property (nonatomic, readonly) BOOL isLoggedIn;

@property (nonatomic, readonly) NSString *userID;
@property (nonatomic, copy) NSString *userEmail;
@property (nonatomic, copy) NSString *userPassword;
@property (nonatomic, copy) NSString *userFirstName;
@property (nonatomic, copy) NSString *userLastName;  // Not currently used.
@property (nonatomic, copy) NSString *userPhoneNumber;
@property (nonatomic, readonly) LPFMSActiveConfig *activeConfig;

@property (nonatomic, strong) LifePicsServices *services;  // Hope to hide this before release.

// Class Methods
+ (LPFSessionManager *)sharedManager;

// Public
- (void)beginPartnerSessionWithID:(NSString *)partnerID sourceID:(NSString *)partnerSourceID password:(NSString *)password completion:(void (^)(NSError *error))completionBlock;
- (void)createAccountWithStore:(LPFStore *)store email:(NSString *)email password:(NSString *)password firstName:(NSString *)firstName mayEmail:(BOOL)mayEmail mayEmailPromos:(BOOL)mayEmailPromos completion:(void (^)(NSError *error))completionBlock;
- (void)createTemporaryAccountWithStore:(LPFStore *)store completion:(void (^)(NSError *error))completionBlock;
- (void)loginWithEmail:(NSString *)email password:(NSString *)password completion:(void (^)(NSError *error))completionBlock;
- (void)logOut;
- (void)submitOrderForCart:(LPFCart *)cart completion:(void (^)(NSError *error))completionBlock;

- (void)loadAlbumsCompletion:(void (^)(NSArray *albums, NSError *error))completion;
- (void)loadAlbumImagesForAlbum:(NSString *)albumID completion:(void (^)(NSArray *images, NSError *error))completion;

// Stores
- (void)findStoresNearby:(void (^)(NSArray *stores, NSError *error))completion;
- (void)findStoresNearLocation:(CLLocationCoordinate2D)locationCoordinates completion:(void (^)(NSArray *stores, NSError *error))completion;
- (void)findStoresNearPostalCode:(NSString *)postalCode completion:(void (^)(NSArray *stores, NSError *error))completion;

@end

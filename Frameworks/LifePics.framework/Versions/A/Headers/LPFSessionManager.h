//
//  LPFSessionManager.h
//  LifePics
//
//  Created by Dave Batton on 2/12/14.
//  Copyright (c) 2014 Taylor Corp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "LPFAddress.h"

extern NSString * const LPFSessionManagerDidReceiveLocationAuthorizationStatusChangeNotification;

@class LPFCart;
@class LPFStore;
@class LifePicsServices;
@class LPFMSActiveConfig;
@class LPFNetworking;

@interface LPFSessionManager : NSObject

@property (nonatomic, copy) NSString *sessionID;
@property (nonatomic, readonly) BOOL isLoggedIn;
@property (nonatomic) BOOL useStagingServer;
//hxliu from NL modified userID's attribute, userID will be set value by new api's response.
@property (nonatomic, copy) NSString *userID;
@property (nonatomic, copy) NSString *userEmail;
@property (nonatomic, copy) NSString *userPassword;
@property (nonatomic, copy) NSString *userFirstName;
@property (nonatomic, copy) NSString *userLastName;
@property (nonatomic, copy) NSString *userPhoneNumber;
@property (nonatomic, copy) NSString *userMerchantID;  // We get this when the user logs in. It may not be the merchant ID for the current order.
@property (nonatomic, readonly) LPFMSActiveConfig *activeConfig;

@property (nonatomic, strong) LPFNetworking *networking;
@property (nonatomic, strong) LifePicsServices *services;  // Hope to hide this before release.

// Use in cases where you might not want to show the continue shopping button on the checkout screen, like when passing an image directly to a canvas screen
@property (assign, nonatomic) BOOL shouldHideContinueButton;

//hxliu from NL added for bug #4087
@property (nonatomic, strong) NSArray *productsFromServer;
@property (nonatomic, strong) NSMutableDictionary *catchContents;//easy to access in all of the classes.
@property BOOL continueAsGuest;
// Class Methods
+ (NSString *)versionString;
+ (LPFSessionManager *)sharedManager;
+ (BOOL)isGenericApp;

- (void)startSession;

// Public//DEPRECATED_MSG_ATTRIBUTE("Kilroy was here.")
- (void)createAccountWithStore:(LPFStore *)store email:(NSString *)email password:(NSString *)password firstName:(NSString *)firstName mayEmail:(BOOL)mayEmail mayEmailPromos:(BOOL)mayEmailPromos completion:(void (^)(NSError *error, id response))completionBlock;
- (void)createAccountWithEmail:(NSString *)email password:(NSString *)password firstName:(NSString *)firstName mayEmail:(BOOL)mayEmail mayEmailPromos:(BOOL)mayEmailPromos completion:(void (^)(NSError *error, id response))completionBlock;
//hxliu from NL add 'response' parameter to completionBlock for PBI 38
- (void)createTemporaryAccountWithStore:(LPFStore *)store completion:(void (^)(NSError *error, id response))completionBlock;
- (void)loginWithEmail:(NSString *)email password:(NSString *)password completion:(void (^)(NSError *error))completionBlock;
- (void)logOut;
- (BOOL)isAsAGuest;
- (void)sendPasswordReminder:(NSString *)emailAddress completion:(void (^)(NSError *error))completionBlock;
-(void)getAddressesForUserByType:(BOOL)isShippingAddress completion:(void (^)(NSError *error, id response)) completionBlock;
-(void)addAddressForUser:(BOOL)isShippingAddress address:(LPFAddress*)address completion:(void (^)(NSError *error, id response)) completionBlock;
// Images
- (void)uploadImages:(NSArray *)images progress:(void (^)(NSString *message, float progress))progressBlock completion:(void (^)(NSError *error))completionBlock;
- (void)loadAlbumsCompletion:(void (^)(NSArray *albums, NSError *error))completion;
- (void)loadAlbumImagesForAlbum:(NSString *)albumID completion:(void (^)(NSArray *images, NSError *error))completion;

// Stores
- (void)startUpdatingLocation;
- (void)findStoresNearby:(void (^)(NSArray *stores, NSError *error))completion;
- (void)findStoresNearPostalCode:(NSString *)postalCode completion:(void (^)(NSArray *stores, NSError *error))completion;

// Ordering
- (void)uploadCart:(LPFCart *)cart progress:(void (^)(NSString *message, float progress))progressBlock completion:(void (^)(NSError *error))completionBlock;
- (void)updateOrderWithCart:(LPFCart *)cart progress:(void (^)(NSString *message, float progress))progressBlock completion:(void (^)(NSError *error))completionBlock;
- (void)updateTotalsForCart:(LPFCart *)cart completion:(void (^)(NSError *error))completionBlock;
- (void)submitOrderForCart:(LPFCart *)cart completion:(void (^)(NSError *error))completionBlock;

// Private
- (void)uploadTinyImage:(void (^)(NSString *uploadedImageID, NSError *error))completion;
- (void)deleteTinyImage;

// Deprecated
- (void)beginPartnerSessionWithID:(NSString *)partnerID sourceID:(NSString *)partnerSourceID password:(NSString *)password completion:(void (^)(NSError *error))completionBlock DEPRECATED_ATTRIBUTE;

@end


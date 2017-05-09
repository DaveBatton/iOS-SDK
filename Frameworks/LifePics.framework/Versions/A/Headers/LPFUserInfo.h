//
//  LPFUserInfo.h
//  LifePics
//
//  Created by administrator on 02/03/2017.
//  Copyright © 2017 Taylor Corp. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LPFUserInfo : NSObject

@property (nonatomic, copy) NSString *userID;
@property (nonatomic, copy) NSString *userEmail;
@property (nonatomic, copy) NSString *userPassword;
@property (nonatomic, copy) NSString *userFirstName;
@property (nonatomic, copy) NSString *userLastName;
@property (nonatomic, copy) NSString *userPhoneNumber;
@property (nonatomic, copy) NSString *userMerchantID;  // We get this when the user logs in. It may not be the merchant ID for the current order.
@property (nonatomic, copy) NSString *contactFirstName;
@property (nonatomic, copy) NSString *contactLastName;
@property (nonatomic, copy) NSString *billingEmail;
@property BOOL isAsAGuest;
@property BOOL loginStatus;
@property BOOL touchIdLoin;


#pragma mark - user
+ (BOOL)lastUserCanTouchLogin;
+ (LPFUserInfo*)getLastUser;
- (void)saveToKeychain;

#pragma mark - when login or logout
+ (LPFUserInfo*)getUserInfoByAutoLogin;
- (void)manualLogined;
- (void)logout;

@end

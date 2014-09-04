//
//  LPFAddress.h
//  LifePics
//
//  Created by Dave Batton on 5/3/14.
//  Copyright (c) 2014 Taylor Corp. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, LPFAddressType) {
    LPFAddressTypeUnknown = 0,
    LPFAddressTypeShipping,
    LPFAddressTypeBilling
};

@class APContact;
@class APAddress;
@class STPCard;

@interface LPFAddress : NSObject

@property (nonatomic, copy) NSString *addressID;  // nil until uploaded to the server.
@property (nonatomic, copy) NSString *label;
@property (nonatomic, copy) NSString *firstName;
@property (nonatomic, copy) NSString *lastName;
@property (nonatomic, copy) NSString *addressOne;
@property (nonatomic, copy) NSString *addressTwo;
@property (nonatomic, copy) NSString *city;
@property (nonatomic, copy) NSString *state;
@property (nonatomic, copy) NSString *postalCode;
@property (nonatomic, copy) NSString *country;
@property (nonatomic, copy) NSString *phone;
@property (nonatomic, copy) NSString *email;

// Class Methods
+ (LPFAddress *)newAddressForCurrentLocale;
+ (LPFAddress *)mostRecentAddress;
+ (void)setMostRecentAddress:(LPFAddress *)address;
+ (NSArray *)savedAddresses;
+ (BOOL)stringRepresentsUnitedStates:(NSString *)string;

// Public
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;
- (instancetype)initWithContact:(APContact *)contact address:(APAddress *)address;
- (instancetype)initWithCreditCard:(STPCard *)creditCard;
- (BOOL)hasText;
- (BOOL)isSufficient;
- (BOOL)isSufficient:(NSString **)description;
- (BOOL)isEqualToAddress:(LPFAddress *)anotherAddress;
- (BOOL)isUSAddress;
- (NSString *)fullName;
- (NSString *)fullAddress;
- (void)save;
- (void)delete;
- (NSDictionary *)dictionaryValue;

@end

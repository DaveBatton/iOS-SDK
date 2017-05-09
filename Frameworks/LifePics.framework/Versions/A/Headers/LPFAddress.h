//
//  LPFAddress.h
//  LifePics
//
//  Created by Dave Batton on 5/3/14.
//  Copyright (c) 2014 Taylor Corp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AddressBook/AddressBook.h>
#import <Contacts/Contacts.h>
#import<passkit/passkit.h>

typedef NS_ENUM(NSInteger, LPFAddressType) {
    LPFAddressTypeUnknown = 0,
    LPFAddressTypeShipping,
    LPFAddressTypeBilling
};

//@class APContact;
//@class APAddress;
@class LPFCard;

@interface LPFAddress : NSObject

@property (nonatomic, strong) NSString *addressID;  // nil until uploaded to the server.
@property (nonatomic, strong) NSString *label;
@property (nonatomic, strong) NSString *firstName;
@property (nonatomic, strong) NSString *lastName;
@property (nonatomic, strong) NSString *addressOne;
@property (nonatomic, strong) NSString *addressTwo;
@property (nonatomic, strong) NSString *city;
@property (nonatomic, strong) NSString *state;
@property (nonatomic, strong) NSString *postalCode;
@property (nonatomic, strong) NSString *country;
@property (nonatomic, readonly) NSString *countryCode;
@property (nonatomic, strong) NSString *phone;
@property (nonatomic, strong) NSString *email;

// Class Methods
+ (NSMutableArray *)parseUserAddressesResponse:(NSArray*)dicArray;
+ (LPFAddress *)newAddressForCurrentLocale;
+ (LPFAddress *)mostRecentAddress;
+ (void)setMostRecentAddress:(LPFAddress *)address;
+ (NSArray *)savedAddresses;
+ (BOOL)stringRepresentsUnitedStates:(NSString *)string;
+ (NSArray*)stateArray;
//access Contacts or Addressbook framework
+ (void)accessContactsOrAddressbookWithBlock:(void (^)())block;


// Public
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;
//- (instancetype)initWithRecordRef:(ABRecordRef)recordRef;
//- (instancetype)initWithContact:(APContact *)contact address:(APAddress *)address;
- (instancetype)initWithCreditCard:(LPFCard *)creditCard;
- (instancetype)initWithCNContact:(CNContact *)contact;
- (instancetype)initWithPKContact:(PKContact*)contact;
- (BOOL)hasText;
- (BOOL)isSufficient;
- (BOOL)isSufficient:(NSString **)details;
- (BOOL)isSufficientNotCareEmail:(NSString **)details;
- (BOOL)isEqualToAddress:(LPFAddress *)anotherAddress;
- (BOOL)isUSAddress;
- (NSString *)fullName;
- (NSString *)fullAddress;
- (void)save;
- (void)delete;
- (NSDictionary *)dictionaryValue;
//- (ABRecordRef)recordRef;

@end

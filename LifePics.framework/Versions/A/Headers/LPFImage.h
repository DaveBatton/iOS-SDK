//
//  LPFImage.h
//  LifePics
//
//  Created by Dave Batton on 2/13/14.
//  Copyright (c) 2014 Taylor Corp. All rights reserved.
//

#import <UIKit/UIKit.h>

@class LPFFolder;

typedef NS_ENUM(NSInteger, LPFImageSourceType) {
    LPFImageSourceTypeNone = 0,
    LPFImageSourceTypeDevice,
    LPFImageSourceTypeFacebook,
    LPFImageSourceTypeInstagram,
    LPFImageSourceTypeGoogle,
    LPFImageSourceTypeFlickr,
    LPFImageSourceTypeSmugMug,
    LPFImageSourceTypeSeeded,
    LPFImageSourceTypeCount,
};

typedef NS_ENUM(NSInteger, LPFImageOrientation) {
    LPFImageOrientationUnknown,
    LPFImageOrientationLandscape,
    LPFImageOrientationPortrait,
    LPFImageOrientationSquare
};

@interface LPFImage : NSObject

@property (copy, nonatomic) NSString *imageId;
@property (assign, nonatomic) LPFImageSourceType sourceType;
@property (copy, nonatomic) NSString *uploadedImageId;
@property (copy, nonatomic) NSURL *thumbnailURL;
@property (copy, nonatomic) NSURL *fullURL;
@property (strong, nonatomic) id userInfo;
@property (assign, nonatomic) CGSize fullImageSize;
@property (readonly, nonatomic) LPFImageOrientation orientation;
@property (weak, nonatomic) LPFFolder *folder;

@end

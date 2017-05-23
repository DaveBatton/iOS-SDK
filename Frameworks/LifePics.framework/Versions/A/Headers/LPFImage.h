//
//  LPFImage.h
//  LifePics
//
//  Created by Dave Batton on 2/13/14.
//  Copyright (c) 2014 Taylor Corp. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Photos/Photos.h>


extern NSString * const LPFImageDidCacheSmallCroppedImageNotification;

typedef NS_ENUM(NSInteger, LPFImageSourceType) {
    LPFImageSourceTypeNone = 0,
    LPFImageSourceTypeDevice,
    LPFImageSourceTypeLifePics,
    LPFImageSourceTypeFacebook,
    LPFImageSourceTypeInstagram,
    LPFImageSourceTypeGoogle,
    LPFImageSourceTypeFlickr,
    LPFImageSourceTypeSmugMug,
    LPFImageSourceTypeSeeded,
    LPFImageSourceTypeCount,
    LPFImageSourceTypeExternal //Provided by implementors of the SDK
};

typedef NS_ENUM(NSInteger, LPFImageOrientation) {
    LPFImageOrientationUnknown,
    LPFImageOrientationLandscape,
    LPFImageOrientationPortrait,
    LPFImageOrientationSquare
};

@class LPFFolder;
@class LPFImagePrintInfo;

@interface LPFImage : NSObject
@property (copy, nonatomic) NSString *imageID;
@property (assign, nonatomic) LPFImageSourceType sourceType;
@property (copy, nonatomic) NSString *uploadedImageId;
@property (copy, nonatomic) NSURL *thumbnailURL;
@property (copy, nonatomic) NSURL *fullURL;
@property (assign, nonatomic) CGSize fullImageSize;
@property (readonly, nonatomic) LPFImageOrientation orientation;
@property (weak, nonatomic) LPFFolder *folder;
@property (strong, nonatomic) NSDictionary *userInfo;
@property (assign, nonatomic) CGFloat cropAspectRatio;  // 0.0 (unspecified) or equal to or less than 1.0 (square), regardless of the image orientation.
@property (strong, nonatomic) NSString *printWidthHeight;
@property (assign, nonatomic) CGRect cropRect;
@property (nonatomic, readonly) UIImage *croppedImage;
@property (nonatomic, readonly) UIImage *smallCroppedImage;  // A 300 x 300 max image. Will return nil until -croppedImageFromFullSizeImage: is called. That caches the cropped image.
@property (nonatomic, readonly) UIImage *croppedThumbnail;  // A 120 x 120 max image. Generated after -croppedImageFromFullSizeImage: has been called. Returns nil if that's not available.
@property (nonatomic, readonly) UIImage *croppedRealImage;
@property BOOL LPFImageDidCacheSmallCroppedImageNotify ;
/*
 Modified by: NL, hxliu,   add sameImageRefArray property and setUploadedImageIdForSameImageRefArrayItems method.
 Analysis result: same images will be upload once, but they should share one uploadedImageId once upload successful.
 Purpose: Mobile(PP): Application crashes when update total price if add same images multiple timess
 TFS Bug: bug#4962
 Date: 2015-3-10
 */
@property (strong, nonatomic) NSMutableArray *sameImageRefArray;
@property CGFloat compressQuality;
@property (strong, nonatomic) NSString *logicalUUID;
@property BOOL lowResolution;
@property LPFImagePrintInfo *userPrintInfo;
// Public
- (UIImage *)croppedImageFromFullSizeImage:(UIImage *)fullSizeImage;
- (UIImage *)croppedImageFromRealImage:(UIImage *)realImage;
- (UIImage *)croppedImageFrom:(UIImage *)croppedImage;

+ (LPFImage *)imageWithUIImage:(UIImage *)image;
- (void)setUploadedImageIdForSameImageRefArrayItems;
- (CGFloat)uploadCompressQuality;
- (NSString *)getImageID;
// Create a smaller version (300x300 * scale (or smaller - don't enlarge the image))
- (UIImage *)getSmallCroppedImageFromCroppedImage:(UIImage *)croppedImage;
- (UIImage *)smallCroppedImageFromCroppedImage:(UIImage *)croppedImage;

- (void)removeSmallCroppedImage;
- (void)removeCroppedImage;


//- (NSString *)smallCroppedImageCacheKey;
@end

//suit for Photes.Framework
@interface LPFNewImage : LPFImage
@property (copy, nonatomic) PHAsset *imageAsset;
@property (copy, nonatomic) NSString *localIdentifier;

@end
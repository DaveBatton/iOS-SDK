//
//  LPFImageDataSource.h
//  LifePics
//
//  Created by John Blanco on 4/3/14.
//  Copyright (c) 2014 Taylor Corp. All rights reserved.
//


#import <Foundation/Foundation.h>


@protocol LPFImageDataSource <NSObject>


@property (readonly, nonatomic) NSString *name;
@property (readonly, nonatomic) UIImage *icon;

- (void)imageRepresentations:(void (^)(NSArray *imageRepresentations))completion;
- (CGSize)fullImageSizeForImageRepresentation:(id)imageRepresentation;
- (void)fetchThumbnailForImageRepresentation:(id)imageRepresentation completion:(void (^)(UIImage *thumbnailImage))completion;
- (void)fetchFullSizeImageRepresentation:(id)imageRepresentation completion:(void (^)(UIImage *fullImage))completion;


@end

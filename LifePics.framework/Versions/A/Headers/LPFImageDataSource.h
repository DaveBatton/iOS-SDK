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

- (void)imageRepresentationsCompleted:(void (^)(NSArray *imageRepresentations))completed;
- (void)fetchThumbnailForImageRepresentation:(id)imageRepresentation completed:(void (^)(UIImage *thumbnailImage))completed;
- (void)fetchFullSizeImageRepresentation:(id)imageRepresentation success:(void (^)(UIImage *fullImage))completed;

@end

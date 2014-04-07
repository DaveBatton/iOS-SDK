//
//  TCSimpleImageDataSource.m
//  LifePics SDK
//
//  Copyright (c) 2014 Taylor Corp. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TCSimpleImageDataSource.h"

@implementation TCSimpleImageDataSource


- (NSString *)name
{
    return @"Simple Images";
}


- (UIImage *)icon
{
    // access the logo from our image assets
    return [UIImage imageNamed:@"SimpleLogo"];
}


- (CGSize)fullImageSizeForImageRepresentation:(id)imageRepresentation
{
    UIImage *fullImage = [UIImage imageNamed:[imageRepresentation objectForKey:@"full"]];
    return CGSizeMake(fullImage.size.width, fullImage.size.height);
}


- (void)imageRepresentations:(void (^)(NSArray *imageRepresentations))completion
{
    // we simple use dictionaries that point at the image files stored in the app
    NSDictionary *simpleOne = @{@"thumb": @"simple-one-thumb.jpg", @"full": @"simple-one.jpg"};
    NSDictionary *simpleTwo = @{@"thumb": @"simple-two-thumb.jpg", @"full": @"simple-two.jpg"};
    NSDictionary *simpleThree = @{@"thumb": @"simple-three-thumb.jpg", @"full": @"simple-three.jpg"};

    // return all the images
    if (completion) {
        completion(@[simpleOne, simpleTwo, simpleThree]);
    }
}


- (void)fetchThumbnailForImageRepresentation:(id)imageRepresentation completion:(void (^)(UIImage *thumbnailImage))completion
{
    // open the thumbnail image file and call the block with it
    completion([UIImage imageNamed:[imageRepresentation objectForKey:@"thumb"]]);
}


- (void)fetchFullSizeImageRepresentation:(id)imageRepresentation completion:(void (^)(UIImage *fullImage))completion
{
    // open the full image file and call the block with it
    completion([UIImage imageNamed:[imageRepresentation objectForKey:@"full"]]);
}


@end

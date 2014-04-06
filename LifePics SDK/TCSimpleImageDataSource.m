//
//  TCSimpleImageDataSource.m
//  LifePics SDK
//
//  Created by John Blanco on 4/4/14.
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


- (void)imageRepresentationsCompleted:(void (^)(NSArray *imageRepresentations))completed
{
    // we simple use dictionaries that point at the image files stored in the app
    NSDictionary *simpleOne = @{@"thumb": @"simple-one-thumb.jpg", @"full": @"simple-one.jpg"};
    NSDictionary *simpleTwo = @{@"thumb": @"simple-two-thumb.jpg", @"full": @"simple-two.jpg"};
    NSDictionary *simpleThree = @{@"thumb": @"simple-three-thumb.jpg", @"full": @"simple-three.jpg"};
    
    // return all the images
    if (completed) {
        completed(@[simpleOne, simpleTwo, simpleThree]);
    }
}


- (void)fetchThumbnailForImageRepresentation:(id)imageRepresentation completed:(void (^)(UIImage *thumbnailImage))completed
{
    // open the thumbnail image file and call the block with it
    completed([UIImage imageNamed:[imageRepresentation objectForKey:@"thumb"]]);
}


- (void)fetchFullSizeImageRepresentation:(id)imageRepresentation success:(void (^)(UIImage *fullImage))completed
{
    // open the full image file and call the block with it
    completed([UIImage imageNamed:[imageRepresentation objectForKey:@"full"]]);
}


@end

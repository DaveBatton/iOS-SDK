//
//  TCDevTools.m
//  LifePics SDK
//
//  Copyright (c) 2014 Taylor Corp. All rights reserved.
//

#import "TCDevTools.h"
#import <UIKit/UIKit.h>
#import <AssetsLibrary/AssetsLibrary.h>

// defaults keys
static NSString * const photoLoadKey = @"photoLoadKey";

typedef enum {
    TCDevAlertTypeAddTestPhotos
} TCDevAlertType;


@implementation TCDevTools


+ (void)offerToAddTestPhotos
// Offers to populate the simulator with some images for testing.
// Does nothing on a real device.
{
#if !TARGET_IPHONE_SIMULATOR
    return;
#endif

    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];

    if (![defaults objectForKey:photoLoadKey]) {
        // never ask again, no matter the answer
        [defaults setObject:@YES forKey:photoLoadKey];
        [defaults synchronize];
        
        ALAssetsLibrary *library = [[ALAssetsLibrary alloc] init];
        [library enumerateGroupsWithTypes:ALAssetsGroupSavedPhotos
                               usingBlock:^(ALAssetsGroup *group, BOOL *stop) {
                                   if (group && [group numberOfAssets] == 0) {
                                       UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"There are no photos in the simulator. Shall we fetch some in the background?"
                                                                                           message:@"We'll get about 30 images from LorumPixel.com. Watch the console for progress."
                                                                                          delegate:self
                                                                                 cancelButtonTitle:@"No"
                                                                                 otherButtonTitles:@"Yes", nil];
                                       alertView.tag = TCDevAlertTypeAddTestPhotos;
                                       [alertView show];
                                   };
                               }
                             failureBlock:NULL];
    }
}


+ (void)addTestPhotos
{
    // iPhone 5s back camera:  3264 x 2448
    //           front camera: 1280 x  960
    // iPhone 5 back camera:   3264 x 2448
    //          front camera:  1280 x  720
    // iPhone 4 back camera:   1280 x  720
    //          front camera:   640 x  480

    NSArray *sizesArray = @[@"2448/3264", @"3264/2448", @"640/640",
                            @"1280/960", @"960/1280", @"300/300",
                            @"1280/720", @"720/1280", @"960/960",
                            @"640/960", @"960/640", @"100/100",
                            @"640/480", @"480/640", @"480/480",
                            @"1280/720", @"720/1280", @"640/640",
                            @"640/960", @"960/640", @"640/640",
                            @"640/960", @"960/640", @"640/640",
                            @"640/960", @"960/640", @"640/640",
                            @"640/960", @"960/640", @"640/640"];

    ALAssetsLibrary *library = [[ALAssetsLibrary alloc] init];

    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_LOW, 0), ^{
        for (NSString *sizeString in sizesArray) {
            NSString *urlString = [NSString stringWithFormat:@"http://lorempixel.com/%@", sizeString];
            NSData *imageData = nil;
            while (imageData == nil) {
                imageData = [NSData dataWithContentsOfURL:[NSURL URLWithString:urlString]]; // Sometimes we get no data from this service.
                if (imageData == nil) {
                    NSLog(@"Failed to get test image data. Trying again.");
                }
            }
            [library writeImageDataToSavedPhotosAlbum:imageData
                                             metadata:nil
                                      completionBlock:^(NSURL *assetURL, NSError *error) {
                                          if ([error code] == 0) {
                                              NSLog(@"Added another test image.");
                                          }
                                          else {
                                              NSLog(@"Error saving test image:%@ [%@]", assetURL, error);
                                          }
                                      }];
        }
        // We can't call -writeImageDataToSavedPhotosAlbum:metadata:completionBlock: too
        // fast or we start getting errors. There are proper ways to handle this, but
        // this is good enough for this non-production code.
        [NSThread sleepForTimeInterval:1];
    });
}


#pragma mark - UIAlertViewDelegate


+ (void)alertView:(UIAlertView *)alertView didDismissWithButtonIndex:(NSInteger)buttonIndex
{
    if ( (alertView.tag == TCDevAlertTypeAddTestPhotos) && (buttonIndex == 1) ) {
        [self addTestPhotos];
    }
}


@end

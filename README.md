LifePics iOS SDK Version 1.0
============================


New in Version 1.0.1
--------------------

We've added a [CocoaPods](http://cocoapods.org) spec file.


Overview
--------

LifePics is the market leader in providing retail photofinishers with the latest online imaging services and technologies to conduct business on the Web.

The LifePics OPEN (Open Photo Ecommerce Network) program allows app developers to drive consumer photo orders through the LifePics Network. We will allow you to link your app into our network, and we will pay you a revenue share percentage for every order your app generates.

To learn more about developer revenue share please read the enclosed [LifePics Developer Agreement](https://github.com/LifePics/iOS-SDK/raw/master/LifePics%20Developer%20Agreement.pdf)
 and review Schedule 1.

To request developer keys from LifePics please email a complete signed copy of the LifePics Developer Agreement to busdev@lifepics.com. LifePics will generate a set of developer keys and email them back to you. Please see Schedule 1 in the LifePics Developer Agreement on documents to send to LifePics to be eligible for developer revenue share payments.

Please email any questions about the OPEN program to busdev@lifepics.com.


The LifePics iOS SDK
--------------------
The LifePics SDK allows your iPhone users to select images and have them printed locally at nearby photofinishers.

Users can select images from their photo library, images provided by your application, or, optionally, images from their Facebook, Instagram, Google, or Flickr accounts.

![](https://s3.amazonaws.com/LifePics-iOS-SDK/Screenshots/screen1.png) ![](https://s3.amazonaws.com/LifePics-iOS-SDK/Screenshots/screen2.png)
![](https://s3.amazonaws.com/LifePics-iOS-SDK/Screenshots/screen3.png) ![](https://s3.amazonaws.com/LifePics-iOS-SDK/Screenshots/screen4.png)

![](https://s3.amazonaws.com/LifePics-iOS-SDK/Screenshots/screen5.png) ![](https://s3.amazonaws.com/LifePics-iOS-SDK/Screenshots/screen6.png)
![](https://s3.amazonaws.com/LifePics-iOS-SDK/Screenshots/screen7.png) ![](https://s3.amazonaws.com/LifePics-iOS-SDK/Screenshots/screen8.png)


Prerequisites
------------

You will need a free LifePics developer key. Details are in the Overview section above.

The SDK supports iOS 7.0 and later.


Installation 
------------

**CocoaPods**

The easiest way to install the LifePics SDK is using [CocoaPods](http://cocoapods.org).

    platform :ios, '7.0'
    pod 'LifePics'


**Manual Installation**

Put a copy of the LifePics.framework and LifePics.bundle files anywhere in your project folder. 

In Xcode, select your project in the Project Navigator.<br>
Select your app target.<br>
Select the Build Phases tab.<br>
Expand Link Binary With Libraries.<br>
Click the + button, then Add Other, to select and add the LifePics.framework file.

Next, add the following system frameworks (if they're not already linked to your project:

* Accelerate
* AssetsLibrary
* CFNetwork
* CoreGraphics
* CoreImage
* ImageIO
* MapKit
* MobileCoreServices
* QuartzCore
* Security
* SystemConfiguration

And these libraries:

* libsqlite3.dylib
* libxml2.dylib
* libz.dylib

![](https://s3.amazonaws.com/LifePics-iOS-SDK/Screenshots/LinkBinaries.png)

Now switch to the Build Settings tab and find the Other Linker Flags setting. Add "-ObjC" here, for both Debug and Release.

![](https://s3.amazonaws.com/LifePics-iOS-SDK/Screenshots/OtherLinkerFlags.png)

Add the LifePics.bundle to your target, by selecting Add Files in the Project Navigator.

![](https://s3.amazonaws.com/LifePics-iOS-SDK/Screenshots/AddFiles.png)<br>
![](https://s3.amazonaws.com/LifePics-iOS-SDK/Screenshots/AddBundle.png)


Import the LifePics headers:

    #import <LifePics/LifePics.h>


Connect to the LifePics network by providing your Partner ID, Source ID, and password:

    [[LPFSessionManager sharedManager] beginPartnerSessionWithID:@"partnerID"
                                                        sourceID:@"sourceID"
                                                        password:@"password"
                                                      completion:^(NSError *error) {
                                                          if ([error code] != 0) {
                                                              // Handle error here.
                                                          }
                                                      }];

Finally, present the LifePics Order View controller:

    LPFOrderViewController *vc = [[LPFOrderViewController alloc] initWithImageDataSource:nil];
    [self presentViewController:vc animated:YES completion:NULL];


Customization
-------------

You can customize the colors used by the LifePics Order View Controller by setting the primary and secondary colors before presenting it:

    LPFOrderViewController *vc = [[LPFOrderViewController alloc] initWithImageDataSource:nil];
    vc.primaryColor = [UIColor blueColor];
    vc.secondaryColor = [UIColor purpleColor];
    [self presentViewController:vc animated:YES completion:NULL];

Further interface customizations can be made using the UIAppearance protocol.

You can also enable Facebook, Instagram, Google, and Flickr access in the Sources view. See the [Configure Photo Sources](https://github.com/LifePics/iOS-SDK/blob/master/Configure%20Photo%20Sources.md) document for details.

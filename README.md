LifePics iOS SDK Version 1.0.9
==============================


Overview
--------

LifePics is the market leader in providing retail photofinishers with the latest online imaging services and technologies to conduct business on the Web.

The LifePics OPEN (Open Photo Ecommerce Network) program allows app developers to drive consumer photo orders through the LifePics Network. We will allow you to link your app into our network, and we will pay you a revenue share percentage for every order your app generates.

To learn more about developer revenue share please read the enclosed [LifePics Developer Agreement](https://github.com/LifePics/iOS-SDK/raw/master/LifePics%20Developer%20Agreement.pdf)
 and review Schedule 1.

To request developer keys from LifePics please email a complete signed copy of the LifePics Developer Agreement to [busdev@lifepics.com](mailto:busdev@lifepics.com). LifePics will generate a set of developer keys and email them back to you. Please see Schedule 1 in the [LifePics Developer Agreement](https://github.com/LifePics/iOS-SDK/blob/master/LifePics%20Developer%20Agreement.pdf) on documents to send to LifePics to be eligible for developer revenue share payments.

If you don't have developer keys and stripe publish key

Please email any questions about the OPEN program to [busdev@lifepics.com](mailto:busdev@lifepics.com).


* * *

The LifePics iOS SDK
--------------------
The LifePics SDK allows your iPhone users to select images and have them printed locally at nearby photofinishers.

Users can select images from their photo library, images provided by your application, or, optionally, images from their Facebook, Instagram, Google, or Flickr accounts.

![](https://github.com/LifePics/iOS-SDK/blob/nl/DemoImages/screen1.png) ![](https://github.com/LifePics/iOS-SDK/blob/nl/DemoImages/screen2.png)
![](https://github.com/LifePics/iOS-SDK/blob/nl/DemoImages/screen3.png) ![](https://github.com/LifePics/iOS-SDK/blob/nl/DemoImages/screen4.png)

![](https://github.com/LifePics/iOS-SDK/blob/nl/DemoImages/screen5.png) ![](https://github.com/LifePics/iOS-SDK/blob/nl/DemoImages/screen7.png) ![](https://github.com/LifePics/iOS-SDK/blob/nl/DemoImages/screen8.png)


* * *

Prerequisites
------------

You will need a free LifePics developer key. Details are in the Overview section above.

The SDK supports iOS 9.0 and later.


* * *

Installation 
------------

**CocoaPods**

The easiest way to install the LifePics SDK is using [CocoaPods](http://cocoapods.org).

    source 'https://github.com/CocoaPods/Specs.git'
    platform :ios, '9.0'
    pod 'LifePics', '~> 1.0.9'


**Manual Installation**

Put a copy of the Frameworks folder from this demo's root folder to your project folder, and then reference  LifePics.framework & LifePics.bundle, CreativeSDK related frameworks & bundles, FaceBook related frameworks, CardIO libraries as well as libGoogleAnalyticsServices to your project.
![](https://github.com/LifePics/iOS-SDK/blob/nl/DemoImages/FrameworksFolder.png)

In Xcode, select your project in the Project Navigator.<br>
Select your app target.<br>
Select the Build Phases tab.<br>
Expand Link Binary With Libraries.<br>
Click the + button, then Add Other, to select and add the LifePics.framework file etc.

Next, add the following system frameworks (if they're not already linked to your project:

* Accelerate
* AddressBook
* AssetsLibrary
* AVFoundation
* CFNetwork
* CoreGraphics
* Contacts
* ImageIO
* MapKit
* MobileCoreServices
* PassKit
* QuartzCore
* Security
* SystemConfiguration
* WebKit
* CoreLocation
* AudioToolbox
* CoreVideo
* OpenGLES
* CoreMedia
* Photos
* MessageUI
* UIKit
* LocalAuthentication
* LifePics
* FBSDKCoreKit
* FBSDKLoginKit
* AdobeCreativeSDKCore
* AdobeCreativeSDKImage


And these libraries:

* libsqlite3.tbd
* libxml2.tbd
* libz.tbd
* libCardIO.a
* libopencv_core.a
* libopencv_imgproc.a
* libGoogleAnalyticsServices

![](https://github.com/LifePics/iOS-SDK/blob/nl/DemoImages/LinkBinaries.png)

Now switch to the Build Settings tab and find the Other Linker Flags setting. Add "-ObjC" here, for both Debug and Release.

![](https://github.com/LifePics/iOS-SDK/blob/nl/DemoImages/OtherLinkerFlags.png)

Add the LifePics.bundle to your target, by selecting Add Files in the Project Navigator.

![](https://s3.amazonaws.com/LifePics-iOS-SDK/Screenshots/AddFiles.png)<br>
![](https://github.com/LifePics/iOS-SDK/blob/nl/DemoImages/AddBundle.png)

Add the AdobeCreativeSDKImageResources.bundle to your target 
![](https://github.com/LifePics/iOS-SDK/blob/nl/DemoImages/AddAdobeCreativeSDKImageResources.png)

Add the AddAdobeCreativeSDKCoreResources.bundle to your target 
![](https://github.com/LifePics/iOS-SDK/blob/nl/DemoImages/AddAdobeCreativeSDKCoreResources.png)

Import the LifePics headers:

    #import <LifePics/LifePics.h>
    #import <LifePics/NSBundle+LPFAdditions.h>
    #import <LifePics/LPFMenuViewController.h>
    #import <LifePics/APLSlideMenuViewController.h>
    #import <FBSDKCoreKit/FBSDKCoreKit.h>

The Navigation Root ViewController of the App is a SlideMenuController, it includes a menu page and main display page.
So init things for the slideMenuController first:


```
- (BOOL)application:(UIApplication *)application willFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
        [UIApplication sharedApplication].statusBarHidden = NO;
        [self.window makeKeyAndVisible];
        self.isRestoring = NO;
        [self setSlideMenuController];
        return YES;
}


- (void)setSlideMenuController
{
    APLSlideMenuViewController *slideMenuController = [[APLSlideMenuViewController alloc] init];
    [LPFOrderViewController setSlideMenuController: slideMenuController];
    slideMenuController.bouncing = YES;
    slideMenuController.gestureSupport = APLSlideMenuGestureSupportDrag;
    slideMenuController.separatorColor = [UIColor grayColor];
    if ([LPFOrderViewController sharedInstance]!=nil) {
        self.orderViewController = [LPFOrderViewController sharedInstance];
        slideMenuController.contentViewController = self.orderViewController;
    }
    UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"LPFMenu" bundle:[NSBundle lpfBundle]];
    LPFMenuViewController *vc = [storyboard instantiateViewControllerWithIdentifier:@"LPFMenuViewController"];
    slideMenuController.leftMenuViewController = vc;
    slideMenuController.slideDelegate = vc;
    self.slideMenuController = slideMenuController;
}

```
Set useStagingServer for session manager in didFinishLaunchingWithOptions method:

    int forStaging = [[[[NSBundle mainBundle] infoDictionary] objectForKey:@"ForStaging"] intValue];
    [LPFSessionManager sharedManager].useStagingServer = forStaging==0? NO:YES;

Then, init orderViewController to relate with slideMenuController , Finally present the slideMenuController:

    self.orderViewController = [[LPFOrderViewController alloc] init];
    self.orderViewController.shouldDisplayCancelButton = !displayOrderViewAtLaunch;
    self.slideMenuController.contentViewController = self.orderViewController;
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)((0.0f) * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{

        self.window.rootViewController = self.slideMenuController;
    });


This SDK support to save cart info to local,

    - (void)applicationWillResignActive:(UIApplication *)application
    {
        LPFOrderViewController* orderController = self.orderViewController;
        orderController = orderController?orderController : [LPFOrderViewController sharedInstance];
        if (orderController) {
            [orderController saveCartPlist];
        }
    }

* * *

Customization
-------------

You can customize the colors used by the LifePics Order View Controller by setting the primary and secondary colors before presenting it:

    LPFOrderViewController *vc = [[LPFOrderViewController alloc] initWithImageDataSource:nil];
    vc.primaryColor = [UIColor blueColor];
    vc.secondaryColor = [UIColor purpleColor];
    LPFOrderViewController.slideMenuController.contentViewController = self.orderViewController;
    ((UIWindow*)[[UIApplication sharedApplication].windows objectAtIndex:0]).rootViewController = self.orderViewController.slideMenuController;

Further interface customizations can be made using the UIAppearance protocol.

You can also enable Facebook, Instagram, Google, and Flickr access in the Sources view. See the [Configure Photo Sources](https://github.com/LifePics/iOS-SDK/blob/master/Configure%20Photo%20Sources.md) document for details.

For using Adobe Creative Image Editor, Please request an acount on the website (https://creativesdk.adobe.com/) for your own Creative_CLIENT_ID & Creative_CLIENT_SECRET for your App.


To customize product comparison rule used on finding available stores to deliver current order, you can realize LPFProduct (Comparison) category in your target, for example,

```
//LPFProduct+Comparison.h as below

#import <LifePics/LifePics.h>

@interface LPFProduct (Comparison)

- (BOOL)isSimilarToProduct4PickupInStore:(LPFProduct *)anotherProduct;

@end
```
```

//LPFProduct+Comparison.m as below

#import "LPFProduct+Comparison.h"

@implementation LPFProduct (Comparison)
- (BOOL)isSimilarToProduct4PickupInStore:(LPFProduct *)anotherProduct
{
return [self.productID isEqualToString:anotherProduct.productID4PickupInStore] || [self.productID4PickupInStore isEqualToString:anotherProduct.productID];
}
@end


```
* * *

Revision History
----------------
## Version 1.0.9

***Features***

- To sign In using your Touch ID.

- Using Apple Pay for ship-to-home or pickup-in-store.

- Product comparison rule customization on searching available stores.

- A preliminary Work Flow customization.

- Native iPad Support!

- Added a side menu.

- Rich Image Editor.

- Added account create & login feature.

- Cart info Serialization to device local. 

- Misc Bugs.


## Version 1.0.8

***Features***

- Added a required email address to the Confirm Order view.

- Added Terms of Service and Privacy Policy links to the Confirm Order view.

- Improved the error message if access to device photos has been denied.


## Version 1.0.7

***Features***

- Photo sources are now dimmed until you log into them.

- You can now log out of a photo source (use the Edit button).

- The staging server will be used when building in DEBUG mode. Otherwise the production server will be used.

- When starting a session, a message will be displayed in the Xcode console to let you know if you’re connected to the staging or production server.

- The Submit Order button will now say “Submit Fake Order” when logged into the staging server.

***Bug Fixes***

- The list of photo sources no longer contains unwanted white space at the top when retuning from a photo source.

- The dialog offering to submit a fake order has been removed.


## Version 1.0.6

***Features***

- We've removed a merchant that no longer wishes to participate in the mobile SDK program.


## Version 1.0.5

***Features***

- Show detailed image upload progress when ordering.
- Added the LPFOrderViewControllerDelgate to keep updated on current order status.

***Bug Fixes***

- Facebook required permissions minimized to photos only.


## Version 1.0.4

***Bug Fixes***

- Fixed instructions for configuring Flickr.
- Fixed permissions request for Facebook so your FB app doesn't need to be in an approved/reviewed state to test it.
- Flickr now supports https only.
- Serialized image uploads to support larger orders.


## Version 1.0.3

***Features***

- Improved the animation when previewing photos.

***Bug Fixes***

- Fixed a bug in the 1.0.2 release that prevented compiling.
- Removed CoreImage from the documentation as a system framework requirement.


## Version 1.0.2

***Features***

- Instagram will now show paged results.

***Bug Fixes***

- Fixed Facebook permissions error.


## Version 1.0.1

***Features***

- We've added a [CocoaPods](http://cocoapods.org) spec file.
- Added SmugMug as an image source.
- Improved store finding when the user's current location can't be determined.
- Now animates from thumbnail view to the single-image preview.
- Updated the activity indicator.
- Enabled the status bar network activity indicator.

***Bug Fixes***

- Fixed text wrap in the floating navigation buttons.
- Fixed a photo rotation bug.
- Fixed a photo source thumbnail aspect ratio bug.
- Fixed the two crashing bugs.
- Fixed an image upload bug.

# Configuring Image Sources

The LifePics framework presents a set of image sources that can retrieve users' favorite images to select for printing. However, they'll only appear when they're properly configured. The official list of supported image sources are:

* Local Device Images (always presented)
* Instagram
* Facebook
* Google
* Flickr
* Seeded Images (developer-defined)

To properly configure an image source, you generally need to provide a Public Key or options that are going to be unique to each one. Configuration for each source is explained below.


### Instagram

1. Create a new client on [Instagram](http://instagram.com/developer/clients/manage/).
2. Set the redirect URL to **ig[Your Instagram Client ID]://authorize**.
3. In your app's Info.plist, add *LPFInstagramKey* and set it to your provided *Instagram Client ID*.
4. In your app's Info.plist, add **ig[Your Instagram Client ID]** to the *URL Schemes* list under *URL types*.
5. In your app's app delegate, add the following code to the *application:openURL:sourceApplication:annotation:* method:

Example:

     NSString *instagramKey = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"LPFInstagramKey"];
     NSString *instagramUrlPrefix = [NSString stringWithFormat:@"ig%@://", instagramKey];
     if ([[url absoluteString] hasPrefix:instagramUrlPrefix]) {
         return [LPFOrderViewController openURL:url sourceApplication:sourceApplication];
     }


### Facebook

1. Create a new app from your Facebook account.
2. Follow the first three steps for [configuring the app for iOS](https://developers.facebook.com/docs/ios/getting-started/).
3. In your app's Info.plist, add *FacebookAppID* and set it to your provided *Facebook App ID*.
4. In your app's Info.plist, add *FacebookDisplayName* and set it to your provided *Facebook App Display Name*.
5. In your app's Info.plist, add **fb[Your Facebook App ID]** to the *URL Schemes* list under *URL types*.
6. In your app's app delegate, add the following code to the *application:openURL:sourceApplication:annotation:* method:

Example:

    // Facebook handling
    NSString *facebookKey = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"FacebookAppID"];
    NSString *facebookUrlPrefix = [NSString stringWithFormat:@"fb%@://", facebookKey];
    if ([[url absoluteString] hasPrefix:facebookUrlPrefix]) {
        return [LPFOrderViewController openURL:url sourceApplication:sourceApplication];
    }


### Google

1. Create a new project on your [Google Dashboard](https://console.developers.google.com/project).
2. In the *Apis and auth* section, add your app's information and bundle ID.
3. In your app's Info.plist, add *LPFGoogleClientID* and set it to your *OAuth Client ID (in APIs & auth section)*.
4. In your app's Info.plist, add *LPFGoogleClientSecret* and set it to your *OAuth Client ID (in APIs & auth section)*.


### Flickr

1. Create a new project on [Flickr](https://www.flickr.com/services/apps/create/).
2. In your app's Info.plist, add *LPFFlickrKey* and set it to your *Flickr Key*.
3. In your app's Info.plist, add *LPFFlickrSecret* and set it to your *Flickr Secret*.
4. In your app's app delegate, add the following code to the *application:openURL:sourceApplication:annotation:* method:

Example:

    // Flickr handling
    NSString *flickrKey = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"LPFFlickrKey"];
    NSString *flickrUrlPrefix = [NSString stringWithFormat:@"flickr%@://", flickrKey];
    if ([[url absoluteString] hasPrefix:flickrUrlPrefix]) {
        return [LPFOrderViewController openURL:url sourceApplication:sourceApplication];
    }


### Seeded Images

Seeded images are a special kind of image source that you define on your own. You might use this image source to provide a set of images bundled in your own app, found on the web somewhere, or perhaps coming from your own in-app photo selection.

To configure this image source, you'll only use code. What you'll need to do is create a class that implements the **LPFImageDataSource** protocol. Then, when beginning the print order flow, pass an instance in to the Order View Controller:

    TCSimpleImageDataSource *imageDataSource = [[TCSimpleImageDataSource alloc] init];
    LPFOrderViewController *vc = [[LPFOrderViewController alloc] initWithImageDataSource:imageDataSource];
    [self presentViewController:vc animated:YES completion:nil];

An example is provided by the *TCSimpleImageDataSource* class. You'll need to implement the following methods:

#### - (NSString *)name

This should return the string you want displayed on the source selection screen. It should represent where the images are coming from or your service name.

#### - (UIImage *)icon

This should return the image you want displayed on the source selection screen. The ideal image size is 60pt x 60pt.

#### - (CGSize)fullImageSizeForImageRepresentation:(id)imageRepresentation

Return the size (width and height) in pixels of the full-sized image.

#### - (void)imageRepresentations:(void (^)(NSArray *imageRepresentations))completion

This is an asynchronous method that should call the completion block with an array of *image representations* that represent each of your images. The datatype is up to you and will be handed back to you in the next two methods.

You might provide an array of UIImage objects or an array of URL strings that point at images on the web. In the sample implementation, it's an NSDictionary with filenames for both a thumbnail and full-size image that exist in the app bundle.

#### - (void)fetchThumbnailForImageRepresentation:(id)imageRepresentation completion:(void (^)(UIImage *thumbnailImage))completion

This is an asynchronous method that passes one image representation to you (from the set you provided previously) and asks that you provide a thumbnail image for it. If your image representation *is* a UIImage, you might pass it right back. In the sample implementation, a UIImage is created from the app bundle file it references. You might also load an image from the web.

#### - (void)fetchFullSizeImageRepresentation:(id)imageRepresentation completion:(void (^)(UIImage *fullImage))completion

This is also an asynchronous method that is identical to the above except it expects a full-size image appropriate for printing. Note that the thumbnail can be this same full-size image, but you shouldn't use a small thumbnail as the full-size image. Providing a low resolution image for printing will result in fuzzy printouts.


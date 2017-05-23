Pod::Spec.new do |s|
  s.name         = "LifePics"
  s.version      = "1.0.9"
  s.homepage     = "https://github.com/LifePics/iOS-SDK"
  s.license      = { :type => 'MIT', :file => 'LICENSE' }
  s.summary      = "The LifePics SDK allows your iPhone users to select images and have them printed locally at nearby photofinishers."
  s.authors      = { "Dave Batton" => "Dave@Batton.org", "John Blanco" => "john@raptureinvenice.com", "Liu, Hai Xia" => "hxliu@nltechdev.com" }
  s.platform     = :ios, '9.0'
  s.ios.deployment_target = '9.0'

  s.source       = { :git => "https://github.com/LifePics/iOS-SDK.git", :tag => "1.0.9" }

  s.description  = <<-DESC
                   The LifePics SDK allows your iPhone users to select images and have them printed locally at nearby photofinishers.

				Users can select images from their photo library, images provided by your application, or, optionally, images from their Facebook, Instagram, Google, or Flickr accounts.
                   DESC

  s.screenshots  = "https://github.com/LifePics/iOS-SDK/blob/nl/DemoImages/screen1.png", "https://github.com/LifePics/iOS-SDK/blob/nl/DemoImages/screen2.png", "https://github.com/LifePics/iOS-SDK/blob/nl/DemoImages/screen3.png", "https://github.com/LifePics/iOS-SDK/blob/nl/DemoImages/screen4.png",
"https://github.com/LifePics/iOS-SDK/blob/nl/DemoImages/screen5.png",
"https://github.com/LifePics/iOS-SDK/blob/nl/DemoImages/screen7.png",
"https://github.com/LifePics/iOS-SDK/blob/nl/DemoImages/screen8.png"

  s.source_files  = 'Frameworks/LifePics.framework/**/*.h','Frameworks/FBSDKCoreKit.framework/**/*.h','Frameworks/FBSDKLoginKit.framework/**/*.h','Frameworks/AdobeCreativeSDKCore.framework/**/*.h','Frameworks/AdobeCreativeSDKImage.framework/**/*.h'
  s.preserve_paths  = 'Frameworks/LifePics.framework','Frameworks/LifePics.bundle','Frameworks/FBSDKCoreKit.framework','Frameworks/FBSDKLoginKit.framework','Frameworks/AdobeCreativeSDKCore.framework','Frameworks/AdobeCreativeSDKImage.framework'
  s.resources    = 'Frameworks/LifePics.bundle'
  s.frameworks = 'Accelerate','AddressBook','AssetsLibrary','AVFoundation','CFNetwork','CoreGraphics','CoreLocation','ImageIO','MapKit','MobileCoreServices','PassKit','QuartzCore','Security', 'SystemConfiguration','UIKit','AudioToolbox','CoreVideo','OpenGLES','CoreMedia','Photos','MessageUI','WebKit','Contacts','LocalAuthentication'
  s.libraries = 'sqlite3', 'xml2', 'z','c++'

  s.requires_arc = true

  s.vendored_frameworks = 'Frameworks/LifePics.framework','Frameworks/FaceBook/FBSDKCoreKit.framework','Frameworks/FaceBook/FBSDKLoginKit.framework','Frameworks/CreativeSDK/AdobeCreativeSDKCore.framework','Frameworks/CreativeSDK/AdobeCreativeSDKImage.framework'
  s.vendored_libraries = 'Frameworks/CardIO/libCardIO.a', 'Frameworks/CardIO/libopencv_core.a', 'Frameworks/CardIO/libopencv_imgproc.a','Frameworks/GoogleAnalytics/libGoogleAnalyticsServices.a'


  # s.dependency "CardIO", "~> 5.3.0"

end

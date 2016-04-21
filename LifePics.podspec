Pod::Spec.new do |s|
  s.name         = "LifePics"
  s.version      = "1.0.9"
  s.homepage     = "https://github.com/LifePics/iOS-SDK"
  s.license      = { :type => 'MIT', :file => 'LICENSE' }
  s.summary      = "The LifePics SDK allows your iPhone users to select images and have them printed locally at nearby photofinishers."
  s.authors      = { "Dave Batton" => "Dave@Batton.org", "John Blanco" => "john@raptureinvenice.com" }
  s.platform     = :ios, '8.1'
  s.source       = { :git => "https://github.com/LifePics/iOS-SDK.git", :tag => "1.0.9" }

  s.description  = <<-DESC
                   The LifePics SDK allows your iPhone users to select images and have them printed locally at nearby photofinishers.

				Users can select images from their photo library, images provided by your application, or, optionally, images from their Facebook, Instagram, Google, or Flickr accounts.
                   DESC

  s.screenshots  = "https://github.com/LifePics/iOS-SDK/blob/nl/DemoImages/screen1.png", "https://github.com/LifePics/iOS-SDK/blob/nl/DemoImages/screen2.png", "https://github.com/LifePics/iOS-SDK/blob/nl/DemoImages/screen3.png", "https://github.com/LifePics/iOS-SDK/blob/nl/DemoImages/screen4.png",
"https://github.com/LifePics/iOS-SDK/blob/nl/DemoImages/screen5.png",
"https://github.com/LifePics/iOS-SDK/blob/nl/DemoImages/screen7.png",
"https://github.com/LifePics/iOS-SDK/blob/nl/DemoImages/screen8.png"

  s.source_files  = 'LifePics.framework/**/*.h'
  s.preserve_paths  = 'LifePics.framework', 'LifePics.bundle'
  s.resources    = 'LifePics.bundle'

  s.frameworks = 'Accelerate', 'AssetsLibrary', 'CFNetwork', 'CoreGraphics', 'CoreLocation', 'ImageIO', 'MapKit', 'MobileCoreServices', 'QuartzCore', 'Security', 'SystemConfiguration', 'UIKit', 'LifePics'
  s.libraries = 'sqlite3', 'xml2', 'z'
  s.requires_arc = true
  s.xcconfig = { 'HEADER_SEARCH_PATHS' => "$(SDKROOT)/usr/include/libxml2", 'FRAMEWORK_SEARCH_PATHS' => '"${PODS_ROOT}/LifePics"' }

end

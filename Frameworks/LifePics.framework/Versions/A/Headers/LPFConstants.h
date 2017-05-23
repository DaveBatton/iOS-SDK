//
// File:	   Constants.h
//
// Abstract:   Contant screen placement values for controls.
//

#define PICDIR              @"/var/mobile/Media/DCIM/100APPLE/"
#define kStackTrace			@"LPStackTrace"
#define kHandlingError		@"LPHandlingError"
#define kHasDB23			@"LPHasDB23"
#define kImageCount			@"LPImageCount"
#define kAppLoaded			@"LPAppLoaded"
#define kLoadingImages		@"LPLoadingImages"
#define kLoggedIn			@"LPLoggedIn"
#define kUserName			@"LPUserName"
#define kPassword			@"LPPassword"
#define kCustomer			@"LPCustomerID"
#define kCustName			@"LPCustomerName"
#define kCameraInUse		@"LPCameraInUse"
//#define kMerchantID			@"LPMerchantID"
#define kCartLocID			@"LPCartLocID"
#define kCartMerchantID		@"LPCartMerchantID"
#define kExpressOrder		@"LPExpressOrder"
#define kSubmitFirstName	@"LPSubmitFirstName"
#define kSubmitLastName		@"LPSubmitLastName"
#define kSubmitPhone		@"LPSubmitPhone"
#define kChangeStore		@"LPChangeStore"
#define kPaymentType		@"LPPaymentType"
#define LPFLifePicsUserIDKey  @"LPFLifePicsUserIDKey"

#define kLPFUserDataVersion      @"LPFUserDataVersion"
#define kuserCartItemsInfo @"CartItemsInfo.plist"
#define kcartItemsInfo @"lifepicsCartItemsInfo.plist"
#define kNotifyFinishReadCartItemsInfoPlist @"kNotifyFinishReadCartItemsInfoPlist"
static NSString *LPFErrorDomain = @"com.TaylorCorp.LifePics.Error";

typedef NS_ENUM(NSInteger, LPFErrorCode) {
    LPFErrorCodeUnexpected = 1000,
    LPFErrorCodeLogin,
    LPFErrorCodeAuthRevoked,
    LPFErrorCodeNoEmailAddress,
    LPFErrorCodeImageUpload,
    LPFErrorCodeLocation,
    LPFErrorCodeBilling,
    LPFErrorCodeCart,
    LPFErrorCodeServer,
    LPFErrorCodeNoResponse
};

static NSString *LPFDefaultsUserFirstNameKey = @"LPFDefaultsUserFirstNameKey";
static NSString *LPFDefaultsUserLastNameKey = @"LPFDefaultsUserLastNameKey";
static NSString *LPFDefaultsUserPhoneNumberKey = @"LPFDefaultsUserPhoneNumberKey";
static NSString *LPFDefaultsUserEmailAddressKey = @"LPFDefaultsUserEmailAddressKey";
static NSString *LPFDefaultsMerchantIDKey = @"LPFDefaultsMerchantIDKey";
static NSString *LPFDefaultsContactFirstNameKey = @"LPFDefaultsContactFirstNameKey";
static NSString *LPFDefaultsContactLastNameKey = @"LPFDefaultsContactLastNameKey";
static NSString *LPFLocalConfigurationFileName = @"LPFConfiguration.json";

static NSString *LPFImageSourceDidAuthenticateNotification = @"LPFImageSourceDidAuthenticateNotification";
static NSString *LPFLifePicsDidLoginNotification = @"LPFLifePicsDidLoginNotification";
static int LPFImageMaxSize = 1024;
#define kLifePicsStagingBaseURL     @"http://staging.api.lifepics.com"
#define kLifePicsProductionBaseURL  @"https://api.lifepics.com"
//#define kAPIv3StagingURL            @"http://staging.api.lifepics.com/v3/LPWebService.asmx"
//#define kAPIv3ProductionURL         @"https://api.lifepics.com/v3/LPWebService.asmx"

#define kAPIv3Namespace         @"https://api.lifepics.com/v3/"
#define kXMLv3Namespace         @" xmlns=\"https://api.lifepics.com/v3/\">"

#define kInfoPlistPlaceholderPrefix     @"<add your"

#define kNewFirstName			@"LPNewFirstName"
#define kNewEmail				@"LPNewEmail"
#define kNewPassword			@"LPNewPassword"
#define kNewConfirmPassword		@"LPNewConfirmPassword"
#define kNewZipCode				@"LPNewZipCode"

#define kStoreDistance			@"LPStoreDistance"
#define kOrderZipCode			@"LPOrderZipCode"

#define kPartnerID				@"28"
#define kPartnerSourceID		@"11"
#define kPartnerPassword		@"y4tg21c5"

#define kShowInitApp			@"SHOW_INIT_APP"
#define kShowLoadingZip			@"SHOW_LOADING_ZIP_CODE"
#define kShowLoadingStores		@"SHOW_LOADING_STORES"
#define kShowLoadingProducts	@"SHOW_LOADING_PRODUCTS"
#define kShowSubmittingOrder	@"SHOW_SUBMITTING_ORDER"
#define kShowSavingImage		@"SHOW_SAVING_IMAGE"
#define kShowAddToCart			@"SHOW_ADDING_TO_CART"
#define kShowUpdatingCart		@"SHOW_UPDATING_CART"
#define kShowEmptyingCart		@"SHOW_EMPTYING_CART"
#define kHideLoading			@"HIDE_LOADING"

#define kDtlLoadingDB			@"DTLS_LOADING_DB"
#define kDtlAlbumsTab			@"DTLS_ALBUMS_TAB"
#define kDtlUploadsTab			@"DTLS_UPLOADS_TAB"
#define kDtlCartTab				@"DTLS_CART_TAB"
#define kDtlCameraTab			@"DTLS_CAMERA_TAB"
#define kDtlPendingTab			@"DTLS_PENDING_TAB"
#define kDtlSettingsTab			@"DTLS_SETTINGS_TAB"
#define kDtlLoadingImages		@"DTLS_LOADING_IMAGES"
#define kDtlLoginScreen			@"DTLS_LOGIN_SCREEN"
#define kDtlNetworkStatus		@"DTLS_NETWORK_STATUS"

// PayPal Details
#define kPayPalURL				@"https://api-3t.sandbox.paypal.com/nvp"
#define kPayPalUser				@""
#define kPayPalPass				@""
#define kPayPalSignature		@""
#define kPayPalMethod			@"DoDirectPayment"
#define kPayPalVersion			@"2.3"

//Types groups
#define kCanvas @"Canvas"
//#define kCanvasProductCategoryID @"4"

//Types canvas
#define kWhite @"White"
#define kBlack @"Black"
#define kWrap @"Wrap"

//iOS Version
#define iOS9_LATER [[UIDevice currentDevice].systemVersion floatValue] >= 9.0 ? YES : NO

// Merchant IDs for branding
enum
{
	idRitz = 997,
	idCamcor = 5225,
	idBedford = 154,
	idMikesCamera = 1,
	idDans = 4609,
	idArista = 5395, // Arista Camera
	idFotoPass = 511, // FotoPass
	idHenrys = 3586, // Henry's Pix
	idLawrence = 5575, // Lawrence
	idCordCamera = 2312, // Cord Camera
	idUniquePhoto = 4392,
    idBartells = 971,
    idIPI = -999,
    idKadair = 4965,
    idTeds = 4989,
    idPitman = 5075,
    idThrifty = 4295,
    idPersnickety = 5302,
    idHooper = 5503,
    idLees = 5816,
    idCCY = 5809, // Camera Center of York

	kToolBarColorR = 17,
	kToolBarColorG = 17,
	kToolBarColorB = 68,
};

// Tab IDs
enum
{
	kTabAlbums = 0,
	kTabUpload = 0,
	kTabCard = 5, //1,
	kTabCart = 1, //2,
	kTabCamera = 2,
	kTabPending = 2, //3,
	kTabSettings = 3, //4,
};

// View IDs
enum
{
	kViewMain = 0,
	kViewLogin = 1,
	kViewOrder = 2,
	kViewPendingCart = 3,
	kViewSubmitOrder = 4,
	kViewCartProducts = 5,
	kViewCameraRoll = 6,
};

// Config Settings
enum 
{
	kMaxStackSize = 100, //0,
	iPadAlbumColumns = 4, //4,
	iPadAlbumLandscapeColumns = 5, //4,
	iPadAlbumThumbSize = 160, //130,
	iPadAlbumImageColumns = 4,
	iPadAlbumImageLandscapeColumns = 5, //4,
	iPadAlbumImageThumbSize = 180,
	iPadAlbumImageDesc = 0,
	iPadBuilderColumns = 4, //4,
	iPadBuilderLandscapeColumns = 5, //4,
	iPadBuilderThumbSize = 160, //130,
	
	iPadUploadColumns = 5,
	iPadUploadLandscapeColumns = 6,
	iPadUploadThumbSize = 140,
	iPadUploadDesc = 0,
	iPhoneAlbumColumns = 3, //1,
	iPhoneAlbumLandscapeColumns = 4, //1,
	iPhoneAlbumThumbSize = 90,
	iPhoneAlbumImageColumns = 3,
	iPhoneAlbumImageLandscapeColumns = 4, //1,
	iPhoneAlbumImageThumbSize = 90,
	iPhoneAlbumImageDesc = 0, //1,
	iPhoneUploadColumns = 3,
	iPhoneUploadLandscapeColumns = 4,
	iPhoneUploadThumbSize = 90,
	iPhoneUploadDesc = 1,
	iPhoneBuilderColumns = 2, //1,
	iPhoneBuilderLandscapeColumns = 3, //1,
	iPhoneBuilderThumbSize = 150,
};

// Payment Types
enum
{
	kPayment_None = 0,
	kPayment_PayInStore = 1,
	kPayment_PayPalShip = 2,
	kPayment_PayPalInStore = 3,
};

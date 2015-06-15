//
//  PhigitalSDK.h
//  PhigitalSDK
//
//  Created by Vassilis Legakis on 11/10/14.
//  Copyright (c) 2014 Phigital inc. All rights reserved.
//

#import "PhigitalProtocols.h"
#import "Experience.h"
#import "User.h"
#import "PhigitalViewController.h"
#import "PhigitalProtocols.h"

// Project version number for PhigitalSDK.
FOUNDATION_EXPORT double PhigitalSDKVersionNumber;

// Project version string for PhigitalSDK.
FOUNDATION_EXPORT const unsigned char PhigitalSDKVersionString[];

@class CLLocation;
@class User;

/*!
 *  @class Phigital
 *
 */
@interface Phigital : NSObject

/*!
 *   @abstract A static call that accesses the Phigital iOS SDK singleton.
 *   @function sharedInstance
 *   @discussion Your application will access most of Phigital's functionality through this singleton. Make this call 
 *   from within the Application's delegate didFinishLaunchingWithOptions method.
 */
+ (Phigital*)sharedInstance;

/*!
 *   @abstract A static call that initializes the Phigital iOS SDK and sets the Phigital application ID and secret.
 *   @function initWithAppId: andAppSecret:
 *   @discussion Phigital gives you an application ID and secrect at account activation. Make this call from within 
 *   the Application's delegate didFinishLaunchingWithOptions method.
 *   @param appID  The unique identifier for the application using the Phigital platform.
 *   @param appSecret  The application secret.
 */
+ (void)initWithAppId:(NSString*)appId andAppSecret:(NSString*)appSecret;

/*!
 *   @function signinWithUserName: andPassword:
 *   @abstract Authorizes a user, with a valid username and password, to use the Phigital platform. 
 *   @param userName  The user's username.
 *   @param password  The user's password.
 */
+ (void)signinWithUserName:(NSString*)userName andPassword:(NSString*)password;

/*!
 *  @function setBackgroundImage:
 *  @abstract (Optional.) A static call that sets the Phigital iOS SDK's main background parameters.
 *  @param backgroundImage  The UIImage object that defines the main background.
 */
+ (void)setBackgroundImage:(UIImage*)backgroundImage;

/*!
 *  @function setFontName:
 *  @abstract (Optional.) A static call that sets the Phigital iOS SDK's font name parameters.
 *  @param fontName  The UIFont object that defines the font family name.
 */
+ (void)setFontName:(NSString*)fontName;

/*!
 *  @function setNavigationColor:
 *  @abstract (Optional.) A static call that sets the Phigital iOS SDK's navigation bar color parameters.
 *  @param color  The UIColor object that defines the navigation bar's colors.
 */
+ (void)setNavigationColor:(UIColor*)color;

/*!
 *  @function setNavigationSecondaryColor:
 *  @abstract A static call that sets the Phigital iOS SDK's navigation bar secondary color parameters.
 *  @param color  The UIColor object that defines the navigation bar's secondary colors.
 */
+ (void)setNavigationSecondaryColor:(UIColor*)color;

/*!
 *  @function setTestMode:
 *  @abstract A static call that enables the test mode for the timeline.
 *  @param testModeOn  A Blooean flag that indicates whether or not the test mode is enabled.
 */
+ (void)setTestMode:(BOOL)testModeOn;

/*!
 *  @function getTestModeStatus
 *  @abstract A static call that checks whether or not the timeline is in test mode.
 *  @return A Boolean flag that indicates whether or not the test mode is enabled.
 */
+ (BOOL)getTestModeStatus;

/*!
 *   @function registerWithFirstName: andLastName: andEmail: andPassword:
 *   @abstract A static call that registers a new Phigital user using the user’s first name, 
 *   last name, email address, and user password.
 *   @param firstName  The user's first name.
 *   @param lastName   The user's last name.
 *   @param email      The user's email address.
 *   @param password   The user's password.
 */
+ (void)registerWithFirstName:(NSString*)firstName andLastName:(NSString*)lastName andEmail:(NSString*)email andPassword:(NSString*)password;

/*!
 *  @function resetPassword:
 *  @abstract A static call that resets the user’s password using the user’s email address.
 *  @param email  The user's email address.
 */
+ (void)resetPassword:(NSString*)email;

/*!
 *  @function getAppId
 *  @abstract A static call that returns the application ID.
 *  @return The application ID.
 */
+ (NSString*)getAppId;

/*!
 *  @function signOut
 *  @abstract A static call that signs out a user from the Phigital platform.
 */
+ (void)signOut;

/*!
 *  @function clearCache
 *  @abstract A static call that clears the Phigital cache.
 */
+ (void)clearCache;

/*!
 *  @function getUser
 *  @abstract A static call that returns the User object.
 *  @return User The User object.
 */
+ (User*)getUser;

/*!
 *   @function sendFeedback: andNotes:
 *   @abstract A static call that captures the user's feedback.
 *   @param userEmail   The user’s email address.
 *   @param userNotes   The user’s feedback comments.
 */
+ (void)sendFeedback:(NSString*)userEmail andNotes:(NSString*)userNotes;

/*!
 *   @function changePassword: withNew:
 *   @abstract A static call that changes the user's password.
 *   @param currentPassword  The user’s current password.
 *   @param newPassword      The user’s new password.
 */
+ (void)changePassword:(NSString*)currentPassword withNew:(NSString*)newPassword;

/*!
 *   @function signinWithFacebook:
 *   @abstract A static call that authorizes a user, with a valid Facebook token, to use the Phigital platform.
 *   @param token  The user’s Facebook token.
 */
+ (void)signinWithFacebook:(NSString*)token;

/*!
 *   @function requestPublishPermissionsForFacebook:
 *   @abstract A static call that authorizes a user, with a valid Facebook token, to use the Phigital platform.
 *   @param token  The user’s Facebook token. If permissions were denied, this can passed in a @"cancel" NSString for the process UI to cancel.
 */
+ (void)registerPublishPermissionsForFacebookWithToken:(NSString*)token;

/*!
 *   @function signinUserAs:
 *   @abstract A static call that authorizes a user, with a valid OAuth access token, to use the Phigital platform.
 *   @param userDetails  NSDictionary of user's details. The only required key is ‘uid’ and should contain the user’s 
 *   unique identifier. Optional keys are: ‘firstName’, ‘lastName’, and ‘email’.
 */
+ (void)signinUserAs:(NSDictionary*)userDetails;

/*!
 *  @function getActiveExperiences
 *  @abstract A static call that returns a list of active experiences.
 *  @return NSArray A list of active Experience objects.
 */
+ (NSArray*)getActiveExperiences;

/*!
 *  @function getCompletedExperiences
 *  @abstract A static call that returns a list of completed experiences.
 *  @return NSArray A list of completed Experience objects.
 */
+ (NSArray*)getCompletedExperiences;

/*!
 *  @function setDelegate:
 *  @abstract A static call that sets the Phigital iOS SDK's delegate for PhigitalProtocol callback methods.
 *  @param delegate  The PhigitalProtocol compliant object.
 */
+ (void)setDelegate:(NSObject<PhigitalProtocol>*)delegate;

/*!
 *  @function setUiDelegate:
 *  @abstract A static call that sets the Phigital iOS SDK's UI delegate for PhigitalProtocol callback methods.
 *  @param delegate  The PhigitalProtocol compliant object.
 */
+ (void)setUiDelegate:(UIViewController<PhigitalProtocol>*)delegate;

/*!
 *  @function enableSound:
 *  @abstract A static call that enables sound effects.
 *  @param sounds  A Boolean flag that indicates whether or not sound effects are enabled.
 */
+ (void)enableSound:(BOOL)sounds;

/*!
 *  @function getSoundStatus
 *  @abstract A static call that checks whether or not sound effects are enabled.
 *  @return A Boolean flag that indicates whether or not sound effects are enabled.
 */
+ (BOOL)getSoundStatus;

/*!
 *  @function startExperienceWithId:
 *  @abstract A static call that starts a Phigital experience, with the given identifier, and displays the timeline.
 *  @param experienceId  The identifier of the experience to start.
 */
+ (void)startExperienceWithId:(NSString*)experienceId;

/*!
 *  @function stopExperienceWithId:
 *  @abstract A static call that stops a Phigital experience with the given identifier.
 *  @param experienceId  The identifier of the experience to stop.
 */
+ (void)stopExperienceWithId:(NSString*)experienceId;

/*!
 *  @function getAboutWithId:
 *  @abstract A static call that gets the About page for the Phigital experience with the given identifier.
 *  @param experienceId  The identifier for the Phigital experience.
 *  @return The Phigital experience identifier.
 */
+ (UIViewController*)getAboutWithId:(NSString*)experienceId;

/*!
 *  @function getDiscover
 *  @abstract A static call that gets the Phigital Discovery page.
 *  @return The Phigital experience search controller.
 */
+ (UIViewController*)getDiscover;

/*!
 *  @function getRewards
 *  @abstract A static call that gets the Phigital Rewards page for the Phigital experience with the given identifier.
 *  @return The rewards controller.
 */
+ (UIViewController*)getRewards;

/*!
 *  @function getEventStreamWithId:
 *  @abstract A static call that gets the Phigital experience with the given identifier.
 *  @param experienceId  The identifier for the experience timeline.
 *  @return The timeline controller.
 */
+ (UIViewController*)getEventStreamWithId:(NSString*)experienceId;

/*!
 *  @function checkPermissions
 *  @abstract A static call that checks device permissions and setup. Callback is deliver in onError of the SDK's delegate.
 */
+ (void)checkPermissions;

/*!
 *  @function requestLocationPermissions
 *  @abstract A static call that requests location monitoring permissions.
 */
+ (void)requestLocationPermissions;

/*!
 *  @function resetExternalAuthorizationForService:
 *  @abstract A static call that resets Phigital external authorization for a specific service.
 *  @param service. A string with the service identifier. e.g "facebook", "twitter". Providing "all" will reset all services.
 */
+ (void)resetExternalAuthorizationForService:(NSString*)service;

/*!
 *  @function  application: didRegisterForRemoteNotificationsWithDeviceToken:
 *  @abstract A static call to register for remote notifications with a device token.
 *  @discussion A forward method that must be called from within the UIApplicationDelegate's relevant methods.
 *  @param application  UIApplication.
 *  @param deviceToken  The device token data.
 */
+ (void)application:(UIApplication*)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData*)deviceToken;

/*!
 *  @function  application: didFailToRegisterForRemoteNotificationsWithError:
 *  @abstract A static call that gets failure error.
 *  @discussion A forward method that must be called from within the UIApplicationDelegate's relevant methods.
 *  @param application  UIApplication.
 *  @param error  NSError.
 */
+ (void)application:(UIApplication*)application didFailToRegisterForRemoteNotificationsWithError:(NSError*)error;

/*!
 *  @function  application: didReceiveRemoteNotification:
 *  @abstract A static call that gets the user's information.
 *  @discussion A forward method that must be called from within the UIApplicationDelegate's relevant methods.
 *  @param application  UIApplication.
 *  @param userInfo  NSDictionary of the user's information.
 */
+ (void)application:(UIApplication*)application didReceiveRemoteNotification:(NSDictionary*)userInfo;

/*!
 *  @function  application: didReceiveLocalNotification:
 *  @abstract This static call gets local notification.
 *  @discussion This is forward method  required to be called from your UIApplicationDelegate's relevant methods.
 *  @param application  UIApplication.
 *  @param notification  Local notification.
 */
+ (void)application:(UIApplication*)application didReceiveLocalNotification:(UILocalNotification*)notification;

/*!
 *  @function  application: openURL: sourceApplication: annotation:
 *  @abstract This is forward method required to be called from your UIApplicationDelegate's relevant methods.
 *  @param application  UIApplication.
 *  @param url  NSURL.
 *  @param sourceApplication  Source application string.
 *  @param annotation  Annotation.
 *  @return Boolean response
 */
+ (BOOL)application:(UIApplication*)application openURL:(NSURL*)url sourceApplication:(NSString*)sourceApplication annotation:(id)annotation;
 
/*! 
 *  @function setTimelineMode:
 *  @abstract A static call that sets the timeline mode.
 *  @param timelineMode  The timeline mode.
 */
+ (void)setTimelineMode:(PhigitalTimelineMode)timelineMode;

@end
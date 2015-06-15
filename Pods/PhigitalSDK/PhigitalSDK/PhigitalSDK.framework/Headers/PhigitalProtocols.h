//
//  PhigitalProtocols.h
//  PhigitalSDK
//
//  Created by Vassilis Legakis on 12/22/14.
//  Copyright (c) 2014 Phigital. All rights reserved.
//

#ifndef PhigitalSDK_PhigitalProtocols_h
#define PhigitalSDK_PhigitalProtocols_h

@class PhigitalViewController;
@class Experience;

/*!
 *   @typedef PhigitalUserRole
 *   @abstract  Types of Phigital Users' Roles
 *    
 */
typedef enum
{
    PHUserRoleExperienceParticipant,
    PHUserRoleExperienceTester
} PhigitalUserRole;


/*!
 *   @typedef PhigitalTimelineMode
 *   @abstract  The different types of Phigital Timelines; a list view or a carousel.
 */
typedef enum
{
    PHTimelineModeListView,
    PHTimelineModeCarousel
} PhigitalTimelineMode;

/*!
 *   @typedef PhigitalExperienceStatus
 *   @abstract  The different types of Phigital Experience statuses, from the user's perspective.
 */
typedef enum
{
    PHExperienceStatusInactive,
    PHExperienceStatusActive,
    PHExperienceStatusCompleted
} PhigitalExperienceStatus;

/*!
 *   @typedef PhigitalErrorCode
 *   @abstract  The different types of Phigital errors.
 */

typedef enum
{
    PHErrorPermissionsLocationServicesMissing,
    PHErrorPermissionsPhotoAlbumAccessMissing,
    PHErrorPermissionsPushNotificaionsMissing,
    PHErrorURLSchemaNotRegistered,
    PHErrorMissingPublishAuthorization
} PhigitalErrorCode;

/*!
 *   @abstract The Phigital Error Domain for the returned NSError.
 */
extern NSString* const phigitalErrorDomain;


/*!
 *  @class PhigitalProtocol
 *
 */

@protocol PhigitalProtocol

@optional

/*! 
 *   @abstract A callback method that indicates that the experience has been started.
 *   @function experienceStarted:
 *   @param experience The experience that was started.
 */
- (void)experienceStarted:(Experience*)experience;

/*! 
 *   @abstract A callback method that indicates that the experience has finished.
 *   @function experienceStopped:
 *   @param stopExpSuccess A Boolean flag that indicates whether or not the experience has finished.
 */
- (void)experienceStopped:(BOOL)stopExpSuccess;

/*! 
 *   @abstract A callback method that returns the login response.
 *   @function finishedSignIn:
 *   @param logInSuccess A Boolean flag that indicates whether or not the login was successful.
 */
- (void)finishedSignIn:(BOOL)logInSuccess;

/*!
 *   @abstract A callback method that returns the sign up response.
 *   @function finishedSignUp:
 *   @param signUpSuccess A Boolean flag that indicates whether or not the signup was successful.
 */
- (void)finishedSignUp:(BOOL)signUpSuccess;

/*! 
 *   @abstract  A callback method that returns the password reset response.
 *   @function finishedResetPassword:
 *   @param resetSuccess  A Boolean flag that indicates whether or not the password reset was successful.
 */
- (void)finishedResetPassword:(BOOL)resetSuccess;

/*!
 *   @abstract  A callback method that returns the password change response.
 *   @function finishedChangePassword:
 *   @param changeSuccess  A Boolean flag that indicates whether or not the password change was successful.
 */
- (void)finishedChangePassword:(BOOL)changeSuccess;

/*! 
 *   @abstract   A callback method that returns an error generated from Phigital SDK.
 *   @function onError:
 *   @param error  The error description.
 */
- (void)onError:(NSError*)error;

/*!
 *   @abstract   A callback method that returns whenever there is a change in test mode status
 *   @function testModeStatusChanged:
 *   @param testModeEnabled  The Test Mode Status.
 */
- (void)testModeStatusChanged:(BOOL)testModeEnabled;

/*!
 *   @abstract   A callback method that returns whenever there is a compatibility check
 *   @function upgradeRequired:
 *   @param upgrade  Whether there is an SDK upgrade required.
 */
- (void)upgradeRequired:(BOOL)upgrade;

#pragma mark SDK passthrough requests
/*! 
 *   @abstract  A request from the timeline to scan code.
 *   @discussion  If this method is not implemented or if it returns nil, then the Phigital SDK will use its default scanner.
 */
- (PhigitalViewController*)scanCodeViewControllerRequest:(PhigitalViewController*)defaultController;

/*! 
 *   @abstract  A request from the SDK for an experience details view controller.
 *   @discussion  If this method is not implemented or if it returns nil, then the Phigital SDK will use its default experience details view controller.
 */
- (PhigitalViewController*)experienceDetailsViewControllerRequest:(PhigitalViewController*)defaultController;

/*! 
 *   @abstract  A request from the SDK for an experience timeline view controller.
 *   @discussion  If this method is not implemented or if it returns nil, then the Phigital SDK will use its default experience timeline view controller.
 */
- (PhigitalViewController*)experienceTimelineViewControllerRequest:(PhigitalViewController*)defaultController;

/*! 
 *   @abstract  A request from the SDK for a discover experiences view controller.
 *   @discussion  If this method is not implemented or if it returns nil, then the Phigital SDK will use its default discover experiences view controller.
 */
- (PhigitalViewController*)discoverExperiencesViewControllerRequest:(PhigitalViewController*)defaultController;

/*! 
 *   @abstract  A callback method that returns the experience rewards view controller.
 *   @discussion  If this method is not implemented or if it returns nil, then the Phigital SDK will use its default experience rewards view controller.
 */
- (PhigitalViewController*)rewardsViewControllerRequest:(PhigitalViewController*)defaultController;

@end


#endif

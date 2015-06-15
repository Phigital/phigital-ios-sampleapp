//
//  PhigitalUtils.h
//  PhigitalSDK
//
//  Created by Vassilis Legakis on 1/11/15.
//  Copyright (c) 2015 Phigital. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 *  @class PhigitalUtils
 *
 */

@interface PhigitalUtils : NSObject

/*!
*  @function phigitalScanner
*  @abstract A static call that returns the Phigital Code Scanner.
*  @return The Phigital Code Scanner.
*/
+ (UIViewController*)phigitalScanner;

/*!
 *  @function playAudioFX:
 *  @abstract A static call that plays an audio file.
 *  @param audioFileName  The name of the audio file to play.
 */
+ (void)playAudioFX:(NSString*)audioFileName;

/*!
 *  @function playBackgroundAudio: looping:
 *  @abstract A static call that plays an audio file in the background.
 *  @param audioFileName  The name of the audio file to play.
 *  @param loop  A Boolean flag that indicates whether or not audio looping is enabled.
 */
+ (void)playBackgroundAudio:(NSString*)audioFileName looping:(BOOL)loop;

/*!
 *  @function stopBackgroundAudio
 *  @abstract A static call that stops playing background audio.
 */
+ (void)stopBackgroundAudio;

/*!
 *  @function phigitalBlue
 *  @abstract A static call that returns the Phigital color.
 *  @return Phigital UIColor.
 */
+ (UIColor*)phigitalBlue;

/*!
 *  @function location
 *  @abstract A static call that returns the location indicated by the Phigital SDK.
 *  @discussion This is provided in case the application has a need for location services, but the application does not
 *  implement its own Location Manager implmentation.
 *  @return Location The location indicated by the Phigital SDK.
 */
+ (CLLocation*)location;

/*!
 *  @function testModeLocation
 *  @abstract A static call that returns the location indicated by thec Phigital SDK test mode.
 *  @return Location The location indicated by the Phigital SDK test mode.
 */
+ (CLLocation*)testModeLocation;

/*!
 *  @function parsePhigitalUrl
 *  @abstract A static helpers call which break Phigital URL schemas down.
 *  @return A NSDictionary with the parameters - broken down components of a phigital URL schema
 */
+ (NSDictionary*)parsePhigitalUrl:(NSString*)phigitalUrlSchema;

/*!
 *  @function shouldLogin
 *  @abstract A static call that checks whether or not a login is required (before any network interactions).
 *  @return A Boolean flag that indicates whether or not a login is required.
 */
+ (BOOL)shouldLogin;

/*!
 *  @function progressIndicator
 *  @abstract A static call that shows a Progress indicator
 *  @param show A Boolean flag that indicates whether to show or hide the progress indicator.
 *  @param description The test to be presented from the progress modal indicator if show is YES else ignored.
 */
+ (void)progressIndicator:(BOOL)show withDescription:(NSString*)description;

@end

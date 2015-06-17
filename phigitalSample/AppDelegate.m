//
//  AppDelegate.m
//  phigitalSample
//
//  Created by giamou giannis
//  Copyright (c) 2015 Phigital. All rights reserved.
//

#import "AppDelegate.h"
#import <PhigitalSDK/Phigital.h>
#import <CoreLocation/CoreLocation.h>

@interface AppDelegate () <PhigitalProtocol, CLLocationManagerDelegate>

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    [Phigital setDelegate:self];
    NSString* appId = @"YourAppID";
    NSString* appSecret = @"YourAppSecret";
    [Phigital initWithAppId:appId andAppSecret:appSecret];
    
    CLLocationManager *locationManager = [[CLLocationManager alloc] init];
    [locationManager setDelegate:self];
    [locationManager requestAlwaysAuthorization];
    [locationManager startUpdatingLocation];
    
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}


- (void)application:(UIApplication*)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData*)deviceToken
{
    [Phigital application:application didRegisterForRemoteNotificationsWithDeviceToken:deviceToken];
}

- (void)application:(UIApplication*)application didFailToRegisterForRemoteNotificationsWithError:(NSError*)error
{
    [Phigital application:application didFailToRegisterForRemoteNotificationsWithError:error];
}

- (void)application:(UIApplication*)application didReceiveRemoteNotification:(NSDictionary*)userInfo
{
    [Phigital application:application didReceiveRemoteNotification:userInfo];
}

- (void)application:(UIApplication*)application didReceiveLocalNotification:(UILocalNotification*)notification
{
    //Forward to Phigital SDK
    [Phigital application:application didReceiveLocalNotification:notification];
}

- (void)onError:(NSError*)error
{
    if (error != nil)
    {
        //Check for Location Permissions
        if (error.code == PHErrorPermissionsLocationServicesMissing)
        {
            UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"PhigitalSample needs Location Services to be enabled"
                                                            message:@"Go to Settings -> Privacy -> Location Services -> phigitalSample and enable location services"
                                                           delegate:self
                                                  cancelButtonTitle:@"OK"
                                                  otherButtonTitles:nil];
            [alert show];
        }
    }
}

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    [alertView dismissWithClickedButtonIndex:buttonIndex animated:YES];
    [[UIApplication sharedApplication] openURL: [NSURL URLWithString: UIApplicationOpenSettingsURLString]];
}

- (BOOL)application:(UIApplication*)application openURL:(NSURL*)url sourceApplication:(NSString*)sourceApplication annotation:(id)annotation
{
    //Get URL schemes handled by app
    NSArray* bundleUrlTypesArray = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleURLTypes"];
    NSDictionary* bundleUrlTypesDic = [bundleUrlTypesArray lastObject];
    NSArray* bundleUrlSchemes = [bundleUrlTypesDic objectForKey:@"CFBundleURLSchemes"];
    NSString* phigitalSchema = [bundleUrlSchemes objectAtIndex:0];

    NSString* handledUrlString = [url absoluteString];
    if ([handledUrlString rangeOfString:phigitalSchema].length > 0)
    {
        BOOL handledURL = [Phigital application:application openURL:url sourceApplication:sourceApplication annotation:annotation];
        return handledURL;
    }
    else
    {
        return NO;
    }
}

@end

//
//  Experience.h
//  PhigitalSDK
//
//  Created by Vassilis Legakis on 1/9/15.
//  Copyright (c) 2015 Phigital. All rights reserved.
//

#import "PhigitalProtocols.h"

@class User;

/*!
 *  @class Experience
 *
 */

@interface Experience : NSObject <NSCoding>

/*! @abstract The identifier for the experience. */
@property (nonatomic, strong) NSString* identifier;

/*! @abstract The author of the experience. */
@property (nonatomic, readonly) User* author;

/*! @abstract The title of the experience. */
@property (nonatomic, readonly) NSString* experienceTitle;

/*! @abstract The completion date for the experience. */
@property (nonatomic, readonly) NSDate* experienceCompetionDate;

/*! @abstract The status for the experience. */
@property (nonatomic, readonly) PhigitalExperienceStatus experienceStatus;

/*! @abstract Whether the experience is Test Mode enabled. */
@property (nonatomic, assign) BOOL isTestModeEnabled;

@end

//
//  User.h
//  PhigitalSDK
//
//  Created by Vassilis Legakis on 3/9/15.
//  Copyright (c) 2015 Phigital. All rights reserved.
//
#import "PhigitalProtocols.h"
@class Experience;

/*!
 *  @class User
 *
 */

@interface User : NSObject <NSCoding>

/*! @abstract The identifier of the user. */
@property (nonatomic, strong) NSString* identifier;

/*! @abstract  The name of the user. */
@property (nonatomic, readonly) NSString* usersName;

/*! @abstract The avatar of the user. */
@property (nonatomic, readonly) UIImage* usersAvatarImage;

/*! @abstract The email of the user. */
@property (nonatomic, readonly) NSString* usersEmail;

/*! @abstract  The role of user. */
@property (nonatomic, readonly) PhigitalUserRole usersRole;

/*! @abstract The current experience of user. */
@property (nonatomic, readonly) Experience* usersCurrentExperience;

@end

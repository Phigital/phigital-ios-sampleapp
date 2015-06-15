//
//  PhigitalViewController.h
//  PhigitalSDK
//
//  Created by Vassilis Legakis on 1/13/15.
//  Copyright (c) 2015 Phigital. All rights reserved.
//

#import <UIKit/UIKit.h>

/*!
 *  @class PhigitalViewController
 *
 */

@interface PhigitalViewController : UIViewController

/*! @abstract The top left button of the PhigitalViewController. */
@property (nonatomic, strong) UIButton* topLeftButton;

/*! @abstract The Boolean value for the controller's transluscent navigation bar. */
@property (nonatomic, assign) BOOL transluscentNavigationBar;

/*! @abstract The color of the controller's navigation bar. */
@property (nonatomic, strong) UIColor* barTintColor;

@end

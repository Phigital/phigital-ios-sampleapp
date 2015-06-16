//
//  ViewController.h
//  phigitalSample
//
//  Created by giamou giannis
//  Copyright (c) 2015 Phigital. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController <UIPickerViewDataSource, UIPickerViewDelegate>

{
    IBOutlet UITextField *idField;
    IBOutlet UITextField *pwdField;
    UIActivityIndicatorView *spinner;
}

@property (nonatomic, strong) UIPickerView *imageSelect;
@property (nonatomic, strong) NSMutableArray *pickerData;

-(IBAction)goPhigital:(id)sender;
-(IBAction)phigitalStartExperience;

@end


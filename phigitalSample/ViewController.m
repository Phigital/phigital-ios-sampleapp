//
//  ViewController.m
//  phigitalSample
//
//  Created by giamou giannis
//  Copyright (c) 2015 Phigital. All rights reserved.
//

#import "ViewController.h"
#import <PhigitalSDK/Phigital.h>
#import <PhigitalSDK/PhigitalUtils.h>

@interface ViewController () <PhigitalProtocol>

@end

@implementation ViewController
@synthesize imageSelect, pickerData;

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.

    //Make navigation bar translucent
    [self.navigationController.navigationBar setTranslucent:YES];
    [self.navigationController.navigationBar setBackgroundImage:[UIImage new] forBarMetrics:UIBarMetricsDefault];
    [self.navigationController.navigationBar setShadowImage:[UIImage new]];

    //Add PickerView for TimeLine background image selection
    pickerData= [[NSMutableArray alloc] initWithObjects:@"Image1",@"Image2",@"Image3",@"Image4", nil];
    imageSelect = [[UIPickerView alloc] initWithFrame:CGRectMake(10, 310, 300, 200)];
    imageSelect.showsSelectionIndicator = YES;
    imageSelect.hidden = NO;
    imageSelect.delegate = self;
    [self.view addSubview:imageSelect];
    
    //Set the delegate for experienceTimelineViewControllerRequest:  callback customization method
    [Phigital setUiDelegate:self];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void) goPhigital:(id)sender
{
    NSString *idValue = idField.text;
    NSString *pwdValue = pwdField.text;
    
    [Phigital setDelegate:self];

    //Check if user is logged in
    if(![PhigitalUtils shouldLogin]){
       
       //Launch Discover
       UIViewController *discoverController = [Phigital getDiscover];
       [self.navigationController pushViewController:discoverController animated:YES];
    }
    else{
   
        //Log In
       [Phigital signinWithUserName:idValue andPassword:pwdValue];
        
        //Add ActivityIndicator
        spinner = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleGray];
        spinner.center = CGPointMake(160, 280);
        [self.view addSubview:spinner];
        [spinner startAnimating];
    }
}

-(void)finishedSignIn:(BOOL)logInSuccess{
    
    if(logInSuccess){
        
        //Remove ActivityIndicator
        [spinner stopAnimating];
         [Phigital setDelegate:self];
        [Phigital setUiDelegate:self];
        
        //Launch Discover
        UIViewController *discoverController = [Phigital getDiscover];
        [self.navigationController pushViewController:discoverController animated:NO];
        
        NSLog(@"login success");
    }
}

//Customize Discover Controller
- (PhigitalViewController*)discoverExperiencesViewControllerRequest:(PhigitalViewController*)defaultController
{
    UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
    button.frame = CGRectMake(0.0f, 0.0f, 22.0f, 22.0f);
    [button setBackgroundImage:[UIImage imageNamed:@"icon_back"] forState:UIControlStateNormal];
    [button setBackgroundImage:[UIImage imageNamed:@"icon_back"] forState:UIControlStateHighlighted];
    //Set Button Action to popViewController
    [button addTarget:defaultController.navigationController action:@selector(popViewControllerAnimated:) forControlEvents:UIControlEventTouchUpInside];
    defaultController.topLeftButton = button;
    defaultController.transluscentNavigationBar = YES;
    return defaultController;
}


/*Phigital TimeLine example Implementation*/

//Start an experience
- (void)phigitalStartExperience
{
   [Phigital setDelegate:self];

    //Check if user is logged in
    if([PhigitalUtils shouldLogin]){
        
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"You are not logged in!"
                                                        message:@"Press GO to log in!"
                                                       delegate:self
                                              cancelButtonTitle:@"OK"
                                              otherButtonTitles:nil];
        [alert show];
    }
    
    else{
        
    //Set experience Id
    NSString* expId = @"expTUSRjNhB";
    
    //Launch experience
    [Phigital startExperienceWithId:expId];
    }
}

//Get experience started responce and launch TimeLine Controller
- (void)experienceStarted:(Experience*)experience
{
    UIViewController *timeLineController = [Phigital getEventStreamWithId:[experience identifier]];
    [self.navigationController pushViewController:timeLineController animated:YES];
}

//Customize TimeLine Controller
- (PhigitalViewController*)experienceTimelineViewControllerRequest:(PhigitalViewController*)defaultController
{
    UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
    button.frame = CGRectMake(0.0f, 0.0f, 22.0f, 22.0f);
    [button setBackgroundImage:[UIImage imageNamed:@"icon_back"] forState:UIControlStateNormal];
    [button setBackgroundImage:[UIImage imageNamed:@"icon_back"] forState:UIControlStateHighlighted];
    //Set Button Action to popViewController
    [button addTarget:defaultController.navigationController action:@selector(popViewControllerAnimated:) forControlEvents:UIControlEventTouchUpInside];
    defaultController.topLeftButton = button;
    defaultController.transluscentNavigationBar = YES;
    return defaultController;
}


/*UIPickerView Implementation for TimeLine background image selection*/

- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView; {
    return 1;
}

- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component; {
    return [pickerData count];
}

-(NSString*) pickerView:(UIPickerView*)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component
{
    return [pickerData objectAtIndex:row];
}

- (void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component;
{
    //Change TimeLine background image
    NSString* img = [NSString stringWithFormat:@"Image-%d",row];
    UIImage* background = [UIImage imageNamed:img];
    [Phigital setBackgroundImage:background];
}

@end

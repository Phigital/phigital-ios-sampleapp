//
//  phigitalSample_Tests.m
//  phigitalSample Tests
//
//  Created by giamou giannis on 6/17/15.
//  Copyright (c) 2015 phigital. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <XCTest/XCTest.h>
#import <PhigitalSDK/Phigital.h>
#import <PhigitalSDK/PhigitalUtils.h>

@interface phigitalSample_Tests : XCTestCase

@end

@implementation phigitalSample_Tests

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testExample {
    // This is an example of a functional test case.
    XCTAssert(YES, @"Pass");
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

- (void)testSignIn
{
    [Phigital initWithAppId:@"YourAppID" andAppSecret:@"YourAppSecret"];
    [Phigital signinWithUserName:@"YourEmail" andPassword:@"YourPassword"];
    [[NSRunLoop currentRunLoop] runUntilDate:[NSDate dateWithTimeIntervalSinceNow:2.0]];
    
    XCTAssertTrue(![PhigitalUtils shouldLogin], @"Operation Fail");
}

@end

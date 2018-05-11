//
//  AppDelegate.m
//  CentrixlinkDemo
//
//  Created by Centrixlink on 16/8/12.
//  Copyright © 2016年 Centrixlink. All rights reserved.
//

#import "CLAppDelegate.h"
#import <CentrixlinkRTB/CentrixlinkRTB.h>
#import "CLViewController.h"
@interface CLAppDelegate ()
{
    CLViewController *vc;
}

@end

@implementation CLAppDelegate

const NSString *  App_ID = @"CL_APP_ID";
const NSString * App_Key = @"CL_APP_KEY";

/* 实际开发中请使用自己申请的AppID 和 AppSecretKey */
const NSString *  Default_App_ID = @"APP_0_20180507_5aeff2a9460000000d61ce3a";
const NSString * Default_App_Key = @"NK2eVTUbFmCiNs5yA0odyuJQVVbSkA6Ssk4Q5DU2I8eKrHWHLsmpDA7YfbR1Or9bzfOZZgVqP22ZLDVnKLtXIO15L8X0r7UBZYfPeE34HZbTZjPCP9uHjhi9CwvkuMkS";

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    [[CLRTBCentrixlinkAD sharedInstance] setDebugEnable:YES];
    
    NSError *error;
    
    extern NSString *App_ID;
    extern NSString *App_Key;
    
    NSString *appId = [[NSUserDefaults standardUserDefaults] objectForKey:App_ID];
    NSString *appKey = [[NSUserDefaults standardUserDefaults] objectForKey:App_Key];
    if (appId.length && appKey.length) {
        //
    }else {
        extern NSString *Default_App_ID;
        extern NSString *Default_App_Key;
        appId = Default_App_ID;
        appKey = Default_App_Key;
        
        [[NSUserDefaults standardUserDefaults] setObject:Default_App_ID forKey:App_ID];
        [[NSUserDefaults standardUserDefaults] setObject:Default_App_Key forKey:App_Key];
        [[NSUserDefaults standardUserDefaults] synchronize];
    }
    
    [[CLRTBCentrixlinkAD sharedInstance] setPlayAdOrientation:UIInterfaceOrientationMaskAll];
    
    [[CLRTBCentrixlinkAD sharedInstance] startWithAppID:appId appSecretKey:appKey error:nil];
    if (error) {
        NSLog(@"startWithAppID Error %@",error);
    }
    vc = (CLViewController *) [self.window rootViewController];
    return YES;
}





-(NSString *)logmessage{
    if(_logmessage == NULL)
    {
        _logmessage = @"";
    }
    
    return _logmessage;
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

@end

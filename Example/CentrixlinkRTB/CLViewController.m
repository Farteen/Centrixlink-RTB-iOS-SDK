//
//  ViewController.m
//  CentrixlinkDemo

#import "CLViewController.h"
#import <CentrixlinkRTB/CentrixlinkRTB.h>
#import "CLAppDelegate.h"

@interface CLViewController ()<CLRTBCentrixlinkADDelegate>

@property (nonatomic, weak) IBOutlet UIButton *resetButton;
@property (nonatomic, weak) IBOutlet UIButton *fullButton;
@property (nonatomic, weak) IBOutlet UIButton *interButton;
@property (weak, nonatomic) IBOutlet UITextField *appIDTextField;
@property (weak, nonatomic) IBOutlet UILabel *label;
@property (weak, nonatomic) IBOutlet UITextField *appKeyTextField;

@end

@implementation CLViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    self.title = [NSString stringWithFormat:@"当前版本%@",[CLRTBCentrixlinkAD SDKVersion]];
    [self.interButton setEnabled:NO];
    [self.fullButton setEnabled:NO];
    
    extern NSString *App_ID;
    extern NSString *Default_App_ID;
    NSString *appId = [[NSUserDefaults standardUserDefaults] objectForKey:App_ID];
    if ([appId isEqualToString:Default_App_ID]) {
        self.label.text = @"当前正在使用: 默认AppID & AppKey";
    }else {
        self.label.text = @"当前正在使用: Yout AppID & AppKey";
    }
    
    NSLog(@"Start SDK %@", [CLRTBCentrixlinkAD SDKVersion]);
    [[CLRTBCentrixlinkAD sharedInstance] setDelegate:self];
    
    [[CLRTBCentrixlinkAD sharedInstance] setDebugCallBack:^(NSString *message, CLRTBStreamLogLevel level) {
        [self outputMessage:message];
    }];
    
    extern NSString *App_ID;
    extern NSString *App_Key;
    
    extern NSString *Default_App_ID;
    extern NSString *Default_App_Key;
    
    self.label.text = @"当前正在使用: 默认AppID & AppKey";
    
    [[NSUserDefaults standardUserDefaults] setObject:Default_App_ID forKey:App_ID];
    [[NSUserDefaults standardUserDefaults] setObject:Default_App_Key forKey:App_Key];
    [[NSUserDefaults standardUserDefaults] synchronize];
    
    [[CLRTBCentrixlinkAD sharedInstance] startWithAppID:Default_App_ID appSecretKey:Default_App_Key error:nil];
}


-(void)outputMessage:(NSString *)message {
    
}

#pragma mark ----CentrixlinkDelegate
- (void)centrixlinkRTBADPlayability:(BOOL)isAdPlayable {
    [self.interButton setEnabled:isAdPlayable];
    [self.fullButton setEnabled:isAdPlayable];
    NSString *message =  [ NSString stringWithFormat:@"Preload Status %@ ", isAdPlayable?@"can play": @"No"];
    //    [self outputMessage:message];
    NSLog(@"%@", message);
}

- (void)centrixlinkRTBVideoADWillShow:(NSDictionary *)ADInfo {
    NSString *message =  @" ***CallBack*** \n - (void)centrixLinkVideoADWillShow:(NSDictionary *)ADInfo \n";
    //    [self outputMessage:message];
    NSLog(@"%@", message);
}

- (void)centrixlinkRTBVideoADDidShow:(NSDictionary *)ADInfo {
    NSString *message =  @" ***CallBack*** \n - (void)centrixLinkVideoADDidShow:(NSDictionary *)ADInfo \n";
    //    [self outputMessage:message];
    NSLog(@"%@", message);
    
}

- (void)centrixlinkRTBVideoADClose:(NSDictionary *)ADInfo {
    NSString *message =  @" ***CallBack*** \n - (void)centrixLinkVideoADClose:(NSDictionary *)ADInfo \n";
    //    [self outputMessage:message];
    NSLog(@"%@", message);
    
    NSLog(@"close-ADInfo = %@", ADInfo);
}

- (void)centrixlinkRTBVideoADAction:(NSDictionary *)ADInfo {
    NSString *message =  @" ***CallBack*** \n - (void)centrixLinkVideoADAction:(NSDictionary *)ADInfo \n";
    //    [self outputMessage:message];
    NSLog(@"%@", message);
}

- (void)centrixlinkRTBVideoADShowFail:(NSError *)error {
    NSString *message =  [NSString stringWithFormat:@" ***CallBack*** \n - (void)centrixLinkVideoADShowFail:(NSError *)error %@\n", error];
    //    [self outputMessage:message];
    NSLog(@"%@", message);
}


-(IBAction)ADClick:(id)sender
{
    //当前是否可以显示广告
    CLRTBCentrixlinkAD *manager = [CLRTBCentrixlinkAD sharedInstance];
    NSError *error;
    if([manager isAdPlayable]) {
        //manager.hasPreloadAD可预先判断是否有有效预加载广告
        [manager playAD:self options:nil error:&error];
        if (error) {
            [self outputMessage:[error description]];
        }
        
    }else{
        [self outputMessage:@"广告没有准备好"];
    }
}



- (IBAction)userAppIdAction:(id)sender {
    extern NSString *App_ID;
    extern NSString *App_Key;
    
    NSString *appId = self.appIDTextField.text;
    NSString *appKey = self.appKeyTextField.text;
    if (appId.length && appKey.length) {
        
        self.label.text = @"当前正在使用: Yout AppID & AppKey";
        
        [[NSUserDefaults standardUserDefaults] setObject:appId forKey:App_ID];
        [[NSUserDefaults standardUserDefaults] setObject:appKey forKey:App_Key];
        [[NSUserDefaults standardUserDefaults] synchronize];
        
        [[CLRTBCentrixlinkAD sharedInstance] startWithAppID:appId appSecretKey:appKey error:nil];
        
    }else {
        UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:nil message:@"appID Or appKey error" delegate:nil cancelButtonTitle:nil otherButtonTitles:@"ok", nil];
        [alertView show];
    }
}

- (IBAction)defaultAppIdAction:(id)sender {
    
    if ([[CLRTBCentrixlinkAD sharedInstance] isAdPlayable]) {
        [[CLRTBCentrixlinkAD sharedInstance] playAD:self options:nil error:nil];
    } else {
        
    }
    
    return;
    extern NSString *App_ID;
    extern NSString *App_Key;
    
    extern NSString *Default_App_ID;
    extern NSString *Default_App_Key;
    
    self.label.text = @"当前正在使用: 默认AppID & AppKey";
    
    [[NSUserDefaults standardUserDefaults] setObject:Default_App_ID forKey:App_ID];
    [[NSUserDefaults standardUserDefaults] setObject:Default_App_Key forKey:App_Key];
    [[NSUserDefaults standardUserDefaults] synchronize];
    
    [[CLRTBCentrixlinkAD sharedInstance] startWithAppID:Default_App_ID appSecretKey:Default_App_Key error:nil];
    
}

- (void)didReceiveMemoryWarning {
    
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
    
}

@end




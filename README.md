# # Centrixlink-RTB-iOS-SDK

### 平台支持
iOS7+ 版本

### 准备工作

#### Cocoapods管理
CentrixlinkRTB iOS SDK可以通过Cocoapods工具自动操作完成。使用Cocoapods工具安装CentrixlinkRTB iOS SDK，只需在工程Podfile文件中添加以下代码并运行pod install命令即可。

```
source 'https://github.com/CocoaPods/Specs.git'
platform :ios, '7.0'

target 'TargetName' do
pod 'CentrixlinkRTB', '~> 1.0.1'
end
```

#### 手动操作
1.  从官网下载[Centrixlink_RTB_iOS_SDK](https://github.com/centrixlink/Centrixlink-RTB-iOS-SDK)文件。
2.  解压缩CentrixlinkRTB框架(CentrixlinkRTB.framework)，并添加到XCode项目中。
3.  添加以下依赖库:

```
* UIKit.framework
* AVFoundation.framework
* Foundation.framework
* CoreMedia.framework
* CoreLocation.framework
* CoreTelephony.framework
* SystemConfiguration.framework  
* Storekit.framework
* MediaPlayer.framework
* CFNetwork.framework
* AdSupport.framework
* ImageIO.framework
* libz.dylib
* libsqlite3.dylib
* libstdc++.dylib
```
4.  添加编译参数

> 在Xcode中选择项目的Targets->Build Settings，配置Other Link Flags 增加 -ObjC -all_load

5. 状态栏控制设置

> 打开项目的Info.plist，增加 "View controller-based status bar appearance" 选项，并设置为 "No".


6. 申请：[App ID、App Key](https://www.centrixlink.com)

## 集成说明

### 1. 添加头文件 
* AppDelegate.h:

```objc
#import <CentrixlinkRTB/CentrixlinkRTB.h>
```



### 2. 激活SDK

* CLAppDelegate.m:

```objc
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
```


### 3. 添加代码到展示视频广告的CLViewController中

#### 3.1 添加代理
```objc
- (void)viewDidLoad{
//设置代理（广告代理）
[[CLRTBCentrixlinkAD sharedInstance] setDelegate:self];
}
```

#### 3.2 跟踪视频广告展示添加相关委托接口

```objc
/**
*  广告adId
*/
UIKIT_EXTERN NSString *const ADInfoKEYADID;


/**
*  视频广告播放状态，true为视频广告完整播放，false为视频广告非完整播放
*/
UIKIT_EXTERN NSString *const ADInfoKEYADPlayStatus;


/**
* 视频广告是否被点击，true为点击，false为未点击
*/
UIKIT_EXTERN NSString *const ADInfoKEYIsClick;


#pragma mark ----CentrixlinkDelegate

- (void)centrixlinkRTBADPlayability:(BOOL)isAdPlayable {
   //返回是否有可播放广告
}
    
/**
*    视频广告即将展示
*
*  @param ADInfo 视频广告信息
*/
- (void)centrixlinkRTBVideoADWillShow:(NSDictionary *)ADInfo {
   //广告资源ID
   NSString *adid = [ADInfo objectForKey:ADInfoKEYADID];
      NSLog(@"视频广告数据已经准备完毕，即将开始展示；请保存当前应用或游戏状态");
}
      

/**
*   视频广告完成展示
*
*  @param ADInfo 视频广告信息
*/
- (void)centrixlinkRTBVideoADDidShow:(NSDictionary *)ADInfo {
//广告资源ID
    NSString *adid = [ADInfo objectForKey:ADInfoKEYADID];
NSLog(@"视频广告页面已经展示");
}

/**
*   视频广告展示已关闭
*
*  @param ADInfo 视频广告信息，若播放广告错误则ADInfo包含error字段及错误信息
*/

- (void)centrixlinkRTBVideoADClose:(NSDictionary *)ADInfo {
//广告资源ID
NSString *adid = [ADInfo objectForKey:ADInfoKEYADID];
//是否有点击事件
BOOL isClick = [[ADInfo objectForKey:ADInfoKEYIsClick] boolValue];
//是否完整播放
BOOL isplayFinished = [ADInfo objectForKey:ADInfoKEYADPlayStatus];
//详细信息
NSLog(@"ADInfo: %@",ADInfo);

}

/**
显示广告出错

@param error 通过不同的error code区分不同的错误类型
*/
- (void)centrixlinkRTBVideoADShowFail:(NSError *)error {
NSLog(@"%@", error);
/* code
100    广告的播放间隔时间不满足条件
101    本地没有可播放广告
105    当前正在播放其它广告
106    处于静默状态
108    当前用户播放超限
*/
}

```

#### 3.3 展示视频广告

```objc
//只展示预加载视频广告
- (void)showPreloadAD:(id )sender {
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
```


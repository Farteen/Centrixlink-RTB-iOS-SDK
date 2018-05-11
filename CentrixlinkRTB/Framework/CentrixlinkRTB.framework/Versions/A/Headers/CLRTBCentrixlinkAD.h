//
//  CLRTBCentrixlinkAD.h
//  Centrixlink
//
//  Created by 王俊拯 on 16/6/14.
//  Copyright © 2016年 Centrixlink. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "CLRTBCentrixlinkConst.h"
#import "CLRTBCentrixlinkProtocol.h"
#import "CLRTBStreamLog.h"


NS_ASSUME_NONNULL_BEGIN

@class UIViewController;


typedef void (^CLRTBCentrixlinkADDebugCallBack)(NSString *message, CLRTBStreamLogLevel level);

@interface CLRTBCentrixlinkAD : NSObject

@property (nonatomic, weak) id<CLRTBCentrixlinkADDelegate>delegate;

/**
 *   单例
 *
 *  @return Centrixlink 类对象
 */
+ (CLRTBCentrixlinkAD *)sharedInstance;

/**
 开发者需要填写申请的appID,appSecrectKey来对接ssp server

 @param appID 开发者在ssp portal中创建的appID
 @param appSecretKey 开发者在ssp portal中创建的appSecretKey
 @param error 错误信息
 @return 返回是否启动SDK成功
 */
-(BOOL)startWithAppID:(NSString *)appID appSecretKey:(NSString *)appSecretKey error:(NSError *__autoreleasing*)error;

/**
 SDK 版本号

 @return 返回SDK版本号,当前版本号为0.0.1
 */
+ (NSString *)SDKVersion;

/**
 *  是否有效的预加载广告
 *
 *  @return true 有可播放预加载广告，false 暂无可播放预加载广告
 */
- (BOOL)isAdPlayable;

/**
 设置视频广告的展示方向

 @param orientation 视频广告展示方向(UIInterfaceOrientationMaskPortrait / UIInterfaceOrientationMaskLandscape / UIInterfaceOrientationMaskAll = default)
 */
- (void)setPlayAdOrientation:(UIInterfaceOrientationMask)orientation;

/**
 *   播放视频全屏广告
 *
 *  @param ViewController 当前显示页面ViewController对象
 *  @param options        自定义上传跟此次广告播放相关数据，便于跟踪广告及广告激励
 *  @param error          播放失败返回
 *
 *  @return true 成功播放，false 播放失败
 */
- (BOOL)playAD:(UIViewController *)ViewController options:(NSDictionary * __nullable)options error:(NSError * __autoreleasing*)error;

/**
 *   DeBug开关显示
 *
 *  @param enable true 开启debug，false 关闭debug
 */
- (void)setDebugEnable:(BOOL)enable;

/**
 *   自定义debug 内容回调显示
 *
 *  @param debugBlock debugBlock，若不设置则在Xcode debug中显示，
 */
- (void)setDebugCallBack:(CLRTBCentrixlinkADDebugCallBack)callBack;

@end


NS_ASSUME_NONNULL_END

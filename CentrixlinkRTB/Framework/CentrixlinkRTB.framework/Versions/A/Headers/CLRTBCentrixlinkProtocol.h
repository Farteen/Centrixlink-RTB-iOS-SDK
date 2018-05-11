//
//  CLRTBCentrixlinkProtocol.h
//  Centrixlink
//
//  Created by Codi on 2017/3/30.
//  Copyright © 2017年 Centrixlink. All rights reserved.
//

#import <Foundation/Foundation.h>
@class CLRTBCentrixlinkADItem;


#pragma mark - CLRTBCentrixlinkADDelegate

@protocol CLRTBCentrixlinkADDelegate <NSObject>

@required

/**
 *  广告关闭
 *
 *  @param ADInfo 预留信息
 */
- (void)centrixlinkRTBVideoADClose:(NSDictionary *)ADInfo;

@optional

/**
 *  本地是否有预加载广告
 *
 *  @param hasPreload YES:存在 NO:不存在
 */
- (void)centrixlinkRTBADPlayability:(BOOL)isAdPlayable;


/**
 *  广告即将显示
 *
 *  @param ADInfo 广告信息
 */
- (void)centrixlinkRTBVideoADWillShow:(NSDictionary *)ADInfo;

/**
 *  广告完成显示
 *
 *  @param ADInfo 广告信息
 */
- (void)centrixlinkRTBVideoADDidShow:(NSDictionary *)ADInfo;




/**
 *  触发endCard的action事件
 *
 *  @param ADInfo 预留信息
 */
- (void)centrixlinkRTBVideoADAction:(NSDictionary *)ADInfo;


/**
 *  显示广告出错
 *
 *  @param error 通过不同的error code区分不同的错误类型
 */
- (void)centrixlinkRTBVideoADShowFail:(NSError *)error;


@end







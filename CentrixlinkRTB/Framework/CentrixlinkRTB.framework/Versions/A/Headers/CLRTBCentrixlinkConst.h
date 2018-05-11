//
//  CLRTBCentrixlinkConst.h
//  Centrixlink
//
//  Created by Codi on 30/03/2017.
//  Copyright © 2017 Centrixlink. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface CLRTBCentrixlinkConst : NSObject



UIKIT_EXTERN NSString *const CLRTBCentrixlinkADapterInitPreloadRes;
UIKIT_EXTERN NSString *const CLRTBCentrixlinkADapterPreloadFinished;



/**
 *  扩展信息
 */
UIKIT_EXTERN NSString *const CLRTBCentrixlinkSDKVersion;
UIKIT_EXTERN NSString *const CLRTBCentrixlinkPlayAdOptionKeyIECAutoClose;
UIKIT_EXTERN NSString *const CLRTBCentrixlinkPlayAdOptionKeyUser;
UIKIT_EXTERN NSString *const CLRTBCLRTBCentrixlinkPlayAdOptionKeyExtraInfoDictionary;
UIKIT_EXTERN NSString *const CLRTBCentrixlinkPlayAdOptionKeyExtra1;
UIKIT_EXTERN NSString *const CLRTBCentrixlinkPlayAdOptionKeyExtra2;
UIKIT_EXTERN NSString *const CLRTBCentrixlinkPlayAdOptionKeyExtra3;
UIKIT_EXTERN NSString *const CLRTBCentrixlinkPlayAdOptionKeyExtra4;
UIKIT_EXTERN NSString *const CLRTBCentrixlinkPlayAdOptionKeyExtra5;
UIKIT_EXTERN NSString *const CLRTBCentrixlinkPlayAdOptionKeyExtra6;
UIKIT_EXTERN NSString *const CLRTBCentrixlinkPlayAdOptionKeyExtra7;
UIKIT_EXTERN NSString *const CLRTBCentrixlinkPlayAdOptionKeyExtra8;



UIKIT_EXTERN NSString *const CLRTB_K_AD_RESIZEVIDEO_TOP;

UIKIT_EXTERN NSString *const CLRTB_K_AD_RESIZEVIDEO_LEFT;

UIKIT_EXTERN NSString *const CLRTB_K_AD_RESIZEVIDEO_VIDEOSCALE;


UIKIT_EXTERN NSString *const CLRTB_SDK_VERSION;

UIKIT_EXTERN NSString *const CLRTB_SDK_VER_CODE;

UIKIT_EXTERN NSString *const CLRTB_REQUEST_ID;

//UIKIT_EXTERN NSString *const ZP_CLRTB_REQUEST_ID;

#pragma Delegate 回调字典KEY
/**
 *  广告Key
 */
UIKIT_EXTERN NSString *const CLRTBADInfoKEYADID;

/**
 *  是否是缓存广告
 */
//UIKIT_EXTERN NSString *const CLRTBADInfoKEYPreloadStatus;
/**
 *  视频播放状态，true 为广告播放完毕，false为广告跳过
 */
UIKIT_EXTERN NSString *const CLRTBADInfoKEYADPlayStatus;


/**
 * 视频广告是否被点击，true 点击，false 未点击
 */
UIKIT_EXTERN NSString *const CLRTBADInfoKEYIsClick;

/**
 * 视频广告是否跳过
 */

UIKIT_EXTERN NSString *const CLRTBADInfoKEYIsSkip;

/**
 *  用于是否插屏广告显示开关
 */
UIKIT_EXTERN NSString *const CLRTBShowADOptionKeyRESIZEVIDEOAD;


/**
 *  只播放预加载广告
 */
UIKIT_EXTERN NSString *const CLRTBShowADOptionKeyOnlyPreload;


/**
 *  插屏广告显示的位置
 */
UIKIT_EXTERN NSString *const CLRTBADRESIZEVIDEOPosition;


UIKIT_EXTERN NSString *const CLRTB_UIInterfaceOrientationLandscapeLeft;
UIKIT_EXTERN NSString *const CLRTB_UIInterfaceOrientationLandscapeRight;
UIKIT_EXTERN NSString *const CLRTB_UIInterfaceOrientationPortrait;
UIKIT_EXTERN NSString *const CLRTB_UIInterfaceOrientationPortraitUpsideDown;


UIKIT_EXTERN NSString *const CLRTB_HTTP_HEADER_UUID;
UIKIT_EXTERN NSString *const CLRTB_HTTP_HEADER_VERSION;
UIKIT_EXTERN NSString *const CLRTB_HTTP_HEADER_APPID;
UIKIT_EXTERN NSString *const CLRTB_HTTP_HEADER_REQUESTID;
UIKIT_EXTERN NSString *const CLRTB_HTTP_HEADER_OS;
UIKIT_EXTERN NSString *const CL_HTTP_HEADER_MODEL;
UIKIT_EXTERN NSString *const CLRTB_HTTP_HEADER_OSVER;
UIKIT_EXTERN NSString *const CL_HTTP_HEADER_APPVER;
UIKIT_EXTERN NSString *const CL_HTTP_HEADER_BUNDLEID;
UIKIT_EXTERN NSString *const CL_HTTP_HEADER_REPORT_REQUESTID;


/* VideoADEventTable */
UIKIT_EXTERN NSString *const CLRTB_VIDEO_EVENT_TABLE;
/* SplashADEventTable */
//UIKIT_EXTERN NSString *const SPLASH_EVENT_TABLE;
/* ADDownloadedTable */
//UIKIT_EXTERN NSString *const DOWNLOADED_AD_TABLE;
/* New ADDownloadedTable */
UIKIT_EXTERN NSString *const CLRTB_DOWNLOADED_AD_NEW_TABLE;
/* ADFileTable */
UIKIT_EXTERN NSString *const CLRTB_DOWNLOADED_FILE_TABLE;
/* BuryingPointTable */
//UIKIT_EXTERN NSString *const BURYINGPOINT_TABLE;
/* ADRequestTable */
UIKIT_EXTERN NSString *const CLRTB_REQUEST_TABLE;
/* trackingUrl */
UIKIT_EXTERN NSString *const CLRTB_TRACKING_EVENT_TABLE;
UIKIT_EXTERN NSString *const CLRTB_FAIL_EVENT_TABLE;


@end

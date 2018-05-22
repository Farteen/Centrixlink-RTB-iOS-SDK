//
//  CLRTBStreamLog.h
//  Centrixlink
//
//  Created by 王俊拯 on 16/7/20.
//  Copyright © 2016年 Centrixlink. All rights reserved.
//

#ifndef _CLRTBSLOG_H_
#define _CLRTBSLOG_H_

#ifdef __cplusplus
#import <Foundation/Foundation.h>
#else
@import Foundation;
#endif

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, CLRTBStreamLogLevel){
    CLRTBStreamLogLevelError,
    CLRTBStreamLogLevelWarning,
    CLRTBStreamLogLevelInformation,
    CLRTBStreamLogLevelDebug
    
};


#define CLRTBStreamLog(level, ...) \
{ \
CLRTBStreamLogEx(level, @(__FILE__), @(__PRETTY_FUNCTION__), __LINE__, nil, __VA_ARGS__); \
}


static const NSUInteger CLRTBStreamLogLevelCount = CLRTBStreamLogLevelDebug + 1;


//! Log to Error level
#define CLRTBStreamLogError(...)        CLRTBStreamLog(CLRTBStreamLogLevelError,__VA_ARGS__)
//! Log to Warning level
#define CLRTBStreamLogWarning(...)      CLRTBStreamLog(CLRTBStreamLogLevelWarning,  __VA_ARGS__)
//! Log to Information level
#define CLRTBStreamLogInfo(...)         CLRTBStreamLog(CLRTBStreamLogLevelInformation,  __VA_ARGS__)
//! Log to Debug level
#define CLRTBStreamLogDebug(...)        CLRTBStreamLog(CLRTBStreamLogLevelDebug, __VA_ARGS__)



FOUNDATION_EXPORT void CLRTBStreamLogEx(CLRTBStreamLogLevel level,
                                NSString *file,
                                NSString *function,
                                unsigned int line,
                                id __nullable contextObject,
                                NSString *format, ...) NS_FORMAT_FUNCTION(6,7);

FOUNDATION_EXTERN NSString *CLRTBStreamLogLevelToString(CLRTBStreamLogLevel level);



NS_ASSUME_NONNULL_END


#endif

//
//  MHAppUtils.h
//  JiuluTV
//
//  Created by CoderMikeHe on 16/11/27.
//  Copyright © 2016年 9lmedia. All rights reserved.
//

#import <Foundation/Foundation.h>



// 是否是iPad
#define IS_IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
// 是否是iPhone
#define IS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)

// 系统放大倍数
#define MHScale [[UIScreen mainScreen] scale]

// 是否是retina
#define IS_RETINA ([[UIScreen mainScreen] scale] >= 2.0)

// IOS版本
#define MHIOSVersion [[[UIDevice currentDevice] systemVersion] floatValue]

// 屏幕总尺寸
#define MHMainScreenBounds  [UIScreen mainScreen].bounds
// 屏幕宽度
#define MHMainScreenWidth   [UIScreen mainScreen].bounds.size.width
// 屏幕高度
#define MHMainScreenHeight  [UIScreen mainScreen].bounds.size.height

// 最长屏幕尺寸
#define MHScreenMaxLength (MAX(MHMainScreenWidth, MHMainScreenHeight))
// 最短屏幕尺寸
#define MHScreenMinLength (MIN(MHMainScreenWidth, MHMainScreenHeight))
// iPhone 4以前
#define IS_IPHONE_4_OR_LESS (IS_IPHONE && MHScreenMaxLength < 568.0)
// iPhone 5
#define IS_IPHONE_5 (IS_IPHONE && MHScreenMaxLength == 568.0)
// iPhone 6/7/6S
#define IS_IPHONE_6 (IS_IPHONE && MHScreenMaxLength == 667.0)
// iPhone 6P/7P/6SP
#define IS_IPHONE_6P (IS_IPHONE && MHScreenMaxLength == 736.0)

// 适配AF
#ifndef TARGET_OS_IOS

#define TARGET_OS_IOS TARGET_OS_IPHONE

#endif

#ifndef TARGET_OS_WATCH

#define TARGET_OS_WATCH 0

#endif


// 输出日志 (格式: [时间] [哪个方法] [哪行] [输出内容])
#ifdef DEBUG
#define NSLog(format, ...) printf("\n💕[%s] %s [第%zd行] →→ %s\n", __TIME__, __FUNCTION__, __LINE__, [[NSString stringWithFormat:format, ##__VA_ARGS__] UTF8String]);
#else
#define NSLog(format, ...)
#endif

// 日记输出宏
#ifdef DEBUG // 调试状态, 打开LOG功能
#define MHLog(...) NSLog(__VA_ARGS__)
#else // 发布状态, 关闭LOG功能
#define MHLog(...)
#endif

// 打印方法
#define MHLogFunc MHLog(@"%s", __func__)


// 打印请求错误信息
#define MHLogErrorMessage  MHLog(@"错误请求日志-----【 %@ 】--【 %@ 】",[self class] , error.mh_message)
// 销毁打印
#define MHDealloc MHLog(@"\n =========+++ %@  销毁了 +++======== \n",[self class])



// KVO获取监听对象的属性 有自动提示
// 宏里面的#，会自动把后面的参数变成c语言的字符串
#define MHKeyPath(objc,keyPath) @(((void)objc.keyPath ,#keyPath))


// 颜色
#define MHColor(r, g, b) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]

// 颜色+透明度
#define MHAlphaColor(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:a]


// 随机色
#define MHRandomColor MHColor(arc4random_uniform(256), arc4random_uniform(256), arc4random_uniform(256))
// 根据rgbValue获取值
#define MHColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]


// 是否为空对象
#define MHObjectIsNil(__object)  ((nil == __object) || [__object isKindOfClass:[NSNull class]])

// 字符串为空
#define MHStringIsEmpty(__string) ((__string.length == 0) || MHObjectIsNil(__string))

// 字符串不为空
#define MHStringIsNotEmpty(__string)  (!MHStringIsEmpty(__string))

// 数组为空
#define MHArrayIsEmpty(__array) ((MHObjectIsNil(__array)) || (__array.count==0))

// 取消ios7以后下移
#define MHDisabledAutomaticallyAdjustsScrollViewInsets \
if (MHIOSVersion>=7.0) {\
self.automaticallyAdjustsScrollViewInsets = NO;\
}

// AppCaches 文件夹路径
#define MHCachesDirectory [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) lastObject]

// App DocumentDirectory 文件夹路径
#define MHDocumentDirectory [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask, YES) lastObject]



/**
 *  Frame PX  ---> Pt 5s的宽度 全部向下取整数
 */
#define MHPxConvertPt(__Px) floor((__Px) * MHMainScreenWidth/320.0f)
/**
 *  Frame PX  ---> Pt 5s的宽度 返回一个合适的值 按钮手指触摸点 44
 */
#define MHFxConvertFitPt(__px) (MAX(MHPxConvertPt(__Px),44))


// 设置图片
#define MHImageNamed(__imageName) [UIImage imageNamed:__imageName]

//  通知中心
#define MHNotificationCenter [NSNotificationCenter defaultCenter]












@interface MHAppUtils : NSObject

#pragma mark - File manager methods
/**
 *  文件管理器
 */
+ (NSFileManager *)fileManager;
/**
 *  该路径是否存在
 */
+ (BOOL)isPathExist:(NSString *)path;
/**
 *  该文件是否存在
 */
+ (BOOL)isFileExist:(NSString *)path;
/**
 *  该文件夹是否存在
 */
+ (BOOL)isDirectoryExist:(NSString *)path;
/**
 *  移除该文件
 */
+ (BOOL)removeFile:(NSString *)path;
/**
 *  创建目录 
 */
+ (BOOL)createDirectoryAtPath:(NSString *)path;
/**
 *  文件个数
 */
+ (NSUInteger)fileCountInPath:(NSString *)path;
/**
 *  目录大小
 */
+ (unsigned long long)folderSizeAtPath:(NSString *)path;


#pragma mark User directory methods
/**
 *  应用文件路径
 */
+ (NSString *)appDocumentDirectoryPath;
/**
 *  应用资源路径
 */
+ (NSString *)appResourcePath;
/**
 *  应用缓存路径
 */
+ (NSString *)appCachesDirectoryPath;
@end

//
//  MHConstant.h
//  MHLiveShow
//
//  Created by CoderMikeHe on 17/2/24.
//  Copyright © 2017年 CoderMikeHe. All rights reserved.
//

// sys
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// category
#import "UIBarButtonItem+MHExtension.h"
#import "UIView+MH.h"
#import "UIFont+MHExtension.h"
#import "NSString+MH.h"
#import "UINavigationController+FDFullscreenPopGesture.h"
#import "NSObject+MH.h"
#import "Colours.h"
#import "UIImage+MH.h"
#import "UIViewController+MHDismissKeyboard.h"
#import "UIViewController+MHHUD.h"
#import "NSDate+Extension.h"
#import "MBProgressHUD+MH.h"


// tool
#import "MHWebImageTool.h"
#import "MHSingleton.h"
#import "Masonry.h"

// UIKit
#import "MHButton.h"
#import "YYText.h"
#import "MHImageView.h"
#import "MHDivider.h"
#import "MHBackButton.h"

// 模型
#import "AppDelegate.h"


/**
 * 设置颜色
 */
#define MHColorFromHexString(__hexString__) [UIColor colorFromHexString:__hexString__]
/**
 *  全局细下滑线颜色 以及分割线颜色
 */
#define MHGlobalBottomLineColor     [UIColor colorFromHexString:@"#d6d7dc"]



@interface MHConstant : NSObject

@end

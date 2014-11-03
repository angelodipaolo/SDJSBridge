//
//  SDJSPlatformAPI.h
//  SDJSBridgeExample
//
//  Created by Angelo Di Paolo on 10/30/14.
//  Copyright (c) 2014 SetDirection. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>
#import <UIKit/UIKit.h>

@class SDJSNavigationAPI;


@protocol SDJSPlatformAPIExports <JSExport>

@property (nonatomic, strong) SDJSNavigationAPI *navigation;

@end

@interface SDJSPlatformAPI : NSObject <SDJSPlatformAPIExports>

@property (nonatomic, strong) SDJSNavigationAPI *navigation;
@property (nonatomic, weak) UIWebView *sharedWebView;

@end
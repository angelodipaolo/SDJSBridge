//
//  SDJSNavigationBarAPI.h
//  SDJSBridgeExample
//
//  Created by Angelo Di Paolo on 11/3/14.
//  Copyright (c) 2014 SetDirection. All rights reserved.
//

#import "SDJSBridgeScript.h"

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <JavaScriptCore/JavaScriptCore.h>

@protocol SDJSNavigationBarAPIExports <JSExport>

- (NSArray *)leftItems;
- (NSArray *)rightItems;
- (void)setLeftItems:(NSArray *)leftItems;
- (void)setRightItems:(NSArray *)rightItems;

@end

/**
 A JavaScript bridge script for interacting with the navigation items of a 
 SDWebViewController instance.
 */
@interface SDJSNavigationBarAPI : SDJSBridgeScript <SDJSNavigationBarAPIExports>

@end

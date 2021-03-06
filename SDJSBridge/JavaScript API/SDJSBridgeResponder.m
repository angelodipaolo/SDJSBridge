//
//  SDJSBridgeResponder.m
//  SDJSBridgeExample
//
//  Created by Angelo Di Paolo on 11/4/14.
//  Copyright (c) 2014 SetDirection. All rights reserved.
//

#import "SDJSBridgeResponder.h"

@implementation SDJSBridgeResponder

- (instancetype)initWithWebViewController:(SDWebViewController *)webViewController callback:(JSValue *)callback {
    if ((self = [super initWithWebViewController:webViewController])) {
        _callback = callback;
    }
    
    return self;
}

- (instancetype)initWithCallback:(JSValue *)callback {
    return [self initWithWebViewController:nil callback:callback];
}

- (void)runCallbackWithSender:(id)sender {
    if (self.callback) {
        [self.callback callWithArguments:nil];
    }
}

@end

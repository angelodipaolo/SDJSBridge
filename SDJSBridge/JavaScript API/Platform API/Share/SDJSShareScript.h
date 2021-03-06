//
//  SDJSShareScript.h
//  SDJSBridgeExample
//
//  Created by Angelo Di Paolo on 11/12/14.
//  Copyright (c) 2014 SetDirection. All rights reserved.
//

#import "SDJSBridgeResponder.h"

#import <JavaScriptCore/JavaScriptCore.h>
#import <UIKit/UIKit.h>

@protocol SDJSShareScriptExports <JSExport>

JSExportAs(share, - (void)shareWithOptions:(NSDictionary *)options);

@end

/**
 A delegate protocol for interacting with a SDJSShareScript object. Allows for 
 customization over the `UIActivityViewController` that is used to share an item.
 */
@protocol SDJSShareScriptDelegate <NSObject>

@optional

/**
 Implement to customize the activity items that are being shared.
 @param url URL of the item being shared.
 @param message Message text of the item being shared.
 @return An array of the activity items that will be used for the `UIActivityViewController`.
 */
- (NSArray *)shareBridgeAPIActivityItemsWithURL:(NSURL *)url message:(NSString *)message;

/**
 Implement to customize the application activities that are used for the `UIActivityViewController`.
 @param url URL of the item being shared.
 @param message Message text of the item being shared.
 @return An array of the application activities that will be used for the `UIActivityViewController`.
 */
- (NSArray *)shareBridgeAPIApplicationActivitiesWithURL:(NSURL *)url message:(NSString *)message;

/**
 Implement to provide the excluded activity types that are used for the `UIActivityViewController`.
 @param url URL of the item being shared.
 @param message Message text of the item being shared.
 @return An array of the excluded activity types that will be used for the `UIActivityViewController`.
 */
- (NSArray *)shareBridgeAPIExcludedActivityTypesWithURL:(NSURL *)url message:(NSString *)message;

/**
 Implement to customize how the `UIActivityViewController` is presented.
 @param activityViewController The `UIActivityViewController` instance
 */
- (void)shareBridgeAPIPresentActivityViewController:(UIActivityViewController *)activityViewController;

/**
 Implement to customize the completion logic.
 @return The completion handler block of type `UIActivityViewControllerCompletionHandler`.
 */
- (UIActivityViewControllerCompletionHandler)shareBridgeAPICompletionHandler;

@end

/**
 A JavaScript bridge script for sharing a URL and message with a
 `UIActivityViewController`. The class has built-in support for configuring and
 presenting a `UIActivityViewController` but the behavior can be customized by
 setting the delegate property and implementing methods of the SDJSShareScriptDelegate
 protocol.
 
 ## Objective-C Usage

 Set the delegate property to customize the `UIActivityViewController` behavior.

     SDWebViewController *webViewController;
     SDJSShareScript *shareAPI = [[SDJSShareScript alloc] initWithWebViewController:webViewController];
     shareAPI.delegate = self;

 Implement the delegate methods to make customizations.

     #pragma mark - SDJSShareScriptDelegate

     - (NSArray *)shareBridgeAPIActivityItemsWithURL:(NSURL *)url message:(NSString *)message {
         return @[message, url];
     }
     
     - (void)shareBridgeAPIPresentActivityViewController:(UIActivityViewController *)activityViewController {
         [self presentViewController:activityViewController animated:YES completion:nil];
     }


 ## JavaScript Usage
 
 Sharing a URL with a message.
 
     var url = "http://www.walmart.com/";
     var message = "Check out this great deal!"
     
     JSBridgeAPI.platform().share(url, message, function () {
       // share complete
     });
 
 */
@interface SDJSShareScript : SDJSBridgeResponder <SDJSShareScriptDelegate>

/**
 By default an instance of SDJSShareScript makes itself the delegate. Set to 
 customize share behavior.
 */
@property (nonatomic, weak) id<SDJSShareScriptDelegate> delegate;

- (void)shareWithOptions:(NSDictionary *)options;

@end

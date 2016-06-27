# Widevine Plugin for Brightcove Player SDK for iOS, version 2.1.0.334


Supported Platforms
===================

iOS 7.0 and above. **Widevine will not run on the iOS Simulator.**

Installation
============
The Widevine Plugin for Brightcove Player SDK provides a static library framework for installation.

CocoaPods
--------------
You can use [Cocoapods][cocoapods] to add the Widevine Plugin for Brightcove Player SDK to your project. You can find the latest `Brightcove-Player-SDK-Widevine` podspec [here][podspecs]. To use this spec, add the following to the top of Podfile:`source 'https://github.com/brightcove/BCOVSpecs.git'` or run `pod repo add BCOVSpecs https://github.com/brightcove/BCOVSpecs.git`. CocoaPods 0.39 or newer is required.

The Widevine SDK **is not** included in this pod. You **must** manually add the Widevine library to your project even when using Cocoapods. The pod will however add all the libraries required by Widevine library such as `libc++`, `libxml2`, `libresolv`, `libSystem`, and `libz`. **Please contact Brightcove Support to get access to the Widevine library .**

To manually install the Widevine library:  

1. Request the Widevine library from Brightcove support.
2. Add the contents of the package to your project.
3. On the "Build Phases" tab of your application target, add the following to the "Link
    Binary With Libraries" phase:
    * `libWViPhoneAPI.a`
4. On the "Build Settings" tab of your application target:
    * Ensure that Widevine headers are in your application's "Header Search Path".
    * Ensure that `-ObjC` has been added to the "Other Linker Flags" build setting.

Static Framework example:  

    source 'https://github.com/CocoaPods/Specs.git'
    source 'https://github.com/brightcove/BCOVSpecs.git'

    pod 'Brightcove-Player-SDK-Widevine'

Manual
--------------

To add the Widevine Plugin for Brightcove Player SDK to your project manually:

1. Install the latest version of the [Brightcove Player SDK][bcovsdk].
2. Download the latest zip'ed release of the plugin from our [release page][release].
3. Request Widevine library from Brightcove support and add it your project.
4. Add the 'BrightcoveWidevine.framework' to your project.
5. On the "Build Settings" tab of your application target, ensure that the "Framework Search Paths" include the path to the framework. This should have been done automatically unless the framework is stored under a different root directory than your project.
6. On the "Build Phases" tab of your application target, add the following to the "Link
    Binary With Libraries" phase:
    * `BrightcoveWidevine.framework`
    * `libWViPhoneAPI.a`
    * `libc++`
    * `libxml2`
    * `libresolv`
    * `libSystem`
    * `libz`
7. On the "Build Settings" tab of your application target:
    * Ensure that `-ObjC` has been added to the "Other Linker Flags" build setting.
    * Ensure that Widevine headers are in your application's "Header Search Path".

[bcovsdk]: https://github.com/brightcove/brightcove-player-sdk-ios
[cocoapods]: http://cocoapods.org
[podspecs]: https://github.com/brightcove/BCOVSpecs/tree/master/Brightcove-Player-SDK-Widevine
[release]: https://github.com/brightcove/brightcove-player-sdk-ios-widevine/releases

Quick Start
===========
```

	    NSString *token;      // (Brightcove Media API token with URL access)
	    NSString *playlistID; // (ID of the playlist you wish to use)

	    BCOVPlayerSDKManager *manager = [BCOVPlayerSDKManager sharedManager];
	[1] id<BCOVPlaybackController> controller = [playbackManager createWidevinePlaybackControllerWithViewStrategy:nil]viewStrategy:nil];
	    [self.view addSubview:controller.view];

	    BCOVCatalogService *catalog = [[BCOVCatalogService alloc] initWithToken:token];
	[2] [catalog findWidevinePlaylistWithPlaylistID:playlistID
	                             parameters:nil
	                             completion:^(BCOVPlaylist *playlist,
	                                          NSDictionary *jsonResponse,
	                                          NSError      *error) {

	                                 [controller setVideos:playlist];
	                                 [controller play];

	                             }];

```
Let's break this code down into steps, to make it a bit simpler to digest:

1. BCOVWidevine adds some category methods to BCOVPlaybackManager. The first of these is `-createWidevinePlaybackControllerWithViewStrategy`. Use this method to create your playback controller. Alternatively (if you are using more than one session provider), you can create a BCOVWidevineSessionProvider and pass that to the manager method that creates a playback controller with upstream session providers.\*
1. BCOVWidevine adds some category methods to BCOVPlaybackManager for retrieving Widevine renditions from the catalog.

\* Note that BCOVWidevineSessionProvider should come before any ad session providers in the chain passed to the manager when constructing the playback controller.

If you have questions or need help, we have a support forum for Brightcove's native Player SDKs at https://groups.google.com/forum/#!forum/brightcove-native-player-sdks .

Customizing Plugin Behavior
===========

You can customize default plugin behavior by creating an instance of `BCOVWidevineSessionProviderOptions` and overriding the default properties. To use a `BCOVWideSessionProviderOptions` options instance, you need to create the `BCOVWideSessionProvider` using `-[BCOVSDKManager createWidevineSessionProviderWithOptions:]`.

```

    BCOVWidevineSessionProviderOptions *options = [[BCOVWidevineSessionProviderOptions alloc] init];
    options.widevineSettings = @{ WVPlayerDrivenAdaptationKey: @0 };
    id<BCOVPlaybackSessionProvider> sessionProvider = [playbackManager createWidevineSessionProviderWithOptions:options];

    id<BCOVPlaybackController> playbackController = [playbackManager createPlaybackControllerWithSessionProvider:sessionProvider viewStrategy:nil];
```

Source Selection (WVM, HTTP/HTTPs)
---------------------------------------
The Brightcove Player SDK for iOS provides clients the ability to attach multiple url and delivery types (`BCOVSource`) to a single video (`BCOVVideo`). For example, if your videos are being retrieved by the catalog or playback service, there may be a mix of WVM, HLS, or MP4 renditions for a single video, along with HTTP and HTTPs versions.  Which one of these sources that get selected is determined by a source selection block. The default source selection policy used by the Widevine plugin selects the first Widevine `BCOVSource` on each `BCOVVideo`, regardless of scheme. 

Source selection can be overridden by creating a `BCOVWidevineSessionProviderOptions` and using it to create a `BCOVWidevineSessionProvider`. For example:

    BCOVPlayerSDKManager *sdkManager = [BCOVPlayerSDKManager sharedManager];
    
    BCOVWidevineSessionProviderOptions *options = [[BCOVWidevineSessionProviderOptions alloc] init];    
    options.sourceSelectionPolicy = <policy>
    
    id<BCOVWidevineSessionProvider> provider = [sdkManager createWidevineSessionProviderWithOptions:options];
    id<BCOVPlaybackController> playbackController [sdkManager createPlaybackControllerWithSessionProvider:provider viewStrategy:nil];


If this default selection policy does not work for you, there are a few alternatives to selecting a source:

* If retrieving videos from Video Cloud via the catalog service or playback service, before calling `-[BCOVPlaybackController setVideos:]`, use the update method on the `BCOVVideo` to only contain the source you want (see the "Values" section for more info).

* If you prefer HTTPS sources, the Widevine plugin provides additional options for selecting Widevine sources with a particular scheme. `[BCOVWidevineSourceSelectionPolicy sourceSelectionWidevineWithScheme:kBCOVSourceURLSchemeHTTPS]` provides a source selection policy that prefers Widevine sources using HTTPS. This will not convert non-HTTP urls to HTTPs urls. If you choose to select HTTPs, ensure that your CDN is configured for HTTPs. If the CDN is configured for HTTPs, use `BCOVPlaybackService` instead of `BCOVCatalogService` to retrieve video/playlist metadata.

* Similar to updating the video object, you may also implement your own source selection block.
        
        options.sourceSelectionPolicy = ^ BCOVSource *(BCOVVideo *video) {
        
           <Check video.sources for source>
           <return source>

        };


Widevine Quirks
===========

###Multiple Widevine Videos/Players

The Widevine library can only load a single video into memory at a time. Therefore, when using the BCOVWidevine plugin, there can be only one `BCOVPlaybackController` using the plugin at a given time. The default behavior of preloading of the next video in a playlist is also disabled for this reason.

###Background/Foreground behavior

Widevine will automatically stop and unload WVM videos when the client app is exited. This occurs on `UIApplicationDidEnterBackgroundNotification`. When re-entering the app (on `UIApplicationWillEnterForegroundNotification`, assuming iOS has not purged the app from memory), the BCOVWidevine plugin will replace the current BCOVPlaybackSession's `player.currentItem` with a new AVPlayerItem, and will automatically seek to the position recorded when the app entered the background. This takes additional time, as the video must be reloaded "from scratch". When the new AVPlayerItem is ready, the plugin will send a `kBCOVWidevineLifeycleEventSessionResumed` lifecycle event to indicate that the AVPlayer can receive message sends. Failing to wait for this event before interacting with the player will result in undefined behavior.

In addition to re-initializing the player, the plugin will also resume playback if the content had been playing when the app exited. This can be disabled with a custom `BCOVWideSessionProviderOptions`.

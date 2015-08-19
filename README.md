# Widevine Plugin for Brightcove Player SDK for iOS, version 1.2.2.285

Requirements
============

This plugin will run on iOS 7.0+. Widevine will not run on the simulator.

Installation
============
You can use [Cocoapods][cocoapods] to add the Widevine Plugin for Brightcove Player SDK to your project.  You can find the latest `Brightcove-Player-SDK-Widevine` podspec [here][podspecs].  To use this spec, using Cocoapods 0.34.1+, add the following to the top of Podfile: `source 'https://github.com/brightcove/BCOVSpecs.git'`.

To add the Widevine Plugin for Brightcove Player SDK to your project manually:

1. Install the latest version of the [Brightcove Player SDK][bcovsdk].
1. Download the latest zip'ed release of the plugin from our [release page][release].
1. Add the contents of Library and Headers to the project.
1. On the "Build Phases" tab of your application target, add the following to the "Link
    Binary With Libraries" phase:
    * `libBCOVWidevine.a`
    * `libWViPhoneAPI.a`
    * `libc++`
    * `libxml2`
    * `libresolv`
    * `libSystem`
    * `libz`
1. On the "Build Settings" tab of your application target:
    * Ensure that BCOVWidevine headers are in your application's "Header Search Path".
    * Ensure that `-ObjC` has been added to the "Other Linker Flags" build setting.

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

Widevine Quirks
===========

###Multiple Widevine Videos/Players

The Widevine library can only load a single video into memory at a time. Therefore, when using the BCOVWidevine plugin, there can be only one `BCOVPlaybackController` using the plugin at a given time. The default behavior of preloading of the next video in a playlist is also disabled for this reason.

###Background/Foreground behavior

Widevine will automatically stop and unload WVM videos when the client app is exited. This occurs on `UIApplicationDidEnterBackgroundNotification`. When re-entering the app (on `UIApplicationWillEnterForegroundNotification`, assuming iOS has not purged the app from memory), the BCOVWidevine plugin will replace the current BCOVPlaybackSession's `player.currentItem` with a new AVPlayerItem, and will automatically seek to the position recorded when the app entered the background. This takes additional time, as the video must be reloaded "from scratch". When the new AVPlayerItem is ready, the plugin will send a `kBCOVWidevineLifeycleEventSessionResumed` lifecycle event to indicate that the AVPlayer can receive message sends. Failing to wait for this event before interacting with the player will result in undefined behavior.

In addition to re-initializing the player, the plugin will also resume playback if the content had been playing when the app exited. This can be disabled with a custom `BCOVWideSessionProviderOptions`.

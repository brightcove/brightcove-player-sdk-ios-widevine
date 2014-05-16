# Widevine Plugin for Brightcove Player SDK for iOS, version 1.0.6.143


Installation
===========

Widevine Plugin for Brightcove Player SDK for iOS can be installed through Cocoapods. In order to install the pod, you must first install the [BCOVSpecs](https://github.com/brightcove/BCOVSpecs) cocoapods repository by executing `pod repo add BCOVSpecs https://github.com/brightcove/BCOVSpecs.git` from the command line. Then include `Brightcove-Player-SDK-Widevine` in your podfile.

To install through Xcode, add libBCOVWidevine.a and accompanying header files to your header search path. You **must** manually add the Widevine SDK to your project along with dependencies.

Quick Start
===========
```objc

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

```objc

    BCOVWidevineSessionProviderOptions *options = [[BCOVWidevineSessionProviderOptions alloc] init];
    options.widevineSessions = @{ WVPlayerDrivenAdaptationKey: @1 };
    id<BCOVPlaybackSessionProvider> sessionProvider = [playbackManager createWidevineSessionProviderWithOptions:options];

    id<BCOVPlaybackController> playbackController = [playbackManager createPlaybackControllerWithSessionProvider:sessionProvider viewStrategy:nil];
```





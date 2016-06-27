# 2.1.0
### Breaking Changes

* Version 2.1.0 of the Widevine plugin requires Brightcove Player SDK for iOS version 5.1.0 or higher.

# 2.0.0

### Breaking Changes

* The static library distributable has been removed. If installed manually (not CocoaPods), you will need to remove the libBCOVWidevine.a library from the Library Search Paths, and its headers from the Header Search Paths. Please see README.md for new install options (including a static library framework).

### Additions and Improvements

* The Widevine Plugin for Brightcove Player SDK is now distributed as a static framework.

# 1.2.3

### Additions and Improvements

* Added `[BCOVWidevineSourceSelectionPolicy sourceSelectionWidevineWithScheme:]` and `[BCOVWidevineSourceSelectionPolicy sourceSelectionWidevine]` methods that provide source selection policies to help choose specific Widevine sources from a BCOVVideo object. See the README.md for more information.

# 1.2.2
### Additions and Improvements
* Internal improvements to support Brightcove Player SDK for iOS v.4.4.0.

# 1.2.1
### Additions and Improvements
* Introduces support for `- [BCOVPlaybackController resumeVideoAtTime:withAutoPlay:` that was added in BCOVPlayerSDK v4.3.4.

# 1.2.0

### Breaking Changes
* The BCOVWidevine plugin now supports iOS 7.0+ only. This is due to a Widevine library update.

### Additions and Improvements
* Updated to Widevine 6.0.0.12790.
    * Fixes seeking issues on iOS 7 and iOS 8.
    * Includes arm64 architecture slice.

# 1.0.10

### Breaking Changes
* This is the last version of Widevine to support iOS 6. Google has recently updated Widevine and dropped support for iOS 6.
* This release has been built with Xcode 6. In Xcode 6, Apple removed armv7s from the list of standard architectures. This release no longer includes an armv7s architecture slice.

### Additions and Improvements
* Internal improvements.

# 1.0.9

### Breaking Changes
 *  Use of ReactiveCocoa in public APIs within the BCOVWidevine Plugin is removed in this release.

### Additions and Improvements
  * Internal improvements.

# 1.0.8

### Additions and Improvements
  * Internal improvements.

# 1.0.7

### Breaking Changes
* Use of ReactiveCocoa in public APIs within the BCOVWidevine Plugin is deprecated in this release. Version 1.1.0 will not require clients to install any version of ReactiveCocoa, and properties or methods that return or expect RACSignal objects will be removed. See the header files for guidance on how to update deprecated functionality for compatibility with 1.1.0. The deprecations include the following:
  * `-[BCOVCatalogService findWidevinePlaylistWithPlaylistID:parameters:]`
  * `-[BCOVCatalogService findWidevinePlaylistDictionaryWithPlaylistID:parameters:]`
  * `-[BCOVCatalogService findWidevinePlaylistWithReferenceID:parameters:]`
  * `-[BCOVCatalogService findWidevinePlaylistDictionaryWithReferenceID:parameters:]`
  * `-[BCOVCatalogService findWidevineVideoWithVideoID:parameters:]`
  * `-[BCOVCatalogService findWidevineVideoDictionaryWithVideoID:parameters:]`
  * `-[BCOVCatalogService findWidevineVideoWithReferenceID:parameters:]`
  * `-[BCOVCatalogService findWidevineVideoDictionaryWithReferenceID:parameters:]`

### Additions and Improvements
* Added methods that return NSOperation objects to BCOVCatalogService. The operations replace similar (deprecated) RACSignal-returning methods.
* Improved information in lifecycle events of type `kBCOVWidevineLifecycleEventError` when the BCOVWidevine plugin detects that Widevine's library fails to initialize, play, stop, or terminate.
* Added a lifecycle event of type `kBCOVWidevineLifecycleEventSessionDidResume` to notify clients of the SDK that the Widevine video's playback state has been restored, and it is now safe to interact with or play the video player.
* Fixed a bug in which a Widevine video's progress events would fail to deliver after exiting and then re-entering the app. This would only happen if the video's playhead position was at zero when exiting the app.
* Notes on quirks and odd behavior in Widevine's library added to `README-DIST.md` document.
* Corrected an option name in `README-DIST.md` document (thanks to `dvdk`).

# 1.0.6

### Additions and Improvements
* Deliver a lifecycle event of type `kBCOVWidevineLifecycleEventError` if Widevine fails to initialize.
* Fixed a bug that caused Widevine to unnecessarily tear down the video if the app was interrupted.

# 1.0.5

### Breaking Changes
* This release no longer removes non-Widevine sources from a video when using `BCOVCatalogService+BCOVWidevineAdditions` methods. Instead, non-Widevine sources are added to the end of sources list.
* This releases introduces an improved Widevine source selection policy. Prior to 1.0.5 and BCOVPlayerSDK 4.1.5, the default policy would select the first source on each video, regardless of the source's `url` or `deliveryMethod` properties.  In 1.0.5, Widevine overrides the default policy to select the first source whose `deliveryMethod` is `kBCOVSourceDeliveryWVM` ("WVM").  If no Widevine source is found, it falls back to the BCOVPlayerSDK default policy.

### Additions and Improvements
* Added a `kBCOVSourceDeliveryWVM` ("WVM") constant for `-[BCOVSource deliveryMethod]`.
* Fixed a bug that caused widevine renditions to not get returned by `-[BCOVCatalogService findWidevineVideoWithReferenceID:parameters completion:]`.

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

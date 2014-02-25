# 1.0.5

### Breaking Changes
* This release no longer removes non-Widevine sources from a video when using `BCOVCatalogService+BCOVWidevineAdditions` methods. Instead, non-Widevine sources are added to the end of sources list.
* This releases introduces an improved Widevine source selection policy. Prior to 1.0.5 and BCOVPlayerSDK 4.1.5, the default policy would select the first source on each video, regardless of the source's `url` or `deliveryMethod` properties.  In 1.0.5, Widevine overrides the default policy to select the first source whose `deliveryMethod` is `kBCOVSourceDeliveryWVM` ("WVM").  If no Widevine source is found, it falls back to the BCOVPlayerSDK default policy.

### Additions and Improvements
* Added a `kBCOVSourceDeliveryWVM` ("WVM") constant for `-[BCOVSource deliveryMethod]`.
* Fixed a bug that caused widevine renditions to not get returned by `-[BCOVCatalogService findWidevineVideoWithReferenceID:parameters completion:]`.
//
// BCOVCatalogService+BCOVWidevineAdditions.h
// BCOVWidevine
//
// Copyright (c) 2014 Brightcove, Inc. All rights reserved.
// License: https://accounts.brightcove.com/en/terms-and-conditions
//

#import "BCOVCatalogService.h"


/**
 * Adds methods to the BCOVCatalogService to retrieve Widevine assets.
 */
@interface BCOVCatalogService (BCOVWidevineAdditions)

/**
 * Retrieves a playlist from the Media API service by its playlist ID.
 *
 * If the Media API returns a standard JSON-formatted error response, the
 * deserialized response will be the delivered error's `userInfo`.
 *
 * If a JSON parse error occurs, the raw NSData response will be included in the
 * delivered error's `userInfo`, keyed by kBCOVCatalogJSONDeserializationErrorRawDataKey.
 *
 * The returned signal does not guarantee that it will deliver its values on
 * the main thread scheduler, so if this is a requirement then use -[RACSignal deliverOn:]
 * to deliver the values on the main thread.
 *
 * @param playlistID string containing the ID of the playlist to find.
 * @param parameters Additional NSString query parameters to add to the Media API
 * requests. These values will override the default values if they conflict.
 * @return  Returns a signal that sends a BCOVPlaylist as its only value, then
 * completes.
 */
- (RACSignal *)findWidevinePlaylistWithPlaylistID:(NSString *)playlistID parameters:(NSDictionary *)parameters;

/**
 * Retrieves playlist data from the Media API service by its playlist ID.
 *
 * If the Media API returns a standard JSON-formatted error response, the
 * deserialized response will be the delivered error's `userInfo`.
 *
 * If a JSON parse error occurs, the raw NSData response will be included in the
 * delivered error's `userInfo`, keyed by kBCOVCatalogJSONDeserializationErrorRawDataKey.
 *
 * The returned signal does not guarantee that it will deliver its values on
 * the main thread scheduler, so if this is a requirement then use -[RACSignal deliverOn:]
 * to deliver the values on the main thread.
 *
 * @param playlistID string containing the ID of the playlist to find.
 * @param parameters Additional NSString query parameters to add to the Media API
 * requests. These values will override the default values if they conflict.
 * @return  Returns a signal that sends a JSON dictionary as its only value,
 * then completes. */
- (RACSignal *)findWidevinePlaylistDictionaryWithPlaylistID:(NSString *)playlistID parameters:(NSDictionary *)parameters;

/**
 * Retrieves a playlist from the Media API service by its reference ID.
 *
 * If the Media API returns a standard JSON-formatted error response, the
 * deserialized response will be the delivered error's `userInfo`.
 *
 * If a JSON parse error occurs, the raw NSData response will be included in the
 * delivered error's `userInfo`, keyed by kBCOVCatalogJSONDeserializationErrorRawDataKey.
 *
 * The returned signal does not guarantee that it will deliver its values on
 * the main thread scheduler, so if this is a requirement then use -[RACSignal deliverOn:]
 * to deliver the values on the main thread.
 *
 * @param referenceID string containing the reference ID of the playlist to find.
 * @param parameters Additional NSString query parameters to add to the Media API
 * requests. These values will override the default values if they conflict.
 * @return  Returns a signal that sends a BCOVPlaylist as its only value, then
 * completes.
 */
- (RACSignal *)findWidevinePlaylistWithReferenceID:(NSString *)referenceID parameters:(NSDictionary *)parameters;

/**
 * Retrieves playlist data from the Media API service by its reference ID.
 *
 * If the Media API returns a standard JSON-formatted error response, the
 * deserialized response will be the delivered error's `userInfo`.
 *
 * If a JSON parse error occurs, the raw NSData response will be included in the
 * delivered error's `userInfo`, keyed by kBCOVCatalogJSONDeserializationErrorRawDataKey.
 *
 * The returned signal does not guarantee that it will deliver its values on
 * the main thread scheduler, so if this is a requirement then use -[RACSignal deliverOn:]
 * to deliver the values on the main thread.
 *
 * @param referenceID string containing the reference ID of the playlist to find.
 * @param parameters Additional NSString query parameters to add to the Media API
 * requests. These values will override the default values if they conflict.
 * @return  Returns a signal that sends a JSON dictionary as its only value,
 * then completes.
 */
- (RACSignal *)findWidevinePlaylistDictionaryWithReferenceID:(NSString *)referenceID parameters:(NSDictionary *)parameters;

/**
 * Retrieves a video from the Media API service by its video ID.
 *
 * If the Media API returns a standard JSON-formatted error response, the
 * deserialized response will be the delivered error's `userInfo`.
 *
 * If a JSON parse error occurs, the raw NSData response will be included in the
 * delivered error's `userInfo`, keyed by kBCOVCatalogJSONDeserializationErrorRawDataKey.
 *
 * The returned signal does not guarantee that it will deliver its values on
 * the main thread scheduler, so if this is a requirement then use -[RACSignal deliverOn:]
 * to deliver the values on the main thread.
 *
 * @param videoID string containing the ID of the video to find.
 * @param parameters Additional NSString query parameters to add to the Media API
 * requests. These values will override the default values if they conflict.
 * @return  Returns a signal that sends a BCOVVideo as its only value, then
 * completes.
 */
- (RACSignal *)findWidevineVideoWithVideoID:(NSString *)videoID parameters:(NSDictionary *)parameters;

/**
 * Retrieves video data from the Media API service by its video ID.
 *
 * If the Media API returns a standard JSON-formatted error response, the
 * deserialized response will be the delivered error's `userInfo`.
 *
 * If a JSON parse error occurs, the raw NSData response will be included in the
 * delivered error's `userInfo`, keyed by kBCOVCatalogJSONDeserializationErrorRawDataKey.
 *
 * The returned signal does not guarantee that it will deliver its values on
 * the main thread scheduler, so if this is a requirement then use -[RACSignal deliverOn:]
 * to deliver the values on the main thread.
 *
 * @param videoID string containing the ID of the video to find.
 * @param parameters Additional NSString query parameters to add to the Media API
 * requests. These values will override the default values if they conflict.
 * @return  Returns a signal that sends a JSON dictionary as its only value,
 * then completes.
 */
- (RACSignal *)findWidevineVideoDictionaryWithVideoID:(NSString *)videoID parameters:(NSDictionary *)parameters;

/**
 * Retrieves a video from the Media API service by its reference ID.
 *
 * If the Media API returns a standard JSON-formatted error response, the
 * deserialized response will be the delivered error's `userInfo`.
 *
 * If a JSON parse error occurs, the raw NSData response will be included in the
 * delivered error's `userInfo`, keyed by kBCOVCatalogJSONDeserializationErrorRawDataKey.
 *
 * The returned signal does not guarantee that it will deliver its values on
 * the main thread scheduler, so if this is a requirement then use -[RACSignal deliverOn:]
 * to deliver the values on the main thread.
 *
 * @param referenceID string containing the reference ID of the video to find.
 * @param parameters Additional NSString query parameters to add to the Media API
 * requests. These values will override the default values if they conflict.
 * @return  Returns a signal that sends a BCOVVideo as its only value, then
 * completes.
 */
- (RACSignal *)findWidevineVideoWithReferenceID:(NSString *)referenceID parameters:(NSDictionary *)parameters;

/**
 * Retrieves video data from the Media API service by its reference ID.
 *
 * If the Media API returns a standard JSON-formatted error response, the
 * deserialized response will be the delivered error's `userInfo`.
 *
 * If a JSON parse error occurs, the raw NSData response will be included in the
 * delivered error's `userInfo`, keyed by kBCOVCatalogJSONDeserializationErrorRawDataKey.
 *
 * The returned signal does not guarantee that it will deliver its values on
 * the main thread scheduler, so if this is a requirement then use -[RACSignal deliverOn:]
 * to deliver the values on the main thread.
 *
 * @param referenceID string containing the reference ID of the video to find.
 * @param parameters Additional NSString query parameters to add to the Media API
 * requests. These values will override the default values if they conflict.
 * @return  Returns a signal that sends a JSON dictionary as its only value,
 * then completes.
 */
- (RACSignal *)findWidevineVideoDictionaryWithReferenceID:(NSString *)referenceID parameters:(NSDictionary *)parameters;

@end

/**
 * The functionality of the finder methods added in these category methods is
 * similar to the core finder methods in BCOVCatalogService, except that rather
 * than return a signal that delivers the results (or an error), these methods
 * return void but take a block which is called with the results (or an error).
 * If you are comfortable using ReactiveCocoa's signal API, the signal methods
 * offered by BCOVCatalogService offer better flexibility. These category
 * methods are intended for clients who do not wish to use signals directly.
 */
@interface BCOVCatalogService (BCOVWidevineImperativeCallbacks)

/**
 * Retrieves a BCOVPlaylist from the Media API service by its playlist ID.
 *
 * If the Media API returns a standard JSON-formatted error response, the
 * deserialized response will be the callback's error's `userInfo`.
 *
 * If a JSON parse error occurs, the raw NSData response will be included in the
 * callback's error's `userInfo`, keyed by kBCOVCatalogJSONDeserializationErrorRawDataKey.
 *
 * @param playlistID The ID of the playlist to find.
 * @param parameters Additional NSString query parameters to add to the Media
 * API requests. These values will override the default values if they conflict.
 * @param completionHandler block which will be invoked when the request
 * finishes. Execution of the completionHandler will occur on the main thread.
 */
- (void)findWidevinePlaylistWithPlaylistID:(NSString *)playlistID parameters:(NSDictionary *)parameters completion:(void (^)(BCOVPlaylist *playlist, NSDictionary *jsonResponse, NSError *error))completionHandler;

/**
 * Retrieves a BCOVPlaylist from the Media API service by its reference ID.
 *
 * If the Media API returns a standard JSON-formatted error response, the
 * deserialized response will be the callback's error's `userInfo`.
 *
 * If a JSON parse error occurs, the raw NSData response will be included in the
 * callback's error's `userInfo`, keyed by kBCOVCatalogJSONDeserializationErrorRawDataKey.
 *
 * @param referenceID The reference ID of the playlist to find.
 * @param parameters Additional NSString query parameters to add to the Media
 * API requests. These values will override the default values if they conflict.
 * @param completionHandler block which will be invoked when the request
 * finishes. Execution of the completionHandler will occur on the main thread.
 */
- (void)findWidevinePlaylistWithReferenceID:(NSString *)referenceID parameters:(NSDictionary *)parameters completion:(void (^)(BCOVPlaylist *playlist, NSDictionary *jsonResponse, NSError *error))completionHandler;

/**
 * Retrieves a BCOVVideo from the Media API service by its video ID.
 *
 * If the Media API returns a standard JSON-formatted error response, the
 * deserialized response will be the callback's error's `userInfo`.
 *
 * If a JSON parse error occurs, the raw NSData response will be included in the
 * callback's error's `userInfo`, keyed by kBCOVCatalogJSONDeserializationErrorRawDataKey.
 *
 * @param videoID The ID of the video to find.
 * @param parameters Additional NSString query parameters to add to the Media
 * API requests. These values will override the default values if they conflict.
 * @param completionHandler block which will be invoked when the request
 * finishes. Execution of the completionHandler will occur on the main thread.
 */
- (void)findWidevineVideoWithVideoID:(NSString *)videoID parameters:(NSDictionary *)parameters completion:(void (^)(BCOVVideo *video, NSDictionary *jsonResponse, NSError *error))completionHandler;

/**
 * Retrieves a BCOVVideo from the Media API service by its reference ID.
 *
 * If the Media API returns a standard JSON-formatted error response, the
 * deserialized response will be the callback's error's `userInfo`.
 *
 * If a JSON parse error occurs, the raw NSData response will be included in the
 * callback's error's `userInfo`, keyed by kBCOVCatalogJSONDeserializationErrorRawDataKey.
 *
 * @param referenceID The reference ID of the video to find.
 * @param parameters Additional NSString query parameters to add to the Media
 * API requests. These values will override the default values if they conflict.
 * @param completionHandler block which will be invoked when the request
 * finishes. Execution of the completionHandler will occur on the main thread.
 */
- (void)findWidevineVideoWithReferenceID:(NSString *)referenceID parameters:(NSDictionary *)parameters completion:(void (^)(BCOVVideo *video, NSDictionary *jsonResponse, NSError *error))completionHandler;

@end

//
// BCOVCatalogService+BCOVWidevineAdditions.h
// BrightcoveWidevine
//
// Copyright (c) 2016 Brightcove, Inc. All rights reserved.
// License: https://accounts.brightcove.com/en/terms-and-conditions
//

#import <BrightcovePlayerSDK/BCOVCatalogService.h>


/**
 * Adds methods to the BCOVCatalogService to retrieve Widevine assets.
 */
@interface BCOVCatalogService (BCOVWidevineAdditions)

/**
 * Returns an operation that retrieves a Widevine BCOVPlaylist corresponding to
 * the specified parameters.  Cast this operation's `result` property to a
 * `BCOVPlaylist *` if the operation succeeds.
 *
 * @param playlistID The playlist ID of the playlist to find.
 * @param parameters Additional NSString query parameters to add to catalog
 * service requests. These values will override the default values if they
 * conflict.
 * @return An operation that retrieves the specified Widevine BCOVPlaylist.
 */
- (BCOVCatalogOperation *)widevinePlaylistOperationWithPlaylistID:(NSString *)playlistID parameters:(NSDictionary *)parameters;

/**
 * Returns an operation that retrieves a Widevine BCOVPlaylist corresponding to
 * the specified parameters.  Cast this operation's `result` property to a
 * `BCOVPlaylist *` if the operation succeeds.
 *
 * @param referenceID The playlist reference ID of the playlist to find.
 * @param parameters Additional NSString query parameters to add to catalog
 * service requests. These values will override the default values if they
 * conflict.
 * @return An operation that retrieves the specified Widevine BCOVPlaylist.
 */
- (BCOVCatalogOperation *)widevinePlaylistOperationWithReferenceID:(NSString *)referenceID parameters:(NSDictionary *)parameters;

/**
 * Returns an operation that retrieves a Widevine BCOVVideo corresponding to
 * the specified parameters.  Cast this operation's `result` property to a
 * `BCOVVideo *` if the operation succeeds.
 *
 * @param videoID The video ID of the video to find.
 * @param parameters Additional NSString query parameters to add to catalog
 * service requests. These values will override the default values if they
 * conflict.
 * @return An operation that retrieves the specified Widevine BCOVVideo.
 */
- (BCOVCatalogOperation *)widevineVideoOperationWithVideoID:(NSString *)videoID parameters:(NSDictionary *)parameters;

/**
 * Returns an operation that retrieves a Widevine BCOVVideo corresponding to
 * the specified parameters.  Cast this operation's `result` property to a
 * `BCOVVideo *` if the operation succeeds.
 *
 * @param referenceID The video reference ID of the video to find.
 * @param parameters Additional NSString query parameters to add to catalog
 * service requests. These values will override the default values if they
 * conflict.
 * @return An operation that retrieves the specified Widevine BCOVVideo.
 */
- (BCOVCatalogOperation *)widevineVideoOperationWithReferenceID:(NSString *)referenceID parameters:(NSDictionary *)parameters;

/**
 * Returns an operation that retrieves JSON for a Widevine playlist
 * corresponding to the specified parameters.  Cast this operation's `result`
 * property to a `NSDictionary *` if the operation succeeds.
 *
 * @param playlistID The playlist ID of the playlist to find.
 * @param parameters Additional NSString query parameters to add to catalog
 * service requests. These values will override the default values if they
 * conflict.
 * @return An operation that retrieves the specified Widevine playlist as JSON.
 */
- (BCOVCatalogOperation *)widevinePlaylistDictionaryOperationWithPlaylistID:(NSString *)playlistID parameters:(NSDictionary *)parameters;

/**
 * Returns an operation that retrieves JSON for a Widevine playlist
 * corresponding to the specified parameters.  Cast this operation's `result`
 * property to a `NSDictionary *` if the operation succeeds.
 *
 * @param referenceID The playlist reference ID of the playlist to find.
 * @param parameters Additional NSString query parameters to add to catalog
 * service requests. These values will override the default values if they
 * conflict.
 * @return An operation that retrieves the specified Widevine playlist as JSON.
 */
- (BCOVCatalogOperation *)widevinePlaylistDictionaryOperationWithReferenceID:(NSString *)referenceID parameters:(NSDictionary *)parameters;

/**
 * Returns an operation that retrieves JSON for a Widevine video corresponding
 * to the specified parameters.  Cast this operation's `result` property to a
 * `NSDictionary *` if the operation succeeds.
 *
 * @param videoID The video ID of the video to find.
 * @param parameters Additional NSString query parameters to add to catalog
 * service requests. These values will override the default values if they
 * conflict.
 * @return An operation that retrieves the specified Widevine video as JSON.
 */
- (BCOVCatalogOperation *)widevineVideoDictionaryOperationWithVideoID:(NSString *)videoID parameters:(NSDictionary *)parameters;

/**
 * Returns an operation that retrieves JSON for a Widevine video corresponding
 * to the specified parameters.  Cast this operation's `result` property to a
 * `NSDictionary *` if the operation succeeds.
 *
 * @param referenceID The video reference ID of the video to find.
 * @param parameters Additional NSString query parameters to add to catalog
 * service requests. These values will override the default values if they
 * conflict.
 * @return An operation that retrieves the specified Widevine video as JSON.
 */
- (BCOVCatalogOperation *)widevineVideoDictionaryOperationWithReferenceID:(NSString *)referenceID parameters:(NSDictionary *)parameters;

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

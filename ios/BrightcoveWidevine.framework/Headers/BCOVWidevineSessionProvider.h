//
// BCOVWidevineSessionProvider.h
// BrightcoveWidevine
//
// Copyright (c) 2016 Brightcove, Inc. All rights reserved.
// License: https://accounts.brightcove.com/en/terms-and-conditions
//

#import <Foundation/Foundation.h>

#import <BrightcovePlayerSDK/BCOVBasicSessionProvider.h>


@protocol BCOVPlaybackSessionCommonPropertiesProtocol;

/**
 * Session provider implementation that delivers playback sessions with support
 * for Widevine.
 *
 * Instances of this class should not be created directly by clients of the
 * Brightcove Player SDK for iOS; instead use the `-[BCOVPlayerSDKManager createWidevineSessionProviderWithOptions:]`
 * factory method (which is added as a category method).
 */
@interface BCOVWidevineSessionProvider : NSObject <BCOVPlaybackSessionProvider>

@property (nonatomic, weak) id<BCOVPlaybackSessionCommonPropertiesProtocol> sessionCommonProperties;

@end


/**
 * The Widevine source selection policy determines
 * which source to select from a BCOVVideo object.
 */
@interface BCOVWidevineSourceSelectionPolicy : NSObject <NSCopying>

/**
 * Select the first Widevine video with the specified scheme.
 * If no Widevine source with that scheme is found, return the first Widevine
 * source of any scheme. If no Widevine source is found, fallback to the HLS
 * scheme-based source selection policy: select the first video in HLS with the
 * specified scheme.
 * If no such source is found, the first HLS source with any scheme is returned.
 * If no HLS sources are present, the first MP4 is returned.
 * If none of the above is found, the first source of any kind is returned.
 * @param scheme The preferred scheme (kBCOVSourceURLSchemeHTTP or
 * kBCOVSourceURLSchemeHTTPS) of the source URL.
 * @return A source selection policy that prefers HLS with the specified scheme.
 */
+ (BCOVBasicSessionProviderSourceSelectionPolicy)sourceSelectionWidevineWithScheme:(NSString *)scheme;

/**
 * Select the first Widevine video, preferring HTTPS over HTTP.
 * If no Widevine source found, fallback to the basic source selection policy:
 * select the first video in HLS, regardless of scheme.
 * If no HLS source is found, select the first source with a deliveryType of
 * "MP4". If neither is found, the first source of any kind is returned.
 * This is the default source selection policy.
 */
+ (BCOVBasicSessionProviderSourceSelectionPolicy)sourceSelectionWidevine;

@end


/**
 * Optional configuration for Widevine session providers.
 */
@interface BCOVWidevineSessionProviderOptions : NSObject

/**
 * Determines whether or not Widevine playback sessions should resume playback
 * when the app returns to the foreground.
 *
 * The default is YES.
 */
@property (nonatomic) BOOL resumePlaybackOnWillEnterForeground;

/**
 * The settings dictionary accepted by the Widevine SDK for iOS. For further
 * information about these settings, see the documentation for the Widevine SDK
 * for iOS.
 *
 * The default is an empty dictionary.
 */
@property (nonatomic, copy) NSDictionary *widevineSettings;

/**
 * The default policy selects the first source with a delivery type of "WVM".
 * If no Widevine source is found, it falls back to the default 
 * BCOVBasicSessionProviderOptions source selection policy.
 */
@property (nonatomic, copy) BCOVBasicSessionProviderSourceSelectionPolicy sourceSelectionPolicy;

@end

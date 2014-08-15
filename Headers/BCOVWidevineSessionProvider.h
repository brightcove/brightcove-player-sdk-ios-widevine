//
// BCOVWidevineSessionProvider.h
// BCOVWidevine
//
// Copyright (c) 2014 Brightcove, Inc. All rights reserved.
// License: https://accounts.brightcove.com/en/terms-and-conditions
//

#import <Foundation/Foundation.h>

#import "BCOVBasicSessionProvider.h"


/**
 * Session provider implementation that delivers playback sessions with support
 * for Widevine.
 *
 * Instances of this class should not be created directly by clients of the
 * Brightcove Player SDK for iOS; instead use the `-[BCOVPlayerSDKManager createWidevineSessionProviderWithOptions:]`
 * factory method (which is added as a category method).
 */
@interface BCOVWidevineSessionProvider : NSObject <BCOVPlaybackSessionProvider>

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

//
// BCOVWidevineComponent.h
// BCOVWidevine
//
// Copyright (c) 2014 Brightcove, Inc. All rights reserved.
// License: https://accounts.brightcove.com/en/terms-and-conditions
//

#import <Foundation/Foundation.h>

#import "BCOVPlayerSDKManager.h"


@protocol BCOVPlaybackSessionConsumerContainer;

@class IMASettings;
@class IMAAdsRenderingSettings;
@class BCOVWidevineSessionProviderOptions;


/**
 * Adds methods to BCOVPlayerSDKManager to create Widevine players.
 */
@interface BCOVPlayerSDKManager (BCOVWidevineAdditions)

/**
 * Creates and returns a new playback controller configured for Widevine with
 * the specified view strategy.
 *
 * @param viewStrategy A view strategy that determines the view for the returned
 * playback controller.
 * @return A new playback controller configured for Widevine playback sessions.
 */
- (id<BCOVPlaybackController>)createWidevinePlaybackControllerWithViewStrategy:(BCOVPlaybackControllerViewStrategy)viewStrategy;

/**
 * Creates and returns a new Widevine session provider with the specified
 * parameters.
 *
 * @param options Optional configuration for the BCOVWidevineSessionProvider.
 * @return A new session provider with the specified parameters.
 */
- (id<BCOVPlaybackSessionProvider>)createWidevineSessionProviderWithOptions:(BCOVWidevineSessionProviderOptions *)options;

@end

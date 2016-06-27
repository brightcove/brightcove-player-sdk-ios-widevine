//
// BCOVWidevineConstants.h
// BrightcoveWidevine
//
// Copyright (c) 2016 Brightcove, Inc. All rights reserved.
// License: https://accounts.brightcove.com/en/terms-and-conditions
//

/**
 * The eventType for a Widevine WViOsApiEvent sent via a lifecycle event.
 */
extern NSString * const kBCOVWidevineLifecycleEventWViOsApi;

/**
 * The key for the Widevine WViOsApiEvent attached to a kBCOVWidevineLifecycleEventWViOsApi
 * lifecycle event.
 */
extern NSString * const kBCOVWidevineWViOsApiEvent;

/**
 * The eventType that signifies that the Widevine session has been re-initialized
 * upon entering the foreground.
 */
extern NSString * const kBCOVWidevineLifeycleEventSessionDidResume;

/**
 * The eventType for a Widevine Error that occurs during initialization and sent
 * via a lifecycle event.
 */
extern NSString * const kBCOVWidevineLifecycleEventError;

/**
 * The key for the Widevine NSError attached to a kBCOVWidevineLifecycleEventError
 * lifecycle event.
 */
extern NSString * const kBCOVWidevineSessionError;

/**
 * The error domain for Widevine session errors.
 */
extern NSString * const kBCOVWidevineSessionErrorDomain;

/**
 * The delivery method for WVM (Widevine) media.
 */
extern NSString * const kBCOVSourceDeliveryWVM;

/**
 * The error domain for the Widevine library wrapper.
 */
extern NSString * const kBCOVWidevineWrapperErrorDomain;

/**
 * The WViOsApiStatus returned by the Widevine library.
 */
extern NSString * const kBCOVWidevineWrapperWViOsApiStatus;

/**
 * An error has occured during creation of the session.
 */
extern const NSInteger kBCOVWidevineSessionErrorCodeSessionCreationFailed;

/**
 * An error has occured during the initialization of Widevine.
 */
extern const NSInteger kBCOVWidevineWrapperErrorCodeInitializationFailed;

/**
 * An error has occured when attempting to play a Widevine asset.
 */
extern const NSInteger kBCOVWidevineWrapperErrorCodePlayFailed;

/**
 * An error has occured when attempting unload a Widevine asset from the Widevine
 * library.
 */
extern const NSInteger kBCOVWidevineWrapperErrorCodeStopFailed;

/**
 * An erro has occured when attempting to terminate Widevine.
 */
extern const NSInteger kBCOVWidevineWrapperErrorCodeTerminateFailed;

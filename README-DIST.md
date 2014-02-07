Brightcove Widevine Component
============

The Brightcove Widevine Component, version 1.0.4.104, allows for playback of Widevine encrypted Sources.

Installation
===========

The Brightcove Widevine Component will need to be manually added to your Xcode project.  There are several ways you achieve this, but here is one example:

1. Extract the BCOVWidevine zip file. 
1. Drag the BCOVWidevine folder into the navigation tree of your Xcode project.  At the prompt, check "Copy items into destination group's folder (if needed)" if you want the files copied into the same directory as your project.  In addition, select any targets that you would like to add the library files to.
1. Under your project's `Build Settings`, ensure that the directory that contains headers and libraries for the Brightcove Widevine Component are added to the `Header Search Paths` and the `Library Search Paths`.
1. Under your project's `Build Phases`, ensure that the libraries for the Brightcove Widevine Component are added to the `Link Binary with Libraries` phase.
    * libBCOVWidevine.a
    * libWViPhoneAPI.a
    * libc++
    * libxml2
    * libresolv
    * libSystem
    * libz



Usage
===========

For convenience, you can import `#import "BCOVWidevine.h"`to access all the component headers.

Before using the Brightcove Widevine Component, you are required to register with the Player SDK Manager.

    BCOVPlayerSDKManager *sdkManager = [BCOVPlayerSDKManager sharedManager];
    
    BCOVWidevineComponent *component = [[BCOVWidevineComponent alloc] init];
    [sdkManager registerComponent:component];


Once registered, you can access any of the methods now exposed on the Player SDK Manager to create a Video Controller that uses Widevine.


Known Issues
===========
Playing back mixed content (widevine/nonwidevine) in the same playlist is not supported.
Decrypting content on the simulator is not supported.



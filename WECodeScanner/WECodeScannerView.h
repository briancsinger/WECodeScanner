//
//  WECodeScannerView.h
//  WECodeScanner
//
//  Created by Werner Altewischer on 10/11/13.
//  Copyright (c) 2013 Werner IT Consultancy. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

@class WECodeScannerView;

@protocol WECodeScannerViewDelegate < NSObject >

- (void)scannerView:(WECodeScannerView *)scannerView didReadCode:(NSString*)code;

@optional
- (void)scannerViewDidStartScanning:(WECodeScannerView *)scannerView;
- (void)scannerViewDidStopScanning:(WECodeScannerView *)scannerView;

@end

@interface WECodeScannerView : UIView

@property (nonatomic, strong) AVCaptureVideoPreviewLayer *previewLayer;
@property (nonatomic, assign) AVCaptureDevice *videoCaptureDevice;
@property (nonatomic, weak) id <WECodeScannerViewDelegate> delegate;
@property (nonatomic, assign) NSTimeInterval quietPeriodAfterMatch;

/**
 *  Defines the video preview torch mode.
 */
@property (nonatomic, assign, readwrite, getter = isFlashEnabled) BOOL flashEnabled;

/**
 *  Hides or displays the torch button in the navigation bar.
 *  The default value is YES.
 */
@property (nonatomic, assign, readwrite, getter = isFlashButtonEnabled) BOOL flashButtonEnabled;

/**
 *  Indicates if the torch mode is available. Varies depending on the device.
 */
@property (nonatomic, assign, readonly, getter = isFlashModeAvailable) BOOL flashModeAvailable;


- (void)setMetadataObjectTypes:(NSArray *)metaDataObjectTypes;
- (void)start;
- (void)stop;


@end

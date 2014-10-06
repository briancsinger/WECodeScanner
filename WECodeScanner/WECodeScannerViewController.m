//
//  WECodeScannerViewController.m
//  WECodeScanner
//
//  Created by Brian Singer on 10/5/14.
//  Copyright (c) 2014 Werner IT Consultancy. All rights reserved.
//

#import "WECodeScannerViewController.h"

@interface WECodeScannerViewController ()
- (void) toggleFlash:(id)sender;
@end

@implementation WECodeScannerViewController

- (id) init {
    
    if ((self = [super init])) {
    
        self.scannerView = [[WECodeScannerView alloc] init];
        self.view = _scannerView;
        
    }
    
    return self;
}

- (void) viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    // Do any additional setup after loading the view.
    if (_scannerView.flashModeAvailable) {
        UIBarButtonItem *torchToggle = [[UIBarButtonItem alloc] initWithTitle:NSLocalizedStringWithDefaultValue(@"bcscanner_torch", nil, [NSBundle mainBundle], @"Torch", @"The title of the torch mode button") style:UIBarButtonItemStyleBordered target:self action:@selector(toggleFlash:)];
        [self.navigationItem setRightBarButtonItem:torchToggle animated:YES];
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

- (void) toggleFlash:(id)sender {
    self.scannerView.flashEnabled = !self.scannerView.flashEnabled;
    
    [self.scannerView.videoCaptureDevice lockForConfiguration:nil];
    self.scannerView.videoCaptureDevice.torchMode = (self.scannerView.flashEnabled ? AVCaptureTorchModeOn : AVCaptureTorchModeOff);
    [self.scannerView.videoCaptureDevice unlockForConfiguration];
}

@end

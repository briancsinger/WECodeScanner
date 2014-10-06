//
//  WECodeScannerViewController.h
//  WECodeScanner
//
//  Created by Brian Singer on 10/5/14.
//  Copyright (c) 2014 Werner IT Consultancy. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "WECodeScannerView.h"

@interface WECodeScannerViewController : UIViewController

@property (nonatomic, retain) WECodeScannerView *scannerView;
@property BOOL flashOn;

@end

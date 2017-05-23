//
//  LPFFeedbackViewController.h
//  LifePics
//
//  Created by Dave Batton on 3/3/14.
//  Copyright (c) 2014 Taylor Corp. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LPFViewController.h"

@interface LPFFeedbackViewController: LPFViewController

- (id)initWithPrimaryColor:(UIColor*)primary secondColor:(UIColor*)second;
- (void)setPrimaryColor:(UIColor*)primary secondColor:(UIColor*)second;
@end

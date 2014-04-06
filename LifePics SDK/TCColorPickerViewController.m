//
//  TCColorPickerViewController.m
//  LifePics SDK
//
//  Created by Dave Batton on 3/22/14.
//  Copyright (c) 2014 Taylor Corp. All rights reserved.
//

#import "TCColorPickerViewController.h"
#import "ISColorWheel.h"


@interface TCColorPickerViewController () <ISColorWheelDelegate>

@property (nonatomic, strong) ISColorWheel* colorWheel;
@property (nonatomic, strong) UISlider *brightnessSlider;

@end


@implementation TCColorPickerViewController


- (void)viewDidLoad
{
    [super viewDidLoad];

    self.view.backgroundColor = [UIColor whiteColor];
    
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemCancel
                                                                                           target:self
                                                                                           action:@selector(cancel:)];

    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemDone
                                                                                           target:self
                                                                                           action:@selector(done:)];

    CGSize size = CGSizeMake(self.view.bounds.size.width * .9, self.view.bounds.size.width * .9);
    CGRect frame = CGRectMake(truncf((self.view.bounds.size.width - size.width) * 0.5f),
                              150.0f,
                              size.width,
                              size.height);
    self.colorWheel = [[ISColorWheel alloc] initWithFrame:frame];
    self.colorWheel.delegate = self;
    self.colorWheel.continuous = YES;
    [self.view addSubview:self.colorWheel];

    size = CGSizeMake(200.0f, 50.0f);
    frame = CGRectMake(truncf((self.view.bounds.size.width - size.width) * 0.5f),
                       CGRectGetMaxY(frame) + 50.0f,
                       size.width ,
                       size.height);
    self.brightnessSlider = [[UISlider alloc] initWithFrame:frame];
    self.brightnessSlider.minimumValue = 0.0;
    self.brightnessSlider.maximumValue = 1.0;
    self.brightnessSlider.value = 1.0;
    self.brightnessSlider.continuous = true;
    [self.brightnessSlider addTarget:self action:@selector(changeBrightness:) forControlEvents:UIControlEventValueChanged];
    [self.view addSubview:self.brightnessSlider];

    self.navigationController.navigationBar.barTintColor = self.color;

    NSDictionary *attributes = @{NSForegroundColorAttributeName : [UIColor whiteColor]};
    self.navigationController.navigationBar.titleTextAttributes = attributes;
    self.navigationItem.leftBarButtonItem.tintColor = [UIColor whiteColor];
    self.navigationItem.rightBarButtonItem.tintColor = [UIColor whiteColor];
}


- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];

    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.0f * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        self.colorWheel.currentColor = self.color;
        self.brightnessSlider.value = self.colorWheel.brightness;
        self.brightnessSlider.tintColor = self.colorWheel.currentColor;
    });

}


#pragma mark - ISColorWheelDelegate


- (void)colorWheelDidChangeColor:(ISColorWheel *)colorWheel
{
    self.navigationController.navigationBar.barTintColor = self.colorWheel.currentColor;
    self.brightnessSlider.tintColor = self.colorWheel.currentColor;

    if ([self.delegate respondsToSelector:@selector(colorPickerViewController:didSelectColor:)]) {
        [self.delegate colorPickerViewController:self didSelectColor:self.colorWheel.currentColor];
    }
}


#pragma mark - Actions


- (IBAction)cancel:(id)sender
{
    [self dismissViewControllerAnimated:YES completion:NULL];
}


- (IBAction)done:(id)sender
{
    self.color = self.colorWheel.currentColor;
    [self dismissViewControllerAnimated:YES completion:NULL];
}


- (void)changeBrightness:(UISlider*)sender
{
    [self.colorWheel setBrightness:self.brightnessSlider.value];
    [self.colorWheel updateImage];
    [self colorWheelDidChangeColor:self.colorWheel];
}


#pragma mark - Accessors


- (void)setColor:(UIColor *)color
{
    if ([_color isEqual:color] == NO) {
        _color = color;
        self.colorWheel.currentColor = _color;
    }
}


@end

//
//  LPFMenuViewController.h
//  LifePics
//
//  Created by administrator on 16/2/3.
//  Copyright © 2016 Taylor Corp. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "APLSlideMenuViewController.h"
#import <LocalAuthentication/LocalAuthentication.h>

@class LPFOrderViewController;

@interface LPFMenuAccountCell : UITableViewCell

@property (weak, nonatomic) IBOutlet UIImageView *accountImg;
@property (weak, nonatomic) IBOutlet UIButton *btnSignIn;
@property (weak, nonatomic) IBOutlet UILabel *line;
@property (weak, nonatomic) IBOutlet UIView *view;

@end


@interface LPFMenuViewController : UIViewController<UITableViewDataSource,UITableViewDelegate,APLSlideMenuViewControllerDelegate>
{
    NSMutableArray* array;
    UIColor *primaryColor;
    UIColor *secondColor;
    UIColor *rowColor;
    UIColor *selectedRowColor;
    UIColor *separatorColor;
    APLSlideMenuViewController *slideMenuViewController;
}

@property LPFOrderViewController *refOrderViewController;
@property (weak, nonatomic) IBOutlet UITableView *table;


@end

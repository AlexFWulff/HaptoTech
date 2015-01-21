//
//  ViewController.h
//  BLERead
//
//  Created by Alex Wulff on 1/4/15.
//  Copyright (c) 2015 Conifer Apps. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BLE.h"

@interface ViewController : UIViewController <BLEDelegate, UITextFieldDelegate> {
    BLE *bleShield;
}

@property (nonatomic) bool firstEdit;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *spinner;
@property (weak, nonatomic) IBOutlet UITextField *textField;
@property (weak, nonatomic) IBOutlet UILabel *label;
@property (weak, nonatomic) IBOutlet UILabel *labelRSSI;
@property (weak, nonatomic) IBOutlet UIButton *buttonConnect;
@property (weak, nonatomic) IBOutlet UILabel *deviceNameLabel;

@property (weak, nonatomic) IBOutlet UITextField *field1;
@property (weak, nonatomic) IBOutlet UITextField *field2;
@property (weak, nonatomic) IBOutlet UITextField *field3;

@property (weak, nonatomic) IBOutlet UIView *view1;
@property (weak, nonatomic) IBOutlet UIView *view2;
@property (weak, nonatomic) IBOutlet UIView *view3;

@property (nonatomic) bool weGotValues;

- (IBAction)updateButtonPressed:(UIButton *)sender;
- (IBAction)refreshButtonPressed:(id)sender;

@property (weak, nonatomic) IBOutlet UILabel *inchesAwayLabel;
@property (weak, nonatomic) IBOutlet UITextField *frameField1;

@property (weak, nonatomic) IBOutlet UITextField *frameField2;
@property (weak, nonatomic) IBOutlet UITextField *frameField3;
@property (weak, nonatomic) IBOutlet UILabel *frameLabel1;
@property (weak, nonatomic) IBOutlet UILabel *frameLabel2;
@property (weak, nonatomic) IBOutlet UILabel *frameLabel3;
@property (weak, nonatomic) IBOutlet UIButton *frameButton;
@property (weak, nonatomic) IBOutlet UILabel *label1;
@property (weak, nonatomic) IBOutlet UILabel *label2;
@property (weak, nonatomic) IBOutlet UILabel *label3;
@property (weak, nonatomic) IBOutlet UIButton *updateButton;
@property (weak, nonatomic) IBOutlet UILabel *inches1;
@property (weak, nonatomic) IBOutlet UILabel *inches2;
@property (weak, nonatomic) IBOutlet UILabel *inches3;


@end

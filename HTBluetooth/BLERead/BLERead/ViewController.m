//
//  ViewController.m
//  BLERead
//
//  Created by Alex Wulff on 1/4/15.
//  Copyright (c) 2015 Conifer Apps. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

UIColor* color1;
UIColor* color2;
UIColor* color3;

CGRect text1Frame;
CGRect text2Frame;
CGRect text3Frame;
CGRect label1Frame;
CGRect label2Frame;
CGRect label3Frame;
CGRect buttonFrame;

CGRect newtext1Frame;
CGRect newtext2Frame;
CGRect newtext3Frame;
CGRect newlabel1Frame;
CGRect newlabel2Frame;
CGRect newlabel3Frame;
CGRect newbuttonFrame;

bool editingValues;

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    bleShield = [[BLE alloc] init];
    [bleShield controlSetup];
    bleShield.delegate = self;
    self.weGotValues = false;
    
    color1 = self.view1.backgroundColor;
    color2 = self.view2.backgroundColor;
    color3 = self.view3.backgroundColor;
    
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
}

// Called when scan period is over to connect to the first found peripheral
-(void) connectionTimer:(NSTimer *)timer
{
    if(bleShield.peripherals.count > 0)
    {
        [bleShield connectPeripheral:[bleShield.peripherals objectAtIndex:0]];
    }
    else
    {
        [self.spinner stopAnimating];
    }
}

-(void) bleDidReceiveData:(unsigned char *)data length:(int)length
{
    NSData *d = [NSData dataWithBytes:data length:length];
    
    NSString *s = [[NSString alloc] initWithData:d encoding:NSUTF8StringEncoding];
    
    const char* clearChar = "!";
    
    if ([self.label.text isEqualToString:@"Label"]) {
        self.label.text = @"";
    }
    
    else if ([s isEqualToString:[NSString stringWithUTF8String:clearChar]]) {
        self.label.text = @"";
    }
    
    else {
//        NSArray *wordList = [s componentsSeparatedByString:@" "]; //Need to get just the number, not the CM at the end.
//        
//        NSString *store = [wordList objectAtIndex:0];
//        NSString *full = [NSString stringWithFormat:@"%@ CM",s];
        self.label.text = s;
    }

    int val1 = [self.field1.text intValue];
    int val2 = [self.field2.text intValue];
    int val3 = [self.field3.text intValue];
    
    int distance = [s intValue];
    
    if (distance != 0) {
    
    if (self.weGotValues == true) {
        if (distance < val3 || distance < val2 || distance < val1) {
        [UIView animateWithDuration:0.5 animations:^{
            if (distance < val1) {
                self.view1.backgroundColor = [UIColor redColor];
            }
            if (distance < val2) {
                self.view2.backgroundColor = [UIColor redColor];
            }
            if (distance < val3) {
                self.view3.backgroundColor = [UIColor redColor];
            }
        } completion:^(BOOL finished) {
            if (distance < val1) {
                self.view1.backgroundColor = color1;
            }
            
            if (distance < val2) {
                self.view2.backgroundColor = color2;
            }
            
            if (distance < val3) {
                self.view3.backgroundColor = color3;
            }
        }];
        }
        if (distance > val3 ) {
            self.view3.backgroundColor = color3;
        }
        
        if (distance > val2) {
            self.view2.backgroundColor = color2;
        }
        
        if (distance > val1) {
            self.view1.backgroundColor = color1;
        }
    }
    }

}

NSTimer *rssiTimer;

-(void) readRSSITimer:(NSTimer *)timer
{
    [bleShield readRSSI];
}

- (void) bleDidDisconnect
{
    [self.buttonConnect setTitle:@"Connect" forState:UIControlStateNormal];
    
    UIAlertView *message = [[UIAlertView alloc] initWithTitle:@"Disconnect"
                                                      message:@"Your HaptoTech device has disconnected. Please select 'Connect' to reconnect to your device."
                                                     delegate:self
                                            cancelButtonTitle:@"OK"
                                            otherButtonTitles:nil];
    [message show];
    
    [rssiTimer invalidate];
}

-(void) bleDidConnect
{
    [self.spinner stopAnimating];
    [self.buttonConnect setTitle:@"Disconnect" forState:UIControlStateNormal];
    
    self.deviceNameLabel.text = [bleShield activePeripheral].name;
    
    // Schedule to read RSSI every 1 sec.
    rssiTimer = [NSTimer scheduledTimerWithTimeInterval:(float)1.0 target:self selector:@selector(readRSSITimer:) userInfo:nil repeats:YES];
}

-(void) bleDidUpdateRSSI:(NSNumber *)rssi
{
    self.labelRSSI.text = rssi.stringValue;
}

- (IBAction)BLEShieldSend:(id)sender
{
    NSString *s;
    NSData *d;
    
    if (self.textField.text.length > 16)
        s = [self.textField.text substringToIndex:16];
    else
        s = self.textField.text;
    
    s = [NSString stringWithFormat:@"%@\r\n", s];
    d = [s dataUsingEncoding:NSUTF8StringEncoding];
    
    [bleShield write:d];
}

-(void)textFieldDidBeginEditing:(UITextField *)textField {
    if (self.firstEdit == false) {
        text1Frame = self.field1.frame;
        text2Frame = self.field2.frame;
        text3Frame = self.field3.frame;
        label1Frame = self.label1.frame;
        label2Frame = self.label2.frame;
        label3Frame = self.label3.frame;
        buttonFrame = self.updateButton.frame;
        
        newtext1Frame = self.frameField1.frame;
        newtext2Frame = self.frameField2.frame;
        newtext3Frame = self.frameField3.frame;
        newlabel1Frame = self.frameLabel1.frame;
        newlabel2Frame = self.frameLabel2.frame;
        newlabel3Frame = self.frameLabel3.frame;
        newbuttonFrame = self.frameButton.frame;
        self.firstEdit = true;

    }
    
    self.weGotValues = false;

    [UIView animateWithDuration:0.5 animations:^{
        self.field1.frame = newtext1Frame;
        self.field2.frame = newtext2Frame;
        self.field3.frame = newtext3Frame;
        self.label1.frame = newlabel1Frame;
        self.label2.frame = newlabel2Frame;
        self.label3.frame = newlabel3Frame;
        self.updateButton.frame = newbuttonFrame;
        self.inches1.alpha = 0;
        self.inches2.alpha = 0;
        self.inches3.alpha = 0;
        self.label.alpha = 0;
        self.inchesAwayLabel.alpha = 0;
    }];
    

}

- (IBAction)BLEShieldScan:(id)sender
{
    if (bleShield.activePeripheral)
        if(bleShield.activePeripheral.isConnected)
        {
            [[bleShield CM] cancelPeripheralConnection:[bleShield activePeripheral]];
            return;
        }
    
    if (bleShield.peripherals)
        bleShield.peripherals = nil;
    
    [bleShield findBLEPeripherals:3];
    
    [NSTimer scheduledTimerWithTimeInterval:(float)3.0 target:self selector:@selector(connectionTimer:) userInfo:nil repeats:NO];
    
    [self.spinner startAnimating];
}
- (IBAction)updateButtonPressed:(UIButton *)sender {
    [self.field1 resignFirstResponder];
    [self.field2 resignFirstResponder];
    [self.field3 resignFirstResponder];
    
    NSNumberFormatter *nf = [[NSNumberFormatter alloc] init];
    BOOL isDecimal = [nf numberFromString:self.field1.text] != nil;
    BOOL isDecimal2 = [nf numberFromString:self.field2.text] != nil;
    BOOL isDecimal3 = [nf numberFromString:self.field3.text] != nil;
    
    bool error = false;
    bool clear1 = false;
    bool clear2 = false;
    bool clear3 = false;
    
    int val1 = [self.field1.text intValue];
    int val2 = [self.field2.text intValue];
    int val3 = [self.field3.text intValue];
    
    if (isDecimal == false || isDecimal2 == false || isDecimal3 == false)
    {
        
        UIAlertView *message = [[UIAlertView alloc] initWithTitle:@"Error"
                                                          message:@"One or more of the entered values is not a number."
                                                         delegate:self
                                                cancelButtonTitle:@"OK"
                                                otherButtonTitles:nil];
        [message show];
        
        if (isDecimal == false) {
            clear1 = true;
        }
        
        if (isDecimal2 == false) {
            clear2 = true;
        }
        
        if (isDecimal3 == false) {
            clear3 = true;
        }
        
        error = true;
    }
    
    
    if ([self.field3.text  isEqual: @""] || [self.field2.text  isEqual: @""] || [self.field1.text  isEqual: @""]) {
        UIAlertView *message = [[UIAlertView alloc] initWithTitle:@"Error"
                                                          message:@"One or more of the fields is blank."
                                                         delegate:self
                                                cancelButtonTitle:@"OK"
                                                otherButtonTitles:nil];
        [message show];
        
        error = true;
    }
    
    if (error == false) {
        if (val3 >= val2) {
            error = true;
            clear3 = true;
            UIAlertView *message = [[UIAlertView alloc] initWithTitle:@"Error"
                                                              message:@"The smallest value cannot be larger than or equal to the medium value."
                                                             delegate:self
                                                    cancelButtonTitle:@"OK"
                                                    otherButtonTitles:nil];
            [message show];

        }
        
        if (val2 >= val1) {
            UIAlertView *message = [[UIAlertView alloc] initWithTitle:@"Error"
                                                              message:@"The medium value cannot be larger than or equal to the largest value."
                                                             delegate:self
                                                    cancelButtonTitle:@"OK"
                                                    otherButtonTitles:nil];
            [message show];

            error = true;
            clear2 = true;
        }
        
        if (val3 >= val1) {
            UIAlertView *message = [[UIAlertView alloc] initWithTitle:@"Error"
                                                              message:@"The smallest value cannot be larger than or equal to the largest value."
                                                             delegate:self
                                                    cancelButtonTitle:@"OK"
                                                    otherButtonTitles:nil];
            [message show];
            
            error = true;
            clear3 = true;

        }
    }
    
    if (error == true) {
        if (clear1 == true) {
            self.field1.text = @"";
        }
        
        if (clear2 == true) {
            self.field2.text = @"";
        }
        
        if (clear3 == true) {
            self.field3.text = @"";
        }
    }
    
    if (error == false) {
        self.weGotValues = true;
        [UIView animateWithDuration:0.5 animations:^{
            self.field1.frame = text1Frame;
            self.field2.frame = text2Frame;
            self.field3.frame = text3Frame;
            self.label1.frame = label1Frame;
            self.label2.frame = label2Frame;
            self.label3.frame = label3Frame;
            self.updateButton.frame = buttonFrame;
            self.inches1.alpha = 1;
            self.inches2.alpha = 1;
            self.inches3.alpha = 1;
            self.label.alpha = 1;
            self.inchesAwayLabel.alpha = 1;
            
        }];
    }
    
}

- (IBAction)refreshButtonPressed:(id)sender {
        self.view3.backgroundColor = color3;
        self.view2.backgroundColor = color2;
        self.view1.backgroundColor = color1;
}
@end


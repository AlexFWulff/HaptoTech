//
//  ViewController.m
//  BLERead
//
//  Created by Alex Wulff on 1/4/15.
//  Copyright (c) 2015 Conifer Apps. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    bleShield = [[BLE alloc] init];
    [bleShield controlSetup];
    bleShield.delegate = self;
    self.weGotValues = false;
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
    
    UIColor* color1 = self.view1.backgroundColor;
    UIColor* color2 = self.view2.backgroundColor;
    UIColor* color3 = self.view3.backgroundColor;

    int val1 = [self.field1.text intValue];
    int val2 = [self.field2.text intValue];
    int val3 = [self.field3.text intValue];
    
    int distance = [s intValue];
    
    NSLog(@"%i",distance);
    NSLog(@"%d",self.weGotValues);
    
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
    self.weGotValues = false;
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
                                                              message:@"The smallest range cannot be larger than or equal to the medium range."
                                                             delegate:self
                                                    cancelButtonTitle:@"OK"
                                                    otherButtonTitles:nil];
            [message show];

        }
        
        if (val2 >= val1) {
            UIAlertView *message = [[UIAlertView alloc] initWithTitle:@"Error"
                                                              message:@"The medium range cannot be larger than or equal to the longest range."
                                                             delegate:self
                                                    cancelButtonTitle:@"OK"
                                                    otherButtonTitles:nil];
            [message show];

            error = true;
            clear2 = true;
        }
        
        if (val3 >= val1) {
            UIAlertView *message = [[UIAlertView alloc] initWithTitle:@"Error"
                                                              message:@"The smallest range cannot be larger than or equal to the largest range."
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
    }
    
}
@end


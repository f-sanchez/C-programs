//
//  ViewController.m
//  LE41
//
//  Created by SANCHEZ, FRETZEL EVE CANTAY on 09/01/2018.
//  Copyright (c) 2018 SANCHEZ, FRETZEL EVE CANTAY. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)add:(id)sender {
    float answer;
    [_num1 resignFirstResponder];
    [_num2 resignFirstResponder];
    
    answer = [_num1.text floatValue] + [_num2.text floatValue];
    _res.text = [NSString stringWithFormat: @"%0.2f", answer];

}

- (IBAction)sub:(id)sender {
    float answer;
    [_num1 resignFirstResponder];
    [_num2 resignFirstResponder];
    
    answer = [_num1.text floatValue] - [_num2.text floatValue];
    _res.text = [NSString stringWithFormat: @"%0.2f", answer];

}

- (IBAction)mult:(id)sender {
    float answer;
    [_num1 resignFirstResponder];
    [_num2 resignFirstResponder];
    
    answer = [_num1.text floatValue] * [_num2.text floatValue];
    _res.text = [NSString stringWithFormat: @"%0.2f", answer];

}

- (IBAction)div:(id)sender {
    float answer;
    [_num1 resignFirstResponder];
    [_num2 resignFirstResponder];
    
    answer = [_num1.text floatValue] / [_num2.text floatValue];
    _res.text = [NSString stringWithFormat: @"%0.2f", answer];

}


@end

/*
float answer = [_num1.text floatValue] + [_num2.text floatValue]; //num1 and num2 = vars
[answer setValue: result]; //answer = var | result=txtbox
_result.text = [NSString stringWithFormat: @"%0.2f", answer];

*/

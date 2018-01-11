//
//  ViewController.h
//  LE41
//
//  Created by SANCHEZ, FRETZEL EVE CANTAY on 09/01/2018.
//  Copyright (c) 2018 SANCHEZ, FRETZEL EVE CANTAY. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController
- (IBAction)add:(id)sender;

- (IBAction)sub:(id)sender;

- (IBAction)mult:(id)sender;
- (IBAction)div:(id)sender;

@property (weak, nonatomic) IBOutlet UITextField *num1;

@property (weak, nonatomic) IBOutlet UITextField *num2;
@property (weak, nonatomic) IBOutlet UILabel *res;

@end


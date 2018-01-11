//
//  main.m
//  LE22
//
//  Created by SANCHEZ, FRETZEL EVE on 09/01/2018.
//  Copyright (c) 2018 SANCHEZ, FRETZEL EVE. All rights reserved.
//

#import <Foundation/Foundation.h>

NSString* getInput() {

    NSFileHandle *input = [NSFileHandle fileHandleWithStandardInput];

    return [[[NSString alloc] initWithData:[NSData dataWithData:[input availableData]] encoding:NSUTF8StringEncoding]

            stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];

}

int main(int argc, const char * argv[]) {

    @autoreleasepool {

        // insert code here...

        NSLog(@"Please enter 10 names:");

        NSMutableDictionary *db = [NSMutableDictionary new];
  
        for(int i = 0; i < 10; i++) {

            NSString *name;

            NSLog(@"Please enter name #%d:", i + 1);

            while([name = getInput() isEqual: @""]) {

                NSLog(@"Please enter an actual name!");

                NSLog(@"Please enter name #%d:", i + 1);
            }

            NSMutableArray *activities = [NSMutableArray new];

            NSLog(@"Please enter the activities the student is in.");

            NSLog(@"Possible activities are basketball, floor hockey, arts, checkers");

            NSLog(@"Press enter to exit");

            NSString *activity;

            while(![activity = getInput() isEqual: @""]) {

                activity = [activity lowercaseString];

               
                if([activity isEqual:@"basketball"] ||

                   [activity isEqual:@"floor hockey"] ||

                   [activity isEqual:@"arts"] ||

                   [activity isEqual:@"checkers"]) {

                    [activities addObject:activity];

               
                } else {

                    NSLog(@"Invalid activity given.");

                    NSLog(@"Possible activities are basketball, floor hockey, arts, checkers");

                }

            }

            [db setObject:activities forKey:name];
        }

        NSArray *names = [[db allKeys] sortedArrayUsingSelector:@selector(compare:)];

        for(NSString *name in names) {

            NSMutableArray *activities = db[name];

            NSLog(@"Student Name: %@, activities: %@", name, activities);
        }
    }
    
    return 0;
}


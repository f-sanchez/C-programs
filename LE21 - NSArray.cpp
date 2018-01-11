int main(int argc, const char * argv[]) {
	
  @autoreleasepool {
  	
      char name[30];
      NSString *myString;
      NSLog(@"After School");
      NSMutableArray *tracker = [ [NSMutableArray alloc] init];
      NSArray *sortedArray;
      
      for (int i=0; i<10; i++){
          NSLog(@"Enter name: ");
          scanf("%s",&name);
          myString = [NSString stringWithCString:name encoding:NSASCIIStringEncoding];
          [tracker addObject:myString];
      }
      
      sortedArray = [tracker sortedArrayUsingSelector: @selector(localizedCaseInsensitiveCompare:)];
      NSLog(@"Names:  %@",sortedArray);
  }
  return 0;
}


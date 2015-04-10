//
//  HBImagePickerControllerEx.h
//  DZ
//
//  Created by Nonato on 14-6-12.
//  Copyright (c) 2014年 Nonato. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface HBImagePickerControllerEx : UIImagePickerController
- (void)viewDidDisappear:(BOOL)animated;
- (void)viewDidAppear:(BOOL)animated;
- (void)viewWillDisappear:(BOOL)animated;
+(UIImage *)scaleImage:(UIImage *)image toScale:(float)scaleSize;
@end

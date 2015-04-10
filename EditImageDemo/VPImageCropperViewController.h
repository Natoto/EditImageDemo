//
//  VPImageCropperViewController.h
//  VPolor
//
//  Created by Vinson.D.Warm on 12/30/13.
//  Copyright (c) 2013 Huang Vinson. All rights reserved.
//

#import <UIKit/UIKit.h>
@class VPImageCropperViewController;

@protocol VPImageCropperDelegate <NSObject>

- (void)imageCropper:(VPImageCropperViewController *)cropperViewController didFinished:(UIImage *)editedImage;
- (void)imageCropperDidCancel:(VPImageCropperViewController *)cropperViewController;
-(BOOL)imageCropperAutoLoadsubview:(VPImageCropperViewController *)cropperViewController;
@end

@interface VPImageCropperViewController : UIViewController

@property (nonatomic, retain) UIImageView *showImgView;
@property (nonatomic, retain) UIImage *originalImage;
@property (nonatomic, assign) NSInteger tag;
@property (nonatomic, assign) id<VPImageCropperDelegate> cropdelegate;
@property (nonatomic, assign) CGRect cropFrame;
- (void)initView;
- (id)initWithImage:(UIImage *)originalImage cropFrame:(CGRect)cropFrame limitScaleRatio:(NSInteger)limitRatio;

-(void)LoadWithImage:(UIImage *)originalImage cropFrame:(CGRect)cropFrame limitScaleRatio:(NSInteger)limitRatio;
-(UIImage *)getSubImage;

-(void)superdealloc;

-(void)removeGestureRecognizers;
- (void) addGestureRecognizers;
@end

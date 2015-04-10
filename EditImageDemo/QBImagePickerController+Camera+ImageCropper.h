//
//  QBImagePickerController+Camera.h
//  EditImageDemo
//
//  Created by 星盛 on 15/4/8.
//  Copyright (c) 2015年 星盛. All rights reserved.
//

#import "QBImagePickerController.h"
#import "VPImageCropperViewController.h"
#import <AVFoundation/AVFoundation.h>
@protocol QBImagePickerControllerCameraDelegate <NSObject>

@optional

/**
 * 从相册挑选一张图片
 */
- (void)hb_imagePickerController:(UIViewController *)imagePickerController didSelectAsset:(ALAsset *)asset;
/**
 * 从相册挑选图片 一系列的图片
 */
- (void)hb_imagePickerController:(UIViewController *)imagePickerController didSelectAssets:(NSArray *)assets;
/**
 * 从相册挑选图片取消
 */
- (void)hb_imagePickerControllerDidCancel:(UIViewController *)imagePickerController;
/**
 * 从相机选择图片
 */
-(void)hb_imagePickerController:(UIViewController *)viewController cameraDidFinishPickingMediaWithImage:(UIImage *)image;
/**
 * 编辑取消
 */
-(void)hb_imageCropperDidCancel:(UIViewController *)cropperViewController;
/**
 * 编辑完成结果
 */
-(void)hb_imageCropperViewController:(UIViewController *)cropperViewController didFinished:(UIImage *)editedImage;

@end

@interface UIViewController(Camera)<UIImagePickerControllerDelegate,UINavigationControllerDelegate,QBImagePickerControllerDelegate,VPImageCropperDelegate>

-(void)presentCameraViewControllerWithAnimated: (BOOL)flag completion:(void (^)(void))completion;

-(void)presentAblumViewControllerWithAnimated: (BOOL)flag completion:(void (^)(void))completion;

-(void)setQBImagePickerControllerCameraDelegate:(id)delegate;

-(void)publishVPImageCropperViewControllerWithImage:(UIImage *)image;

@end

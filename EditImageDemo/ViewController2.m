//
//  ViewController2.m
//  EditImageDemo
//
//  Created by 星盛 on 15/4/8.
//  Copyright (c) 2015年 星盛. All rights reserved.
//

#import "ViewController2.h"
#import "QBImagePickerController.h"
#import "VPImageCropperViewController.h"

#import "QBImagePickerController+Camera+ImageCropper.h"

@interface ViewController2 ()<UIActionSheetDelegate,VPImageCropperDelegate,QBImagePickerControllerCameraDelegate>


@property (weak, nonatomic) IBOutlet UIImageView *img_profile;

@end

@implementation ViewController2

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    UITapGestureRecognizer * tapgesture = [[UITapGestureRecognizer  alloc] initWithTarget:self action:@selector(imageViewTap:)];
    self.img_profile.userInteractionEnabled = YES;
    [self.img_profile addGestureRecognizer:tapgesture];
    [self setQBImagePickerControllerCameraDelegate:self];
}

-(void)imageViewTap:(UITapGestureRecognizer *)gesture
{
    UIActionSheet * actionsheet = [[UIActionSheet alloc] initWithTitle:nil delegate:self cancelButtonTitle:@"取消" destructiveButtonTitle:@"相册" otherButtonTitles:@"相机",@"编辑", nil];
    [actionsheet showInView:self.view];
}

-(void)actionSheet:(UIActionSheet *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex
{
    NSLog(@"%d",buttonIndex);
    if (!buttonIndex) {//相册
        [self presentAblumViewControllerWithAnimated:YES completion:nil];
    }
    else if(buttonIndex == 1)//相机
    {
        [self presentCameraViewControllerWithAnimated:YES completion:nil];
    }
    else if(buttonIndex == 2)//编辑
    {
        [self publishVPImageCropperViewControllerWithImage:self.img_profile.image];
        
    }
}

-(void)hb_imageCropperViewController:(UIViewController *)cropperViewController didFinished:(UIImage *)editedImage
{
    self.img_profile.image = editedImage;
}

-(void)hb_imagePickerController:(UIViewController *)imagePickerController didSelectAsset:(ALAsset *)asset
{
    UIImage * image = [UIImage imageWithCGImage:[[asset defaultRepresentation] fullScreenImage]];
    self.img_profile.image = image;
}

-(void)hb_imagePickerController:(UIViewController *)imagePickerController didSelectAssets:(NSArray *)assets
{
    
}
-(void)hb_imagePickerControllerDidCancel:(UIViewController *)imagePickerController
{
    
}
-(void)hb_imagePickerController:(UIViewController *)viewController cameraDidFinishPickingMediaWithImage:(UIImage *)image
{
//    self.img_profile.image = image;
    [self publishVPImageCropperViewControllerWithImage:image];
}

@end

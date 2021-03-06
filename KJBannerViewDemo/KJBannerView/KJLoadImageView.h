//
//  KJLoadImageView.h
//  iSchool
//
//  Created by 杨科军 on 2018/12/22.
//  Copyright © 2018 杨科军. All rights reserved.
//  https://github.com/yangKJ/KJBannerViewDemo
//  不依赖三方网络加载图片显示

#import <UIKit/UIKit.h>
#import "KJBannerTool.h"

/// 下载完成回调
typedef void (^KJDownLoadImageBlock)(UIImage *image);
/// 网络请求回调
typedef void (^KJDownLoadDataCallBack)(NSData *data, NSError *error);
/// 下载进度回调
typedef void (^KJDownloadProgressBlock)(unsigned long long total, unsigned long long current);

@interface KJLoadImageView : UIImageView
/// 下载完成回调
@property(nonatomic,copy,readwrite)KJDownLoadImageBlock kj_completionBlock;
/// 下载进度回调
@property(nonatomic,copy,readwrite)KJDownloadProgressBlock kj_progressBlock;

/// 指定URL下载图片失败时重试的次数，默认为2次
@property (nonatomic,assign)NSUInteger kj_failedTimes;
/// 是否裁剪为ImageView的尺寸，默认为NO
@property (nonatomic,assign)BOOL kj_isScale;

/// 使用这些方法下载图像异步
- (void)kj_setImageWithURLString:(NSString*)url Placeholder:(UIImage*)placeholderImage;
- (void)kj_setImageWithURLString:(NSString*)url Placeholder:(UIImage*)placeholderImage Completion:(void(^)(UIImage*image))completion;

/// 取消请求
- (void)kj_cancelRequest;
/// 清理掉本地缓存
+ (void)kj_clearImagesCache;
/// 获取图片缓存的占用的总大小/bytes
+ (unsigned long long)kj_imagesCacheSize;
/// 裁剪后的图片
+ (UIImage*)kj_clipImage:(UIImage*)image Size:(CGSize)size IsScaleToMax:(BOOL)isScaleToMax;

@end


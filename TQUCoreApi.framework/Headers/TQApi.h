//
//  TQApi.h
//  TQUCoreApi
//
//  Created by TQXD on 2021/5/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@protocol TQApiDelegate <NSObject>
@optional
/*
 返回得到登录的结果
 msgCode:为0授权成功
       为1授权失败
       
 data: 返回的信息(msgCode:为0 返回的是授权code  )
 
 state: 返回的信息(当msgCode:为0 才返回)
 */
- (void)onResp:(NSDictionary *)resp;
@end

@interface TQApi : NSObject

@property (nonatomic, weak) id<TQApiDelegate> delegate;

/*
  判断是否安装了ucodeApp
 */
+(BOOL)is_haveApp;
/*
 注册
 AppID：
 appSecret：
 UrlScheme： 自己的urlschemes
 Operating: 0:开发 1。测试 2.预发布 3.正式环境
 */
+(void)registerAppID:(NSString *)AppID appSecret:(NSString*)appSecret urlSchemes:(NSString *)urlSchemes Operating:(NSString *)Operating; 

/*
 - (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;

 写在AppDelegate里面
 */

+(void)handleOpenURL:(NSURL *)url delegate:(id)delegate;

/*
 发起登录请求
 */

-(void)sendReq;
/*
 
 返回得到登录的结果
 
 msgCode:为0授权成功
       为1授权失败
       
 
 data: 返回的信息(msgCode:为0 返回的是授权code  )
 
 state: 返回的信息(当msgCode:为0 才返回)
 
 */
@property (nonatomic,copy)void(^onRespBlock)(NSDictionary *RespDic);

@end

NS_ASSUME_NONNULL_END

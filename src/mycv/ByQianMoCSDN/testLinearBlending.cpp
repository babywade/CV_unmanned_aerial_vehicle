//-----------------------------------【程序说明】----------------------------------------------
//  程序名称:：【OpenCV入门教程之四】 ROI区域图像叠加&初级图像混合 全剖析   配套源码
// VS2010版   OpenCV版本：2.4.8
//     2014年3月10日 Create by 浅墨
//    图片素材出处：dota2原画 dota2logo
//     浅墨的微博：@浅墨_毛星云
//------------------------------------------------------------------------------------------------

//-----------------------------------【头文件包含部分】---------------------------------------
//     描述：包含程序所依赖的头文件
//----------------------------------------------------------------------------------------------
#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include <iostream>

//-----------------------------------【命名空间声明部分】---------------------------------------
//     描述：包含程序所使用的命名空间
//-----------------------------------------------------------------------------------------------
using namespace cv;
using namespace std;


//-----------------------------------【全局函数声明部分】--------------------------------------
//     描述：全局函数声明
//-----------------------------------------------------------------------------------------------
bool ROI_AddImage();
bool LinearBlending();
bool ROI_LinearBlending();

//-----------------------------------【main( )函数】--------------------------------------------
//     描述：控制台应用程序的入口函数，我们的程序从这里开始
//-----------------------------------------------------------------------------------------------
int test4(  )
{
       system("color 5E");

       if(ROI_AddImage()&& LinearBlending( )&&ROI_LinearBlending( ))
       {
              cout<<endl<<"嗯。好了，得出了你需要的图像~! : )";
       }

       cvWaitKey(0);
       return 0;
}

//----------------------------------【ROI_AddImage( )函数】----------------------------------
// 函数名：ROI_AddImage（）
//     描述：利用感兴趣区域ROI实现图像叠加
//----------------------------------------------------------------------------------------------
bool ROI_AddImage()
{

       //【1】读入图像
       Mat srcImage1= imread("dota_pa.jpg");
       Mat logoImage= imread("dota_logo.jpg");
       if(!srcImage1.data ) { printf("你妹，读取srcImage1错误~！ \n"); return false; }
       if(!logoImage.data ) { printf("你妹，读取logoImage错误~！ \n"); return false; }

       //【2】定义一个Mat类型并给其设定ROI区域
       Mat imageROI= srcImage1(Rect(200,250,logoImage.cols,logoImage.rows));

       //【3】加载掩模（必须是灰度图）
       Mat mask= imread("dota_logo.jpg",0);

       //【4】将掩膜拷贝到ROI
       logoImage.copyTo(imageROI,mask);

       //【5】显示结果
       namedWindow("<1>利用ROI实现图像叠加示例窗口");
       imshow("<1>利用ROI实现图像叠加示例窗口",srcImage1);

       return true;
}


//---------------------------------【LinearBlending（）函数】-------------------------------------
// 函数名：LinearBlending（）
// 描述：利用cv::addWeighted（）函数实现图像线性混合
//--------------------------------------------------------------------------------------------
bool LinearBlending()
{
       //【0】定义一些局部变量
       double alphaValue = 0.5;
       double betaValue;
       Mat srcImage2, srcImage3, dstImage;

       //【1】读取图像 ( 两幅图片需为同样的类型和尺寸 )
       srcImage2= imread("mogu.jpg");
       srcImage3= imread("rain.jpg");

       if(!srcImage2.data ) { printf("你妹，读取srcImage2错误~！ \n"); return false; }
       if(!srcImage3.data ) { printf("你妹，读取srcImage3错误~！ \n"); return false; }

       //【2】进行图像混合加权操作
       betaValue= ( 1.0 - alphaValue );
       addWeighted(srcImage2, alphaValue, srcImage3, betaValue, 0.0, dstImage);

       //【3】创建并显示原图窗口
       namedWindow("<2>线性混合示例窗口【原图】 by浅墨", 1);
       imshow("<2>线性混合示例窗口【原图】 by浅墨", srcImage2 );

       namedWindow("<3>线性混合示例窗口【效果图】 by浅墨", 1);
       imshow("<3>线性混合示例窗口【效果图】 by浅墨", dstImage );

       return true;

}

//---------------------------------【ROI_LinearBlending（）】-------------------------------------
// 函数名：ROI_LinearBlending（）
// 描述：线性混合实现函数,指定区域线性图像混合.利用cv::addWeighted（）函数结合定义
//                     感兴趣区域ROI，实现自定义区域的线性混合
//--------------------------------------------------------------------------------------------
bool ROI_LinearBlending()
{

       //【1】读取图像
       Mat srcImage4= imread("dota_pa.jpg",1);
       Mat logoImage= imread("dota_logo.jpg");

       if(!srcImage4.data ) { printf("你妹，读取srcImage4错误~！ \n"); return false; }
       if(!logoImage.data ) { printf("你妹，读取logoImage错误~！ \n"); return false; }

       //【2】定义一个Mat类型并给其设定ROI区域
       Mat imageROI;
              //方法一
       imageROI=srcImage4(Rect(200,250,logoImage.cols,logoImage.rows));
       //方法二
       //imageROI=srcImage4(Range(250,250+logoImage.rows),Range(200,200+logoImage.cols));

       //【3】将logo加到原图上
       addWeighted(imageROI,0.5,logoImage,0.3,0.,imageROI);

       //【4】显示结果
       namedWindow("<4>区域线性图像混合示例窗口 by浅墨");
       imshow("<4>区域线性图像混合示例窗口 by浅墨",srcImage4);

       return true;
}

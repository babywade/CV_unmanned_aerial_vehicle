/**********************************************************************************************************
*文件说明:
*        利用一个简单的例子说明三通道图片和单通道的含义
*开发环境:
*        win7+vs2010+opencv2.4.8
*时间地点:
*        陕西师范大学.2017.1.24
*作    者:
*        李丽
***********************************************************************************************************/
#include<iostream>
#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    //载入一张彩色图片并显示
    Mat srcImage=imread("dota.jpg",1);
    namedWindow("Image",WINDOW_AUTOSIZE);
    imshow("Image",srcImage);

    int nHeight=srcImage.rows;
    int nWidth=srcImage.cols;

    //载入一张灰度图并显示，这里使用同一张图片 只是imread函数的最后一个参数不一样  效果是相同的
    Mat grayImage=imread("dota.jpg",0);
    namedWindow("grayImage",WINDOW_AUTOSIZE);
    imshow("grayImage",grayImage);

    //基本信息
    cout<<"图像的高度"<<nHeight<<endl;
    cout<<"图像的宽度"<<nWidth<<endl;
    cout<<"Image的通道数"<<srcImage.channels()<<endl;      //彩色图片的通道数
    cout<<"grayImage的通道数"<<grayImage.channels()<<endl; //灰度图片的通道数

    for(int i=0;i<nHeight;i++)
    {
        for(int j=0;j<nWidth;j++)
        {
            srcImage.at<uchar>(i,j)=0;
            grayImage.at<uchar>(i,j)=0;
        }
    }
    namedWindow("彩色图片处理后对应黑色图片",WINDOW_AUTOSIZE);
    imshow("彩色图片处理后对应黑色图片",srcImage);

    namedWindow("灰度图片处理后对应黑色图片",WINDOW_AUTOSIZE);
    imshow("灰度图片处理后对应黑色图片",grayImage);

    cvWaitKey(0);
    cvDestroyWindow("Image");
    cvDestroyWindow("grayImage");
    cvDestroyWindow("彩色图片处理后对应黑色图片");
    cvDestroyWindow("灰度图片处理后对应黑色图片");

    return 0;

}

//-----------------------------------【头文件包含部分】---------------------------------------
//      描述：包含程序所依赖的头文件
//----------------------------------------------------------------------------------------------
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//-----------------------------------【命名空间声明部分】---------------------------------------
//      描述：包含程序所使用的命名空间
//-----------------------------------------------------------------------------------------------
using namespace cv;
//-----------------------------------【main( )函数】--------------------------------------------
//      描述：控制台应用程序的入口函数，我们的程序从这里开始
//-----------------------------------------------------------------------------------------------
int main( )
{
    //【1】载入原始图和Mat变量定义
    Mat srcImage = imread("Qiu.jpg");  //工程目录下应该有一张名为1.jpg的素材图
    Mat midImage,dstImage;//临时变量和目标图的定义

    //【2】显示原始图
    imshow("【原始图】", srcImage);

    //【3】转为灰度图，进行图像平滑
    cvtColor(srcImage,midImage, CV_BGR2GRAY);//转化边缘检测后的图为灰度图
    GaussianBlur( midImage, midImage, Size(9, 9), 2, 2 );

    //【4】进行霍夫圆变换
    std::vector<Vec3f> circles;
    HoughCircles( midImage, circles, CV_HOUGH_GRADIENT,1.5, 10, 200, 100, 0, 0 );

    //【5】依次在图中绘制出圆
    for( size_t i = 0; i < circles.size(); i++ )
    {
        Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);
        //绘制圆心
        circle( srcImage, center, 3, Scalar(0,255,0), -1, 8, 0 );
        //绘制圆轮廓
        circle( srcImage, center, radius, Scalar(155,50,255), 3, 8, 0 );
    }

    //【6】显示效果图
    imshow("【效果图】", srcImage);

    waitKey(0);

    return 0;
}

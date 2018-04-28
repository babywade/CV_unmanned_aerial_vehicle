#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    Mat CCD_srcImage = imread("C:\\Users\\babywade\\Documents\\红外图像\\110kV杜邦变电站20180123\\新建文件夹\\FLIR12047.jpg");
    Mat IR_srcImage = imread("C:\\Users\\babywade\\Documents\\红外图像\\110kV杜邦变电站20180123\\FLIR12046.jpg");
    Mat CCD_midImage, CCD_dstImage, IR_midImage, IR_dstImage;

    Canny(CCD_srcImage, CCD_midImage, 50, 200, 3);
    cvtColor(CCD_midImage, CCD_dstImage, CV_GRAY2BGR);

    vector<Vec4i> lines1;
    HoughLinesP(CCD_midImage, lines1, 1, CV_PI/180, 80, 50, 10);

    for(size_t i = 0; i < lines1.size(); i++) {
        Vec4i l = lines1[i];
        line(CCD_dstImage, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(186, 88, 255), 1, CV_AA);
    }

    namedWindow("【原始图】1", CV_WINDOW_NORMAL);
    imshow("【原始图】1", CCD_srcImage);
    namedWindow("【边缘检测后的图】1", CV_WINDOW_NORMAL);
    imshow("【边缘检测后的图】1", CCD_midImage);
    namedWindow("【效果图】1", CV_WINDOW_NORMAL);
    imshow("【效果图】1", CCD_dstImage);

    Canny(IR_srcImage, IR_midImage, 50, 200, 3);
    cvtColor(IR_midImage, IR_dstImage, CV_GRAY2BGR);

    vector<Vec4i> lines2;
    HoughLinesP(IR_midImage, lines2, 1, CV_PI/180, 80, 50, 10);

    for(size_t i = 0; i < lines2.size(); i++) {
        Vec4i l = lines2[i];
        line(IR_dstImage, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(186, 88, 255), 1, CV_AA);
    }

    imshow("【原始图】2", IR_srcImage);
    imshow("【边缘检测后的图】2", IR_midImage);
    imshow("【效果图】2", IR_dstImage);

    waitKey(0);

    return 0;
}

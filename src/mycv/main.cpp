#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    Mat CCD_srcImage = imread("C:\\Users\\babywade\\Documents\\����ͼ��\\110kV�Ű���վ20180123\\�½��ļ���\\FLIR12047.jpg");
    Mat IR_srcImage = imread("C:\\Users\\babywade\\Documents\\����ͼ��\\110kV�Ű���վ20180123\\FLIR12046.jpg");
    Mat CCD_midImage, CCD_dstImage, IR_midImage, IR_dstImage;

    Canny(CCD_srcImage, CCD_midImage, 50, 200, 3);
    cvtColor(CCD_midImage, CCD_dstImage, CV_GRAY2BGR);

    vector<Vec4i> lines1;
    HoughLinesP(CCD_midImage, lines1, 1, CV_PI/180, 80, 50, 10);

    for(size_t i = 0; i < lines1.size(); i++) {
        Vec4i l = lines1[i];
        line(CCD_dstImage, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(186, 88, 255), 1, CV_AA);
    }

    namedWindow("��ԭʼͼ��1", CV_WINDOW_NORMAL);
    imshow("��ԭʼͼ��1", CCD_srcImage);
    namedWindow("����Ե�����ͼ��1", CV_WINDOW_NORMAL);
    imshow("����Ե�����ͼ��1", CCD_midImage);
    namedWindow("��Ч��ͼ��1", CV_WINDOW_NORMAL);
    imshow("��Ч��ͼ��1", CCD_dstImage);

    Canny(IR_srcImage, IR_midImage, 50, 200, 3);
    cvtColor(IR_midImage, IR_dstImage, CV_GRAY2BGR);

    vector<Vec4i> lines2;
    HoughLinesP(IR_midImage, lines2, 1, CV_PI/180, 80, 50, 10);

    for(size_t i = 0; i < lines2.size(); i++) {
        Vec4i l = lines2[i];
        line(IR_dstImage, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(186, 88, 255), 1, CV_AA);
    }

    imshow("��ԭʼͼ��2", IR_srcImage);
    imshow("����Ե�����ͼ��2", IR_midImage);
    imshow("��Ч��ͼ��2", IR_dstImage);

    waitKey(0);

    return 0;
}

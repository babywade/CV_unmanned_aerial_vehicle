class CV_EXPORTS Mat
{
public:
    int flag;
    int dims;
    int rows, cols;
    uchar* data;
    int* refcount;
}//矩阵头
Mat M(3, 2, CV_8UC3, Scalar(0,0,255));
cout << "M = " << endl << " "<< M << endl;
Mat::Mat()
Mat::Mat(int rows, int cols, int type)
Mat::Mat(Size size, int type)
Mat::Mat(int rows, int cols, int type, const Scalar& s)
Mat::Mat(Size size, int type, const Scalar& s)
Mat::Mat(const Mat& m)
Mat::Mat(int rows, int cols, int type, void* data, size_t step=AUTO_STEP)
typedef Vec<uchar, 2> Vec2b;
typedef Vec<uchar, 3> Vec3b;
uchar value = grayim.at<uchar>(i,j);
grayim.at<uchar>(i,j) = 128;

#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int argc, char* argv[]) {
    Mat grayim(600, 800, CV_8UC1);
    Mat colorim(600, 800, CV_8UC3);

    for(int i = 0; i < grayim.rows; ++i) {
        for(int j = 0; j < grayim.cols; ++j) {
            grayim.at<uchar>(i,j) = (i+j)%255;
        }
    }

    for(int i = 0; i < colorim.rows; ++i) {
        for(int j = 0; j < colorim.cols; ++j) {
            Vec3b pixel;
            pixel[0] = i % 255;
            pixel[1] = i % 255;
            pixel[2] = 0;
            colorim.at<Vec3b>(i,j) = pixel;
        }
    }

    imshow("grayim", grayim);
    imshow("colorim", colorim);
    waitKey(0);

    return 0;
}

#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int argc, char* argv[]) {
    Mat grayim(600, 800, CV_8UC1);
    Mat colorim(600, 800, CV_8UC3);

    MatIterator_<uchar> grayit, grayend;
    for(grayit = grayim.begin<uchar>(), grayend = grayim.end<uchar>(); grayit != grayend; ++grayit) {
        *grayit = rand() % 255;
    }

    MatIterator_<Vec3b> colorit, colorend;
    for(colorit = colorim.begin<Vec3b>(), colorend = clorim.end<Vec3b>; colorit != colorend; ++colorit) {
        (*colorit)[0] = rand() % 255;
        (*colorit)[1] = rand() % 255;
        (*colorit)[2] = rand() % 255;
    }

    imshow("grayim", grayim);
    imshow("colorim", colorim);
    waitKey(0);

    return 0;
}

Mat Mat::row(int i) const
Mat Mat::col(int j) const

Mat line = A.row(i);
A.row(j) = A.row(i) * 2;
class Range {
public:
    int start, end;
};

Mat img(Size(320,240), CV_8UC3);
Mat roi(img, Rect(10,10,100,100));
Mat roi2 = img(Rect(10,10,100,100));
Mat roi3 = img(Range(10,100), Range(10,100));
Mat roi4(img, Range(10,100), Range(10,100));

Mat Mat::diag(int d) const
C = A + B + 1;

transposition
inversion
inv

#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int argc, char* argv[]) {
    Mat A = Mat::eye(4, 4, CV_32SC1);
    Mat B = A * 3 + 1;
    Mat C = B.diag(0) + B.col(1);

    cout << "A = " << A << endl << endl;
    cout << "B = " << B << endl << endl;
    cout << "C = " << C << endl << endl;
    cout << "C .* diag(B)" << C.dot(B.diag(0)) << endl;

    return 0;
}

template<typename _Tp> class Mat_ : public Mat {
    public:
};
//wrong example
Mat M(600, 800, CV_8UC1);
for(int i = 0; i < M.rows; ++i) {
    uchar *p = M.ptr<uchar>(i);
    for(int j = 0; j < M.cols; ++j) {
        double d1 = (double)((i + j) % 255);
        M.at<uchar>(i, j) = d1;
        double d2 = M.at<double>(i, j);
    }
}
//using Mat_ class
#include <iostream>
#include "opencv2/opencv.hpp"
#include <stdio.h>

using namespace std;
using namespace cv;

int main(int argc, char* argv[]) {
    Mat M(600, 800, CV_8UC1);

    for(int i = 0; i < M.rows; ++i) {
        uchar *p = M.ptr<uchar>(i);
        for(int j = 0; j < M.cols; ++j) {
            double 
        }
    }
}

void mycvOldFunc(IplImage *p, ...);
Mat img(Size(320, 240), CV_8UC3);
IplImage iplimg = img;
mycvOldFunc(&iplimg, ...);

Mat::Mat(const CvMat *m, bool copyData=false)
Mat::Mat(const IplImage *img, bool copyData=false)
//example
IplImage *iplimg = cvLoadImage("lena.jpg");
Mat im(iplimg, true);

Mat imread(const string& filename, int flags=1)
bool imwrite(const string& filename, InputArray image, const vector<int>& params=vector<int>())
Mat::convertTo() cvtColor()

#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int argc, char* argv[]) {
    Mat im = imread("lena.jpg", 0);
    if(im.empty()) {
        cout << "Can not load image." << endl;
        return -1;
    }

    Mat result;
    Canny(im, result, 50, 150);

    imwrite("lena-canny.png", result);

    return 0;
}

coder decoder codec
VideoCapture VideoWriter
VideoCapture::Open()
VideoCapture::Release()
VideoCapture::read()
VideoCapture::write()

#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    VideoCapture cap(0);

    VideoCapture cap("video.short.raw.avi");

    if(!cap.isOpened()) {
        cerr << "Can not open a camera or file." << endl;
        return -1;
    }

    Mat edges;
    namedWindow("edges", 1);
    for(;;) {
        Mat frame;
        cap >> frame;
        if(frame.empty()) {
            break;
        }

        cvtColor(frame, edges, CV_BGR2GRAY);
        Canny(edges, edges, 0, 30, 3);
        imshow("edges", edges);

        if(waitKey(30) >= 0) {
            break;
        }
        return 0;
    }
}

#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    Size s(320, 240);

    VideoWriter writer = VideoWriter("myvideo.avi", CV_FOURCC('M', 'J', 'P', 'G'), 25, s);

    if(!write.isOpened()) {
        cerr << "Can not create video file.\n" << endl;
        return -1;
    }

    Mat frame(s, CV_8UC3);

    for(int i = 0; i < 100; i++) {
        frame = Scalar::all(0);
        char text[128];
        snprintf(text, sizeof(text), "%d", i);

        putText(frame, text, Point(s.width/3, s.height/3), FONT_HERSHEY_SCRIPT_SIMPLEX, 3, Scalar(0,0,255), 3, 8);

        writer << frame;
    }
    return 0;
}
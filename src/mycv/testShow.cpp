#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


using namespace cv;


int test1()
{
    // ����һ��ͼƬ����Ϸԭ����
    Mat img=imread("test.jpg", 0);
    // ����һ����Ϊ "��Ϸԭ��"����
    namedWindow("��Ϸԭ��");
    // �ڴ�������ʾ��Ϸԭ��
    imshow("��Ϸԭ��",img);
    // �ȴ�6000 ms�󴰿��Զ��ر�
    waitKey(6000);
}

//-----------------------------------������˵����----------------------------------------------
//      ��������:������OpenCV���Ž̳�֮ʮ�ߡ�OpenCV��ӳ�� & SURF��������ϼ� �� ��������Դ�� ֮��SURF�������⡿
//      ��������IDE�汾��Visual Studio 2010
//      ��������OpenCV�汾��   2.4.9
//      2014��6��15�� Created by ǳī
//      ���ײ������ӣ� http://blog.csdn.net/poem_qianmo/article/details/30974513
//      PS:��������ϲ���ѧϰЧ������
//      ǳī��΢����@ǳī_ë���� http://weibo.com/1723155442
//      ǳī��֪����http://www.zhihu.com/people/mao-xing-yun
//      ǳī�Ķ��꣺http://www.douban.com/people/53426472/
//----------------------------------------------------------------------------------------------

//-----------------------------------��ͷ�ļ��������֡�---------------------------------------
//      ����������������������ͷ�ļ�
//----------------------------------------------------------------------------------------------
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/nonfree/nonfree.hpp"
#include <iostream>


//-----------------------------------�������ռ��������֡�--------------------------------------
//          ����������������ʹ�õ������ռ�
//-----------------------------------------------------------------------------------------------
using namespace cv;

//-----------------------------------��ȫ�ֺ����������֡�--------------------------------------
//          ������ȫ�ֺ���������
//-----------------------------------------------------------------------------------------------
static void ShowHelpText( );//�����������

//-----------------------------------��main( )������--------------------------------------------
//   ����������̨Ӧ�ó������ں��������ǵĳ�������￪ʼִ��
//-----------------------------------------------------------------------------------------------
int main( int argc, char** argv )
{
    //��0���ı�console������ɫ
    system("color 2F");

    //��0����ʾ��������
    ShowHelpText( );

    //��1������ԴͼƬ����ʾ
    Mat srcImage1 = imread("book1.jpg", 1 );
    Mat srcImage2 = imread("book2.jpg", 1 );
    if( !srcImage1.data || !srcImage2.data )//����Ƿ��ȡ�ɹ�
    { printf("��ȡͼƬ������ȷ��Ŀ¼���Ƿ���imread����ָ�����Ƶ�ͼƬ����~�� \n"); return false; }
    imshow("ԭʼͼ1",srcImage1);
    imshow("ԭʼͼ2",srcImage2);

    //��2��������Ҫ�õ��ı�������
    int minHessian = 400;//����SURF�е�hessian��ֵ������������
    SurfFeatureDetector detector( minHessian );//����һ��SurfFeatureDetector��SURF�� ������������
    std::vector<KeyPoint> keypoints_1, keypoints_2;//vectorģ�������ܹ�����������͵Ķ�̬���飬�ܹ����Ӻ�ѹ������

    //��3������detect��������SURF�����ؼ��㣬������vector������
    detector.detect( srcImage1, keypoints_1 );
    detector.detect( srcImage2, keypoints_2 );

    //��4�����������ؼ���
    Mat img_keypoints_1; Mat img_keypoints_2;
    drawKeypoints( srcImage1, keypoints_1, img_keypoints_1, Scalar::all(-1), DrawMatchesFlags::DEFAULT );
    drawKeypoints( srcImage2, keypoints_2, img_keypoints_2, Scalar::all(-1), DrawMatchesFlags::DEFAULT );

    //��5����ʾЧ��ͼ
    imshow("��������Ч��ͼ1", img_keypoints_1 );
    imshow("��������Ч��ͼ2", img_keypoints_2 );

    waitKey(0);
    return 0;
}


//-----------------------------------��ShowHelpText( )������----------------------------------
//          ���������һЩ������Ϣ
//----------------------------------------------------------------------------------------------
void ShowHelpText()
{
    //���һЩ������Ϣ
    printf("\n\n\n\t��ӭ������SURF�������⡿ʾ������~\n\n");
    printf("\t��ǰʹ�õ�OpenCV�汾Ϊ OpenCV "CV_VERSION);
    printf( "\n\n\t��������˵��: \n\n"
                "\t\t���̰��������- �˳�����\n\n"
                "\n\n\t\t\t\t\t\t\t\t byǳī\n\n\n");

}

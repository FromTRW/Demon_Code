#include <opencv2/opencv.hpp> 
using namespace cv;
int main()
{
	// ����һ��ͼƬ����Ϸԭ���� 
	Mat img = imread("C:/Users/DELL/Desktop/1.jpg");
	// ����һ����Ϊ "��Ϸԭ��"���� 
	namedWindow("��Ϸԭ��");
	// �ڴ�������ʾ��Ϸԭ�� 
	imshow("��Ϸԭ��", img);
	// �ȴ�6000 ms�󴰿��Զ��ر� 
	waitKey();
}
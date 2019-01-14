#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main() 
{
	Mat girl = imread("girl.jpg");
	namedWindow("��1������ͼ");
	imshow("girl", girl);

	Mat image = imread("dota.jpg");
	Mat logo = imread("dota_logo.jpg");
	namedWindow("��2��ԭ��ͼ");
	imshow("��2��ԭ��ͼ", image);

	namedWindow("��3��logoͼ");
	imshow("��2��logoͼ", logo);

	Mat imageROI;
	imageROI = image(Rect(800, 350, logo.cols, logo.rows));				//x,y����д��
    //imageROI = image(Rect(350,350+logo.rows),Rect(800+logo.cols)		//����д��

	//��logo�ӵ�ԭͼ��
	addWeighted(imageROI, 0.5, logo, 0.3, 0., imageROI);

	namedWindow("��4��ԭ��+logoͼ");
	imshow("��4��ԭ��+logoͼ", image);

	imwrite("��imwrite���ɵ�ͼƬ.jpg", image);


	waitKey();
	return 0;
}
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main() 
{
	Mat girl = imread("girl.jpg");
	namedWindow("【1】动漫图");
	imshow("girl", girl);

	Mat image = imread("dota.jpg");
	Mat logo = imread("dota_logo.jpg");
	namedWindow("【2】原画图");
	imshow("【2】原画图", image);

	namedWindow("【3】logo图");
	imshow("【2】logo图", logo);

	Mat imageROI;
	imageROI = image(Rect(800, 350, logo.cols, logo.rows));				//x,y坐标写法
    //imageROI = image(Rect(350,350+logo.rows),Rect(800+logo.cols)		//行列写法

	//将logo加到原图上
	addWeighted(imageROI, 0.5, logo, 0.3, 0., imageROI);

	namedWindow("【4】原画+logo图");
	imshow("【4】原画+logo图", image);

	imwrite("由imwrite生成的图片.jpg", image);


	waitKey();
	return 0;
}
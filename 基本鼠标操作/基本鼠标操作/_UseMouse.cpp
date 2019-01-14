//--------------------------------------������˵����-------------------------------------------
//		����˵������OpenCV3������š�OpenCV2���鱾����ʾ������18
//		����������HelloOpenCV
//		������������IDE�汾��Visual Studio 2010
//		������������OpenCV�汾��	3.0 beta
//		2014��11�� Created by @ǳī_ë����
//		2014��12�� Revised by @ǳī_ë����
//------------------------------------------------------------------------------------------------

//---------------------------------��ͷ�ļ��������ռ�������֡�-----------------------------
//		����������������ʹ�õ�ͷ�ļ��������ռ�
//-------------------------------------------------------------------------------------------------
#include <opencv2/opencv.hpp>
using namespace cv;

//-----------------------------------���궨�岿�֡�--------------------------------------------
//  ����������һЩ������ 
//------------------------------------------------------------------------------------------------ 
#define WINDOW_NAME "�����򴰿ڡ�"        //Ϊ���ڱ��ⶨ��ĺ� 


//-----------------------------------��ȫ�ֺ����������֡�------------------------------------
//		������ȫ�ֺ���������
//------------------------------------------------------------------------------------------------
void on_MouseHandle(int event, int x, int y, int flags, void* param);
void DrawRectangle(cv::Mat& img, cv::Rect box);
void ShowHelpText();

//-----------------------------------��ȫ�ֱ����������֡�-----------------------------------
//		������ȫ�ֱ���������
//-----------------------------------------------------------------------------------------------
Rect g_rectangle;
bool g_bDrawingBox = false;//�Ƿ���л���
RNG g_rng(12345);



//-----------------------------------��main( )������--------------------------------------------
//		����������̨Ӧ�ó������ں��������ǵĳ�������￪ʼִ��
//-------------------------------------------------------------------------------------------------
int main(int argc, char** argv)
{
	//��0���ı�console������ɫ
	system("color 9F");

	//��0����ʾ��ӭ�Ͱ�������
	ShowHelpText();

	//��1��׼������
	g_rectangle = Rect(-1, -1, 0, 0);
	Mat srcImage(600, 800, CV_8UC3), tempImage;
	srcImage.copyTo(tempImage);
	g_rectangle = Rect(-1, -1, 0, 0);
	srcImage = Scalar::all(0);

	//��2�������������ص�����
	namedWindow(WINDOW_NAME);
	setMouseCallback(WINDOW_NAME, on_MouseHandle, (void*)&srcImage);

	//��3��������ѭ���������л��Ƶı�ʶ��Ϊ��ʱ�����л���
	while (1)
	{
		srcImage.copyTo(tempImage);//����Դͼ����ʱ����
		if (g_bDrawingBox) DrawRectangle(tempImage, g_rectangle);//�����л��Ƶı�ʶ��Ϊ�棬����л���
		imshow(WINDOW_NAME, tempImage);
		if (waitKey(10) == 27) break;//����ESC���������˳�
	}
	return 0;
}



//--------------------------------��on_MouseHandle( )������-----------------------------
//		���������ص����������ݲ�ͬ������¼����в�ͬ�Ĳ���
//-----------------------------------------------------------------------------------------------
void on_MouseHandle(int event, int x, int y, int flags, void* param)
{

	Mat& image = *(cv::Mat*) param;
	switch (event)
	{
		//����ƶ���Ϣ
	case EVENT_MOUSEMOVE:
	{
		if (g_bDrawingBox)//����Ƿ���л��Ƶı�ʶ��Ϊ�棬���¼�³��Ϳ�RECT�ͱ�����
		{
			g_rectangle.width = x - g_rectangle.x;
			g_rectangle.height = y - g_rectangle.y;
		}
	}
	break;

	//���������Ϣ
	case EVENT_LBUTTONDOWN:
	{
		g_bDrawingBox = true;
		g_rectangle = Rect(x, y, 0, 0);//��¼��ʼ��
	}
	break;

	//���̧����Ϣ
	case EVENT_LBUTTONUP:
	{
		g_bDrawingBox = false;//�ñ�ʶ��Ϊfalse
							  //�Կ�͸�С��0�Ĵ���
		if (g_rectangle.width < 0)
		{
			g_rectangle.x += g_rectangle.width;
			g_rectangle.width *= -1;
		}

		if (g_rectangle.height < 0)
		{
			g_rectangle.y += g_rectangle.height;
			g_rectangle.height *= -1;
		}
		//���ú������л���
		DrawRectangle(image, g_rectangle);
	}
	break;

	}
}



//-----------------------------------��DrawRectangle( )������------------------------------
//		�������Զ���ľ��λ��ƺ���
//-----------------------------------------------------------------------------------------------
void DrawRectangle(cv::Mat& img, cv::Rect box)
{
	cv::rectangle(img, box.tl(), box.br(), cv::Scalar(g_rng.uniform(0, 255), g_rng.uniform(0, 255), g_rng.uniform(0, 255)));//�����ɫ
}


//-----------------------------------��ShowHelpText( )������-----------------------------
//          ���������һЩ������Ϣ
//----------------------------------------------------------------------------------------------
void ShowHelpText()
{
	//�����ӭ��Ϣ��OpenCV�汾
	printf("\n\n\t\t\t�ǳ���л����OpenCV3������š�һ�飡\n");
	printf("\n\n\t\t\t��Ϊ����OpenCV3��ĵ�18������ʾ������\n");
	printf("\n\n\t\t\t   ��ǰʹ�õ�OpenCV�汾Ϊ��" CV_VERSION);
	printf("\n\n  ----------------------------------------------------------------------------\n");
	//���һЩ������Ϣ
	printf("\n\n\n\t��ӭ��������꽻����ʾ��ʾ������\n");
	printf("\n\n\t���ڴ����е�����������϶��Ի��ƾ���\n");

}
//#include<iostream>  
//#include<string>  
//#include <limits>  
//
//using namespace std;
//
//int main()
//{
//	cout << "type: \t\t" << "************size**************" << endl;
//	cout << "bool: \t\t" << "��ռ�ֽ�����" << sizeof(bool);
//	cout << "\t���ֵ��" << (numeric_limits<bool>::max)();
//	cout << "\t\t��Сֵ��" << (numeric_limits<bool>::min)() << endl;
//	cout << "char: \t\t" << "��ռ�ֽ�����" << sizeof(char);
//	cout << "\t���ֵ��" << (numeric_limits<char>::max)();
//	cout << "\t\t��Сֵ��" << (numeric_limits<char>::min)() << endl;
//	cout << "signed char: \t" << "��ռ�ֽ�����" << sizeof(signed char);
//	cout << "\t���ֵ��" << (numeric_limits<signed char>::max)();
//	cout << "\t\t��Сֵ��" << (numeric_limits<signed char>::min)() << endl;
//	cout << "unsigned char: \t" << "��ռ�ֽ�����" << sizeof(unsigned char);
//	cout << "\t���ֵ��" << (numeric_limits<unsigned char>::max)();
//	cout << "\t\t��Сֵ��" << (numeric_limits<unsigned char>::min)() << endl;
//	cout << "wchar_t: \t" << "��ռ�ֽ�����" << sizeof(wchar_t);
//	cout << "\t���ֵ��" << (numeric_limits<wchar_t>::max)();
//	cout << "\t\t��Сֵ��" << (numeric_limits<wchar_t>::min)() << endl;
//	cout << "short: \t\t" << "��ռ�ֽ�����" << sizeof(short);
//	cout << "\t���ֵ��" << (numeric_limits<short>::max)();
//	cout << "\t\t��Сֵ��" << (numeric_limits<short>::min)() << endl;
//	cout << "int: \t\t" << "��ռ�ֽ�����" << sizeof(int);
//	cout << "\t���ֵ��" << (numeric_limits<int>::max)();
//	cout << "\t��Сֵ��" << (numeric_limits<int>::min)() << endl;
//	cout << "unsigned: \t" << "��ռ�ֽ�����" << sizeof(unsigned);
//	cout << "\t���ֵ��" << (numeric_limits<unsigned>::max)();
//	cout << "\t��Сֵ��" << (numeric_limits<unsigned>::min)() << endl;
//	cout << "long: \t\t" << "��ռ�ֽ�����" << sizeof(long);
//	cout << "\t���ֵ��" << (numeric_limits<long>::max)();
//	cout << "\t��Сֵ��" << (numeric_limits<long>::min)() << endl;
//	cout << "unsigned long: \t" << "��ռ�ֽ�����" << sizeof(unsigned long);
//	cout << "\t���ֵ��" << (numeric_limits<unsigned long>::max)();
//	cout << "\t��Сֵ��" << (numeric_limits<unsigned long>::min)() << endl;
//	cout << "double: \t" << "��ռ�ֽ�����" << sizeof(double);
//	cout << "\t���ֵ��" << (numeric_limits<double>::max)();
//	cout << "\t��Сֵ��" << (numeric_limits<double>::min)() << endl;
//	cout << "long double: \t" << "��ռ�ֽ�����" << sizeof(long double);
//	cout << "\t���ֵ��" << (numeric_limits<long double>::max)();
//	cout << "\t��Сֵ��" << (numeric_limits<long double>::min)() << endl;
//	cout << "float: \t\t" << "��ռ�ֽ�����" << sizeof(float);
//	cout << "\t���ֵ��" << (numeric_limits<float>::max)();
//	cout << "\t��Сֵ��" << (numeric_limits<float>::min)() << endl;
//	cout << "size_t: \t" << "��ռ�ֽ�����" << sizeof(size_t);
//	cout << "\t���ֵ��" << (numeric_limits<size_t>::max)();
//	cout << "\t��Сֵ��" << (numeric_limits<size_t>::min)() << endl;
//	cout << "string: \t" << "��ռ�ֽ�����" << sizeof(string) << endl;
//	// << "\t���ֵ��" << (numeric_limits<string>::max)() << "\t��Сֵ��" << (numeric_limits<string>::min)() << endl;  
//	cout << "type: \t\t" << "************size**************" << endl;
//	system("PAUSE ");
//	return 0;
//}
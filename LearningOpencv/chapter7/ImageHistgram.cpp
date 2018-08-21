#include "stdafx.h"
//#include "cv.h"
//#include "highgui.h"
//#include <iostream>
//
//using namespace cv;
//
//using namespace std;
//
//class Histogram1D
//{
//private:
//	int histSize[1]; // �������
//	float hranges[2]; // ͳ�����ص����ֵ����Сֵ
//	const float* ranges[1];
//	int channels[1]; // ������һ��ͨ��
//
//public:
//	Histogram1D()
//	{
//		// ׼��1Dֱ��ͼ�Ĳ���
//		histSize[0] = 256;
//		hranges[0] = 0.0f;
//		hranges[1] = 255.0f;
//		ranges[0] = hranges;
//		channels[0] = 0;
//	}
//
//	MatND getHistogram(const Mat &image)
//	{
//		MatND hist;
//		// ����ֱ��ͼ
//		calcHist(&image ,// Ҫ����ͼ���
//			1,                // ֻ����һ��ͼ���ֱ��ͼ
//			channels,        // ͨ������
//			Mat(),            // ��ʹ������
//			hist,            // ���ֱ��ͼ
//			1,                // 1Dֱ��ͼ
//			histSize,        // ͳ�ƵĻҶȵĸ���
//			ranges);        // �Ҷ�ֵ�ķ�Χ
//		return hist;
//	}
//
//	Mat getHistogramImage(const Mat &image)
//	{
//		MatND hist = getHistogram(image);
//
//		// ���ֵ����Сֵ
//		double maxVal = 0.0f;
//		double minVal = 0.0f;
//
//		minMaxLoc(hist, &minVal, &maxVal);
//
//		//��ʾֱ��ͼ��ͼ��
//		Mat histImg(histSize[0], histSize[0], CV_8U, Scalar(255));
//
//		// ������ߵ�Ϊnbins��90%
//		int hpt = static_cast<int>(0.9 * histSize[0]);
//		//ÿ����Ŀ����һ����ֱ��
//		for (int h = 0; h < histSize[0]; h++)
//		{
//			float binVal = hist.at<float>(h);
//			int intensity = static_cast<int>(binVal * hpt / maxVal);
//			// ����֮�����һ��ֱ��
//			line(histImg, Point(h, histSize[0]), Point(h, histSize[0] - intensity), Scalar::all(0));
//		}
//		return histImg;
//	}
//};
//
//
//int main()
//{
//
//	IplImage * image = cvLoadImage("fruits.jpg", CV_LOAD_IMAGE_GRAYSCALE);
//	Histogram1D hist;
//	Mat histImg;
//	/*histImg = hist.getHistogramImage("ImageHistgram.png");*/
//	histImg = hist.getHistogramImage(image);
//
//	/*imshow("Image", image);*/
//	imshow("Histogram", histImg);
//	return 0;
//}
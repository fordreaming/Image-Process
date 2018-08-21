//***************************************************************************************************
//ch7_Ex7_1
//***************************************************************************************************
#include "stdafx.h"

#include <cv.h>
#include <highgui.h>

int main( int argc, char** argv ) 
{

	IplImage* src;

	/*if( argc == 2 && (src=cvLoadImage(argv[1], 1))!= 0) */
	if((src=cvLoadImage("fruits.jpg", 1))!= 0) 
	{

		// Compute the HSV image, and decompose it into separate planes.
		//
		IplImage* hsv = cvCreateImage( cvGetSize(src), 8, 3 ); 
		cvCvtColor( src, hsv, CV_BGR2HSV );

		IplImage* h_plane  = cvCreateImage( cvGetSize(src), 8, 1 );
		IplImage* s_plane  = cvCreateImage( cvGetSize(src), 8, 1 );
		IplImage* v_plane  = cvCreateImage( cvGetSize(src), 8, 1 );
		IplImage* planes[] = { h_plane, s_plane };


		cvCvtPixToPlane( hsv, h_plane, s_plane, v_plane, 0 );

		// Build the histogram and compute its contents.
		//
		int h_bins = 30, s_bins = 32; 
		CvHistogram* hist;
		{
			int    hist_size[] = { h_bins, s_bins };
			float  h_ranges[]  = { 0, 180 };          // hue is [0,180]
			float  s_ranges[]  = { 0, 255 }; 
			float* ranges[]    = { h_ranges, s_ranges };
			hist = cvCreateHist( 
				2, 
				hist_size, 
				CV_HIST_ARRAY, 
				ranges, 
				1 
				); 
		}
		cvCalcHist( planes, hist, 0, 0 );

		// Create an image to use to visualize our histogram.
		//
		int scale = 10;
		IplImage* hist_img = cvCreateImage(  
			cvSize( h_bins * scale, s_bins * scale ), 
			8, 
			3
			); 
		cvZero( hist_img );

		// populate our visualization with little gray squares.
		//
		float max_value = 0;
		cvGetMinMaxHistValue( hist, 0, &max_value, 0, 0 );

		for( int h = 0; h < h_bins; h++ ) 
		{
			for( int s = 0; s < s_bins; s++ ) 
			{
				float bin_val = cvQueryHistValue_2D( hist, h, s );
				int intensity = cvRound( bin_val * 255 / max_value );
				cvRectangle( 
					hist_img, 
					cvPoint( h*scale, s*scale ),
					cvPoint( (h+1)*scale - 1, (s+1)*scale - 1),
					CV_RGB(intensity,intensity,intensity), 
					CV_FILLED
					);
			}
		}

		cvNamedWindow( "Source", 1 );
		cvShowImage(   "Source", src );

		cvNamedWindow( "H-S Histogram", 1 );
		cvShowImage(   "H-S Histogram", hist_img );

		cvWaitKey(0);
	}
}


//***************************************************************************************************
//ch7_prac7_1
//***************************************************************************************************
//#include "stdafx.h"
//#include "cv.h"
//#include "highgui.h"
////#include <IOSTREAM.H>
//#include <iostream>
//
////#pragma comment(lib,"cv.lib")
////#pragma comment(lib,"highgui.lib")
////#pragma comment(lib,"cxcore.lib")
//
//using namespace std;
//
//int main(int argc, char** argv)
//{
//	CvRNG rng;//���������Ŀ����Ϊ�˱�֤ÿ�����г���ʱ�õ������������
//	rng = cvRNG(cvGetTickCount());
//	IplImage* mat = cvCreateImage(cvSize(1,1000),IPL_DEPTH_32F,1);//����һ��1*1000��ͼ��ʵ�ʾ���һ��������
//
//
//	for (int i=0;i<1000;i++)
//	{
//		cvSet1D(mat,i,cvScalar(cvRandReal(&rng)));
//	}
//
//	int dims = 1;
//	int bins = 10; //ֻ��һά������ֻ��һ��bin����,Ҳ����ʹ��int size[] = {bins}����ʽ
//	//int size[] = {bins};
//
//	float range[] = {0,1};
//	float* rangs[] = {range}; //����ʹ����������ʽ����������һ���������������&range��cvCalcHist
//
//
//
//	CvHistogram* hist = cvCreateHist(dims,&bins,CV_HIST_ARRAY,rangs,1);
//	cvCalcHist(&mat,hist,0,0);
//
//	for (int j = 0; j < bins; j++)
//	{
//		double values = cvQueryHistValue_1D(hist,j);
//		cout<<"the bins of "<< j<<":"<<values<<endl;
//	}
//	return 1;
//
//
//}



//***************************************************************************************************
//ch7_prac7_2
//***************************************************************************************************

//#include "stdafx.h"
//#include "cv.h"
//#include "highgui.h"
//#include<stdio.h>
//#define binNum 2	//ÿһάbin�Ĵ�С
//void dspHistogram(CvHistogram* hist, char* windName);
//
//int main()
//{
//	IplImage* src1 = cvLoadImage("HandIndoorColor.jpg");
//	IplImage* src2 = cvLoadImage("HandOutdoorColor.jpg");
//	IplImage* src3 = cvLoadImage("HandOutdoorSunColor.jpg");
//	//�ֱ𴴽�3������ͼ���HSV�ռ�ͼ��Ԫ
//	IplImage* hsv_src1 = cvCreateImage(cvGetSize(src1), 8, 3);
//	IplImage* hsv_src2 = cvCreateImage(cvGetSize(src2), 8, 3);
//	IplImage* hsv_src3 = cvCreateImage(cvGetSize(src3), 8, 3);
//	cvZero(hsv_src1);
//	cvZero(hsv_src2);
//	cvZero(hsv_src3);
//
//	cvCvtColor(src1, hsv_src1, CV_BGR2HSV);
//	cvCvtColor(src2, hsv_src2, CV_BGR2HSV);
//	cvCvtColor(src3, hsv_src3, CV_BGR2HSV);
//
//	IplImage* h_plane1 = cvCreateImage(cvGetSize(src1), 8, 1);
//	IplImage* h_plane2 = cvCreateImage(cvGetSize(src2), 8, 1);
//	IplImage* h_plane3 = cvCreateImage(cvGetSize(src3), 8, 1);
//
//	IplImage* s_plane1 = cvCreateImage(cvGetSize(src1), 8, 1);
//	IplImage* s_plane2 = cvCreateImage(cvGetSize(src2), 8, 1);
//	IplImage* s_plane3 = cvCreateImage(cvGetSize(src3), 8, 1);
//
//	IplImage* v_plane1 = cvCreateImage(cvGetSize(src1), 8, 1);
//	IplImage* v_plane2 = cvCreateImage(cvGetSize(src2), 8, 1);
//	IplImage* v_plane3 = cvCreateImage(cvGetSize(src3), 8, 1);
//
//	IplImage* planes1[] = { h_plane1, s_plane1 };
//	IplImage* planes2[] = { h_plane2, s_plane2 };
//	IplImage* planes3[] = { h_plane3, s_plane3 };
//
//	cvCvtPixToPlane( hsv_src1, h_plane1, s_plane1, v_plane1, 0 );	
//	cvCvtPixToPlane( hsv_src2, h_plane2, s_plane2, v_plane2, 0 );	
//	cvCvtPixToPlane( hsv_src3, h_plane3, s_plane3, v_plane3, 0 );	
//
//	//create a histogram
//	int h_bins1 = binNum;
//	int h_bins2 = binNum;
//	int h_bins3 = binNum;
//
//	int s_bins1 = binNum;
//	int s_bins2 = binNum;
//	int s_bins3 = binNum;
//
//	CvHistogram* hist_1;
//	CvHistogram* hist_2;
//	CvHistogram* hist_3;
//	{
//		int hist_size1[] = { h_bins1, s_bins1 };
//		int hist_size2[] = { h_bins2, s_bins2 };
//		int hist_size3[] = { h_bins3, s_bins3 };
//
//		float h_ranges1[] = {0, 180};	
//		float h_ranges2[] = {0, 180};	
//		float h_ranges3[] = {0, 180};	
//
//		float s_ranges1[] = {0, 255};
//		float s_ranges2[] = {0, 255};
//		float s_ranges3[] = {0, 255};
//
//		float* ranges1[] = {h_ranges1, s_ranges1};
//		float* ranges2[] = {h_ranges2, s_ranges2};
//		float* ranges3[] = {h_ranges3, s_ranges3};
//
//		hist_1 = cvCreateHist(2, hist_size1, CV_HIST_ARRAY, ranges1, 1);
//		hist_2 = cvCreateHist(2, hist_size2, CV_HIST_ARRAY, ranges2, 1);
//		hist_3 = cvCreateHist(2, hist_size3, CV_HIST_ARRAY, ranges3, 1);
//	}
//
//	cvCalcHist(planes1, hist_1, 0, 0);	
//	cvCalcHist(planes2, hist_2, 0, 0);	
//	cvCalcHist(planes3, hist_3, 0, 0);	
//	//��һ��
//	cvNormalizeHist(hist_1, 1.0);	
//	cvNormalizeHist(hist_2, 1.0);	
//	cvNormalizeHist(hist_3, 1.0);
//
//	printf("Bins = %d\n\n", binNum);
//	//-----------------����ֱ��ͼƥ��------------------------
//	double dist_1_to_2[4] = { 0.0 };
//	double dist_1_to_3[4] = { 0.0 };
//	double dist_2_to_3[4] = { 0.0 };
//	int i=0;
//	//����ֱ��ͼƥ�䷽��
//	char* histMethod[4] = { "���", "����", "ֱ��ͼ�ཻ", "Bhattacharyya����" };
//	for(i = 0; i < 4; i ++)//���ν�����ء�������ֱ��ͼ�ཻ��Bhattacharyya�������,����ʾ���
//	{
//		dist_1_to_2[i] = cvCompareHist(hist_1, hist_2, i);
//		printf("ͼ��1����ͼ��2��ƥ������%lf <--- %s\n", dist_1_to_2[i], histMethod[i]);
//	}
//	printf("\n");
//	for( i = 0; i < 4; i ++)
//	{
//		dist_1_to_3[i] = cvCompareHist(hist_1, hist_3, i);
//		printf("ͼ��1����ͼ��3��ƥ������%lf <--- %s\n", dist_1_to_3[i], histMethod[i]);
//	}
//	printf("\n");
//	for( i = 0; i < 4; i ++)
//	{
//		dist_2_to_3[i] = cvCompareHist(hist_2, hist_3, i);
//		printf("ͼ��2����ͼ��3��ƥ������%lf <--- %s\n", dist_2_to_3[i], histMethod[i]);
//	}
//
//	//-----------------��ʾ����ƥ����-----------
//
//
//	dspHistogram(hist_1, "hist_1");
//	dspHistogram(hist_2, "hist_2");
//	dspHistogram(hist_3, "hist_3");
//	cvWaitKey();
//	cvReleaseImage(&src1);
//	cvReleaseHist(&hist_1);
//	cvDestroyAllWindows();
//	return 0;
//}//-----------------����ֱ��ͼ-----------------
////����: �ڴ�������ʾֱ��ͼ
////����1����Ҫ��ʾ��ֱ��ͼ
////����2����ʾ���ڵ�����
//void dspHistogram(CvHistogram* hist, char* windName)
//{
//	if( (!hist) || (!windName) )
//	{
//		exit(0);
//	}
//	int scale = 10;		//���ű���
//	int h_bins = hist->mat.dim[0].size;
//	int s_bins = hist->mat.dim[1].size; //��ȡ��bin�Ĵ�С
//	IplImage* histImage = cvCreateImage(cvSize(h_bins * scale, s_bins * scale), 8, 3);
//	cvZero(histImage);
//
//	//��ʾֱ��ͼ
//	float max_value = 0;
//	cvGetMinMaxHistValue(hist, 0, &max_value, 0, 0);
//	for(int h = 0; h < h_bins; h++)
//	{
//		for(int s = 0; s < s_bins; s++)
//		{
//			float bin_val = cvQueryHistValue_2D(hist, h, s);
//			int intensity = cvRound(bin_val * 255 / max_value);
//			cvRectangle
//				(
//				histImage, 
//				cvPoint(h * scale, s * scale), 
//				cvPoint( (h + 1) * scale - 1, (s + 1) * scale - 1), 
//				CV_RGB(intensity, intensity, intensity), CV_FILLED
//				);
//		}
//	}
//
//	cvNamedWindow(windName);
//	cvShowImage(windName, histImage);
//}


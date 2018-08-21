// OpenCvLearning.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

///* License:
//   Oct. 3, 2008
//   Right to use this code in any way you want without warrenty, support or any guarentee of it working.
//
//   BOOK: It would be nice if you cited it:
//   Learning OpenCV: Computer Vision with the OpenCV Library
//     by Gary Bradski and Adrian Kaehler
//     Published by O'Reilly Media, October 3, 2008
// 
//   AVAILABLE AT: 
//     http://www.amazon.com/Learning-OpenCV-Computer-Vision-Library/dp/0596516134
//     Or: http://oreilly.com/catalog/9780596516130/
//     ISBN-10: 0596516134 or: ISBN-13: 978-0596516130    
//
//   OTHER OPENCV SITES:
//   * The source code is on sourceforge at:
//     http://sourceforge.net/projects/opencvlibrary/
//   * The OpenCV wiki page (As of Oct 1, 2008 this is down for changing over servers, but should come back):
//     http://opencvlibrary.sourceforge.net/
//   * An active user group is at:
//     http://tech.groups.yahoo.com/group/OpenCV/
//   * The minutes of weekly OpenCV development meetings are at:
//     http://pr.willowgarage.com/wiki/OpenCV
//*/
//#include "highgui.h"
//
////int main( int argc, char** argv )
////{
////
////	char fileName[100] = "BlueCup.jpg";
////	/*IplImage* img = cvLoadImage( argv[1] );*/
////	IplImage* img = cvLoadImage( fileName );
////  cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE );
////  cvShowImage("Example1", img );
////  cvWaitKey(0);
////  cvReleaseImage( &img );
////  cvDestroyWindow("Example1");
////}
//
//
//int main( int argc, char** argv ) { 
//	cvNamedWindow( "Example2", CV_WINDOW_AUTOSIZE );
//	//CvCapture* capture = cvCaptureFromAVI( argv[1] ); // either one will work
//	/*CvCapture* capture = cvCreateFileCapture( argv[1] );*/
//	char videoAVI[100] = "test.avi";
//	CvCapture* capture = cvCreateFileCapture( videoAVI );
//	IplImage* frame;
//	while(1) {
//		frame = cvQueryFrame( capture );
//		if( !frame ) break;
//		cvShowImage( "Example2", frame );
//		char c = cvWaitKey(33);
//		if( c == 27 ) break;
//	}
//	cvReleaseCapture( &capture );
//	cvDestroyWindow( "Example2" );
//}



//ch2_ex2_3

//#include <stdio.h>
//#include <iostream>
//#include <fstream>
//#include "cv.h"
//#include "highgui.h"
///*
//OK, you caught us.  Video playback under linux is still just bad.  Part of this is due to FFMPEG, part of this
//is due to lack of standards in video files.  But the position slider here will often not work. We tried to at least
//find number of frames using the "getAVIFrames" hack below.  Terrible.  But, this file shows something of how to
//put a slider up and play with it.  Sorry.
//*/
//
//
//using namespace std;
//
//int        g_slider_position = 0;
//CvCapture* g_capture         = NULL;
//
//void onTrackbarSlide(int pos) {
//	cvSetCaptureProperty(
//		g_capture,
//		CV_CAP_PROP_POS_FRAMES,
//		pos
//		);
//}
//
////Hack because sometimes the number of frames in a video is not accessible. 
////Probably delete this on Widows
//int getAVIFrames(char * fname) { 
//	char tempSize[4];
//	// Trying to open the video file
//	ifstream  videoFile( fname , ios::in | ios::binary );
//	// Checking the availablity of the file
//	if ( !videoFile ) {
//		cout << "Couldn’t open the input file " << fname << endl;
//		exit( 1 );
//	}
//	// get the number of frames
//	videoFile.seekg( 0x30 , ios::beg );
//	videoFile.read( tempSize , 4 );
//	int frames = (unsigned char ) tempSize[0] + 0x100*(unsigned char ) tempSize[1] + 0x10000*(unsigned char ) tempSize[2] +    0x1000000*(unsigned char ) tempSize[3];
//	videoFile.close(  );
//	return frames;
//}
//
//
//int main( int argc, char** argv ) {
//	cvNamedWindow( "Example2_3", CV_WINDOW_AUTOSIZE );
//
//	char videoAVI[100] = "test.avi";
//	CvCapture* g_capture = cvCreateFileCapture( videoAVI );
//	/*g_capture = cvCreateFileCapture( argv[1] );*/
//	IplImage *foo = cvQueryFrame( g_capture);
//
//
//	int frames = (int) cvGetCaptureProperty(
//		g_capture,
//		CV_CAP_PROP_FRAME_COUNT
//		);
//
//	int tmpw = (int) cvGetCaptureProperty(
//		g_capture,
//		CV_CAP_PROP_FRAME_WIDTH
//		);
//
//	int tmph = (int) cvGetCaptureProperty(
//		g_capture,
//		CV_CAP_PROP_FRAME_HEIGHT
//		);
//
//	printf("opencv frames %d w %d h %d\n",frames,tmpw,tmph);
//
//	frames = getAVIFrames(videoAVI);
//	//frames = getAVIFrames(argv[1]); //This is a hack because on linux, getting number of frames often doesn't work
//
//	printf("hacked frames %d w %d h %d\n",frames,tmpw,tmph);
//
//	cvCreateTrackbar(
//		"Position",
//		"Example2_3",
//		&g_slider_position,
//		frames,
//		onTrackbarSlide
//		);
//	IplImage* frame;
//	frames = 0;
//	while(1) {
//		frame = cvQueryFrame( g_capture );
//		if( !frame ) /*break*/ frames = 0;
//		
//		//      int frames = cvGetCaptureProperty( g_capture, CV_CAP_PROP_POS_FRAMES);//This should work, sometimes it does not on linux
//		frames++; //My cheat
//		printf("\nFrame number=%d\n",frames);
//		cvSetTrackbarPos("Position","Example2_3",frames);
//		cvShowImage( "Example2_3", frame );
//		char c = (char)cvWaitKey(10);
//		if( c == 27 ) break;
//	}
//	cvReleaseCapture( &g_capture );
//	cvDestroyWindow( "Example2_3" );
//	return(0);
//}



////*************************************************************
////ch2_ex2_4
////*************************************************************
//
//
//#include "cv.h"
//#include "highgui.h"
//
//void example2_4( IplImage* image )
//{
//	// Create some windows to show the input
//	// and output images in.
//	//
//	cvNamedWindow( "Example2_4-in", CV_WINDOW_AUTOSIZE );
//	cvNamedWindow( "Example2_4-out", CV_WINDOW_AUTOSIZE );
//
//	// Create a window to show our input image
//	//
//	cvShowImage( "Example2_4-in", image );
//
//	// Create an image to hold the smoothed output
//	//
//	IplImage* out = cvCreateImage(
//		cvGetSize(image),
//		IPL_DEPTH_8U,
//		3
//		);
//
//	// Do the smoothing
//	//
//	cvSmooth( image, out, CV_GAUSSIAN, 5,5 );
//	cvSmooth( out, out, CV_GAUSSIAN, 5, 5);
//
//	// Show the smoothed image in the output window
//	//
//	cvShowImage( "Example2_4-out", out );
//
//	// Be tidy
//	//
//	cvReleaseImage( &out );
//
//	// Wait for the user to hit a key, then clean up the windows
//	//
//	cvWaitKey( 1); 
//	cvDestroyWindow("Example2_4-in" );
//	cvDestroyWindow("Example2_4-out" );
//
//}
//
//int main( int argc, char** argv )
//{
//	//IplImage* img = cvLoadImage( argv[1] );
//	char fileName[100] = "BlueCup.jpg";
//	IplImage* img = cvLoadImage( fileName );
//	cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE );
//	cvShowImage("Example1", img );
//	example2_4( img );
//	//  cvWaitKey(0);
//	cvReleaseImage( &img );
//	cvDestroyWindow("Example1");
//}


////*************************************************************
////ch2_ex2_5
////*************************************************************
//
//#include "cv.h"
//#include "highgui.h"
//
//IplImage* doPyrDown(
//					IplImage* in,
//					int       filter = IPL_GAUSSIAN_5x5)
//{
//
//	// Best to make sure input image is divisible by two.
//	//
//	assert( in->width%2 == 0 && in->height%2 == 0 );
//
//	IplImage* out = cvCreateImage( 
//		cvSize( in->width/2, in->height/2 ),
//		in->depth,
//		in->nChannels
//		);
//	cvPyrDown( in, out );
//	return( out );
//};
//
//int main( int argc, char** argv )
//{
//	/*IplImage* img = cvLoadImage( argv[1] );*/
//	IplImage* img = cvLoadImage("stuff.jpg", CV_LOAD_IMAGE_UNCHANGED);
//	IplImage* img2 = cvCreateImage( cvSize( img->width/2,img->height/2 ), img->depth, img->nChannels);
//	cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE );
//	cvNamedWindow("Example2", CV_WINDOW_AUTOSIZE );
//	cvShowImage("Example1", img );
//	img2 = doPyrDown( img );
//	cvShowImage("Example2", img2 );
//	cvWaitKey(0);
//	cvReleaseImage( &img );
//	cvReleaseImage( &img2 );
//	cvDestroyWindow("Example1");
//	cvDestroyWindow("Example2");
//}


////*************************************************************
////ch2_ex2_6
////*************************************************************
//
//#include "cv.h"
//#include "highgui.h"
//
//IplImage* doCanny(
//				  IplImage* in,
//				  double    lowThresh,
//				  double    highThresh,
//				  double    aperture)
//{
//	if (in->nChannels != 1)
//		return(0); // Canny only handles gray scale images
//	IplImage* out = cvCreateImage( 
//		cvGetSize( in ),
//		in->depth, //IPL_DEPTH_8U,    
//		1);
//	cvCanny( in, out, lowThresh, highThresh, aperture );
//	return( out );
//};
//
//int main( int argc, char** argv )
//{
//	//IplImage* img_rgb = cvLoadImage( argv[1] );
//	IplImage* img_rgb = cvLoadImage("stuff.jpg");
//	IplImage* img_gry = cvCreateImage( cvSize( img_rgb->width,img_rgb->height ), img_rgb->depth, 1);
//	cvCvtColor(img_rgb, img_gry ,CV_BGR2GRAY);
//	cvNamedWindow("Example Gray", CV_WINDOW_AUTOSIZE );
//	cvNamedWindow("Example Canny", CV_WINDOW_AUTOSIZE );
//	cvShowImage("Example Gray", img_gry );
//	IplImage* img_cny = doCanny( img_gry, 10, 100, 3 );
//	cvShowImage("Example Canny", img_cny );
//	cvWaitKey(0);
//	cvReleaseImage( &img_rgb);
//	cvReleaseImage( &img_gry);
//	cvReleaseImage( &img_cny);
//	cvDestroyWindow("Example Gray");
//	cvDestroyWindow("Example Canny");
//}



////*************************************************************
////ch2_ex2_7
////*************************************************************
//
//
//#include "cv.h"
//#include "highgui.h"
//
//IplImage* doCanny(
//				  IplImage* in,
//				  double    lowThresh,
//				  double    highThresh,
//				  double    aperture)
//{
//	IplImage* out = cvCreateImage( 
//		cvGetSize( in ),
//		in->depth, //IPL_DEPTH_8U,    
//		1);
//	cvCanny( in, out, lowThresh, highThresh, aperture );
//	return( out );
//};
//
//IplImage* doPyrDown(
//					IplImage* in,
//					int       filter = IPL_GAUSSIAN_5x5)
//{
//
//	// Best to make sure input image is divisible by two.
//	//
//	assert( in->width%2 == 0 && in->height%2 == 0 );
//
//	IplImage* out = cvCreateImage( 
//		cvSize( in->width/2, in->height/2 ),
//		in->depth,
//		in->nChannels
//		);
//	cvPyrDown( in, out );
//	return( out );
//};
//
//int main( int argc, char** argv )
//{
//	/*IplImage* img_rgb  = cvLoadImage( argv[1] );*/
//	IplImage* img_rgb = cvLoadImage("stuff.jpg");
//	IplImage* img_gry  = cvCreateImage( cvSize( img_rgb->width,img_rgb->height ), img_rgb->depth, 1);
//	cvCvtColor(img_rgb, img_gry ,CV_BGR2GRAY);
//	IplImage* img_pyr  = doPyrDown( img_gry, IPL_GAUSSIAN_5x5 );
//	IplImage* img_pyr2 = doPyrDown( img_pyr, IPL_GAUSSIAN_5x5 );
//	IplImage* img_cny  = doCanny( img_pyr2, 10, 100, 3 );
//
//	cvNamedWindow("Example Gray", CV_WINDOW_AUTOSIZE );
//	cvNamedWindow("Example Pyr", CV_WINDOW_AUTOSIZE );
//	cvNamedWindow("Example Canny", CV_WINDOW_AUTOSIZE );
//	cvShowImage("Example Gray", img_gry );
//	cvShowImage("Example Pyr", img_pyr2 );
//	cvShowImage("Example Canny", img_cny );
//	cvWaitKey(0);
//	cvReleaseImage( &img_rgb);
//	cvReleaseImage( &img_gry);
//	cvReleaseImage( &img_pyr);
//	cvReleaseImage( &img_pyr2);
//	cvReleaseImage( &img_cny);
//	cvDestroyWindow("Example Gray");
//	cvDestroyWindow("Example Pyr");
//	cvDestroyWindow("Example Canny");
//}



////*************************************************************
////ch2_ex2_8
////*************************************************************
//
//
//#include "cv.h"
//#include "highgui.h"
//
//IplImage* doCanny(
//				  IplImage* in,
//				  double    lowThresh,
//				  double    highThresh,
//				  double    aperture)
//{
//	IplImage* out = cvCreateImage( 
//		cvGetSize( in ),
//		in->depth, //IPL_DEPTH_8U,    
//		1);
//	cvCanny( in, out, lowThresh, highThresh, aperture );
//	return( out );
//};
//
//IplImage* doPyrDown(
//					IplImage* in,
//					int       filter = IPL_GAUSSIAN_5x5)
//{
//
//	// Best to make sure input image is divisible by two.
//	//
//	assert( in->width%2 == 0 && in->height%2 == 0 );
//
//	IplImage* out = cvCreateImage( 
//		cvSize( in->width/2, in->height/2 ),
//		in->depth,
//		in->nChannels
//		);
//	cvPyrDown( in, out );
//	return( out );
//};
//
//int main( int argc, char** argv )
//{
//	cvNamedWindow("Example Gray", CV_WINDOW_AUTOSIZE );
//	cvNamedWindow("Example Pyr", CV_WINDOW_AUTOSIZE );
//	cvNamedWindow("Example Canny", CV_WINDOW_AUTOSIZE );
//	/*IplImage* img_rgb = cvLoadImage( argv[1] );*/
//	IplImage* img_rgb = cvLoadImage("stuff.jpg");
//	IplImage* out;
//
//	out = cvCreateImage( cvSize( img_rgb->width,img_rgb->height ), img_rgb->depth, 1);
//	cvCvtColor(img_rgb, out ,CV_BGR2GRAY);
//	cvShowImage("Example Gray", out );
//	out = doPyrDown( out );
//	out = doPyrDown( out );
//	cvShowImage("Example Pyr", out );
//	out = doCanny( out, 10, 100, 3 );
//	cvShowImage("Example Canny", out );
//
//	cvWaitKey(0);
//	cvReleaseImage( &out);
//	cvDestroyWindow("Example Gray");
//	cvDestroyWindow("Example Pyr");
//	cvDestroyWindow("Example Canny");
//}


////*************************************************************
////ch2_ex2_9
////*************************************************************
//
//#include "cv.h"
//#include "highgui.h"
//
//int main( int argc, char** argv )
//{ 
//	cvNamedWindow( "Example2_9", CV_WINDOW_AUTOSIZE );
//	CvCapture* capture;
//	if (argc==1) {
//		capture = cvCreateCameraCapture( 0 );
//	} else {
//		capture = cvCreateFileCapture( argv[1] );
//	}
//	assert( capture != NULL );
//
//	IplImage* frame;
//	while(1) {
//		frame = cvQueryFrame( capture );//下一帧视频文件载入内存
//		if( !frame ) break;
//		cvShowImage( "Example2_9", frame );
//		char c = cvWaitKey(10);
//		if( c == 27 ) break;
//	}
//	cvReleaseCapture( &capture );
//	cvDestroyWindow( "Example2_9" );
//}



////*************************************************************
////ch2_ex2_10
////*************************************************************

//#include "cv.h"
//#include "highgui.h"
//#include <stdio.h>
//
//// Convert a video to grayscale
//// argv[1]: input video file
//// argv[2]: name of new output file
////
//
////#define NOWRITE 1;   //Turn this on (removed the first comment out "//" if you can't write on linux
//
//int main( int argc, char* argv[] ) 
//{
//	cvNamedWindow( "Example2_10", CV_WINDOW_AUTOSIZE );
//	cvNamedWindow( "Log_Polar", CV_WINDOW_AUTOSIZE );
//	/*CvCapture* capture = cvCreateFileCapture( argv[1] );*/
//	char videoAVI[100] = "test.avi";
//	CvCapture* capture = cvCreateFileCapture(videoAVI);
//	if (!capture)
//	{
//		return -1;
//	}
//	IplImage* bgr_frame;
//	double fps = cvGetCaptureProperty (
//		capture,
//		CV_CAP_PROP_FPS
//		);
//	printf("fps=%d\n",(int)fps);
//
//	CvSize size = cvSize(
//		(int)cvGetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH),
//		(int)cvGetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT)
//		);
//
//	printf("frame (w, h) = (%d, %d)\n",size.width,size.height);
//#ifndef NOWRITE
//	CvVideoWriter* writer = cvCreateVideoWriter(  // On linux Will only work if you've installed ffmpeg development files correctly, 
//		argv[2],                               // otherwise segmentation fault.  Windows probably better.
//		CV_FOURCC('D','X','5','0'),    
//		fps,
//		size
//		);
//#endif
//	IplImage* logpolar_frame = cvCreateImage(
//		size,
//		IPL_DEPTH_8U,
//		3
//		);
//
//	IplImage* gray_frame = cvCreateImage(
//		size,
//		IPL_DEPTH_8U,
//		1
//		);
//
//	while( (bgr_frame=cvQueryFrame(capture)) != NULL ) 
//	{
//		cvShowImage( "Example2_10", bgr_frame );
//		cvConvertImage(   //We never make use of this gray image
//			bgr_frame,
//			gray_frame,
//			CV_RGB2GRAY
//			);
//		cvLogPolar( bgr_frame, logpolar_frame,  //This is just a fun conversion the mimic's the human visual system
//			cvPoint2D32f(bgr_frame->width/2,
//			bgr_frame->height/2), 
//			40, 
//			CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS );
//		cvShowImage( "Log_Polar", logpolar_frame );
//		//Sigh, on linux, depending on your ffmpeg, this often won't work ...
//#ifndef NOWRITE
//		cvWriteToAVI( writer, logpolar_frame );
//#endif
//		char c = cvWaitKey(10);
//		if( c == 27 ) break;
//	}
//#ifndef NOWRITE
//	cvReleaseVideoWriter( &writer );
//#endif
//	cvReleaseImage( &gray_frame );
//	cvReleaseImage( &logpolar_frame );
//	cvReleaseCapture( &capture );
//}




////*************************************************************
////ch3_ex3_3
////*************************************************************

//#include "cv.h"
//#include <stdio.h>
//
//int main()
//{
//	// Create an OpenCV Matrix containing some fixed data.
//	//
//	float vals[] = { 0.866025, -0.500000, 0.500000, 0.866025};
//
//	CvMat rotmat;
//
//	cvInitMatHeader(
//		&rotmat,
//		2,
//		3, 
//		CV_32FC1,
//		vals
//		);
//	printf("Ex 3_3 matrix initialized\n");
//}


////*************************************************************
////ch3_ex3_4
////*************************************************************

//#include "cv.h"
//#include <stdio.h>
//
//int main()
//{
//	CvMat* mat = cvCreateMat( 5, 5, CV_32FC1 );
//	float element_3_2 = CV_MAT_ELEM( *mat, float, 3, 2 );
//	printf("Exercise 3_4, matrix created and accessed [3,2]=%f\n",element_3_2);
//}



////*************************************************************
////ch3_ex3_5
////*************************************************************
//#include "cv.h"
//#include <stdio.h>
//
//int main()
//{
//	CvMat* mat = cvCreateMat( 5, 5, CV_32FC1 );
//	float element_3_2 = 7.7;
//	*( (float*)CV_MAT_ELEM_PTR( *mat, 3, 2 ) ) = element_3_2;
//
//	// below from example ch3_ex3_8.txt
//	cvmSet( mat, 2, 2, 0.5000 );
//	cvSetReal2D( mat, 3, 3, 0.3300 );
//
//
//	printf("Exercise 3_5, matrix created and accessed [3,2]=%f, [2,2]=%f, [3,3]=%f\n",CV_MAT_ELEM( *mat, float, 3, 2 ),CV_MAT_ELEM( *mat, float, 2, 2 ),CV_MAT_ELEM( *mat, float, 3, 3 ));
//
//
//}



////*************************************************************
////ch3_ex3_9
////*************************************************************
//#include <stdio.h>
//#include <cv.h>
//#include <highgui.h>
//
//float sum( CvMat* mat ) {
//	float s = 0.0f;
//	for( int row=0; row<mat->height; row++ ) {
//		float* ptr = mat->data.fl + row * mat->step/4;
//		for( int col=0; col<mat->width; col++ ) {
//			s += *ptr++;
//		}
//	}
//	return( s );
//};
//
//int main(int argc, char** argv)
//{
//	CvMat *mat = cvCreateMat(5,5,CV_32FC1);
//	float element_3_2 = 7.7;
//	*((float*)CV_MAT_ELEM_PTR( *mat, 3,2) ) = element_3_2;
//	cvmSet(mat,4,4,0.5000);
//	cvSetReal2D(mat,3,3,0.5000);
//	float s = sum(mat);
//	printf("%f\n",s);
//	return 0;
//}



////*************************************************************
////ch3_ex3_11
////*************************************************************


//#include <stdio.h>
//#include <cv.h>
//#include <highgui.h>
//
//void saturate_sv( IplImage* img ) 
//{
//
//	for( int y=0; y<img->height; y++ ) {
//		uchar* ptr = (uchar*) (
//			img->imageData + y * img->widthStep 
//			);
//		for( int x=0; x<img->width; x++ ) 
//		{
//			ptr[3*x+1] = 255;
//			ptr[3*x+2] = 255;
//		}
//	}
//}
//
//int main( int argc, char** argv )
//{
//	IplImage* img = cvLoadImage( "stuff.jpg");
//	cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE );
//	saturate_sv(img);
//	cvShowImage("Example1", img );
//	cvWaitKey(0);
//	cvReleaseImage( &img );
//	cvDestroyWindow("Example1");
//}


////*************************************************************
////ch3_ex3_12
////*************************************************************

//#include <cv.h>
//#include <highgui.h>
//// ch3_ex3_12 image_name x y width height add# 
//int main(int argc, char** argv)
//{
//
//	IplImage* src;
//	cvNamedWindow("Example3_12_pre", CV_WINDOW_AUTOSIZE);
//	cvNamedWindow("Example3_12_post", CV_WINDOW_AUTOSIZE); 
//
//	if((src=cvLoadImage("stuff.jpg",1)) != 0 )
//	{
//		int x = 20;
//		int y = 30;
//		int width = 50;
//		int height = 50;
//		int add = 100;
//		cvShowImage( "Example3_12_pre", src);
//		cvSetImageROI(src, cvRect(x,y,width,height));
//		cvAddS(src, cvScalar(add),src);
//		cvResetImageROI(src);
//		cvShowImage( "Example3_12_post",src);
//		cvWaitKey();
//	}
//	cvReleaseImage( &src );
//	cvDestroyWindow("Example3_12_pre");
//	cvDestroyWindow("Example3_12_post");   
//	return 0;
//}






////************************************************************************************************
////ch3_ex3_12
////************************************************************************************************

//#include <cv.h>
//#include <highgui.h>
//
//// ch3_ex3_13 image_name x y width height add# 
//
//int main(int argc, char** argv)
//{
//	IplImage* interest_img;
//	CvRect interest_rect;
//	//if( argc == 7 && ((interest_img=cvLoadImage(argv[1],1)) != 0 ))
//	if((interest_img=cvLoadImage("stuff.jpg", 1)) != 0 )
//	{
//		interest_rect.x = 100;
//		interest_rect.y = 100;
//		interest_rect.width = 200;
//		interest_rect.height = 100;
//		int add = 200;
//
//		// Assuming IplImage *interest_img; and 
//		//  CvRect interest_rect;
//		//  Use widthStep to get a region of interest
//		//
//		// (Alternate method)
//		//
//		IplImage *sub_img = cvCreateImageHeader(
//			cvSize(
//			interest_rect.width, 
//			interest_rect.height
//			),
//			interest_img->depth, 
//			interest_img->nChannels
//			);
//
//		sub_img->origin = interest_img->origin;
//
//		sub_img->widthStep = interest_img->widthStep;
//
//		sub_img->imageData = interest_img->imageData + 
//			interest_rect.y * interest_img->widthStep  +
//			interest_rect.x * interest_img->nChannels;
//
//		cvAddS( sub_img, cvScalar(add, add), sub_img );
//
//		cvReleaseImageHeader(&sub_img);
//
//		cvNamedWindow( "Roi_Add", CV_WINDOW_AUTOSIZE );
//		cvShowImage( "Roi_Add", interest_img );
//		cvWaitKey();
//	}
//	return 0;
//}


////*******************************************************************************************
////ch3_ex3_14
////*******************************************************************************************



//#include <cv.h>
//#include <highgui.h>
//#include <stdio.h>
//
//int main(int argc, char** argv)
//{
//	IplImage *src1, *src2;
//	//if( argc == 9 && ((src1=cvLoadImage(argv[1],1)) != 0 
//	//	)&&((src2=cvLoadImage(argv[2],1)) != 0 ))
//
//
//	if(((src1=cvLoadImage("test.jpg",1)) != 0 
//		)&&((src2=cvLoadImage("fruits.jpg",1)) != 0 ))
//	{
//		int x = 100;
//		int y = 100;
//		int width = 200;
//		int height = 100;
//		double alpha = (double)0;
//		double beta  = (double)1;
//		cvSetImageROI(src1, cvRect(x,y,width,height));
//		cvSetImageROI(src2, cvRect(0,0,width,height));
//		cvAddWeighted(src1, alpha, src2, beta,0.0,src1);
//		cvResetImageROI(src1);
//		cvNamedWindow( "Alpha_blend", 1 );
//		cvShowImage( "Alpha_blend", src1 );
//		cvWaitKey();
//	}
//	else 
//		printf("Couldn't load one or both of %s, %s\n");
//	return 0;
//}


////*******************************************************************************************
////ch3_ex3_15
////*******************************************************************************************


//#include <cv.h>
//#include <highgui.h>
//#include <stdio.h>
//
//int main(int argc, char** argv)
//{
//	CvMat *the_matrix_data = cvCreateMat(5,5,CV_32FC1);
//	float element_3_2 = 7.7;
//	*((float*)CV_MAT_ELEM_PTR( *the_matrix_data, 3,2) ) = element_3_2;
//	cvmSet(the_matrix_data,4,4,0.5000);
//	cvSetReal2D(the_matrix_data,3,3,0.5000);
//
//	CvMat A = cvMat( 5, 5, CV_32F, the_matrix_data );
//
//	printf("Example 3_15:\nSaving my_matrix.xml\n");
//	cvSave( "my_matrix.xml", &A );
//	//. . .
//	// to load it then in some other program use …
//	printf("Loading my_matrix.xml\n");
//	CvMat* A1 = (CvMat*) cvLoad( "my_matrix.xml" );
//}




////*************************************************************
////ch3_ex3_20
////*************************************************************

//#include <stdio.h>
//#include <cv.h>
//#include <highgui.h>
//
//int main(int argc, char** argv)
//{
//	const char* libraries;
//	const char* modules;
//	cvGetModuleInfo( 0, &libraries, &modules );
//	printf("Libraries: %s\nModules: %s\n", libraries, modules );
//}



////*************************************************************
////ch3_prac3_2
////*************************************************************

//#include "cv.h"
//#include "highgui.h"
//#include <stdio.h>
//#include <cv.h>
//#include <highgui.h>
//
//
//int main()
//{
//	//创建一个三通道二维矩阵，字节类型，大小100*100
//	CvMat * mat = cvCreateMat(100, 100, CV_8UC3);
//	//所有数值置0
//	cvZero(mat);
//
//	//CvPoint cirPoint = cvPoint(50, 50);	//圆心
//	//int radius = 40;//半径
//	//CvScalar cirColor = cvScalar(255, 0,0 );//蓝色
//	//cvCircle(mat, cirPoint, radius, cirColor);	//画圆
//
//
//	
//	CvPoint center = cvPoint(50, 50);
//	CvScalar colorCircle = cvScalar(256, 256, 256, 0);
//	//画一个圆
//	cvCircle(mat, center, 40, colorCircle);
//
//	cvNamedWindow("Exam302");
//	cvShowImage("Exam302", (IplImage*)mat);
//
//	cvWaitKey(0);
//	cvReleaseMat(&mat);
//	cvDestroyWindow("Exam302");
//	return 0;
//
//}


////*************************************************************
////ch3_prac3_3
////*************************************************************

//#include <stdio.h>
//#include <cv.h>
//#include <highgui.h>
//
//int main()
//{
//	CvMat *mat = cvCreateMat(100, 100, CV_8UC3);
//	cvZero(mat);
//
//	//cvRectangle(mat, cvPoint(20, 5), cvPoint(40, 20), cvScalar(0, 255, 0));
//	//调用cvPtr2D()
//
//	uchar * leftTopptr = cvPtr2D(mat, 20, 5);
//	uchar * leftBottom = leftTopptr + 4500;
//	uchar * rightTopper = leftTopptr + 57;
//
//	//绘制水平线
//	for (int i = 20-20; i < 40-20; i++)
//	{
//	
//		leftTopptr[3*i+1] = 255;
//		leftBottom[3*i+1] = 255;
//
//	}
//
//	//绘制竖直线
//	for (int i = 5-5; i < 20 - 5; i++)
//	{
//		leftTopptr   [300*i + 1] = 255;
//		rightTopper  [300*i + 1] = 255;
//	}
//
//	//

//方法二：
//////uchar * leftTopptr = cvPtr2D(mat, 20, 5);
//////
////////绘制矩形
//////for (int i = 20-20; i < 40-20; i++)
//////{
//////
//////	for (int j = 5-5; j < 20-5; j++)
//////	{
//////		if(j == 0 || j == 14)
//////		{
//////			leftTopptr[3*i+1+ j*300] = 255;
//////		}
//////		else
//////		{
//////			if (i == 0 || i == 19)
//////			{
//////				leftTopptr[3*i+1+ j*300] = 255;
//////			}
//////		}
//////	}
//////}
//
//	
//	
//	cvNamedWindow("Exam303_Rectangle");
//	cvShowImage("Exam303_Rectangle", mat);
//	cvWaitKey(0);
//
//	cvReleaseMat(&mat);
//	cvDestroyWindow("Exam303_Rectangle");
//	return 0;
//}



////*************************************************************
////ch3_prac3_4
////*************************************************************


//#include <stdio.h>
//#include <cv.h>
//#include <highgui.h>
//
//int main()
//{
//	CvMat *mat = cvCreateMat(100, 100, CV_8UC3);
//	cvZero(mat);
//
//	//cvRectangle(mat, cvPoint(20, 5), cvPoint(40, 20), cvScalar(0, 255, 0));
//	//调用cvPtr2D()
//
//	uchar * leftTopptr = cvPtr2D(mat, 20, 5);
//
//	//绘制矩形
//	for (int i = 20-20; i < 40-20; i++)
//	{
//
//		for (int j = 5-5; j < 20-5; j++)
//		{
//
//			leftTopptr[3*i+1+ j*300] = 255;
//		}
//	}
//
//	cvNamedWindow("Exam303_Rectangle");
//	cvShowImage("Exam303_Rectangle", mat);
//	cvWaitKey(0);
//
//	cvReleaseMat(&mat);
//	cvDestroyWindow("Exam303_Rectangle");
//	return 0;
//}



////*************************************************************
////ch3_prac3_5
////*************************************************************
//#include "cv.h"
//#include "highgui.h"
//
//int main()
//{
//	IplImage* single_img = cvCreateImage(cvSize(210, 210), 8, 1);//210*210 单通道
//	cvZero(single_img);
//
//	int Width		= 210	, Height = 210;
//	int maxPixel	= 200	;
//	int value		= 0	 	;
//	int i, j;
//	for(i = 0, j = 0; i <= Width, j <= Height;)
//	{
//		//	for(i = 0; i <= Width;)
//		//	{
//		cvSetImageROI(single_img, cvRect(i, j, Width - 2*i, Height - 2*j));	//set the ROI of the single_img
//		//	cvSetImageROI(single_img, cvRect(0, 0, Width, Height));
//		cvSet(single_img, cvScalar(value, 0, 0));
//
//		value += 20;
//		cvResetImageROI(single_img);
//		//	}
//		i += 10;//边界都为10个像素宽度
//		j += 10;
//		if(value == maxPixel)//超过最大像素值200时，退出
//		{
//			break;
//		}
//	}
//
//	cvNamedWindow("ROI", 0);
//	cvShowImage("ROI", single_img);
//
//	cvWaitKey(0);
//	cvDestroyWindow("ROI");
//	cvReleaseImage(&single_img);
//
//	return 0;
//}



//#include <cv.h>
//#include <highgui.h>
//#include <stdio.h>
//int main(int argc, char** argv)
//{
//	IplImage *img;
//	img = cvCreateImage(cvSize(210,210),IPL_DEPTH_8U,1);
//	cvZero(img);
//	int interset_x = 0;
//	int interset_y = 0;
//	int offset_x = img->width;
//	int offset_y = img->height;
//	int add = 0;
//	int res =0;
//	BOOL condition = TRUE;
//	while(add<200)
//	{
//		cvSetImageROI(img,cvRect(interset_x,interset_y,offset_x,offset_y));
//		//if (condition)
//		//{
//		//	cvSet(img,cvScalar(0));
//		//	condition = FALSE;
//		//}
//		//else
//		//{
//		cvSet(img,cvScalar(add));
//		condition = TRUE;
//		//}  
//		cvResetImageROI(img);
//		add = add+20;
//		interset_x = interset_x +10;
//		interset_y = interset_y +10;
//		offset_x = offset_x -20;
//		offset_y = offset_y -20;
//
//	}
//
//	cvNamedWindow( "Source", CV_WINDOW_AUTOSIZE );
//	cvShowImage( "Source", img );
//	cvWaitKey();
//	return 0;
//}




//*************************************************************
//ch3_prac3_6
//*************************************************************
//#include <cv.h>
//#include <highgui.h>
//#include <stdio.h>
//int main(int argc, char** argv)
//{
//	IplImage *img;
//	
//	img = cvLoadImage("lena.bmp");
//	IplImage* dst1 = cvCreateImageHeader(cvSize(20,30),img->depth,img->nChannels);
//	IplImage* dst2 = cvCreateImageHeader(cvSize(20,30),img->depth,img->nChannels);
//	dst1->origin = img->origin;
//	dst2->origin = img->origin;
//	dst1->widthStep = img->widthStep;
//	dst2->widthStep = img->widthStep;
//	dst1->imageData = img->imageData+10*img->widthStep+5*img->nChannels;
//	dst2->imageData = img->imageData+60*img->widthStep+50*img->nChannels;
//	cvNot(dst1,dst1);
//	cvNot(dst2,dst2);
//
//	cvNamedWindow( "Source", CV_WINDOW_AUTOSIZE );
//	cvShowImage( "Source", img );
//	cvWaitKey();
//	cvReleaseImageHeader(&dst1);
//	cvReleaseImageHeader(&dst2);
//	return 0;
//}



//*************************************************************
//ch3_prac3_7
//*************************************************************
//#include <cv.h>
//#include <highgui.h>
//#include <stdio.h>
//int main(int argc, char** argv)
//{
//	IplImage *img;
//	IplImage *clone1,*clone2;
//	img = cvLoadImage("lena.bmp",CV_LOAD_IMAGE_UNCHANGED);
//	IplImage* dst = cvCreateImage(cvGetSize(img),img->depth,1);
//	cvSplit( img, 0, dst, 0, 0 );
//	clone1 = cvCloneImage(dst);
//	clone2 = cvCloneImage(dst);
//	double max,min;
//	cvMinMaxLoc(dst,&min,&max);
//	double thresh = (max-min)/2;
//	cvSet(clone1,cvScalar(thresh));
//	cvZero(clone2);
//	cvCmp(dst,clone1,clone2,CV_CMP_GE);
//	cvSubS(dst,cvScalar(thresh/2),dst,clone2);
//	cvNamedWindow( "Source", CV_WINDOW_AUTOSIZE );
//	cvShowImage( "Source", dst );
//	cvWaitKey();
//	cvReleaseImage(&dst);
//
//	return 0;
//}



//*************************************************************
//ch3_prac3_8
//*************************************************************
//#include <cv.h>
//#include <highgui.h>
//#include <stdio.h>
//
//
//struct my_struct{
//	int Value;
//	CvPoint point;
//	CvRect rect;
//};
//
//void write_my_struct(CvFileStorage* fs,const char* name,my_struct* ms)
//{
//	cvWriteInt(fs,name,ms->Value);
//	cvStartWriteStruct(fs,name,CV_NODE_SEQ);
//	cvWriteInt(fs,0,ms->point.x);
//	cvWriteInt(fs,0,ms->point.y);
//	cvEndWriteStruct(fs);
//	cvStartWriteStruct(fs,name,CV_NODE_SEQ);
//	cvWriteInt(fs,0,ms->rect.x);
//	cvWriteInt(fs,0,ms->rect.y);
//	cvWriteInt(fs,0,ms->rect.width);
//	cvWriteInt(fs,0,ms->rect.height);
//	cvEndWriteStruct(fs);
//
//}
//void read_my_struct(CvFileStorage* fs,CvFileNode* ms_node,my_struct* ms)
//{
//	int value = cvReadIntByName(fs,0,"Value",5);
//	CvSeq* s = cvGetFileNodeByName(fs,0,"point")->data.seq;
//	int point_x = cvReadInt((CvFileNode*)cvGetSeqElem(s,0));
//	int point_y = cvReadInt((CvFileNode*)cvGetSeqElem(s,1));
//}
//int main(int argc, char** argv)
//{
//	CvFileStorage* fs = cvOpenFileStorage(
//		"cfg.xml",
//		0,
//		CV_STORAGE_WRITE
//		);
//	my_struct ms = {10,cvPoint(10,20),cvRect(0,0,20,50)};
//	write_my_struct(fs,"struct",&ms);
//	cvReleaseFileStorage(&fs);
//
//	return 0;
//}



//*************************************************************
//ch4_Ex4_1
//*************************************************************


//#include <cv.h>
//#include <highgui.h>
//
//// Define our callback which we will install for
//// mouse events.
////
//void my_mouse_callback(
//					   int event, int x, int y, int flags, void* param 
//					   );
//
//CvRect box;
//bool drawing_box = false;
//
//// A litte subroutine to draw a box onto an image
////
//void draw_box( IplImage* img, CvRect rect ) {
//	cvRectangle (
//		img, 
//		cvPoint(box.x,box.y),
//		cvPoint(box.x+box.width,box.y+box.height),
//		cvScalar(0xff,0x00,0x00)    /* red */
//		);
//}
//
//int main( int argc, char* argv[] ) 
//{
//
//	box = cvRect(-1,-1,0,0);
//
//	IplImage* image = cvCreateImage( 
//		cvSize(200,200),
//		IPL_DEPTH_8U,
//		3
//		);
//	cvZero( image );
//	IplImage* temp = cvCloneImage( image );
//
//	cvNamedWindow( "Box Example" );
//
//	// Here is the crucial moment that we actually install
//	// the callback.  Note that we set the value ‘param’ to
//	// be the image we are working with so that the callback
//	// will have the image to edit.
//	//
//	cvSetMouseCallback( 
//		"Box Example", 
//		my_mouse_callback, 
//		(void*) image 
//		);
//
//	// The main program loop.  Here we copy the working image
//	// to the ‘temp’ image, and if the user is drawing, then
//	// put the currently contemplated box onto that temp image.
//	// display the temp image, and wait 15ms for a keystroke,
//	// then repeat…
//	//
//	while( 1 ) {
//
//		cvCopyImage( image, temp );
//		if( drawing_box ) draw_box( temp, box ); 
//		cvShowImage( "Box Example", temp );
//
//		if( cvWaitKey( 15 )==27 ) break;
//	}
//
//	// Be tidy
//	//
//	cvReleaseImage( &image );
//	cvReleaseImage( &temp );
//	cvDestroyWindow( "Box Example" );
//}
//
//// This is our mouse callback.  If the user
//// presses the left button, we start a box.
//// when the user releases that button, then we
//// add the box to the current image.  When the
//// mouse is dragged (with the button down) we 
//// resize the box.
////
//void my_mouse_callback(
//					   int event, int x, int y, int flags, void* param )
//{
//
//	IplImage* image = (IplImage*) param;
//
//	switch( event ) 
//	{
//	case CV_EVENT_MOUSEMOVE: 
//		{
//			if( drawing_box ) 
//			{
//			box.width  = x-box.x;
//			box.height = y-box.y;
//			}
//							 
//		}				
//		break;
//	case CV_EVENT_LBUTTONDOWN: 
//		{
//			drawing_box = true;
//			box = cvRect( x, y, 0, 0 );
//		}   
//		break;
//	case CV_EVENT_LBUTTONUP: 
//		{
//		drawing_box = false; 
//		if( box.width<0  ) 
//		{ 
//			box.x+=box.width;  
//			box.width *=-1; 
//		}
//		if( box.height<0 ) 
//		{ 
//			box.y+=box.height; 
//			box.height*=-1; 
//		}
//		draw_box( image, box );
//							 
//		}				 
//		break;   
//	}
//}



//*************************************************************
//ch4_Ex4_2
//*************************************************************


//#include <cv.h>
//#include <highgui.h>
//
//int g_switch_value = 1;
//
//void switch_off_function() 
//{
//	printf("Pause\n");
//}; //YOU COULD DO SOMETHING WITH THESE FUNCTIONS TOO
//void switch_on_function() 
//{
//	printf("Run\n");
//}; 
//
////
//// This will be the callback that we give to the
//// trackbar.
////
//void switch_callback( int position ) {
//	if( position == 0 ) {
//		switch_off_function();
//	} else {
//		switch_on_function();
//	}
//}
//
////OK, OK, I ADDED READING A MOVIE AND USING THE "BUTTON" TO STOP AND GO
//int main( int argc, char* argv[] ) {
//	IplImage *frame; //To hold movie images
//	CvCapture* g_capture         = NULL;
//
//	char CaptureName[100] = "test.avi";
//	if(!(g_capture = cvCreateFileCapture( CaptureName )))
//		printf("Failed to Open!");
//
//	// Name the main window
//	//
//	cvNamedWindow( "Example4_2", 1 );
//
//	// Create the trackbar.  We give it a name,
//	// and tell it the name of the parent window.
//	//
//	cvCreateTrackbar(
//		"Switch",
//		"Example4_2",
//		&g_switch_value,
//		1,
//		switch_callback
//		);
//
//	// This will just cause OpenCV to idle until 
//	// someone hits the "Escape" key.
//	//
//	while( 1 ) {
//		if(g_switch_value)
//		{
//			frame = cvQueryFrame( g_capture );
//			if( !frame ) break;
//		}
//		cvShowImage( "Example4_2", frame);
//		if(cvWaitKey(10)==27 ) break;
//	}
//
//	//CLEAN UP
//	cvReleaseCapture( &g_capture );
//	cvDestroyWindow( "Example4_2" );
//	return(0);
//
//}



//*************************************************************
//ch4_Ex4_3
//*************************************************************

//#include <cv.h>
//#include <highgui.h>
//#include <stdio.h>
//
//int main(int argc, char** argv)
//{
//	//Adding something to open a video so that we can read its properties ...
//	IplImage *frame; //To hold movie images
//	CvCapture* capture         = NULL;
//	char CaptureName[100] = "test.avi";
//	if(!(capture = cvCreateFileCapture( CaptureName )))
//	{
//		printf("Failed to open %s\n");
//		return -1;
//	}
//	//Read the properties
//	double f = cvGetCaptureProperty(
//		capture,
//		CV_CAP_PROP_FOURCC
//		);
//	char* fourcc = (char*) (&f);
//	printf("Properties of %s are:\n",argv[1]);
//	printf("FORCC = %d | %d | %d | %d |\n",fourcc[0],fourcc[1],fourcc[2],fourcc[3]);
//	cvReleaseCapture( &capture );
//	return 0;
//}



//*************************************************************
//ch4_prac4_1_a
//*************************************************************


//#include <cv.h>
//#include <highgui.h>
//#include <stdio.h>
//
//
//
//
////Canny边缘检测算法
//IplImage* doCanny(
//				  IplImage* in,
//				  double lowThresh,
//				  double highThresh,
//				  double aperture
//				  )
//{
//	  if(in->nChannels != 1)
//		  return 0;
//	  IplImage* out = cvCreateImage(
//		  cvGetSize(in),
//		  IPL_DEPTH_8U,
//		  1);
//
//	  //边缘检测
//	  cvCanny(in,out,lowThresh,highThresh,aperture);
//	  return out;
//}
//
//
//int main()
//{
//	IplImage *frame; 
//	CvCapture* capture         = NULL;
//	
//	
//	//读入视频
//	char CaptureName[100] = "test.avi";
//	if(!(capture = cvCreateFileCapture( CaptureName )))
//	{
//		printf("Failed to open %s\n");
//		return -1;
//	}
//
//
//	//
//	//定义三个窗口
//	//
//	cvNamedWindow("window");
//	cvNamedWindow("window_gray");
//	cvNamedWindow("window_canny");
//	//
//	//捕获视频的宽度和高度
//	int capture_width =(int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);
//	int capture_height =(int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);
//
//	//捕获视频的大小
//	CvSize capture_size = cvSize(capture_width, capture_height);
//
//	//创建图像
//	IplImage * frame_gray = cvCreateImage(capture_size, IPL_DEPTH_8U, 1);
//	IplImage * frame_canny = cvCreateImage(capture_size, IPL_DEPTH_8U, 1);
//
//
//	while(1)
//	{
//		//读视频帧
//		frame = cvQueryFrame(capture);
//		if(!frame)
//		{
//			break;
//		}
//
//		//灰度图像
//		cvCvtColor(frame,frame_gray,CV_RGB2GRAY);
//
//		//边缘检测
//		frame_canny = doCanny(frame_gray,10,100,3);
//
//
//		cvShowImage("window",frame);
//		cvShowImage("window_gray",frame_gray);
//		cvShowImage("window_Canny",frame_canny);
//
//		if(cvWaitKey(100) == 27){//每秒显示30帧
//			break;
//		}
//	}
//	cvReleaseCapture(&capture);
//	cvDestroyWindow("window");
//	cvDestroyWindow("window_gray");
//	cvDestroyWindow("window_Canny");
//
//
//	return 0;
//}



//*************************************************************
//ch4_prac4_1_b
//ch4_prac4_1_b目前想到的方法有三种
//ch4_prac4_1_b_1:直接采用指针将三帧图像的数据复制到frame_all之中；
//ch4_prac4_1_b_2:打算采用RoI进行处理，暂时还没解决；
//ch4_prac4_1_b_3:采用文件头进行处理；

//*************************************************************




//*************************************************************
//ch4_prac4_1_b_1  直接采用指针将三帧图像的数据复制到frame_all之中；
//*************************************************************

//#include <cv.h>
//#include <highgui.h>
//#include <stdio.h>
//
////Canny边缘检测算法
//IplImage* doCanny(
//				  IplImage* in,
//				  double lowThresh,
//				  double highThresh,
//				  double aperture
//				  )
//{
//	  if(in->nChannels != 1)
//		  return 0;
//	  IplImage* out = cvCreateImage(
//		  cvGetSize(in),
//		  IPL_DEPTH_8U,
//		  1);
//	  cvCanny(in,out,lowThresh,highThresh,aperture);
//	  return out;
//}
//
//
//int main()
//{
//	
//	IplImage *frame; 
//	CvCapture* capture         = NULL;//视频的每一帧
//	char CaptureName[100] = "test.avi";
//
//	if(!(capture = cvCreateFileCapture( CaptureName )))
//	{
//		printf("Failed to open %s\n");
//		return -1;
//	}
//
//	frame = cvQueryFrame(capture);//读帧视频
//
//	
//	//
//	//
//	cvNamedWindow("window");
//	cvNamedWindow("window_gray");
//	cvNamedWindow("window_cnany");
//
//	//显示三幅图像的窗口
//	cvNamedWindow("window_all");
//	//
//	//抓取视频图像的宽和高
//	int capture_width =(int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);
//	int capture_height =(int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);
//	int capture_widthStep = frame->widthStep;
//	
//
//	//图像大小
//	CvSize capture_size = cvSize(capture_width, capture_height);
//
//	//单通道灰度图像
//	IplImage * frame_gray_1channle = cvCreateImage(capture_size, IPL_DEPTH_8U, 1);
//	//3通道灰度图像
//	IplImage * frame_gray_3channels = cvCreateImage(capture_size, IPL_DEPTH_8U, 3);
//	//单通道canny边缘检测图像
//	IplImage * frame_canny_1channel = cvCreateImage(capture_size, IPL_DEPTH_8U, 1);
//	//3通道canny边缘检测图像
//	IplImage * frame_canny_3channels = cvCreateImage(capture_size, IPL_DEPTH_8U, 3);
//
//
//	//3张图像一起显示
//	CvSize frame_all_size = cvSize(3*capture_width, capture_height);
//	IplImage * frame_all = cvCreateImage(frame_all_size, IPL_DEPTH_8U, 3);
//
//
//	cvZero(frame_all);
//
//	
//	while(1)
//	{
//		frame = cvQueryFrame(capture);
//		if(!frame)
//		{
//			return 1;
//		}
//		//将彩色图像转化为灰色图像
//		cvCvtColor(frame,frame_gray_1channle,CV_RGB2GRAY);
//		cvCvtColor(frame_gray_1channle,frame_gray_3channels,CV_GRAY2BGR);
//		frame_canny_1channel = doCanny(frame_gray_1channle,10,100,3);
//		cvCvtColor(frame_canny_1channel,frame_canny_3channels,CV_GRAY2BGR);
//
//
//		//复制数据
//		for(int i = 0; i < capture_width; i++)
//		{
//			for (int j = 0; j < capture_height; j++)
//			{
//				//复制frame图像
//				frame_all->imageData[3*j*3*capture_width + 3*i] = frame->imageData[j*3*capture_width + 3*i];
//				frame_all->imageData[3*j*3*capture_width + 3*i+1] = frame->imageData[j*3*capture_width + 3*i+1];
//				frame_all->imageData[3*j*3*capture_width + 3*i+2] = frame->imageData[j*3*capture_width + 3*i+2];
//
//
//
//				//复制frame_gray_3channels图像
//				frame_all->imageData[(3*j+1)*3*capture_width+ 3*i] = frame_gray_3channels->imageData[j*3*capture_width + 3*i];
//				frame_all->imageData[(3*j+1)*3*capture_width+ 3*i+1] = frame_gray_3channels->imageData[j*3*capture_width + 3*i+1];
//				frame_all->imageData[(3*j+1)*3*capture_width + 3*i+2] = frame_gray_3channels->imageData[j*3*capture_width + 3*i+2];
//
//				
//				//复制frame_canny_3channels图像
//				frame_all->imageData[(3*j+2)*3*capture_width+ 3*i] = frame_canny_3channels->imageData[j*3*capture_width + 3*i];
//				frame_all->imageData[(3*j+2)*3*capture_width+ 3*i+1] = frame_canny_3channels->imageData[j*3*capture_width + 3*i+1];
//				frame_all->imageData[(3*j+2)*3*capture_width + 3*i+2] = frame_canny_3channels->imageData[j*3*capture_width + 3*i+2];
//
//			}
//		}
//
//		CvFont textfont = cvFont(10.0,1);
//		cvInitFont(&textfont, CV_FONT_HERSHEY_SIMPLEX, 0.5f, 0.5f, 0, 1);
//		cvPutText(frame_all, "Frame", cvPoint(10,20), &textfont, cvScalar(0,0,255));
//		cvPutText(frame_all, "Frame_Gray", cvPoint(capture_width+10,20), &textfont, cvScalar(255,0,0));
//		cvPutText(frame_all, "Frame_Canny", cvPoint(capture_width*2+10, 20), &textfont, cvScalar(0,255,0));
//
//		cvShowImage("window_all",frame_all);
//
//		if(cvWaitKey(1000) == 27){//每秒显示30帧
//			break;
//		}
//	}
//	cvReleaseImage(&frame);
//	cvReleaseImage(&frame_gray_1channle);
//	cvReleaseImage(&frame_gray_3channels);
//	cvReleaseImage(&frame_canny_1channel);
//	cvReleaseImage(&frame_canny_3channels);
//	cvReleaseImage(&frame_all);
//	cvReleaseCapture(&capture);
//	cvDestroyWindow("window_all");
//
//	return 0;
//
//}




//*************************************************************
//ch4_prac4_1_b_2
//创建图像头指向frame_all的第一幅/第二幅/第三幅图像
//通过widthStep进行处理
//调用cvAdd()
//*************************************************************

//#include <cv.h>
//#include <highgui.h>
//#include <stdio.h>
//
////Canny边缘检测算法
//IplImage* doCanny(
//				  IplImage* in,
//				  double lowThresh,
//				  double highThresh,
//				  double aperture
//				  )
//{
//	  if(in->nChannels != 1)
//		  return 0;
//	  IplImage* out = cvCreateImage(
//		  cvGetSize(in),
//		  IPL_DEPTH_8U,
//		  1);
//	  cvCanny(in,out,lowThresh,highThresh,aperture);
//	  return out;
//}
//
//
//int main()
//{
//	
//	IplImage *frame; 
//	CvCapture* capture         = NULL;//视频的每一帧
//	char CaptureName[100] = "test.avi";
//
//	if(!(capture = cvCreateFileCapture( CaptureName )))
//	{
//		printf("Failed to open %s\n");
//		return -1;
//	}
//
//	frame = cvQueryFrame(capture);//读帧视频
//
//	
//	//
//	//
//	cvNamedWindow("window");
//	cvNamedWindow("window_gray");
//	cvNamedWindow("window_cnany");
//
//	//三个画面放在一个窗口进行显示
//	cvNamedWindow("window_all");
//	//
//	//抓取视频图像的宽和高
//	int capture_width =(int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);
//	int capture_height =(int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);
//	int capture_widthStep = frame->widthStep;
//	
//
//	//图像大小
//	CvSize capture_size = cvSize(capture_width, capture_height);
//	CvSize capture_size_2 = cvSize(capture_width, capture_height);
//	CvSize capture_size_3 = cvSize(capture_width, capture_height);
//
//	//单通道灰度图像
//	IplImage * frame_gray_1channle = cvCreateImage(capture_size, IPL_DEPTH_8U, 1);
//	//3通道灰度图像
//	IplImage * frame_gray_3channels = cvCreateImage(capture_size, IPL_DEPTH_8U, 3);
//
//
//	//单通道canny边缘检测图像
//	IplImage * frame_canny_1channel = cvCreateImage(capture_size, IPL_DEPTH_8U, 1);
//	//3通道canny边缘检测图像
//	IplImage * frame_canny_3channels = cvCreateImage(capture_size, IPL_DEPTH_8U, 3);
//
//
//	//3张图像一起显示
//	CvSize frame_all_size = cvSize(3*capture_width, capture_height);
//	IplImage * frame_all = cvCreateImage(frame_all_size, IPL_DEPTH_8U, 3);
//
//
//	cvZero(frame_all);
//
//
//
//
//	//创建图像头
//	IplImage * img1 =  cvCreateImageHeader(capture_size, frame->depth, frame->nChannels);
//	IplImage * img2 =  cvCreateImageHeader(capture_size, frame->depth, frame->nChannels);
//	IplImage * img3 =  cvCreateImageHeader(capture_size, frame->depth, frame->nChannels);
//
//	img1 ->origin = frame_all ->origin;
//	img1 ->widthStep = frame_all ->widthStep;
//	img1->depth = frame_all->depth;
//	img1 ->nChannels = 3;
//
//
//	img2 ->origin = frame_all ->origin;
//	img2 ->widthStep = frame_all ->widthStep;
//	img2->depth = frame_all->depth;
//	img2 ->nChannels = 3;
//
//
//	img3 ->origin = frame_all ->origin;
//	img3 ->widthStep = frame_all ->widthStep;
//	img3->depth = frame_all->depth;
//	img3 ->nChannels = 3;
//
//	while(1)
//	{
//		cvZero(frame_all);
//		frame = cvQueryFrame(capture);
//		if(!frame)
//		{
//			return 1;
//		}
//		//将彩色图像转化为灰度图像
//		cvCvtColor(frame,frame_gray_1channle,CV_RGB2GRAY);
//		cvCvtColor(frame_gray_1channle,frame_gray_3channels,CV_GRAY2BGR);
//		//
//		frame_canny_1channel = doCanny(frame_gray_1channle,10,100,3);
//		cvCvtColor(frame_canny_1channel,frame_canny_3channels,CV_GRAY2BGR);
//
//		//
//		//指向frame的数据
//		img1->imageData = frame_all->imageData;
//		img2->imageData = frame_all->imageData + capture_widthStep;
//		img3->imageData = frame_all->imageData + 2*capture_widthStep;
//		
//		cvAdd(img1, frame, img1);
//		cvAdd(img2, frame_gray_3channels, img2);
//		cvAdd(img3, frame_canny_3channels,img3);
//
//
//
//		//图像的不同部分写上合适的标签
//		CvFont textfont = cvFont(10.0,1);
//		cvInitFont(&textfont, CV_FONT_HERSHEY_SIMPLEX, 0.5f, 0.5f, 0, 1);
//		cvPutText(frame_all, "Frame", cvPoint(10,20), &textfont, cvScalar(0,0,255));
//		cvPutText(frame_all, "Frame_Gray", cvPoint(capture_width+10,20), &textfont, cvScalar(255,0,0));
//		cvPutText(frame_all, "Frame_Canny", cvPoint(capture_width*2+10, 20), &textfont, cvScalar(0,255,0));
//
//		cvShowImage("window_all",frame_all);
//
//		if(cvWaitKey(33) == 27)
//		{//每秒显示30帧
//			break;
//		}
//	}
//	cvReleaseImage(&frame);
//	cvReleaseImage(&frame_gray_1channle);
//	cvReleaseImage(&frame_gray_3channels);
//	cvReleaseImage(&frame_canny_1channel);
//	cvReleaseImage(&frame_canny_3channels);
//	cvReleaseImage(&img1);
//
//	cvReleaseCapture(&capture);
//	cvDestroyWindow("window_all");
//	return 0;
//}



//*************************************************************
//ch4_prac4_1_b_3

//直接设置Roi进行处理；
//*************************************************************

//#include <cv.h>
//#include <highgui.h>
//#include <stdio.h>
//
////Canny边缘检测算法
//IplImage* doCanny(
//				  IplImage* in,
//				  double lowThresh,
//				  double highThresh,
//				  double aperture
//				  )
//{
//	  if(in->nChannels != 1)
//		  return 0;
//	  IplImage* out = cvCreateImage(
//		  cvGetSize(in),
//		  IPL_DEPTH_8U,
//		  1);
//	  cvCanny(in,out,lowThresh,highThresh,aperture);
//	  return out;
//}
//
//
//int main()
//{
//	
//	IplImage *frame; 
//	CvCapture* capture         = NULL;//视频的每一帧
//	char CaptureName[100] = "test.avi";
//
//	if(!(capture = cvCreateFileCapture( CaptureName )))
//	{
//		printf("Failed to open %s\n");
//		return -1;
//	}
//
//	frame = cvQueryFrame(capture);//读帧视频
//	
//	//
//	//
//	cvNamedWindow("window");
//	cvNamedWindow("window_gray");
//	cvNamedWindow("window_cnany");
//
//	//三个画面放在一个窗口进行显示
//	cvNamedWindow("window_all");
//	//
//	//抓取视频图像的宽和高
//	int capture_width =(int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);
//	int capture_height =(int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);
//	int capture_widthStep = frame->widthStep;
//	
//
//	//图像大小
//	CvSize capture_size = cvSize(capture_width, capture_height);
//
//	//单通道灰度图像
//	IplImage * frame_gray_1channle = cvCreateImage(capture_size, IPL_DEPTH_8U, 1);
//	//3通道灰度图像
//	IplImage * frame_gray_3channels = cvCreateImage(capture_size, IPL_DEPTH_8U, 3);
//
//
//	//单通道canny边缘检测图像
//	IplImage * frame_canny_1channel = cvCreateImage(capture_size, IPL_DEPTH_8U, 1);
//	//3通道canny边缘检测图像
//	IplImage * frame_canny_3channels = cvCreateImage(capture_size, IPL_DEPTH_8U, 3);
//
//
//	//3张图像
//	CvSize frame_all_size = cvSize(3*capture_width, capture_height);
//	IplImage * frame_all = cvCreateImage(frame_all_size, IPL_DEPTH_8U, 3);
//
//
//	cvZero(frame_all);
//
//	while(1)
//	{
//		cvZero(frame_all);
//		frame = cvQueryFrame(capture);
//		if(!frame)
//		{
//			return 1;
//		}
//		//将彩色图像转化为灰色图像
//		cvCvtColor(frame,frame_gray_1channle,CV_RGB2GRAY);
//		cvCvtColor(frame_gray_1channle,frame_gray_3channels,CV_GRAY2BGR);
//		//
//		frame_canny_1channel = doCanny(frame_gray_1channle,10,100,3);
//		cvCvtColor(frame_canny_1channel,frame_canny_3channels,CV_GRAY2BGR);
//
//
//
//		//frame 设置图像Roi及数据复制
//		cvSetImageROI(frame_all, cvRect(0, 0, capture_width, capture_height));
//		cvAdd(frame_all, frame, frame_all);
//		cvResetImageROI(frame_all);
//
//		//frame_gray_3channels
//		cvSetImageROI(frame_all, cvRect(capture_width, 0, capture_width, capture_height));//注意cvRect按width设置
//		cvAdd(frame_all, frame_gray_3channels, frame_all);
//		cvResetImageROI(frame_all);
//
//
//		//frame_canny_3channels
//		cvSetImageROI(frame_all, cvRect(2*capture_width, 0, capture_width, capture_height));
//		cvAdd(frame_all, frame_canny_3channels, frame_all);
//		cvResetImageROI(frame_all);
//
//
//		//图像的不同部分写上合适的标签
//		CvFont textfont = cvFont(10.0,1);
//		cvInitFont(&textfont, CV_FONT_HERSHEY_SIMPLEX, 0.5f, 0.5f, 0, 1);
//		cvPutText(frame_all, "Frame", cvPoint(10,20), &textfont, cvScalar(0,0,255));
//		cvPutText(frame_all, "Frame_Gray", cvPoint(capture_width+10,20), &textfont, cvScalar(255,0,0));
//		cvPutText(frame_all, "Frame_Canny", cvPoint(capture_width*2+10, 20), &textfont, cvScalar(0,255,0));
//
//		cvShowImage("window_all",frame_all);
//
//		if(cvWaitKey(33) == 27){//每秒显示30帧
//			break;
//		}
//	}
//	cvReleaseImage(&frame);
//	cvReleaseImage(&frame_gray_1channle);
//	cvReleaseImage(&frame_gray_3channels);
//	cvReleaseImage(&frame_canny_1channel);
//	cvReleaseImage(&frame_canny_3channels);
//	cvReleaseCapture(&capture);
//	cvDestroyWindow("window_all");
//	return 0;
//}






//*************************************************************
//ch4_prac4_1_b_4
//创建图像头，分别指向frame_all第一幅/第二幅/第三幅图像的 imageData
//使用cvCopy()
//*************************************************************

//#include <cv.h>
//#include <highgui.h>
//#include <stdio.h>
//
////Canny边缘检测算法
//IplImage* doCanny(
//				  IplImage* in,
//				  double lowThresh,
//				  double highThresh,
//				  double aperture
//				  )
//{
//	  if(in->nChannels != 1)
//		  return 0;
//	  IplImage* out = cvCreateImage(
//		  cvGetSize(in),
//		  IPL_DEPTH_8U,
//		  1);
//	  cvCanny(in,out,lowThresh,highThresh,aperture);
//	  return out;
//}
//
//
//int main()
//{
//	
//	IplImage *frame; 
//	CvCapture* capture         = NULL;//视频的每一帧
//	char CaptureName[100] = "test.avi";
//
//	if(!(capture = cvCreateFileCapture( CaptureName )))
//	{
//		printf("Failed to open %s\n");
//		return -1;
//	}
//
//	frame = cvQueryFrame(capture);//读帧视频
//
//	
//	//
//	//
//	cvNamedWindow("window");
//	cvNamedWindow("window_gray");
//	cvNamedWindow("window_cnany");
//
//	//三个画面放在一个窗口进行显示
//	cvNamedWindow("window_all");
//	//
//	//抓取视频图像的宽和高
//	int capture_width =(int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);
//	int capture_height =(int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);
//	int capture_widthStep = frame->widthStep;
//	
//
//	//图像大小
//	CvSize capture_size = cvSize(capture_width, capture_height);
//
//
//	//创建图像
//	//单通道灰度图像
//	IplImage * frame_gray_1channle = cvCreateImage(capture_size, IPL_DEPTH_8U, 1);
//	//3通道灰度图像
//	IplImage * frame_gray_3channels = cvCreateImage(capture_size, IPL_DEPTH_8U, 3);
//	//单通道canny边缘检测图像
//	IplImage * frame_canny_1channel = cvCreateImage(capture_size, IPL_DEPTH_8U, 1);
//	//3通道canny边缘检测图像
//	IplImage * frame_canny_3channels = cvCreateImage(capture_size, IPL_DEPTH_8U, 3);
//	//3张图像一起显示
//	CvSize frame_all_size = cvSize(3*capture_width, capture_height);
//	IplImage * frame_all = cvCreateImage(frame_all_size, IPL_DEPTH_8U, 3);
//
//
//	cvZero(frame_all);
//
//	
//
//	
//
//	//创建图像头
//	IplImage * img1 =  cvCreateImageHeader(capture_size, frame->depth, frame->nChannels);
//	IplImage * img2 =  cvCreateImageHeader(capture_size, frame->depth, frame->nChannels);
//	IplImage * img3 =  cvCreateImageHeader(capture_size, frame->depth, frame->nChannels);
//
//	//对图像头的相关参数进行赋值
//	//img1 ->origin = frame ->origin;
//	img1 ->widthStep = frame_all ->widthStep;
//	//img1->depth = frame->depth;
//	//img1 ->nChannels = 3;
//
//	img2 ->origin = frame ->origin;
//	img2 ->widthStep = frame_all ->widthStep;
//	img2->depth = frame->depth;
//	img2 ->nChannels = 3;
//
//
//	img3 ->origin = frame ->origin;
//	img3 ->widthStep = frame_all ->widthStep;
//	img3->depth = frame->depth;
//	img3 ->nChannels = 3;
//
//	while(1)
//	{
//		frame = cvQueryFrame(capture);
//		if(!frame)
//		{
//			return 1;
//		}
//
//		//将彩色图像转化为灰色图像
//		cvCvtColor(frame,frame_gray_1channle,CV_RGB2GRAY);
//
//		//单通道灰度图像转化为灰度三通道图像
//		cvCvtColor(frame_gray_1channle,frame_gray_3channels,CV_GRAY2BGR);
//
//		frame_canny_1channel = doCanny(frame_gray_1channle,10,100,3);
//		cvCvtColor(frame_canny_1channel,frame_canny_3channels,CV_GRAY2BGR);
//
//
//		//
//		img1 ->imageData = frame_all ->imageData;
//		cvCopy(frame,img1);
//		img2 ->imageData = frame_all ->imageData + frame ->widthStep;
//		cvCopy(frame_gray_3channels,img2);
//		img3 ->imageData = frame_all ->imageData + 2 * frame ->widthStep;
//		cvCopy(frame_canny_3channels,img3);
//
//
//		//图像的不同部分写上合适的标签
//		CvFont textfont = cvFont(10.0,1);
//		cvInitFont(&textfont, CV_FONT_HERSHEY_SIMPLEX, 0.5f, 0.5f, 0, 1);
//		cvPutText(frame_all, "Frame", cvPoint(10,20), &textfont, cvScalar(0,0,255));
//		cvPutText(frame_all, "Frame_Gray", cvPoint(capture_width+10,20), &textfont, cvScalar(255,0,0));
//		cvPutText(frame_all, "Frame_Canny", cvPoint(capture_width*2+10, 20), &textfont, cvScalar(0,255,0));
//
//		cvShowImage("window_all",frame_all);
//
//		if(cvWaitKey(33) == 27){//每秒显示30帧
//			break;
//		}
//	}
//	cvReleaseImage(&frame);
//	cvReleaseImage(&frame_gray_1channle);
//	cvReleaseImage(&frame_gray_3channels);
//	cvReleaseImage(&frame_canny_1channel);
//	cvReleaseImage(&frame_canny_3channels);
//	cvReleaseImage(&img1);
//	cvReleaseImage(&img2);
//	cvReleaseImage(&img3);
//	cvReleaseCapture(&capture);
//	cvDestroyWindow("window_all");
//		
//
//	return 0;
//
//}





//**************************************************************************************************
//ch4_prac4_1_b_5
//创建图像，分别指向frame_all第一幅/第二幅/第三幅图像的 imageData
//使用cvCopy()
//经验证，创建图像也可以达到相同的效果
//两者没有多大区别；
//**************************************************************************************************

//#include <cv.h>
//#include <highgui.h>
//#include <stdio.h>
//
////Canny边缘检测算法
//IplImage* doCanny(
//				  IplImage* in,
//				  double lowThresh,
//				  double highThresh,
//				  double aperture
//				  )
//{
//	  if(in->nChannels != 1)
//		  return 0;
//	  IplImage* out = cvCreateImage(
//		  cvGetSize(in),
//		  IPL_DEPTH_8U,
//		  1);
//	  cvCanny(in,out,lowThresh,highThresh,aperture);
//	  return out;
//}
//
//
//int main()
//{
//	
//	IplImage *frame; 
//	CvCapture* capture         = NULL;//视频的每一帧
//	char CaptureName[100] = "test.avi";
//
//	if(!(capture = cvCreateFileCapture( CaptureName )))
//	{
//		printf("Failed to open %s\n");
//		return -1;
//	}
//
//	frame = cvQueryFrame(capture);//读帧视频
//
//	
//	//
//	//
//	cvNamedWindow("window");
//	cvNamedWindow("window_gray");
//	cvNamedWindow("window_cnany");
//
//	//三个画面放在一个窗口进行显示
//	cvNamedWindow("window_all");
//	//
//	//抓取视频图像的宽和高
//	int capture_width =(int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);
//	int capture_height =(int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);
//	int capture_widthStep = frame->widthStep;
//	
//
//	//图像大小
//	CvSize capture_size = cvSize(capture_width, capture_height);
//
//
//	//创建图像
//	//单通道灰度图像
//	IplImage * frame_gray_1channle = cvCreateImage(capture_size, IPL_DEPTH_8U, 1);
//	//3通道灰度图像
//	IplImage * frame_gray_3channels = cvCreateImage(capture_size, IPL_DEPTH_8U, 3);
//	//单通道canny边缘检测图像
//	IplImage * frame_canny_1channel = cvCreateImage(capture_size, IPL_DEPTH_8U, 1);
//	//3通道canny边缘检测图像
//	IplImage * frame_canny_3channels = cvCreateImage(capture_size, IPL_DEPTH_8U, 3);
//	//3张图像一起显示
//	CvSize frame_all_size = cvSize(3*capture_width, capture_height);
//	IplImage * frame_all = cvCreateImage(frame_all_size, IPL_DEPTH_8U, 3);
//
//
//	cvZero(frame_all);
//
//	
//
//	
//
//	////创建图像头
//	//IplImage * img1 =  cvCreateImageHeader(capture_size, frame->depth, frame->nChannels);
//	//IplImage * img2 =  cvCreateImageHeader(capture_size, frame->depth, frame->nChannels);
//	//IplImage * img3 =  cvCreateImageHeader(capture_size, frame->depth, frame->nChannels);
//
//
//	//创建图像头
//	IplImage * img1 =  cvCreateImage(capture_size, frame->depth, frame->nChannels);
//	IplImage * img2 =  cvCreateImage(capture_size, frame->depth, frame->nChannels);
//	IplImage * img3 =  cvCreateImage(capture_size, frame->depth, frame->nChannels);
//
//
//	//对图像头的相关参数进行赋值
//	//img1 ->origin = frame ->origin;
//	img1 ->widthStep = frame_all ->widthStep;
//	//img1->depth = frame->depth;
//	//img1 ->nChannels = 3;
//
//	img2 ->origin = frame ->origin;
//	img2 ->widthStep = frame_all ->widthStep;
//	img2->depth = frame->depth;
//	img2 ->nChannels = 3;
//
//
//	img3 ->origin = frame ->origin;
//	img3 ->widthStep = frame_all ->widthStep;
//	img3->depth = frame->depth;
//	img3 ->nChannels = 3;
//
//	while(1)
//	{
//		frame = cvQueryFrame(capture);
//		if(!frame)
//		{
//			return 1;
//		}
//
//		//将彩色图像转化为灰色图像
//		cvCvtColor(frame,frame_gray_1channle,CV_RGB2GRAY);
//
//		//单通道灰度图像转化为灰度三通道图像
//		cvCvtColor(frame_gray_1channle,frame_gray_3channels,CV_GRAY2BGR);
//
//		frame_canny_1channel = doCanny(frame_gray_1channle,10,100,3);
//		cvCvtColor(frame_canny_1channel,frame_canny_3channels,CV_GRAY2BGR);
//
//
//		//
//		img1 ->imageData = frame_all ->imageData;
//		cvCopy(frame,img1);
//		img2 ->imageData = frame_all ->imageData + frame ->widthStep;
//		cvCopy(frame_gray_3channels,img2);
//		img3 ->imageData = frame_all ->imageData + 2 * frame ->widthStep;
//		cvCopy(frame_canny_3channels,img3);
//
//
//		//图像的不同部分写上合适的标签
//		CvFont textfont = cvFont(10.0,1);
//		cvInitFont(&textfont, CV_FONT_HERSHEY_SIMPLEX, 0.5f, 0.5f, 0, 1);
//		cvPutText(frame_all, "Frame", cvPoint(10,20), &textfont, cvScalar(0,0,255));
//		cvPutText(frame_all, "Frame_Gray", cvPoint(capture_width+10,20), &textfont, cvScalar(255,0,0));
//		cvPutText(frame_all, "Frame_Canny", cvPoint(capture_width*2+10, 20), &textfont, cvScalar(0,255,0));
//
//		cvShowImage("window_all",frame_all);
//
//		if(cvWaitKey(33) == 27){//每秒显示30帧
//			break;
//		}
//	}
//	cvReleaseImage(&frame);
//	cvReleaseImage(&frame_gray_1channle);
//	cvReleaseImage(&frame_gray_3channels);
//	cvReleaseImage(&frame_canny_1channel);
//	cvReleaseImage(&frame_canny_3channels);
//	cvReleaseImage(&img1);
//	cvReleaseImage(&img2);
//	cvReleaseImage(&img3);
//	cvReleaseCapture(&capture);
//	cvDestroyWindow("window_all");
//		
//
//	return 0;
//
//}




//***********************************************************************************
//ch4_prac4_2
//***********************************************************************************


//#include <cv.h>
//#include <highgui.h>
//#include <stdio.h>
//#include <iostream>
//
//using namespace std;
//
//char* str = (char*)malloc(30 * sizeof(char*));
//bool draw = false;
//CvPoint point;
//CvFont font = cvFont(10.0,1);  
//
//void my_mouse_callback(
//					   int event,
//					   int x,
//					   int y,
//					   int flags,
//					   void* param)
//{
//	   IplImage* img = (IplImage*)param;
//	   switch(event)
//	   {
//		case CV_EVENT_MOUSEMOVE:
//			break;
//		case CV_EVENT_LBUTTONDOWN:
//			{
//				draw = true;
//				CvScalar pt = cvGet2D(img,y,x);
//				double b = pt.val[0];
//				double g = pt.val[1];
//				double r = pt.val[2];
//				memset(str,0,30);
//				//格式化需要显示的字符串
//				sprintf(str,"B:%.0f,G:%.0f,R:%.0f",b,g,r);
//				cout<<"B:"<<b<<",G:"<<g<<",R:"<<r<<endl;
//				point = cvPoint(x,y);
//				cvInitFont(&font, CV_FONT_HERSHEY_SIMPLEX, 0.5f, 0.5f, 0, 1); 
//	  
//			}
//			break;
//
//		case CV_EVENT_LBUTTONUP:
//			draw = false;
//			break;
//		}
//
//}
//
//int main()
//{
//	IplImage* img = cvLoadImage("stuff.jpg");
//	cvNamedWindow("image");
//	//保存原始图像的副本，防止修改图像时，改变原始图像的数据；
//	IplImage* temp = cvCloneImage(img);
//	//设置回调函数
//	cvSetMouseCallback("image",my_mouse_callback,(void*)img);
//	while(1)
//	{
//		cvCopyImage(img,temp);
//		if(draw)
//		{
//			cvPutText(temp,
//				str,
//				point,
//				&font,
//				cvScalar(255,0,0)
//				);
//		}
//		cvShowImage("image",temp);
//		if(cvWaitKey(30) == 27)break;
//	}
//	cvReleaseImage(&img);
//	cvReleaseImage(&temp);
//	cvDestroyWindow("image");
//}





//*********************************************************************************************************
//ch4_prac4_2_a
//*********************************************************************************************************


//#include "opencv\cv.h"
//#include "opencv\highgui.h"
//#include <iostream>
//
//using namespace std;
//
//char* str = (char*)malloc(30 * sizeof(char*));  
//bool draw = false;  
//CvPoint point;  
//CvFont font = cvFont(10.0,1);  
//
//void my_mouse_callback(  
//					   int event,  
//					   int x,  
//					   int y,  
//					   int flags,  
//					   void* param){  
//						   IplImage* img = (IplImage*)param;  
//						   switch(event){  
//		case CV_EVENT_MOUSEMOVE:  
//			break;  
//		case CV_EVENT_LBUTTONDOWN:{  
//			draw = true;  
//			memset(str,0,30);  
//			sprintf(str,"x:%d,y:%d",x,y);  
//			cout<<"x:"<<x<<",y:"<<y<<endl;  
//			point = cvPoint(x,y);  
//			cvInitFont(&font, CV_FONT_HERSHEY_SIMPLEX, 0.5f, 0.5f, 0, 1);   
//								  }  
//								  break;  
//		case CV_EVENT_LBUTTONUP:  
//			draw = false;  
//			break;  
//						   }  
//}  
//
////Canny边缘检测算法
//IplImage* doCanny(
//				  IplImage* in,
//				  int lowThresh,
//				  int highThresh,
//				  int aperture
//				  ){
//					  if(in->nChannels != 1)return 0;
//					  IplImage* out = cvCreateImage(
//						  cvGetSize(in),
//						  IPL_DEPTH_8U,
//						  1);
//					  cvCanny(in,out,lowThresh,highThresh,aperture);
//					  return out;
//}
//
//int main(){
//	CvCapture* capture = cvCreateFileCapture("test.avi");
//	//把三个画面在一个窗口里面显示
//	cvNamedWindow("window_all");
//
//	//视频的每一帧
//	IplImage* frame = NULL;
//	frame = cvQueryFrame(capture);
//	//视频帧图像的宽度和高度
//	int width = (int)cvGetCaptureProperty(capture,CV_CAP_PROP_FRAME_WIDTH);
//	int height = (int)cvGetCaptureProperty(capture,CV_CAP_PROP_FRAME_HEIGHT);
//	//定义两种，是为了使三种图像的通道数一样，便于一起显示
//	//单通道灰度图像
//	IplImage* gray = cvCreateImage(
//		cvSize(width, height),
//		IPL_DEPTH_8U,
//		1);
//	//3通道灰度图像
//	IplImage* frame_gray = cvCreateImage(
//		cvSize(width, height),
//		IPL_DEPTH_8U,
//		3);
//	//单通道Canny边缘检测图像
//	IplImage* Canny = cvCreateImage(
//		cvSize(width, height),
//		IPL_DEPTH_8U,
//		1);
//	//3通道Canny边缘检测图像
//	IplImage* frame_Canny = cvCreateImage(
//		cvSize(width, height),
//		IPL_DEPTH_8U,
//		3);
//	//把3张图像放在一起显示
//	IplImage* frame_all = cvCreateImage(
//		cvSize(width * 3,height),
//		IPL_DEPTH_8U,
//		frame ->nChannels);
//	cvZero(frame_all);
//
//	IplImage* temp = cvCloneImage(frame_all);  
//	cvSetMouseCallback("window_all",my_mouse_callback,(void*)frame_all); 
//
//	//定义三个图像头
//	IplImage* img1 = cvCreateImageHeader(cvSize(width, height),frame ->depth,3);
//	IplImage* img2 = cvCreateImageHeader(cvSize(width, height),frame ->depth,3);
//	IplImage* img3 = cvCreateImageHeader(cvSize(width, height),frame ->depth,3);
//	//img1 ->origin = frame ->origin;
//	img1 ->widthStep = frame_all ->widthStep;
//	//img1->depth = frame->depth;
//	//img1 ->nChannels = 3;
//	//img2 ->origin = frame ->origin;
//	img2 ->widthStep = frame_all ->widthStep;
//	//img2->depth = frame->depth;
//	//img2 ->nChannels = 3;
//	//img3 ->origin = frame ->origin;
//	img3 ->widthStep = frame_all ->widthStep;
//	//img3->depth = frame->depth;
//	//img3 ->nChannels = 3;
//
//	while(1){
//		frame = cvQueryFrame(capture);
//		if(!frame){
//			return 1;
//		}
//		//将彩色图像转化为灰色图像
//		cvCvtColor(frame,gray,CV_RGB2GRAY);
//		cvCvtColor(gray,frame_gray,CV_GRAY2BGR);
//		Canny = doCanny(gray,10,100,3);
//		cvCvtColor(Canny,frame_Canny,CV_GRAY2BGR);
//
//		img1 ->imageData = frame_all ->imageData;
//		cvCopy(frame,img1);
//		img2 ->imageData = frame_all ->imageData + frame ->widthStep;
//		cvCopy(frame_gray,img2);
//		img3 ->imageData = frame_all ->imageData + 2 * frame ->widthStep;
//		cvCopy(frame_Canny,img3);
//
//		CvFont textfont = cvFont(10.0,1);
//		cvInitFont(&textfont, CV_FONT_HERSHEY_SIMPLEX, 0.5f, 0.5f, 0, 1);
//		cvPutText(frame_all, "Frame", cvPoint(10,20), &textfont, cvScalar(0,0,255));
//		cvPutText(frame_all, "Frame_Gray", cvPoint(width+10,20), &textfont, cvScalar(255,0,0));
//		cvPutText(frame_all, "Frame_Canny", cvPoint(width*2+10, 20), &textfont, cvScalar(0,255,0));
//
//
//		cvCopyImage(frame_all,temp);  
//		if(draw){  
//			cvPutText(temp,  
//				str,  
//				point,  
//				&font,  
//				cvScalar(0,0,255)  
//				);  
//		}  
//
//
//		cvShowImage("window_all",temp);
//
//		if(cvWaitKey(33) == 27){//每秒显示30帧
//			return 0;
//		}
//	}
//	cvReleaseImage(&temp);
//	cvReleaseImage(&frame);
//	cvReleaseImage(&gray);
//	cvReleaseImage(&frame_gray);
//	cvReleaseImage(&Canny);
//	cvReleaseImage(&frame_Canny);
//	cvReleaseImage(&img1);
//	cvReleaseImage(&img2);
//	cvReleaseImage(&img3);
//	cvReleaseCapture(&capture);
//	cvDestroyWindow("window_all");
//}




//***************************************************************************************************
//ch4_prac4_3_a
//点击鼠标时，没有恢复为以前的图像
//***************************************************************************************************


//#include "opencv\cv.h"
//#include "opencv\highgui.h"
//
//CvRect rect;	  //矩形框
//bool draw = false;//标记画的状态
//
//void draw_rect(IplImage* img,CvRect rect)
//{
//	cvRectangle(img,cvPoint(rect.x,rect.y),	cvPoint(rect.x + rect.width,rect.y + rect.height),	cvScalar(0x00,0x00,0xff));
//}
//
//
//void my_mouse_callback(
//					   int event,
//					   int x,
//					   int y,
//					   int flags,
//					   void* param)
//{
//	   IplImage* img = (IplImage*)param;
//	   switch(event)
//	   {
//			case CV_EVENT_MOUSEMOVE:
//			{
//				if(draw)
//				{
//					rect.width = x - rect.x;
//					rect.height = y - rect.y;
//				}					
//			}
//			break;
//			case CV_EVENT_LBUTTONDOWN:
//			{
//				draw = true;
//				rect = cvRect(x,y,0,0);
//			}				 
//			break;
//			case CV_EVENT_LBUTTONUP:
//			{
//				draw = false;
//				if(rect.width < 0)
//				{
//					rect.x += rect.width;
//					rect.width *= -1;
//				}
//				if(rect.height < 0)
//				{
//					rect.y += rect.height;
//					rect.height *= -1;
//				}
//				draw_rect(img,rect);
//			}
//			break;
//		}
//}
//
//int main()
//{
//	IplImage* img = cvLoadImage("stuff.jpg");
//	rect = cvRect(-1,-1,0,0);
//	cvNamedWindow("draw rect");
//	//在内存保存副本
//	IplImage* temp = cvCloneImage(img);
//
//	cvSetMouseCallback("draw rect", my_mouse_callback, (void*)img);
//
//	while(1)
//	{
//		cvCopyImage(img, temp);
//		if(draw)
//		{
//			draw_rect(temp,rect);
//		}
//		cvShowImage("draw rect",img);
//		if(cvWaitKey(15) == 27) break;
//	}
//	cvReleaseImage(&img);
//	cvReleaseImage(&temp);
//	cvDestroyWindow("draw rect");
//}


//***************************************************************************************************
//ch4_prac4_3_a
//***************************************************************************************************

//#include "opencv\cv.h"
//#include "opencv\highgui.h"
//
//CvRect rect;//矩形框
//bool draw = false;//标记画矩形框的状态
//bool draw_hist = false;//鼠标左键弹起开始画直方图
//
////绘制直方图的函数
//void draw_rect(IplImage* img,CvRect rect)
//{
//	cvSetImageROI(img,rect);
//	IplImage* src= cvCreateImage(cvSize(rect.width,rect.height),IPL_DEPTH_8U,3);
//	cvCopy(img,src);
//	cvResetImageROI(img);
//
//
//	IplImage* r_img = cvCreateImage(cvGetSize(src),IPL_DEPTH_8U,1);
//	IplImage* g_img = cvCreateImage(cvGetSize(src),IPL_DEPTH_8U,1);
//	IplImage* b_img = cvCreateImage(cvGetSize(src),IPL_DEPTH_8U,1);
//	IplImage* gray_img = cvCreateImage(cvGetSize(src),IPL_DEPTH_8U,1);
//
//
//	//分离R,G,B分量
//	cvSplit(src,r_img,g_img,b_img,NULL);
//	//灰度转换
//	cvCvtColor(src,gray_img,CV_BGR2GRAY);
//	int size = 256;
//	float range[] = {0,255};
//	float* ranges[] = {range};
//
//	//创建直方图
//	CvHistogram* r_hist = cvCreateHist(1,&size,CV_HIST_ARRAY,ranges,1);
//	CvHistogram* g_hist = cvCreateHist(1,&size,CV_HIST_ARRAY,ranges,1);
//	CvHistogram* b_hist = cvCreateHist(1,&size,CV_HIST_ARRAY,ranges,1);
//	CvHistogram* gray_hist = cvCreateHist(1,&size,CV_HIST_ARRAY,ranges,1);
//
//	//红色分量直方图
//	cvCalcHist(&r_img,r_hist,0,NULL);
//	IplImage* r_dst = cvCreateImage(cvSize(400,300),IPL_DEPTH_8U,3);
//	cvSet(r_dst,cvScalarAll(255),0);
//	float r_max = 0;
//	cvGetMinMaxHistValue(r_hist,NULL,&r_max,NULL,NULL);
//	double r_bin_width = (double)r_dst ->width / size;
//	double r_bin_unith = (double)r_dst ->height / r_max;//高度比例
//	for(int i = 0;i < size;++i)
//	{
//		//获得矩形左上角和右下角坐标
//		CvPoint p0 = cvPoint(i * r_bin_width,r_dst ->height);
//		CvPoint p1 = cvPoint((i + 1) * r_bin_width,
//			r_dst ->height - cvGetReal1D(r_hist ->bins,i) * r_bin_unith);
//		cvRectangle(r_dst,p0,p1,cvScalar(255,0,0),-1,8,0);//-1表示画实心矩形
//	}
//
//	//绿色分量直方图
//	cvCalcHist(&g_img,g_hist,0,NULL);
//	IplImage* g_dst = cvCreateImage(cvSize(400,300),IPL_DEPTH_8U,3);
//	cvSet(g_dst,cvScalarAll(255),0);
//	float g_max = 0;
//	cvGetMinMaxHistValue(g_hist,NULL,&g_max,NULL,NULL);
//	double g_bin_width = (double)g_dst ->width / size;
//	double g_bin_unith = (double)g_dst ->height / g_max;//高度比例
//	for(int i = 0;i < size;++i)
//	{
//		//获得矩形左上角和右下角坐标
//		CvPoint p0 = cvPoint(i * g_bin_width,g_dst ->height);
//		CvPoint p1 = cvPoint((i + 1) * g_bin_width,
//			g_dst ->height - cvGetReal1D(g_hist ->bins,i) * g_bin_unith);
//		cvRectangle(g_dst,p0,p1,cvScalar(0,255,0),-1,8,0);//-1表示画实心矩形
//	}
//
//	//蓝色分量直方图
//	cvCalcHist(&b_img,b_hist,0,NULL);
//	IplImage* b_dst = cvCreateImage(cvSize(400,300),IPL_DEPTH_8U,3);
//	cvSet(b_dst,cvScalarAll(255),0);
//	float b_max = 0;
//	cvGetMinMaxHistValue(b_hist,NULL,&b_max,NULL,NULL);
//	double b_bin_width = (double)b_dst ->width / size;
//	double b_bin_unith = (double)b_dst ->height / b_max;//高度比例
//	for(int i = 0;i < size;++i)
//	{
//		//获得矩形左上角和右下角坐标
//		CvPoint p0 = cvPoint(i * b_bin_width,b_dst ->height);
//		CvPoint p1 = cvPoint((i + 1) * b_bin_width,
//			b_dst ->height - cvGetReal1D(b_hist ->bins,i) * b_bin_unith);
//		cvRectangle(b_dst,p0,p1,cvScalar(0,0,255),-1,8,0);//-1表示画实心矩形
//	}
//
//	//灰度图直方图
//	cvCalcHist(&gray_img,gray_hist,0,NULL);
//	IplImage* gray_dst = cvCreateImage(cvSize(400,300),IPL_DEPTH_8U,3);
//	cvSet(gray_dst,cvScalarAll(255),0);
//	float gray_max = 0;
//	cvGetMinMaxHistValue(gray_hist,NULL,&gray_max,NULL,NULL);
//	double gray_bin_width = (double)gray_dst ->width / size;
//	double gray_bin_unith = (double)gray_dst ->height / gray_max;//高度比例
//	for(int i = 0;i < size;++i)
//	{
//		//获得矩形左上角和右下角坐标
//		CvPoint p0 = cvPoint(i * gray_bin_width,gray_dst ->height);
//		CvPoint p1 = cvPoint((i + 1) * gray_bin_width,
//			gray_dst ->height - cvGetReal1D(gray_hist ->bins,i) * gray_bin_unith);
//		cvRectangle(gray_dst,p0,p1,cvScalar(0),-1,8,0);//-1表示画实心矩形
//	}
//
//	//把四个直方图在一幅图片上显示出来
//	IplImage* dst = cvCreateImage(cvSize(800,600),8,3);
//	cvSetZero(dst);
//	//拷贝红色分量直方图
//	CvRect rect = cvRect(0,0,400,300);
//	cvSetImageROI(dst,rect);
//	cvCopy(r_dst,dst);
//	//拷贝绿色分量直方图
//	rect = cvRect(400,0,400,300);
//	cvSetImageROI(dst,rect);
//	cvCopy(g_dst,dst);
//	//拷贝蓝色分量直方图
//	rect = cvRect(0,300,400,300);
//	cvSetImageROI(dst,rect);
//	cvCopy(b_dst,dst);
//	//拷贝灰度图分量直方图
//	rect = cvRect(400,300,400,300);
//	cvSetImageROI(dst,rect);
//	cvCopy(gray_dst,dst);
//
//	cvResetImageROI(dst);
//
//	cvNamedWindow("src",1);
//	cvShowImage("src",src);
//	cvNamedWindow("dst",1);
//	cvShowImage("dst",dst);
//	cvSaveImage("dst.jpg",dst);
//	cvWaitKey(0);
//	cvDestroyAllWindows();
//	cvReleaseImage(&r_img);
//	cvReleaseImage(&g_img);
//	cvReleaseImage(&b_img);
//	cvReleaseImage(&gray_img);
//	cvReleaseImage(&src);
//	cvReleaseImage(&dst);
//	cvReleaseImage(&r_dst);
//	cvReleaseImage(&g_dst);
//	cvReleaseImage(&b_dst);
//
//}
//
////我的鼠标响应函数
//void my_mouse_callback(
//					   int event,
//					   int x,
//					   int y,
//					   int flags,
//					   void* param)
//{
//   IplImage* img = (IplImage*)param;
//   switch(event)   
//   {
//	case CV_EVENT_MOUSEMOVE:
//		{
//			if(draw)
//			{
//				rect.width = x - rect.x;
//				rect.height = y - rect.y;
//			}
//			draw_hist = false;
//		}
//		break;
//	case CV_EVENT_LBUTTONDOWN:
//		{
//			draw = true;
//			rect = cvRect(x,y,0,0);
//			draw_hist = false;
//		}
//		break;
//	case CV_EVENT_LBUTTONUP:
//		{
//			draw = false;
//			draw_hist = true;
//			if(rect.width < 0)
//			{
//				rect.x += rect.width;
//				rect.width *= -1;
//			}
//			if(rect.height < 0)
//			{
//				rect.y += rect.height;
//				rect.height *= -1;
//			}
//			draw_rect(img,rect);
//		}
//		break;
//	}
//}
//
//int main()
//{
//	IplImage* img = cvLoadImage("stuff.jpg");
//
//
//	rect = cvRect(-1,-1,0,0);
//	cvNamedWindow("draw rect");
//
//	//在内存保存副本
//	IplImage* temp = cvCloneImage(img);
//
//	cvSetMouseCallback("draw rect",	my_mouse_callback,(void*)img);
//	while(1)
//	{
//		cvCopyImage(img,temp);
//
//
//		if(draw_hist)
//		{
//			draw_rect(temp,rect);
//		}
//
//
//		cvShowImage("draw rect",temp);
//		if(cvWaitKey(15) == 27)break;
//	}
//	cvReleaseImage(&img);
//	cvReleaseImage(&temp);
//	cvDestroyWindow("draw rect");
//}


//***************************************************************************************************
//ch4_prac4_3_b
//***************************************************************************************************

//#include "opencv\cv.h"
//#include "opencv\highgui.h"
//
//CvRect rect;//矩形框
//bool draw = false;//标记画矩形框的状态
//bool draw_hist = false;//鼠标左键弹起开始画直方图
//
////绘制直方图的函数
//void draw_rect(IplImage* img,CvRect rect){
//	cvSetImageROI(img,rect);
//	IplImage* src= cvCreateImage(
//		cvSize(rect.width,rect.height),
//		IPL_DEPTH_8U,
//		3);
//	cvCopy(img,src);
//	cvResetImageROI(img);
//	IplImage* r_img = cvCreateImage(cvGetSize(src),IPL_DEPTH_8U,1);
//	IplImage* g_img = cvCreateImage(cvGetSize(src),IPL_DEPTH_8U,1);
//	IplImage* b_img = cvCreateImage(cvGetSize(src),IPL_DEPTH_8U,1);
//	IplImage* gray_img = cvCreateImage(cvGetSize(src),IPL_DEPTH_8U,1);
//	//分离R,G,B分量
//	cvSplit(src,r_img,g_img,b_img,NULL);
//	//灰度转换
//	cvCvtColor(src,gray_img,CV_BGR2GRAY);
//	int size = 256;
//	float range[] = {0,255};
//	float* ranges[] = {range};
//	//创建直方图
//	CvHistogram* r_hist = cvCreateHist(1,&size,CV_HIST_ARRAY,ranges,1);
//	CvHistogram* g_hist = cvCreateHist(1,&size,CV_HIST_ARRAY,ranges,1);
//	CvHistogram* b_hist = cvCreateHist(1,&size,CV_HIST_ARRAY,ranges,1);
//	CvHistogram* gray_hist = cvCreateHist(1,&size,CV_HIST_ARRAY,ranges,1);
//	//红色分量直方图
//	cvCalcHist(&r_img,r_hist,0,NULL);
//	IplImage* r_dst = cvCreateImage(cvSize(400,300),IPL_DEPTH_8U,3);
//	cvSet(r_dst,cvScalarAll(255),0);
//	float r_max = 0;
//	cvGetMinMaxHistValue(r_hist,NULL,&r_max,NULL,NULL);
//	double r_bin_width = (double)r_dst ->width / size;
//	double r_bin_unith = (double)r_dst ->height / r_max;//高度比例
//	for(int i = 0;i < size;++i){
//		//获得矩形左上角和右下角坐标
//		CvPoint p0 = cvPoint(i * r_bin_width,r_dst ->height);
//		CvPoint p1 = cvPoint((i + 1) * r_bin_width,
//			r_dst ->height - cvGetReal1D(r_hist ->bins,i) * r_bin_unith);
//		cvRectangle(r_dst,p0,p1,cvScalar(255,0,0),-1,8,0);//-1表示画实心矩形
//	}
//
//	//绿色分量直方图
//	cvCalcHist(&g_img,g_hist,0,NULL);
//	IplImage* g_dst = cvCreateImage(cvSize(400,300),IPL_DEPTH_8U,3);
//	cvSet(g_dst,cvScalarAll(255),0);
//	float g_max = 0;
//	cvGetMinMaxHistValue(g_hist,NULL,&g_max,NULL,NULL);
//	double g_bin_width = (double)g_dst ->width / size;
//	double g_bin_unith = (double)g_dst ->height / g_max;//高度比例
//	for(int i = 0;i < size;++i){
//		//获得矩形左上角和右下角坐标
//		CvPoint p0 = cvPoint(i * g_bin_width,g_dst ->height);
//		CvPoint p1 = cvPoint((i + 1) * g_bin_width,
//			g_dst ->height - cvGetReal1D(g_hist ->bins,i) * g_bin_unith);
//		cvRectangle(g_dst,p0,p1,cvScalar(0,255,0),-1,8,0);//-1表示画实心矩形
//	}
//
//	//蓝色分量直方图
//	cvCalcHist(&b_img,b_hist,0,NULL);
//	IplImage* b_dst = cvCreateImage(cvSize(400,300),IPL_DEPTH_8U,3);
//	cvSet(b_dst,cvScalarAll(255),0);
//	float b_max = 0;
//	cvGetMinMaxHistValue(b_hist,NULL,&b_max,NULL,NULL);
//	double b_bin_width = (double)b_dst ->width / size;
//	double b_bin_unith = (double)b_dst ->height / b_max;//高度比例
//	for(int i = 0;i < size;++i){
//		//获得矩形左上角和右下角坐标
//		CvPoint p0 = cvPoint(i * b_bin_width,b_dst ->height);
//		CvPoint p1 = cvPoint((i + 1) * b_bin_width,
//			b_dst ->height - cvGetReal1D(b_hist ->bins,i) * b_bin_unith);
//		cvRectangle(b_dst,p0,p1,cvScalar(0,0,255),-1,8,0);//-1表示画实心矩形
//	}
//
//	//灰度图直方图
//	cvCalcHist(&gray_img,gray_hist,0,NULL);
//	IplImage* gray_dst = cvCreateImage(cvSize(400,300),IPL_DEPTH_8U,3);
//	cvSet(gray_dst,cvScalarAll(255),0);
//	float gray_max = 0;
//	cvGetMinMaxHistValue(gray_hist,NULL,&gray_max,NULL,NULL);
//	double gray_bin_width = (double)gray_dst ->width / size;
//	double gray_bin_unith = (double)gray_dst ->height / gray_max;//高度比例
//	for(int i = 0;i < size;++i){
//		//获得矩形左上角和右下角坐标
//		CvPoint p0 = cvPoint(i * gray_bin_width,gray_dst ->height);
//		CvPoint p1 = cvPoint((i + 1) * gray_bin_width,
//			gray_dst ->height - cvGetReal1D(gray_hist ->bins,i) * gray_bin_unith);
//		cvRectangle(gray_dst,p0,p1,cvScalar(0),-1,8,0);//-1表示画实心矩形
//	}
//
//	//把四个直方图在一幅图片上显示出来
//	IplImage* dst = cvCreateImage(cvSize(800,600),8,3);
//	cvSetZero(dst);
//	//拷贝红色分量直方图
//	CvRect rect = cvRect(0,0,400,300);
//	cvSetImageROI(dst,rect);
//	cvCopy(r_dst,dst);
//	//拷贝绿色分量直方图
//	rect = cvRect(400,0,400,300);
//	cvSetImageROI(dst,rect);
//	cvCopy(g_dst,dst);
//	//拷贝蓝色分量直方图
//	rect = cvRect(0,300,400,300);
//	cvSetImageROI(dst,rect);
//	cvCopy(b_dst,dst);
//	//拷贝灰度图分量直方图
//	rect = cvRect(400,300,400,300);
//	cvSetImageROI(dst,rect);
//	cvCopy(gray_dst,dst);
//
//	cvResetImageROI(dst);
//
//	cvNamedWindow("src",1);
//	cvShowImage("src",src);
//	cvNamedWindow("dst",1);
//	cvShowImage("dst",dst);
//	cvSaveImage("dst.jpg",dst);
//	cvWaitKey(0);
//	cvDestroyAllWindows();
//	cvReleaseImage(&r_img);
//	cvReleaseImage(&g_img);
//	cvReleaseImage(&b_img);
//	cvReleaseImage(&gray_img);
//	cvReleaseImage(&src);
//	cvReleaseImage(&dst);
//	cvReleaseImage(&r_dst);
//	cvReleaseImage(&g_dst);
//	cvReleaseImage(&b_dst);
//
//}
//
////我的鼠标响应函数
//void my_mouse_callback(
//					   int event,
//					   int x,
//					   int y,
//					   int flags,
//					   void* param){
//						   IplImage* img = (IplImage*)param;
//						   switch(event){
//		case CV_EVENT_MOUSEMOVE:{
//			if(draw){
//				rect.width = x - rect.x;
//				rect.height = y - rect.y;
//			}
//			draw_hist = false;
//								}
//								break;
//		case CV_EVENT_LBUTTONDOWN:{
//			draw = true;
//			rect = cvRect(x,y,0,0);
//			draw_hist = false;
//								  }
//								  break;
//		case CV_EVENT_LBUTTONUP:{
//			draw = false;
//			draw_hist = true;
//			if(rect.width < 0){
//				rect.x += rect.width;
//				rect.width *= -1;
//			}
//			if(rect.height < 0){
//				rect.y += rect.height;
//				rect.height *= -1;
//			}
//			draw_rect(img,rect);
//								}
//								break;
//						   }
//}
//
//int main(){
//	IplImage* img = cvLoadImage("stuff.jpg");
//	rect = cvRect(-1,-1,0,0);
//	cvNamedWindow("draw rect");
//	//在内存保存副本
//	IplImage* temp = cvCloneImage(img);
//	cvSetMouseCallback("draw rect",
//		my_mouse_callback,
//		(void*)img
//		);
//	while(1){
//		cvCopyImage(img,temp);
//		if(draw_hist){
//			draw_rect(temp,rect);
//		}
//		cvShowImage("draw rect",temp);
//		if(cvWaitKey(15) == 27)break;
//	}
//	cvReleaseImage(&img);
//	cvReleaseImage(&temp);
//	cvDestroyWindow("draw rect");
//}



//***************************************************************************************************
//ch4_prac4_4
//***************************************************************************************************

//#include <cv.h>
//#include <highgui.h>
//#include<stdio.h>
//int g_slider_position=0;
//CvCapture *g_capture=NULL;
//int i=0;
//int  g_slider_position1=0;
//bool t=true;
//void onTrackbarSlide(int pos)
//{
//	cvSetCaptureProperty(g_capture,CV_CAP_PROP_POS_FRAMES,pos);
//	i=pos;
//}
//void switch_callback(int position){
//	if(position == 0){
//		t=true;
//	}
//	else
//	{
//		t=false;
//	}
//}
//
//int main()
//{
//	cvNamedWindow("Video",CV_WINDOW_AUTOSIZE);
//	g_capture=cvCaptureFromFile("test.avi");
//	int frames=(int)cvGetCaptureProperty(g_capture,CV_CAP_PROP_FRAME_COUNT);
//	if(frames!=0)
//	{
//		cvCreateTrackbar("Position","Video",&g_slider_position,frames,onTrackbarSlide);
//		cvCreateTrackbar("Position1","Video",&g_slider_position1,1,switch_callback);
//	}
//	else printf("read video wrong");
//	cvSetTrackbarPos("Position","Video",1);
//	cvSetTrackbarPos("Position1","Video",0);
//	IplImage *frame;
//	while((frame=cvQueryFrame(g_capture))!=NULL)
//	{
//		char c=cvWaitKey(1000);
//		if(c==27) break;
//		cvShowImage("Video",frame);
//		cvSetTrackbarPos("Position","Video",i);
//		if(t)
//		{
//			i=i+10;//10为步长
//			cvSetCaptureProperty(g_capture,CV_CAP_PROP_POS_FRAMES,i);
//		}
//		else
//		{
//			cvSetCaptureProperty(g_capture,CV_CAP_PROP_POS_FRAMES,i);
//		}
//	}
//	cvReleaseCapture(&g_capture);
//	cvDestroyWindow("Video");
//	return 0;
//
//}


//***************************************************************************************************
//ch4_prac4_5
//***************************************************************************************************

//#include "stdafx.h"
//#include "cv.h"
//#include "highgui.h"
//#include "stdio.h"
//#include <iostream>
//#include "math.h"
//using namespace std;
//CvRect m_rect;
//bool drawing =false;
//bool drawing_end =false; 
//bool eraser_flag =false;
//void m_mouse_callback(int event,int x, int y,int flag, void *param);
//
//int main(int argc, char **argv)
//{
//
//	cvNamedWindow("Draw");
//	IplImage *m_image=cvCreateImage(cvSize(500,500),IPL_DEPTH_8U,3);
//	IplImage *clone1 =cvCloneImage(m_image);
//	int flag=0;
//	cvZero(m_image);
//	cvSetMouseCallback("Draw",m_mouse_callback,(void *)clone1);
//	cvCreateTrackbar("选择图形","Draw",&flag,3,NULL);
//	while (1)
//	{
//		if (cvWaitKey(10) == 27)
//		{
//			break; 
//		}
//		if (drawing_end == false&&eraser_flag ==false)
//		{
//			cvCopy(m_image,clone1);
//		}
//		if (!eraser_flag &&drawing)
//		{
//			switch (flag)
//			{
//			case 0:cvLine(clone1,cvPoint(m_rect.x,m_rect.y),cvPoint(m_rect.x+m_rect.width,m_rect.y+m_rect.height),cvScalar(255,255,255));
//				break;
//			case 1:cvRectangle(clone1,cvPoint(m_rect.x,m_rect.y),cvPoint(m_rect.x+m_rect.width,m_rect.y+m_rect.height),cvScalar(255,255,255));
//				break;
//			case 2:{
//				int dot_x = (int)m_rect.x;   //画圆形
//				int dot_y = (int)m_rect.y;
//				CvPoint dot =cvPoint(dot_x,dot_y);
//				int redius =(int)sqrt((long double)((m_rect.width*m_rect.width)+(m_rect.height*m_rect.height)));
//				cvCircle(clone1,dot,redius,cvScalar(255,255,255));
//				   }
//				   break;
//			case 3:
//				break;
//			}
//		}
//		cvShowImage("Draw",clone1);
//	}
//	cvWaitKey(0);
//	cvDestroyWindow("Draw");
//	cvReleaseImage(&m_image);
//	cvReleaseImage(&clone1);
//
//}
//void m_mouse_callback(int event,int x, int y,int flag, void *param)
//{
//	switch (event)
//	{
//	case CV_EVENT_LBUTTONDOWN:
//		drawing_end =false;
//		drawing = true;
//		m_rect=cvRect(x,y,0,0);
//		break;
//	case CV_EVENT_LBUTTONUP:
//		drawing_end =true;
//		drawing =false;
//		break;
//	case CV_EVENT_MOUSEMOVE:
//		if (drawing == true)
//		{
//			m_rect.width = x-m_rect.x;
//			m_rect.height =y-m_rect.y;
//		}
//		else if (eraser_flag)
//		{
//			IplImage * temp = cvCreateImageHeader(cvSize(20,20),((IplImage *)param)->depth,3);     //矩形橡皮擦
//			temp->widthStep =((IplImage *)param)->widthStep;
//			temp->imageData =((IplImage *)param)->imageData+temp->widthStep*y+x*3;
//			cvSet(temp,cvScalar(0,0,0));
//
//			cvReleaseImageHeader(&temp);
//
//		}
//		break;
//	case CV_EVENT_RBUTTONDOWN:
//
//		eraser_flag = true;
//		break;
//	case CV_EVENT_RBUTTONUP:
//		eraser_flag =false;
//		break;
//	default:break;
//	}
//}







//***************************************************************************************************
//ch4_prac4_6
//***************************************************************************************************



//#include "stdafx.h"
//#include "cv.h"
//#include "highgui.h"
//#include "stdio.h"
//#include <iostream>
//#include "math.h"
//using namespace std;
//bool edit_flag = false;
//void m_mouse_callback(int event,int x, int y,int flag, void *param);
//CvPoint m_point;
//int main(int argc, char **argv)
//{
//	CvFont my_font;
//	cvInitFont(&my_font,CV_FONT_HERSHEY_SIMPLEX,1.0,1.0);
//	IplImage * m_image = cvCreateImage(cvSize(500,500),IPL_DEPTH_8U,3);
//	cvNamedWindow("My_Picture");
//	cvZero(m_image);
//	cvSetMouseCallback("My_Picture",m_mouse_callback,(void *)m_image);
//	cvShowImage("My_Picture",m_image);
//	char c[2]={0,'\0'};
//	while(1)
//	{
//		if (edit_flag)
//		{
//			c[0]=cvWaitKey(0);
//			if ( 13 == c[0] )
//			{
//				edit_flag = false;
//			}
//			else
//			{
//				cvPutText(m_image,c,m_point,&my_font,cvScalar(255,255,255));
//				m_point.x+=20;
//				cvShowImage("My_Picture",m_image);
//			}
//
//		}
//		else if (cvWaitKey(1) == 27)
//		{
//			break;
//		}
//
//	}
//	cvReleaseImage(&m_image);
//	cvDestroyWindow("My_Picture");
//	return 0;
//}
//void m_mouse_callback(int event,int x, int y,int flag, void *param)
//{
//	switch (event)
//	{
//	case CV_EVENT_LBUTTONDOWN:
//		m_point.x = x;
//		m_point.y = y;
//		edit_flag = true;
//		break;
//	default:break;
//	}
//}


//***************************************************************************************************
//ch4_prac4_7
//***************************************************************************************************



//#include <cv.h>
//#include <highgui.h>
//#include "math.h"  
//int main(int argc, char* argv[])
//{
//	IplImage *src_image=cvLoadImage("fruits.jpg");
//	assert(src_image!=NULL);
//
//	/*************************** a **********************************/
//	IplImage *dst_image=cvCreateImage(cvGetSize(src_image),
//		src_image->depth,
//		src_image->nChannels);
//	assert(dst_image!=NULL);
//	dst_image->origin=src_image->origin;
//	dst_image=cvCloneImage(src_image);
//	CvPoint2D32f srcTri[3];
//	CvPoint2D32f dstTri[3];
//	CvMat *warp_mat=cvCreateMat(2,3,CV_32FC1);
//	srcTri[0].x=0.0f;
//	srcTri[0].y=0.0f;
//	srcTri[1].x=(float)src_image->width-1;
//	srcTri[1].y=0.0f;
//	srcTri[2].x=0.0f;
//	srcTri[2].y=(float)src_image->height-1;
//	cvNamedWindow("Show_Src",1);
//	cvNamedWindow("Show_Dst",1);
//	cvShowImage("Show_Src",src_image);
//	cvShowImage("Show_Dst",dst_image);
//	while (1)
//	{
//		char c=cvWaitKey(0);
//
//		switch (c)
//		{
//		case '1':
//			{
//				dstTri[0].x=src_image->width*0.0;
//				dstTri[0].y=src_image->height*0.0;
//				dstTri[1].x=src_image->width*0.90;
//				dstTri[1].y=src_image->height*0.10;
//				dstTri[2].x=src_image->width*0.10;
//				dstTri[2].y=src_image->height*0.90;
//			}
//			break;
//		case '2':
//			{
//				dstTri[0].x=src_image->width*0.0;
//				dstTri[0].y=src_image->height*0.0;
//				dstTri[1].x=src_image->width*0.80;
//				dstTri[1].y=src_image->height*0.20;
//				dstTri[2].x=src_image->width*0.20;
//				dstTri[2].y=src_image->height*0.80;
//			}
//			break;
//		case '3':
//			{
//				dstTri[0].x=src_image->width*0.0;
//				dstTri[0].y=src_image->height*0.0;
//				dstTri[1].x=src_image->width*0.70;
//				dstTri[1].y=src_image->height*0.30;
//				dstTri[2].x=src_image->width*0.30;
//				dstTri[2].y=src_image->height*0.70;
//			}
//			break;
//		case '4':
//			{
//				dstTri[0].x=src_image->width*0.0;
//				dstTri[0].y=src_image->height*0.0;
//				dstTri[1].x=src_image->width*0.60;
//				dstTri[1].y=src_image->height*0.40;
//				dstTri[2].x=src_image->width*0.40;
//				dstTri[2].y=src_image->height*0.60;
//
//			}
//			break;
//		case '5':
//			{
//				dstTri[0].x=src_image->width*0.0;
//				dstTri[0].y=src_image->height*0.0;
//				dstTri[1].x=src_image->width*0.55;
//				dstTri[1].y=src_image->height*0.45;
//				dstTri[2].x=src_image->width*0.45;
//				dstTri[2].y=src_image->height*0.55;
//			}
//			break;
//		case '6':
//			{
//				dstTri[0].x=src_image->width*0.0;
//				dstTri[0].y=src_image->height*0.0;
//				dstTri[1].x=src_image->width*0.40;
//				dstTri[1].y=src_image->height*0.60;
//				dstTri[2].x=src_image->width*0.60;
//				dstTri[2].y=src_image->height*0.40;
//			}
//			break;
//		case '7':
//			{
//				dstTri[0].x=src_image->width*0.0;
//				dstTri[0].y=src_image->height*0.0;
//				dstTri[1].x=src_image->width*0.30;
//				dstTri[1].y=src_image->height*0.70;
//				dstTri[2].x=src_image->width*0.70;
//				dstTri[2].y=src_image->height*0.30;
//			}
//		case '8':
//			{
//				dstTri[0].x=src_image->width*0.0;
//				dstTri[0].y=src_image->height*0.0;
//				dstTri[1].x=src_image->width*0.20;
//				dstTri[1].y=src_image->height*0.80;
//				dstTri[2].x=src_image->width*0.80;
//				dstTri[2].y=src_image->height*0.20;
//			}
//			break;
//		case '9':
//			{
//				dstTri[0].x=src_image->width*0.0;
//				dstTri[0].y=src_image->height*0.0;
//				dstTri[1].x=src_image->width*0.10;
//				dstTri[1].y=src_image->height*0.90;
//				dstTri[2].x=src_image->width*0.90;
//				dstTri[2].y=src_image->height*0.10;
//			}
//			break;
//
//		default:
//			{
//				dstTri[0].x=src_image->width*0.0;
//				dstTri[0].y=src_image->height*0.0;
//				dstTri[1].x=src_image->width*1.0;
//				dstTri[1].y=src_image->height*0.0;
//				dstTri[2].x=src_image->width*0.0;
//				dstTri[2].y=src_image->height*1.0;
//			}
//		}
//		//得到仿射矩阵。由三个不共线的点得到，这样具有唯一性
//		cvGetAffineTransform(srcTri,dstTri,warp_mat);
//		//实现仿射变换，第三个参数为上一个函数得到的仿射矩阵
//		cvWarpAffine(src_image,dst_image,warp_mat);
//		cvShowImage("Show_Dst",dst_image);
//		if(cvWaitKey(0)==27)
//			break;
//		/************************************ b *******************************/
//		IplImage* dst_1=0;    //放大目标图像
//		IplImage* dst_2;      //缩小目标图像
//		float         scaler1 = 1.5;      //图像放大为原来的5倍
//		float         scaler2 = 0.618;    //图像缩小为原来的0.5倍
//		CvSize        Size;        //放大目标图像大小
//		CvSize        Size1;       //缩小目标图像大小
//		//设置放大的图像的尺寸
//		Size.width= src_image->width*scaler1;  
//		Size.height= src_image->height*scaler1;
//		dst_1 = cvCreateImage(Size,src_image->depth,src_image->nChannels);
//		cvResize(src_image,dst_1,CV_INTER_LINEAR); 
//		Size1.width=src_image->width*scaler2;
//		Size1.height=src_image->height*scaler2;
//		dst_2 = cvCreateImage(Size1,src_image->depth,src_image->nChannels);
//		cvResize(src_image,dst_2,CV_INTER_LINEAR);
//		cvNamedWindow("dst_max");
//		cvNamedWindow("dst_min");
//		cvShowImage("dst_max",dst_1);
//		cvShowImage("dst_min",dst_2);
//		cvWaitKey();
//		/*********************************** c ***************************/
//		int delta = 1; //用于控制旋转的角度
//		int angle = 0;  //旋转的角度
//		int opt = 0;		// 1： 旋转加缩放
//		// 0:  仅仅旋转
//		double factor;   //控制旋转
//		IplImage* dst;  //目标图像存放
//		dst = cvCloneImage (src_image);
//		for (;;)
//		{
//			float m[6];
//			CvMat M = cvMat (2, 3, CV_32F, m);
//			int w = src_image->width;
//			int h = src_image->height;
//			if (1)		// 旋转加缩放
//				factor = (cos (angle * CV_PI / 180.0) + 1.0) * 2;
//			else			
//				factor = 1;
//			m[0] = (float) (factor * cos (-angle * 2 * CV_PI / 180.));
//			m[1] = (float) (factor * sin (-angle * 2 * CV_PI / 180.));
//			m[3] = -m[1];
//			m[4] = m[0];
//			// 将旋转中心移至图像中间
//			m[2] = w * 0.5f;
//			m[5] = h * 0.5f;
//			//  dst(x,y) = A * src(x,y) + b
//			cvZero (dst);
//			//提取像素四边形，使用子像素精度
//			cvGetQuadrangleSubPix (src_image, dst, &M);
//			cvNamedWindow ("dst", 1);
//			cvShowImage ("dst", dst);
//			if (cvWaitKey (1) == 27)
//				break;
//			angle = (int) (angle + delta) % 360;
//		}		
//		return 0;
//	}
//}




//***************************************************************************************************
//ch4_prac4_8
//***************************************************************************************************


//#include <opencv/cv.h> 
//#include <opencv/highgui.h>
////#include <opencv_libs.h>
// 
//#include <stdio.h> 
//#include <stdlib.h> 
//#include <string.h> 
//#include <assert.h> 
//#include <math.h> 
//#include <float.h> 
//#include <limits.h> 
//#include <time.h> 
//#include <ctype.h>
// 
//#define  WND_RESULT   "result"
// 
//static CvMemStorage* storage = 0; 
//static CvHaarClassifierCascade* cascade = 0;
// 
//void detect_and_draw( IplImage* image );
// 
//const char* cascade_name = "haarcascade_frontalface_alt.xml"; 
// 
///* Skull image */
//IplImage* g_skullImage;
// 
///* Trackbar initial value */
//int g_trackbar_value = 5;
///* Tackbar total values */
//int g_trackbar_total = 10;
// 
///* Alpha blend's alpha */
//double g_alpha = 0;
// 
///* Trackbar callback function */
//void switch_callback(int pos)
//{
//    printf("Trackbar event.  pos: %d\n", pos);
//    g_alpha = (double)pos / g_trackbar_total;
//}
// 
//int main( ) 
//{ 
//    /*CvCapture* capture = cvCreateCameraCapture(0);*/
//	char videoAVI[100] = "test.avi";
//	CvCapture* capture = cvCreateFileCapture( videoAVI );
//    if(!capture)
//    {
//        printf("Camera error.\n");
//        return -1;
//    }
//
//    cascade_name = "haarcascade_frontalface_alt.xml"; 
//    cascade = (CvHaarClassifierCascade*)cvLoad( cascade_name, 0, 0, 0 ); 
// 
//    if( !cascade ) 
//    { 
//        printf( "ERROR: Could not load classifier cascade\n" ); 
//        return -1; 
//    } 
// 
//    storage = cvCreateMemStorage(0); 
//    cvNamedWindow( WND_RESULT, 1 ); 
// 
//    IplImage* frame = cvQueryFrame(capture);
//    if(!frame)
//    {
//        return -1;
//    }
// 
//    // Load skull image
//    IplImage* skullImage = cvLoadImage("skull.jpg", CV_LOAD_IMAGE_UNCHANGED);
//    if(!skullImage)
//    {
//        printf("ERROR: Can't load skull image.\n");
//        return -1;
//    }
//    g_skullImage = cvCreateImage(cvGetSize(skullImage), skullImage->depth, 3);
//    if(skullImage->nChannels != 3)
//    {
//        cvCvtColor(skullImage, g_skullImage, CV_GRAY2BGR);
//    }
//    else
//    {
//        cvCopy(skullImage, g_skullImage);
//    }
// 
//    // Create trackbar
//    cvCreateTrackbar("Switch", WND_RESULT, &g_trackbar_value, g_trackbar_total, switch_callback );
//    // Initialize Alpha-Blend's alpha
//    g_alpha = (double)g_trackbar_value / g_trackbar_total;
// 
//    char c;
//    while( 1 ) 
//    { 
//        frame = cvQueryFrame(capture);
//        if(!frame)
//        {
//            return -1;
//        }
// 
//        detect_and_draw( frame ); 
// 
//        c = cvWaitKey(500);
//        if(c == 27)
//        {
//            break;
//        }
//    }
// 
//    cvDestroyWindow(WND_RESULT); 
//    cvReleaseImage(&frame);
//    cvReleaseCapture(&capture);
//    cvReleaseImage(&skullImage);
//    cvReleaseImage(&g_skullImage);
// 
//    return 0; 
//}
// 
// 
//void detect_and_draw(IplImage* img ) 
//{ 
//    double scale=1.2; 
//    static CvScalar colors[] = { 
//        {{0,0,255}},{{0,128,255}},{{0,255,255}},{{0,255,0}}, 
//        {{255,128,0}},{{255,255,0}},{{255,0,0}},{{255,0,255}} 
//    };//Just some pretty colors to draw with
// 
//    //Image Preparation 
//    // 
//    IplImage* gray = cvCreateImage(cvSize(img->width,img->height),8,1); 
//    IplImage* small_img=cvCreateImage(cvSize(cvRound(img->width/scale),cvRound(img->height/scale)),8,1); 
//    cvCvtColor(img,gray, CV_BGR2GRAY); 
//    cvResize(gray, small_img, CV_INTER_LINEAR);
// 
//    cvEqualizeHist(small_img,small_img); //直方图均衡
// 
//    //Detect objects if any 
//    // 
//    cvClearMemStorage(storage); 
//    double t = (double)cvGetTickCount(); 
//    CvSeq* objects = cvHaarDetectObjects(small_img, 
//        cascade, 
//        storage, 
//        1.1, 
//        2, 
//        0/*CV_HAAR_DO_CANNY_PRUNING*/, 
//        cvSize(30,30));
// 
//    t = (double)cvGetTickCount() - t; 
//    printf( "detection time = %gms\n", t/((double)cvGetTickFrequency()*1000.) );
// 
//    //Loop through found objects and draw boxes around them 
//    for(int i=0;i<(objects? objects->total:0);++i) 
//    { 
//        CvRect* r=(CvRect*)cvGetSeqElem(objects,i); 
// 
//        CvRect r_scale = cvRect( r->x * scale, r->y * scale, r->width * scale, r->height * scale );
//        // 改变骷髅头图像大小
//        IplImage * skullResize = cvCreateImage( cvSize(r_scale.width, r_scale.height),
//            g_skullImage->depth, g_skullImage->nChannels );
//        cvResize(g_skullImage, skullResize, CV_INTER_LINEAR);
// 
//        // 将人脸检测区域用骷髅头图像代替
//        cvSetImageROI(img, r_scale);
//        // b -- Alpha blend 
//        printf("Alpha: %f\t", g_alpha);
//        cvAddWeighted( img, g_alpha, skullResize, 1.0 - g_alpha, 0.0, img);
//       /* This is a part
//        cvCopy(skullResize, img); */
//        cvResetImageROI(img);
//        cvReleaseImage(&skullResize);
// 
//     //   cvRectangle(img, cvPoint(r->x*scale,r->y*scale), cvPoint((r->x+r->width)*scale,(r->y+r->height)*scale), colors[i%8]); 
//    } 
// /*   for( int i = 0; i < (objects? objects->total : 0); i++ ) 
//    { 
//        CvRect* r = (CvRect*)cvGetSeqElem( objects, i ); 
//        CvPoint center; 
//        int radius; 
//        center.x = cvRound((r->x + r->width*0.5)*scale); 
//        center.y = cvRound((r->y + r->height*0.5)*scale); 
//        radius = cvRound((r->width + r->height)*0.25*scale); 
//        cvCircle( img, center, radius, colors[i%8], 3, 8, 0 ); 
//    } */
// 
//    cvShowImage( WND_RESULT, img ); 
//    cvReleaseImage(&gray); 
//    cvReleaseImage(&small_img); 
//}





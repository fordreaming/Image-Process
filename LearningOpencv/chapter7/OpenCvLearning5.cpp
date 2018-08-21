#include "stdafx.h"
//#include <stdio.h>
//#include <cv.h>
//#include <highgui.h>
//
//#include <opencv2/legacy/legacy.hpp>
//#pragma comment(lib, "opencv_legacy240.lib")
//
//
//void f(IplImage* src,  IplImage* dst ) 
//{
//   CvMemStorage* storage = cvCreateMemStorage(0);
//   CvSeq* comp = NULL;
//
//   cvPyrSegmentation( src, dst, storage, &comp, 4, 200, 50 );
//   int n_comp = comp->total;
//
//   for( int i=0; i<n_comp; i++ ) 
//   {
//	   CvConnectedComp* cc = (CvConnectedComp*) cvGetSeqElem( comp, i );
//	   // do_something_with( cc );
//   }
//   cvReleaseMemStorage( &storage );
//}
//
//int main(int argc, char** argv)
//{
//
//	// Create a named window with a the name of the file.
//	/*cvNamedWindow( argv[1], 1 );*/
//	cvNamedWindow("ch5_1", 1 );
//	// Load the image from the given file name.
//	/*IplImage* src = cvLoadImage( argv[1] );*/
//	IplImage* src = cvLoadImage("stuff.jpg");
//	if(!src) 
//	{ 
//		printf("Couldn't seem to Open %s, sorry\n", "ch5_1"); 
//		return -1;
//	}
//
//	IplImage* dst = cvCreateImage( cvGetSize(src), src->depth, src->nChannels);
//	f( src, dst);
//
//	// Show the image in the named window
//	cvShowImage( "ch5_1", dst );
//
//	// Idle until the user hits the "Esc" key.
//	while( 1 ) { if( cvWaitKey( 100 ) == 27 ) break; }
//
//	// Clean up and don¡¯t be piggies
//	cvDestroyWindow( "ch5_1" );
//	cvReleaseImage( &src );
//	cvReleaseImage( &dst );
//
//}
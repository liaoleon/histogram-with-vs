#include <stdio.h>
#include <cv.h>
#include <highgui.h>
#include <iostream>
using namespace std;
using namespace cv;

int main( int argc, char **argv )
{


	char* FileName="DSC_0122.jpg";
	IplImage *image1 = cvLoadImage(FileName,CV_LOAD_IMAGE_COLOR);
	IplImage *image2 = cvCreateImage(cvGetSize(image1),IPL_DEPTH_8U,3);
 	int Height=cvGetDimSize(image1,0);//讀取矩陣高度
	int Width=cvGetDimSize(image1,1);//讀取矩陣寬度
	double Y,U,V;
	CvScalar Scalar1;
	
	for(int i=0;i<Height;i++){
		for (int j=0;j<Width;j++){
			 Scalar1=cvGet2D(image1,i,j);
			 Y=Scalar1.val[2]*0.299+0.587*Scalar1.val[1]+0.114*Scalar1.val[0];
			 //U=0.436*(Scalar1.val[0]-Y)/(1-0,114)+128;
			 //V=0.615*(Scalar1.val[2]-Y)/(1-0.299)+128;
			 if(Y<64)
				cvSet2D(image2,i,j,cvScalar(0,0,0));
			 else
				cvSet2D(image2,i,j,cvScalar(255,255,255));
			 
			
		}
	}
	
	
    cvNamedWindow("Show Image",0);
	cvResizeWindow("Show Image",774,510);
    cvShowImage("Show Image",image1);

	cvNamedWindow("Show Image2",0);
	cvResizeWindow("Show Image2",774,510);
    cvShowImage("Show Image2",image2);


    cvWaitKey(0);

    cvDestroyWindow("Show Image");

    cvReleaseImage(&image1);
	return 0;
}

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

	int Height=cvGetDimSize(image1,0);//讀取矩陣高度
	int Width=cvGetDimSize(image1,1);//讀取矩陣寬度
	double B[4000][3000];
	CvScalar Scalar1;

	for(int i=1;i<=Height;i++){
		for (int j=1;j<=Width;j++){
			 Scalar1=cvGet2D(image1,i,j);
			 B[i][j]=Scalar.val[0];
			
		}
	}



	
    cvNamedWindow("Show Image",0);
	cvResizeWindow("Show Image",774,510);
    cvShowImage("Show Image",image1);

    cvWaitKey(0);

    cvDestroyWindow("Show Image");

    cvReleaseImage(&image1);
	return 0;
}

#include <stdio.h>
#include <cv.h>
#include <highgui.h>
#include <iostream>
using namespace std;
using namespace cv;

int main( int argc, char **argv )
{

	int GrayLevel[256]={0};
	double pdf[256]={0};
	double cdf[256]={0};
	int idx[256]={0};
	char* FileName="DSC_038.jpg";
	char* testimage="001.jpg";
	char* FileName2="DSC_0158.jpg";
	IplImage *image1 = cvLoadImage(testimage,CV_LOAD_IMAGE_COLOR);
	IplImage *image2 = cvLoadImage(FileName2,CV_LOAD_IMAGE_COLOR);
	IplImage *image3 = cvCreateImage(cvGetSize(image2),IPL_DEPTH_8U,3);
 	int Height=cvGetDimSize(image1,0);//讀取矩陣高度
	int Width=cvGetDimSize(image1,1);//讀取矩陣寬度
	int Y,U,V;
	int temp=0;
	int temp2=0;
	CvScalar Scalar1;
	
	for(int i=0;i<Height;i++){
		for (int j=0;j<Width;j++){
			 Scalar1=cvGet2D(image1,i,j);
			 Y=(int)Scalar1.val[2]*0.299+0.587*Scalar1.val[1]+0.114*Scalar1.val[0];
			 GrayLevel[Y]++;		 
			 
		}
	}
	//pdf
	for(int i=0;i<256;i++){
		pdf[i]=(GrayLevel[i]*1.0/(Height*Width));
	}

	/*for(int i=0;i<256;i++){
		cout<< pdf[i]<<endl;
		temp++;
		temp2+=GrayLevel[i];
	}

	cout<<"temp:"<<temp<<endl;
	cout<<"GreyLevel:"<<temp2<<endl;
	cout<<"Height*Width:"<<Height*Width<<endl;*/

	//cdf
	for(int i=0;i<256;i++){
		for (int j=0;j<=i;j++){
			cdf[i]+=pdf[j];
		}

	}
	/*for(int i=0;i<256;i++){
		cout<< cdf[i]<<endl;
	}*/

	for(int i=0;i<256;i++)
    {
        idx[i]=256*cdf[i];
	}

	//for(int i=0;i<Height;i++){
	//	for (int j=0;j<Width;j++){
	//		 Scalar1=cvGet2D(image2,i,j);
	//		 cvSet2D(image3,i,j,cvScalar(0,0,0));
	//	}
	//}

	Height=cvGetDimSize(image2,0);//讀取矩陣高度
	Width=cvGetDimSize(image2,1);//讀取矩陣寬度

	for(int i=0;i<Height;i++){
		for (int j=0;j<Width;j++){
			 Scalar1=cvGet2D(image2,i,j);
			 Y=(int)Scalar1.val[2]*0.299+0.587*Scalar1.val[1]+0.114*Scalar1.val[0];
			 U=0.436*(Scalar1.val[0]-Y)/(1-0,114)+128;
			 V=0.615*(Scalar1.val[2]-Y)/(1-0.299)+128;
			 Scalar1.val[2]=idx[Y]+(1.4075*(V-128));
			 Scalar1.val[1]=idx[Y]-(0.3455*(U-128)-(0.7169*(V-128)));
			 Scalar1.val[0]=idx[Y]+(1.7790*(U-128));
			 cvSet2D(image3,i,j,Scalar1);
		}
	}

    cvNamedWindow("Show Image",0);
	cvResizeWindow("Show Image",774,510);
    cvShowImage("Show Image",image1);

	cvNamedWindow("Show Image2",0);
	cvResizeWindow("Show Image2",774,510);
    cvShowImage("Show Image2",image3);


    cvWaitKey(0);
	cvDestroyWindow("Show Image");
	cvReleaseImage(&image1);
	cvReleaseImage(&image2);
	cvReleaseImage(&image3);
	return 0;
}

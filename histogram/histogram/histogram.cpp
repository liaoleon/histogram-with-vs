 #include <stdio.h>
#include <cv.h>
#include <highgui.h>
#include <iostream>
using namespace std ;

int main( int argc, char **argv )
{


	IplImage *img01;
	CvSize imgsize01 = cvSize(300,300);  // 給圖像SIZE
	img01 = cvCreateImage(imgsize01,IPL_DEPTH_8U,3);//創造img01

	int Height=cvGetDimSize(img01,0);//讀取矩陣高度
	int Width=cvGetDimSize(img01,1);//讀取矩陣寬度

	//這裡先給img01全白
	for(int y = 0 ; y < Height ; y++)
		for(int x = 0 ; x < Width ; x++ )
			cvSet2D(img01,y,x,CV_RGB(255,255,255));//特別注意 給值是 (y,x)

	for(int y = 0 ;y < Width ; y++)
		cvSet2D(img01,y,10,CV_RGB(255,0,0));//特別注意 給值是 (y,x)

	for(int x = 0 ;x < Width ; x++)
		cvSet2D(img01,10,x,CV_RGB(0,255,0));//特別注意 給值是 (y,x)


	cout<<"(10,100)R ="<<cvGet2D(img01, 100 , 10 ).val[2]<<endl;//試著讀取某個點的RGB值
	cout<<"(10,100)G ="<<cvGet2D(img01, 100 , 10 ).val[1]<<endl;//特別注意是cvGet2D(img,y,x)
	cout<<"(10,100)B ="<<cvGet2D(img01, 100 , 10 ).val[0]<<endl;//所以在輸入XY時 X 和 Y 要對調


	cvNamedWindow("img01",CV_WINDOW_AUTOSIZE);
	cvShowImage("img01", img01);
	//輸出img01




	cvWaitKey(0);
	cvReleaseImage(&img01);
	cvDestroyAllWindows();
	return 0;
}

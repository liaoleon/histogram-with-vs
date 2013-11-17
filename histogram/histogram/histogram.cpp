 #include <stdio.h>
#include <cv.h>
#include <highgui.h>
#include <iostream>
using namespace std ;

int main( int argc, char **argv )
{


	IplImage *img01;
	CvSize imgsize01 = cvSize(300,300);  // ���Ϲ�SIZE
	img01 = cvCreateImage(imgsize01,IPL_DEPTH_8U,3);//�гyimg01

	int Height=cvGetDimSize(img01,0);//Ū���x�}����
	int Width=cvGetDimSize(img01,1);//Ū���x�}�e��

	//�o�̥���img01����
	for(int y = 0 ; y < Height ; y++)
		for(int x = 0 ; x < Width ; x++ )
			cvSet2D(img01,y,x,CV_RGB(255,255,255));//�S�O�`�N ���ȬO (y,x)

	for(int y = 0 ;y < Width ; y++)
		cvSet2D(img01,y,10,CV_RGB(255,0,0));//�S�O�`�N ���ȬO (y,x)

	for(int x = 0 ;x < Width ; x++)
		cvSet2D(img01,10,x,CV_RGB(0,255,0));//�S�O�`�N ���ȬO (y,x)


	cout<<"(10,100)R ="<<cvGet2D(img01, 100 , 10 ).val[2]<<endl;//�յ�Ū���Y���I��RGB��
	cout<<"(10,100)G ="<<cvGet2D(img01, 100 , 10 ).val[1]<<endl;//�S�O�`�N�OcvGet2D(img,y,x)
	cout<<"(10,100)B ="<<cvGet2D(img01, 100 , 10 ).val[0]<<endl;//�ҥH�b��JXY�� X �M Y �n���


	cvNamedWindow("img01",CV_WINDOW_AUTOSIZE);
	cvShowImage("img01", img01);
	//��Ximg01




	cvWaitKey(0);
	cvReleaseImage(&img01);
	cvDestroyAllWindows();
	return 0;
}

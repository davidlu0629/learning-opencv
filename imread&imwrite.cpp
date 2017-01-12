#define _CRT_SECURE_NO_DEPRECATE


//#include "stdafx.h"
//need precise path
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <stdlib.h>
using namespace cv;
using namespace std;

int main(int argc, const char** argv)
{
	
	Mat img = imread("d:\\appp.jpg", CV_LOAD_IMAGE_UNCHANGED);
	
	Mat red_img(500, 500, CV_8UC3, Scalar(0, 0, 256));
	//sometimes will use convertTo func to let your img fit to the desire size of imwrite
	red_img.convertTo(red_img, CV_8U);
	

	if (img.empty())
	{
		cout << "fail" << endl;
		system("pause");
		return -1;
	}

	namedWindow("ShowWindow", CV_WINDOW_AUTOSIZE);
	namedWindow("RedWindow", CV_WINDOW_AUTOSIZE);
	
	//sometime will have some problem when you want to save your img as .jpg file
	imwrite("d:\\jj.bmp", img);
	imshow("ShowWindow", img);
	imshow("RedWindow", red_img);
	

	waitKey(0);
	

	destroyWindow("ShowWindow");
	destroyWindow("RedWindow");
	system("pause");
	return 0;
}

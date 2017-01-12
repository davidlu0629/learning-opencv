#define _CRT_SECURE_NO_DEPRECATE


//#include "stdafx.h"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <stdlib.h>
using namespace cv;
using namespace std;

int main(int argc, const char** argv)
{
	
	Mat img = imread("d:\\appp.jpg", CV_LOAD_IMAGE_UNCHANGED);
	
	Mat red_img(500, 500, CV_8UC3, Scalar(0, 0, 256));
	red_img.convertTo(red_img, CV_8U);
	

	if (img.empty())
	{
		cout << "fail" << endl;
		system("pause");
		return -1;
	}

	namedWindow("ShowWindow", CV_WINDOW_AUTOSIZE);
	namedWindow("RedWindow", CV_WINDOW_AUTOSIZE);
	

	imwrite("d:\\jj.bmp", img);
	imshow("ShowWindow", img);
	imshow("RedWindow", red_img);
	

	waitKey(0);
	

	destroyWindow("ShowWindow");
	destroyWindow("RedWindow");
	system("pause");
	return 0;
}

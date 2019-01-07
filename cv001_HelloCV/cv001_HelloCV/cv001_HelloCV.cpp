#include "pch.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#pragma comment(lib, "opencv_world343d.lib")
using namespace std;
using namespace cv;

int main()
{
	Mat img;
	img = imread("image.jpg");
	if (img.empty()) {
		cout << "Unable to read the file";
		cin.get();
		return -1;
	}
	imshow("Image", img);
	waitKey();
	return 0;
}
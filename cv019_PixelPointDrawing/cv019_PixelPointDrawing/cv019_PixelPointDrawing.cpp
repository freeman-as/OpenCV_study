﻿#include "pch.h"
#include <opencv2/opencv.hpp>
#pragma comment(lib, "opencv_world343d.lib")
using namespace std;
using namespace cv;
static const string DATA_PATH = "../../data/";

int main()
{
	Mat img;
	while (1) {
		if (waitKey(30) == 27) break;
	}
	return 0;
}

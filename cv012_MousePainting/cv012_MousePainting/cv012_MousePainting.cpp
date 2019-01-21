#include "pch.h"
#include <opencv2/opencv.hpp>
#pragma comment(lib, "opencv_world343d.lib")
using namespace std;
using namespace cv;
static const string OUT_PATH = "../../out/";

Mat img(Size(640, 480), CV_8UC3, Scalar(255, 255, 255));
int vR = 0, vG = 0, vB = 255, vS = 8;

// マウスコールバック関数
void onMouse(int event, int x, int y, int flags, void* userdata);

int main()
{
	imshow("ペイント", img);
	setMouseCallback("ペイント", onMouse);

	createTrackbar("赤", "ペイント", &vR, 255);
	createTrackbar("青", "ペイント", &vG, 255);
	createTrackbar("緑", "ペイント", &vB, 255);
	createTrackbar("サイズ", "ペイント", &vS, 32);

	int key = waitKey(0);
	if (key == 's') imwrite(OUT_PATH + "ペイント.png", img);
	return 0;
}

// マウスコールバック関数
void onMouse(int event, int x, int y, int flags, void* userdata)
{
	// 左ボタンを押しながらマウス移動
	if (event == EVENT_MOUSEMOVE && flags == EVENT_FLAG_LBUTTON)
	{
		circle(img, Point(x, y), vS, Scalar(vB, vG, vR), CV_FILLED, LINE_AA);
	}
	else if (event == EVENT_FLAG_RBUTTON)
	{
		img.setTo(255);
	}
	imshow("ペイント", img);
}
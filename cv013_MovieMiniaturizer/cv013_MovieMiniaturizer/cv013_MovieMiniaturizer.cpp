#include "pch.h"
#include <opencv2/opencv.hpp>
#pragma comment(lib, "opencv_world343d.lib")
using namespace std;
using namespace cv;
static const string DATA_PATH = "../../data/";

// コールバック関数
void changeBrigtness(int position, void* userdata);
void setRectangle(int event, int x, int y, int flags, void* userdata);

int main()
{
	Mat src, dst;
	VideoCapture cap(DATA_PATH + "video.avi");
	namedWindow("出力映像");

	// ぼけ
	int sizeBlur = 12;
	createTrackbar("ぼかし", "出力映像", &sizeBlur, 30);

	// 速さ
	int speed = 5;
	createTrackbar("速さ", "出力映像", &speed, 50);

	// 明るさ
	double brigtness = 2.0;
	createTrackbar("明るさ", "出力映像", NULL, 50, changeBrigtness, &brigtness);
	setTrackbarPos("明るさ", "出力映像", 20);

	// 矩形領域
	// 始点と終点の座標
	int pt[] = { 40, 100, 600, 320 };
	setMouseCallback("出力映像", setRectangle, pt);

	while (1)
	{
		cap >> src;
		if (src.empty()) break;
		resize(src, src, Size(640, 480));
		src = src * brigtness;

		//ぼけ＆矩形
		blur(src, dst, Size(sizeBlur + 1, sizeBlur + 1));
		Rect roi(Point(pt[0], pt[1]), Point(pt[2], pt[3]));		// 矩形の対角
		src(roi).copyTo(dst(roi));

		imshow("出力映像", dst);

		// 速さの調整
		if (waitKey(speed + 1) == 27) break;
	}

	return 0;
}

// トラックバー（明るさ）コールバック関数
void changeBrigtness(int position, void* userdata)
{
	// void型をdouble型にキャスト
	double* br = (double*)(userdata);
	// 明るさ倍率計算
	*br = (double)position / 10.0;
}
void setRectangle(int event, int x, int y, int flags, void* userdata)
{
	// void型をint型にキャスト
	int* pt = (int*)(userdata);

	// マウスイベントで処理分岐
	switch (event)
	{
	case EVENT_LBUTTONDOWN:
		// 左ボタンを押したとき
		if (0 < x && x < 640 && 0 < y && y < 480)
		{
			// 始点座標を更新
			pt[0] = x, pt[1] = y;
		}
		break;
	case EVENT_MOUSEMOVE:
		// マウスを移動して
		if (flags == EVENT_FLAG_LBUTTON)
		{
			// 左ボタンを押している時
			if (0 < x && x < 640 && 0 < y && y < 480 && x != pt[0] && y != pt[1])
			{
				// 終点座標を更新
				pt[2] = x, pt[3] = y;
			}
		}
		break;
	}
}


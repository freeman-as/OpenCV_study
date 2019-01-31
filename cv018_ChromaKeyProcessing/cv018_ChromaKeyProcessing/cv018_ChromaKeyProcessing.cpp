#include "pch.h"
#include <opencv2/opencv.hpp>
#pragma comment(lib, "opencv_world343d.lib")
using namespace std;
using namespace cv;
static const string DATA_PATH = "../../data/";

int main()
{
	Mat src1, src2, mask, dst, hsv;
	VideoCapture cap1(DATA_PATH + "video.avi"), 
				 cap2(DATA_PATH + "duck_greenback.avi");
			 	 //cap2(DATA_PATH + "color_chart.jpg");
	vector<Mat> ch(3);

	// 色相範囲ウィンドウと色相環の生成
	Mat imgHue1(Size(300, 300), CV_8UC3, Scalar::all(0)), imgHue2;
	for (int h = 0; h < 180; h++) {
		ellipse(imgHue1, Point(150, 150), Size(120, 120), -90, 2 * h - 1, 2 * h + 1, Scalar(h, 255, 255), -1);
	}
	cvtColor(imgHue1, imgHue1, COLOR_HSV2BGR);
	imshow("色相範囲", imgHue1);
	// 色相範囲初期値
	int minTrack = 30, maxTrack = 110;
	createTrackbar("最小値", "色相範囲", &minTrack, 180);
	createTrackbar("最大値", "色相範囲", &maxTrack, 180);

	while (1) {
		cap1 >> src1;
		if (src1.empty()) break;
		cap2 >> src2;
		if (src2.empty()) break;
		// src2をsrc1のサイズにあわせる
		resize(src2, src2, src1.size());

		// BGR > HSV変換合成
		cvtColor(src2, hsv, COLOR_BGR2HSV);
		split(hsv, ch);

		// HSVのHからマスク画像生成
		int maxH = max(maxTrack, minTrack);
		int minH = min(maxTrack, minTrack);
		// 上限
		threshold(ch[0], mask, maxH, 255, THRESH_TOZERO_INV);
		// 下限
		threshold(mask, mask, minH, 255, THRESH_BINARY);
		// ノイズ除去
		morphologyEx(mask, mask, MORPH_OPEN, noArray(), Point(-1, -1), 2);

		// 合成
		// アヒル映像を全部コピー
		src2.copyTo(dst);
		// 入力映像をマスク
		src1.copyTo(dst, mask);

		// 色相環と範囲の描画
		imgHue1.copyTo(imgHue2);
		ellipse(imgHue2, Point(150, 150), Size(130, 130), -90, 2 * minH - 1, 2 * maxH + 1, Scalar::all(255), 16);

		imshow("マスク映像", mask);
		imshow("合成映像", dst);
		imshow("色相範囲", imgHue2);

		if (waitKey(20) == 27) break;
	}

	return 0;
}

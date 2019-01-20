#include "pch.h"
#include <opencv2/opencv.hpp>
#pragma comment(lib, "opencv_world343d.lib")
using namespace std;
using namespace cv;
static const string DATA_PATH = "../../data/";

// 明るさ倍率の初期値
double brigtness = 1.0;
// トラックバー呼び出し関数
void changeBrigtness(int position, void* userdata);

int main()
{
	// 2値化閾値の初期値
	int val = 128;
	// 2値化の際の閾値の判定方法
	int mode = 1;	// THRESH_BINARY_INV
	Mat src, gray, dst;
	VideoCapture cap(DATA_PATH + "video.avi");
	namedWindow("入力映像");
	namedWindow("2値化映像");
	// トラックバー生成
	createTrackbar("閾値", "2値化映像", &val, 255);
	// 値が変化したときのコールバックを設定するパターン
	createTrackbar("明るさ", "入力映像", NULL, 200, changeBrigtness);
	// スライダ初期位置設定
	setTrackbarPos("明るさ", "入力映像", 100);

	while (1)
	{
		cap >> src;
		if (src.empty()) return -1;
		// 明るさ変更
		src = src * brigtness;
		cvtColor(src, gray, COLOR_BGR2GRAY);
		// mode:0==THRESH_BINARY, mode:1==THRESH_BINARY_INV
		//threshold(gray, dst, val, 255, mode);
		//threshold(gray, dst, val, 255, THRESH_BINARY_INV);
		
		// 大津アルゴリズム
		int thresh = (int)threshold(gray, dst, NULL, 255, THRESH_BINARY_INV | THRESH_OTSU);

		imshow("入力映像", src);
		imshow("2値化映像", dst);

		int key = waitKey(30);

		// 2値化の輝度を反転
		if (key == 'o') mode = !mode;
		
		if (key == 27) break;

	}
	return 0;
}

// トラックバー（明るさ）呼び出し関数
void changeBrigtness(int position, void* userdata)
{
	brigtness = (double)position / 100.0;
	cout << "明るさ倍率 = " << brigtness << endl;
}

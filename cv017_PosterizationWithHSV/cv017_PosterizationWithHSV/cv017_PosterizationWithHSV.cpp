#include "pch.h"
#include <opencv2/opencv.hpp>
#pragma comment(lib, "opencv_world343d.lib")
using namespace std;
using namespace cv;
static const string DATA_PATH = "../../data/";

int main()
{
	// 減色数のパターン(180の約数)
	vector<int>lColor{ 180, 1, 2, 3, 4, 5, 6, 9, 10, 12, 15, 18, 20, 30, 36, 45, 60, 90 };

	Mat src, hsv, poster;
	src = imread(DATA_PATH + "image.png");
	//src = imread(DATA_PATH + "lena.jpg");
	
	if (src.empty()) {
		cout << "画像がありません" << endl;
		cin.get();
		return -1;
	};

	cvtColor(src, hsv, COLOR_BGR2HSV);

	for (int c = 0; c < lColor.size(); c++) {
		vector<Mat> ch(3);
		// BGRチャンネルに分離
		split(hsv, ch);
		int nColor = lColor[c];
		int colorRange = 180 / nColor;

		// 整数で割っているので、小数点以下が切り捨てられ
		// nColor色数でcolorRange範囲内に収まる
		// ex.) nColor=3, colorRange=60, h=128(ある1ピクセルの色相) => 128 / 60 = 2 * 60 = 120
		// 上の計算から128から120に変換されている
		ch[0] /= colorRange;
		ch[0] *= colorRange;
		merge(ch, poster);
		cvtColor(poster, poster, COLOR_HSV2BGR);

		stringstream ss;
		ss << "C=" << nColor;
		putText(poster, ss.str(), Point(20, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar::all(0));

		imshow("ポスタリゼーション", poster);

		if (waitKey() == 27) break;
	}

	return 0;
}

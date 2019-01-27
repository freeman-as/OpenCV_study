#include "pch.h"
#include <opencv2/opencv.hpp>
#pragma comment(lib, "opencv_world343d.lib")
using namespace std;
using namespace cv;
static const string DATA_PATH = "../../data/";

// 処理周期と周波数の表示関数
void showFPS(Mat &img, double period);

int main()
{
	VideoCapture cap(DATA_PATH + "sample1.avi");
	int numDilate = 8;	// dilate処理反復数初期値
	// 1秒間のtick数
	double tickS = getTickFrequency();
	namedWindow("dilate処理");
	// トラックバー作成
	createTrackbar("処理反復数", "dilate処理", &numDilate, 32);
	Mat src, dst;

	while (1) {
		cap >> src;
		if (src.empty()) break;
		// 現時点のtick数を取得
		int64 startTick = getTickCount();
		// dilate処理
		dilate(src, dst, noArray(), Point(-1, -1), numDilate);
		double period = (getTickCount() - startTick) * 1000.0 / tickS;
		
		// 処理時間[ms]とFPS表示
		showFPS(dst, period);
		imshow("dilate処理", dst);
		if (waitKey(30) == 27) break;
	}

	return 0;
}

// 処理時間[ms]とFPS表示関数
void showFPS(Mat &img, double period) {
	// 周波数[fps]
	double fps = 1000.0 / period;
	// 文字表示
	stringstream st;
	st.precision(1);
	st << fixed << period << " ms, " << fps << " fps";
	putText(img, st.str(), Point(16, 32), FONT_HERSHEY_SIMPLEX, 1, Scalar::all(255), 2, LINE_AA);
}
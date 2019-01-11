#include "pch.h"
#include <opencv2/opencv.hpp>
#pragma comment(lib, "opencv_world343d.lib")
using namespace std;
using namespace cv;

int main()
{
	VideoCapture cap(0);
	if (! cap.isOpened())
	{
		cout << "カメラが見つかりません" << endl;
		cin.get();
		return -1;
	}

	// 表示ウィンドウの作成
	namedWindow("反転映像", WINDOW_NORMAL);
	// ウィンドウサイズを変更
	resizeWindow("反転映像", 800, 600);
	Mat src, dst;

	while (1)
	{
		cap >> src;
		if (src.empty()) break;
		// 左右反転処理
		flip(src, dst, 1);
		imshow("カメラ映像", src);
		imshow("反転映像", dst);
		if (waitKey(30) == 27) break;
	}
	return 0;
}

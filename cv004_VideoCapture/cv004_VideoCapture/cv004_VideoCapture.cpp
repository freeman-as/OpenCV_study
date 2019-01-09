#include "pch.h"
#include <opencv2/opencv.hpp>
#pragma comment(lib, "opencv_world343d.lib")
using namespace std;
using namespace cv;

int main()
{
	// ビデオファイル開く
	VideoCapture cap("../../data/vtest.avi");
	if (!cap.isOpened())
	{
		cout << "ビデオファイルが開けません" << endl;
		cin.get();
		return -1;
	}

	Mat img;

	while (1)
	{
		cap >> img;		// 1フレーム読込
		if (img.empty())
		{
			cout << "映像終了" << endl;
			break;		//フレームが空のとき終了
		}
		imshow("映像表示", img);
		if (waitKey(30) == 27) break;
	}
	return 0;
}

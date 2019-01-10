#include "pch.h"
#include <opencv2/opencv.hpp>
#pragma comment(lib, "opencv_world343d.lib")
using namespace std;
using namespace cv;

int main()
{
	VideoCapture cap("../../data/sample2.avi");
	VideoWriter rec("video_dst.avi"
		, VideoWriter::fourcc('X', 'V', 'I', 'D'), 30, Size(640, 480));

	Mat src, gray, dst;

	while (1)
	{
		cap >> src;
		if (src.empty()) break;

		// グレースケールに変換
		cvtColor(src, gray, COLOR_BGR2GRAY);
		// 二値化処理
		threshold(gray, gray, 128, 255, THRESH_BINARY);
		// 3チャンネルに変換
		// 書き込み用に指定したチャンネル数に合わせるため
		cvtColor(gray, dst, COLOR_GRAY2BGR);

		imshow("入力映像", src);
		imshow("出力映像", dst);

		// 1フレーム書き込み
		rec << dst;

		if (waitKey(30) == 27) break;
	}
	return 0;
}

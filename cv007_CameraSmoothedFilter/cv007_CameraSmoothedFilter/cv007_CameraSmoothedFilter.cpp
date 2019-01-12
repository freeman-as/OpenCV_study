#include "pch.h"
#include <opencv2/opencv.hpp>
#pragma comment(lib, "opencv_world343d.lib")
using namespace std;
using namespace cv;

int main()
{
	VideoCapture cap(0);
	Size sizeRec(800, 600);
	VideoWriter rec(
		"video_dst.avi", VideoWriter::fourcc('X', 'V', 'I', 'D'), 30, sizeRec);
	Mat src, dst, tmp, gaussian, moving;

	if (!cap.isOpened())
	{
		cout << "カメラ映像が取得できません" << endl;
		cin.get();
		return -1;
	}

	while (1)
	{
		cap >> src;
		if (src.empty()) break;

		// ガウシアン平滑化
		GaussianBlur(src, tmp, Size(15, 15), 5.0, 5.0);
		resize(tmp, gaussian, sizeRec);
		// 平滑化
		blur(src, tmp, Size(100, 5));
		resize(tmp, moving, sizeRec);

		imshow("カメラ映像", src);
		imshow("ガウシアン平滑化", gaussian);
		imshow("移動平均平滑化", moving);

		dst = gaussian;
		// dst = blur;
		rec << dst;

		if (waitKey(30) == 27) break;
	}
}

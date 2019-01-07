#include "pch.h"
#include <opencv2/opencv.hpp>	// OpenCVヘッダ
#pragma comment(lib, "opencv_world343d.lib")	// OpenCVライブラリ
using namespace std;	// C++標準ライブラリ名前空間
using namespace cv;		// OpenCV名前空間

int main()
{
	Mat src = imread("../../data/lena.jpg", IMREAD_GRAYSCALE);
	Mat	dest;

	// Cannyアルゴリズムによるエッジ検出
	Canny(src, dest, 50, 150);

	imshow("入力画像", src);
	imshow("出力画像", dest);
	
	// 出力画像の保存
	imwrite("img_dest.png", dest);

	waitKey();
	return 0;
}

#include "pch.h"
#include <opencv2/opencv.hpp>	// OpenCVヘッダ
#pragma comment(lib, "opencv_world343d.lib")	// OpenCVライブラリ
using namespace std;	// C++標準ライブラリ名前空間
using namespace cv;		// OpenCV名前空間

int main()
{
	Mat src = imread("../../data/lena.jpg");
	Mat src_gray = imread("../../data/lena.jpg", IMREAD_GRAYSCALE);	// grayscaleにして読込
	Mat	dst, dst1, dst2, dst3, dst4;

	// Cannyアルゴリズムによるエッジ検出
	Canny(src, dst1, 50, 150);		// 戻りは第二引数で受ける

	// イラスト風処理
	stylization(src, dst2);

	// 鉛筆画風に加工
	pencilSketch(src, dst3, dst4);

	dst = dst3;
	imshow("入力画像", src);
	imshow("出力画像", dst);

	// 保存時のパラメーター
	vector<int> params{ IMWRITE_JPEG_QUALITY, 50 };

	// 出力画像の保存
	imwrite("img_dst.png", dst);
	imwrite("img_src.jpg", src, params);	// param指定


	waitKey();
	return 0;
}

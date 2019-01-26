#include "pch.h"
#include <opencv2/opencv.hpp>
#pragma comment(lib, "opencv_world343d.lib")
using namespace std;
using namespace cv;
static const string DATA_PATH = "../../data/";

int sw = 480, sh = 480, cr = 16;
int numNearPoint = -1;
Mat src, dst;
vector<Point2f> ptSrc{
	Point2f(150, 100), Point2f(250, 100),
	Point2f(250, 200), Point2f(150, 200)
};
vector<Point2f> ptDst{
	Point2f(0, 0), Point2f(sw, 0),
	Point2f(sw, sh), Point2f(0, sh)
};

// マウスコールバック関数
void onMouse(int event, int x, int y, int flags, void* userdata);

int main()
{
	VideoCapture cap(DATA_PATH + "sample1.avi");
	namedWindow("入力映像");
	setMouseCallback("入力映像", onMouse);

	while (1)
	{
		cap >> src;
		if (src.empty()) break;
		// 射影変換行列取得
		Mat pM = getPerspectiveTransform(ptSrc, ptDst);
		// 射影変換
		warpPerspective(src, dst, pM, Size(sw, sh), INTER_LINEAR);
		// Point2f -> Point型に変換
		vector<Point> pt4{ ptSrc[0], ptSrc[1], ptSrc[2], ptSrc[3] };
		
		// 枠線の描画
		polylines(src, pt4, true, Scalar(255, 0, 0), 2);
		// 
		for (int i = 0; i < 4; i++)
		{
			// 小円の描画
			circle(src, pt4[i], cr, Scalar(0, 0, 0), 3);
		}
		imshow("入力映像", src);
		imshow("射影変換", dst);

		if (waitKey(30) == 27) break;
	}

	return 0;
}

// マウスコールバック関数
void onMouse(int event, int x, int y, int flags, void* userdata)
{
	switch (event) {
		// 左ボタンを押したとき
		case EVENT_LBUTTONDOWN: {
			// 距離最小値minDistanceの初期化
			double minDistance = cr;
			numNearPoint = -1;
			for (int i = 0; i < 4; i++) {
				// 4点から近い点番号を探す
				double distance = norm(Point(x, y) - (Point)ptSrc[i]);
				// 距離最小値より小さいとき
				if (distance < minDistance) {
					// 点番号の更新
					numNearPoint = i;
					minDistance = distance;
				}
			}
			break;
		}
		// マウス移動したとき
		case EVENT_MOUSEMOVE:
			// 左ボタン押されていてかつ近い点取得済の時
			if (flags == EVENT_FLAG_LBUTTON && numNearPoint >= 0) {
				ptSrc[numNearPoint] = Point(x, y);
			}
			break;
		// 右ボタンクリック
		case EVENT_RBUTTONDOWN:
			// 4点をリセット
			ptSrc[0] = Point2f(150, 100), ptSrc[1] = Point2f(250, 100);
			ptSrc[2] = Point2f(250, 200), ptSrc[3] = Point2f(150, 200);
			break;
	}
}
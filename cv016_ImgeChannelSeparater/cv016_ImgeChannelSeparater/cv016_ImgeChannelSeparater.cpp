#include "pch.h"
#include <opencv2/opencv.hpp>
#pragma comment(lib, "opencv_world343d.lib")
using namespace std;
using namespace cv;
static const string DATA_PATH = "../../data/";

int main()
{
	VideoCapture cap(DATA_PATH + "sample1.avi");
	// 入力映像サイズ
	Size frame((int)cap.get(CAP_PROP_FRAME_WIDTH),
		(int)cap.get(CAP_PROP_FRAME_HEIGHT));
	Mat src;
	// ゼロ画像
	Mat imgZero = Mat::zeros(frame, CV_8UC1);
	// 総フレーム数
	//int count = cap.get(CV_CAP_PROP_FRAME_COUNT);
	//int frameCount = 0;
	//cout << "総フレーム数" << count << endl;

	// 3チャンネル出力用のMatとそれぞれの名前
	// 3チャンネル出力画像3枚
	vector<Mat> dst(3);
	// 各色の名称
	vector<string> colors = { "青チャンネル", "緑チャンネル", "赤チャンネル" };

	while (1) {
		cap >> src;
		if (src.empty()) break;
		vector<Mat>ch(3);
		// BGRチャンネルに分離
		split(src, ch);
		for (int i = 0; i < ch.size(); i++) {
			vector<Mat> temp { imgZero, imgZero, imgZero };
			temp[i] = ch[i];
			// チャンネル合成
			merge(temp, dst[i]);
			imshow(colors[i], dst[i]);
		}
		imshow("入力カラー映像", src);

		// BGRピクセル平均値を計算し表示する
		Scalar ave = mean(src);

		cout.precision(0);
		//cout << fixed << "フレーム数: " << frameCount++ <<  "; BGR平均値: " << ave << "; ";
		cout << fixed << "BGR平均値: " << ave << "; ";
		Point maxLoc;
		// 最大値の要素番号を求める
		minMaxLoc(ave, NULL, NULL, NULL, &maxLoc);
		cout << colors[maxLoc.y] + "成分が多い" << endl;

		if (waitKey(30) == 27) break;
	}
	return 0;
}

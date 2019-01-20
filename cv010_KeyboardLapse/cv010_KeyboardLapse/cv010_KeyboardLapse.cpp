#include "pch.h"
#include <opencv2/opencv.hpp>
#pragma comment(lib, "opencv_world343d.lib")
using namespace std;
using namespace cv;
static const string OUT_PATH = "../../out/";

void drawGrid(Mat img, int count)
{
	int grid = 30;
	Scalar white = Scalar::all(255);
	// 画像の幅でループ
	for (int x = grid; x < img.cols; x += grid)
	{
		// 画像の高さでループ
		for (int y = grid; y < img.rows; y += grid)
		{
			line(img, Point(x, y), Point(x, y), white, 1, LINE_4);
		}
	}
	// 文字列ストリーム
	stringstream ss;
	ss << count;
	putText(img, ss.str(), Point(10, 20), FONT_HERSHEY_PLAIN, 1, white);
}

int main()
{
	int frameRate = 5;
	
	string filename = "komadori.avi";
	Mat src, disp, prev;
	int mode = 0;
	vector<float> overlay = { 0.0, 0.5 };

	VideoCapture cap(0);
	// 入力カメラサイズ取得
	Size frame(
		(int)cap.get(CAP_PROP_FRAME_WIDTH),
		(int)cap.get(CAP_PROP_FRAME_HEIGHT));
	VideoWriter rec(OUT_PATH + filename, VideoWriter::fourcc('X', 'V', 'I', 'D'), frameRate, frame);

	cout << "Frame" << frame << ". c: 書き込み o: オーバーレイ ESC: 保存終了" << endl;
	prev = Mat(frame, CV_8UC3, Scalar::all(128));
	int count = 0;

	while (1)
	{
		cap >> src;
		// - 演算の前にキャスト必要かも
		disp = src * (1 - overlay[mode]) + prev * overlay[mode];
		drawGrid(disp, count);
		imshow("コマ撮り", disp);

		int key = waitKey(30);
		if (key == 'c' || key == 32)
		{
			rec << src;
			// 指定したコマをディープコピー
			prev = src.clone();
			count++;
		}
		else if (key == 'o')
		{
			mode = 1 - mode;
			// mode = !mode;	// こっちでもok
		}
		else if (key == 27)
		{
			break;
		}
	}
}

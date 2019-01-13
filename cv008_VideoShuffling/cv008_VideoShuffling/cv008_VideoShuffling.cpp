#include "pch.h"
#include <opencv2/opencv.hpp>
#pragma comment(lib, "opencv_world343d.lib")
using namespace std;
using namespace cv;

int main()
{
	VideoCapture cap("../../data/video.avi");
	Mat src;

	if (!cap.isOpened())
	{
		cout << "映像が読み込めません" << endl;
		cin.get();
		return -1;
	}

	// ビデオ属性の取得
	int frameWidth  = (int)cap.get(CAP_PROP_FRAME_WIDTH);
	int frameHeight = (int)cap.get(CAP_PROP_FRAME_HEIGHT);
	int frameCount = (int)cap.get(CAP_PROP_FRAME_COUNT);
	int fps = (int)cap.get(CAP_PROP_FPS);
	int wait = 1000 / fps;

	cout << "(w, h) = (" << frameWidth << ", " << frameHeight << ")" << endl;
	cout << "fps = " << fps << ", wait = " << wait << "ms" << endl;
	cout << "ビデオ長" << frameCount << " (" << frameCount / fps << "s)" << endl;

	bool loop = true;
	while (loop)
	{
		int pos = rand() % frameCount;
		int window = rand() % 30 + 10;
		int direction = 2 * (rand() % 2) - 1;
		cout << "開始: " << pos << ", コマ数: " << window << ", 方向: " <<
			direction << endl;

		for (int f = 0; f < window; f++)
		{
			cap.set(CAP_PROP_POS_FRAMES, pos);
			cap >> src;
			imshow("シャッフル", src);
			pos += direction;
			pos = min(pos, frameCount-1);
			pos = max(pos, 0);
			if (waitKey(wait) == 27)
			{
				loop = false;
				break;
			}
		}

	}

	// 処理終了
	cap.release();
	// ウィンドウを閉じる
	destroyWindow("シャッフル");

	cout << "キーを押して終了してください" << endl;
	cin.get();
	return 0;
}

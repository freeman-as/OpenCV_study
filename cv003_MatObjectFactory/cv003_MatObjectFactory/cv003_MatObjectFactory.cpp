#include "pch.h"
#include <opencv2/opencv.hpp>
#pragma comment(lib, "opencv_world343d.lib")
using namespace std;
using namespace cv;

void printMat(string, Mat &m);

int main()
{
	// (cos, rows, type)のコストラクタ
	Mat img1(480, 640, CV_8UC1);
	printMat("img1", img1);

	// (Size, Type)のコストラクタ
	Size s2(640, 480);
	Mat img2(s2, CV_8UC1);
	printMat("img2", img2);

	// (Size, Type, カラー(Scalar))のコストラクタ
	Scalar color(237, 149, 100);
	Mat img3(Size(400, 400), CV_8UC3, color);
	printMat("img3", img3);

	// Scalarで::allを用いてグレー画像を生成
	Mat img4(s2 * 2, CV_8UC3, Scalar::all(128));
	printMat("img4", img4);

	// Zeros
	Mat img5 = Mat::zeros(Size(320, 160), CV_8UC3);
	printMat("img5", img5);

	// createメソッドを使った方法
	Mat img6;
	img6.create(Size(300, 300), CV_32FC3);
	img6.setTo(Scalar(0.0, 1.0, 0.0));
	printMat("img6", img6);

	// cloneメソッドを使って同じMatを生成（コピー）
	Mat img7 = img3.clone();
	printMat("img7", img7);

	// copyToメソッドを用いてコピー生成
	Mat img8;
	img3.copyTo(img8);
	printMat("img8", img8);

	return 0;
}

void printMat(string str, Mat &m)
{
	cout << "----" << str << "----" << endl;
	cout << "Size (attr): [" << m.cols << "," << m.rows << "]" << endl;
	cout << "Dim (attr): " << m.dims << endl;
	cout << "Size (method): " << m.size() << endl;
	cout << "Total (method): " << m.total() << endl;
	cout << "Channels (method): " << m.channels() << endl;
	cout << "Depth (method): " << m.depth() << endl;
	cout << "Type (method): " << m.type() << endl;
	imshow("生成画像", m);
	waitKey();
}
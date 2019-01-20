## cv011_SwitchingBinarization
トラックバーのスライド操作で映像の明るさと2値化の閾値をそれぞれリアルタイムに変化させつつ、処理後の映像を再生する

---
### 使用したOpenCVのAPIについて

- **``createTrackbar()``**
  トラックバーの作成
  https://docs.opencv.org/3.4.3/d7/dfc/group__highgui.html#gaf78d2155d30b728fc413803745b67a9b

  ```c++
  int cv::createTrackbar(const String & trackbarname, const String & winname, int * value, int count, TrackbarCallback onChange = 0, void * userdata = 0)
  // - trackbarname: 作成するトラックバーの識別名
  // - winname: トラックバーを作成するウィンドウのウィンドウ識別名
  // - value: スライダの初期位置(値)
  // - count: スライダの最大値。最小値は常に0
  // - onChange: スライダ位置が変更されるたびに呼び出される関数
  // - userdata: コールバック関数に渡されるユーザーデータ	
  ```

  ```c++
  // コールバック関数定義
  typedef void(* cv::TrackbarCallback)(int pos, void *userdata)
  ```



- **``setTrackbarPos()``**
  スライダ位置(値)を設定
  https://docs.opencv.org/3.4.3/d7/dfc/group__highgui.html#ga67d73c4c9430f13481fd58410d01bd8d

  ```c++
  void cv::setTrackbarPos(const String & trackbarname, const String & winname, int pos)
  // - pos: スライダ位置(値)作成するトラックバーの識別名
  ```




- 

---
### メモ

- **``createTrackbar()``** を実行する時点で指定ウィンドウが存在しないときは生成されない

- トラックバーは指定したウィンドウに自動配置される

- 即値指定とコールバック指定の方法があり、即値指定の場合は、スライダの値が第三引数のvalに即渡されるので、指定時は参照渡しなので**&が必要**

- コールバック指定の場合は**NULL**を指定する

- コールバック関数指定について
  http://nodemand.hatenablog.com/entry/2016/07/03/152154

- threshold関数の2値化手法

  | 定数              | 閾値以下 | 閾値超え |
  | ----------------- | -------- | -------- |
  | THRESH_BINARY     | 0        | 最大値   |
  | THRESH_BINARY_INV | 最大値   | 0        |
  | THRESH_TRUNC      | そのまま | 閾値     |
  | THRESH_TOZERO     | 0        | そのまま |
  | THRESH_TOZERO_INV | そのまま | 0        |
  | THRESH_OTSU       |          |          |
  | THRESH_TRIANGLE   |          |          |

- 2値化閾値の自動判定

  **変化する明るさ**などに対応するようなケースで必要

  **大津アルゴリズム**、**トライアングル法**など

  ```c++
  // threshold()による閾値自動判定
  thresh = (int)threshold(xx, xx, NULL, 255, THRESH_BINARY | THRESH_OTSU)
  // return: 自動判別した閾値
  ```

- adaptiveThreshold

  適応的2値化関数
  http://opencv.jp/opencv-2.1/cpp/miscellaneous_image_transformations.html

- 

------

### 参考

- 大津アルゴリズム
  https://algorithm.joho.info/programming/python/opencv-otsu-thresholding-py/
  http://labs.eecs.tottori-u.ac.jp/sd/Member/oyamada/OpenCV/html/py_tutorials/py_imgproc/py_thresholding/py_thresholding.html
- トライアングルアルゴリズム
  https://dronebiz.net/tech/opencv/binarize
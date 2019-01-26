## cv013_MovieMiniaturizer
ROI(注目領域)によって、画像の選択した部分にミニチュア風の加工をする

---
### 使用したOpenCVのAPIについて

- **``operator()``**
  ROIのデータを抽出
  https://docs.opencv.org/3.4.3/df/dfc/classcv_1_1Mat__.html#aae6a61bc65e081d2740b7994b514fbf1

  ```C++
  Mat_ cv::Mat_< _Tp >::operator()(const Rect & roi) const
  // - roi: Rect型で指定したROI(注目領域)
  ```



- 

---
### メモ

- 通常の変数のアドレス取得
  **&** を先頭につける
- ポインタ変数に格納されているアドレス先に格納されている値を取得
  ポインタ変数の前に **＊** をつける
- 配列はそれ自体がアドレス
  配列各値は&によりアドレス取得できる
- アドレスはポインタ変数に格納する必要がある
  **＊** を変数につけて宣言する
  http://www.isc.meiji.ac.jp/~re00079/EX2.2011/20110518.html
- **ROI (注目領域)**
  特定の処理を画像全体ではなく、その部分だけに適応したい時に必要
  ※ROIが一部でも画像の外にはみ出ているとエラーになるので注意
- 

------

### 参考

- **C++でポインタのキャスト**

  [参考URL]
  http://www7b.biglobe.ne.jp/~robe/cpphtml/html02/cpp02041.html

- **void型ポインタ**

  汎用ポインタ。ポインタ型でのみ存在する特殊な型

  void* は通常の変数には存在しない

  あらゆるポインタ型に変換できるポインタ型で、どのような型も受け取れる関数を作成するのに使用

  void型のポインタを**逆参照するには必ず型キャスト**

  http://wisdom.sakura.ne.jp/programming/c/c47.html

- ポインタの参照

  http://www.isl.ne.jp/pcsp/beginC/C_Language_13.html

## cv016_ImgeChannelSeparater
カラー入力映像のチャンネルをB, G, Rに分離し、それぞれの色で表示する

---
### 使用したOpenCVのAPIについて

- **``split()``**
  画像のチャンネル分離
  https://docs.opencv.org/3.4.3/d2/de8/group__core__array.html#ga0547c7fed86152d7e9d0096029c8518a

  ```C++
  void cv::split(const Mat & src, Mat * mvbegin)
  // - src: 入力画像（マルチチャンネル）
  // 入力画像にアルファチャンネルが含まれているときはvectorは4要素
  // - mvbegin: 出力画像の配列（あるいはvector）。配列サイズは必要に応じて動的に再割り当てされる
  ```




- **``merge()``**
  1チャンネル画像からマルチチャンネル画像を合成
  https://docs.opencv.org/3.4.3/d2/de8/group__core__array.html#ga61f2f2bde4a0a0154b2333ea504fab1d

  ```C++
  void cv::merge(InputArrayOfArrays mv, OutputArray dst)
  // - mv: 合成元の入力画像配列（BGRアルファの順）
  // - dst: 合成後の出力画像
  ```




- **``mean()``**
  ピクセル値の平均をチャンネル単位で計算
  https://docs.opencv.org/3.4.3/d2/de8/group__core__array.html#ga191389f8a0e58180bb13a727782cd461

  ```C++
  Scalar cv::mean(InputArray src, InputArray mask = noArray())
  // - src: 計算対象となる1～4チャンネルの入力配列
  // - mask: マスク画像
  // return: Scalar
  // 計算結果をScalar型の（BGRアルファの順）で返す
  // 入力画像が3チャンネルでも、アルファチャンネル付きの4要素で返されるので注意
  ```



- **``minMaxLoc()``**
  画像内の最小／最大値およびその座標を取得
  https://docs.opencv.org/3.4.3/d2/de8/group__core__array.html#gab473bf2eb6d14ff97e89b355dac20707

  ```C++
  void cv::minMaxLoc(InputArray src, double * minVal, double * maxVal = 0, Point * minLoc = 0, Point * maxLoc = 0, InputArray mask = noArray())
  // - src: 計算対象となる1～4チャンネルの入力配列
  // - minVal: 最小値へのポインタ（必要のない場合はNULLを指定）
  // - maxVal: 最大値へのポインタ（必要のない場合はNULLを指定）
  // - minLoc: 最小値の座標値へのポインタ（必要のない場合はNULLを指定）
  // - maxLoc: 最大値の座標値へのポインタ（必要のない場合はNULLを指定）
  // - mask: 最小値へのポインタ（必要のない場合はNULLを指定）
  // 引数はアドレス渡し
  
  ```




- 

---
### メモ

- **``meanStdDev()``**
  平均値と標準偏差を同時に計算する関数
  https://docs.opencv.org/3.4.3/d2/de8/group__core__array.html#ga846c858f4004d59493d7c6a4354b301d
- 

------

### 参考

- 

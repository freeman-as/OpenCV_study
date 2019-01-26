## cv014_ProjectiveTransformation
マウスクリックで頂点を操作した領域を射影変換して表示する

---
### 使用したOpenCVのAPIについて

- **``Point2f``**
  2次元座標(浮動小数点型)を扱うクラス
  https://docs.opencv.org/3.4.3/dc/d84/group__core__basic.html#ga7d080aa40de011e4410bca63385ffe2a

  ```C++
  typedef Point_<float> cv::Point2f
  // xとyをメンバ変数に持ち、2次元の点(float型)を表現するのに使用
  
  // コンストラクタ
  Point2f(float x, float y)
  // return: Point2f
  // 格納された座標をPoint2f型で返す
  ```




- **``norm()``**
  ベクトルの長さを算出する
  https://docs.opencv.org/3.4.3/dc/d84/group__core__basic.html#ga4e556cb8ad35a643a1ea66e035711bb9

  ```C++
  static double cv::norm(const Matx< _Tp, m, n > & M)
  double norm(const Mat& src1, int normType=NORM_L2)
  
  norm(Point v)
  // return: double
  // ベクトルの長さを返す
  // ベクトルv(x, y)の長さを算出する
  ```




- **``getPerspctiveTransform()``**
  射影変換行列の取得
  https://docs.opencv.org/3.4.3/da/d54/group__imgproc__transform.html#ga15302cbff82bdcddb70158a58b73d981

  ```C++
  Mat cv::getPerspectiveTransform(InputArray src, InputArray dst)
  // - src: 入力画像内の変換元四角形4点の座標
  // - dst: 出力画像内の変換先四角形4点の座標
  // return: Mat
  // 3x3射影変換行列を返す
  ```



- **``warpPerspective()``**
  画像の射影変換
  https://docs.opencv.org/3.4.3/dc/d84/group__core__basic.html#ga7d080aa40de011e4410bca63385ffe2a

  ```C++
  void cv::warpPerspective(InputArray src, OutputArray dst, InputArray M, Size dsize, int flags = INTER_LINEAR, int borderMode = BORDER_CONSTANT, const Scalar & borderValue = Scalar())
  ```

  | 引数        | 説明                                                         |
  | ----------- | ------------------------------------------------------------ |
  | src         | 入力画像                                                     |
  | dst         | 出力画像                                                     |
  | M           | 3x3射影変換行列                                              |
  | dsize       | 出力画像Size(幅、高さ)                                       |
  | flags       | ピクセル補間方法。INTER_NEAREST(デフォルト)またはINTER_LINEARが利用可能。WARP_INVERSE_MAPをORで指定すると、Mをdstからsrcへの逆変換行列としてセット |
  | borderMode  | 画像範囲内のピクセル値の外挿方法を指定。デフォルトはBORDER_CONSTANT |
  | borderValue | borderModeがBORDER_CONSTANTの時、ピクセル値をScalar(B,G,R)で指定。デフォルトは黒 |




- 

---
### メモ

- **射影変換**
  3次元空間にある平面Pの座標系を平面P'(別の)座標系に変換する操作
  ある平面を別の平面から透かしてみたときにそれぞれの座標点を対応付けるので**透視投影変換**ともいう
  射影変換を用いれば、傾いたり奥に歪んだり映ったりしている画像を正面からの見え方に補正できる
- **射影変換行列**
  射影変換を行う行列操作
- **cv::Matx** クラス
  https://docs.opencv.org/3.4/de/de1/classcv_1_1Matx.html
  http://pukulab.blog.fc2.com/blog-entry-45.html
- InterpolationFlags
  nonounounuo
  https://docs.opencv.org/3.4.3/da/d54/group__imgproc__transform.html#ga5bb5a1fea74ea38e1a5445ca803ff121
- **INTER_NEAREST**
  最近傍補間
  https://algorithm.joho.info/image-processing/nearest-neighbor-linear-interpolation/
- **INTER_LINEAR**
  バイリニア補間
  https://algorithm.joho.info/image-processing/bi-linear-interpolation/
- 

------

### 参考

- **cv::Matの基本**
  http://opencv.jp/cookbook/opencv_mat.html

- 射影変換
  http://marupeke296.com/DXG_No70_perspective.html
  http://wildpie.hatenablog.com/entry/20141112/1415802846
  https://qiita.com/mix_dvd/items/5674f26af467098842f0
  https://www58.atwiki.jp/dooooornob/pages/43.html

- **Geometric Image Transformations**

  Enumerations
  https://docs.opencv.org/3.3.0/da/d54/group__imgproc__transform.html

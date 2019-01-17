## cv009_GraphicsDrawing
Matオブジェクト上にグラフィックを描画する

---
### 使用したOpenCVのAPIについて

- **line**
  2点を結ぶ線の描画
  https://docs.opencv.org/3.4.3/d6/d6e/group__imgproc__draw.html#ga7078a9fae8c7e7d13d24dac2520ae4a2

  ```C++
  void cv::line(InputOutputArray img, Point pt1, Point pt2, const Scalar & color, int thickness = 1, int lineType = LINE_8, int shift = 0)
  // - pt1: 線の始点座標
  // - pt2: 線の終点座標
  // - thickness: 線の太さ(デフォルト: 1ピクセル)
  // - lineType: 線の描画方法(デフォルト: 8連結)
  // - shift: 点座標の小数点以下のビット数(デフォルト: 0)
  ```




- **Point**
  2次元座標(整数型)を扱うクラス
  https://docs.opencv.org/3.4.3/db/d4e/classcv_1_1Point__.html

  ```C++
  Point cv::Point(int x, int y)
  // xとyをメンバ変数に持ち、2次元の点(整数型)を表現
  // - return: Point
  // 格納された座標をPoint型で返す
  ```



- **arrowedLine**
  矢印の描画
  https://docs.opencv.org/3.4.3/d6/d6e/group__imgproc__draw.html#ga0a165a3ca093fd488ac709fdf10c05b2

  ```C++
  void cv::arrowedLine(InputOutputArray img, Point pt1, Point pt2, const Scalar & color, int thickness = 1, int lineType = LINE_8, int shift = 0, double tipLength = 0.1)
  // - pt1: 矢印の始点座標
  // - pt2: 矢印の終点座標
  // - thickness: 線の太さ(デフォルト: 1ピクセル)
  // - lineType: 線の描画方法(デフォルト: 8連結)
  // - shift: 点座標の小数点以下のビット数(デフォルト: 0)
  // - tipLength: 矢じりの長さを矢全体の長さの割合(デフォルト: 0.1)で指定
  ```



- **rectangle**
  長方形の描画
  https://docs.opencv.org/3.4.3/d6/d6e/group__imgproc__draw.html#ga07d2f74cadcf8e305e810ce8eed13bc9

  ```C++
  void cv::rectangle(InputOutputArray img, Point pt1, Point pt2, const Scalar & color, int thickness = 1, int lineType = LINE_8, int shift = 0)
  // - pt1: 長方形の1点目の角の座標
  // - pt2: 長方形の2点目の角(1点目の対角)の座標
  // - thickness: 線の太さ(デフォルト: 1ピクセル)。FIELD(-1)を指定すると内部の塗りつぶし
  // - lineType: 線の描画方法(デフォルト: 8連結)
  // - shift: 点座標の小数点以下のビット数(デフォルト: 0)
  ```



- **Rect**
  長方形の指定(左上頂点と幅、高さで指定)
  https://docs.opencv.org/3.4.3/d2/d44/classcv_1_1Rect__.html

  ```C++
  Rect cv::Rect(int x, int y, int width, int height)
  // - x: 長方形の左上頂点のx座標
  // - y: 長方形の左上頂点のy座標
  // - return: Rect
  // 指定された長方形の情報をRect型で返す
  ```



- **fillConvexPoly**
  塗りつぶしたポリゴンの描画
  https://docs.opencv.org/3.4.3/d6/d6e/group__imgproc__draw.html#ga9bb982be9d641dc51edd5e8ae3624e1f

  ```C++
  void cv::fillConvexPoly(InputOutputArray img, InputArrayOfArrays pts, const Scalar & color, int lineType = LINE_8, int shift = 0, Point offset = Point())
  // - pts: ポリゴンの各頂点の座標
  // Point型のvectorコンテナを渡す - vector<Point>
  // - offset: 全頂点のオフセット(デフォルト: Point(0, 0))
  // すべての頂点を指定の量だけ平行移動(オフセット)する
  ```



- **polylines**
  折れ線や多角形の描画
  https://docs.opencv.org/3.4.3/d6/d6e/group__imgproc__draw.html#gaa3c25f9fb764b6bef791bf034f6e26f5

  ```C++
  void cv::polylines(InputOutputArray img, InputArrayOfArrays pts, bool isClosed, const Scalar & color, int thickness = 1, int lineType = LINE_8, int shift = 0)
  // - pts: ポリゴンの各頂点の座標
  // Point型のvectorコンテナを渡す - vector<Point>
  // - isClosed: 線を閉じる(true), 閉じない(false)。閉じた場合は最初と最後の点を結ぶ
  ```



- **circle**
  円の描画
  https://docs.opencv.org/3.4.3/d6/d6e/group__imgproc__draw.html#gaf10604b069374903dbd0f0488cb43670

  ```C++
  void cv::circle(InputOutputArray img, Point center, int radius, const Scalar & color, int thickness = 1, int lineType = LINE_8, int shift = 0)
  // - center: 円の中心座標
  // - radius: 円の半径
  // - thickness: 円の線の太さ(デフォルト: 1ピクセル)。FIELD(-1)を指定すると内部の塗りつぶし
  ```



- **ellipse**
  円の描画
  https://docs.opencv.org/3.4.3/d6/d6e/group__imgproc__draw.html#ga28b2267d35786f5f890ca167236cbc69

  ```C++
  void cv::ellipse(InputOutputArray img, Point center, Size axes, double angle, double startAngle, double endAngle, const Scalar & color, int thickness = 1, int lineType = LINE_8, int shift = 0)
  // - center: 楕円の中心座標
  // - axes: 楕円の無回転時の水平方向半径と垂直方向半径をSize型で指定
  // - angle: 楕円の回転角(単位は度)
  // - startAngle: 楕円の開始角(単位は度)
  // - endAngle: 楕円の終了角(単位は度)
  // - thickness: 楕円の線の太さ(デフォルト: 1ピクセル)。FIELD(-1)を指定すると内部の塗りつぶし
  ```



- **putText**
  文字列の描画
  https://docs.opencv.org/3.4.3/d6/d6e/group__imgproc__draw.html#ga28b2267d35786f5f890ca167236cbc69

  ```C++
  void cv::putText(InputOutputArray img, const String & text, Point org, int fontFace, double fontScale, Scalar color, int thickness = 1, int lineType = LINE_8, bool bottomLeftOrigin = false)
  // - text: 描画する文字列
  // - org: 文字列左端の左下の座標
  // - fontFace: フォント種別
  // - fontScale: 文字列の大きさを1.0を基準とした割合で指定
  // - thickness: 文字列の太さ(デフォルト: 1ピクセル)
  // - bottomLeftOrigin: trueを指定すると文字列を上下反転(デフォルト: false)
  ```




- 

---
### メモ

- 線描画方法

  | 線の種類(lineType) | 値   | 方法                         |
  | ------------------ | ---- | ---------------------------- |
  | LINE_4             | 4    | 4連結(Bresenhamアルゴリズム) |
  | LINE_8             | 8    | 8連結(デフォルトの線種)      |
  | LINE_AA            | 16   | アンチエイリアス             |

- 画像処理では、ピクセルとピクセルの間に**サブピクセル**と呼ばれる仮想的なピクセルを考えることで、計算精度を高める手法がある。

- **push_back()**
  vectorのメンバ関数で、配列末尾に要素を追加

- **pop_back()**
  vectorのメンバ関数で、配列末尾の要素を削除

- **size()**
  現在の要素数の取得

------

### 参考

- **vectorコンテナ**

  https://cpprefjp.github.io/reference/vector.html

  https://ja.cppreference.com/w/cpp/container/vector
  http://vivi.dyndns.org/tech/cpp/vector.html
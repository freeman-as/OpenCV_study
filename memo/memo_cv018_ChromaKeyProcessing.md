## cv018_ChromaKeyProcessing
色相範囲から指定したグレースケールマスク画像を生成して、背景画像とクロマキー合成

---
### 使用したOpenCVのAPIについて

- **``morphologyEx()``**
  画像の各種モルフォロジー演算、open処理やclose処理を行う
  https://docs.opencv.org/3.4.3/d4/d86/group__imgproc__filter.html#ga67493776e3ad1a3df63883829375201f

  ```C++
  void cv::morphologyEx(InputArray src, OutputArray dst, int op, InputArray kernel, Point anchor = Point(-1,-1), int iterations = 1, int borderMode = BORDER_CONSTANT, const Scalar & borderValue = morphologyDefaultBorderValue())
  // - op: 基本的に使用するのはMORPH_OPEN, MORPH_CLOSE
  // - kernel: erode/dilateと同じ構造要素を指定
  ```

  | 引数        | 説明                                                         |
  | ----------- | ------------------------------------------------------------ |
  | src         | 入力画像                                                     |
  | dst         | 出力画像                                                     |
  | op          | モルフォロジー演算の方法                                     |
  | kernel      | 構造要素                                                     |
  | anchor      | アンカー位置(X, Y)を指定する。デフォルト値の(-1, -1)は中心を表す |
  | iterations  | 処理回数                                                     |
  | borderMode  | 画像範囲外のピクセル値の外挿方法を指定                       |
  | borderValue | borderModeがBORDER_CONSTANTのとき、ピクセル値をScalar(B, G, R)で指定する。デフォルト値は処理に応じて自動計算される |




- 

---
### メモ

- **クロマキー合成**
  スタジオで撮影した人物像を別に撮影した背景映像に埋め込むことで、その背景中にあたかも人物が存在するかのような特殊な演出のことで、
  均質な背景色の前で前景を撮影した上で背景を透明にし、この映像を背景映像と合成することで行う
  背景には**緑**が使われることが多い
- 背景にする「緑」は<u>純粋な緑以外の成分が混入してくる</u>ので、BGRカラーのGチャンネルだと適切に分離するのが難しいので、**HSV**に変換してから処理する
- **マスク画像**
  関数の操作が影響を及ぼす範囲を限定する時に使用
  マスク画像のピクセル値が0ならその位置に対応する画像のピクセルに関数が影響しない
  通常1チャンネル符号なし8ビット (**CV_8UC1**)のMatオブジェクトを使う
- モルフォロジー演算
  **erode処理**
  注目領域の中の最小値で注目画素を置き換えることで、物体を収縮させる
  https://algorithm.joho.info/programming/python/opencv-dilate-erode-py/
- 入力画像にあるノイズが比較的大きいときは、処理回数を適当に増やしノイズを除去する
  **open処理かclose処理かは除去したいノイズが白か黒かによる**
- モルフォロジー演算方法指定定数
  **``morphologyEx()``**の第3引数に指定する
  https://docs.opencv.org/3.4.3/d4/d86/group__imgproc__filter.html#ga7be549266bad7b2e6a04db49827f9f32
- 

------

### 参考

- モルフォロジー演算
  **open処理**
  erode処理に続いて、dilate処理を行う
  縮退→膨張させるので、白と黒の総面積は最終的には元画像とだいたい同じになる
  erodeによっていったん消去された微小領域がdilateによって復活しないので、同じ形状を保ったまま白の微小領域をなくす、つまりノイズ除去ができる
  **close処理**
  膨張させてから縮小させるので、黒の微小領域がなくなる
  白い領域中に黒い微小な穴のようなノイズがあれば膨張で穴を埋めることができ、再度縮小しても穴が復活することはない
  http://labs.eecs.tottori-u.ac.jp/sd/Member/oyamada/OpenCV/html/py_tutorials/py_imgproc/py_morphological_ops/py_morphological_ops.html
- マクベスチャート
  色校正用の色チャート
  マスク映像や合成結果を見ながら、パラメーターの調整に使う
- 
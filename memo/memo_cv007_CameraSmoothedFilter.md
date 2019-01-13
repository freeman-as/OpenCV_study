## cv007_CameraSmoothedFilter
`` GaussianBlur()``, ``blur()`` など平滑化関数を用いて、取得したカメラ映像の平滑化処理と保存

---
### 使用したOpenCVのAPIについて

- **GaussianBlur**
  画像の平滑化（ガウシアン）

  https://docs.opencv.org/3.4.3/d4/d86/group__imgproc__filter.html#gaabe8c836e97159a9193fb0b11ac52cf1

  ```C++
  void cv::GaussanBlur(InputArray src, OutputArray dst, Size ksize, double sigmaX, double sigmaY = 0, int borderType = BORDER_DEFUALT)
  // - ksize: サイズが大きいほど平滑化（ぼけ）の度合いが強くなる
  // - sigmaX, sigmaY: 標準偏差の値を大きくすれば、広範囲にぼやけた画像になる
  ```

  | 引数       | 説明                                                         |
  | ---------- | ------------------------------------------------------------ |
  | src        | 入力画像                                                     |
  | dst        | 出力画像                                                     |
  | ksize      | 平滑化フィルタサイズSize(幅, 高さ)を**奇数**で指定する。値が大きいほど強く平滑化される |
  | sigmaX     | ガウシアン平滑化における標準偏差(X軸)。値が大きいほど強く平滑化される |
  | sigmaY     | ガウシアン平滑化における標準偏差(Y軸)。0の場合はSigmaXと同じ値が適用される |
  | borderType | 画像の外側のピクセルを推定する方法を指定                     |




- **resize**
  画像の拡大縮小

  https://docs.opencv.org/3.4.3/da/d54/group__imgproc__transform.html#ga47a974309e9102f5f08231edc7e7529d

  ```C++
  void cv::resize(InputArray src, OutputArray dst, Size dsize, double fx = 0, double fy = 0, int interpolation = INTER_LINEAR)
  // dsize: 出力画像サイズSize(幅, 高さ)を指定。これが(0, 0)のときは、幅は第4引数x第1引数の元画像の幅、高さは第5引数x元の高さから算出される
  // fx: X方向の倍率(オプション)
  // fy: Y方向の倍率(オプション)
  // interpolation: 補間方法を指定する
  ```



- **blur**
  画像の平滑化（移動平均平滑化）

  https://docs.opencv.org/3.4.3/d4/d86/group__imgproc__filter.html#ga8c45db9afe636703801b0b2e440fce37

  ```C++
  void cv::blur(InputArray src, OutputArray dst, Size ksize, Point anchor = Point(-1, -1), int borderType = BORDER_DEFUALT)
  // - ksize: 値が大きいほど強く平滑化
  // - anchor: ksizeの矩形内の平均値を、矩形の中のどの位置のピクセルで置き換えるかを指定する
  ```

  | 引数       | 説明                                                         |
  | ---------- | ------------------------------------------------------------ |
  | src        | 入力画像                                                     |
  | dst        | 出力画像                                                     |
  | ksize      | 平滑化フィルタサイズSize(幅, 高さ)を指定。**偶数**での指定も可能 |
  | anchor     | アンカー位置(X, Y)をPoint型で指定。デフォルト値の(-1, -1)はksizeの中心を表す |
  | borderType | 画像の外側のピクセルを推定する方法を指定                     |




- 

---
### メモ

- 外挿(extrapolation)

  すでにある値から未知の値を推定すること

  ※例えば最も外側にあるピクセルの周辺情報を取得するときなど

- **平滑化**とは

  飛びぬけて明るいところや暗いところを近隣のピクセル値に近づけることで、輝度の変化を滑らかにする処理のこと。画像のノイズを削減したり、物体表面のキメをぼかして綺麗にみせることなどが可能

- その他の平滑化関数

  - medianBlur()：
  - bilateraFilter()：
  - edgePreservingFilter()：

- **resize() 使用時の注意**

  倍率を指定する場合は、第3引数にはデフォルト指定がないので、**明示的に(0, 0)を指定**する

  それ以外の値が指定された時は倍率は無視される

- 画像拡大について

  隙間なく並べていたピクセル同士に間をあけて、そのピクセルに適当な値を入れる処理をする

  最も単純な方法は**間の前後のピクセルの平均値**を取る

- 画像拡大縮小時のピクセル補間方法（アルゴリズム）

  | ピクセル補間定数 | 方法                                                 |
  | ---------------- | ---------------------------------------------------- |
  | INTER_NEAREST    | 最近傍補間                                           |
  | INTER_LINEAR     | バイリニア補間（デフォルト）※ 処理速度早い           |
  | INTER_AREA       | ピクセル領域関係を利用したリサンプリング ※縮小に最適 |
  | INTER_CUBIC      | バイキュービック補間 ※拡大に最適だが処理速度遅い     |
  | INTER_LANCZOS4   | Lanczos 補間                                         |

- **blur() 使用時の注意**

  アンカー位置は矩形内になければいけないので、第3引数よりも小さくなければいけない

---
### 参考

- 画像の**平滑化関数**について

  [OpenCVを使った画像処理]
  http://lang.sist.chukyo-u.ac.jp/classes/OpenCV/py_tutorials/py_imgproc/py_table_of_contents_imgproc/py_table_of_contents_imgproc.html

  http://lang.sist.chukyo-u.ac.jp/classes/OpenCV/py_tutorials/py_imgproc/py_filtering/py_filtering.html#filtering(Python)

  http://ishidate.my.coocan.jp/opencv_6/opencv_6.htm(C++)

  https://qiita.com/ankomotch/items/74884b0ca24b739159c0

- リサイズの補間アルゴリズム

  https://qiita.com/yoya/items/b1590de289b623f18639

  http://opencv.jp/sample/sampling_and_geometricaltransforms.html

  http://opencv.jp/cookbook/opencv_img.html

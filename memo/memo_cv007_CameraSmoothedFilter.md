## cv007_CameraSmoothedFilter
`` GaussianBlur()``, ``blur()`` など平滑化関数を用いて、取得したカメラ映像の平滑化処理と保存

---
### 使用したOpenCVのAPIについて

- **GaussianBlur**
  画像の平滑化（ガウシアン）

  ```C++
  GaussanBlur(InputArray src, OutputArray dst, Size ksize, double sigmaX, double sigmaY = 0, int borderType = BORDER_DEFUALT)
  // - ksize: サイズが大きいほど平滑化（ぼけ）の度合いが強くなります
  // - sigmaX, sigmaY: 標準偏差の値を大きくすれば、広範囲にぼやけた画像が得られます
  ```

  | 引数       | 説明                                                         |
  | ---------- | ------------------------------------------------------------ |
  | src        | 入力画像                                                     |
  | dst        | 出力画像                                                     |
  | ksize      | 平滑化フィルタサイズSize(幅, 高さ)を**奇数**で指定する。値が大きいほど強く平滑化される |
  | sigmaX     | ガウシアン平滑化における標準偏差(X軸)。値が大きいほど強く平滑化される |
  | sigmaY     | ガウシアン平滑化における標準偏差(Y軸)。0の場合はSigmaXと同じ値が適用される |
  | borderType | 画像の外側のピクセルを推定する方法を指定                     |




- 画像の拡大縮小

  ```C++
  resize(InputArray src, OutputArray dst, Size dsize, double fx = 0, double fy = 0, int interpolation = INTER_LINEAR)
  // dsize: 出力画像サイズSize(幅, 高さ)を指定。これが(0, 0)のときは、幅は第4引数x第1引数の元画像の幅、高さは第5引数x元の高さから算出される
  // fx: X方向の倍率(オプション)
  // fy: Y方向の倍率(オプション)
  // interpolation: 補間方法を指定する
  ```



- **GaussianBlur**
  画像の平滑化（ガウシアン）

  ```C++
  GaussanBlur(InputArray src, OutputArray dst, Size ksize, double sigmaX, double sigmaY = 0, int borderType = BORDER_DEFUALT)
  // - ksize: サイズが大きいほど平滑化（ぼけ）の度合いが強くなります
  // - sigmaX, sigmaY: 標準偏差の値を大きくすれば、広範囲にぼやけた画像が得られます
  ```

  | 引数       | 説明                                                         |
  | ---------- | ------------------------------------------------------------ |
  | src        | 入力画像                                                     |
  | dst        | 出力画像                                                     |
  | ksize      | 平滑化フィルタサイズSize(幅, 高さ)を**奇数**で指定する。値が大きいほど強く平滑化される |
  | sigmaX     | ガウシアン平滑化における標準偏差(X軸)。値が大きいほど強く平滑化される |
  | sigmaY     | ガウシアン平滑化における標準偏差(Y軸)。0の場合はSigmaXと同じ値が適用される |
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

- 


---
### 参考

- 画像の**平滑化関数**について

  [OpenCVを使った画像処理]
  http://lang.sist.chukyo-u.ac.jp/classes/OpenCV/py_tutorials/py_imgproc/py_table_of_contents_imgproc/py_table_of_contents_imgproc.html

  http://lang.sist.chukyo-u.ac.jp/classes/OpenCV/py_tutorials/py_imgproc/py_filtering/py_filtering.html#filtering(Python)

  http://ishidate.my.coocan.jp/opencv_6/opencv_6.htm(C++)

  https://qiita.com/ankomotch/items/74884b0ca24b739159c0


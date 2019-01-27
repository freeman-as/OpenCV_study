## cv015_MorphologicalOperation
プロジェクトの説明

---
### 使用したOpenCVのAPIについて

- **``getTickFrequency()``**
  1秒あたりのtick数を返す
  https://docs.opencv.org/3.4.3/db/de0/group__core__utils.html#ga705441a9ef01f47acdc55d87fbe5090c

  ```C++
  double cv::getTickFrequency()
  ```




- **``getTickCount()``**
  その時点のtick数を返す
  https://docs.opencv.org/3.4.3/db/de0/group__core__utils.html#gae73f58000611a1af25dd36d496bf4487

  ```C++
  int64 cv::getTickCount()
  // ある時刻（たとえばシステム起動時）からのtick数を返す
  ```

  | 引数     | 説明                                                         |
  | -------- | ------------------------------------------------------------ |
  | filename | 書き出すファイル名                                           |
  | flags    | コーデックを指定するための関数の戻り値で指定（4つの文字を引数渡して取得） |



- **``dilate()``**
  画像のdilate(膨張)処理
  https://docs.opencv.org/3.4.3/d4/d86/group__imgproc__filter.html#ga4ff0f3318642c4f469d0e11f242f3b6c

  ```C++
  void cv::dilate(InputArray src, OutputArray dst, InputArray kernel, Point anchor = Point(-1,-1), int iterations = 1, int borderType = BORDER_CONSTANT, const Scalar & borderValue = morphologyDefaultBorderValue())
  ```

  | 引数        | 説明                                                         |
  | ----------- | ------------------------------------------------------------ |
  | src         | 入力画像                                                     |
  | dst         | 出力画像                                                     |
  | kernel      | 注目領域の形状。デフォルトの3x3の場合はnoArray()を指定       |
  | anchor      | アンカー位置(x, y)を指定。デフォルト値の(-1, 1)は中心を表す  |
  | iterations  | 処理回数。デフォルトは1回                                    |
  | borderMode  | 画像範囲外のピクセル値の外挿方法を指定。デフォルトはBORDER_CONSTANT |
  | borderValue | borderModeがBORDER_CONSTANTのとき、ピクセル値をScalar(B, G, R)で指定。デフォルト値は処理に応じて自動計算される |




- 

---
### メモ

- **tick**
  PC (OS) がCPUクロックと同期して、基準時刻 (PC起動時など) から一定間隔でカウントしている数

- **周期**：処理1回あたりの時間
  周期 (ms) = (処理終了時tick数  - 処理開始時tick数) / (単位時間のCPU tick数 / 1000ms)

- **周波数**：単位時間当たりの処理回数
  周波数 (fps) = 1000ms / 周期 (ms)

  二値化するthreshold関数には1チャンネル画像を渡す必要があるため

- **dilate(膨張)処理**
  3x3ピクセルの注目領域(カーネル)を平行移動させながら、注目領域内の9箇所のピクセルの最大値(相対的に明るい画素値)を注目領域の中央ピクセル値として記録していく処理
  元々の白の物体は少し膨らむ
  細線を削除したり前景に混じったノイズを削除するなどの効果がある

  https://algorithm.joho.info/image-processing/dilation-erosion-opening-closing-tophat-blackhat/
  http://labs.eecs.tottori-u.ac.jp/sd/Member/oyamada/OpenCV/html/py_tutorials/py_imgproc/py_morphological_ops/py_morphological_ops.html#dilation

- **構造要素**
  引数で指定する注目領域の指定のことで、デフォルトは3x3で注目画素中心の周囲8ピクセルを計算対象にするので、**8近傍**という
  上下左右の4ピクセルを計算対象とすることを、**4近傍**という

- 

------

### 参考

- **モルフォロジ処理**
  http://www.clg.niigata-u.ac.jp/~medimg/practice_medical_imaging/imgproc_scion/7binarize/index.htm
- **``morphologyEx()``**
  https://docs.opencv.org/3.4.3/d4/d86/group__imgproc__filter.html#ga67493776e3ad1a3df63883829375201f
  **``erode()``**
  https://docs.opencv.org/3.4.3/d4/d86/group__imgproc__filter.html#gaeb1e0c1033e3f6b891a25d0511362aeb
  **モルフォロジー変換**
  http://labs.eecs.tottori-u.ac.jp/sd/Member/oyamada/OpenCV/html/py_tutorials/py_imgproc/py_morphological_ops/py_morphological_ops.html
- 
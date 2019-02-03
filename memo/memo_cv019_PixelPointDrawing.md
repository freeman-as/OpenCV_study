## cv019_PixelPointDrawing
プロジェクトの説明

---
### 使用したOpenCVのAPIについて

- **``imread()``**
  画像の読み込み
  https://docs.opencv.org/3.4.3/d4/da8/group__imgcodecs.html#ga288b8b3da0892bd651fce07b3bbd3a56

  ```C++
  Mat cv::imread(const String & filename, int flags = IMREAD_COLOR)	
  // - filename: 
  // - flags: 
  ```

  | 引数     | 説明                                                         |
  | -------- | ------------------------------------------------------------ |
  | filename | 書き出すファイル名                                           |
  | flags    | コーデックを指定するための関数の戻り値で指定（4つの文字を引数渡して取得） |



- **``imread()``**
  画像の読み込み
  https://docs.opencv.org/3.4.3/d4/da8/group__imgcodecs.html#ga288b8b3da0892bd651fce07b3bbd3a56

  ```C++
  Mat cv::imread(const String & filename, int flags = IMREAD_COLOR)	
  // - filename: 
  // - flags: 
  ```

  | 引数     | 説明                                                         |
  | -------- | ------------------------------------------------------------ |
  | filename | 書き出すファイル名                                           |
  | flags    | コーデックを指定するための関数の戻り値で指定（4つの文字を引数渡して取得） |




- FOURCCコーデックの指定

  ```C++
  // 識別子を4個の文字に分解して指定して呼び出す
  // 静的メソッド
  VideoWriter::fourcc(char c1, char c2, char c3, char c4)
  // return: static int
  // 指定した文字列に対応するコードを返す
  ```




- 

---
### メモ

- 二値化するには**グレースケール化**して、**1チャンネル画像**に変換する必要がある

  二値化するthreshold関数には1チャンネル画像を渡す必要があるため

- **FOURCC**(four characters code) ビデオコーデック識別子
  http://fourcc.org/

  各文字を逆順にして、ASCIIコード順に連結する

  ※MPEGの場合、GEPMにしたものをASCIIコード化

- 

------

### 参考

- 二値化するには**グレースケール化**して、**1チャンネル画像**に変換する必要がある

  二値化するthreshold関数には1チャンネル画像を渡す必要があるため

- **フレームを映像に書き込み時の演算子(<<)はC++のオーバーロードで拡張されてる**

  **C++で演算子のオーバーロード**

  [参考URL]
  https://qiita.com/ouchiminh/items/71b0348215695f443a62
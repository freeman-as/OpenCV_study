## cv004_VideoCapture
OpenCVでのビデオファイルの読込と表示

---
### 使用したOpenCVのAPIについて

- ビデオファイルを開く

  ```C++
  // コンストラクタ
  // VideoCaptureオブジェクト生成
  VideoCapture::VideoCapture(const string &filename)
  // open関数でも開ける
  VideoCapture cap;
  cap.open("filename");
  ```

- ビデオキャプチャの初期状態を調べる

  ```C++
  VideoCapture::isOpened()
  // return: bool
  // 正常に開けていればtrue
  ```



- 映像からフレーム取得

  ```C++
  // 出力演算子(>>)を使用
  // VideoCaptureオブジェクトから1フレーム取得してMatオブジェクトに格納
  VideoCature >> Mat
  ```

- 

---
### メモ

- **ESCキー**で終了

- **ファイルオープン失敗時エラー**

- **ビデオファイル非対応時エラー**

- **映像からフレーム取得時の演算子(>>)はC++のオーバーロードで拡張されてる**

  `` virtual VideoCapture & oprator >> (Mat &image) ``

- **C++で演算子のオーバーロード**

  [参考URL]
  https://qiita.com/ouchiminh/items/71b0348215695f443a62

- **映像表示のwhileループで待機時間指定しないと表示しない**
  待機時間が短すぎるのもダメ
- 
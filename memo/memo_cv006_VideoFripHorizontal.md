## cv006_VideoFripHorizontal
カメラからの映像を読み込んで、反転表示してウィンドウに表示する

---
### 使用したOpenCVのAPIについて

- ウィンドウの作成

  ```C++
  // ウィンドウの生成なので表示はされない
  namedWindow(const String & winname, int flags = WINDOW_AUTOSIZE)
  // - winname: ウィンドウ識別名。指定した識別名のウィンドウが存在しなければ自動生成
  // - flags: ウィンドウ操作に関わるフラグ。指定可能な値はWINDOW_NORMAL(値:0)またはWINDOW_AUTOSIZE(値:1)
  ```



- ウィンドウサイズの設定

  ```C++
  // WIDNOW_NORMALを指定して準備したウィンドウサイズを変更する
  resizeWindow(const String & winname, int width, int height)
  // - winname: サイズ変更するウィンドウ識別名
  ```



- 垂直軸／水平軸／両軸に対する画像反転

  ```C++
  // WIDNOW_NORMALを指定して準備したウィンドウサイズを変更する
  flip(InputArray src, OutputArray dst, int flipCode)
  // - dst: 入力サイズと同じサイズと形式の出力画像
  // - flipCode: 画像の反転方法
  // 0: x軸(上下反転), 1(正の値): y軸(左右反転), -1(負の値): 両軸反転
  ```




- 

---
### メモ・参考

- カメラ映像を取得するときは、カメラの**デバイス番号は通常は0**

  ※内臓と外付けを併用するなど複数のカメラが利用可能な状態だと、デバイス番号の確認が必要。順番気にせず複数カメラを使用するなら、とりあえずループの中で、デバイス番号をインクリメントすれば全部取得することで対応は可能。特定のデバイスを特定する場合参考URLが使えそう

  [参考]

  http://daily-tech.hatenablog.com/entry/2016/05/25/025616

  http://www.geekpage.jp/programming/directshow/list-capture-device.php

- ``namedWindow()`` を使うことで、プログラムによるサイズ変更やユーザーによるリサイズ許可の設定が可能になる

  ※`` imshow()`` だと自動的にMatオブジェクトのサイズに一致したウィンドウサイズで表示されリサイズできない

- WINDOW_AUTOSIZEはMatサイズに自動調整

- WINDOW_NORMALはユーザーのリサイズ操作が可能になる

- 

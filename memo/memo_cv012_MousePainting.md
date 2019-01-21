## cv012_MousePainting
マウスを動かした軌跡をキャンバスに描くだけの簡単なペイントアプリケーション

---
### 使用したOpenCVのAPIについて

- **``setMouseCallback()``**
  マウスイベントに対するコールバック関数の登録
  https://docs.opencv.org/3.4.3/d7/dfc/group__highgui.html#ga89e7806b0a616f6f1d502bd8c183ad3e

  ```C++
  void cv::setMouseCallback(const String & winname, MouseCallback onMouse, void * userdata = 0)
  // - winname: ウィンドウ識別名
  // - onMouse: マウスイベント発生時に呼び出される関数
  // - userdata: コールバック関数に渡されるユーザーデータ
  ```

  ```c++
  // コールバック関数定義
  typedef void(* cv::MouseCallback)(int event, int x, int y, int flags, void *userdata)
  // - event: マウスイベント定数
  // - x: イベント発生時のマウスのx座標
  // - y: イベント発生時のマウスのy座標
  // - flags: イベント発生時のキーコンビネーション
  ```




- 

---
### メモ

- **``setMouseCallback()``** を実行する時点で指定ウィンドウが存在しないときはウィンドウに関連付けられない

- **``waitKey()``** の引数に0を渡して実行するとキー入力があるまで待機し続ける

- **MouseEventTypes**

  コールバック内で、発生したイベントの種類を判別するためのマウスイベント定数

  https://docs.opencv.org/3.4.3/d7/dfc/group__highgui.html#ga927593befdddc7e7013602bca9b079b0

- 

------

### 参考

- 

## cv008_VideoShuffling
ランダムにビデオをシャッフリングしながら再生。ランダムに選択したフレームにジャンプして、順送りか逆順かで再生を繰り返す

---
### 使用したOpenCVのAPIについて

- **VideoCapture::get**
  ビデオキャプチャ属性の取得
  https://docs.opencv.org/3.4.3/d8/dfe/classcv_1_1VideoCapture.html#aa6480e6972ef4c00d74814ec841a2939

  ```C++
  virtual double cv::VideoCapture::get(int propId) const	
  // - propId: 取得する情報のビデオ属性ID 
  // - return: double
  // ※属性値が本来的に整数なら、int型にキャスト
  ```




- **VideoCapture::set**
  カメラ／ビデオファイルの属性値のセット
  https://docs.opencv.org/3.4.3/d8/dfe/classcv_1_1VideoCapture.html#a8c6d8c2d37505b5ca61ffd4bb54e9a7c

  ```C++
  virtual bool cv::VideoCapture::set(int propId, double value)	
  // - propId: セットする属性IDを指定 
  // - value: セットする値
  // - return: bool
  // セットに成功したかどうかを返す
  ```



- **VideoCapture::release**
  ビデオキャプチャを閉じる
  https://docs.opencv.org/3.4.3/d8/dfe/classcv_1_1VideoCapture.html#afb4ab689e553ba2c8f0fec41b9344ae6

  ```C++
  virtual void cv::VideoCapture::release()
  ```



- **VideoWriter::release**
  ビデオライタを閉じる
  https://docs.opencv.org/3.4.3/dd/d9e/classcv_1_1VideoWriter.html#a667f737e56d5ba6b0533c6c7bf941140

  ```C++
  virtual void cv::VideoWriter::release()
  ```



- **destroyWindow**
  指定したウィンドウを閉じる
  https://docs.opencv.org/3.4.3/d7/dfc/group__highgui.html#ga851ccdd6961022d1d5b4c4f255dbab34

  ```C++
  void cv::destroyWindow(const String & winname)
  ```



- **destroyAllWindows**
  すべてのウィンドウを閉じる
  https://docs.opencv.org/3.4.3/d7/dfc/group__highgui.html#ga6b7fc1c1a8960438156912027b38f481

  ```C++
  void cv::destroyAllWindows()
  ```


- 

---
### メモ

- VideoCaptureのビデオ属性ID
  https://docs.opencv.org/3.4.3/d4/d15/group__videoio__flags__base.html#gaeb8dd9c89c10a5c63c139bf7c4f5704d

  | ビデオ属性ID           | 説明 |
  | ---------------------- | ---- |
  | CAP_PROP_POS_MSEC      |      |
  | CAP_PROP_POS_FRAMES    |      |
  | CAP_PROP_POS_AVI_RATIO |      |
  | CAP_PROP_FRAME_WIDTH   |      |
  | CAP_PROP_FRAME_HEIGHT  |      |
  | CAP_PROP_FPS           |      |
  | CAP_PROP_FOURCC        |      |
  | CAP_PROP_FRAME_COUNT   |      |
  | CAP_PROP_FORMAT        |      |
  | CAP_PROP_BRIGHTNESS    |      |
  | CAP_PROP_CONTRAST      |      |
  | CAP_PROP_SATURATION    |      |
  | CAP_PROP_HUE           |      |
  | CAP_PROP_GAIN          |      |
  | CAP_PROP_EXPOSURE      |      |
  | CAP_PROP_CONVERT_RGB   |      |

- フレームレートから**フレーム間時間**を計算するには逆数を取る

  秒 ( / sec)：**1 / fps**

  ミリ秒 ( / ms)：**1000 / fps

- **rand**

  C++標準ライブラリ(std::)に含まれる疑似乱数生成
  https://ja.cppreference.com/w/cpp/numeric/random/rand

  ```C++
  // 識別子を4個の文字に分解して指定して呼び出す
  // 静的メソッド
  int std::rand(void)
  // return: int
  // 0以上RAND_MAX未満のランダムなint型の値を返す
  // RAND_MAXは、VS2017では32768(0x7FFF)
  ```

- **モジュロ演算**
  「余り算」のことで、整数のモジュロXを取ると、その値は必ず0からX-1の値になるという性質があるので、ある範囲の値に収めたい時に使用

- **min**

  指定された値の小さい方を返す。C++標準ライブラリ(std::)に含まれる関数
  https://cpprefjp.github.io/reference/algorithm/min.html
  https://ja.cppreference.com/w/cpp/algorithm/min

  ```C++
  constexpr const T& min(const T& a, const T& b)
  // return: 指定された値(a, b)のうち小さい方を返します
  ```

- **max**

  指定された値の大きい方を返す。C++標準ライブラリ(std::)に含まれる関数
  https://cpprefjp.github.io/reference/algorithm/max.html
  https://ja.cppreference.com/w/cpp/algorithm/max

  ```C++
  constexpr const T& max(const T& a, const T& b)
  // return: 指定された値(a, b)のうち大きい方を返します
  ```

- 

------

### 参考

- 

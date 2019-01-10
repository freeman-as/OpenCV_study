## cv005_VideoBinarization
ビデオファイルから読み込んだフレームを二値化処理した後に、指定のビデオファイルに書き込み

---
### 使用したOpenCVのAPIについて

- **VideoWriter**
  映像保存用のVideoWriterオブジェクト生成

  ```C++
  // コンストラクタ
  VideoWriter::VideoWriter(const string &filename, int fourcc, double fps, Size frameSize, bool isColor=true)
  // - forcc: 第二引数はビデオコーデック識別子する整数値を指定
  //   ビデオ識別子は通常「XVID」などの英数文字4文字から識別
  // - frameSize: 実際に書き込む際のサイズと一致している必要がある
  // - isColor: trueなら3チャンネルで保存（Windowsのみサポート）
  ```

  | 引数                                     | 説明                                                         |
  | ---------------------------------------- | ------------------------------------------------------------ |
  | filename                                 | 書き出すファイル名                                           |
  | fourcc                                   | コーデックを指定するための関数の戻り値で指定（4つの文字を引数渡して取得） |
  | [fps](http://d.hatena.ne.jp/keyword/fps) | 動画像のフレームレート（＝1秒あたりのフレーム数）            |
  | frameSize                                | 動画像の縦横サイズ ※書き込み用に保持したMatオブジェクトのサイズにあわせる必要がある |
  | isColor                                  | カラーの動画像ファイルとして書き出すかを指定                 |


- FOURCCコーデックの指定

  ```C++
  // 識別子を4個の文字に分解して指定して呼び出す
  // 静的メソッド
  VideoWriter::fourcc(char c1, char c2, char c3, char c4)
  // return: static int
  // 指定した文字列に対応するコードを返す
  ```



- 画像カラーモデルの変換

  ```C++
  cvtColor(InputArray src, OutputArray dst, int code, int dstCn = 0)
  // - dst: 入力と同じサイズと深度の出力画像
  // - code: 色変換方法を指示する定数 (etc. COLOR_BGR2GRAY)
  // - dstCn: 出力画像配列のチャンネル数。0の場合srcから自動的に取得
  ```



- 画像の二値化処理

  ```C++
  threshold(InputArray src, OutputArray dst, double threshold, double maxval, int type)
  // return: double
  // 用いられた閾値を返す
  // - dst: 入力と同じサイズと形式の出力画像
  // - maxval: typeにTHRESH_BINARYかBINARY_INVを指定した場合に使用される最大値
  // - type: 閾値処理のタイプ
  ```




- フレームをビデオファイルに書き込む

  ```C++
  // 挿入演算子(<<)を使用
  // VideoCaptureオブジェクトから取得した1フレーム分をMatオブジェクトとして、ビデオファイルに保存
  VideoCature << Mat
  ```

- 

---
### メモ・参考

- 二値化するには**グレースケール化**して、**1チャンネル画像**に変換する必要がある

  二値化するthreshold関数には1チャンネル画像を渡す必要があるため

- **FOURCC**(four characters code) ビデオコーデック識別子
  http://fourcc.org/

  各文字を逆順にして、ASCIIコード順に連結する

  ※MPEGの場合、GEPMにしたものをASCIIコード化

- 映像を書き込む際に指定したコーデックの書き込み用エンコーダーが環境に事前インストールされている必要がある（再生用だけでは書き込めない）

- cvtColor使用方法

  https://note.nkmk.me/python-opencv-bgr-rgb-cvtcolor/

- カラーモデル変換方法の指定定数（抜粋）

  **COLOR_BGR2GRAY**：BGR -> グレースケール

  **COLOR_GRAY2BGR**：グレースケール -> BGR

  内部的には計算式が指定されていて、

  COLOR_BGR2GRAYの変換式は

  **Y = 0.299R + 0.587G + 0.114B**

  ※単純な平均ではなくそれぞれに異なる重み係数を掛け合わせている。（ヒトの輝度に対する感度が色によって異なることを考慮しているため）

- **フレームを映像に書き込み時の演算子(<<)はC++のオーバーロードで拡張されてる**

  **C++で演算子のオーバーロード**

  [参考URL]
  https://qiita.com/ouchiminh/items/71b0348215695f443a62

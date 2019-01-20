## cv010_KeyboardLapse
キーボードを操作してカメラ映像からコマ撮り映像を作成する

---
### 使用したOpenCVのAPIについて


- 

---
### メモ

- **``stringstream()``**

  文字列操作をするストリーム(I/O)　C++標準ライブラリ(std::)のクラステンプレート

  https://ja.cppreference.com/w/cpp/io/basic_stringstream
  http://www.geocities.jp/eneces_jupiter_jp/cpp1/013-001.html

  ```C++
  stringstream ss;
  // [<<]で文字や数値を書き込む
  ss << count;
  ```

- **``stringstream::str()``**

  ストリームに格納された文字列を取り出す
  https://ja.cppreference.com/w/cpp/numeric/random/rand

  ```C++
  std::basic_string<CharT,Traits,Allocator> str() const;
  // return: string
  // ストリームに書き込まれた文字列
  ```

- 0 or 1のトグル処理
  **``x = 1 - x``** でxは0と1を繰り返す
- 

------

### 参考

- 

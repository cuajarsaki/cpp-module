# C++ Module 00 - ex00: megaphone

## 概要

この演習では、C++言語の基本的な入出力と文字列操作について学びます。「megaphone」という名前のプログラムを作成し、コマンドライン引数として受け取った文字列をすべて大文字に変換して出力します。

## 学習目標

- C++プログラムの基本構造を理解する
- 標準ライブラリ（iostream, string）の使用方法を学ぶ
- 文字列操作と型変換の基本を習得する
- コマンドライン引数の処理方法を理解する

## プログラムの仕様

1. コマンドライン引数として文字列を受け取る
2. 受け取った文字列をすべて大文字に変換
3. 変換した文字列を標準出力に表示
4. 引数がない場合は「* LOUD AND UNBEARABLE FEEDBACK NOISE *」と表示

## 使用例

```
$> ./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
$> ./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT  !  SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$> ./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

## 重要な概念

### C++の基本構造

- ヘッダファイルのインクルード: `#include <iostream>`、`#include <string>`
- 名前空間: `std::`プレフィックス
- main関数: プログラムのエントリーポイント

### 入出力

- `std::cout`: 標準出力ストリーム
- `<<`演算子: ストリーム挿入演算子
- `std::endl`: 改行とバッファのフラッシュ

### 文字列操作

- `std::string`: C++の文字列クラス
- 文字列の長さ取得: `str.length()`
- 文字へのアクセス: インデックス表記 `str[j]`

### 型変換

- `std::toupper()`: 文字を大文字に変換
- `static_cast<char>()`: 型の明示的変換

### C言語との違い

- `char*` や `char[]` ではなく `std::string` クラスを使用
- `printf` ではなく `std::cout` を使用
- 文字列操作が簡潔に記述可能


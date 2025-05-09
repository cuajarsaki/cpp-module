# C++ Module 01 - ex00: BraiiiiiiinnnzzzZ

## 概要

この演習では、C++言語でのメモリ管理とオブジェクトの生存期間について学びます。「Zombie」クラスを実装し、スタックとヒープ上に異なる方法でオブジェクトを作成することで、メモリ割り当ての違いを理解します。

## 学習目標

- C++クラスの実装方法を習得する
- スタックメモリとヒープメモリの違いを理解する
- 適切なメモリ管理（特にヒープメモリの解放）の重要性を学ぶ
- ポインタと参照の基本的な概念を理解する
- デストラクタの役割と動作を学ぶ

## プログラムの仕様

1. 以下の機能を持つZombieクラスを実装:
   - プライベートな文字列属性 `name` を持つ
   - `void announce( void )` メンバ関数を実装
   - デストラクタでデバッグメッセージを表示

2. 以下の2つの関数を実装:
   - `Zombie* newZombie( std::string name )`: ヒープ上にZombieを作成して返す
   - `void randomChump( std::string name )`: スタック上にZombieを作成し、自己紹介させる

3. 関数 `announce()` は以下の形式でメッセージを表示:
   ```
   <name>: BraiiiiiiinnnzzzZ...
   ```

## 重要な概念

### スタックメモリとヒープメモリの違い

- **スタックメモリ**:
  - 自動的に割り当てと解放が行われる
  - 関数スコープが終了すると自動的に破棄される
  - 比較的小さなオブジェクトに適している
  - 高速なメモリアクセス

- **ヒープメモリ**:
  - 明示的に割り当てと解放を行う必要がある (`new` と `delete`)
  - プログラマが解放するまでメモリが保持される
  - より大きなオブジェクトや、長期間存在するオブジェクトに適している
  - スタックに比べて若干遅いメモリアクセス

### メモリリークの防止

- ヒープ上に作成したオブジェクトは、使用後に必ず `delete` で解放する
- デストラクタが呼ばれるタイミングを理解する
- スマートポインタの概念（この課題では使用しないが重要な概念）

## 実装のヒント

1. Zombieクラスのコンストラクタで名前を初期化する
2. デストラクタでは、ゾンビの名前を含むデバッグメッセージを表示する
3. `newZombie` 関数では `new` 演算子を使用してヒープ上にZombieを割り当てる
4. `randomChump` 関数ではローカル変数としてZombieを作成する（スタック上）
5. メインプログラムでは両方の方法でZombieを作成し、その違いを観察する

## テストケース

```cpp
int main() {
    // スタック上にZombieを作成
    randomChump("Stack Zombie");
    
    // ヒープ上にZombieを作成
    Zombie* heapZombie = newZombie("Heap Zombie");
    heapZombie->announce();
    delete heapZombie; // メモリリークを防ぐために必要
    
    return 0;
}
```


## C言語との違い

- クラスと継承を使った構造化されたプログラミング
- コンストラクタとデストラクタによる自動的なリソース管理
- `malloc`/`free` の代わりに `new`/`delete` を使用
- ヘッダガードによる多重インクルードの防止
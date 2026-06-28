*This project has been created as part of the 42 curriculum by dakobaya, kasuzuki.*

# push_swap

## English Version

### Description

`push_swap` is a C program that sorts a list of integers in ascending order by using two stacks, `a` and `b`, and a limited set of stack operations.

The goal of this project is not only to implement sorting, but also to think about how to reduce the number of operations under strict constraints. It is also a practical exercise in understanding algorithmic complexity in terms of Push_swap operations. The project brings together C programming topics such as parsing, error handling, linked-list management, memory management, Makefiles, and pair programming.

The program validates the integer list received as arguments, stores the valid values in stack `a`, selects a sorting strategy, and prints the generated operation sequence to standard output, one operation per line.

### Available Instructions

| Instruction | Description |
| --- | --- |
| `sa` / `sb` | Swap the first two elements at the top of stack `a` / `b`. |
| `ss` | Execute `sa` and `sb` at the same time. |
| `pa` / `pb` | Move the top element from one stack to the top of the other stack. |
| `ra` / `rb` | Rotate stack `a` / `b` upward. The first element becomes the last one. |
| `rr` | Execute `ra` and `rb` at the same time. |
| `rra` / `rrb` | Reverse rotate stack `a` / `b`. The last element becomes the first one. |
| `rrr` | Execute `rra` and `rrb` at the same time. |

### Instructions

#### Makefile

Use the following commands to compile and clean the project.

```sh
make
```

Builds the `push_swap` executable.

```sh
make bonus
```

Builds the bonus `checker` executable.

```sh
make clean
```

Removes compiled object files.

```sh
make fclean
```

Removes object files and executables.

```sh
make re
```

Runs `fclean` and then rebuilds the project.

#### Basic Usage

```sh
./push_swap 4 67 3 87 23
./push_swap "4 67 3 87 23"
```

The first argument is treated as the top of stack `a`. If no argument is provided, the program prints nothing and exits.

If invalid arguments are provided, the program prints `Error` followed by a newline to standard error. Invalid input includes non-integer values, values outside the `int` range, and duplicate values.

```sh
./push_swap 1 2 3 2
# Error
```

#### Strategy Flags

Strategy flags must be placed before the integer list. If no strategy flag is provided, `--adaptive` is used.

```sh
./push_swap --simple 5 4 3 2 1
./push_swap --medium 4 67 3 87 23
./push_swap --complex 4 67 3 87 23
./push_swap --adaptive 4 67 3 87 23
```

| Flag | Description |
| --- | --- |
| `--simple` | Use the `O(n^2)` simple strategy. |
| `--medium` | Use the `O(n sqrt(n))` medium strategy. |
| `--complex` | Use the `O(n log n)` complex strategy. |
| `--adaptive` | Select a strategy automatically based on disorder. |

#### Benchmark Mode

When `--bench` is enabled, the normal operation sequence is printed to standard output, and the following benchmark information is printed to standard error:

- disorder value
- selected strategy name and complexity
- total number of operations
- count for each operation

```sh
./push_swap --bench --adaptive 4 67 3 87 23
```

Because the operation sequence remains on standard output, it can still be piped into the checker.

```sh
ARG="4 67 3 87 23"
./push_swap --bench --adaptive $ARG | ./checker $ARG
```

#### Random Test Example

```sh
shuf -i 0-9999 -n 500 > args.txt
./push_swap $(cat args.txt)
```

To check only the operation count:

```sh
./push_swap $(cat args.txt) | wc -l
```

#### Bonus Checker

`checker` reads operations from standard input and verifies whether the given stack is sorted correctly.

```sh
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG
```

The output is:

- `OK` if sorting succeeds
- `KO` if sorting fails
- `Error` for invalid arguments or invalid instructions

### Explanation and Justification of the Algorithms

This implementation first applies coordinate compression instead of comparing the original input values directly. For example, `2 5 8 9 20` is converted into indexes like `0 1 2 3 4` while preserving the relative order of the values. This makes it easier to handle negative numbers and large integers uniformly.

The program also computes disorder before sorting. Disorder is the ratio of inverted pairs, where an earlier value is greater than a later value, to all possible pairs.

```text
disorder = inverted_pairs / total_pairs
```

If the input is already sorted, disorder is `0`. The closer the input is to reverse order, the closer disorder gets to `1`.

#### Small Sort

For inputs of size 5 or less, the program uses a dedicated small sorter. It handles the cases of 2, 3, and up to 5 elements with a small number of swaps, rotations, and pushes. Since this is a constant-size case, it does not affect the complexity upper bound of any selected strategy.

#### Simple Strategy: Selection Extraction

`--simple`

Complexity: `O(n^2)`

The simple strategy adapts selection sort to stack operations. It searches stack `a` for the smallest index, moves it to the top with `ra` or `rra`, and pushes it to stack `b` with `pb`. This repeats until stack `a` is small enough for the small sorter, then the saved elements are pushed back with `pa`.

The scan that finds the minimum position is done in C and is not printed as Push_swap operations. However, moving the chosen element to the top can require up to about `n / 2` rotations, followed by a `pb`. Repeating this for stack sizes `n`, `n - 1`, `n - 2`, ... makes the generated operation count proportional to `n + (n - 1) + ... + 1`, so the upper bound is `O(n^2)`.

#### Medium Strategy: Chunk Sort

`--medium`

Complexity: `O(n sqrt(n))`

The medium strategy divides coordinate-compressed indexes into chunks. The chunk size is based roughly on `sqrt(n)`. For each chunk, the program searches stack `a` for values in the current range and pushes them to stack `b` with `pb`. Then it finds the maximum index in stack `b`, moves it to the top, and pushes it back to stack `a` with `pa`.

If the chunk size is `O(sqrt(n))`, the number of chunks is also `O(sqrt(n))`. For each chunk, stack `a` may be rotated while searching for target values, producing up to `O(n)` `ra` / `pb` operations. Repeating this for `O(sqrt(n))` chunks gives `O(n sqrt(n))`. Moving values back from stack `b` also stays within the same upper bound.

#### Complex Strategy: Binary Radix Sort

`--complex`

Complexity: `O(n log n)`

The complex strategy is an LSD binary radix sort over the compressed indexes. For each bit, every element in stack `a` is checked once: if the bit is `0`, the element is pushed to stack `b` with `pb`; if the bit is `1`, stack `a` is rotated with `ra`. After one pass, all elements in stack `b` are pushed back to stack `a` with `pa`.

The maximum index is `n - 1`, so the number of required bits is `log n`. For each bit, every element is processed once, and the elements pushed to stack `b` are returned with `pa`. Therefore, each bit costs at most `O(n)` Push_swap operations, and the total upper bound is `O(n log n)`.

#### Adaptive Strategy

`--adaptive`

The adaptive strategy computes disorder before sorting and selects an internal strategy according to that value.

| Disorder | Selected strategy | Complexity |
| --- | --- | --- |
| `disorder < 0.2` | simple strategy | `O(n^2)` |
| `0.2 <= disorder < 0.5` | medium strategy | `O(n sqrt(n))` |
| `disorder >= 0.5` | complex strategy | `O(n log n)` |

These thresholds follow the project requirements. Low disorder means the input is already somewhat ordered, so the simple strategy remains acceptable. Medium disorder benefits from chunk-based partitioning. High disorder uses radix sort because it is stable and less dependent on the original input order.

### Division of Labor

This project was developed as a pair project. We shared the implementation plan and algorithmic understanding while dividing the work.

- `dakobaya`: Makefile, argument parsing, error handling, stack management, small sort, simple strategy, medium strategy, benchmark mode, and bonus checker.
- `kasuzuki`: data structure design and implementation, coordinate compression, complex strategy, operation interfaces, and sorting behavior review.

Both contributors reviewed each other's parts so that both could explain the project during evaluation.

### Resources

#### References

- [Radix sort](https://algoful.com/Archive/Algorithm/RadixSort): used to understand the LSD radix sort used in the complex strategy.
- [Bit operation article](https://zenn.dev/kodyi/articles/3210f1b56c6aee): used to review bit operations.
- [Chunked sorting article](https://satyadeepmaheshwari.medium.com/sorting-large-datasets-with-limited-memory-the-chunked-merge-sort-approach-318275275c81): used as a reference for the idea of processing values in chunks.

#### Use of AI

AI was used to organize this README, check the subject requirements, explain the algorithms in writing, and identify possible edge cases. Generated content was not used blindly; it was checked against the actual implementation files.

## 日本語版

### Description

`push_swap` は、2つのスタック `a` と `b`、そして限られた命令だけを使って整数列を昇順に並べ替える C 言語のプログラムです。

この課題の目的は、単にソートを実装することではなく、限られた操作セットの中でどのように手数を減らすかを考え、アルゴリズムの計算量を Push_swap の操作数として理解することです。また、パース、エラー処理、リスト操作、メモリ管理、Makefile、ペア開発など、これまで学んだ C 言語の知識を総合的に使います。

プログラムは引数として受け取った整数列を検証し、有効な値を stack `a` に格納します。その後、選択された戦略に従って `sa`, `pb`, `ra` などの命令列を生成し、標準出力に1行ずつ表示します。

### Available Instructions

| 命令 | 内容 |
| --- | --- |
| `sa` / `sb` | stack `a` / `b` の先頭2要素を入れ替える |
| `ss` | `sa` と `sb` を同時に実行する |
| `pa` / `pb` | 一方の stack の先頭要素をもう一方の stack の先頭へ移動する |
| `ra` / `rb` | stack `a` / `b` を上方向に回転させる。先頭要素は末尾へ移動する |
| `rr` | `ra` と `rb` を同時に実行する |
| `rra` / `rrb` | stack `a` / `b` を下方向に回転させる。末尾要素は先頭へ移動する |
| `rrr` | `rra` と `rrb` を同時に実行する |

### Instructions

#### Makefile

以下のコマンドでコンパイルと削除を行います。

```sh
make
```

`push_swap` を生成します。

```sh
make bonus
```

bonus の `checker` を生成します。

```sh
make clean
```

コンパイル済みのオブジェクトファイルを削除します。

```sh
make fclean
```

オブジェクトファイルと実行ファイルを削除します。

```sh
make re
```

`fclean` の後に再コンパイルします。

#### Basic Usage

```sh
./push_swap 4 67 3 87 23
./push_swap "4 67 3 87 23"
```

最初の引数が stack `a` の先頭として扱われます。引数がない場合、プログラムは何も表示せず終了します。

無効な引数が渡された場合は、標準エラー出力に `Error` と改行を表示します。エラーには、整数ではない値、`int` の範囲外の値、重複した値などが含まれます。

```sh
./push_swap 1 2 3 2
# Error
```

#### Strategy Flags

フラグは整数列より前に指定します。指定しない場合は `--adaptive` が使われます。

```sh
./push_swap --simple 5 4 3 2 1
./push_swap --medium 4 67 3 87 23
./push_swap --complex 4 67 3 87 23
./push_swap --adaptive 4 67 3 87 23
```

| フラグ | 内容 |
| --- | --- |
| `--simple` | `O(n^2)` の simple strategy を使う |
| `--medium` | `O(n sqrt(n))` の medium strategy を使う |
| `--complex` | `O(n log n)` の complex strategy を使う |
| `--adaptive` | disorder に応じて戦略を自動選択する |

#### Benchmark Mode

`--bench` を指定すると、通常の命令列を標準出力に表示した後、以下の情報を標準エラー出力に表示します。

- disorder の値
- 使用された戦略名と計算量
- 総操作数
- 各命令の実行回数

```sh
./push_swap --bench --adaptive 4 67 3 87 23
```

標準出力には命令列だけが流れるため、checker と組み合わせて使えます。

```sh
ARG="4 67 3 87 23"
./push_swap --bench --adaptive $ARG | ./checker $ARG
```

#### Random Test Example

```sh
shuf -i 0-9999 -n 500 > args.txt
./push_swap $(cat args.txt)
```

手数だけを確認する場合:

```sh
./push_swap $(cat args.txt) | wc -l
```

#### Bonus Checker

`checker` は標準入力から命令を読み取り、与えられた stack が正しくソートされるかを検証します。

```sh
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG
```

結果は以下のように表示されます。

- ソート成功: `OK`
- ソート失敗: `KO`
- 不正な引数または不正な命令: `Error`

### Explanation and Justification of the Algorithms

この実装では、入力値をそのまま比較するのではなく、最初に座標圧縮を行います。例えば `2 5 8 9 20` は、値の大小関係を保ったまま `0 1 2 3 4` のような index に変換されます。これにより、負数や大きな整数を含む入力でも、ソート処理を扱いやすい範囲の index で統一できます。

また、ソート前に disorder を計算します。disorder は全てのペアのうち、前にある値の方が後ろの値より大きい「逆転ペア」の割合です。

```text
disorder = inverted_pairs / total_pairs
```

すでに整列済みなら `0`、逆順に近いほど `1` に近づきます。

#### Small Sort

要素数が5以下の場合は、専用の小規模ソートを使います。2個、3個、5個以下のケースに分け、最小限に近い回転・swap・push で処理します。これは定数サイズの処理なので、どの戦略が選ばれていても計算量の上限には影響しません。

#### Simple Strategy: Selection Extraction

`--simple`

計算量: `O(n^2)`

simple strategy は、選択ソートの考え方を stack 操作に置き換えたものです。stack `a` の中から最小 index の位置を探し、`ra` または `rra` で先頭まで移動してから `pb` で stack `b` に送ります。これを stack `a` が小規模ソートで処理できるサイズになるまで繰り返し、最後に `pa` で戻します。

C言語上で最小値の位置を探す走査は命令として出力されませんが、見つけた要素を先頭へ移動するためには `ra` または `rra` が最大で `n / 2` 回程度必要です。さらに各要素を `pb` で stack `b` に送ります。これを `n`, `n - 1`, `n - 2`, ... のサイズに対して繰り返すため、出力される Push_swap 操作数は `n + (n - 1) + ... + 1` に比例し、上限は `O(n^2)` です。実装が理解しやすく、低 disorder の入力や小さい入力の説明に向いています。

#### Medium Strategy: Chunk Sort

`--medium`

計算量: `O(n sqrt(n))`

medium strategy は、座標圧縮済みの index を範囲ごとの chunk に分割して処理します。chunk のサイズはおおよそ `sqrt(n)` を基準に決めています。現在の chunk に含まれる値を stack `a` から探し、見つかったら `pb` で stack `b` に送ります。その後、stack `b` から最大 index を探して先頭へ移動し、`pa` で stack `a` に戻します。

chunk の大きさを `O(sqrt(n))` とすると、chunk の個数も `O(sqrt(n))` になります。各 chunk を処理するとき、stack `a` を回転しながら対象範囲の値を探すため、1 chunk あたり最大 `O(n)` 回程度の `ra` / `pb` が発生します。これを `O(sqrt(n))` 個の chunk に対して行うので `O(n sqrt(n))` です。また、stack `b` から値を戻す部分は、1 chunk あたり最大 `O((sqrt(n))^2) = O(n)` 操作で、全 chunk では同じく `O(n sqrt(n))` に収まります。

#### Complex Strategy: Binary Radix Sort

`--complex`

計算量: `O(n log n)`

complex strategy は、座標圧縮された index を2進数として見て、下位 bit から順番に処理する LSD radix sort です。各 bit について、stack `a` の全要素を確認し、その bit が `0` なら `pb`、`1` なら `ra` を行います。1周した後、stack `b` の要素を `pa` で stack `a` に戻します。

最大 index は `n - 1` なので、必要な bit 数は `log n` 個です。各 bit では、全要素に対して `pb` または `ra` を1回ずつ行い、その後 stack `b` に送った要素を `pa` で戻します。つまり1 bit あたりの操作数は高々 `O(n)` です。これを `O(log n)` bit 分繰り返すため、Push_swap の操作数モデルでは `O(n log n)` です。入力の並びに左右されにくく、大きい入力や disorder が高い入力で安定します。

#### Adaptive Strategy

`--adaptive`

adaptive strategy は、ソート前に計算した disorder によって内部で使う戦略を切り替えます。

| disorder | 選択される戦略 | 計算量 |
| --- | --- | --- |
| `disorder < 0.2` | simple strategy | `O(n^2)` |
| `0.2 <= disorder < 0.5` | medium strategy | `O(n sqrt(n))` |
| `disorder >= 0.5` | complex strategy | `O(n log n)` |

この閾値は課題要件に合わせたものです。低 disorder では入力がすでにある程度整っているため simple strategy でも十分に扱いやすく、中程度では chunk による分割が有効です。高 disorder では入力順に依存しにくい radix sort を使うことで、手数の増加を安定して抑えます。

### 役割分担 (Division of Labor)

本プロジェクトはペア課題として、実装方針やアルゴリズムの理解を共有しながら進めました。

- `dakobaya`: Makefile、引数パース、エラー処理、stack 管理、small sort, simple strategy、medium strategy、benchmark、bonus checker 周辺、全体的な細かい修正を担当。
- `kasuzuki`: 構造体の設計と実装、座標圧縮、complex strategy、操作インターフェースやソート挙動の検討を担当。

最終的には、どちらの担当箇所も相互に確認し、評価時に両者が説明できる状態を目指しました。

### Resources

#### References

- [Radix sort](https://algoful.com/Archive/Algorithm/RadixSort): complex strategy の LSD radix sort を理解するために使用。
- [Bit operation article](https://zenn.dev/kodyi/articles/3210f1b56c6aee): bit 演算の復習に使用。
- [Chunked sorting article](https://satyadeepmaheshwari.medium.com/sorting-large-datasets-with-limited-memory-the-chunked-merge-sort-approach-318275275c81): chunk に分割して処理する考え方の参考に使用。

#### Use of AI

AI は、README の構成整理、課題要件のチェック、アルゴリズム説明の言語化、エッジケースの洗い出しに使用しました。生成された内容はそのまま採用せず、実装ファイルと照らし合わせて確認しています。

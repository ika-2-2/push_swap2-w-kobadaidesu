*This project has been created as part of the 42 curriculum by dakobaya.*

# libft

## 説明

libc の関数をゼロから自分で書いた。あと libc にないやつも少し。
標準ライブラリの中身を実装することで、メモリ操作や文字列処理の仕組みをちゃんと理解するのが目的。
完成したら `libft.a` になって、今後の42課題でも使い回せる。

## 関数一覧

### Part 1 — libc の再実装

| 関数 | やること |
|---|---|
| `ft_isalpha` | アルファベットか判定 |
| `ft_isdigit` | 数字か判定 |
| `ft_isalnum` | 英数字か判定 |
| `ft_isascii` | ASCII文字か判定 |
| `ft_isprint` | 印字可能文字か判定 |
| `ft_toupper` | 小文字→大文字 |
| `ft_tolower` | 大文字→小文字 |
| `ft_strlen` | 文字列の長さ |
| `ft_memset` | メモリを指定バイトで埋める |
| `ft_bzero` | メモリをゼロで初期化 |
| `ft_memcpy` | メモリコピー（オーバーラップ非対応） |
| `ft_memmove` | メモリコピー（オーバーラップ対応） |
| `ft_memchr` | メモリ内バイト探索 |
| `ft_memcmp` | メモリ比較 |
| `ft_strlcpy` | サイズ制限付きコピー |
| `ft_strlcat` | サイズ制限付き連結 |
| `ft_strchr` | 文字を前から探す |
| `ft_strrchr` | 文字を後ろから探す |
| `ft_strncmp` | n文字まで比較 |
| `ft_strnstr` | 部分文字列探索 |
| `ft_atoi` | 文字列→int |
| `ft_calloc` | ゼロ初期化済みメモリ確保 |
| `ft_strdup` | 文字列を複製 |

### Part 2 — 追加ユーティリティ

| 関数 | やること |
|---|---|
| `ft_substr` | 部分文字列を切り出す |
| `ft_strjoin` | 2つの文字列を結合 |
| `ft_strtrim` | 両端から指定文字を削除 |
| `ft_split` | 区切り文字で文字列を分割 |
| `ft_itoa` | int→文字列 |
| `ft_strmapi` | 各文字に関数を適用（新しい文字列を返す） |
| `ft_striteri` | 各文字に関数を適用（インプレース） |
| `ft_putchar_fd` | fdに1文字出力 |
| `ft_putstr_fd` | fdに文字列出力 |
| `ft_putendl_fd` | fdに文字列+改行出力 |
| `ft_putnbr_fd` | fdに整数出力 |

### ボーナス — 連結リスト

| 関数 | やること |
|---|---|
| `ft_lstnew` | 新しいノードを作る |
| `ft_lstadd_front` | リストの先頭に追加 |
| `ft_lstadd_back` | リストの末尾に追加 |
| `ft_lstlast` | 最後のノードを取得 |
| `ft_lstsize` | ノード数を返す |
| `ft_lstdelone` | ノード1つを削除 |
| `ft_lstclear` | リスト全体を削除・解放 |
| `ft_lstiter` | 各ノードに関数を適用 |
| `ft_lstmap` | 各ノードを変換した新しいリストを返す |

## インストール・使い方

```bash
make
```

```c
#include "libft.h"
```

```bash
cc your_file.c -L. -lft -o your_program
```

## 参考資料

- [42 Docs — libft課題PDF](https://cdn.intra.42.fr/pdf/pdf/140846/en.subject.pdf)

### AIの使用について

このプロジェクトではClaude（claude.ai / Claude Code）を以下の用途で使用しました：

- 要件に基づいたREADME.mdの構成・内容の作成
- 標準ライブラリ関数のエッジケースの確認（例：`ft_strnstr` の境界処理、`ft_memmove` のオーバーラップ動作）

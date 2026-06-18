構造体作った

これから構造体にデータ詰め込む関数つくる

```
typedef struct s_stack
{
	int value;
    int index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;
```

コマンドライン引数で受け取った値を直接変えるのはまずいので、
座標圧縮はスタックを直接書き換える

TODO: swap系とpush系がnorm引っかかるので関数分割する

sa, sbの中に
`write(1, "sa\n", 3)`
と直接書いていたので、ssで両方実行するとき
sa
sb
とどっちも出てしまうため、ssで呼び出されたかどうか判定するためにフラグを追加↓

`void sa(t_stack **stack_a, int flg)`

rotate系、reverseもフラグ追加した

## radix-sort(基数ソート)

参考記事
https://zenn.dev/kodyi/articles/3210f1b56c6aee

基数ソートを可視化したもの
https://algoful.com/Archive/Algorithm/RadixSort

### やること
1. Aスタックの一番上の要素のbitが1ならBスタックへ移動、0ならAスタックの一番下へ移動
2. 1をすべての要素に対して行う
3. Bスタックの要素を全てAスタックに戻す

ビルド

make          # ビルド
make re       # クリーンしてリビルド
make bonus    # checker もビルド
基本実行

# オペレーション列を表示
./push_swap 5 3 1 4 2

# --complex（radix）を強制
./push_swap --complex 5 3 1 4 2

# --simple を強制
./push_swap --simple 5 3 1 4 2

# 引数なし → 何も出ない（正常）
./push_swap
ソートが正しいか確認

# OKかKOが出る
./push_swap --complex 5 3 1 4 2 | ./checker 5 3 1 4 2
ops数を数える

./push_swap --complex 5 3 1 4 2 | wc -l
ランダムテスト（ワンライナー）

# 100個
ARG=$(shuf -i 1-10000 -n 100 | tr '\n' ' ')
./push_swap --complex $ARG | tee /tmp/ops | ./checker $ARG && wc -l < /tmp/ops

# 500個
ARG=$(shuf -i 1-10000 -n 500 | tr '\n' ' ')
./push_swap --complex $ARG | tee /tmp/ops | ./checker $ARG && wc -l < /tmp/ops
複数回回してopsの平均を見る

for i in $(seq 1 10); do
  ARG=$(shuf -i 1-10000 -n 100 | tr '\n' ' ')
  ./push_swap --complex $ARG | wc -l
done
bench モード（--bench フラグ）

# ops列は出ず、統計だけ stderr に出る
./push_swap --bench --complex 5 3 1 4 2 2>&1 1>/dev/null
エラーケース確認

./push_swap --complex 1 2 abc    # Error
./push_swap --complex 1 2 2      # Error（重複）
./push_swap --complex             # Error（数字なし）
デバッグ用 test_radix（個別確認）

# 再ビルド
cc -Wall -Wextra -I. test.c stack.c compression.c error.c \
   push.c rotate.c reverse_lotate.c disorder.c radix.c \
   libft/libft.a -o test_radix

# 実行（操作列がstdoutに、SORTED/NOT SONTEDはstdinに出る）
./test_radix 5 3 1 4 2
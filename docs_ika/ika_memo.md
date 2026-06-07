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

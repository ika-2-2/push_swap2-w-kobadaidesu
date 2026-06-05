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

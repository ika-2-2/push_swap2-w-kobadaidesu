# push_swap operations memo

stack は左側を top として書く。

```text
A: [top] [...] [bottom]
```

要素が0個か1個しかない stack に対して `swap` / `rotate` / `reverse rotate` をしても、stack は変化しない。

## swap 系

### `sa`

`stack a` の上2つを入れ替える。

```text
Before
A: [3] [2] [1]

sa

After
A: [2] [3] [1]
```

### `sb`

`stack b` の上2つを入れ替える。

```text
Before
B: [5] [4] [6]

sb

After
B: [4] [5] [6]
```

### `ss`

`sa` と `sb` を同時に行う。

```text
Before
A: [3] [2] [1]
B: [5] [4] [6]

ss

After
A: [2] [3] [1]
B: [4] [5] [6]
```

## push 系

### `pa`

`stack b` の top を取り出して、`stack a` の top に置く。

つまり、`B` から `A` に push する。

```text
Before
A: [2] [3]
B: [1] [4]

pa

After
A: [1] [2] [3]
B: [4]
```

`stack b` が空なら何もしない。

### `pb`

`stack a` の top を取り出して、`stack b` の top に置く。

つまり、`A` から `B` に push する。

```text
Before
A: [1] [2] [3]
B: [4]

pb

After
A: [2] [3]
B: [1] [4]
```

`stack a` が空なら何もしない。

## rotate 系

### `ra`

`stack a` を上方向に1つ回す。

top が一番下に移動する。

```text
Before
A: [1] [2] [3]

ra

After
A: [2] [3] [1]
```

双方向循環リストなら、head を次に進めるだけで表現できる。

```c
*a = (*a)->next;
```

### `rb`

`stack b` を上方向に1つ回す。

```text
Before
B: [4] [5] [6]

rb

After
B: [5] [6] [4]
```

### `rr`

`ra` と `rb` を同時に行う。

```text
Before
A: [1] [2] [3]
B: [4] [5] [6]

rr

After
A: [2] [3] [1]
B: [5] [6] [4]
```

## reverse rotate 系

### `rra`

`stack a` を下方向に1つ回す。

一番下の要素が top に移動する。

```text
Before
A: [1] [2] [3]

rra

After
A: [3] [1] [2]
```

双方向循環リストなら、head を前に戻すだけで表現できる。

```c
*a = (*a)->prev;
```

### `rrb`

`stack b` を下方向に1つ回す。

```text
Before
B: [4] [5] [6]

rrb

After
B: [6] [4] [5]
```

### `rrr`

`rra` と `rrb` を同時に行う。

```text
Before
A: [1] [2] [3]
B: [4] [5] [6]

rrr

After
A: [3] [1] [2]
B: [6] [4] [5]
```

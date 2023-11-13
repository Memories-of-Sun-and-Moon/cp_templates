# others

- 分類をしたいが、イイ感じの配置がわからないもの
- 考察の末に、解法がわかるもの

## ABC324D Printing Machine [greedy]

1. 打てるんだったら何か打った方がいい
2. 複数打てるんだったら、時間の制約が厳しい物から打った方がいい

と考えることによって、 greedy に帰着することができる。

## yukicoder No.2518 Adjacent Larger [greedy, YES/NO]

- 入力として与えられる状態数が [0, 1, 2] と少ない
- 小さいケースで全通り考えたが、矛盾するケースの必要十分条件を求めることができず
- 状態のそれぞれの "気持ち" になればわかったかもしれない
- 「矛盾が無ければ順列が生成可能か」ということについても考えておくべきだったかも
- 順列を基に、入力で与えられる $A$ を逆に考えてみる

## yukicoder No.2519 Coins in Array [math, constructive]

- $f(x, y)$ の性質については、完全に熟知できていた
- その後の場合分けに苦労している（複雑なアルゴリズムができてしまい、壊れた）
- $A$ の下限が $0$ なのに後半で気づいたのも敗因か

- $f$ の結果は「互いに素か否か」で変わるものだけど、本質としては偶奇性だけで解ける

バグった時(バグりそうな時) -> もう少し簡単な方法は無いか

## ARC146B Plus and AND

- 考察までは出来た
- 実装方法がわからなかった
- 変数は積極的に分離してよい
- 数値の bit を見る際は、よほどのことがない限りループながら愚直に見ても間に合う
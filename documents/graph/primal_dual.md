---
title: 最小費用流（primal-dual法）
documentation_of: ./../../graph/primal_dual.hpp
---

# 最小費用流

最小費用流を求める。負の辺を張ることはできない。

## 使い方

- ``primal_dual<T>(int V)`` : コンストラクタ。頂点数 $V$ の最小費用流の構築の準備を行う。
- ``add_edge(int from, int to, T cap, T cost)`` : $from$ から $to$ へ、容量 $cap$ で $1$ 流量当たりのコストが $cost$ の辺を張る $O(1)$
- ``pair<bool, T> min_cost_flow(int s, int t, T f)`` : $s$ から $t$ へ、流量 $f$ を流せるだけ流したときの最小費用流を求める。``true`` が返ったときは、$f$ 流すことができたことを示す。 **最悪計算量** $O(fV^2)$

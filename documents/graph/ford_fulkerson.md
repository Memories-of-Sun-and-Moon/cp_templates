---
title: 最大流(Ford-Fulkerson)
documentation_of: ./../../graph/ford_fulkerson.hpp
---

# 最大流(Ford-Fulkerson)

## 使い方

- ``ford_fulkerson<T>(int V)`` : 頂点数 $V$ の最大流グラフのコンストラクタ
- ``void add edge(int a, int b, T c)`` : $a$ から $b$ に容量 $c$ の辺を張る
- ``T calc(int a, int b)`` $a$ から $b$ への最大流を求める。辺中を流れる最大流量を $f$, 辺数 $E$ とすると、最悪計算量 $O(fE)$

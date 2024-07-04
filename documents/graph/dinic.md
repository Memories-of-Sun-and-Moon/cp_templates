---
title: 最大流(Dinic)
documentation_of: ./../../graph/dinic.hpp
---

# 最大流(Dinic)

## 使い方

- ``dinic<T>(int V)`` : 頂点数 $V$ の最大流グラフのコンストラクタ
- ``void add edge(int a, int b, T c)`` : $a$ から $b$ に容量 $c$ の辺を張る
- ``T calc(int a, int b)`` $a$ から $b$ への最大流を求める。頂点 $V$, 辺数 $E$ とすると、最悪計算量 $O(V^2E)$

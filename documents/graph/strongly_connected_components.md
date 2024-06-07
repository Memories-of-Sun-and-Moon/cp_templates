---
title: 強連結成分分解
documentation_of: ./../../graph/strongly_connected_components.hpp
---

# 強連結成分分解

## 使い方

グラフ $G$ は頂点数 $N$, 辺数 $M$ の有向グラフとする。

- ``scc_graph(n)`` : 頂点数 $N$ の有向グラフを定義する
- ``add_edge(int a, int b)`` : $a$ から $b$ へ向かう辺を追加する
- ``vector<vector<int>> scc()`` : 強連結成分分解をする。トポロジカルソートされた強連結成分・その強連結成分に属する頂点集合を返す。 $O(N+M)$

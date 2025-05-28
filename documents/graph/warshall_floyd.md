---
title: 全頂点間最短距離 O(V^3) 及び更新を O(V^2) で行うアルゴリズム (ワーシャルフロイド法)
documentation_of: ./../../graph/warshall_floyd.hpp
---

# 全頂点間最短距離 O(V^3) 及び更新を O(V^2) で行うアルゴリズム (ワーシャルフロイド法)

## 使い方

- ``warshall_floyd(vector<vector<T>> &edge_cost, T infty=::numeric_limits<T>()/2)`` : コンストラクタ。距離行列を用意する。
  - 全頂点間最短距離を格納した行列 ``dist`` が $O(V^3)$ で求まる。
  - ただし、 ``edge_cost[i][i] = 0``, 結ばれていない頂点間は $\text{infty}$ を格納すること($2 \times \text{infty} < \text(型 T の最大値)$ である必要がある)
- ``void update(int s, int t, T, cost)`` : ``edge_cost[s][t]`` を ``cost`` に更新する。 $O(V^2)$

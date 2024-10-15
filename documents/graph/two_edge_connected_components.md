---
title: 二重辺連結成分分解
documentation_of: ./../../graph/two_edge_connected_components.hpp
---

# 二重辺連結成分分解

## 使い方

``tuple(vector<vector<int>>, vector<int>, vector<vector<int>>) two_edge_connected_components(vector<vector<int>> g)`` 
$G$ の二重辺連結成分分解をした

- 圧縮された頂点のグループ
- 各頂点が圧縮された後の集合
- 二重辺連結成分分解をしたグラフ

を返す。

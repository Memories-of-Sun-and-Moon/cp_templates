---
title: 木の直径計算
documentation_of: ./../../graph/tree_diameter.hpp
---

# 木の直径計算

## 使い方

- ``auto [diameter, path] = tree_diameter(vector<vector<pair<int, ll>>> g)`` : 重み付き木 $G$ の直径とそのパスを返す。 $O(N)$
- ``auto [diameter, path] = tree_diameter(vector<vector<int>> g)`` : 重み無し木 $G$ の直径とそのパスを返す。 $O(N)$

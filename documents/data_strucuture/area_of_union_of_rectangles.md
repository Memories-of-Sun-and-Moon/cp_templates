---
title: area_of_union_of_rectangles(長方形の和集合の面積)
documentation_of: ./../../data_structure/area_of_union_of_rectangles.hpp
---

# area_of_union_of_rectangles(長方形の和集合の面積)

## 使い方

- 要素数を $N$ とする
- ``area_of_union_of_rectangles<T>(vector<tuple<T, T, T, T> rectangles).solve<T2>()`` : $i$ 番目の長方形を $\{(x, y) : l_i \leq x \leq r_i, d_i \leq y \leq u_i\}$ で表すとき、この和集合の面積を返す。 $O(N \log{N})$

## 説明

$(\text{最小値}, \text{最小値となっている数})$ を持つ遅延セグ木を使って $y$ 座標を走査することによって求めることができる。

走査する際には、重なっている長方形の数が $0$ である部分について数えている。

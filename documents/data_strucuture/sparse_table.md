---
title: sparse table
documentation_of: ./../../data_structure/segment_tree.hpp
---

# sparse table

## 使い方

- $N$ を要素数

とする。

また、要素の取り方は **0-indexed** であることに注意する。

- ``sparse_table<T>(const vector<T> &v, auto combine)`` : 要素数 $N$ の sparse table を生成する $O(N \log{N})$
- ``T fold(int l, int r)`` : $[l, r)$ を満たす区間内に対する区間演算クエリの結果を返す $O(1)$

## 概要

$2$ 冪の長さの全区間をあらかじめ計算しておき、$[L, R)$ に対する区間演算は $2$ つの区間の和集合として求める。

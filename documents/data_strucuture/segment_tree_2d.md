---
title: 2Dセグメント木
documentation_of: ./../../data_structure/segment_tree_2d.hpp
---

# 2Dセグメント木

## 使い方

- $H$ を縦の要素数
- $W$ を横の要素数

とする。

また、要素の取り方は **0-indexed** であることに注意する。

- ``segment_tree_2d<T>(T H, T W, auto combine, T identify)`` : $H\times W$ の 2Dセグメント木を生成する
- ``void set(int y, int x, T val)`` : $(y, x)$ の要素を $val$ に変更する  $O(\log(H)\log(W))$
- ``T fold(int li, int lj, int ri, int rj)`` : $[l_i, r_i), [l_j, r_j)$ を満たす矩形内に対する区間演算クエリの結果を返す $O(\log(H)\log(W))$

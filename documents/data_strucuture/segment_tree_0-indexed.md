---
title: 0-indexedのセグメント木
documentation_of: ./../../data_structure/segment_tree_0-indexed.hpp
---

# 0-indexedのセグメント木

## 使い方

- $N$ を要素数

とする。

また、要素の取り方は **0-indexed** であることに注意する。

- ``segment_tree<T>(int N, auto combine, T identify)`` : 要素数 $N$ の セグメント木を生成する
- ``segment_tree<T>(vector<T> v, auto combine, T identify)`` : 要素数 $N$ で、 ``vector<T> v`` で初期化されたセグメント木を生成する
- ``void set(int x, T val)`` : $x$ 番目の要素を $val$ に変更する  $O(\log(N))$
- ``T fold(int l, int r)`` : $[l, r)$ を満たす区間内に対する区間演算クエリの結果を返す $O(\log(N))$
- ``seg[x]`` : $x$ 番目の値を返す。$O(1)$

## 概要

完全二分木は 1-indexed で作った方が何かと便利なため、これは観賞用である（ただ、[0-indexedの完全二分木の考え方が本質な問題](https://atcoder.jp/contests/abc349/tasks/abc349_d)があったため、こちらも残しておく）。

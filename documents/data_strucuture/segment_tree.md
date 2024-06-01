---
title: セグメント木
documentation_of: ./../../data_structure/segment_tree.hpp
---

# セグメント木

## 使い方

- $N$ を要素数

とする。

また、要素の取り方は **0-indexed** であることに注意する。

- ``segment_tree<T>(int N, auto combine, T identify)`` : 要素数 $N$ の セグメント木を生成する
- ``segment_tree<T>(vector<T> v, auto combine, T identify)`` : 要素数 $N$ で、 ``vector<T> v`` で初期化されたセグメント木を生成する
- ``void set(int x, T val)`` : $x$ 番目の要素を $val$ に変更する  $O(\log(N))$
- ``T fold(int l, int r)`` : $[l, r)$ を満たす区間内に対する区間演算クエリの結果を返す $O(\log(N))$
- ``seg[x]`` : $x$ 番目の値を返す。$O(1)$
- ``max_right(f<bool(T)>, l)`` : $l \leq i < N$ のうち、各要素に対する条件 $f$ を満たすもののなかで最も最大（ $N-1$ 寄り）のものを返す $O(\log(N))$

## !!!UNVERIFYED!!!

- ``min_left(f<bool(T)>, r)`` : $0 \leq i \leq r$ のうち、各要素に対する条件 $f$ を満たすもののなかで最も最小（ $0$ 寄り）のものを返す $O(\log(N))$


## 概要

内部で完全二分木を **1-indexed** で構築している。こちらの方が定数倍がよく、また ``max_right()`` なども実装しやすい

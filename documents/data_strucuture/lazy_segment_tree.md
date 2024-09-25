---
title: 遅延セグメント木
documentation_of: ./../../data_structure/lazy_segment_tree.hpp
---

# 遅延セグメント木

## 使い方

- $N$ を要素数

とする。

また、要素の取り方は **0-indexed** であることに注意する。

- ``lazy_segment_tree<S, op, e, F, mapping, composition, id>(int N)`` : 要素数 $N$ の セグメント木を生成する
- ``lazy_segment_tree<S, op, e, F, mapping, composition, id>(vector<S> v)`` : 要素数 $N$ で、 ``vector<S> v`` で初期化された遅延セグメント木を生成する
- ``void set(int x, S val)`` : $x$ 番目の要素を $val$ に変更する  $O(\log(N))$
- ``S fold(int l, int r)`` : $[l, r)$ を満たす区間内に対する区間演算クエリの結果を返す $O(\log(N))$
- ``seg[x]`` : $x$ 番目の値を返す。$O(1)$
- ``apply(int x, F f)`` : $seg_x$ について $seg_x = f(seg_x)$ とする。 $O(\log(N))$
- ``apply(int l, int r, F f)`` : $l \leq i < r$ を満たす部分 $seg_i$ について $seg_i = f(seg_i)$ とする。 $O(\log(N))$
- ``max_right(g<bool(S)>, int l)`` : $l \leq i < N$ のうち、各要素に対する条件 $g$ を満たすもののなかで最も最大（ $N-1$ 寄り）のものを返す $O(\log(N))$
- ``min_left(g<bool(S)>, int r)`` : $0 \leq i \leq r$ のうち、各要素に対する条件 $f$ を満たすもののなかで最も最小（ $0$ 寄り）のものを返す $O(\log(N))$

## !!CAUTION!!

``max_right(g<bool(S)>, int l)`` の検証は atcoder の問題上に手動で提出しており、自動では verify されない

``min_left(g<bool(S)>, int r)`` の検証は atcoder の問題上に手動で提出しており、自動では verify されない

[検証](https://atcoder.jp/contests/abc371/submissions/58020164)

## 概要

セグ木同様、内部で完全二分木を **1-indexed** で構築している。こちらの方が定数倍がよく、また ``max_right()`` なども実装しやすい。

なお、セグ木に必要な要素の書き方は、[チートシート](https://betrue12.hateblo.jp/entry/2020/09/23/005940) などを参照すること（自分でもまとめようね）

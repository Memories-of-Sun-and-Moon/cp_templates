---
title: Monotoneな行列における行最小値問題(monotone-minima)
documentation_of: ./../../dp/monotone_minima.hpp
---

# Monotoneな行列における行最小値問題(monotone-minima)

## 使い方

- ``vector<int> monotone_minima(int n, int m, const F &argmin)`` : $N$ 行 $M$ 列の Monotone な行列について、$i$ 行目の $[l, r)$ 列の $\arg\min$ （最小値の添え字）を求める関数を用意したとき、その行列における各行の最小値の添え字を求める $O(N + \sigma M \log N )$

ただし、 $\sigma$ を $\arg\min$ を求める計算量とする。

## 概要

$\arg \min_j A_{i,j}$ が $i$ について講義単調増加である時、 $A$ は Monotone であるという。

$A$ が Monotone であれば、 $\arg \min_j A_{i,j}$ が $j$ であると分かったとき、$A_{i, j}$ の右上と左下には $\min_j A_{i, j}$ となる要素が存在しない。よって、分割統治の要領で効率的に最小値を求めることができる。

引数に $A$ を渡してしまった場合、それだけで $O(NM)$ かかることに注意したい。

## Verify

[スペースエクスプローラー高橋君](https://atcoder.jp/contests/colopl2018-final-open/submissions/54235541)

## 参考

Acompany勉強会 2024/06/04 Monge 入門

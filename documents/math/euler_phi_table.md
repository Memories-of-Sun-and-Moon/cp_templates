---
title: オイラーのφ関数（オイラーのトーシェント関数）テーブル
documentation_of: ./../../math/euler_phi_table.hpp
---

# オイラーのφ関数（オイラーのトーシェント関数）テーブル

## 使い方

- ``vector<int> euler_phi_table(int n)`` : $\phi(x)$ ($1 \leq x \leq n$) が配列の添え字 $1, 2, \cdots ,n$ に格納された長さ $n+1$ の配列を返す $O(N \log N \log N)$

## 概要

$\phi(n)$ : $1$ から $n$ までの自然数のうち、 $n$ と互いに素なものの個数

$\phi(n) = \prod_{p \mid n} \left(1 - \frac{1}{p}\right)$

これを、素因数側から求めることによって、$\phi(x)$ ($1 \leq x \leq n$) についてまとめて計算することが可能となる。

---
title: 2項係数mod
documentation_of: ./../../math/combination.hpp
---

# 2項係数mod

## 使い方

``binomial<T> bin`` : 2項係数mod $M$ (型は ``T``) のコンストラクタを呼ぶ。2項係数で扱う値の上限を $K = 1010101$ としており、型 ``T`` における $1!, 2!, ..., K!$ 及びそれらの逆元の計算に比例した計算量がかかる。

``bin.nCr(n, r)`` : $_nC_r \pmod{M}$ を返す。

## 概要

## 一応Verify出来たサイト

[AtCoder](https://atcoder.jp/contests/abc066/tasks/arc077_b)

---
title: 約数列挙
documentation_of: ./../../math/enumerate_divisors.hpp
---

# 約数列挙

## 使い方

- ``vector<T> enumerate_divisors(T n)`` : $n$ の約数を昇順に列挙したものを返す。素因数分解の計算量を $O(\alpha)$ として、 $O(\alpha + \log(n))$

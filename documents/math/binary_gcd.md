---
title: binary_gcd
documentation_of: ./../../math/combination.hpp
---

# binary_gcd

## 使い方

``binary_gcd(ll a, ll b)`` : $\text{gcd}(a, b)$ を返す。$O(\log{a+b})$ 程度

## 概要

除算が遅いため、それを回避するためにビットシフトに限定した GCD 計算アルゴリズム

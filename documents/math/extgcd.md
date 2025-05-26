---
title: 拡張ユークリッドの互除法
documentation_of: ./../../math/extgcd.hpp
---

# 拡張ユークリッドの互除法

## 使い方

``extgcd(T a, T b, T &x, T &y)`` : $ax + by = \text{gcd}(a, b)$ なる $x, y$ を求める。$O(\log{a+b})$ 程度

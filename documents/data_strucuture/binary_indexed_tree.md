---
title: BIT(Binary Indexed Tree)
documentation_of: ./../../data_structure/binary_indexed_tree.hpp
---

# BIT(Binary Indexed Tree)

## 使い方

- 要素数を $N$ とする
- ``binary_indexed_tree<T>(int n)`` : 要素数 $N$ の BIT を構築する
- ``add(int i, T x)`` : $i$ 番目に $x$ を加算する $O(\log(N))$
- ``sum(int i)`` : $[1, i]$ の総和を求める $O(\log(N))$

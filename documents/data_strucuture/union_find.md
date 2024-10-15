---
title: Union-Find
documentation_of: ./../../data_structure/union_find.hpp
---

# Union-Find

## 使い方

$n$ を Union-Find のサイズとする

- ``union_find(int size)`` : サイズ $size$ の Union-Find を生成する
- ``bool unite(int x, int y)`` : x と y をマージする。マージが成功したときに ``true`` を返す $O(\alpha(n))$
- ``bool is_same(int x, int y)`` : x と y が同じグループかを返す $O(\alpha(n))$
- ``int get_size(int x)`` : x が属する集合のサイズを返す $O(1)$
- ``int groups_size()`` : Union-Find の集合の数を返す $O(1)$
- ``vector<vector<int>> groups()`` : 集合の状態を表した二次元配列を返す。 $O(N)$


## 概要

Union-Find です。

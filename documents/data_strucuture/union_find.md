---
title: Union-Find
documentation_of: ./../../data_structure/union_find.hpp
---

# Union-Find

## 使い方

$n$ を Union-Find のサイズとする

- ``union_find(int size)`` : サイズ $size$ の Union-Find を生成する
- ``void unite(int x, int y)`` : x と y をマージする $O(\alpha(n))$
- ``bool is_same(int x, int y)`` : x と y が同じグループかを返す
- ``int get_size(int x)`` : x が属する集合のサイズを返す

## 概要

Union-Find です。
詳しい説明はインターネットを利用してね。

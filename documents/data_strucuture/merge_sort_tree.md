---
title: merge-sort tree
documentation_of: ./../../data_structure/merge_sort_tree.hpp
---

# merge-sort tree

固定の列 A について、区間 $K$ 未満・区間 $K$ 未満の和を $O((\log{N})^2)$ で求めるデータ構造

## 使い方

- ``merge_sort_tree(vector<T> A)`` : コンストラクタ
- ``count_less(int l, int r, T q)`` : $[l, r)$ かつ $A_i < q$ を満たす要素の数を返す
- ``sum_less(int l, int r, T q)`` : $[l, r)$ かつ $A_i < q$ を満たす要素の和を返す
- ``count_leq(int l, int r, T q)`` : $[l, r)$ かつ $q \leq A_i$ を満たす要素の数を返す
- ``sum_leq(int l, int r, T q)`` : $[l, r)$ かつ $q \leq A_i$ を満たす要素の和を返す

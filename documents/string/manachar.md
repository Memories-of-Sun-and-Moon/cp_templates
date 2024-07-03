---
title: manachar
documentation_of: ./../../string/manachar.hpp
---

# manachar

## 使い方

**0-indexed** で表す。

- ``vector<int>manachar(string s)`` : 文字列 $S$ の
  - 奇数番目 : $S_{i/2}, S_{i/2+1}$ の間を中心とした回文の半径
  - 偶数番目 : $S_{i/2}$ を中心とした回文の半径（自身を含む）
- を求めた長さ $2n-1$ の配列を返す $O(\lvert S \rvert)$

---
title: LIS
documentation_of: ./../../z_other/longest_increasing_subsequences.hpp
---

# LIS

## 使い方

``longest_increasing_subsequences<bool is_strict, T>(vector<T> v)`` : $v$ の最長増加部分列の長さを返す。

- ``is_strict = true`` の時、狭義単調増加
- ``is_strict = false`` の時、講義単調増加

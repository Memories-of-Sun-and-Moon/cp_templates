---
title: Suffix Array
documentation_of: ./../../string/suffix_array.hpp
---

# Suffix Array

## 使い方

配列で且つ、各項の比較が可能な型を T とする。
また、 T の長さを $N$ とする。

- ``suffix_array<T>(T S, gen_lcp)`` : S の Suffix Array を構築する $O(N \log^2 N)$
  - ``gen_lcp = true`` のとき : LCP 配列を構築する $O(N)$

- ``sa[i]`` : Suffix Array の $i$ 番目を返す。 $i$ は **1-indexed**
- ``lcp[i]`` : LCP 配列の $i$ 番目を返す。 $i$ は **1-indexed**


## 概要

Suffix Array は、接尾辞をソートしたもの。

LCP 配列（高さ配列）は、接尾辞配列における隣同士の接尾辞で、先頭何文字が共通しているかを表す配列。LCP は Longest Common Prefix の略。これを利用することで、 Number of Substrings 等の問題を解くことができる。

Suffix Array を計算するのにダブリングを用いている。SA-ISに変更することで、線形時間で構築可能となる。

（**1-indexed** と書いたのは、 $0$ 番目に空文字が入るためである）

## 参考

蟻本 p.335

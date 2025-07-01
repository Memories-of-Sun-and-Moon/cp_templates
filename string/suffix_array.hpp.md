---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/number_of_substrings.test.cpp
    title: verify/yosupo/number_of_substrings.test.cpp
  - icon: ':x:'
    path: verify/yosupo/suffixarray.test.cpp
    title: verify/yosupo/suffixarray.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/suffix_array.hpp\"\n\n#include<numeric>\n#include<vector>\n\
    \ntemplate <typename T> struct suffix_array {\n\tT s;\n\tstd::vector<int> sa;\n\
    \tstd::vector<int> rank;\n\tstd::vector<int> lcp;\n\n\tsuffix_array(const T &str,\
    \ bool gen_lcp = true) : s(str) {\n\t\tint n = (int)s.size();\n\t\tsa.resize(n+1);\n\
    \t\tstd::iota(sa.begin(), sa.end(), 0);\n\t\trank.assign(n+1, -1);\n\t\tfor(int\
    \ i = 0;i < n;i++){\n\t\t\trank[i] = s[i];\n\t\t}\n\t\tstd::vector<int> tmp(n+1);\n\
    \t\tint k;\n\t\tauto comp_sa = [&](int i, int j) -> bool {\n\t\t\tif(rank[i] !=\
    \ rank[j])return rank[i] < rank[j];\n\t\t\tint ri = i + k <= n ? rank[i+k] : -1;\n\
    \t\t\tint rj = j + k <= n ? rank[j+k] : -1;\n\t\t\treturn ri < rj;\n\t\t};\n\t\
    \tfor(k = 1;k <= n;k *= 2){\n\t\t\tsort(sa.begin(), sa.end(), comp_sa);\n\t\t\t\
    tmp[sa[0]] = 0;\n\t\t\tfor(int i = 1;i <= n;i++){\n\t\t\t\ttmp[sa[i]] = tmp[sa[i-1]]\
    \ + (comp_sa(sa[i-1], sa[i]) ? 1 : 0);\n\t\t\t}\n\t\t\trank = tmp;\n\t\t}\n\n\t\
    \tif(not gen_lcp)return;\n\n\t\tlcp.assign(n, 0);\n\t\tint h = 0;\n\t\tfor(int\
    \ i = 0;i < n;i++){\n\t\t\tint j = sa[rank[i]-1];\n\t\t\tif(h)h--;\n\t\t\tfor(;j+h\
    \ < n and i+h < n;h++){\n\t\t\t\tif(s[j+h] != s[i+h])break;\n\t\t\t}\n\t\t\tlcp[rank[i]-1]\
    \ = h;\n\t\t}\n\t}\n};\n"
  code: "#pragma once\n\n#include<numeric>\n#include<vector>\n\ntemplate <typename\
    \ T> struct suffix_array {\n\tT s;\n\tstd::vector<int> sa;\n\tstd::vector<int>\
    \ rank;\n\tstd::vector<int> lcp;\n\n\tsuffix_array(const T &str, bool gen_lcp\
    \ = true) : s(str) {\n\t\tint n = (int)s.size();\n\t\tsa.resize(n+1);\n\t\tstd::iota(sa.begin(),\
    \ sa.end(), 0);\n\t\trank.assign(n+1, -1);\n\t\tfor(int i = 0;i < n;i++){\n\t\t\
    \trank[i] = s[i];\n\t\t}\n\t\tstd::vector<int> tmp(n+1);\n\t\tint k;\n\t\tauto\
    \ comp_sa = [&](int i, int j) -> bool {\n\t\t\tif(rank[i] != rank[j])return rank[i]\
    \ < rank[j];\n\t\t\tint ri = i + k <= n ? rank[i+k] : -1;\n\t\t\tint rj = j +\
    \ k <= n ? rank[j+k] : -1;\n\t\t\treturn ri < rj;\n\t\t};\n\t\tfor(k = 1;k <=\
    \ n;k *= 2){\n\t\t\tsort(sa.begin(), sa.end(), comp_sa);\n\t\t\ttmp[sa[0]] = 0;\n\
    \t\t\tfor(int i = 1;i <= n;i++){\n\t\t\t\ttmp[sa[i]] = tmp[sa[i-1]] + (comp_sa(sa[i-1],\
    \ sa[i]) ? 1 : 0);\n\t\t\t}\n\t\t\trank = tmp;\n\t\t}\n\n\t\tif(not gen_lcp)return;\n\
    \n\t\tlcp.assign(n, 0);\n\t\tint h = 0;\n\t\tfor(int i = 0;i < n;i++){\n\t\t\t\
    int j = sa[rank[i]-1];\n\t\t\tif(h)h--;\n\t\t\tfor(;j+h < n and i+h < n;h++){\n\
    \t\t\t\tif(s[j+h] != s[i+h])break;\n\t\t\t}\n\t\t\tlcp[rank[i]-1] = h;\n\t\t}\n\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/suffix_array.hpp
  requiredBy: []
  timestamp: '2025-07-01 03:22:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo/suffixarray.test.cpp
  - verify/yosupo/number_of_substrings.test.cpp
documentation_of: string/suffix_array.hpp
layout: document
title: Suffix Array
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

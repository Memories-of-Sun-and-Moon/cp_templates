---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/3078.test.cpp
    title: verify/yukicoder/3078.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/merge_sort_tree.hpp\"\n\n#include<algorithm>\n\
    #include<vector>\n\ntemplate<typename T>\nstruct merge_sort_tree {\n\tint n;\n\
    \tstd::vector<std::vector<T>> x, cs;\n\tmerge_sort_tree(const std::vector<T> &v)\
    \ : n(std::ssize(v)) {\n\t\tx.resize(n*2);\n\t\tcs.resize(n*2);\n\t\tfor(int i\
    \ = 0;i < n;i++)x[n+i] = {v[i]}, cs[n+i] = {0, v[i]};\n\t\tfor(int i = n-1;i >\
    \ 0;i--){\n\t\t\tstd::merge(x[i*2].begin(), x[i*2].end(), x[i*2 + 1].begin(),\
    \ x[i*2 + 1].end(), std::back_inserter(x[i]));\n\t\t\tcs[i].resize(std::ssize(x[i])\
    \ + 1);\n\t\t\tfor(int j = 0;j < std::ssize(x[i]);j++){\n\t\t\t\tcs[i][j+1] +=\
    \ cs[i][j] + x[i][j];\n\t\t\t}\n\t\t}\n\t}\n\tint count_less(int l, int r, T q)\
    \ {\n\t\tl += n, r += n;\n\t\tint ret = 0;\n\t\twhile(l < r) {\n\t\t\tif(l & 1){\n\
    \t\t\t\tret += std::lower_bound(x[l].begin(), x[l].end(), q) - x[l].begin();\n\
    \t\t\t\tl++;\n\t\t\t}\n\t\t\tif(r & 1){\n\t\t\t\tr--;\n\t\t\t\tret += std::lower_bound(x[r].begin(),\
    \ x[r].end(), q) - x[r].begin();\n\t\t\t}\n\t\t\tl >>= 1, r >>= 1;\n\t\t}\n\t\t\
    return ret;\n\t}\n\n\tint count_leq(int l, int r, T q) {\n\t\tl += n, r += n;\n\
    \t\tint ret = 0;\n\t\twhile(l < r) {\n\t\t\tif(l & 1){\n\t\t\t\tret += x[l].end()\
    \ - std::lower_bound(x[l].begin(), x[l].end(), q);\n\t\t\t\tl++;\n\t\t\t}\n\t\t\
    \tif(r & 1){\n\t\t\t\tr--;\n\t\t\t\tret += x[r].end() - std::lower_bound(x[r].begin(),\
    \ x[r].end(), q);\n\t\t\t}\n\t\t\tl >>= 1, r >>= 1;\n\t\t}\n\t\treturn ret;\n\t\
    }\n\n\tT sum_less(int l, int r, T q) {\n\t\tl += n, r += n;\n\t\tT ret = 0;\n\t\
    \twhile(l < r) {\n\t\t\tif(l & 1){\n\t\t\t\tret += cs[l][std::lower_bound(x[l].begin(),\
    \ x[l].end(), q) - x[l].begin()];\n\t\t\t\tl++;\n\t\t\t}\n\t\t\tif(r & 1){\n\t\
    \t\t\tr--;\n\t\t\t\tret += cs[r][std::lower_bound(x[r].begin(), x[r].end(), q)\
    \ - x[r].begin()];\n\t\t\t}\n\t\t\tl >>= 1, r >>= 1;\n\t\t}\n\t\treturn ret;\n\
    \t}\n\n\tT sum_leq(int l, int r, T q) {\n\t\tl += n, r += n;\n\t\tT ret = 0;\n\
    \t\twhile(l < r) {\n\t\t\tif(l & 1){\n\t\t\t\tret += cs[l].back() - cs[l][std::lower_bound(x[l].begin(),\
    \ x[l].end(), q) - x[l].begin()];\n\t\t\t\tl++;\n\t\t\t}\n\t\t\tif(r & 1){\n\t\
    \t\t\tr--;\n\t\t\t\tret += cs[r].back() - cs[r][std::lower_bound(x[r].begin(),\
    \ x[r].end(), q) - x[r].begin()];\n\t\t\t}\n\t\t\tl >>= 1, r >>= 1;\n\t\t}\n\t\
    \treturn ret;\n\t}\n};\n"
  code: "#pragma once\n\n#include<algorithm>\n#include<vector>\n\ntemplate<typename\
    \ T>\nstruct merge_sort_tree {\n\tint n;\n\tstd::vector<std::vector<T>> x, cs;\n\
    \tmerge_sort_tree(const std::vector<T> &v) : n(std::ssize(v)) {\n\t\tx.resize(n*2);\n\
    \t\tcs.resize(n*2);\n\t\tfor(int i = 0;i < n;i++)x[n+i] = {v[i]}, cs[n+i] = {0,\
    \ v[i]};\n\t\tfor(int i = n-1;i > 0;i--){\n\t\t\tstd::merge(x[i*2].begin(), x[i*2].end(),\
    \ x[i*2 + 1].begin(), x[i*2 + 1].end(), std::back_inserter(x[i]));\n\t\t\tcs[i].resize(std::ssize(x[i])\
    \ + 1);\n\t\t\tfor(int j = 0;j < std::ssize(x[i]);j++){\n\t\t\t\tcs[i][j+1] +=\
    \ cs[i][j] + x[i][j];\n\t\t\t}\n\t\t}\n\t}\n\tint count_less(int l, int r, T q)\
    \ {\n\t\tl += n, r += n;\n\t\tint ret = 0;\n\t\twhile(l < r) {\n\t\t\tif(l & 1){\n\
    \t\t\t\tret += std::lower_bound(x[l].begin(), x[l].end(), q) - x[l].begin();\n\
    \t\t\t\tl++;\n\t\t\t}\n\t\t\tif(r & 1){\n\t\t\t\tr--;\n\t\t\t\tret += std::lower_bound(x[r].begin(),\
    \ x[r].end(), q) - x[r].begin();\n\t\t\t}\n\t\t\tl >>= 1, r >>= 1;\n\t\t}\n\t\t\
    return ret;\n\t}\n\n\tint count_leq(int l, int r, T q) {\n\t\tl += n, r += n;\n\
    \t\tint ret = 0;\n\t\twhile(l < r) {\n\t\t\tif(l & 1){\n\t\t\t\tret += x[l].end()\
    \ - std::lower_bound(x[l].begin(), x[l].end(), q);\n\t\t\t\tl++;\n\t\t\t}\n\t\t\
    \tif(r & 1){\n\t\t\t\tr--;\n\t\t\t\tret += x[r].end() - std::lower_bound(x[r].begin(),\
    \ x[r].end(), q);\n\t\t\t}\n\t\t\tl >>= 1, r >>= 1;\n\t\t}\n\t\treturn ret;\n\t\
    }\n\n\tT sum_less(int l, int r, T q) {\n\t\tl += n, r += n;\n\t\tT ret = 0;\n\t\
    \twhile(l < r) {\n\t\t\tif(l & 1){\n\t\t\t\tret += cs[l][std::lower_bound(x[l].begin(),\
    \ x[l].end(), q) - x[l].begin()];\n\t\t\t\tl++;\n\t\t\t}\n\t\t\tif(r & 1){\n\t\
    \t\t\tr--;\n\t\t\t\tret += cs[r][std::lower_bound(x[r].begin(), x[r].end(), q)\
    \ - x[r].begin()];\n\t\t\t}\n\t\t\tl >>= 1, r >>= 1;\n\t\t}\n\t\treturn ret;\n\
    \t}\n\n\tT sum_leq(int l, int r, T q) {\n\t\tl += n, r += n;\n\t\tT ret = 0;\n\
    \t\twhile(l < r) {\n\t\t\tif(l & 1){\n\t\t\t\tret += cs[l].back() - cs[l][std::lower_bound(x[l].begin(),\
    \ x[l].end(), q) - x[l].begin()];\n\t\t\t\tl++;\n\t\t\t}\n\t\t\tif(r & 1){\n\t\
    \t\t\tr--;\n\t\t\t\tret += cs[r].back() - cs[r][std::lower_bound(x[r].begin(),\
    \ x[r].end(), q) - x[r].begin()];\n\t\t\t}\n\t\t\tl >>= 1, r >>= 1;\n\t\t}\n\t\
    \treturn ret;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/merge_sort_tree.hpp
  requiredBy: []
  timestamp: '2025-07-01 03:22:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yukicoder/3078.test.cpp
documentation_of: data_structure/merge_sort_tree.hpp
layout: document
title: merge-sort tree
---

# merge-sort tree

固定の列 A について、区間 $K$ 未満・区間 $K$ 未満の和を $O((\log{N})^2)$ で求めるデータ構造

## 使い方

- ``merge_sort_tree(vector<T> A)`` : コンストラクタ
- ``count_less(int l, int r, T q)`` : $[l, r)$ かつ $A_i < q$ を満たす要素の数を返す
- ``sum_less(int l, int r, T q)`` : $[l, r)$ かつ $A_i < q$ を満たす要素の和を返す
- ``count_leq(int l, int r, T q)`` : $[l, r)$ かつ $q \leq A_i$ を満たす要素の数を返す
- ``sum_leq(int l, int r, T q)`` : $[l, r)$ かつ $q \leq A_i$ を満たす要素の和を返す

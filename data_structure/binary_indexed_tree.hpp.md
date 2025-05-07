---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/dsl/2_B___BIT.test.cpp
    title: verify/aoj/dsl/2_B___BIT.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/dsl/2_E___BIT.test.cpp
    title: verify/aoj/dsl/2_E___BIT.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/binary_indexed_tree.hpp\"\n\ntemplate<typename\
    \ T>struct binary_indexed_tree {\n\tint n;\n\tvector<T> BIT;\n\tbinary_indexed_tree(int\
    \ n_) : n(n_ + 1), BIT(n, 0) {}\n\n\tvoid add(int i, T x){\n\t\tassert(1 <= i\
    \ && i <= n);\n\t\tfor(int idx = i;idx < n;idx += (idx & -idx)){\n\t\t\tBIT[idx]\
    \ += x;\n\t\t}\n\t}\n\t\n\tT sum(int i) {\n\t\tassert(1 <= i && i <= n);\n\t\t\
    T ret = 0;\n\t\tfor(int idx = i;idx > 0;idx -= (idx & -idx)){\n\t\t\tret += BIT[idx];\n\
    \t\t}\n\t\treturn ret;\n\t}\n};\n"
  code: "\ntemplate<typename T>struct binary_indexed_tree {\n\tint n;\n\tvector<T>\
    \ BIT;\n\tbinary_indexed_tree(int n_) : n(n_ + 1), BIT(n, 0) {}\n\n\tvoid add(int\
    \ i, T x){\n\t\tassert(1 <= i && i <= n);\n\t\tfor(int idx = i;idx < n;idx +=\
    \ (idx & -idx)){\n\t\t\tBIT[idx] += x;\n\t\t}\n\t}\n\t\n\tT sum(int i) {\n\t\t\
    assert(1 <= i && i <= n);\n\t\tT ret = 0;\n\t\tfor(int idx = i;idx > 0;idx -=\
    \ (idx & -idx)){\n\t\t\tret += BIT[idx];\n\t\t}\n\t\treturn ret;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/binary_indexed_tree.hpp
  requiredBy: []
  timestamp: '2025-03-09 13:19:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/dsl/2_E___BIT.test.cpp
  - verify/aoj/dsl/2_B___BIT.test.cpp
documentation_of: data_structure/binary_indexed_tree.hpp
layout: document
title: BIT(Binary Indexed Tree)
---

# BIT(Binary Indexed Tree)

## 使い方

- 要素数を $N$ とする
- ``binary_indexed_tree<T>(int n)`` : 要素数 $N$ の BIT を構築する
- ``add(int i, T x)`` : $i$ 番目に $x$ を加算する $O(\log(N))$
- ``sum(int i)`` : $[1, i]$ の総和を求める $O(\log(N))$

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/dsl/1_A.test.cpp
    title: verify/aoj/dsl/1_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/union_find.hpp\"\n\nstruct union_find {\n\
    \tvector<int> v;\n\n\tunion_find(size_t size) : v(size, -1) {}\n\n\tint root(int\
    \ x){\n\t\treturn (v[x] < 0 ? x : v[x] = root(v[x]));\n\t}\n\n\tbool is_root(int\
    \ x){\n\t\treturn root(x) == x;\n\t}\n\n\tvoid unite(int x, int y){\n\t\tx = root(x);\n\
    \t\ty = root(y);\n\t\tif(x != y){\n\t\t\tif(v[x] > v[y])swap(x, y);\n\t\t\tv[x]\
    \ += v[y];\n\t\t\tv[y] = x;\n\t\t}\n\t}\n\n\tbool is_same(int x,int y){\n\t\t\
    return root(x) == root(y);\n\t}\n\n\tint get_size(int x){\n\t\tx = root(x);\n\t\
    \treturn -v[x];\n\t}\n};\n"
  code: "\nstruct union_find {\n\tvector<int> v;\n\n\tunion_find(size_t size) : v(size,\
    \ -1) {}\n\n\tint root(int x){\n\t\treturn (v[x] < 0 ? x : v[x] = root(v[x]));\n\
    \t}\n\n\tbool is_root(int x){\n\t\treturn root(x) == x;\n\t}\n\n\tvoid unite(int\
    \ x, int y){\n\t\tx = root(x);\n\t\ty = root(y);\n\t\tif(x != y){\n\t\t\tif(v[x]\
    \ > v[y])swap(x, y);\n\t\t\tv[x] += v[y];\n\t\t\tv[y] = x;\n\t\t}\n\t}\n\n\tbool\
    \ is_same(int x,int y){\n\t\treturn root(x) == root(y);\n\t}\n\n\tint get_size(int\
    \ x){\n\t\tx = root(x);\n\t\treturn -v[x];\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/union_find.hpp
  requiredBy: []
  timestamp: '2024-05-28 06:08:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/dsl/1_A.test.cpp
documentation_of: data_structure/union_find.hpp
layout: document
title: Union-Find
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

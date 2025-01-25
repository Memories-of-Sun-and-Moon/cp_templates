---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/two_edge_connected_components.hpp
    title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/dsl/1_A.test.cpp
    title: verify/aoj/dsl/1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/grl/2_A.test.cpp
    title: verify/aoj/grl/2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/two_edge_connected_components.test.cpp
    title: verify/yosupo/two_edge_connected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/unionfind.test.cpp
    title: verify/yosupo/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/union_find.hpp\"\n\nstruct union_find {\n\
    \tvector<int> v;\n\tint g_size;\n\tint n;\n\n\tunion_find(size_t size) : v(size,\
    \ -1), g_size(size), n(size) {}\n\n\tint root(int x){\n\t\tassert(x < n);\n\t\t\
    return (v[x] < 0 ? x : v[x] = root(v[x]));\n\t}\n\n\tbool is_root(int x){\n\t\t\
    assert(x < n);\n\t\treturn root(x) == x;\n\t}\n\n\tbool unite(int x, int y){\n\
    \t\tassert(x < n && y < n);\n\t\tx = root(x);\n\t\ty = root(y);\n\t\tif(x != y){\n\
    \t\t\tif(v[x] > v[y])swap(x, y);\n\t\t\tv[x] += v[y];\n\t\t\tv[y] = x;\n\t\t\t\
    g_size--;\n\t\t\treturn true;\n\t\t}\n\t\treturn false;\n\t}\n\n\tbool is_same(int\
    \ x,int y){\n\t\tassert(x < n && y < n);\n\t\treturn root(x) == root(y);\n\t}\n\
    \n\tint get_size(int x){\n\t\tassert(x < n);\n\t\tx = root(x);\n\t\treturn -v[x];\n\
    \t}\n\n\tint groups_size(){\n\t\treturn g_size;\n\t}\n\n\tvector<vector<int>>\
    \ groups(){\n\t\tvector<vector<int>> member(n);\n\t\tfor(int i = 0;i < n;i++){\n\
    \t\t\tmember[root(i)].push_back(i);\n\t\t}\n\n\t\tvector<vector<int>> ret;\n\t\
    \tfor(int i = 0;i < n;i++){\n\t\t\tif(member[i].empty())continue;\n\t\t\tret.push_back(member[i]);\n\
    \t\t}\n\t\treturn ret;\n\t}\n};\n"
  code: "\nstruct union_find {\n\tvector<int> v;\n\tint g_size;\n\tint n;\n\n\tunion_find(size_t\
    \ size) : v(size, -1), g_size(size), n(size) {}\n\n\tint root(int x){\n\t\tassert(x\
    \ < n);\n\t\treturn (v[x] < 0 ? x : v[x] = root(v[x]));\n\t}\n\n\tbool is_root(int\
    \ x){\n\t\tassert(x < n);\n\t\treturn root(x) == x;\n\t}\n\n\tbool unite(int x,\
    \ int y){\n\t\tassert(x < n && y < n);\n\t\tx = root(x);\n\t\ty = root(y);\n\t\
    \tif(x != y){\n\t\t\tif(v[x] > v[y])swap(x, y);\n\t\t\tv[x] += v[y];\n\t\t\tv[y]\
    \ = x;\n\t\t\tg_size--;\n\t\t\treturn true;\n\t\t}\n\t\treturn false;\n\t}\n\n\
    \tbool is_same(int x,int y){\n\t\tassert(x < n && y < n);\n\t\treturn root(x)\
    \ == root(y);\n\t}\n\n\tint get_size(int x){\n\t\tassert(x < n);\n\t\tx = root(x);\n\
    \t\treturn -v[x];\n\t}\n\n\tint groups_size(){\n\t\treturn g_size;\n\t}\n\n\t\
    vector<vector<int>> groups(){\n\t\tvector<vector<int>> member(n);\n\t\tfor(int\
    \ i = 0;i < n;i++){\n\t\t\tmember[root(i)].push_back(i);\n\t\t}\n\n\t\tvector<vector<int>>\
    \ ret;\n\t\tfor(int i = 0;i < n;i++){\n\t\t\tif(member[i].empty())continue;\n\t\
    \t\tret.push_back(member[i]);\n\t\t}\n\t\treturn ret;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/union_find.hpp
  requiredBy:
  - graph/two_edge_connected_components.hpp
  timestamp: '2024-10-15 14:47:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/grl/2_A.test.cpp
  - verify/aoj/dsl/1_A.test.cpp
  - verify/yosupo/two_edge_connected_components.test.cpp
  - verify/yosupo/unionfind.test.cpp
documentation_of: data_structure/union_find.hpp
layout: document
title: Union-Find
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

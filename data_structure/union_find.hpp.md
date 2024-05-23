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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bits/stdc++.h:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"bits/stdc++.h\"\nusing namespace std;\n\nstruct\
    \ union_find {\n\tvector<int> v;\n\n\tunion_find(size_t size) : v(size, -1) {}\n\
    \n\tint root(int x){\n\t\treturn (v[x] < 0 ? x : v[x] = root(v[x]));\n\t}\n\n\t\
    bool is_root(int x){\n\t\treturn root(x) == x;\n\t}\n\n\tvoid unite(int x, int\
    \ y){\n\t\tx = root(x);\n\t\ty = root(y);\n\t\tif(x != y){\n\t\t\tif(v[x] > v[y])swap(x,\
    \ y);\n\t\t\tv[x] += v[y];\n\t\t\tv[y] = x;\n\t\t}\n\t}\n\n\tbool is_same(int\
    \ x,int y){\n\t\treturn root(x) == root(y);\n\t}\n\n\tint get_size(int x){\n\t\
    \tx = root(x);\n\t\treturn -v[x];\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/union_find.hpp
  requiredBy: []
  timestamp: '2024-05-23 23:47:56+09:00'
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

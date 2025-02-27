---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/dsl/2_A___segment_tree_0-indexed.test.cpp
    title: verify/aoj/dsl/2_A___segment_tree_0-indexed.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/dsl/2_B___segment_tree_0-indexed.test.cpp
    title: verify/aoj/dsl/2_B___segment_tree_0-indexed.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/segment_tree_0-indexed.hpp\"\n\ntemplate<typename\
    \ T>struct [[deprecated(\"use 1-indexed segment tree (segment_tree.hpp)\")]] segment_tree\
    \ {\n\tusing F = function<T(T, T)>;\n\n\tint n;\n\tvector<T> node;\n\tF combine;\n\
    \tT identify;\n\n\tsegment_tree(vector<T> v, F _combine, T _identity) : combine(_combine),\
    \ identify(_identity) {\n\t\tint sz = (int)v.size();\n\t\tn = 1;\n\t\twhile(n\
    \ < sz)n *= 2;\n\t\tnode.resize(2 * n - 1, identify);\n\n\t\tfor(int i = 0;i <\
    \ sz;i++)node[i + n - 1] = v[i];\n\t\tfor(int i = n - 2;i >= 0;i--)node[i] = combine(node[2\
    \ * i + 1], node[2 * i + 2]);\n\t}\n\n\tsegment_tree(int _n, F _combine, T _identify)\
    \ : combine(_combine), identify(_identify){\n\t\tint sz = _n;\n\t\tn = 1;\n\t\t\
    while(n < sz)n *= 2;\n\t\tnode.resize(2 * n - 1, identify);\n\t}\n\n\tT operator[](int\
    \ x) {return node[x + n - 1]; }\n\n\tvoid set(int x, T val){\n\t\tx += (n - 1);\n\
    \n\t\tnode[x] = val;\n\t\twhile(x > 0){\n\t\t\tx = (x - 1) / 2;\n\t\t\tnode[x]\
    \ = combine(node[2 * x + 1], node[2 * x + 2]);\n\t\t}\n\t}\n\n\tT fold(int a,\
    \ int b, int k = 0, int l = 0, int r = -1){\n\t\tif(r < 0) r = n;\n\n\t\tif(r\
    \ <= a || b <= l)return identify;\n\t\t\n\t\tif(a <= l && r <= b)return node[k];\n\
    \n\t\tT vl = fold(a, b, 2 * k + 1, l, (l + r) / 2);\n\t\tT vr = fold(a, b, 2 *\
    \ k + 2, (l + r) / 2, r);\n\t\treturn combine(vl, vr);\n\t}\n};\n"
  code: "\ntemplate<typename T>struct [[deprecated(\"use 1-indexed segment tree (segment_tree.hpp)\"\
    )]] segment_tree {\n\tusing F = function<T(T, T)>;\n\n\tint n;\n\tvector<T> node;\n\
    \tF combine;\n\tT identify;\n\n\tsegment_tree(vector<T> v, F _combine, T _identity)\
    \ : combine(_combine), identify(_identity) {\n\t\tint sz = (int)v.size();\n\t\t\
    n = 1;\n\t\twhile(n < sz)n *= 2;\n\t\tnode.resize(2 * n - 1, identify);\n\n\t\t\
    for(int i = 0;i < sz;i++)node[i + n - 1] = v[i];\n\t\tfor(int i = n - 2;i >= 0;i--)node[i]\
    \ = combine(node[2 * i + 1], node[2 * i + 2]);\n\t}\n\n\tsegment_tree(int _n,\
    \ F _combine, T _identify) : combine(_combine), identify(_identify){\n\t\tint\
    \ sz = _n;\n\t\tn = 1;\n\t\twhile(n < sz)n *= 2;\n\t\tnode.resize(2 * n - 1, identify);\n\
    \t}\n\n\tT operator[](int x) {return node[x + n - 1]; }\n\n\tvoid set(int x, T\
    \ val){\n\t\tx += (n - 1);\n\n\t\tnode[x] = val;\n\t\twhile(x > 0){\n\t\t\tx =\
    \ (x - 1) / 2;\n\t\t\tnode[x] = combine(node[2 * x + 1], node[2 * x + 2]);\n\t\
    \t}\n\t}\n\n\tT fold(int a, int b, int k = 0, int l = 0, int r = -1){\n\t\tif(r\
    \ < 0) r = n;\n\n\t\tif(r <= a || b <= l)return identify;\n\t\t\n\t\tif(a <= l\
    \ && r <= b)return node[k];\n\n\t\tT vl = fold(a, b, 2 * k + 1, l, (l + r) / 2);\n\
    \t\tT vr = fold(a, b, 2 * k + 2, (l + r) / 2, r);\n\t\treturn combine(vl, vr);\n\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segment_tree_0-indexed.hpp
  requiredBy: []
  timestamp: '2024-06-09 16:05:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/dsl/2_B___segment_tree_0-indexed.test.cpp
  - verify/aoj/dsl/2_A___segment_tree_0-indexed.test.cpp
documentation_of: data_structure/segment_tree_0-indexed.hpp
layout: document
title: "0-indexed\u306E\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---

# 0-indexedのセグメント木

## 使い方

- $N$ を要素数

とする。

また、要素の取り方は **0-indexed** であることに注意する。

- ``segment_tree<T>(int N, auto combine, T identify)`` : 要素数 $N$ の セグメント木を生成する
- ``segment_tree<T>(vector<T> v, auto combine, T identify)`` : 要素数 $N$ で、 ``vector<T> v`` で初期化されたセグメント木を生成する
- ``void set(int x, T val)`` : $x$ 番目の要素を $val$ に変更する  $O(\log(N))$
- ``T fold(int l, int r)`` : $[l, r)$ を満たす区間内に対する区間演算クエリの結果を返す $O(\log(N))$
- ``seg[x]`` : $x$ 番目の値を返す。$O(1)$

## 概要

完全二分木は 1-indexed で作った方が何かと便利なため、これは観賞用である（ただ、[0-indexedの完全二分木の考え方が本質な問題](https://atcoder.jp/contests/abc349/tasks/abc349_d)があったため、こちらも残しておく）。

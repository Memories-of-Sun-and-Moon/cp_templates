---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/dsl/2_A___segment_tree.test.cpp
    title: verify/aoj/dsl/2_A___segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/dsl/2_B___segment_tree.test.cpp
    title: verify/aoj/dsl/2_B___segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/1435.test.cpp
    title: verify/yukicoder/1435.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/segment_tree.hpp\"\n\ntemplate<typename T>struct\
    \ segment_tree {\n\tusing F = function<T(T, T)>;\n\n\tint offset;\n\tint n;\n\t\
    vector<T> node;\n\tF combine;\n\tT identify;\n\n\tsegment_tree(int _n, F _combine,\
    \ T _identify) : segment_tree(vector<T>(_n, _identify), _combine, _identify) {}\n\
    \n\tsegment_tree(vector<T> v, F _combine, T _identify) : combine(_combine), identify(_identify)\
    \ {\n\t\tn = (int)v.size();\n\t\toffset = 1;\n\t\twhile(offset < n)offset <<=\
    \ 1;\n\n\t\tnode.resize(2*offset, identify);\n\n\t\tfor(int i = 0;i < n;i++)node[i\
    \ + offset] = v[i];\n\t\tfor(int i = offset - 1;i >= 1;i--)node[i] = combine(node[2\
    \ * i + 0], node[2 * i + 1]);\n\t}\n\n\tT operator[](int x) {return node[x + offset];\
    \ }\n\n\tvoid set(int x, T val){\n\t\tx += offset;\n\n\t\tnode[x] = val;\n\t\t\
    while(x >>= 1){;\n\t\t\tnode[x] = combine(node[2 * x + 0], node[2 * x + 1]);\n\
    \t\t}\n\t}\n\n\tT fold(int a, int b){\n\t\tT L = identify, R = identify;\n\t\t\
    for(a += offset, b += offset; a < b;a >>= 1, b >>= 1){\n\t\t\tif(a&1)L = combine(L,\
    \ node[a++]);\n\t\t\tif(b&1)R = combine(node[--b], R);\n\t\t}\n\t\treturn combine(L,\
    \ R);\n\t}\n\n\tint max_right(const function<bool(T)> f, int l = 0){\n\t\tif(l\
    \ == n)return n;\n\t\tl += offset;\n\t\tT sum = identify;\n\t\tdo{\n\t\t\twhile(l%2\
    \ == 0)l >>= 1;\n\t\t\tif(not f(combine(sum, node[l]))){\n\t\t\t\twhile(l < offset){\n\
    \t\t\t\t\tl <<= 1;\n\t\t\t\t\tif(f(combine(sum, node[l]))){\n\t\t\t\t\t\tsum =\
    \ combine(sum, node[l]);\n\t\t\t\t\t\t++l;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\treturn\
    \ l - offset;\n\t\t\t}\n\t\t\tsum = combine(sum, node[l]);\n\t\t\t++l;\n\t\t}while((l&-l)\
    \ != l);\n\t\treturn n;\n\t}\n\n\tint min_left(const function<bool(T)> f, int\
    \ r = -1){\n\t\tif(r == 0)return 0;\n\t\tif(r == -1)r = n;\n\t\tr += offset;\n\
    \t\tT sum = identify;\n\t\tdo{\n\t\t\t--r;\n\t\t\twhile(r > 1 && (r % 2))r >>=\
    \ 1;\n\t\t\tif(not f(combine(node[r], sum))){\n\t\t\t\twhile(r < offset){\n\t\t\
    \t\t\tr = r*2 + 1;\n\t\t\t\t\tif(f(combine(node[r], sum))){\n\t\t\t\t\t\tsum =\
    \ combine(node[r], sum);\n\t\t\t\t\t\t--r;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\treturn\
    \ r+1 - offset;\n\t\t\t}\n\t\t\tsum = combine(node[r], sum);\n\t\t}while((r&-r)\
    \ != r);\n\t\treturn 0;\n\t}\n};\n"
  code: "\ntemplate<typename T>struct segment_tree {\n\tusing F = function<T(T, T)>;\n\
    \n\tint offset;\n\tint n;\n\tvector<T> node;\n\tF combine;\n\tT identify;\n\n\t\
    segment_tree(int _n, F _combine, T _identify) : segment_tree(vector<T>(_n, _identify),\
    \ _combine, _identify) {}\n\n\tsegment_tree(vector<T> v, F _combine, T _identify)\
    \ : combine(_combine), identify(_identify) {\n\t\tn = (int)v.size();\n\t\toffset\
    \ = 1;\n\t\twhile(offset < n)offset <<= 1;\n\n\t\tnode.resize(2*offset, identify);\n\
    \n\t\tfor(int i = 0;i < n;i++)node[i + offset] = v[i];\n\t\tfor(int i = offset\
    \ - 1;i >= 1;i--)node[i] = combine(node[2 * i + 0], node[2 * i + 1]);\n\t}\n\n\
    \tT operator[](int x) {return node[x + offset]; }\n\n\tvoid set(int x, T val){\n\
    \t\tx += offset;\n\n\t\tnode[x] = val;\n\t\twhile(x >>= 1){;\n\t\t\tnode[x] =\
    \ combine(node[2 * x + 0], node[2 * x + 1]);\n\t\t}\n\t}\n\n\tT fold(int a, int\
    \ b){\n\t\tT L = identify, R = identify;\n\t\tfor(a += offset, b += offset; a\
    \ < b;a >>= 1, b >>= 1){\n\t\t\tif(a&1)L = combine(L, node[a++]);\n\t\t\tif(b&1)R\
    \ = combine(node[--b], R);\n\t\t}\n\t\treturn combine(L, R);\n\t}\n\n\tint max_right(const\
    \ function<bool(T)> f, int l = 0){\n\t\tif(l == n)return n;\n\t\tl += offset;\n\
    \t\tT sum = identify;\n\t\tdo{\n\t\t\twhile(l%2 == 0)l >>= 1;\n\t\t\tif(not f(combine(sum,\
    \ node[l]))){\n\t\t\t\twhile(l < offset){\n\t\t\t\t\tl <<= 1;\n\t\t\t\t\tif(f(combine(sum,\
    \ node[l]))){\n\t\t\t\t\t\tsum = combine(sum, node[l]);\n\t\t\t\t\t\t++l;\n\t\t\
    \t\t\t}\n\t\t\t\t}\n\t\t\t\treturn l - offset;\n\t\t\t}\n\t\t\tsum = combine(sum,\
    \ node[l]);\n\t\t\t++l;\n\t\t}while((l&-l) != l);\n\t\treturn n;\n\t}\n\n\tint\
    \ min_left(const function<bool(T)> f, int r = -1){\n\t\tif(r == 0)return 0;\n\t\
    \tif(r == -1)r = n;\n\t\tr += offset;\n\t\tT sum = identify;\n\t\tdo{\n\t\t\t\
    --r;\n\t\t\twhile(r > 1 && (r % 2))r >>= 1;\n\t\t\tif(not f(combine(node[r], sum))){\n\
    \t\t\t\twhile(r < offset){\n\t\t\t\t\tr = r*2 + 1;\n\t\t\t\t\tif(f(combine(node[r],\
    \ sum))){\n\t\t\t\t\t\tsum = combine(node[r], sum);\n\t\t\t\t\t\t--r;\n\t\t\t\t\
    \t}\n\t\t\t\t}\n\t\t\t\treturn r+1 - offset;\n\t\t\t}\n\t\t\tsum = combine(node[r],\
    \ sum);\n\t\t}while((r&-r) != r);\n\t\treturn 0;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segment_tree.hpp
  requiredBy: []
  timestamp: '2024-09-21 12:51:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/dsl/2_B___segment_tree.test.cpp
  - verify/aoj/dsl/2_A___segment_tree.test.cpp
  - verify/yukicoder/1435.test.cpp
documentation_of: data_structure/segment_tree.hpp
layout: document
title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---

# セグメント木

## 使い方

- $N$ を要素数

とする。

また、要素の取り方は **0-indexed** であることに注意する。

- ``segment_tree<T>(int N, auto combine, T identify)`` : 要素数 $N$ の セグメント木を生成する
- ``segment_tree<T>(vector<T> v, auto combine, T identify)`` : 要素数 $N$ で、 ``vector<T> v`` で初期化されたセグメント木を生成する
- ``void set(int x, T val)`` : $x$ 番目の要素を $val$ に変更する  $O(\log(N))$
- ``T fold(int l, int r)`` : $[l, r)$ を満たす区間内に対する区間演算クエリの結果を返す $O(\log(N))$
- ``seg[x]`` : $x$ 番目の値を返す。$O(1)$
- ``max_right(f<bool(T)>, l)`` : $l \leq i < N$ のうち、各要素に対する条件 $f$ を満たすもののなかで最も最大（ $N-1$ 寄り）のものを返す $O(\log(N))$

## !!!UNVERIFIED!!!

- ``min_left(f<bool(T)>, r)`` : $0 \leq i \leq r$ のうち、各要素に対する条件 $f$ を満たすもののなかで最も最小（ $0$ 寄り）のものを返す $O(\log(N))$


## 概要

内部で完全二分木を **1-indexed** で構築している。こちらの方が定数倍がよく、また ``max_right()`` なども実装しやすい

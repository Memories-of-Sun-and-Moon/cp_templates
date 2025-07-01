---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/static_range_frequency.test.cpp
    title: verify/yosupo/static_range_frequency.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/mo.hpp\"\n\n#include<algorithm>\n#include<cmath>\n\
    #include<numeric>\n#include<ranges>\n#include<utility>\n#include<vector>\n\nclass\
    \ Mo {\n\tstd::vector<std::pair<int, int>> lr;\npublic:\n\tMo() = default;\n\t\
    Mo(const std::vector<std::pair<int, int>> &_lr) : lr(_lr) {}\n\n\ttemplate<typename\
    \ AL, typename AR, typename EL, typename ER, typename F>\n\tvoid calc(const AL\
    \ &add_left, const AR &add_right, const EL &erase_left, const ER& erase_right,\
    \ const F &f, int _n = -1, int _B = -1){\n\t\tint n = (_n == -1 ? std::ranges::max(lr,\
    \ {}, &std::pair<int, int>::second).second : _n);\n\t\tint q = (int)lr.size();\n\
    \t\tint B = (_B == -1 ? std::max(1, n/int(sqrt(q))) : _B);\n\n\t\tstd::vector<int>\
    \ index(q);\n\t\tstd::iota(index.begin(), index.end(), 0);\n\t\tstd::sort(index.begin(),\
    \ index.end(), [&](int i, int j){\n\t\t\tconst auto &[l_i, r_i] = lr[i];\n\t\t\
    \tconst auto &[l_j, r_j] = lr[j];\n\t\t\tconst int B_i = l_i / B, B_j = l_j /\
    \ B;\n\t\t\tif(B_i != B_j){\n\t\t\t\treturn B_i < B_j;\n\t\t\t}\n\t\t\tif(B_i\
    \ & 1){\n\t\t\t\treturn r_j < r_i;\n\t\t\t}else{\n\t\t\t\treturn r_i < r_j;\n\t\
    \t\t}\n\t\t});\n\n\t\tint l = 0, r = 0;\n\t\tfor(int idx : index){\n\t\t\tconst\
    \ auto &[L, R] = lr[idx];\n\n\t\t\twhile(L < l)add_left(--l);\n\t\t\twhile(r <\
    \ R)add_right(r++);\n\t\t\t\n\t\t\twhile(l < L)erase_left(l++);\n\t\t\twhile(R\
    \ < r)erase_right(--r);\n\n\t\t\tf(idx);\n\t\t}\n\t}\n\n\ttemplate<typename A,\
    \ typename E, typename F>\n\tvoid calc(const A &add, const E &erase, const F &f){\n\
    \t\tcalc(add, add, erase, erase, f);\n\t}\n};\n"
  code: "#pragma once\n\n#include<algorithm>\n#include<cmath>\n#include<numeric>\n\
    #include<ranges>\n#include<utility>\n#include<vector>\n\nclass Mo {\n\tstd::vector<std::pair<int,\
    \ int>> lr;\npublic:\n\tMo() = default;\n\tMo(const std::vector<std::pair<int,\
    \ int>> &_lr) : lr(_lr) {}\n\n\ttemplate<typename AL, typename AR, typename EL,\
    \ typename ER, typename F>\n\tvoid calc(const AL &add_left, const AR &add_right,\
    \ const EL &erase_left, const ER& erase_right, const F &f, int _n = -1, int _B\
    \ = -1){\n\t\tint n = (_n == -1 ? std::ranges::max(lr, {}, &std::pair<int, int>::second).second\
    \ : _n);\n\t\tint q = (int)lr.size();\n\t\tint B = (_B == -1 ? std::max(1, n/int(sqrt(q)))\
    \ : _B);\n\n\t\tstd::vector<int> index(q);\n\t\tstd::iota(index.begin(), index.end(),\
    \ 0);\n\t\tstd::sort(index.begin(), index.end(), [&](int i, int j){\n\t\t\tconst\
    \ auto &[l_i, r_i] = lr[i];\n\t\t\tconst auto &[l_j, r_j] = lr[j];\n\t\t\tconst\
    \ int B_i = l_i / B, B_j = l_j / B;\n\t\t\tif(B_i != B_j){\n\t\t\t\treturn B_i\
    \ < B_j;\n\t\t\t}\n\t\t\tif(B_i & 1){\n\t\t\t\treturn r_j < r_i;\n\t\t\t}else{\n\
    \t\t\t\treturn r_i < r_j;\n\t\t\t}\n\t\t});\n\n\t\tint l = 0, r = 0;\n\t\tfor(int\
    \ idx : index){\n\t\t\tconst auto &[L, R] = lr[idx];\n\n\t\t\twhile(L < l)add_left(--l);\n\
    \t\t\twhile(r < R)add_right(r++);\n\t\t\t\n\t\t\twhile(l < L)erase_left(l++);\n\
    \t\t\twhile(R < r)erase_right(--r);\n\n\t\t\tf(idx);\n\t\t}\n\t}\n\n\ttemplate<typename\
    \ A, typename E, typename F>\n\tvoid calc(const A &add, const E &erase, const\
    \ F &f){\n\t\tcalc(add, add, erase, erase, f);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/mo.hpp
  requiredBy: []
  timestamp: '2025-07-01 03:22:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo/static_range_frequency.test.cpp
documentation_of: data_structure/mo.hpp
layout: document
title: Mo's Algorithm
---

# Mo's Algorithm

## 使い方

- $N$ を要素数
- $B$ をクエリ中の $L$ を分割するブロックの幅とする

とする（実装の詳細は具体的な実装例を見た方が早い）。

- ``Mo(pair<int, int> query)`` : コンストラクタ。クエリの情報を与える（クエリは **0-indexed**）。
- ``void calc(auto &add, auto &erase, &f, int n=-1, int B=-1)`` : すべてのクエリに対する答えを計算する。
  - ``add`` は区間を $1$ 増やす操作を行う関数
  - ``erase`` は区間を $1$ 減らす操作を行う関数
  - 操作後に、その区間の解が求まっている状態にする必要がある。
  - ``f`` は区間が一致したクエリに対する答えを格納する。答えの情報は外部に保存されるように実装する。
  - 解を求めるための操作は、外の変数や配列を見て行えるようにする必要がある。
  - $N$, $B$ は要素数およびブロック数
- ``void calc(auto &add_left, &add_right, &erase_left, &erase_right, auto &erase, &f, int n=-1, int B=-1)`` : すべてのクエリに対する答えを計算する。
  - ``add_left, add_right`` は区間を $1$ 増やす操作を行う関数
  - ``erase_left, erase_right`` は区間を $1$ 減らす操作を行う関数
  - 操作後に、その区間の解が求まっている状態にする必要がある。
  - ``f`` は区間が一致したクエリに対する答えを格納する。答えの情報は外部に保存されるように実装する。
  - 解を求めるための操作は、外の変数や配列を見て行えるようにする必要がある。
  - $N$, $B$ は要素数およびブロック数

計算量は、区間を $1$ 変更する操作を $O(1)$ としたとき、 $O(QB+\frac{N^2}{B})$

特に $B = \frac{N}{\sqrt{Q}}$ の時、 $O(N\sqrt{Q})$

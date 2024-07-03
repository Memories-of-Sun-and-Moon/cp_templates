---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/static_range_frequency.test.cpp
    title: verify/yosupo/static_range_frequency.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/mo.hpp\"\nclass Mo {\n    vector<pair<int,\
    \ int>> lr;\npublic:\n    Mo() = default;\n    Mo(const vector<pair<int, int>>\
    \ &_lr) : lr(_lr) {}\n\n    template<typename AL, typename AR, typename EL, typename\
    \ ER, typename F>\n    void calc(const AL &add_left, const AR &add_right, const\
    \ EL &erase_left, const ER& erase_right, const F &f, int _n = -1, int _B = -1){\n\
    \        int n = (_n == -1 ? ranges::max(lr, {}, &pair<int, int>::second).second\
    \ : _n);\n        int q = (int)lr.size();\n        int B = (_B == -1 ? max(1,\
    \ n/int(sqrt(q))) : _B);\n\n        vector<int> index(q);\n        iota(index.begin(),\
    \ index.end(), 0);\n        sort(index.begin(), index.end(), [&](int i, int j){\n\
    \            const auto &[l_i, r_i] = lr[i];\n            const auto &[l_j, r_j]\
    \ = lr[j];\n            const int B_i = l_i / B, B_j = l_j / B;\n            return\
    \ (B_i != B_j ? (B_i < B_j) : (r_i < r_j));\n        });\n\n        int l = 0,\
    \ r = 0;\n        for(int idx : index){\n            const auto &[L, R] = lr[idx];\n\
    \n            while(L < l)add_left(--l);\n            while(l < L)erase_left(l++);\n\
    \            \n            while(r < R)add_right(r++);\n            while(R <\
    \ r)erase_right(--r);\n\n            f(idx);\n        }\n    }\n\n    template<typename\
    \ A, typename E, typename F>\n    void calc(const A &add, const E &erase, const\
    \ F &f){\n        calc(add, add, erase, erase, f);\n    }\n};\n"
  code: "class Mo {\n    vector<pair<int, int>> lr;\npublic:\n    Mo() = default;\n\
    \    Mo(const vector<pair<int, int>> &_lr) : lr(_lr) {}\n\n    template<typename\
    \ AL, typename AR, typename EL, typename ER, typename F>\n    void calc(const\
    \ AL &add_left, const AR &add_right, const EL &erase_left, const ER& erase_right,\
    \ const F &f, int _n = -1, int _B = -1){\n        int n = (_n == -1 ? ranges::max(lr,\
    \ {}, &pair<int, int>::second).second : _n);\n        int q = (int)lr.size();\n\
    \        int B = (_B == -1 ? max(1, n/int(sqrt(q))) : _B);\n\n        vector<int>\
    \ index(q);\n        iota(index.begin(), index.end(), 0);\n        sort(index.begin(),\
    \ index.end(), [&](int i, int j){\n            const auto &[l_i, r_i] = lr[i];\n\
    \            const auto &[l_j, r_j] = lr[j];\n            const int B_i = l_i\
    \ / B, B_j = l_j / B;\n            return (B_i != B_j ? (B_i < B_j) : (r_i < r_j));\n\
    \        });\n\n        int l = 0, r = 0;\n        for(int idx : index){\n   \
    \         const auto &[L, R] = lr[idx];\n\n            while(L < l)add_left(--l);\n\
    \            while(l < L)erase_left(l++);\n            \n            while(r <\
    \ R)add_right(r++);\n            while(R < r)erase_right(--r);\n\n           \
    \ f(idx);\n        }\n    }\n\n    template<typename A, typename E, typename F>\n\
    \    void calc(const A &add, const E &erase, const F &f){\n        calc(add, add,\
    \ erase, erase, f);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/mo.hpp
  requiredBy: []
  timestamp: '2024-07-03 18:57:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
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

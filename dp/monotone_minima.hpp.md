---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dp/monotone_minima.hpp\"\n\n// argmin(i,l,r) : argmin_{j\\\
    in[l,r)} A[i][j]\ntemplate<typename F>\nvector<int> monotone_minima(int n, int\
    \ m, const F &argmin){\n\tvector<int> ret(n);\n\n\t//submatrix [u, d) * [l, r)\n\
    \tqueue<tuple<int, int, int, int>> q;\n\tq.push({0, n, 0, m});\n\n\twhile(not\
    \ q.empty()){\n\t\tauto [u, d, l, r] = q.front();\n\t\tq.pop();\n\n\t\tif(u ==\
    \ d)continue;\n\t\tint mid = (u+d) >> 1;\n\t\tret[mid] = argmin(mid, l, r);\n\t\
    \tq.push({u, mid, l, ret[mid]+1});\n\t\tq.push({mid+1, d, ret[mid], r});\n\t}\n\
    \n\treturn ret;\n}\n"
  code: "\n// argmin(i,l,r) : argmin_{j\\in[l,r)} A[i][j]\ntemplate<typename F>\n\
    vector<int> monotone_minima(int n, int m, const F &argmin){\n\tvector<int> ret(n);\n\
    \n\t//submatrix [u, d) * [l, r)\n\tqueue<tuple<int, int, int, int>> q;\n\tq.push({0,\
    \ n, 0, m});\n\n\twhile(not q.empty()){\n\t\tauto [u, d, l, r] = q.front();\n\t\
    \tq.pop();\n\n\t\tif(u == d)continue;\n\t\tint mid = (u+d) >> 1;\n\t\tret[mid]\
    \ = argmin(mid, l, r);\n\t\tq.push({u, mid, l, ret[mid]+1});\n\t\tq.push({mid+1,\
    \ d, ret[mid], r});\n\t}\n\n\treturn ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/monotone_minima.hpp
  requiredBy: []
  timestamp: '2024-06-05 00:58:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/monotone_minima.hpp
layout: document
title: "Monotone\u306A\u884C\u5217\u306B\u304A\u3051\u308B\u884C\u6700\u5C0F\u5024\
  \u554F\u984C(monotone-minima)"
---

# Monotoneな行列における行最小値問題(monotone-minima)

## 使い方

- ``vector<int> monotone_minima(int n, int m, const F &argmin)`` : $N$ 行 $M$ 列の Monotone な行列について、$i$ 行目の $[l, r)$ 列の $\arg\min$ を求める関数を用意したとき、その行列における各行の最小値を求める $O(N + \sigma M \log N )$

ただし、 $\sigma$ を $\arg\min$ を求める計算量とする。

## 概要

$\arg \min_j A_{i,j}$ が $i$ について講義単調増加である時、 $A$ は Monotone であるという。

$A$ が Monotone であれば、 $\arg \min_j A_{i,j}$ が $j$ であると分かったとき、$A_{i, j}$ の右上と左下には $\min_j A_{i, j}$ となる要素が存在しない。よって、分割統治の要領で効率的に最小値を求めることができる。

引数に $A$ を渡してしまった場合、それだけで $O(NM)$ かかることに注意したい。

## Verify

[スペースエクスプローラー高橋君](https://atcoder.jp/contests/colopl2018-final-open/submissions/54235541)

## 参考

Acompany勉強会 2024/06/04 Monge 入門

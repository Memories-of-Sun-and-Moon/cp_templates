---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/id/2286.test.cpp
    title: verify/aoj/id/2286.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/euler_phi_table.hpp\"\n\nvector<int> euler_phi_table(int\
    \ n){\n\tvector<int> phi(n + 1);\n\tfor(int i = 0;i <= n;i++){\n\t\tphi[i] = i;\n\
    \t}\n\tfor(int i = 2;i <= n;i++){\n\t\tif(phi[i] == i){\n\t\t\tfor(int j = i;j\
    \ <= n;j += i){\n\t\t\t\tphi[j] = phi[j] / i * (i - 1);\n\t\t\t}\n\t\t}\n\t}\n\
    \treturn phi;\n}\n"
  code: "\nvector<int> euler_phi_table(int n){\n\tvector<int> phi(n + 1);\n\tfor(int\
    \ i = 0;i <= n;i++){\n\t\tphi[i] = i;\n\t}\n\tfor(int i = 2;i <= n;i++){\n\t\t\
    if(phi[i] == i){\n\t\t\tfor(int j = i;j <= n;j += i){\n\t\t\t\tphi[j] = phi[j]\
    \ / i * (i - 1);\n\t\t\t}\n\t\t}\n\t}\n\treturn phi;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/euler_phi_table.hpp
  requiredBy: []
  timestamp: '2024-05-28 06:25:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/id/2286.test.cpp
documentation_of: math/euler_phi_table.hpp
layout: document
title: "\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\u6570\uFF08\u30AA\u30A4\u30E9\u30FC\
  \u306E\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570\uFF09\u30C6\u30FC\u30D6\u30EB"
---

# オイラーのφ関数（オイラーのトーシェント関数）テーブル

## 使い方

- ``vector<int> euler_phi_table(int n)`` : $\phi(x)$ ($1 \leq x \leq n$) が配列の添え字 $1, 2, \cdots ,n$ に格納された長さ $n+1$ の配列を返す $O(N \log N \log N)$

## 概要

$\phi(n)$ : $1$ から $n$ までの自然数のうち、 $n$ と互いに素なものの個数

$\phi(n) = \prod_{p \mid n} \left(1 - \frac{1}{p}\right)$

これを、素因数側から求めることによって、$\phi(x)$ ($1 \leq x \leq n$) についてまとめて計算することが可能となる。

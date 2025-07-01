---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/enumerate_divisors.hpp
    title: "\u7D04\u6570\u5217\u6319"
  - icon: ':heavy_check_mark:'
    path: math/euler_phi.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\u6570\uFF08\u30AA\u30A4\u30E9\
      \u30FC\u306E\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570\uFF09"
  - icon: ':heavy_check_mark:'
    path: math/factor.hpp
    title: "\u7D20\u56E0\u6570\u5206\u89E3\uFF08\u30DD\u30E9\u30FC\u30C9\u30FB\u30ED\
      \u30FC\u6CD5\uFF09"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/id/1642.test.cpp
    title: verify/aoj/id/1642.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/ntl/1_D.test.cpp
    title: verify/aoj/ntl/1_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/factorize.test.cpp
    title: verify/yosupo/factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/primality_test.test.cpp
    title: verify/yosupo/primality_test.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/is_prime.hpp\"\n\n#include<vector>\n\n__int128_t __power(__int128_t\
    \ n, __int128_t k, __int128_t m) {\n\tn %= m;\n\t__int128_t ret = 1;\n\twhile(k\
    \ > 0){\n\t\tif(k & 1)ret = ret * n % m;\n\t\tn = __int128_t(n) * n % m;\n\t\t\
    k >>= 1;\n\t}\n\treturn ret % m;\n}\n\nbool is_prime(long long n){\n\tif(n <=\
    \ 1)return false;\n\tif(n == 2 || n == 3 || n == 5)return true;\n\tif(n % 2 ==\
    \ 0)return false;\n\tif(n % 3 == 0)return false;\n\tif(n % 5 == 0)return false;\n\
    \n\tstd::vector<long long> A = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};\n\
    \n\tlong long s = 0, d = n - 1;\n\twhile(d % 2 == 0){\n\t\ts++;\n\t\td >>= 1;\n\
    \t}\n\n\tfor (auto a : A){\n\t\tif(a % n == 0)return true;\n\t\tlong long t, x\
    \ = __power(a, d, n);\n\t\tif(x != 1){\n\t\t\tfor(t = 0;t < s;t++){\n\t\t\t\t\
    if(x == n - 1)break;\n\t\t\t\tx = __int128_t(x) * x % n;\n\t\t\t}\n\t\t\tif(t\
    \ == s)return false;\n\t\t}\n\t}\n\treturn true;\n}\n"
  code: "#pragma once\n\n#include<vector>\n\n__int128_t __power(__int128_t n, __int128_t\
    \ k, __int128_t m) {\n\tn %= m;\n\t__int128_t ret = 1;\n\twhile(k > 0){\n\t\t\
    if(k & 1)ret = ret * n % m;\n\t\tn = __int128_t(n) * n % m;\n\t\tk >>= 1;\n\t\
    }\n\treturn ret % m;\n}\n\nbool is_prime(long long n){\n\tif(n <= 1)return false;\n\
    \tif(n == 2 || n == 3 || n == 5)return true;\n\tif(n % 2 == 0)return false;\n\t\
    if(n % 3 == 0)return false;\n\tif(n % 5 == 0)return false;\n\n\tstd::vector<long\
    \ long> A = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};\n\n\tlong long\
    \ s = 0, d = n - 1;\n\twhile(d % 2 == 0){\n\t\ts++;\n\t\td >>= 1;\n\t}\n\n\tfor\
    \ (auto a : A){\n\t\tif(a % n == 0)return true;\n\t\tlong long t, x = __power(a,\
    \ d, n);\n\t\tif(x != 1){\n\t\t\tfor(t = 0;t < s;t++){\n\t\t\t\tif(x == n - 1)break;\n\
    \t\t\t\tx = __int128_t(x) * x % n;\n\t\t\t}\n\t\t\tif(t == s)return false;\n\t\
    \t}\n\t}\n\treturn true;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/is_prime.hpp
  requiredBy:
  - math/enumerate_divisors.hpp
  - math/euler_phi.hpp
  - math/factor.hpp
  timestamp: '2025-07-01 03:22:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/primality_test.test.cpp
  - verify/yosupo/factorize.test.cpp
  - verify/aoj/id/1642.test.cpp
  - verify/aoj/ntl/1_D.test.cpp
documentation_of: math/is_prime.hpp
layout: document
title: "\u7D20\u6570\u5224\u5B9A\uFF08\u30DF\u30E9\u30FC\u30FB\u30E9\u30D3\u30F3\u7D20\
  \u6570\u5224\u5B9A\u6CD5\uFF09"
---

# 素数判定（ミラー・ラビン素数判定法）

## 使い方

- ``is_prime(int64_t n)`` : $n$ が素数かどうかの判定を行う $O(log n)$

## 概要

ミラー・ラビン素数判定法によって、long long に収まる範囲内の素数判定は、$n-1$ から $2$ の素因数を取り除いたのちに、$A = {2, 325, 9375, 28178, 450775, 9780504, 1795265022}$ についてのみ検証すればよい。

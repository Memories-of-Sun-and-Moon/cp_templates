---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/factor.hpp
    title: "\u7D20\u56E0\u6570\u5206\u89E3\uFF08\u30DD\u30E9\u30FC\u30C9\u30FB\u30ED\
      \u30FC\u6CD5\uFF09"
  _extendedVerifiedWith:
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
  bundledCode: "#line 2 \"math/is_prime.hpp\"\n__int128_t __power(__int128_t n, __int128_t\
    \ k, __int128_t m) {\n    n %= m;\n\t__int128_t ret = 1;\n    while(k > 0){\n\
    \        if(k & 1)ret = ret * n % m;\n        n = __int128_t(n) * n % m;\n   \
    \     k >>= 1;\n    }\n    return ret % m;\n}\n\nbool is_prime(long long n){\n\
    \    if(n <= 1)return false;\n    if(n == 2 || n == 3 || n == 5)return true;\n\
    \    if(n % 2 == 0)return false;\n    if(n % 3 == 0)return false;\n    if(n %\
    \ 5 == 0)return false;\n\n    vector<long long> A = {2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022};\n\n    long long s = 0, d = n - 1;\n    while(d % 2 ==\
    \ 0){\n        s++;\n        d >>= 1;\n    }\n\n    for (auto a : A){\n      \
    \  if(a % n == 0)return true;\n        long long t, x = __power(a, d, n);\n  \
    \      if(x != 1){\n            for(t = 0;t < s;t++){\n                if(x ==\
    \ n - 1)break;\n                x = __int128_t(x) * x % n;\n            }\n  \
    \          if(t == s)return false;\n        }\n    }\n    return true;\n}\n"
  code: "#pragma once\n__int128_t __power(__int128_t n, __int128_t k, __int128_t m)\
    \ {\n    n %= m;\n\t__int128_t ret = 1;\n    while(k > 0){\n        if(k & 1)ret\
    \ = ret * n % m;\n        n = __int128_t(n) * n % m;\n        k >>= 1;\n    }\n\
    \    return ret % m;\n}\n\nbool is_prime(long long n){\n    if(n <= 1)return false;\n\
    \    if(n == 2 || n == 3 || n == 5)return true;\n    if(n % 2 == 0)return false;\n\
    \    if(n % 3 == 0)return false;\n    if(n % 5 == 0)return false;\n\n    vector<long\
    \ long> A = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};\n\n    long long\
    \ s = 0, d = n - 1;\n    while(d % 2 == 0){\n        s++;\n        d >>= 1;\n\
    \    }\n\n    for (auto a : A){\n        if(a % n == 0)return true;\n        long\
    \ long t, x = __power(a, d, n);\n        if(x != 1){\n            for(t = 0;t\
    \ < s;t++){\n                if(x == n - 1)break;\n                x = __int128_t(x)\
    \ * x % n;\n            }\n            if(t == s)return false;\n        }\n  \
    \  }\n    return true;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/is_prime.hpp
  requiredBy:
  - math/factor.hpp
  timestamp: '2025-02-08 20:53:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/factorize.test.cpp
  - verify/yosupo/primality_test.test.cpp
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

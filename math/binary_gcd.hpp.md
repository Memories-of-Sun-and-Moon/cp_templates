---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yukicoder/1250.test.cpp
    title: verify/yukicoder/1250.test.cpp
  - icon: ':x:'
    path: verify/yukicoder/3020.test.cpp
    title: verify/yukicoder/3020.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/binary_gcd.hpp\"\n\n#include<algorithm>\n#include<cmath>\n\
    \nlong long binary_gcd(long long a, long long b){\n\tif(a == 0)return b;\n\tif(b\
    \ == 0)return a;\n\n\ta = std::abs(a);\n\tb = std::abs(b);\n\n\tint a_zero = __builtin_ctzll(a);\n\
    \tint b_zero = __builtin_ctzll(b);\n\ta >>= a_zero;\n\tb >>= b_zero;\n\t\n\twhile(a\
    \ != b){\n\t\tif(a > b){\n\t\t\tstd::swap(a, b);\n\t\t}\n\t\tb -= a;\n\t\tb >>=\
    \ __builtin_ctzll(b);\n\t}\n\treturn a << std::min(a_zero, b_zero);\n}\n"
  code: "#pragma once\n\n#include<algorithm>\n#include<cmath>\n\nlong long binary_gcd(long\
    \ long a, long long b){\n\tif(a == 0)return b;\n\tif(b == 0)return a;\n\n\ta =\
    \ std::abs(a);\n\tb = std::abs(b);\n\n\tint a_zero = __builtin_ctzll(a);\n\tint\
    \ b_zero = __builtin_ctzll(b);\n\ta >>= a_zero;\n\tb >>= b_zero;\n\t\n\twhile(a\
    \ != b){\n\t\tif(a > b){\n\t\t\tstd::swap(a, b);\n\t\t}\n\t\tb -= a;\n\t\tb >>=\
    \ __builtin_ctzll(b);\n\t}\n\treturn a << std::min(a_zero, b_zero);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/binary_gcd.hpp
  requiredBy: []
  timestamp: '2025-07-01 03:22:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yukicoder/3020.test.cpp
  - verify/yukicoder/1250.test.cpp
documentation_of: math/binary_gcd.hpp
layout: document
title: binary_gcd
---

# binary_gcd

## 使い方

``binary_gcd(ll a, ll b)`` : $\text{gcd}(a, b)$ を返す。$O(\log{a+b})$ 程度

## 概要

除算が遅いため、それを回避するためにビットシフトに限定した GCD 計算アルゴリズム

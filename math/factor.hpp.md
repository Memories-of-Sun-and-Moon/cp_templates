---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A\uFF08\u30DF\u30E9\u30FC\u30FB\u30E9\u30D3\u30F3\
      \u7D20\u6570\u5224\u5B9A\u6CD5\uFF09"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/enumerate_divisors.hpp
    title: "\u7D04\u6570\u5217\u6319"
  - icon: ':heavy_check_mark:'
    path: math/euler_phi.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\u6570\uFF08\u30AA\u30A4\u30E9\
      \u30FC\u306E\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570\uFF09"
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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/factor.hpp\"\n\n#line 2 \"math/is_prime.hpp\"\n\n#include<vector>\n\
    \n__int128_t __power(__int128_t n, __int128_t k, __int128_t m) {\n\tn %= m;\n\t\
    __int128_t ret = 1;\n\twhile(k > 0){\n\t\tif(k & 1)ret = ret * n % m;\n\t\tn =\
    \ __int128_t(n) * n % m;\n\t\tk >>= 1;\n\t}\n\treturn ret % m;\n}\n\nbool is_prime(long\
    \ long n){\n\tif(n <= 1)return false;\n\tif(n == 2 || n == 3 || n == 5)return\
    \ true;\n\tif(n % 2 == 0)return false;\n\tif(n % 3 == 0)return false;\n\tif(n\
    \ % 5 == 0)return false;\n\n\tstd::vector<long long> A = {2, 325, 9375, 28178,\
    \ 450775, 9780504, 1795265022};\n\n\tlong long s = 0, d = n - 1;\n\twhile(d %\
    \ 2 == 0){\n\t\ts++;\n\t\td >>= 1;\n\t}\n\n\tfor (auto a : A){\n\t\tif(a % n ==\
    \ 0)return true;\n\t\tlong long t, x = __power(a, d, n);\n\t\tif(x != 1){\n\t\t\
    \tfor(t = 0;t < s;t++){\n\t\t\t\tif(x == n - 1)break;\n\t\t\t\tx = __int128_t(x)\
    \ * x % n;\n\t\t\t}\n\t\t\tif(t == s)return false;\n\t\t}\n\t}\n\treturn true;\n\
    }\n#line 4 \"math/factor.hpp\"\n\n#include<algorithm>\n#include<numeric>\n#line\
    \ 8 \"math/factor.hpp\"\n\nlong long rho(long long n){\n\tif(n % 2 == 0)return\
    \ 2;\n\tif(is_prime(n))return n;\n\n\tauto f = [&](long long x) -> long long {\n\
    \t\treturn (__int128_t(x) * x + 13) % n;\n\t};\n\n\tlong long step = 0;\n\twhile\
    \ (true) {\n\t\t++step;\n\t\tlong long x = step, y = f(x);\n\t\twhile (true) {\n\
    \t\t\tlong long p = std::gcd(y - x + n, n);\n\t\t\tif (p == 0 || p == n) break;\n\
    \t\t\tif (p != 1) return p;\n\t\t\tx = f(x);\n\t\t\ty = f(f(y));\n\t\t}\n\t}\n\
    }\n\nstd::vector<long long> factor(long long x){\n\tif(x == 1)return {};\n\tlong\
    \ long p = rho(x);\n\tif(p == x) return {p};\n\t\t\n\tstd::vector<long long> l\
    \ = factor(p);\n\tstd::vector<long long> r = factor(x / p);\n\n\tl.insert(l.end(),\
    \ r.begin(), r.end());\n\tstd::sort(l.begin(), l.end());\n\n\treturn l;\n}\n"
  code: "#pragma once\n\n#include \"is_prime.hpp\"\n\n#include<algorithm>\n#include<numeric>\n\
    #include<vector>\n\nlong long rho(long long n){\n\tif(n % 2 == 0)return 2;\n\t\
    if(is_prime(n))return n;\n\n\tauto f = [&](long long x) -> long long {\n\t\treturn\
    \ (__int128_t(x) * x + 13) % n;\n\t};\n\n\tlong long step = 0;\n\twhile (true)\
    \ {\n\t\t++step;\n\t\tlong long x = step, y = f(x);\n\t\twhile (true) {\n\t\t\t\
    long long p = std::gcd(y - x + n, n);\n\t\t\tif (p == 0 || p == n) break;\n\t\t\
    \tif (p != 1) return p;\n\t\t\tx = f(x);\n\t\t\ty = f(f(y));\n\t\t}\n\t}\n}\n\n\
    std::vector<long long> factor(long long x){\n\tif(x == 1)return {};\n\tlong long\
    \ p = rho(x);\n\tif(p == x) return {p};\n\t\t\n\tstd::vector<long long> l = factor(p);\n\
    \tstd::vector<long long> r = factor(x / p);\n\n\tl.insert(l.end(), r.begin(),\
    \ r.end());\n\tstd::sort(l.begin(), l.end());\n\n\treturn l;\n}\n"
  dependsOn:
  - math/is_prime.hpp
  isVerificationFile: false
  path: math/factor.hpp
  requiredBy:
  - math/enumerate_divisors.hpp
  - math/euler_phi.hpp
  timestamp: '2025-07-01 03:22:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/ntl/1_D.test.cpp
  - verify/aoj/id/1642.test.cpp
  - verify/yosupo/factorize.test.cpp
documentation_of: math/factor.hpp
layout: document
title: "\u7D20\u56E0\u6570\u5206\u89E3\uFF08\u30DD\u30E9\u30FC\u30C9\u30FB\u30ED\u30FC\
  \u6CD5\uFF09"
---

# 素因数分解（ポラード・ロー法）

## 使い方

- ``vector<int64_t> factor(int64_t x)`` : $x$ の素因数分解を求める $O(n^{\frac{1}{4}})$ 

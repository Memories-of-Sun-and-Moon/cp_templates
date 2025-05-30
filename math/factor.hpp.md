---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A\uFF08\u30DF\u30E9\u30FC\u30FB\u30E9\u30D3\u30F3\
      \u7D20\u6570\u5224\u5B9A\u6CD5\uFF09"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/euler_phi.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\u6570\uFF08\u30AA\u30A4\u30E9\
      \u30FC\u306E\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570\uFF09"
  _extendedVerifiedWith:
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
  bundledCode: "#line 2 \"math/is_prime.hpp\"\n__int128_t __power(__int128_t n, __int128_t\
    \ k, __int128_t m) {\n\tn %= m;\n\t__int128_t ret = 1;\n\twhile(k > 0){\n\t\t\
    if(k & 1)ret = ret * n % m;\n\t\tn = __int128_t(n) * n % m;\n\t\tk >>= 1;\n\t\
    }\n\treturn ret % m;\n}\n\nbool is_prime(long long n){\n\tif(n <= 1)return false;\n\
    \tif(n == 2 || n == 3 || n == 5)return true;\n\tif(n % 2 == 0)return false;\n\t\
    if(n % 3 == 0)return false;\n\tif(n % 5 == 0)return false;\n\n\tvector<long long>\
    \ A = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};\n\n\tlong long s = 0,\
    \ d = n - 1;\n\twhile(d % 2 == 0){\n\t\ts++;\n\t\td >>= 1;\n\t}\n\n\tfor (auto\
    \ a : A){\n\t\tif(a % n == 0)return true;\n\t\tlong long t, x = __power(a, d,\
    \ n);\n\t\tif(x != 1){\n\t\t\tfor(t = 0;t < s;t++){\n\t\t\t\tif(x == n - 1)break;\n\
    \t\t\t\tx = __int128_t(x) * x % n;\n\t\t\t}\n\t\t\tif(t == s)return false;\n\t\
    \t}\n\t}\n\treturn true;\n}\n#line 2 \"math/factor.hpp\"\n\nlong long rho(long\
    \ long n){\n    if(n % 2 == 0)return 2;\n    if(is_prime(n))return n;\n\n    auto\
    \ f = [&](long long x) -> long long {\n        return (__int128_t(x) * x + 13)\
    \ % n;\n    };\n\n    long long step = 0;\n    while (true) {\n        ++step;\n\
    \        long long x = step, y = f(x);\n        while (true) {\n            long\
    \ long p = gcd(y - x + n, n);\n            if (p == 0 || p == n) break;\n    \
    \        if (p != 1) return p;\n            x = f(x);\n            y = f(f(y));\n\
    \        }\n    }\n}\n\nvector<long long> factor(long long x){\n    if(x == 1)return\
    \ {};\n    long long p = rho(x);\n    if(p == x) return {p};\n    \n    vector<long\
    \ long> l = factor(p);\n    vector<long long> r = factor(x / p);\n\n    l.insert(l.end(),\
    \ r.begin(), r.end());\n    sort(l.begin(), l.end());\n\n    return l;\n}\n"
  code: "#include \"is_prime.hpp\"\n\nlong long rho(long long n){\n    if(n % 2 ==\
    \ 0)return 2;\n    if(is_prime(n))return n;\n\n    auto f = [&](long long x) ->\
    \ long long {\n        return (__int128_t(x) * x + 13) % n;\n    };\n\n    long\
    \ long step = 0;\n    while (true) {\n        ++step;\n        long long x = step,\
    \ y = f(x);\n        while (true) {\n            long long p = gcd(y - x + n,\
    \ n);\n            if (p == 0 || p == n) break;\n            if (p != 1) return\
    \ p;\n            x = f(x);\n            y = f(f(y));\n        }\n    }\n}\n\n\
    vector<long long> factor(long long x){\n    if(x == 1)return {};\n    long long\
    \ p = rho(x);\n    if(p == x) return {p};\n    \n    vector<long long> l = factor(p);\n\
    \    vector<long long> r = factor(x / p);\n\n    l.insert(l.end(), r.begin(),\
    \ r.end());\n    sort(l.begin(), l.end());\n\n    return l;\n}\n"
  dependsOn:
  - math/is_prime.hpp
  isVerificationFile: false
  path: math/factor.hpp
  requiredBy:
  - math/euler_phi.hpp
  timestamp: '2025-05-20 23:52:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/ntl/1_D.test.cpp
  - verify/yosupo/factorize.test.cpp
documentation_of: math/factor.hpp
layout: document
title: "\u7D20\u56E0\u6570\u5206\u89E3\uFF08\u30DD\u30E9\u30FC\u30C9\u30FB\u30ED\u30FC\
  \u6CD5\uFF09"
---

# 素因数分解（ポラード・ロー法）

## 使い方

- ``vector<int64_t> factor(int64_t x)`` : $x$ の素因数分解を求める $O(n^{\frac{1}{4}})$ 

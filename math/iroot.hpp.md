---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/counting_primes.hpp
    title: "$n$ \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\u6570\u3048\u4E0A\u3052"
  - icon: ':heavy_check_mark:'
    path: math/discrete_logarithm.hpp
    title: discrete_logarithm
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/counting_primes.test.cpp
    title: verify/yosupo/counting_primes.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/discrete_logarithm.test.cpp
    title: verify/yosupo/discrete_logarithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/kth_root_integer.test.cpp
    title: verify/yosupo/kth_root_integer.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/1661.test.cpp
    title: verify/yukicoder/1661.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/iroot.hpp\"\n\n#include<cmath>\n#include<limits>\n\n\
    unsigned long long iroot(unsigned long long n, int k=2){\n\tconstexpr unsigned\
    \ long long LIM = std::numeric_limits<unsigned long long>::max();\n\tif(n <= 1\
    \ || k == 1){\n\t\treturn n;\n\t}\n\tif(k >= 64){\n\t\treturn 1;\n\t}\n\tif(k\
    \ == 2){\n\t\treturn sqrtl(n);\n\t}\n\n\tif(n == LIM)n--;\n\n\tauto safe_mul =\
    \ [&](unsigned long long &x, unsigned long long &y) -> void {\n\t\tif(x <= LIM\
    \ / y){\n\t\t\tx *= y;\n\t\t}else{\n\t\t\tx = LIM;\n\t\t}\n\t};\n\n\tauto power\
    \ = [&](unsigned long long a, int b) -> unsigned long long {\n\t\tunsigned long\
    \ long ret = 1;\n\t\twhile(b){\n\t\t\tif(b & 1)safe_mul(ret, a);\n\t\t\tsafe_mul(a,\
    \ a);\n\t\t\tb >>= 1;\n\t\t}\n\t\treturn ret;\n\t};\n\n\tunsigned long long ret\
    \ = (k == 3 ? cbrt(n)-1 : std::pow(n, std::nextafter(1.0/double(k), 0.0)));\n\t\
    while(power(ret+1, k) <= n)ret++;\n\treturn ret;\n}\n"
  code: "#pragma once\n\n#include<cmath>\n#include<limits>\n\nunsigned long long iroot(unsigned\
    \ long long n, int k=2){\n\tconstexpr unsigned long long LIM = std::numeric_limits<unsigned\
    \ long long>::max();\n\tif(n <= 1 || k == 1){\n\t\treturn n;\n\t}\n\tif(k >= 64){\n\
    \t\treturn 1;\n\t}\n\tif(k == 2){\n\t\treturn sqrtl(n);\n\t}\n\n\tif(n == LIM)n--;\n\
    \n\tauto safe_mul = [&](unsigned long long &x, unsigned long long &y) -> void\
    \ {\n\t\tif(x <= LIM / y){\n\t\t\tx *= y;\n\t\t}else{\n\t\t\tx = LIM;\n\t\t}\n\
    \t};\n\n\tauto power = [&](unsigned long long a, int b) -> unsigned long long\
    \ {\n\t\tunsigned long long ret = 1;\n\t\twhile(b){\n\t\t\tif(b & 1)safe_mul(ret,\
    \ a);\n\t\t\tsafe_mul(a, a);\n\t\t\tb >>= 1;\n\t\t}\n\t\treturn ret;\n\t};\n\n\
    \tunsigned long long ret = (k == 3 ? cbrt(n)-1 : std::pow(n, std::nextafter(1.0/double(k),\
    \ 0.0)));\n\twhile(power(ret+1, k) <= n)ret++;\n\treturn ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/iroot.hpp
  requiredBy:
  - math/discrete_logarithm.hpp
  - math/counting_primes.hpp
  timestamp: '2025-07-01 03:22:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yukicoder/1661.test.cpp
  - verify/yosupo/counting_primes.test.cpp
  - verify/yosupo/kth_root_integer.test.cpp
  - verify/yosupo/discrete_logarithm.test.cpp
documentation_of: math/iroot.hpp
layout: document
title: "floor K \u4E57\u6839"
---

# floor K 乗根

## 使い方

``ll iroot(ll n, ll k=2)`` : $\lfloor \sqrt[k]{n} \rfloor$ を求める（ $k$ のデフォルトは $2$ ）

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/discrete_logarithm.hpp
    title: discrete_logarithm
  - icon: ':heavy_check_mark:'
    path: math/formal_power_series.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\u30E9\u30EA"
  - icon: ':warning:'
    path: math/geometric_series_sum.hpp
    title: "\u7B49\u6BD4\u6570\u5217\u306E\u7DCF\u548C"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/convolution_mod.test.cpp
    title: verify/yosupo/convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/discrete_logarithm.test.cpp
    title: verify/yosupo/discrete_logarithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/generalized_discrete_logarithm.test.cpp
    title: verify/yosupo/generalized_discrete_logarithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/power.hpp\"\n\ntemplate<typename T>\nT power(T n, long\
    \ long k) {\n\tT ret = 1;\n\twhile(k > 0) {\n\t\tif(k & 1)ret *= n;\n\t\tn = n*n;\n\
    \t\tk >>= 1;\n\t}\n\treturn ret;\n}\n\nlong long power(long long n, long long\
    \ k, long long p) {\n\tlong long ret = 1;\n\twhile(k > 0){\n\t\tif(k & 1)ret =\
    \ ret*n % p;\n\t\tn = n*n % p;\n\t\tk >>= 1;\n\t}\n\treturn ret;\n}\n"
  code: "\ntemplate<typename T>\nT power(T n, long long k) {\n\tT ret = 1;\n\twhile(k\
    \ > 0) {\n\t\tif(k & 1)ret *= n;\n\t\tn = n*n;\n\t\tk >>= 1;\n\t}\n\treturn ret;\n\
    }\n\nlong long power(long long n, long long k, long long p) {\n\tlong long ret\
    \ = 1;\n\twhile(k > 0){\n\t\tif(k & 1)ret = ret*n % p;\n\t\tn = n*n % p;\n\t\t\
    k >>= 1;\n\t}\n\treturn ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/power.hpp
  requiredBy:
  - math/formal_power_series.hpp
  - math/discrete_logarithm.hpp
  - math/geometric_series_sum.hpp
  timestamp: '2025-03-08 05:27:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/convolution_mod.test.cpp
  - verify/yosupo/generalized_discrete_logarithm.test.cpp
  - verify/yosupo/discrete_logarithm.test.cpp
documentation_of: math/power.hpp
layout: document
redirect_from:
- /library/math/power.hpp
- /library/math/power.hpp.html
title: math/power.hpp
---

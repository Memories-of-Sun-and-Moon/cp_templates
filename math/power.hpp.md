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
  bundledCode: "#line 2 \"math/power.hpp\"\n\n#include <type_traits>\n\ntemplate<typename\
    \ T>\nconcept NotPrimitiveInt =\n\t!(std::is_same_v<T, int> ||\n\t\tstd::is_same_v<T,\
    \ long> ||\n\t\tstd::is_same_v<T, long long> ||\n\t\tstd::is_same_v<T, unsigned>\
    \ ||\n\t\tstd::is_same_v<T, unsigned long> ||\n\t\tstd::is_same_v<T, unsigned\
    \ long long>);\n\ntemplate<NotPrimitiveInt T>\nT power(T n, long long k) {\n\t\
    T ret = 1;\n\twhile(k > 0) {\n\t\tif(k & 1)ret *= n;\n\t\tn = n*n;\n\t\tk >>=\
    \ 1;\n\t}\n\treturn ret;\n}\n\nlong long power(long long n, long long k, long\
    \ long p) {\n\tlong long ret = 1;\n\twhile(k > 0){\n\t\tif(k & 1)ret = ret*n %\
    \ p;\n\t\tn = n*n % p;\n\t\tk >>= 1;\n\t}\n\treturn ret;\n}\n"
  code: "#pragma once\n\n#include <type_traits>\n\ntemplate<typename T>\nconcept NotPrimitiveInt\
    \ =\n\t!(std::is_same_v<T, int> ||\n\t\tstd::is_same_v<T, long> ||\n\t\tstd::is_same_v<T,\
    \ long long> ||\n\t\tstd::is_same_v<T, unsigned> ||\n\t\tstd::is_same_v<T, unsigned\
    \ long> ||\n\t\tstd::is_same_v<T, unsigned long long>);\n\ntemplate<NotPrimitiveInt\
    \ T>\nT power(T n, long long k) {\n\tT ret = 1;\n\twhile(k > 0) {\n\t\tif(k &\
    \ 1)ret *= n;\n\t\tn = n*n;\n\t\tk >>= 1;\n\t}\n\treturn ret;\n}\n\nlong long\
    \ power(long long n, long long k, long long p) {\n\tlong long ret = 1;\n\twhile(k\
    \ > 0){\n\t\tif(k & 1)ret = ret*n % p;\n\t\tn = n*n % p;\n\t\tk >>= 1;\n\t}\n\t\
    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/power.hpp
  requiredBy:
  - math/discrete_logarithm.hpp
  - math/formal_power_series.hpp
  - math/geometric_series_sum.hpp
  timestamp: '2025-07-01 03:22:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/generalized_discrete_logarithm.test.cpp
  - verify/yosupo/convolution_mod.test.cpp
  - verify/yosupo/discrete_logarithm.test.cpp
documentation_of: math/power.hpp
layout: document
redirect_from:
- /library/math/power.hpp
- /library/math/power.hpp.html
title: math/power.hpp
---

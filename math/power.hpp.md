---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: math/formal_power_series.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\u30E9\u30EA"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/convolution_mod.test.cpp
    title: verify/yosupo/convolution_mod.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/power.hpp\"\n\ntemplate<typename mint>\nmint power(mint\
    \ n, long long k) {\n\tmint ret = 1;\n\twhile(k > 0) {\n\t\tif(k & 1)ret *= n;\n\
    \t\tn = n*n;\n\t\tk >>= 1;\n\t}\n\treturn ret;\n}\n"
  code: "\ntemplate<typename mint>\nmint power(mint n, long long k) {\n\tmint ret\
    \ = 1;\n\twhile(k > 0) {\n\t\tif(k & 1)ret *= n;\n\t\tn = n*n;\n\t\tk >>= 1;\n\
    \t}\n\treturn ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/power.hpp
  requiredBy:
  - math/formal_power_series.hpp
  timestamp: '2024-06-28 01:22:25+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo/convolution_mod.test.cpp
documentation_of: math/power.hpp
layout: document
redirect_from:
- /library/math/power.hpp
- /library/math/power.hpp.html
title: math/power.hpp
---

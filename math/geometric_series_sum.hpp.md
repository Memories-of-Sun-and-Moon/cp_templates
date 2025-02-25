---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/power.hpp
    title: math/power.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/power.hpp\"\n\ntemplate<typename mint>\nmint power(mint\
    \ n, long long k) {\n\tmint ret = 1;\n\twhile(k > 0) {\n\t\tif(k & 1)ret *= n;\n\
    \t\tn = n*n;\n\t\tk >>= 1;\n\t}\n\treturn ret;\n}\n\nlong long power(long long\
    \ n, long long k, long long p) {\n\tlong long ret = 1;\n\twhile(k > 0){\n\t\t\
    if(k & 1)ret = ret*n % p;\n\t\tn = n*n % p;\n\t\tk >>= 1;\n\t}\n\treturn ret;\n\
    }\n#line 2 \"math/geometric_series_sum.hpp\"\n\nll geometric_series_sum(ll a,\
    \ ll n, ll m){\n\tif(n == 0)return 0;\n\tif(n & 1){\n\t\treturn (geometric_series_sum(a,\
    \ n-1, m) + power(a, n-1, m)) % m;\n\t}\n\treturn (geometric_series_sum(a, n/2,\
    \ m) * (1LL + power(a, n/2, m))) % m;\n}\n"
  code: "#include \"../math/power.hpp\"\n\nll geometric_series_sum(ll a, ll n, ll\
    \ m){\n\tif(n == 0)return 0;\n\tif(n & 1){\n\t\treturn (geometric_series_sum(a,\
    \ n-1, m) + power(a, n-1, m)) % m;\n\t}\n\treturn (geometric_series_sum(a, n/2,\
    \ m) * (1LL + power(a, n/2, m))) % m;\n}\n"
  dependsOn:
  - math/power.hpp
  isVerificationFile: false
  path: math/geometric_series_sum.hpp
  requiredBy: []
  timestamp: '2025-02-26 05:50:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/geometric_series_sum.hpp
layout: document
title: "\u7B49\u6BD4\u6570\u5217\u306E\u7DCF\u548C"
---

# 等比数列の総和

## 使い方

- ``ll geometric_series_sum(ll a, ll n, ll m)`` : 初項 $1$, 公比 $a$, 項数 $n$ の等比数列の総和を $m$ で割ったあまりを返す。 $O(\log{N})$

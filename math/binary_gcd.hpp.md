---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/1250.test.cpp
    title: verify/yukicoder/1250.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/binary_gcd.hpp\"\nll binary_gcd(ll a, ll b){\n\tif(a\
    \ == 0)return b;\n\tif(b == 0)return a;\n\n\ta = abs(a);\n\tb = abs(b);\n\n\t\
    int a_zero = __builtin_ctzll(a);\n\tint b_zero = __builtin_ctzll(b);\n\ta >>=\
    \ a_zero;\n\tb >>= b_zero;\n\t\n\twhile(a != b){\n\t\tif(a > b){\n\t\t\tswap(a,\
    \ b);\n\t\t}\n\t\tb -= a;\n\t\tb >>= __builtin_ctzll(b);\n\t}\n\treturn a << min(a_zero,\
    \ b_zero);\n}\n"
  code: "ll binary_gcd(ll a, ll b){\n\tif(a == 0)return b;\n\tif(b == 0)return a;\n\
    \n\ta = abs(a);\n\tb = abs(b);\n\n\tint a_zero = __builtin_ctzll(a);\n\tint b_zero\
    \ = __builtin_ctzll(b);\n\ta >>= a_zero;\n\tb >>= b_zero;\n\t\n\twhile(a != b){\n\
    \t\tif(a > b){\n\t\t\tswap(a, b);\n\t\t}\n\t\tb -= a;\n\t\tb >>= __builtin_ctzll(b);\n\
    \t}\n\treturn a << min(a_zero, b_zero);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/binary_gcd.hpp
  requiredBy: []
  timestamp: '2025-05-20 23:51:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yukicoder/1250.test.cpp
documentation_of: math/binary_gcd.hpp
layout: document
redirect_from:
- /library/math/binary_gcd.hpp
- /library/math/binary_gcd.hpp.html
title: math/binary_gcd.hpp
---

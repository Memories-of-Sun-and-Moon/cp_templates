---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: modint.cpp: line\
    \ -1: no such header\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n# include \"modint.cpp\"\
    \n\nusing mint = modint<998244353>;\n//using mint = modint<1000000007>;\n\nconstexpr\
    \ int max_combination = 1010101;\n\nmint fact[max_combination], inv_fact[max_combination];\n\
    \nvoid combination_init(){\n    fact[0] = 1, inv_fact[0] = 1;\n    for(int i =\
    \ 1;i < max_combination;i++){\n        fact[i] = fact[i - 1];\n        fact[i]\
    \ *= i;\n        inv_fact[i] = inv_fact[i - 1];\n        inv_fact[i] /= i;\n \
    \   }\n}\n\nmint nCr(int n, int r){\n    if(fact[0].a == 0)combination_init();\n\
    \n    if(r < 0 || r > n)return 0;\n\n    mint ret = fact[n];\n    ret *= inv_fact[r];\n\
    \    ret *= inv_fact[n - r];\n\n    return ret;\n}\n\n\n// n\u500B\u304B\u3089\
    , (a, b)\u500B\u306E\u7D44\u3092\u4F5C\u308B\u6642\u306E\u5834\u5408\u306E\u6570\
    \nmint sub(int n, int a, int b) {\n    if(a + b > n)return 0;\n    return nCr(n,\
    \ a) * nCr(n - a, b);\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/nCr%mod(combination).cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/nCr%mod(combination).cpp
layout: document
redirect_from:
- /library/math/nCr%mod(combination).cpp
- /library/math/nCr%mod(combination).cpp.html
title: math/nCr%mod(combination).cpp
---

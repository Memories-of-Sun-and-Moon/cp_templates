---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/modint.cpp
    title: math/modint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bits/stdc++.h:\
    \ line -1: no such header\n"
  code: "# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B\"\
    \n# include \"bits/stdc++.h\"\nusing namespace std;\n\nlong long power(long long\
    \ n, long long k, long long m) {\n\tn %= m;\n\tlong long ret = 1;\n\twhile(k >\
    \ 0){\n\t\tif(k & 1)ret = ret * n % m;\n\t\tn = n * n % m;\n\t\tk >>= 1;\n\t}\n\
    \treturn ret % m;\n}\n\n# include \"modint.cpp\"\n\nusing mint = modint<998244353>;\n\
    \nmint power(mint n, long long k) {\n\tmint ret = 1;\n\twhile(k > 0) {\n\t\tif(k\
    \ & 1)ret *= n;\n\t\tn = n*n;\n\t\tk >>= 1;\n\t}\n\treturn ret;\n}\n\nlong long\
    \ m, n;\nconst long long mod = 1000000000 + 7;\n\nint main(){\n\tcin >> m >> n;\n\
    \tcout << power(m, n, mod) << endl;\n}"
  dependsOn:
  - math/modint.cpp
  isVerificationFile: false
  path: math/power.cpp
  requiredBy: []
  timestamp: '2024-05-28 05:46:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/power.cpp
layout: document
redirect_from:
- /library/math/power.cpp
- /library/math/power.cpp.html
title: math/power.cpp
---

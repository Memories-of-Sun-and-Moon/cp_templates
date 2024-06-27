---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  requiredBy: []
  timestamp: '2024-06-28 01:22:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/power.hpp
layout: document
redirect_from:
- /library/math/power.hpp
- /library/math/power.hpp.html
title: math/power.hpp
---

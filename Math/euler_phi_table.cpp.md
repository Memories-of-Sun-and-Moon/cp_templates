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
  bundledCode: "#line 1 \"Math/euler_phi_table.cpp\"\n# include <bits/stdc++.h>\n\
    using namespace std;\n\n//O(n log log n)\n// [1, n] \u306E phi(x) \u3092\u6C42\
    \u3081\u308B\nvector<int> euler_phi_table(int n){\n    vector<int> phi(n + 1);\n\
    \    for(int i = 0;i <= n;i++){\n        phi[i] = i;\n    }\n    for(int i = 2;i\
    \ <= n;i++){\n        if(phi[i] == i){\n            for(int j = i;j <= n;j +=\
    \ i){\n                phi[j] = phi[j] / i * (i - 1);\n            }\n       \
    \ }\n    }\n    return phi;\n}\n"
  code: "# include <bits/stdc++.h>\nusing namespace std;\n\n//O(n log log n)\n// [1,\
    \ n] \u306E phi(x) \u3092\u6C42\u3081\u308B\nvector<int> euler_phi_table(int n){\n\
    \    vector<int> phi(n + 1);\n    for(int i = 0;i <= n;i++){\n        phi[i] =\
    \ i;\n    }\n    for(int i = 2;i <= n;i++){\n        if(phi[i] == i){\n      \
    \      for(int j = i;j <= n;j += i){\n                phi[j] = phi[j] / i * (i\
    \ - 1);\n            }\n        }\n    }\n    return phi;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/euler_phi_table.cpp
  requiredBy: []
  timestamp: '2023-03-17 23:45:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/euler_phi_table.cpp
layout: document
redirect_from:
- /library/Math/euler_phi_table.cpp
- /library/Math/euler_phi_table.cpp.html
title: Math/euler_phi_table.cpp
---

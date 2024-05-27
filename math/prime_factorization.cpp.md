---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_A
  bundledCode: "#line 1 \"math/prime_factorization.cpp\"\n# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_A\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\nvector<pair<int,int>> prime_factorization(int\
    \ val){\n\tassert(val >= 1);\n\tif(val == 1){\n\t\treturn {};\n\t}\n\tvector<pair<int,int>>\
    \ ans;\n    int idx = 0;\n\tfor(int i = 2;i * i <= val;i++){\n\t\tif(val % i !=\
    \ 0)continue;\n\t\tans.push_back({i, 0});\n\t\twhile(val % i == 0){\n\t\t\tans[idx].second++;\n\
    \t\t\tval /= i;\n\t\t}\n        idx++;\n\t}\n\tif(val != 1) ans.push_back({val,\
    \ 1});\n\treturn ans;\n}\n\nint n;\n\nint main(){\n    cin >> n;\n    auto ret\
    \ = prime_factorization(n);\n    cout << n << \":\";\n    for(int i = 0;i < (int)ret.size();i++){\n\
    \        for(int j = 0;j < ret[i].second;j++)cout << \" \" << ret[i].first;\n\
    \    }\n    cout << endl;\n}\n"
  code: "# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_A\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\nvector<pair<int,int>> prime_factorization(int\
    \ val){\n\tassert(val >= 1);\n\tif(val == 1){\n\t\treturn {};\n\t}\n\tvector<pair<int,int>>\
    \ ans;\n    int idx = 0;\n\tfor(int i = 2;i * i <= val;i++){\n\t\tif(val % i !=\
    \ 0)continue;\n\t\tans.push_back({i, 0});\n\t\twhile(val % i == 0){\n\t\t\tans[idx].second++;\n\
    \t\t\tval /= i;\n\t\t}\n        idx++;\n\t}\n\tif(val != 1) ans.push_back({val,\
    \ 1});\n\treturn ans;\n}\n\nint n;\n\nint main(){\n    cin >> n;\n    auto ret\
    \ = prime_factorization(n);\n    cout << n << \":\";\n    for(int i = 0;i < (int)ret.size();i++){\n\
    \        for(int j = 0;j < ret[i].second;j++)cout << \" \" << ret[i].first;\n\
    \    }\n    cout << endl;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/prime_factorization.cpp
  requiredBy: []
  timestamp: '2024-05-28 05:46:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/prime_factorization.cpp
layout: document
redirect_from:
- /library/math/prime_factorization.cpp
- /library/math/prime_factorization.cpp.html
title: math/prime_factorization.cpp
---

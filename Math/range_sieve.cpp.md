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
  bundledCode: "#line 1 \"Math/range_sieve.cpp\"\n// \u672A\u691C\u8A3C\n#include\
    \ <bits/stdc++.h>\nusing ll = long long;\nusing namespace std;\n\nclass range_sieve\
    \ {\n\tll l, r, m;\n\tvector<int> small;\n\tvector<vector<ll>> large;\n\tvector<ll>\
    \ aux;\n\npublic:\n\trange_sieve(ll l, ll r) : l(l), r(r), m(sqrt(r)+1) {\n\t\t\
    small.resize(m);\n\t\tiota(small.begin(), small.end(), 0);\n\t\tlarge.resize(r-l);\n\
    \t\taux.assign(r-l, 1);\n\n\t\tfor(ll i = 2;i*i < r;i++){\n\t\t\tif(small[i] <\
    \ i)continue;\n\t\t\tsmall[i] = i; // \u3053\u308C\u8981\u308B\u304B\uFF1F\n\t\
    \t\tfor(ll j = i*i;j < m;j += i){\n\t\t\t\tif(small[j] == j)small[j] = i;\n\t\t\
    \t}\n\t\t\tfor(ll j = (l+i-1)/i*i;j < r;j += i){\n\t\t\t\tll k = j;\n\t\t\t\t\
    do{\n\t\t\t\t\tif(aux[j-l] * aux[j-l] > r)break;\n\n\t\t\t\t\tlarge[j-l].push_back(i);\n\
    \t\t\t\t\taux[j-l] *= i;\n\t\t\t\t\tk /= i;\n\t\t\t\t}while(k % i == 0);\n\t\t\
    \t}\n\t\t}\n\t}\n\n\tvector<ll> factor(ll n) {\n\t\tassert(l <= n && n < r);\n\
    \t\tvector<ll> res = large[n-l];\n\t\tn /= aux[n-l];\n\t\tif(n >= m){\n\t\t\t\
    res.push_back(n);\n\t\t\treturn res;\n\t\t}\n\t\twhile(n > 1){\n\t\t\tres.push_back(small[n]);\n\
    \t\t\tn /= small[n];\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  code: "// \u672A\u691C\u8A3C\n#include <bits/stdc++.h>\nusing ll = long long;\n\
    using namespace std;\n\nclass range_sieve {\n\tll l, r, m;\n\tvector<int> small;\n\
    \tvector<vector<ll>> large;\n\tvector<ll> aux;\n\npublic:\n\trange_sieve(ll l,\
    \ ll r) : l(l), r(r), m(sqrt(r)+1) {\n\t\tsmall.resize(m);\n\t\tiota(small.begin(),\
    \ small.end(), 0);\n\t\tlarge.resize(r-l);\n\t\taux.assign(r-l, 1);\n\n\t\tfor(ll\
    \ i = 2;i*i < r;i++){\n\t\t\tif(small[i] < i)continue;\n\t\t\tsmall[i] = i; //\
    \ \u3053\u308C\u8981\u308B\u304B\uFF1F\n\t\t\tfor(ll j = i*i;j < m;j += i){\n\t\
    \t\t\tif(small[j] == j)small[j] = i;\n\t\t\t}\n\t\t\tfor(ll j = (l+i-1)/i*i;j\
    \ < r;j += i){\n\t\t\t\tll k = j;\n\t\t\t\tdo{\n\t\t\t\t\tif(aux[j-l] * aux[j-l]\
    \ > r)break;\n\n\t\t\t\t\tlarge[j-l].push_back(i);\n\t\t\t\t\taux[j-l] *= i;\n\
    \t\t\t\t\tk /= i;\n\t\t\t\t}while(k % i == 0);\n\t\t\t}\n\t\t}\n\t}\n\n\tvector<ll>\
    \ factor(ll n) {\n\t\tassert(l <= n && n < r);\n\t\tvector<ll> res = large[n-l];\n\
    \t\tn /= aux[n-l];\n\t\tif(n >= m){\n\t\t\tres.push_back(n);\n\t\t\treturn res;\n\
    \t\t}\n\t\twhile(n > 1){\n\t\t\tres.push_back(small[n]);\n\t\t\tn /= small[n];\n\
    \t\t}\n\t\treturn res;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/range_sieve.cpp
  requiredBy: []
  timestamp: '2024-03-08 22:36:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/range_sieve.cpp
layout: document
redirect_from:
- /library/Math/range_sieve.cpp
- /library/Math/range_sieve.cpp.html
title: Math/range_sieve.cpp
---

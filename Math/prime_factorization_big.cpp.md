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
    - https://judge.yosupo.jp/submission/124918
  bundledCode: "#line 1 \"Math/prime_factorization_big.cpp\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n// https://judge.yosupo.jp/submission/124918\n\n// \u5927\
    \u304D\u306A\u6570\u306B\u5BFE\u3059\u308B\u7D20\u56E0\u6570\u5206\u89E3\u306F\
    \u3053\u3063\u3061\u306E\u65B9\u304C\u306F\u3084\u3044\n// \u305F\u3060\u3001\u30ED\
    \u30FC\u6CD5\u306E\u7591\u4F3C\u4E71\u6570\u751F\u6210\u304C\u7518\u3044\u3088\
    \u3046\u3060\n\n__int128_t power(__int128_t n, __int128_t k, __int128_t m) {\n\
    \    n %= m;\n\t__int128_t ret = 1;\n    while(k > 0){\n        if(k & 1)ret =\
    \ ret * n % m;\n        n = __int128_t(n) * n % m;\n        k >>= 1;\n    }\n\
    \    return ret % m;\n}\n\n\nbool is_prime(int64_t n){\n    if(n <= 1)return false;\n\
    \    if(n == 2 || n == 3 || n == 5)return true;\n    if(n % 2 == 0)return false;\n\
    \    if(n % 3 == 0)return false;\n    if(n % 5 == 0)return false;\n\n    vector<int64_t>\
    \ A = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};\n\n    int64_t s = 0,\
    \ d = n - 1;\n    while(d % 2 == 0){\n        s++;\n        d >>= 1;\n    }\n\n\
    \    for (auto a : A){\n        if(a % n == 0)return true;\n        int64_t t,\
    \ x = power(a, d, n);\n        if(x != 1){\n            for(t = 0;t < s;t++){\n\
    \                if(x == n - 1)break;\n                x = __int128_t(x) * x %\
    \ n;\n            }\n            if(t == s)return false;\n        }\n    }\n \
    \   return true;\n}\n\nint64_t rho(int64_t n){\n    if(n % 2 == 0)return 2;\n\
    \    if(is_prime(n))return n;\n\n    auto f = [&](int64_t x) -> int64_t {\n  \
    \      return (__int128_t(x) * x + 13) % n;\n    };\n\n    int64_t step = 0;\n\
    \    while (true) {\n        ++step;\n        int64_t x = step, y = f(x);\n  \
    \      while (true) {\n            int64_t p = gcd(y - x + n, n);\n          \
    \  if (p == 0 || p == n) break;\n            if (p != 1) return p;\n         \
    \   x = f(x);\n            y = f(f(y));\n        }\n    }\n\n}\n\nvector<int64_t>\
    \ factorize(int64_t x){\n    if(x == 1)return {};\n    int64_t p = rho(x);\n \
    \   if(p == x) return {p};\n    \n    vector<int64_t> l = factorize(p);\n    vector<int64_t>\
    \ r = factorize(x / p);\n\n    l.insert(l.end(), r.begin(), r.end());\n    sort(l.begin(),\
    \ l.end());\n\n    return l;\n}\n\nvoid solve(){\n    long long n;\n    cin >>\
    \ n;\n    auto ret = factorize(n);\n    int k = ret.size();\n    cout << k;\n\
    \    for(int i = 0;i < k;i++){\n        cout << \" \";\n        cout << ret[i];\n\
    \    }\n    cout << endl;\n}\n\nint main(){\n    int t = 1;\n    cin >> t;\n \
    \   while(t--)solve();\n}\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\n\n// https://judge.yosupo.jp/submission/124918\n\
    \n// \u5927\u304D\u306A\u6570\u306B\u5BFE\u3059\u308B\u7D20\u56E0\u6570\u5206\u89E3\
    \u306F\u3053\u3063\u3061\u306E\u65B9\u304C\u306F\u3084\u3044\n// \u305F\u3060\u3001\
    \u30ED\u30FC\u6CD5\u306E\u7591\u4F3C\u4E71\u6570\u751F\u6210\u304C\u7518\u3044\
    \u3088\u3046\u3060\n\n__int128_t power(__int128_t n, __int128_t k, __int128_t\
    \ m) {\n    n %= m;\n\t__int128_t ret = 1;\n    while(k > 0){\n        if(k &\
    \ 1)ret = ret * n % m;\n        n = __int128_t(n) * n % m;\n        k >>= 1;\n\
    \    }\n    return ret % m;\n}\n\n\nbool is_prime(int64_t n){\n    if(n <= 1)return\
    \ false;\n    if(n == 2 || n == 3 || n == 5)return true;\n    if(n % 2 == 0)return\
    \ false;\n    if(n % 3 == 0)return false;\n    if(n % 5 == 0)return false;\n\n\
    \    vector<int64_t> A = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};\n\
    \n    int64_t s = 0, d = n - 1;\n    while(d % 2 == 0){\n        s++;\n      \
    \  d >>= 1;\n    }\n\n    for (auto a : A){\n        if(a % n == 0)return true;\n\
    \        int64_t t, x = power(a, d, n);\n        if(x != 1){\n            for(t\
    \ = 0;t < s;t++){\n                if(x == n - 1)break;\n                x = __int128_t(x)\
    \ * x % n;\n            }\n            if(t == s)return false;\n        }\n  \
    \  }\n    return true;\n}\n\nint64_t rho(int64_t n){\n    if(n % 2 == 0)return\
    \ 2;\n    if(is_prime(n))return n;\n\n    auto f = [&](int64_t x) -> int64_t {\n\
    \        return (__int128_t(x) * x + 13) % n;\n    };\n\n    int64_t step = 0;\n\
    \    while (true) {\n        ++step;\n        int64_t x = step, y = f(x);\n  \
    \      while (true) {\n            int64_t p = gcd(y - x + n, n);\n          \
    \  if (p == 0 || p == n) break;\n            if (p != 1) return p;\n         \
    \   x = f(x);\n            y = f(f(y));\n        }\n    }\n\n}\n\nvector<int64_t>\
    \ factorize(int64_t x){\n    if(x == 1)return {};\n    int64_t p = rho(x);\n \
    \   if(p == x) return {p};\n    \n    vector<int64_t> l = factorize(p);\n    vector<int64_t>\
    \ r = factorize(x / p);\n\n    l.insert(l.end(), r.begin(), r.end());\n    sort(l.begin(),\
    \ l.end());\n\n    return l;\n}\n\nvoid solve(){\n    long long n;\n    cin >>\
    \ n;\n    auto ret = factorize(n);\n    int k = ret.size();\n    cout << k;\n\
    \    for(int i = 0;i < k;i++){\n        cout << \" \";\n        cout << ret[i];\n\
    \    }\n    cout << endl;\n}\n\nint main(){\n    int t = 1;\n    cin >> t;\n \
    \   while(t--)solve();\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/prime_factorization_big.cpp
  requiredBy: []
  timestamp: '2023-02-08 19:33:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/prime_factorization_big.cpp
layout: document
redirect_from:
- /library/Math/prime_factorization_big.cpp
- /library/Math/prime_factorization_big.cpp.html
title: Math/prime_factorization_big.cpp
---

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
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B
    - https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
  bundledCode: "#line 1 \"Strings/rolling_hash.cpp\"\n# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B\"\
    \n# include <bits/stdc++.h>\nusing namespace std;\n\n//https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\n\
    \n// char \u304C 0-127 \u3067\u3042\u308B\u3053\u3068\u3092\u5229\u7528\u3057\u3066\
    \u3044\u308B\u3053\u3068\u306B\u6CE8\u610F\nstruct rolling_hash {\n    using ull\
    \ = unsigned long long;\n\n    const ull MASK30 = (1UL << 30) - 1;\n    const\
    \ ull MASK31 = (1UL << 31) - 1;\n    const ull MOD = (1UL << 61) - 1;\n    const\
    \ ull MASK61 = MOD;\n    const ull POSITIVIZER = MOD * ((1UL << 3) - 1);\n\n \
    \   string s;\n    int n;\n    const ull bs = 23948798;\n\n    vector<ull> base_pow;\n\
    \    vector<ull> prefix_hash;\n\n    rolling_hash(string _s){\n        s = _s;\n\
    \        n = int(s.size());\n        base_pow.resize(n + 1);\n        base_pow[0]\
    \ = 1;\n        for(int i = 0;i < n;i++){\n            base_pow[i + 1] = calcmod(mul(base_pow[i],\
    \ bs));\n        }\n        \n\n        prefix_hash.resize(n + 1, 0LL);\n    \
    \    for(int i = 0;i < n;i++){\n            prefix_hash[i + 1] = calcmod(mul(prefix_hash[i],\
    \ bs) + s[i]);\n            \n        }\n    }\n\n    ull slice(int begin, int\
    \ length){\n        return calcmod(prefix_hash[begin + length] + POSITIVIZER -\
    \ mul(prefix_hash[begin], base_pow[length]));\n    }\n\n    //a * b % mod (2^{61}\
    \ - 1)\n    ull mul(ull a, ull b){\n        ull au = a >> 31;\n        ull ad\
    \ = a & MASK31;\n        ull bu = b >> 31;\n        ull bd = b & MASK31;\n   \
    \     ull mid = ad * bu + au * bd;\n        ull midu = mid >> 30;\n        ull\
    \ midd = mid & MASK30;\n        return calcmod(au * bu * 2 + midu + (midd << 31)\
    \ + ad * bd);\n    }\n\n    // mod(2^{61} - 1)\n    ull calcmod(ull x){\n    \
    \    ull xu = x >> 61;\n        ull xd = x & MASK61;\n        ull res = xu + xd;\n\
    \        if (res >= MOD) res -= MOD;\n        return res;\n    }\n};\n\nint main(){\n\
    \    string s, t;\n    cin >> s >> t;\n    string st = s + t;\n    rolling_hash\
    \ rh(st);\n\n    for(int i = 0;i < (int)s.size() - (int)t.size() + 1;i++){\n \
    \       if(rh.slice(i, (int)t.size()) == rh.slice((int)s.size(), (int)t.size())){\n\
    \            cout << i << endl;\n        }\n    }\n}\n"
  code: "# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B\"\
    \n# include <bits/stdc++.h>\nusing namespace std;\n\n//https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\n\
    \n// char \u304C 0-127 \u3067\u3042\u308B\u3053\u3068\u3092\u5229\u7528\u3057\u3066\
    \u3044\u308B\u3053\u3068\u306B\u6CE8\u610F\nstruct rolling_hash {\n    using ull\
    \ = unsigned long long;\n\n    const ull MASK30 = (1UL << 30) - 1;\n    const\
    \ ull MASK31 = (1UL << 31) - 1;\n    const ull MOD = (1UL << 61) - 1;\n    const\
    \ ull MASK61 = MOD;\n    const ull POSITIVIZER = MOD * ((1UL << 3) - 1);\n\n \
    \   string s;\n    int n;\n    const ull bs = 23948798;\n\n    vector<ull> base_pow;\n\
    \    vector<ull> prefix_hash;\n\n    rolling_hash(string _s){\n        s = _s;\n\
    \        n = int(s.size());\n        base_pow.resize(n + 1);\n        base_pow[0]\
    \ = 1;\n        for(int i = 0;i < n;i++){\n            base_pow[i + 1] = calcmod(mul(base_pow[i],\
    \ bs));\n        }\n        \n\n        prefix_hash.resize(n + 1, 0LL);\n    \
    \    for(int i = 0;i < n;i++){\n            prefix_hash[i + 1] = calcmod(mul(prefix_hash[i],\
    \ bs) + s[i]);\n            \n        }\n    }\n\n    ull slice(int begin, int\
    \ length){\n        return calcmod(prefix_hash[begin + length] + POSITIVIZER -\
    \ mul(prefix_hash[begin], base_pow[length]));\n    }\n\n    //a * b % mod (2^{61}\
    \ - 1)\n    ull mul(ull a, ull b){\n        ull au = a >> 31;\n        ull ad\
    \ = a & MASK31;\n        ull bu = b >> 31;\n        ull bd = b & MASK31;\n   \
    \     ull mid = ad * bu + au * bd;\n        ull midu = mid >> 30;\n        ull\
    \ midd = mid & MASK30;\n        return calcmod(au * bu * 2 + midu + (midd << 31)\
    \ + ad * bd);\n    }\n\n    // mod(2^{61} - 1)\n    ull calcmod(ull x){\n    \
    \    ull xu = x >> 61;\n        ull xd = x & MASK61;\n        ull res = xu + xd;\n\
    \        if (res >= MOD) res -= MOD;\n        return res;\n    }\n};\n\nint main(){\n\
    \    string s, t;\n    cin >> s >> t;\n    string st = s + t;\n    rolling_hash\
    \ rh(st);\n\n    for(int i = 0;i < (int)s.size() - (int)t.size() + 1;i++){\n \
    \       if(rh.slice(i, (int)t.size()) == rh.slice((int)s.size(), (int)t.size())){\n\
    \            cout << i << endl;\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: Strings/rolling_hash.cpp
  requiredBy: []
  timestamp: '2024-03-05 16:59:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Strings/rolling_hash.cpp
layout: document
redirect_from:
- /library/Strings/rolling_hash.cpp
- /library/Strings/rolling_hash.cpp.html
title: Strings/rolling_hash.cpp
---

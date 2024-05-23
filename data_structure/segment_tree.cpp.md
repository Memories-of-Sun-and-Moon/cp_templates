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
    - https://onlinejudge.u-aizu.ac.jp/status/users/M3_cp/submissions/2/DSL_2_A/judge/6708968/C++17
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
  code: "#include \"bits/stdc++.h\"\nusing namespace std;\n\n// Verified\n// https://onlinejudge.u-aizu.ac.jp/status/users/M3_cp/submissions/2/DSL_2_A/judge/6708968/C++17\n\
    \ntemplate<typename T>struct segment_tree {\n    using F = function<T(T, T)>;\n\
    \n    int n;\n    vector<T> node;\n    F combine; // \u533A\u9593\u306E\u6F14\u7B97\
    \n    T identify; // \u5358\u4F4D\u5143\n\n    //\u6271\u3046\u914D\u5217\u304C\
    \u3059\u3067\u306B\u3067\u304D\u3066\u3044\u308B\u5834\u5408\n    segment_tree(vector<T>\
    \ v, F _combine, T _identity) : combine(_combine), identify(_identity) {\n   \
    \     int sz = (int)v.size();\n        n = 1;\n        while(n < sz)n *= 2;\n\
    \        node.resize(2 * n - 1, identify);\n\n        for(int i = 0;i < sz;i++)node[i\
    \ + n - 1] = v[i];\n        for(int i = n - 2;i >= 0;i--)node[i] = combine(node[2\
    \ * i + 1], node[2 * i + 2]);\n    }\n\n    //\u7A7A\u306E\u3082\u306E\u304B\u3089\
    \u3084\u3063\u3066\u3044\u304F\u5834\u5408\n    segment_tree(int _n, F _combine,\
    \ T _identify) : combine(_combine), identify(_identify){\n        int sz = _n;\n\
    \        n = 1;\n        while(n < sz)n *= 2;\n        node.resize(2 * n - 1,\
    \ identify);\n    }\n\n    T operator[](int x) {return node[x + n - 1]; }\n\n\
    \    void set(int x, T val){\n        x += (n - 1);\n\n        node[x] = val;\n\
    \        while(x > 0){\n            x = (x - 1) / 2;\n            node[x] = combine(node[2\
    \ * x + 1], node[2 * x + 2]);\n        }\n    }\n\n    T fold(int a, int b, int\
    \ k = 0, int l = 0, int r = -1){\n        //\u6700\u521D\u306B\u547C\u3073\u51FA\
    \u3055\u308C\u305F\u6642\u306E\u5BFE\u8C61\u533A\u9593\u306F [0, n)\n        if(r\
    \ < 0) r = n;\n\n        //\u8981\u6C42\u533A\u9593\u3068\u5BFE\u8C61\u533A\u9593\
    \u304C\u4EA4\u308F\u3089\u306A\u3044 -> \u9069\u5F53\u306B\uFF08\u5358\u4F4D\u5143\
    \u3092\uFF09\u8FD4\u3059\n        if(r <= a || b <= l)return identify;\n     \
    \   \n        //\u8981\u6C42\u533A\u9593\u304C\u5BFE\u8C61\u533A\u9593\u3068\u5B8C\
    \u5168\u88AB\u8986 -> \u5BFE\u8C61\u533A\u9593\u3092\u7B54\u3048\u306E\u8A08\u7B97\
    \u306B\u4F7F\u3046\n        if(a <= l && r <= b)return node[k];\n\n        //\u8981\
    \u6C42\u533A\u9593\u304C\u5BFE\u8C61\u533A\u9593\u306E\u4E00\u90E8\u3092\u88AB\
    \u8986 -> \u5B50\u306B\u3064\u3044\u3066\u306E\u63A2\u7D22\u3092\u884C\u3046\n\
    \        T vl = fold(a, b, 2 * k + 1, l, (l + r) / 2);\n        T vr = fold(a,\
    \ b, 2 * k + 2, (l + r) / 2, r);\n        return combine(vl, vr);\n    }\n};\n\
    \n//Usage\n\nint n;\n\nint main(){\n    auto combine_sum = [](int a, int b){return\
    \ a + b; };\n    segment_tree<int> Range_Sum_Query(n, combine_sum, 0);\n}\n\n\
    /*\u8EE2\u5012\u6570\nint main() {\n    auto combine_sum = [](int a, int b){return\
    \ a + b; };\n    segment_tree<int> seg(n, combine_sum, 0);\n\n    LL ans = 0;\n\
    \n    REP(i, n){\n        LL num = i - seg.fold(0, a[i]);\n        seg.set(a[i],\
    \ 1);\n        ans += num;\n    }\n}\n*/"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segment_tree.cpp
  requiredBy: []
  timestamp: '2024-05-23 22:56:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/segment_tree.cpp
layout: document
redirect_from:
- /library/data_structure/segment_tree.cpp
- /library/data_structure/segment_tree.cpp.html
title: data_structure/segment_tree.cpp
---

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
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bits/stdc++.h:\
    \ line -1: no such header\n"
  code: "# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B\"\
    \n# include \"bits/stdc++.h\"\nusing namespace std;\n\n\n//1-indexed \u306B\u6CE8\
    \u610F\ntemplate<typename T>struct binary_indexed_tree {\n    int n;\n    vector<T>\
    \ BIT;\n    binary_indexed_tree(int n_) : n(n_ + 1), BIT(n, 0) {}\n\n    void\
    \ add(int i, T x){\n        for(int idx = i;idx < n;idx += (idx & -idx)){\n  \
    \          BIT[idx] += x;\n        }\n    }\n\n    //[1, i] \u306E\u7DCF\u548C\
    \n    T sum(int i) {\n        T ret = 0;\n        for(int idx = i;idx > 0;idx\
    \ -= (idx & -idx)){\n            ret += BIT[idx];\n        }\n        return ret;\n\
    \    }\n};\n\nint main(){\n    int n, q;\n    cin >> n >> q;\n    binary_indexed_tree<int>\
    \ bit(n);\n    while(q--){\n        int com, x, y;\n        cin >> com >> x >>\
    \ y;\n        if(com == 0){\n            bit.add(x, y);\n        }else{\n    \
    \        cout << bit.sum(y) - (x != 1 ? bit.sum(x - 1) : 0) << endl;\n       \
    \ }\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/binary_indexed_tree.cpp
  requiredBy: []
  timestamp: '2024-05-23 22:56:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/binary_indexed_tree.cpp
layout: document
redirect_from:
- /library/data_structure/binary_indexed_tree.cpp
- /library/data_structure/binary_indexed_tree.cpp.html
title: data_structure/binary_indexed_tree.cpp
---

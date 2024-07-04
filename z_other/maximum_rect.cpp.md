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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bits/stdc++.h:\
    \ line -1: no such header\n"
  code: "#include \"bits/stdc++.h\"\nusing namespace std;\n\nusing ll = long long;\n\
    \nll maximum_rect(vector<ll> a){\n\tint n = (int)a.size();\n\tvector<ll> l(n),\
    \ r(n);\n\t{\n\t\tstack<ll> st;\n\t\tfor(int i = 0;i < n;i++){\n\t\t\twhile(not\
    \ st.empty() && a[st.top()] >= a[i])st.pop();\n\t\t\tl[i] = (st.empty() ? 0 :\
    \ st.top() + 1);\n\t\t\tst.push(i);\n\t\t}\n\t}\n\t{\n\t\tstack<ll> st;\n\t\t\
    for(int i = n - 1;i >= 0;i--){\n\t\t\twhile(not st.empty() && a[st.top()] >= a[i])st.pop();\n\
    \t\t\tr[i] = (st.empty() ? n : st.top());\n\t\t\tst.push(i);\n\t\t}\n\t}\n\tll\
    \ ans = 0;\n\tfor(int i = 0;i < n;i++)ans = max(ans, a[i] * (r[i] - l[i]));\n\t\
    return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: z_other/maximum_rect.cpp
  requiredBy: []
  timestamp: '2024-07-04 21:12:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: z_other/maximum_rect.cpp
layout: document
redirect_from:
- /library/z_other/maximum_rect.cpp
- /library/z_other/maximum_rect.cpp.html
title: z_other/maximum_rect.cpp
---

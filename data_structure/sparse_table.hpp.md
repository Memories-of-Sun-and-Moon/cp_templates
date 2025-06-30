---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/staticrmq.test.cpp
    title: verify/yosupo/staticrmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/sparse_table.hpp\"\n\ntemplate<typename T>\n\
    struct sparse_table {\n\tusing F = function<T(T, T)>;\n\n\tF f;\n\tstd::vector<std::vector<T>>\
    \ table;\n\tstd::vector<int> lr_length;\n\n\tsparse_table() = default;\n\n\tsparse_table(const\
    \ std::vector<T> &v, const F &_f) : f(_f) {\n\t\tconst int n = (int)v.size();\n\
    \t\tconst int msb = 32 - __builtin_clz(n);\n\t\t\n\t\ttable.assign(msb, std::vector<T>(n));\n\
    \t\tfor(int i = 0;i < ssize(v);i++){\n\t\t\ttable[0][i] = v[i];\n\t\t}\n\t\tfor(int\
    \ i = 1;i < msb;i++){\n\t\t\tfor(int j = 0;j + (1 << i) <= n;j++){\n\t\t\t\ttable[i][j]\
    \ = f(table[i-1][j], table[i-1][j + (1 << (i-1))]);\n\t\t\t}\n\t\t}\n\n\t\tlr_length.resize(ssize(v)\
    \ + 1);\n\t\tfor(int i = 2;i < ssize(lr_length);i++){\n\t\t\tlr_length[i] = lr_length[i\
    \ >> 1] + 1;\n\t\t}\n\t}\n\n\tT fold(int l, int r) const {\n\t\treturn f(table[lr_length[r-l]][l],\
    \ table[lr_length[r-l]][r-(1 << lr_length[r-l])]);\n\t}\n};\n"
  code: "\ntemplate<typename T>\nstruct sparse_table {\n\tusing F = function<T(T,\
    \ T)>;\n\n\tF f;\n\tstd::vector<std::vector<T>> table;\n\tstd::vector<int> lr_length;\n\
    \n\tsparse_table() = default;\n\n\tsparse_table(const std::vector<T> &v, const\
    \ F &_f) : f(_f) {\n\t\tconst int n = (int)v.size();\n\t\tconst int msb = 32 -\
    \ __builtin_clz(n);\n\t\t\n\t\ttable.assign(msb, std::vector<T>(n));\n\t\tfor(int\
    \ i = 0;i < ssize(v);i++){\n\t\t\ttable[0][i] = v[i];\n\t\t}\n\t\tfor(int i =\
    \ 1;i < msb;i++){\n\t\t\tfor(int j = 0;j + (1 << i) <= n;j++){\n\t\t\t\ttable[i][j]\
    \ = f(table[i-1][j], table[i-1][j + (1 << (i-1))]);\n\t\t\t}\n\t\t}\n\n\t\tlr_length.resize(ssize(v)\
    \ + 1);\n\t\tfor(int i = 2;i < ssize(lr_length);i++){\n\t\t\tlr_length[i] = lr_length[i\
    \ >> 1] + 1;\n\t\t}\n\t}\n\n\tT fold(int l, int r) const {\n\t\treturn f(table[lr_length[r-l]][l],\
    \ table[lr_length[r-l]][r-(1 << lr_length[r-l])]);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sparse_table.hpp
  requiredBy: []
  timestamp: '2025-06-30 19:47:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/staticrmq.test.cpp
documentation_of: data_structure/sparse_table.hpp
layout: document
redirect_from:
- /library/data_structure/sparse_table.hpp
- /library/data_structure/sparse_table.hpp.html
title: data_structure/sparse_table.hpp
---

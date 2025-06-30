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
  bundledCode: "#line 1 \"data_structure/rollbackmo.hpp\"\n\nclass RollbackMo {\n\t\
    std::vector<std::pair<int, int>> lr;\npublic:\n\tRollbackMo() = default;\n\tRollbackMo(const\
    \ std::vector<std::pair<int, int>> &_lr) : lr(_lr) {}\n\n\ttemplate<typename AL,\
    \ typename AR, typename RST, typename SNP, typename RB, typename F>\n\tvoid calc(const\
    \ AL &add_left, const AR &add_right, const RST &reset, const SNP &snapshot, const\
    \ RB &rollback, const F &f,  int _n = -1, int _B = -1){\n\t\tint n = (_n == -1\
    \ ? ranges::max(lr, {}, &std::pair<int, int>::second).second : _n);\n\t\tint q\
    \ = (int)lr.size();\n\t\tint B = (_B == -1 ? max(1, n/int(sqrt(q))) : _B);\n\n\
    \t\tauto naive = [&](int idx) -> void {\n\t\t\tsnapshot();\n\t\t\tconst auto &[l,\
    \ r] = lr[idx];\n\t\t\tfor(int i = l;i < r;i++)add_right(l, i);\n\t\t\tf(idx);\n\
    \t\t\trollback();\n\t\t};\n\n\t\tstd::vector<std::vector<int>> index((n+B-1)/B);\n\
    \t\tindex.reserve(q);\n\t\tfor(int i = 0;i < q;i++){\n\t\t\tauto &[l, r] = lr[i];\n\
    \t\t\tif(l/B == r/B)naive(i);\n\t\t\telse index[l/B].pb(i);\n\t\t}\n\n\t\tfor(auto\
    \ &v : index){\n\t\t\tif(v.empty())continue;\n\t\t\tsort(v.begin(), v.end(), [&](int\
    \ i, int j){\n\t\t\t\tconst auto &[l_i, r_i] = lr[i];\n\t\t\t\tconst auto &[l_j,\
    \ r_j] = lr[j];\n\t\t\t\treturn r_i < r_j;\n\t\t\t});\n\t\t\tint LMAX = 0;\n\t\
    \t\tfor(auto &idx : v){\n\t\t\t\tauto &[l, r] = lr[idx];\n\t\t\t\tLMAX = max(LMAX,\
    \ l);\n\t\t\t}\n\t\t\treset();\n\t\t\tint l = LMAX, r = LMAX;\n\t\t\tfor(auto\
    \ &idx : v){\n\t\t\t\tauto &[L, R] = lr[idx];\n\t\t\t\twhile(r < R)add_right(l,\
    \ r++);\n\t\t\t\tsnapshot();\n\t\t\t\twhile(L < l)add_left(--l, r);\n\t\t\t\t\
    f(idx);\n\t\t\t\trollback();\n\t\t\t\tl = LMAX;\n\t\t\t}\n\t\t}\n\t}\n};\n"
  code: "\nclass RollbackMo {\n\tstd::vector<std::pair<int, int>> lr;\npublic:\n\t\
    RollbackMo() = default;\n\tRollbackMo(const std::vector<std::pair<int, int>> &_lr)\
    \ : lr(_lr) {}\n\n\ttemplate<typename AL, typename AR, typename RST, typename\
    \ SNP, typename RB, typename F>\n\tvoid calc(const AL &add_left, const AR &add_right,\
    \ const RST &reset, const SNP &snapshot, const RB &rollback, const F &f,  int\
    \ _n = -1, int _B = -1){\n\t\tint n = (_n == -1 ? ranges::max(lr, {}, &std::pair<int,\
    \ int>::second).second : _n);\n\t\tint q = (int)lr.size();\n\t\tint B = (_B ==\
    \ -1 ? max(1, n/int(sqrt(q))) : _B);\n\n\t\tauto naive = [&](int idx) -> void\
    \ {\n\t\t\tsnapshot();\n\t\t\tconst auto &[l, r] = lr[idx];\n\t\t\tfor(int i =\
    \ l;i < r;i++)add_right(l, i);\n\t\t\tf(idx);\n\t\t\trollback();\n\t\t};\n\n\t\
    \tstd::vector<std::vector<int>> index((n+B-1)/B);\n\t\tindex.reserve(q);\n\t\t\
    for(int i = 0;i < q;i++){\n\t\t\tauto &[l, r] = lr[i];\n\t\t\tif(l/B == r/B)naive(i);\n\
    \t\t\telse index[l/B].pb(i);\n\t\t}\n\n\t\tfor(auto &v : index){\n\t\t\tif(v.empty())continue;\n\
    \t\t\tsort(v.begin(), v.end(), [&](int i, int j){\n\t\t\t\tconst auto &[l_i, r_i]\
    \ = lr[i];\n\t\t\t\tconst auto &[l_j, r_j] = lr[j];\n\t\t\t\treturn r_i < r_j;\n\
    \t\t\t});\n\t\t\tint LMAX = 0;\n\t\t\tfor(auto &idx : v){\n\t\t\t\tauto &[l, r]\
    \ = lr[idx];\n\t\t\t\tLMAX = max(LMAX, l);\n\t\t\t}\n\t\t\treset();\n\t\t\tint\
    \ l = LMAX, r = LMAX;\n\t\t\tfor(auto &idx : v){\n\t\t\t\tauto &[L, R] = lr[idx];\n\
    \t\t\t\twhile(r < R)add_right(l, r++);\n\t\t\t\tsnapshot();\n\t\t\t\twhile(L <\
    \ l)add_left(--l, r);\n\t\t\t\tf(idx);\n\t\t\t\trollback();\n\t\t\t\tl = LMAX;\n\
    \t\t\t}\n\t\t}\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/rollbackmo.hpp
  requiredBy: []
  timestamp: '2025-06-30 19:47:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/rollbackmo.hpp
layout: document
title: Rollback Mo
---

# Rollback Mo

- 削除操作のない Mo's Algorithm

## 使い方

実装の詳細は [ABC388-Gの提出](https://atcoder.jp/contests/abc388/submissions/61703817) 等を見るといい

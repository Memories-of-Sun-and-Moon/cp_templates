---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/iroot.hpp
    title: "floor K \u4E57\u6839"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/counting_primes.test.cpp
    title: verify/yosupo/counting_primes.test.cpp
  - icon: ':x:'
    path: verify/yukicoder/1661.test.cpp
    title: verify/yukicoder/1661.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://judge.yosupo.jp/submission/61551
    - https://rsk0315.hatenablog.com/entry/2021/05/18/015511
  bundledCode: "#line 2 \"math/counting_primes.hpp\"\n\n#line 2 \"math/iroot.hpp\"\
    \n\n#include<cmath>\n#include<limits>\n\nunsigned long long iroot(unsigned long\
    \ long n, int k=2){\n\tconstexpr unsigned long long LIM = std::numeric_limits<unsigned\
    \ long long>::max();\n\tif(n <= 1 || k == 1){\n\t\treturn n;\n\t}\n\tif(k >= 64){\n\
    \t\treturn 1;\n\t}\n\tif(k == 2){\n\t\treturn sqrtl(n);\n\t}\n\n\tif(n == LIM)n--;\n\
    \n\tauto safe_mul = [&](unsigned long long &x, unsigned long long &y) -> void\
    \ {\n\t\tif(x <= LIM / y){\n\t\t\tx *= y;\n\t\t}else{\n\t\t\tx = LIM;\n\t\t}\n\
    \t};\n\n\tauto power = [&](unsigned long long a, int b) -> unsigned long long\
    \ {\n\t\tunsigned long long ret = 1;\n\t\twhile(b){\n\t\t\tif(b & 1)safe_mul(ret,\
    \ a);\n\t\t\tsafe_mul(a, a);\n\t\t\tb >>= 1;\n\t\t}\n\t\treturn ret;\n\t};\n\n\
    \tunsigned long long ret = (k == 3 ? cbrt(n)-1 : std::pow(n, std::nextafter(1.0/double(k),\
    \ 0.0)));\n\twhile(power(ret+1, k) <= n)ret++;\n\treturn ret;\n}\n#line 4 \"math/counting_primes.hpp\"\
    \n\n#include<vector>\n\n//https://judge.yosupo.jp/submission/61551\n//https://rsk0315.hatenablog.com/entry/2021/05/18/015511\n\
    long long counting_primes(const long long N) {\n\tif (N <= 1) return 0;\n\tif\
    \ (N == 2) return 1;\n\tconst int v = iroot(N);\n\tint s = (v + 1) / 2;\n\tstd::vector<int>\
    \ smalls(s);\n\tfor (int i = 1; i < s; i++) smalls[i] = i;\n\tstd::vector<int>\
    \ roughs(s);\n\tfor (int i = 0; i < s; i++) roughs[i] = 2 * i + 1;\n\tstd::vector<long\
    \ long> larges(s);\n\tfor (int i = 0; i < s; i++) larges[i] = (N / (2 * i + 1)\
    \ - 1) / 2;\n\tstd::vector<bool> skip(v + 1);\n\tconst auto divide = [](long long\
    \ n, long long d) -> int { return (double)n / d;};\n\tconst auto half = [](int\
    \ n) -> int { return (n - 1) >> 1;};\n\tint pc = 0;\n\tfor (int p = 3; p <= v;\
    \ p += 2) if (!skip[p]) {\n\t\tint q = p * p;\n\t\tif ((long long)q * q > N) break;\n\
    \t\tskip[p] = true;\n\t\tfor (int i = q; i <= v; i += 2 * p) skip[i] = true;\n\
    \t\tint ns = 0;\n\t\tfor (int k = 0; k < s; k++) {\n\t\t\tint i = roughs[k];\n\
    \t\t\tif (skip[i]) continue;\n\t\t\tlong long d = (long long)i * p;\n\t\t\tlarges[ns]\
    \ = larges[k] - (d <= v ? larges[smalls[d >> 1] - pc] : smalls[half(divide(N,\
    \ d))]) + pc;\n\t\t\troughs[ns++] = i;\n\t\t}\n\t\ts = ns;\n\t\tfor (int i = half(v),\
    \ j = ((v / p) - 1) | 1; j >= p; j -= 2) {\n\t\t\tint c = smalls[j >> 1] - pc;\n\
    \t\t\tfor (int e = (j * p) >> 1; i >= e; i--) smalls[i] -= c;\n\t\t}\n\t\tpc++;\n\
    \t}\n\tlarges[0] += (long long)(s + 2 * (pc - 1)) * (s - 1) / 2;\n\tfor (int k\
    \ = 1; k < s; k++) larges[0] -= larges[k];\n\tfor (int l = 1; l < s; l++) {\n\t\
    \tlong long q = roughs[l];\n\t\tlong long M = N / q;\n\t\tint e = smalls[half(M\
    \ / q)] - pc;\n\t\tif (e < l + 1) break;\n\t\tlong long t = 0;\n\t\tfor (int k\
    \ = l + 1; k <= e; k++)\n\t\t\tt += smalls[half(divide(M, roughs[k]))];\n\t\t\
    larges[0] += t - (long long)(e - l) * (pc + l - 1);\n\t}\n\treturn larges[0] +\
    \ 1;\n}\n"
  code: "#pragma once\n\n#include \"iroot.hpp\"\n\n#include<vector>\n\n//https://judge.yosupo.jp/submission/61551\n\
    //https://rsk0315.hatenablog.com/entry/2021/05/18/015511\nlong long counting_primes(const\
    \ long long N) {\n\tif (N <= 1) return 0;\n\tif (N == 2) return 1;\n\tconst int\
    \ v = iroot(N);\n\tint s = (v + 1) / 2;\n\tstd::vector<int> smalls(s);\n\tfor\
    \ (int i = 1; i < s; i++) smalls[i] = i;\n\tstd::vector<int> roughs(s);\n\tfor\
    \ (int i = 0; i < s; i++) roughs[i] = 2 * i + 1;\n\tstd::vector<long long> larges(s);\n\
    \tfor (int i = 0; i < s; i++) larges[i] = (N / (2 * i + 1) - 1) / 2;\n\tstd::vector<bool>\
    \ skip(v + 1);\n\tconst auto divide = [](long long n, long long d) -> int { return\
    \ (double)n / d;};\n\tconst auto half = [](int n) -> int { return (n - 1) >> 1;};\n\
    \tint pc = 0;\n\tfor (int p = 3; p <= v; p += 2) if (!skip[p]) {\n\t\tint q =\
    \ p * p;\n\t\tif ((long long)q * q > N) break;\n\t\tskip[p] = true;\n\t\tfor (int\
    \ i = q; i <= v; i += 2 * p) skip[i] = true;\n\t\tint ns = 0;\n\t\tfor (int k\
    \ = 0; k < s; k++) {\n\t\t\tint i = roughs[k];\n\t\t\tif (skip[i]) continue;\n\
    \t\t\tlong long d = (long long)i * p;\n\t\t\tlarges[ns] = larges[k] - (d <= v\
    \ ? larges[smalls[d >> 1] - pc] : smalls[half(divide(N, d))]) + pc;\n\t\t\troughs[ns++]\
    \ = i;\n\t\t}\n\t\ts = ns;\n\t\tfor (int i = half(v), j = ((v / p) - 1) | 1; j\
    \ >= p; j -= 2) {\n\t\t\tint c = smalls[j >> 1] - pc;\n\t\t\tfor (int e = (j *\
    \ p) >> 1; i >= e; i--) smalls[i] -= c;\n\t\t}\n\t\tpc++;\n\t}\n\tlarges[0] +=\
    \ (long long)(s + 2 * (pc - 1)) * (s - 1) / 2;\n\tfor (int k = 1; k < s; k++)\
    \ larges[0] -= larges[k];\n\tfor (int l = 1; l < s; l++) {\n\t\tlong long q =\
    \ roughs[l];\n\t\tlong long M = N / q;\n\t\tint e = smalls[half(M / q)] - pc;\n\
    \t\tif (e < l + 1) break;\n\t\tlong long t = 0;\n\t\tfor (int k = l + 1; k <=\
    \ e; k++)\n\t\t\tt += smalls[half(divide(M, roughs[k]))];\n\t\tlarges[0] += t\
    \ - (long long)(e - l) * (pc + l - 1);\n\t}\n\treturn larges[0] + 1;\n}\n"
  dependsOn:
  - math/iroot.hpp
  isVerificationFile: false
  path: math/counting_primes.hpp
  requiredBy: []
  timestamp: '2025-07-01 03:22:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yukicoder/1661.test.cpp
  - verify/yosupo/counting_primes.test.cpp
documentation_of: math/counting_primes.hpp
layout: document
title: "$n$ \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\u6570\u3048\u4E0A\u3052"
---

# $n$ 以下の素数の数え上げ

## 使い方

``counting_primes(ll n)`` : $n$ 以下の素数の数を返す。 $O(\frac{n^{3/4}}{\log n})$

[参考](https://rsk0315.hatenablog.com/entry/2021/05/18/015511)

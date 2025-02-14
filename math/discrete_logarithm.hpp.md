---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/iroot.hpp
    title: "floor K \u4E57\u6839"
  - icon: ':heavy_check_mark:'
    path: math/power.hpp
    title: math/power.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/discrete_logarithm.test.cpp
    title: verify/yosupo/discrete_logarithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/iroot.hpp\"\n\nunsigned long long iroot(unsigned long\
    \ long n, int k=2){\n\tconstexpr unsigned long long LIM = -1;\n\tif(n <= 1 ||\
    \ k == 1){\n\t\treturn n;\n\t}\n\tif(k >= 64){\n\t\treturn 1;\n\t}\n\tif(k ==\
    \ 2){\n\t\treturn sqrtl(n);\n\t}\n\n\tif(n == LIM)n--;\n\n\tauto safe_mul = [&](unsigned\
    \ long long &x, unsigned long long &y) -> void {\n\t\tif(x <= LIM / y){\n\t\t\t\
    x *= y;\n\t\t}else{\n\t\t\tx = LIM;\n\t\t}\n\t};\n\n\tauto power = [&](unsigned\
    \ long long a, int b) -> unsigned long long {\n\t\tunsigned long long ret = 1;\n\
    \t\twhile(b){\n\t\t\tif(b & 1)safe_mul(ret, a);\n\t\t\tsafe_mul(a, a);\n\t\t\t\
    b >>= 1;\n\t\t}\n\t\treturn ret;\n\t};\n\n\tunsigned long long ret = (k == 3 ?\
    \ cbrt(n)-1 : pow(n, nextafter(1.0/double(k), 0.0)));\n\twhile(power(ret+1, k)\
    \ <= n)ret++;\n\treturn ret;\n}\n#line 1 \"math/power.hpp\"\n\ntemplate<typename\
    \ mint>\nmint power(mint n, long long k) {\n\tmint ret = 1;\n\twhile(k > 0) {\n\
    \t\tif(k & 1)ret *= n;\n\t\tn = n*n;\n\t\tk >>= 1;\n\t}\n\treturn ret;\n}\n\n\
    long long power(long long n, long long k, long long p) {\n\tlong long ret = 1;\n\
    \twhile(k > 0){\n\t\tif(k & 1)ret = ret*n % p;\n\t\tn = n*n % p;\n\t\tk >>= 1;\n\
    \t}\n\treturn ret;\n}\n#line 3 \"math/discrete_logarithm.hpp\"\n\nll __modinv(ll\
    \ a, ll m){\n\tll b=m, u=1, v=0;\n\twhile(b){\n\t\tll t = a/b;\n\t\ta -= t*b;swap(a,\
    \ b);\n\t\tu -= t*v;swap(u, v);\n\t}\n\tu %= m;\n\tif(u < 0)u += m;\n\treturn\
    \ u;\n}\n\nll discrete_logarithm(ll x, ll y, ll m) {\n\tassert(x < m && y < m);\n\
    \tif(m == 1)return 0;\n\tif(y == 1)return 0;\n\tif(x == 0){\n\t\tif(y == 1)return\
    \ 0;\n\t\telse if(y == 0)return 1;\n\t\telse return -1;\n\t}\n\n\tif(gcd(x, m)\
    \ != 1){\n\t\tll d = gcd(x, m);\n\t\tif(y%d)return -1;\n\t\ty /= d;\n\t\tm /=\
    \ d;\n\t\tll ret = discrete_logarithm(x%m, (y*__modinv(x/d, m))%m, m);\n\t\tif(ret\
    \ == -1)return -1;\n\t\telse return ret+1;\n\t}\n\n\tll sq = iroot(m);\n\tif(sq\
    \ < 3)sq = 3;\n\tvector<ll> _b(sq);\n\tfor(int i = 0;i < sq;i++)_b[i] = (i ==\
    \ 0 ? 1 : (_b[i-1]*x)%m);\n\n\tmap<ll, ll> b;\n\tfor(int i = sq-1;i >= 0;i--)b[_b[i]]\
    \ = i;\n\n\tll inv = __modinv((_b.back()*x)%m, m);\n\n\tfor(int i = 0;i < sq;i++){\n\
    \t\tll num = (y*power(inv, i, m))%m;\n\t\tif(b.contains(num)){\n\t\t\treturn i*sq\
    \ + b[num];\n\t\t}\n\t}\n\treturn -1;\n};\n"
  code: "#include \"../math/iroot.hpp\"\n#include \"../math/power.hpp\"\n\nll __modinv(ll\
    \ a, ll m){\n\tll b=m, u=1, v=0;\n\twhile(b){\n\t\tll t = a/b;\n\t\ta -= t*b;swap(a,\
    \ b);\n\t\tu -= t*v;swap(u, v);\n\t}\n\tu %= m;\n\tif(u < 0)u += m;\n\treturn\
    \ u;\n}\n\nll discrete_logarithm(ll x, ll y, ll m) {\n\tassert(x < m && y < m);\n\
    \tif(m == 1)return 0;\n\tif(y == 1)return 0;\n\tif(x == 0){\n\t\tif(y == 1)return\
    \ 0;\n\t\telse if(y == 0)return 1;\n\t\telse return -1;\n\t}\n\n\tif(gcd(x, m)\
    \ != 1){\n\t\tll d = gcd(x, m);\n\t\tif(y%d)return -1;\n\t\ty /= d;\n\t\tm /=\
    \ d;\n\t\tll ret = discrete_logarithm(x%m, (y*__modinv(x/d, m))%m, m);\n\t\tif(ret\
    \ == -1)return -1;\n\t\telse return ret+1;\n\t}\n\n\tll sq = iroot(m);\n\tif(sq\
    \ < 3)sq = 3;\n\tvector<ll> _b(sq);\n\tfor(int i = 0;i < sq;i++)_b[i] = (i ==\
    \ 0 ? 1 : (_b[i-1]*x)%m);\n\n\tmap<ll, ll> b;\n\tfor(int i = sq-1;i >= 0;i--)b[_b[i]]\
    \ = i;\n\n\tll inv = __modinv((_b.back()*x)%m, m);\n\n\tfor(int i = 0;i < sq;i++){\n\
    \t\tll num = (y*power(inv, i, m))%m;\n\t\tif(b.contains(num)){\n\t\t\treturn i*sq\
    \ + b[num];\n\t\t}\n\t}\n\treturn -1;\n};\n"
  dependsOn:
  - math/iroot.hpp
  - math/power.hpp
  isVerificationFile: false
  path: math/discrete_logarithm.hpp
  requiredBy: []
  timestamp: '2025-02-04 02:16:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/discrete_logarithm.test.cpp
documentation_of: math/discrete_logarithm.hpp
layout: document
title: discrete_logarithm
---

# discrete_logarithm

## 使い方

``discrete_logarithm(ll x, ll y, ll m)`` : $x^k \pmod{m}$ となる最小の $k$ を返す。無い場合は $-1$ が返る。 $O(\sqrt{M})$

## 参考

[OI wiki](https://oi-wiki.org/math/number-theory/discrete-logarithm/#%E6%89%A9%E5%B1%95%E7%AF%87%E6%89%A9%E5%B1%95-bsgs)

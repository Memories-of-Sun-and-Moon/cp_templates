---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/discrete_logarithm.hpp
    title: discrete_logarithm
  - icon: ':heavy_check_mark:'
    path: math/iroot.hpp
    title: "floor K \u4E57\u6839"
  - icon: ':heavy_check_mark:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"verify/yosupo/discrete_logarithm.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\n\n#line 1 \"template/template.hpp\"\
    \n# include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nconst double pi = acos(-1);\ntemplate<class T>constexpr\
    \ T inf() { return ::std::numeric_limits<T>::max(); }\ntemplate<class T>constexpr\
    \ T hinf() { return inf<T>() / 2; }\ntemplate <typename T_char>T_char TL(T_char\
    \ cX) { return tolower(cX); }\ntemplate <typename T_char>T_char TU(T_char cX)\
    \ { return toupper(cX); }\ntemplate<class T> bool chmin(T& a,T b) { if(a > b){a\
    \ = b; return true;} return false; }\ntemplate<class T> bool chmax(T& a,T b) {\
    \ if(a < b){a = b; return true;} return false; }\nint popcnt(unsigned long long\
    \ n) { int cnt = 0; for (int i = 0; i < 64; i++)if ((n >> i) & 1)cnt++; return\
    \ cnt; }\nint d_sum(ll n) { int ret = 0; while (n > 0) { ret += n % 10; n /= 10;\
    \ }return ret; }\nint d_cnt(ll n) { int ret = 0; while (n > 0) { ret++; n /= 10;\
    \ }return ret; }\nll gcd(ll a, ll b) { if (b == 0)return a; return gcd(b, a%b);\
    \ };\nll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g*b; };\nll MOD(ll x,\
    \ ll m){return (x%m+m)%m; }\nll FLOOR(ll x, ll m) {ll r = (x%m+m)%m; return (x-r)/m;\
    \ }\ntemplate<class T> using dijk = priority_queue<T, vector<T>, greater<T>>;\n\
    # define all(qpqpq)           (qpqpq).begin(),(qpqpq).end()\n# define UNIQUE(wpwpw)\
    \        (wpwpw).erase(unique(all((wpwpw))),(wpwpw).end())\n# define LOWER(epepe)\
    \         transform(all((epepe)),(epepe).begin(),TL<char>)\n# define UPPER(rprpr)\
    \         transform(all((rprpr)),(rprpr).begin(),TU<char>)\n# define rep(i,upupu)\
    \         for(ll i = 0, i##_len = (upupu);(i) < (i##_len);(i)++)\n# define reps(i,opopo)\
    \        for(ll i = 1, i##_len = (opopo);(i) <= (i##_len);(i)++)\n# define len(x)\
    \                ((ll)(x).size())\n# define bit(n)               (1LL << (n))\n\
    # define pb push_back\n# define eb emplace_back\n# define exists(c, e)       \
    \  ((c).find(e) != (c).end())\n\nstruct INIT{\n\tINIT(){\n\t\tstd::ios::sync_with_stdio(false);\n\
    \t\tstd::cin.tie(0);\n\t\tcout << fixed << setprecision(20);\n\t}\n}INIT;\n\n\
    namespace mmrz {\n\tvoid solve();\n}\n\nint main(){\n\tmmrz::solve();\n}\n#line\
    \ 2 \"math/discrete_logarithm.hpp\"\n\n#line 2 \"math/iroot.hpp\"\n\n#line 5 \"\
    math/iroot.hpp\"\n\nunsigned long long iroot(unsigned long long n, int k=2){\n\
    \tconstexpr unsigned long long LIM = std::numeric_limits<unsigned long long>::max();\n\
    \tif(n <= 1 || k == 1){\n\t\treturn n;\n\t}\n\tif(k >= 64){\n\t\treturn 1;\n\t\
    }\n\tif(k == 2){\n\t\treturn sqrtl(n);\n\t}\n\n\tif(n == LIM)n--;\n\n\tauto safe_mul\
    \ = [&](unsigned long long &x, unsigned long long &y) -> void {\n\t\tif(x <= LIM\
    \ / y){\n\t\t\tx *= y;\n\t\t}else{\n\t\t\tx = LIM;\n\t\t}\n\t};\n\n\tauto power\
    \ = [&](unsigned long long a, int b) -> unsigned long long {\n\t\tunsigned long\
    \ long ret = 1;\n\t\twhile(b){\n\t\t\tif(b & 1)safe_mul(ret, a);\n\t\t\tsafe_mul(a,\
    \ a);\n\t\t\tb >>= 1;\n\t\t}\n\t\treturn ret;\n\t};\n\n\tunsigned long long ret\
    \ = (k == 3 ? cbrt(n)-1 : std::pow(n, std::nextafter(1.0/double(k), 0.0)));\n\t\
    while(power(ret+1, k) <= n)ret++;\n\treturn ret;\n}\n#line 2 \"math/power.hpp\"\
    \n\n#include <type_traits>\n\ntemplate<typename T>\nconcept NotPrimitiveInt =\n\
    \t!(std::is_same_v<T, int> ||\n\t\tstd::is_same_v<T, long> ||\n\t\tstd::is_same_v<T,\
    \ long long> ||\n\t\tstd::is_same_v<T, unsigned> ||\n\t\tstd::is_same_v<T, unsigned\
    \ long> ||\n\t\tstd::is_same_v<T, unsigned long long>);\n\ntemplate<NotPrimitiveInt\
    \ T>\nT power(T n, long long k) {\n\tT ret = 1;\n\twhile(k > 0) {\n\t\tif(k &\
    \ 1)ret *= n;\n\t\tn = n*n;\n\t\tk >>= 1;\n\t}\n\treturn ret;\n}\n\nlong long\
    \ power(long long n, long long k, long long p) {\n\tlong long ret = 1;\n\twhile(k\
    \ > 0){\n\t\tif(k & 1)ret = ret*n % p;\n\t\tn = n*n % p;\n\t\tk >>= 1;\n\t}\n\t\
    return ret;\n}\n#line 5 \"math/discrete_logarithm.hpp\"\n\n#line 12 \"math/discrete_logarithm.hpp\"\
    \n\nlong long __modinv(long long a, long long m){\n\tlong long b=m, u=1, v=0;\n\
    \twhile(b){\n\t\tlong long t = a/b;\n\t\ta -= t*b; std::swap(a, b);\n\t\tu -=\
    \ t*v; std::swap(u, v);\n\t}\n\tu %= m;\n\tif(u < 0)u += m;\n\treturn u;\n}\n\n\
    long long discrete_logarithm(long long x, long long y, long long m) {\n\tassert(x\
    \ < m && y < m);\n\tif(m == 1)return 0;\n\tif(y == 1)return 0;\n\tif(x == 0){\n\
    \t\tif(y == 1)return 0;\n\t\telse if(y == 0)return 1;\n\t\telse return -1;\n\t\
    }\n\n\tif(std::gcd(x, m) != 1){\n\t\tlong long d = std::gcd(x, m);\n\t\tif(y%d)return\
    \ -1;\n\t\ty /= d;\n\t\tm /= d;\n\t\tlong long ret = discrete_logarithm(x%m, (y*__modinv(x/d,\
    \ m))%m, m);\n\t\tif(ret == -1)return -1;\n\t\telse return ret+1;\n\t}\n\n\tlong\
    \ long sq = iroot(m);\n\tif(sq < 3)sq = 3;\n\tstd::vector<long long> _b(sq);\n\
    \tfor(int i = 0;i < sq;i++)_b[i] = (i == 0 ? 1 : (_b[i-1]*x)%m);\n\n\tstd::map<long\
    \ long, long long> b;\n\tfor(int i = sq-1;i >= 0;i--)b[_b[i]] = i;\n\n\tlong long\
    \ inv = __modinv((_b.back()*x)%m, m);\n\n\tfor(int i = 0;i < sq;i++){\n\t\tlong\
    \ long num = (y*power(inv, i, m))%m;\n\t\tif(b.contains(num)){\n\t\t\treturn i*sq\
    \ + b[num];\n\t\t}\n\t}\n\treturn -1;\n};\n#line 5 \"verify/yosupo/discrete_logarithm.test.cpp\"\
    \n\nusing namespace mmrz;\n\nvoid SOLVE(){\n\tint x, y, m;\n\tcin >> x >> y >>\
    \ m;\n\tcout << discrete_logarithm(x, y, m) << '\\n';\n}\n\nvoid mmrz::solve(){\n\
    \tint t = 1;\n\tcin >> t;\n\twhile(t--)SOLVE();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n\n#include \"./../../template/template.hpp\"\n#include \"./../../math/discrete_logarithm.hpp\"\
    \n\nusing namespace mmrz;\n\nvoid SOLVE(){\n\tint x, y, m;\n\tcin >> x >> y >>\
    \ m;\n\tcout << discrete_logarithm(x, y, m) << '\\n';\n}\n\nvoid mmrz::solve(){\n\
    \tint t = 1;\n\tcin >> t;\n\twhile(t--)SOLVE();\n}\n"
  dependsOn:
  - template/template.hpp
  - math/discrete_logarithm.hpp
  - math/iroot.hpp
  - math/power.hpp
  isVerificationFile: true
  path: verify/yosupo/discrete_logarithm.test.cpp
  requiredBy: []
  timestamp: '2025-07-01 03:22:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/discrete_logarithm.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/discrete_logarithm.test.cpp
- /verify/verify/yosupo/discrete_logarithm.test.cpp.html
title: verify/yosupo/discrete_logarithm.test.cpp
---

---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/iroot.hpp
    title: "floor K \u4E57\u6839"
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/kth_root_integer
    links:
    - https://judge.yosupo.jp/problem/kth_root_integer
  bundledCode: "#line 1 \"verify/yosupo/kth_root_integer.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/kth_root_integer\"\n\n#line 1 \"template/template.hpp\"\
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
    \ 2 \"math/iroot.hpp\"\n\n#line 5 \"math/iroot.hpp\"\n\nunsigned long long iroot(unsigned\
    \ long long n, int k=2){\n\tconstexpr unsigned long long LIM = std::numeric_limits<unsigned\
    \ long long>::max();\n\tif(n <= 1 || k == 1){\n\t\treturn n;\n\t}\n\tif(k >= 64){\n\
    \t\treturn 1;\n\t}\n\tif(k == 2){\n\t\treturn sqrtl(n);\n\t}\n\n\tif(n == LIM)n--;\n\
    \n\tauto safe_mul = [&](unsigned long long &x, unsigned long long &y) -> void\
    \ {\n\t\tif(x <= LIM / y){\n\t\t\tx *= y;\n\t\t}else{\n\t\t\tx = LIM;\n\t\t}\n\
    \t};\n\n\tauto power = [&](unsigned long long a, int b) -> unsigned long long\
    \ {\n\t\tunsigned long long ret = 1;\n\t\twhile(b){\n\t\t\tif(b & 1)safe_mul(ret,\
    \ a);\n\t\t\tsafe_mul(a, a);\n\t\t\tb >>= 1;\n\t\t}\n\t\treturn ret;\n\t};\n\n\
    \tunsigned long long ret = (k == 3 ? cbrt(n)-1 : std::pow(n, std::nextafter(1.0/double(k),\
    \ 0.0)));\n\twhile(power(ret+1, k) <= n)ret++;\n\treturn ret;\n}\n#line 5 \"verify/yosupo/kth_root_integer.test.cpp\"\
    \n\nusing namespace mmrz;\n\nvoid mmrz::solve(){\n\tint t;\n\tcin >> t;\n\twhile(t--){\n\
    \t\tull a, k;\n\t\tcin >> a >> k;\n\t\tcout << iroot(a, k) << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/kth_root_integer\"\n\n\
    #include \"./../../template/template.hpp\"\n#include \"./../../math/iroot.hpp\"\
    \n\nusing namespace mmrz;\n\nvoid mmrz::solve(){\n\tint t;\n\tcin >> t;\n\twhile(t--){\n\
    \t\tull a, k;\n\t\tcin >> a >> k;\n\t\tcout << iroot(a, k) << '\\n';\n\t}\n}\n"
  dependsOn:
  - template/template.hpp
  - math/iroot.hpp
  isVerificationFile: true
  path: verify/yosupo/kth_root_integer.test.cpp
  requiredBy: []
  timestamp: '2025-07-01 03:22:56+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/kth_root_integer.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/kth_root_integer.test.cpp
- /verify/verify/yosupo/kth_root_integer.test.cpp.html
title: verify/yosupo/kth_root_integer.test.cpp
---

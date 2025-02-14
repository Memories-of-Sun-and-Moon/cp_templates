---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: string/z_algorithm.hpp
    title: Z Algorithm
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"verify/yosupo/zalgorithm.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
    \n\n#line 1 \"template/template.hpp\"\n# include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing ull = unsigned long long;\nconst double pi\
    \ = acos(-1);\ntemplate<class T>constexpr T inf() { return ::std::numeric_limits<T>::max();\
    \ }\ntemplate<class T>constexpr T hinf() { return inf<T>() / 2; }\ntemplate <typename\
    \ T_char>T_char TL(T_char cX) { return tolower(cX); }\ntemplate <typename T_char>T_char\
    \ TU(T_char cX) { return toupper(cX); }\ntemplate<class T> bool chmin(T& a,T b)\
    \ { if(a > b){a = b; return true;} return false; }\ntemplate<class T> bool chmax(T&\
    \ a,T b) { if(a < b){a = b; return true;} return false; }\nint popcnt(unsigned\
    \ long long n) { int cnt = 0; for (int i = 0; i < 64; i++)if ((n >> i) & 1)cnt++;\
    \ return cnt; }\nint d_sum(ll n) { int ret = 0; while (n > 0) { ret += n % 10;\
    \ n /= 10; }return ret; }\nint d_cnt(ll n) { int ret = 0; while (n > 0) { ret++;\
    \ n /= 10; }return ret; }\nll gcd(ll a, ll b) { if (b == 0)return a; return gcd(b,\
    \ a%b); };\nll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g*b; };\nll MOD(ll\
    \ x, ll m){return (x%m+m)%m; }\nll FLOOR(ll x, ll m) {ll r = (x%m+m)%m; return\
    \ (x-r)/m; }\ntemplate<class T> using dijk = priority_queue<T, vector<T>, greater<T>>;\n\
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
    \ 1 \"string/z_algorithm.hpp\"\n\ntemplate<typename T>\nvector<int> z_algorithm(const\
    \ T &s){\n\tvector<int> z(s.size());\n\tz[0] = (int)z.size();\n\tint i = 1, j\
    \ = 0;\n\twhile(i < (int)z.size()){\n\t\twhile(i+j < (int)s.size() && s[j] ==\
    \ s[i+j])j++;\n\t\tz[i] = j;\n\t\t\n\t\tif(j == 0){\n\t\t\ti++;\n\t\t\tcontinue;\n\
    \t\t}\n\t\t\n\t\tint k = 1;\n\t\twhile(k < j && k + z[k] < j){\n\t\t\tz[i+k] =\
    \ z[k];\n\t\t\tk++;\n\t\t}\n\t\ti += k;\n\t\tj -= k;\n\t}\n\treturn z;\n}\n#line\
    \ 5 \"verify/yosupo/zalgorithm.cpp\"\n\nvoid mmrz::solve(){\n\tstring s;\n\tcin\
    \ >> s;\n\tvector<int> z = z_algorithm(s);\n\trep(i, len(s)){\n\t\tcout << z[i]\
    \ << \" \\n\"[i == len(s)-1];\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include\
    \ \"./../../template/template.hpp\"\n#include \"./../../string/z_algorithm.hpp\"\
    \n\nvoid mmrz::solve(){\n\tstring s;\n\tcin >> s;\n\tvector<int> z = z_algorithm(s);\n\
    \trep(i, len(s)){\n\t\tcout << z[i] << \" \\n\"[i == len(s)-1];\n\t}\n}\n"
  dependsOn:
  - template/template.hpp
  - string/z_algorithm.hpp
  isVerificationFile: false
  path: verify/yosupo/zalgorithm.cpp
  requiredBy: []
  timestamp: '2025-02-14 10:23:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: verify/yosupo/zalgorithm.cpp
layout: document
redirect_from:
- /library/verify/yosupo/zalgorithm.cpp
- /library/verify/yosupo/zalgorithm.cpp.html
title: verify/yosupo/zalgorithm.cpp
---

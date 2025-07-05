---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/z_algorithm.hpp
    title: Z Algorithm
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc150/tasks/abc150_f
  bundledCode: "#line 1 \"verify/atcoder/abc/150/f.___test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc150/tasks/abc150_f\"\n\n#line 1 \"template/template.hpp\"\
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
    \ 2 \"string/z_algorithm.hpp\"\n\n#line 4 \"string/z_algorithm.hpp\"\n\ntemplate<typename\
    \ T>\nstd::vector<int> z_algorithm(const T &s){\n\tstd::vector<int> z(s.size());\n\
    \tz[0] = (int)z.size();\n\tint i = 1, j = 0;\n\twhile(i < (int)z.size()){\n\t\t\
    while(i+j < (int)s.size() && s[j] == s[i+j])j++;\n\t\tz[i] = j;\n\t\t\n\t\tif(j\
    \ == 0){\n\t\t\ti++;\n\t\t\tcontinue;\n\t\t}\n\t\t\n\t\tint k = 1;\n\t\twhile(k\
    \ < j && k + z[k] < j){\n\t\t\tz[i+k] = z[k];\n\t\t\tk++;\n\t\t}\n\t\ti += k;\n\
    \t\tj -= k;\n\t}\n\treturn z;\n}\n#line 5 \"verify/atcoder/abc/150/f.___test.cpp\"\
    \n\nvoid mmrz::solve(){\n\tint n;\n\tcin >> n;\n\tvector<int> a(n), b(n);\n\t\
    for(auto &x : a)cin >> x;\n\tfor(auto &x : b)cin >> x;\n\t\n\tvector<int> c;\n\
    \trep(i, n)c.pb(b[i]^b[(i+1)%n]);\n\trep(i, n)c.pb(a[i]^a[(i+1)%n]);\n\trep(i,\
    \ n)c.pb(a[i]^a[(i+1)%n]);\n\n\tauto z = z_algorithm(c);\n\t\n\trep(i, n){\n\t\
    \tif(z[n+i] >= n){\n\t\t\tcout << i << \" \" << (a[i]^b[0]) << '\\n';\n\t\t}\n\
    \t}\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc150/tasks/abc150_f\"\n\n\
    #include \"./../../../../template/template.hpp\"\n#include \"./../../../../string/z_algorithm.hpp\"\
    \n\nvoid mmrz::solve(){\n\tint n;\n\tcin >> n;\n\tvector<int> a(n), b(n);\n\t\
    for(auto &x : a)cin >> x;\n\tfor(auto &x : b)cin >> x;\n\t\n\tvector<int> c;\n\
    \trep(i, n)c.pb(b[i]^b[(i+1)%n]);\n\trep(i, n)c.pb(a[i]^a[(i+1)%n]);\n\trep(i,\
    \ n)c.pb(a[i]^a[(i+1)%n]);\n\n\tauto z = z_algorithm(c);\n\t\n\trep(i, n){\n\t\
    \tif(z[n+i] >= n){\n\t\t\tcout << i << \" \" << (a[i]^b[0]) << '\\n';\n\t\t}\n\
    \t}\n}\n"
  dependsOn:
  - template/template.hpp
  - string/z_algorithm.hpp
  isVerificationFile: false
  path: verify/atcoder/abc/150/f.___test.cpp
  requiredBy: []
  timestamp: '2025-07-01 03:22:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: verify/atcoder/abc/150/f.___test.cpp
layout: document
redirect_from:
- /library/verify/atcoder/abc/150/f.___test.cpp
- /library/verify/atcoder/abc/150/f.___test.cpp.html
title: verify/atcoder/abc/150/f.___test.cpp
---

---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/hungarian.hpp
    title: "\u5272\u5F53\u554F\u984C\uFF08\u30CF\u30F3\u30AC\u30EA\u30A2\u30F3\u6CD5\
      \uFF09"
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
    PROBLEM: https://judge.yosupo.jp/problem/assignment
    links:
    - https://judge.yosupo.jp/problem/assignment
  bundledCode: "#line 1 \"verify/yosupo/assignment.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/assignment\"\n\n#line 1 \"template/template.hpp\"\
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
    \ 2 \"graph/hungarian.hpp\"\n\n#line 6 \"graph/hungarian.hpp\"\n\ntemplate<bool\
    \ is_min, typename T>\nstd::vector<int> hungarian(std::vector<std::vector<T>>\
    \ a) {\n\tT infty = std::numeric_limits<T>::max()/T(2);\n\tint n = (int)a.size();\n\
    \t\n\tif(not is_min){\n\t\tfor(int i = 0;i < n;i++){\n\t\t\tfor(int j = 0; j <\
    \ n;j++){\n\t\t\t\ta[i][j] = -a[i][j];\n\t\t\t}\n\t\t}\n\t}\n\n\tstd::vector<int>\
    \ p(n);\n\tstd::iota(p.begin(), p.end(), 0);\n\n\tstd::vector<T> h = {0};\n\t\
    h.reserve(n);\n\tfor(int i = 1;i < n;i++){\n\t\th.push_back(0);\n\t\tstd::vector<T>\
    \ d(i+1, infty);\n\t\tstd::vector<int> pre(i+1, -1);\n\t\tstd::vector<bool> used(i+1,\
    \ false);\n\n\t\td[i] = 0;\n\t\tpre[i] = i;\n\n\t\tfor(int _ = 0;_ <= i;_++){\n\
    \t\t\tT min_d = infty;\n\t\t\tint v = -1;\n\t\t\tfor(int j = 0;j <= i;j++){\n\t\
    \t\t\tif(not used[j] && min_d > d[j]-h[j]){\n\t\t\t\t\tmin_d = d[j]-h[j];\n\t\t\
    \t\t\tv = j;\n\t\t\t\t}\n\t\t\t}\n\t\t\t\t\n\t\t\tused[v] = true;\n\n\t\t\tfor(int\
    \ j = 0;j <= i;j++){\n\t\t\t\tif(not used[j] || j == i){\n\t\t\t\t\tT nd = d[v]\
    \ - a[v][p[v]] + a[j][p[v]];\n\t\t\t\t\tif(d[j] > nd){\n\t\t\t\t\t\td[j] = nd;\n\
    \t\t\t\t\t\tpre[j] = v;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\n\t\tint cur\
    \ = i;\n\t\twhile(pre[cur] != i){\n\t\t\tstd::swap(p[cur], p[pre[cur]]);\n\t\t\
    \tcur = pre[cur];\n\t\t}\n\t\th = d;\n\t}\n\treturn p;\n}\n#line 5 \"verify/yosupo/assignment.test.cpp\"\
    \n\nusing namespace mmrz;\n\nvoid mmrz::solve(){\n\tint n;\n\tcin >> n;\n\tvector\
    \ a(n, vector(n, 0LL));\n\trep(i, n)rep(j, n)cin >> a[i][j];\n\n\tvector<int>\
    \ h = hungarian<true, ll>(a);\n\tll x = 0;\n\trep(i, n)x += a[i][h[i]];\n\tcout\
    \ << x << '\\n';\n\trep(i, n)cout << h[i] << \" \\n\"[i == n-1];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\n\n#include\
    \ \"./../../template/template.hpp\"\n#include \"./../../graph/hungarian.hpp\"\n\
    \nusing namespace mmrz;\n\nvoid mmrz::solve(){\n\tint n;\n\tcin >> n;\n\tvector\
    \ a(n, vector(n, 0LL));\n\trep(i, n)rep(j, n)cin >> a[i][j];\n\n\tvector<int>\
    \ h = hungarian<true, ll>(a);\n\tll x = 0;\n\trep(i, n)x += a[i][h[i]];\n\tcout\
    \ << x << '\\n';\n\trep(i, n)cout << h[i] << \" \\n\"[i == n-1];\n}\n"
  dependsOn:
  - template/template.hpp
  - graph/hungarian.hpp
  isVerificationFile: true
  path: verify/yosupo/assignment.test.cpp
  requiredBy: []
  timestamp: '2025-07-01 03:22:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/assignment.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/assignment.test.cpp
- /verify/verify/yosupo/assignment.test.cpp.html
title: verify/yosupo/assignment.test.cpp
---

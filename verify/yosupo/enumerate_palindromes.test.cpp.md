---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/manachar.hpp
    title: manachar
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"verify/yosupo/enumerate_palindromes.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\n\n#line 1\
    \ \"template/template.hpp\"\n# include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing ull = unsigned long long;\nconst double pi = acos(-1);\n\
    template<class T>constexpr T inf() { return ::std::numeric_limits<T>::max(); }\n\
    template<class T>constexpr T hinf() { return inf<T>() / 2; }\ntemplate <typename\
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
    # define pb push_back\n# define exists(c, e)         ((c).find(e) != (c).end())\n\
    \nstruct INIT{\n\tINIT(){\n\t\tstd::ios::sync_with_stdio(false);\n\t\tstd::cin.tie(0);\n\
    \t\tcout << fixed << setprecision(20);\n\t}\n}INIT;\n\nnamespace mmrz {\n\tvoid\
    \ solve();\n}\n\nint main(){\n\tmmrz::solve();\n}\n#line 1 \"string/manachar.hpp\"\
    \n\nvector<int> manachar(string _s){\n    string t = \"\";\n    int n = (int)_s.size();\n\
    \    for(int i = 0;i < n;i++){\n        if(i)t += '#';\n        t += _s[i];\n\
    \    }\n    n = (int)t.size();\n    int i = 0, j = 0;\n    vector<int> r(n);\n\
    \    while(i < n){\n        while(i-j >= 0 && i+j < n && t[i-j] == t[i+j]) j++;\n\
    \        r[i] = j;\n        int k = 1;\n        while(i-k >= 0 && k+r[i-k] < j)\
    \ r[i+k] = r[i-k], k++;\n        i += k, j -= k;\n    }\n    for(int i = 0;i <\
    \ n;i++){\n        if(i%2)r[i] /= 2;\n        else r[i] = (r[i]+1)/2;\n    }\n\
    \    return r;\n}\n\n/*\nint i = 0, j = 0;\nwhile (i < S.size()) {\n  while (i-j\
    \ >= 0 && i+j < S.size() && S[i-j] == S[i+j]) ++j;\n  R[i] = j;\n  int k = 1;\n\
    \  while (i-k >= 0 && k+R[i-k] < j) R[i+k] = R[i-k], ++k;\n  i += k; j -= k;\n\
    }\n*/\n#line 5 \"verify/yosupo/enumerate_palindromes.test.cpp\"\n\nusing namespace\
    \ mmrz;\n\nvoid mmrz::solve(){\n    string s;\n    cin >> s;\n    vector<int>\
    \ r = manachar(s);\n    vector<int> ans(2*len(s)-1);\n    rep(i, 2*len(s)-1){\n\
    \        if(i%2){\n            ans[i] = r[i]*2;\n        }else{\n            ans[i]\
    \ = r[i]*2-1;\n        }\n    }\n    rep(i, 2*len(s)-1){\n        cout << ans[i]\
    \ << \" \\n\"[i == 2*len(s)-2];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n\n#include \"./../../template/template.hpp\"\n#include \"./../../string/manachar.hpp\"\
    \n\nusing namespace mmrz;\n\nvoid mmrz::solve(){\n    string s;\n    cin >> s;\n\
    \    vector<int> r = manachar(s);\n    vector<int> ans(2*len(s)-1);\n    rep(i,\
    \ 2*len(s)-1){\n        if(i%2){\n            ans[i] = r[i]*2;\n        }else{\n\
    \            ans[i] = r[i]*2-1;\n        }\n    }\n    rep(i, 2*len(s)-1){\n \
    \       cout << ans[i] << \" \\n\"[i == 2*len(s)-2];\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - string/manachar.hpp
  isVerificationFile: true
  path: verify/yosupo/enumerate_palindromes.test.cpp
  requiredBy: []
  timestamp: '2024-07-07 01:02:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/enumerate_palindromes.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/enumerate_palindromes.test.cpp
- /verify/verify/yosupo/enumerate_palindromes.test.cpp.html
title: verify/yosupo/enumerate_palindromes.test.cpp
---

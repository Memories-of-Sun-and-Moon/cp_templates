---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/formal_power_series.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\u30E9\u30EA"
  - icon: ':question:'
    path: math/modint.hpp
    title: modint
  - icon: ':heavy_check_mark:'
    path: math/power.hpp
    title: math/power.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"verify/yosupo/convolution_mod.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#line 1 \"template/template.hpp\"\
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
    \ 1 \"math/modint.hpp\"\n\ntemplate <std::uint_fast64_t Modulus> class modint\
    \ {\n\tusing u64 = std::uint_fast64_t;\npublic:\n\tu64 a;\n\tconstexpr modint(const\
    \ u64 x = 0) noexcept : a(x % Modulus) {}\n\tconstexpr u64 &value() noexcept {\
    \ return a; }\n\tconstexpr const u64 &value() const noexcept { return a; }\n\t\
    constexpr modint operator+(const modint rhs) const noexcept {\n\t\treturn modint(*this)\
    \ += rhs;\n\t}\n\tconstexpr modint operator-(const modint rhs) const noexcept\
    \ {\n\t\treturn modint(*this) -= rhs;\n\t}\n\tconstexpr modint operator*(const\
    \ modint rhs) const noexcept {\n\t\treturn modint(*this) *= rhs;\n\t}\n\tconstexpr\
    \ modint operator/(const modint rhs) const noexcept {\n\t\treturn modint(*this)\
    \ /= rhs;\n\t}\n\tconstexpr modint &operator+=(const modint rhs) noexcept {\n\t\
    \ta += rhs.a;\n\t\tif (a >= Modulus) {\n\t\t\ta -= Modulus;\n\t\t}\n\t\treturn\
    \ *this;\n\t}\n\tconstexpr modint &operator-=(const modint rhs) noexcept {\n\t\
    \tif (a < rhs.a) {\n\t\t\ta += Modulus;\n\t\t}\n\t\ta -= rhs.a;\n\t\treturn *this;\n\
    \t}\n\tconstexpr modint &operator*=(const modint rhs) noexcept {\n\t\ta = a *\
    \ rhs.a % Modulus;\n\t\treturn *this;\n\t}\n\tconstexpr modint &operator/=(modint\
    \ rhs) noexcept {\n\t\tu64 exp = Modulus - 2;\n\t\twhile (exp) {\n\t\t\tif (exp\
    \ % 2) {\n\t\t\t\t*this *= rhs;\n\t\t\t}\n\t\t\trhs *= rhs;\n\t\t\texp /= 2;\n\
    \t\t}\n\t\treturn *this;\n\t}\n\n\tfriend std::ostream& operator<<(std::ostream&\
    \ os, const modint& rhs) {\n\t\tos << rhs.a;\n\t\treturn os;\n\t}\n};\n#line 5\
    \ \"verify/yosupo/convolution_mod.test.cpp\"\nusing mint998 = modint<998244353>;\n\
    #line 1 \"math/formal_power_series.hpp\"\n\ntemplate<typename mint998>\nstruct\
    \ formal_power_series : vector<mint998> {\n\tusing vector<mint998>::vector;\n\t\
    using FPS = formal_power_series;\n\n\tFPS &operator+=(const FPS &r){\n\t\tif(r.size()\
    \ > this->size()){\n\t\t\tthis->resize(r.size());\n\t\t}\n\t\tfor(size_t i = 0;i\
    \ < r.size();i++){\n\t\t\t(*this)[i] += r[i];\n\t\t}\n\t\treturn *this;\n\t}\n\
    \n\tFPS &operator+=(const mint998 &v){\n\t\tif(this->empty())this->resize(1);\n\
    \t\t(*this)[0] += v;\n\t\treturn *this;\n\t}\n\n\tFPS &operator-=(const FPS &r){\n\
    \t\tif(r.size() > this->size()){\n\t\t\tthis->resize(r.size());\n\t\t}\n\t\tfor(size_t\
    \ i = 0;i < r.size();i++){\n\t\t\t(*this)[i] -= r[i];\n\t\t}\n\t\treturn *this;\n\
    \t}\n\n\tFPS &operator-=(const mint998 &v){\n\t\tif(this->empty())this->resize(1);\n\
    \t\t(*this)[0] -= v;\n\t\treturn *this;\n\t}\n\n\tFPS &operator*=(const FPS &g){\n\
    \t\tsize_t N = std::bit_ceil(this->size() + g.size() - 1);\n\n\t\tvector<mint998>\
    \ F(N, 0), G(N, 0);\n\n\t\tfor (size_t i = 0; i < this->size(); i++){\n\t\t\t\
    F[i] = (*this)[i];\n\t\t}\n\t\tfor (size_t i = 0; i < g.size(); i++){\n\t\t\t\
    G[i] = g[i];\n\t\t}\n\n\t\tDFT(F);\n\t\tDFT(G);\n\n\t\tvector<mint998> FG(N);\n\
    \t\tfor (size_t i = 0; i < N; i++){\n\t\t\tFG[i] = F[i] * G[i];\n\t\t}\n\t\tIDFT(FG);\n\
    \n\t\tFPS fg(this->size() + g.size() - 1);\n\t\tfor (size_t i = 0; i < fg.size();\
    \ i++){\n\t\t\tfg[i] = FG[i];\n\t\t}\n\t\treturn *this = fg;\n\t}\n\n\tFPS &operator*=(const\
    \ mint998 &v){\n\t\tfor(size_t k = 0;k < this->size();k++){\n\t\t\t(*this)[k]\
    \ *= v;\n\t\t\treturn *this;\n\t\t}\n\t}\n\n\tFPS operator+(const FPS &r) const\
    \ { return FPS(*this) += r; }\n\tFPS operator+(const mint998 &v) const { return\
    \ FPS(*this) += v; }\n\tFPS operator-(const FPS &r) const { return FPS(*this)\
    \ -= r; }\n\tFPS operator-(const mint998 &v) const { return FPS(*this) -= v; }\n\
    \tFPS operator*(const FPS &r) const { return FPS(*this) *= r; }\n\tFPS operator*(const\
    \ mint998 &v) const { return FPS(*this) *= v; }\n\tFPS operator-() const {\n\t\
    \tFPS ret(this->size());\n\t\tfor(size_t i = 0;i < this->size();i++){\n\t\t\t\
    ret[i] = -(*this)[i];\n\t\t}\n\t\treturn ret;\n\t}\n\n\tvoid shrink(){\n\t\twhile(this->size()\
    \ && this->back() == mint998(0))this->pop_back();\n\t}\n\n\tmint998 eval(mint998\
    \ x) const {\n\t\tmint998 r = 0, w = 1;\n\t\tfor(auto &v : *this){\n\t\t\tr +=\
    \ w*v;\n\t\t\tw *= x;\n\t\t}\n\t\treturn r;\n\t}\n};\n\n#line 1 \"math/power.hpp\"\
    \n\ntemplate<typename mint>\nmint power(mint n, long long k) {\n\tmint ret = 1;\n\
    \twhile(k > 0) {\n\t\tif(k & 1)ret *= n;\n\t\tn = n*n;\n\t\tk >>= 1;\n\t}\n\t\
    return ret;\n}\n\nlong long power(long long n, long long k, long long p) {\n\t\
    long long ret = 1;\n\twhile(k > 0){\n\t\tif(k & 1)ret = ret*n % p;\n\t\tn = n*n\
    \ % p;\n\t\tk >>= 1;\n\t}\n\treturn ret;\n}\n#line 103 \"math/formal_power_series.hpp\"\
    \n\nvector<vector<mint998>> zeta_table;\n\nmint998 zeta(size_t n, int i){\n\t\
    i += n;\n\ti %= n;\n\tif(zeta_table.empty()){\n\t\tzeta_table.resize(24);\n\t\t\
    mint998 r = power<mint998>(3,119);\n\t\tfor(int j = 23;j >= 0;j--){\n\t\t\tzeta_table[j].resize(1);\n\
    \t\t\tzeta_table[j][0] = r;\n\t\t\tr *= r;\n\t\t}\n\t}\n\tint N_2 = __builtin_ctz(n);\n\
    \tif(zeta_table[N_2].size() == 1){\n\t\tmint998 r = zeta_table[N_2][0];\n\t\t\
    zeta_table[N_2][0] = 1;\n\t\tzeta_table[N_2].resize(n);\n\t\tfor(size_t j = 1;j\
    \ < n;j++){\n\t\t\tzeta_table[N_2][j] = r * zeta_table[N_2][j-1];\n\t\t\tif(j\
    \ == n-1){\n\t\t\t\tassert((zeta_table[N_2][j] * r).a == 1);\n\t\t\t}\n\t\t}\n\
    \t}\n\treturn zeta_table[N_2][i];\n}\n\nvoid DFT(vector<mint998> &f, bool inverse\
    \ = false){\n\tsize_t N = f.size();\n\tif(N == 1)return;\n\n\tsize_t n = N >>\
    \ 1;\n\n\tvector<mint998> f0(n), f1(n);\n\tfor (size_t i = 0; i < n; i++){\n\t\
    \tf0[i] = f[2 * i];\n\t\tf1[i] = f[2 * i + 1];\n\t}\n\n\tDFT(f0, inverse);\n\t\
    DFT(f1, inverse);\n\n\tfor (size_t i = 0; i < n; i++){\n\t\tf[i] = f0[i] + (inverse\
    \ ? zeta(N, -i) : zeta(N, i)) * f1[i];\n\t\tf[n + i] = f0[i] + (inverse ? zeta(N,\
    \ -n - i) : zeta(N, n + i)) * f1[i];\n\t}\n}\n\nvoid IDFT(vector<mint998> &f){\n\
    \tDFT(f, true);\n\tsize_t N = f.size();\n\tfor (mint998 &a : f){\n\t\ta /= N;\n\
    \t}\n}\n#line 7 \"verify/yosupo/convolution_mod.test.cpp\"\nusing fps = formal_power_series<mint998>;\n\
    \nusing namespace mmrz;\n\nvoid mmrz::solve(){\n\tint n, m;\n\tcin >> n >> m;\n\
    \tfps a(n), b(m);\n\trep(i, n){\n\t\tint _a;\n\t\tcin >> _a;\n\t\ta[i] = _a;\n\
    \t}\n\trep(i, m){\n\t\tint _b;\n\t\tcin >> _b;\n\t\tb[i] = _b;\n\t}\n\tfps f{1};\n\
    \tf *= a;\n\tf *= b;\n\trep(i, n+m-1){\n\t\tcout << f[i] << \" \\n\"[i == n+m-1];\n\
    \t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include\
    \ \"./../../template/template.hpp\"\n#include \"./../../math/modint.hpp\"\nusing\
    \ mint998 = modint<998244353>;\n#include \"./../../math/formal_power_series.hpp\"\
    \nusing fps = formal_power_series<mint998>;\n\nusing namespace mmrz;\n\nvoid mmrz::solve(){\n\
    \tint n, m;\n\tcin >> n >> m;\n\tfps a(n), b(m);\n\trep(i, n){\n\t\tint _a;\n\t\
    \tcin >> _a;\n\t\ta[i] = _a;\n\t}\n\trep(i, m){\n\t\tint _b;\n\t\tcin >> _b;\n\
    \t\tb[i] = _b;\n\t}\n\tfps f{1};\n\tf *= a;\n\tf *= b;\n\trep(i, n+m-1){\n\t\t\
    cout << f[i] << \" \\n\"[i == n+m-1];\n\t}\n}\n"
  dependsOn:
  - template/template.hpp
  - math/modint.hpp
  - math/formal_power_series.hpp
  - math/power.hpp
  isVerificationFile: true
  path: verify/yosupo/convolution_mod.test.cpp
  requiredBy: []
  timestamp: '2025-02-14 10:23:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/convolution_mod.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/convolution_mod.test.cpp
- /verify/verify/yosupo/convolution_mod.test.cpp.html
title: verify/yosupo/convolution_mod.test.cpp
---

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/cgl/1_A.test.cpp
    title: verify/aoj/cgl/1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/cgl/1_B.test.cpp
    title: verify/aoj/cgl/1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/cgl/1_C.test.cpp
    title: verify/aoj/cgl/1_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/cgl/2_A.test.cpp
    title: verify/aoj/cgl/2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/cgl/2_B.test.cpp
    title: verify/aoj/cgl/2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/cgl/2_C.test.cpp
    title: verify/aoj/cgl/2_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/cgl/2_D.test.cpp
    title: verify/aoj/cgl/2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/cgl/3_A.test.cpp
    title: verify/aoj/cgl/3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/cgl/3_B.test.cpp
    title: verify/aoj/cgl/3_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/cgl/3_C.test.cpp
    title: verify/aoj/cgl/3_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/cgl/4_A.test.cpp
    title: verify/aoj/cgl/4_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/cgl/4_B.test.cpp
    title: verify/aoj/cgl/4_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/cgl/4_C.test.cpp
    title: verify/aoj/cgl/4_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/cgl/5_A.test.cpp
    title: verify/aoj/cgl/5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/3154.test.cpp
    title: verify/yukicoder/3154.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/util.hpp\"\n\nusing DOUBLE = long double;\n\nconstexpr\
    \ DOUBLE EPS = 1e-9;\n\nstruct point {\n\tDOUBLE x, y;\n\n\tpoint(DOUBLE _x =\
    \ 0, DOUBLE _y = 0): x(_x), y(_y) {}\n\n\tpoint operator+(point p){ return point(x+p.x,\
    \ y+p.y); };\n\tpoint operator-(point p){ return point(x-p.x, y-p.y); };\n\tpoint\
    \ operator*(DOUBLE a) {return point(x*a, y*a); };\n\tpoint operator/(DOUBLE a)\
    \ {return point(x/a, y/a); };\n\n\tDOUBLE abs() {return sqrtl(norm()); };\n\t\
    DOUBLE norm() {return x*x + y*y; };\n\n\tbool operator<(const point &p) const\
    \ {\n\t\treturn (not (fabs(x-p.x) < EPS)? x<p.x : y<p.y);\n\t}\n\n\tbool operator==(const\
    \ point &p) const {\n\t\treturn fabs(x-p.x) < EPS && fabs(y-p.y) < EPS;\n\t}\n\
    };\nistream& operator >> (istream &is, point &p){return is >> p.x >> p.y;}\nostream&\
    \ operator << (ostream &os, const point &p){return os << p.x << \" \" << p.y;}\n\
    \nusing polygon = vector<point>;\n\nstruct segment {point p1, p2; };\ntypedef\
    \ segment line;\nistream& operator >> (istream &is, segment &s){return is >> s.p1\
    \ >> s.p2;}\nostream& operator << (ostream &os, const segment &s){return os <<\
    \ s.p1 << \" \" << s.p2;}\n\n\nstruct circle {\n\tpoint c;\n\tDOUBLE r;\n\tcircle(point\
    \ _c = point(), DOUBLE _r = 0.0): c(_c), r(_r) {}\n};\n\nDOUBLE dot(point a, point\
    \ b) {\n\treturn a.x*b.x + a.y*b.y;\n}\n\nDOUBLE cross(point a, point b) {\n\t\
    return a.x*b.y - a.y*b.x;\n}\n\nconstexpr int COUNTER_CLOCKWISE = 1;\nconstexpr\
    \ int CLOCKWISE = -1;\nconstexpr int ONLINE_BACK = 2;\nconstexpr int ONLINE_FRONT\
    \ = -2;\nconstexpr int ON_SEGMENT = 0;\n\nint ccw(point p0, point p1, point p2)\
    \ {\n\tpoint a = p1 - p0;\n\tpoint b = p2 - p0;\n\t\n\tif(p0 == p1)return ON_SEGMENT;\n\
    \tif(p0 == p2)return ON_SEGMENT;\n\tif(p1 == p2)return ON_SEGMENT;\n\t\n\tif(cross(a,\
    \ b) > EPS)return COUNTER_CLOCKWISE;\n\tif(cross(a, b) < -EPS)return CLOCKWISE;\n\
    \tif(dot(a, b) < -EPS)return ONLINE_BACK;\n\tif(a.norm() < b.norm())return ONLINE_FRONT;\n\
    \t\n\treturn ON_SEGMENT;\n}\n\nbool intersect(point p1, point p2, point p3, point\
    \ p4) {\n\treturn (ccw(p1, p2, p3)*ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1)*ccw(p3,\
    \ p4, p2) <= 0);\n}\n\nbool intersect(segment s1, segment s2) {\n\treturn intersect(s1.p1,\
    \ s1.p2, s2.p1, s2.p2);\n}\n\npoint project(line &s, point &p) {\n\tpoint base\
    \ = s.p2 - s.p1;\n\tDOUBLE r = dot(p-s.p1, base) / base.norm();\n\treturn s.p1\
    \ + base*r;\n}\n\npoint reflect(line s, point p) {\n\treturn p + (project(s, p)\
    \ - p) * 2.0;\n}\n\nDOUBLE get_distance(point &a, point &b){\n\treturn (a-b).abs();\n\
    }\n\n// line, point\nDOUBLE get_distance_lp(line &l, point &p){\n\treturn abs(cross(l.p2-l.p1,\
    \ p-l.p1) / (l.p2-l.p1).abs());\n}\n// segment, point\nDOUBLE get_distance_sp(segment\
    \ &s, point &p){\n\tif(dot(s.p2-s.p1, p-s.p1) < 0.0)return (p-s.p1).abs();\n\t\
    if(dot(s.p1-s.p2, p-s.p2) < 0.0)return (p-s.p2).abs();\n\treturn get_distance_lp(s,\
    \ p);\n}\n\nDOUBLE get_distance(segment &s1, segment &s2){\n\tif(intersect(s1,\
    \ s2))return 0.0;\n\treturn min({get_distance_sp(s1, s2.p1), get_distance_sp(s1,\
    \ s2.p2), get_distance_sp(s2, s1.p1), get_distance_sp(s2, s1.p2)});\n}\n\nvector<point>\
    \ get_crosspoint(line &l, line &m){\n\tvector<point> res;\n\tDOUBLE d = cross(m.p2-m.p1,\
    \ l.p2-l.p1);\n\tif(abs(d) < EPS)return vector<point>();\n\tDOUBLE t = cross(m.p2-m.p1,\
    \ m.p2-l.p1) / d;\n\tpoint r = l.p1 + (l.p2-l.p1) * t;\n\tres.push_back(r);\n\t\
    return res;\n}\n\npair<point, point> get_crosspoints(circle &c, line &l){\n\t\
    point pr = project(l, c.c);\n\tpoint e = (l.p2-l.p1)/(l.p2-l.p1).abs();\n\tDOUBLE\
    \ base = sqrt(max<DOUBLE>(0.0, c.r*c.r - (pr-c.c).norm()));\n\treturn {pr+e*base,\
    \ pr-e*base};\n}\n\npoint polar (DOUBLE a, DOUBLE r){\n\treturn point(cos(r)*a,\
    \ sin(r)*a);\n}\n\npair<point, point> get_crosspoints(circle &c1, circle &c2){\n\
    \tDOUBLE d = (c1.c-c2.c).abs();\n\tDOUBLE a = acos((c1.r*c1.r + d*d - c2.r*c2.r)\
    \ / (2*c1.r*d));\n\tDOUBLE t = atan2((c2.c-c1.c).y, (c2.c-c1.c).x);\n\treturn\
    \ {c1.c+polar(c1.r, t+a), c1.c+polar(c1.r, t-a)};\n}\n\nDOUBLE deg_to_rad(const\
    \ DOUBLE &deg) {return deg*pi / 180.0; };\n\n//a > 0\u306A\u3089\u3070+1, a ==\
    \ 0\u306A\u3089\u30700, a < 0\u306A\u3089\u3070-1\u3000\u3092\u8FD4\u3059\u3002\
    \u3000\u57FA\u672C\u7684\u306BEPS\u8FBC\u307F\u306E\u8A55\u4FA1\u306F\u3053\u308C\
    \u3067\u884C\u3046\u3002\n//\u4E0D\u7B49\u5F0F\u306F\u3001\u52A0\u6E1B\u7B97\u306B\
    \u76F4\u3057\u3066\u3053\u308C\u306B\u9069\u7528\u3059\u308B\u3002\nint sgn(const\
    \ double a) {\n    return (a < -EPS ? -1 : (a > EPS ? +1 : 0));\n}\n\n//\u76F4\
    \u4EA4\u5224\u5B9A\nbool is_orthogonal(point a, point b){\n    return sgn(dot(a,\
    \ b)) == 0;\n}\nbool is_orthogonal(segment s1, segment s2){\n    return sgn(dot(s1.p2\
    \ - s1.p1, s2.p2 - s2.p1)) == 0;\n}\n\n//\u4E26\u884C\u5224\u5B9A\nbool is_parallel(point\
    \ a, point b){\n    return sgn(cross(a, b)) == 0;\n}\nbool is_parallel(segment\
    \ s1, segment s2){\n    return sgn(cross(s1.p2 - s1.p1, s2.p2 - s2.p1)) == 0;\n\
    }\n\nDOUBLE area(polygon &p){\n\tDOUBLE s = 0.0;\n\tsize_t n = p.size();\n\tfor(size_t\
    \ i = 0;i < n;i++){\n\t\tint nxt = (i+1)%n;\n\t\ts += p[i].x*p[nxt].y - p[nxt].x*p[i].y;\n\
    \t}\n\ts = abs(s);\n\ts /= 2.0;\n\treturn s;\n}\n\nbool __is_convex_allow_colinear(polygon\
    \ &p){\n\tint n = ssize(p);\n\tassert(n >= 3);\n\tint base_ccw;\n\t{\n\t\tint\
    \ idx = 0;\n\t\tint r;\n\t\twhile(true){\n\t\t\tr = ccw(p[idx], p[(idx+1)%n],\
    \ p[(idx+2)%n]);\n\t\t\tif(r == CLOCKWISE || r == COUNTER_CLOCKWISE){\n\t\t\t\t\
    base_ccw = r;\n\t\t\t\tbreak;\n\t\t\t}\n\t\t\tidx++;\n\t\t}\n\t}\n\tfor(int i\
    \ = 0;i < n;i++){\n\t\tint r = ccw(p[i], p[(i+1)%n], p[(i+2)%n]);\n\t\tif(r !=\
    \ CLOCKWISE && r != COUNTER_CLOCKWISE)continue;\n\t\tif(r != base_ccw)return false;\n\
    \t}\n\treturn true;\n}\n\nbool is_convex(polygon &p, bool allow_colinear=false){\n\
    \tif(allow_colinear)return __is_convex_allow_colinear(p);\n\tint n = ssize(p);\n\
    \tassert(n >= 3);\n\tint base_ccw = ccw(p[0], p[1], p[2]);\n\tfor(int i = 0;i\
    \ < n;i++){\n\t\tint r = ccw(p[i], p[(i+1)%n], p[(i+2)%n]);\n\t\tif(r != base_ccw)return\
    \ false;\n\t}\n\treturn true;\n}\n\n/*\nIN 2\nON 1\nOUT 0\n*/\nint contains(polygon\
    \ g, point p){\n\tint n = (int)g.size();\n\tbool x = false;\n\tfor(int i = 0;i\
    \ < n;i++){\n\t\tpoint a = g[i]-p, b = g[(i+1)%n]-p;\n\t\tif(abs(cross(a, b))\
    \ < EPS && dot(a, b) < EPS)return 1;\n\t\tif(a.y > b.y)swap(a, b);\n\t\tif(a.y\
    \ < EPS && EPS < b.y && cross(a, b) > EPS)x = !x;\n\t}\n\treturn (x ? 2 : 0);\n\
    }\n\npolygon convex_hull(polygon &ps, bool allow_colinear=false){\n\tint n = (int)ps.size();\n\
    \tsort(ps.begin(), ps.end());\n\tint k = 0;\n\tpolygon qs(n*2);\n\tfor(int i =\
    \ 0;i < n;i++){\n\t\tif(allow_colinear)while(k > 1 && cross(qs[k-1]-qs[k-2], ps[i]-qs[k-1])\
    \ <  0.0)k--;\n\t\telse              while(k > 1 && cross(qs[k-1]-qs[k-2], ps[i]-qs[k-1])\
    \ <= 0.0)k--;\n\t\tqs[k++] = ps[i];\n\t}\n\tfor(int i = n-2, t=k;i >= 0;i--){\n\
    \t\tif(allow_colinear)while(k > t && cross(qs[k-1]-qs[k-2], ps[i]-qs[k-1]) < \
    \ 0.0)k--;\n\t\telse              while(k > t && cross(qs[k-1]-qs[k-2], ps[i]-qs[k-1])\
    \ <= 0.0)k--;\n\t\tqs[k++] = ps[i];\n\t}\n\tqs.resize(k-1);\n\treturn qs;\n}\n\
    \nDOUBLE diameter(polygon &ps) {\n\tpolygon convex = convex_hull(ps, false);\n\
    \tint n = (int)convex.size();\n\n\tif(n == 2)return get_distance(convex[0], convex[1]);\n\
    \n\tint i = 0, j = 0;\n\tfor(int k = 0;k < n;k++){\n\t\tif(convex[k] < convex[i])i\
    \ = k;\n\t\tif(convex[j] < convex[k])j = k;\n\t}\n\tDOUBLE res = 0;\n\tint si\
    \ = i, sj = j;\n\twhile(i != sj || j != si){\n\t\tres = max(res, get_distance(convex[i],\
    \ convex[j]));\n\t\tif(cross(convex[(i+1)%n]-convex[i], convex[(j+1)%n]-convex[j])\
    \ < 0.0){\n\t\t\ti = (i+1) % n;\n\t\t}else{\n\t\t\tj = (j+1) % n;\n\t\t}\n\t}\n\
    \treturn res;\n}\n\npolygon convex_cut(polygon &p, line s){\n\tpolygon ret;\n\t\
    int n = (int)p.size();\n\tfor(int i = 0;i < n;i++){\n\t\tconst point &now = p[i];\n\
    \t\tconst point &nxt = p[(i+1)%n];\n\t\tauto cf = cross(s.p1 - now, s.p2 - now);\n\
    \t\tauto cs = cross(s.p1 - nxt, s.p2 - nxt);\n\t\tif(sgn(cf) >= 0){\n\t\t\tret.emplace_back(now);\n\
    \t\t}\n\t\tif(sgn(cf) * sgn(cs) < 0){\n\t\t\tline l = line{now, nxt};\n\t\t\t\
    ret.emplace_back(get_crosspoint(l, s)[0]);\n\t\t}\n\t}\n\treturn ret;\n}\n\nbool\
    \ __compare_y(const point &a, const point &b){\n\treturn a.y < b.y;\n}\n\nDOUBLE\
    \ closest_pair(vector<point> &p, int l=0, int r=-1) {\n\tif(r == -1)r = (int)p.size();\n\
    \tif(r-l <= 1)return 1e100;\n\tint mid = (l+r)/2;\n\tDOUBLE x = p[mid].x;\n\t\
    DOUBLE d = min(closest_pair(p, l, mid), closest_pair(p, mid, r));\n\tauto iti\
    \ = p.begin(), itl =iti+l, itm = iti+mid, itr = iti+r;\n\tinplace_merge(itl, itm,\
    \ itr, __compare_y);\n\n\tvector<point> near_line;\n\tfor(int i = l;i < r;i++){\n\
    \t\tif(abs(p[i].x-x) >= d)continue;\n\n\t\tint sz = (int)near_line.size();\n\t\
    \tfor(int j = sz-1;j >= 0;j--){\n\t\t\tpoint delta = p[i]-near_line[j];\n\t\t\t\
    if(delta.y >= d)break;\n\t\t\td = min(d, sqrtl(delta.norm()));\n\t\t}\n\t\tnear_line.emplace_back(p[i]);\n\
    \t}\n\treturn d;\n}\n"
  code: "\nusing DOUBLE = long double;\n\nconstexpr DOUBLE EPS = 1e-9;\n\nstruct point\
    \ {\n\tDOUBLE x, y;\n\n\tpoint(DOUBLE _x = 0, DOUBLE _y = 0): x(_x), y(_y) {}\n\
    \n\tpoint operator+(point p){ return point(x+p.x, y+p.y); };\n\tpoint operator-(point\
    \ p){ return point(x-p.x, y-p.y); };\n\tpoint operator*(DOUBLE a) {return point(x*a,\
    \ y*a); };\n\tpoint operator/(DOUBLE a) {return point(x/a, y/a); };\n\n\tDOUBLE\
    \ abs() {return sqrtl(norm()); };\n\tDOUBLE norm() {return x*x + y*y; };\n\n\t\
    bool operator<(const point &p) const {\n\t\treturn (not (fabs(x-p.x) < EPS)? x<p.x\
    \ : y<p.y);\n\t}\n\n\tbool operator==(const point &p) const {\n\t\treturn fabs(x-p.x)\
    \ < EPS && fabs(y-p.y) < EPS;\n\t}\n};\nistream& operator >> (istream &is, point\
    \ &p){return is >> p.x >> p.y;}\nostream& operator << (ostream &os, const point\
    \ &p){return os << p.x << \" \" << p.y;}\n\nusing polygon = vector<point>;\n\n\
    struct segment {point p1, p2; };\ntypedef segment line;\nistream& operator >>\
    \ (istream &is, segment &s){return is >> s.p1 >> s.p2;}\nostream& operator <<\
    \ (ostream &os, const segment &s){return os << s.p1 << \" \" << s.p2;}\n\n\nstruct\
    \ circle {\n\tpoint c;\n\tDOUBLE r;\n\tcircle(point _c = point(), DOUBLE _r =\
    \ 0.0): c(_c), r(_r) {}\n};\n\nDOUBLE dot(point a, point b) {\n\treturn a.x*b.x\
    \ + a.y*b.y;\n}\n\nDOUBLE cross(point a, point b) {\n\treturn a.x*b.y - a.y*b.x;\n\
    }\n\nconstexpr int COUNTER_CLOCKWISE = 1;\nconstexpr int CLOCKWISE = -1;\nconstexpr\
    \ int ONLINE_BACK = 2;\nconstexpr int ONLINE_FRONT = -2;\nconstexpr int ON_SEGMENT\
    \ = 0;\n\nint ccw(point p0, point p1, point p2) {\n\tpoint a = p1 - p0;\n\tpoint\
    \ b = p2 - p0;\n\t\n\tif(p0 == p1)return ON_SEGMENT;\n\tif(p0 == p2)return ON_SEGMENT;\n\
    \tif(p1 == p2)return ON_SEGMENT;\n\t\n\tif(cross(a, b) > EPS)return COUNTER_CLOCKWISE;\n\
    \tif(cross(a, b) < -EPS)return CLOCKWISE;\n\tif(dot(a, b) < -EPS)return ONLINE_BACK;\n\
    \tif(a.norm() < b.norm())return ONLINE_FRONT;\n\t\n\treturn ON_SEGMENT;\n}\n\n\
    bool intersect(point p1, point p2, point p3, point p4) {\n\treturn (ccw(p1, p2,\
    \ p3)*ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1)*ccw(p3, p4, p2) <= 0);\n}\n\nbool\
    \ intersect(segment s1, segment s2) {\n\treturn intersect(s1.p1, s1.p2, s2.p1,\
    \ s2.p2);\n}\n\npoint project(line &s, point &p) {\n\tpoint base = s.p2 - s.p1;\n\
    \tDOUBLE r = dot(p-s.p1, base) / base.norm();\n\treturn s.p1 + base*r;\n}\n\n\
    point reflect(line s, point p) {\n\treturn p + (project(s, p) - p) * 2.0;\n}\n\
    \nDOUBLE get_distance(point &a, point &b){\n\treturn (a-b).abs();\n}\n\n// line,\
    \ point\nDOUBLE get_distance_lp(line &l, point &p){\n\treturn abs(cross(l.p2-l.p1,\
    \ p-l.p1) / (l.p2-l.p1).abs());\n}\n// segment, point\nDOUBLE get_distance_sp(segment\
    \ &s, point &p){\n\tif(dot(s.p2-s.p1, p-s.p1) < 0.0)return (p-s.p1).abs();\n\t\
    if(dot(s.p1-s.p2, p-s.p2) < 0.0)return (p-s.p2).abs();\n\treturn get_distance_lp(s,\
    \ p);\n}\n\nDOUBLE get_distance(segment &s1, segment &s2){\n\tif(intersect(s1,\
    \ s2))return 0.0;\n\treturn min({get_distance_sp(s1, s2.p1), get_distance_sp(s1,\
    \ s2.p2), get_distance_sp(s2, s1.p1), get_distance_sp(s2, s1.p2)});\n}\n\nvector<point>\
    \ get_crosspoint(line &l, line &m){\n\tvector<point> res;\n\tDOUBLE d = cross(m.p2-m.p1,\
    \ l.p2-l.p1);\n\tif(abs(d) < EPS)return vector<point>();\n\tDOUBLE t = cross(m.p2-m.p1,\
    \ m.p2-l.p1) / d;\n\tpoint r = l.p1 + (l.p2-l.p1) * t;\n\tres.push_back(r);\n\t\
    return res;\n}\n\npair<point, point> get_crosspoints(circle &c, line &l){\n\t\
    point pr = project(l, c.c);\n\tpoint e = (l.p2-l.p1)/(l.p2-l.p1).abs();\n\tDOUBLE\
    \ base = sqrt(max<DOUBLE>(0.0, c.r*c.r - (pr-c.c).norm()));\n\treturn {pr+e*base,\
    \ pr-e*base};\n}\n\npoint polar (DOUBLE a, DOUBLE r){\n\treturn point(cos(r)*a,\
    \ sin(r)*a);\n}\n\npair<point, point> get_crosspoints(circle &c1, circle &c2){\n\
    \tDOUBLE d = (c1.c-c2.c).abs();\n\tDOUBLE a = acos((c1.r*c1.r + d*d - c2.r*c2.r)\
    \ / (2*c1.r*d));\n\tDOUBLE t = atan2((c2.c-c1.c).y, (c2.c-c1.c).x);\n\treturn\
    \ {c1.c+polar(c1.r, t+a), c1.c+polar(c1.r, t-a)};\n}\n\nDOUBLE deg_to_rad(const\
    \ DOUBLE &deg) {return deg*pi / 180.0; };\n\n//a > 0\u306A\u3089\u3070+1, a ==\
    \ 0\u306A\u3089\u30700, a < 0\u306A\u3089\u3070-1\u3000\u3092\u8FD4\u3059\u3002\
    \u3000\u57FA\u672C\u7684\u306BEPS\u8FBC\u307F\u306E\u8A55\u4FA1\u306F\u3053\u308C\
    \u3067\u884C\u3046\u3002\n//\u4E0D\u7B49\u5F0F\u306F\u3001\u52A0\u6E1B\u7B97\u306B\
    \u76F4\u3057\u3066\u3053\u308C\u306B\u9069\u7528\u3059\u308B\u3002\nint sgn(const\
    \ double a) {\n    return (a < -EPS ? -1 : (a > EPS ? +1 : 0));\n}\n\n//\u76F4\
    \u4EA4\u5224\u5B9A\nbool is_orthogonal(point a, point b){\n    return sgn(dot(a,\
    \ b)) == 0;\n}\nbool is_orthogonal(segment s1, segment s2){\n    return sgn(dot(s1.p2\
    \ - s1.p1, s2.p2 - s2.p1)) == 0;\n}\n\n//\u4E26\u884C\u5224\u5B9A\nbool is_parallel(point\
    \ a, point b){\n    return sgn(cross(a, b)) == 0;\n}\nbool is_parallel(segment\
    \ s1, segment s2){\n    return sgn(cross(s1.p2 - s1.p1, s2.p2 - s2.p1)) == 0;\n\
    }\n\nDOUBLE area(polygon &p){\n\tDOUBLE s = 0.0;\n\tsize_t n = p.size();\n\tfor(size_t\
    \ i = 0;i < n;i++){\n\t\tint nxt = (i+1)%n;\n\t\ts += p[i].x*p[nxt].y - p[nxt].x*p[i].y;\n\
    \t}\n\ts = abs(s);\n\ts /= 2.0;\n\treturn s;\n}\n\nbool __is_convex_allow_colinear(polygon\
    \ &p){\n\tint n = ssize(p);\n\tassert(n >= 3);\n\tint base_ccw;\n\t{\n\t\tint\
    \ idx = 0;\n\t\tint r;\n\t\twhile(true){\n\t\t\tr = ccw(p[idx], p[(idx+1)%n],\
    \ p[(idx+2)%n]);\n\t\t\tif(r == CLOCKWISE || r == COUNTER_CLOCKWISE){\n\t\t\t\t\
    base_ccw = r;\n\t\t\t\tbreak;\n\t\t\t}\n\t\t\tidx++;\n\t\t}\n\t}\n\tfor(int i\
    \ = 0;i < n;i++){\n\t\tint r = ccw(p[i], p[(i+1)%n], p[(i+2)%n]);\n\t\tif(r !=\
    \ CLOCKWISE && r != COUNTER_CLOCKWISE)continue;\n\t\tif(r != base_ccw)return false;\n\
    \t}\n\treturn true;\n}\n\nbool is_convex(polygon &p, bool allow_colinear=false){\n\
    \tif(allow_colinear)return __is_convex_allow_colinear(p);\n\tint n = ssize(p);\n\
    \tassert(n >= 3);\n\tint base_ccw = ccw(p[0], p[1], p[2]);\n\tfor(int i = 0;i\
    \ < n;i++){\n\t\tint r = ccw(p[i], p[(i+1)%n], p[(i+2)%n]);\n\t\tif(r != base_ccw)return\
    \ false;\n\t}\n\treturn true;\n}\n\n/*\nIN 2\nON 1\nOUT 0\n*/\nint contains(polygon\
    \ g, point p){\n\tint n = (int)g.size();\n\tbool x = false;\n\tfor(int i = 0;i\
    \ < n;i++){\n\t\tpoint a = g[i]-p, b = g[(i+1)%n]-p;\n\t\tif(abs(cross(a, b))\
    \ < EPS && dot(a, b) < EPS)return 1;\n\t\tif(a.y > b.y)swap(a, b);\n\t\tif(a.y\
    \ < EPS && EPS < b.y && cross(a, b) > EPS)x = !x;\n\t}\n\treturn (x ? 2 : 0);\n\
    }\n\npolygon convex_hull(polygon &ps, bool allow_colinear=false){\n\tint n = (int)ps.size();\n\
    \tsort(ps.begin(), ps.end());\n\tint k = 0;\n\tpolygon qs(n*2);\n\tfor(int i =\
    \ 0;i < n;i++){\n\t\tif(allow_colinear)while(k > 1 && cross(qs[k-1]-qs[k-2], ps[i]-qs[k-1])\
    \ <  0.0)k--;\n\t\telse              while(k > 1 && cross(qs[k-1]-qs[k-2], ps[i]-qs[k-1])\
    \ <= 0.0)k--;\n\t\tqs[k++] = ps[i];\n\t}\n\tfor(int i = n-2, t=k;i >= 0;i--){\n\
    \t\tif(allow_colinear)while(k > t && cross(qs[k-1]-qs[k-2], ps[i]-qs[k-1]) < \
    \ 0.0)k--;\n\t\telse              while(k > t && cross(qs[k-1]-qs[k-2], ps[i]-qs[k-1])\
    \ <= 0.0)k--;\n\t\tqs[k++] = ps[i];\n\t}\n\tqs.resize(k-1);\n\treturn qs;\n}\n\
    \nDOUBLE diameter(polygon &ps) {\n\tpolygon convex = convex_hull(ps, false);\n\
    \tint n = (int)convex.size();\n\n\tif(n == 2)return get_distance(convex[0], convex[1]);\n\
    \n\tint i = 0, j = 0;\n\tfor(int k = 0;k < n;k++){\n\t\tif(convex[k] < convex[i])i\
    \ = k;\n\t\tif(convex[j] < convex[k])j = k;\n\t}\n\tDOUBLE res = 0;\n\tint si\
    \ = i, sj = j;\n\twhile(i != sj || j != si){\n\t\tres = max(res, get_distance(convex[i],\
    \ convex[j]));\n\t\tif(cross(convex[(i+1)%n]-convex[i], convex[(j+1)%n]-convex[j])\
    \ < 0.0){\n\t\t\ti = (i+1) % n;\n\t\t}else{\n\t\t\tj = (j+1) % n;\n\t\t}\n\t}\n\
    \treturn res;\n}\n\npolygon convex_cut(polygon &p, line s){\n\tpolygon ret;\n\t\
    int n = (int)p.size();\n\tfor(int i = 0;i < n;i++){\n\t\tconst point &now = p[i];\n\
    \t\tconst point &nxt = p[(i+1)%n];\n\t\tauto cf = cross(s.p1 - now, s.p2 - now);\n\
    \t\tauto cs = cross(s.p1 - nxt, s.p2 - nxt);\n\t\tif(sgn(cf) >= 0){\n\t\t\tret.emplace_back(now);\n\
    \t\t}\n\t\tif(sgn(cf) * sgn(cs) < 0){\n\t\t\tline l = line{now, nxt};\n\t\t\t\
    ret.emplace_back(get_crosspoint(l, s)[0]);\n\t\t}\n\t}\n\treturn ret;\n}\n\nbool\
    \ __compare_y(const point &a, const point &b){\n\treturn a.y < b.y;\n}\n\nDOUBLE\
    \ closest_pair(vector<point> &p, int l=0, int r=-1) {\n\tif(r == -1)r = (int)p.size();\n\
    \tif(r-l <= 1)return 1e100;\n\tint mid = (l+r)/2;\n\tDOUBLE x = p[mid].x;\n\t\
    DOUBLE d = min(closest_pair(p, l, mid), closest_pair(p, mid, r));\n\tauto iti\
    \ = p.begin(), itl =iti+l, itm = iti+mid, itr = iti+r;\n\tinplace_merge(itl, itm,\
    \ itr, __compare_y);\n\n\tvector<point> near_line;\n\tfor(int i = l;i < r;i++){\n\
    \t\tif(abs(p[i].x-x) >= d)continue;\n\n\t\tint sz = (int)near_line.size();\n\t\
    \tfor(int j = sz-1;j >= 0;j--){\n\t\t\tpoint delta = p[i]-near_line[j];\n\t\t\t\
    if(delta.y >= d)break;\n\t\t\td = min(d, sqrtl(delta.norm()));\n\t\t}\n\t\tnear_line.emplace_back(p[i]);\n\
    \t}\n\treturn d;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/util.hpp
  requiredBy: []
  timestamp: '2025-05-26 08:31:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yukicoder/3154.test.cpp
  - verify/aoj/cgl/3_C.test.cpp
  - verify/aoj/cgl/4_A.test.cpp
  - verify/aoj/cgl/2_B.test.cpp
  - verify/aoj/cgl/3_B.test.cpp
  - verify/aoj/cgl/2_C.test.cpp
  - verify/aoj/cgl/5_A.test.cpp
  - verify/aoj/cgl/1_B.test.cpp
  - verify/aoj/cgl/4_C.test.cpp
  - verify/aoj/cgl/1_A.test.cpp
  - verify/aoj/cgl/4_B.test.cpp
  - verify/aoj/cgl/2_D.test.cpp
  - verify/aoj/cgl/3_A.test.cpp
  - verify/aoj/cgl/1_C.test.cpp
  - verify/aoj/cgl/2_A.test.cpp
documentation_of: geometry/util.hpp
layout: document
title: "\u5E7E\u4F55\u30E9\u30A4\u30D6\u30E9\u30EA"
---

# 幾何ライブラリ

幾何に関するものをまとめたライブラリ。ファイル分け等は要検討

# 使い方

- EPS は ``10^{-9}`` 統一
- 浮動小数型として ``long double`` を採用

## point 型

点やベクトルを表す際に使用

- 四則演算
- 絶対値
- ノルム
- 比較( x 座標優先)
- 入出力

## segment 型

線分を表す際に使用

- 入出力

## line 型

直線を表す際に使用。 segment と同一

## circle 型

円を表す際に使用。

# 関数群

## ``DOUBLE dot(point a, point b)``

- $2$ 点の内積を計算

## ``DOUBLE cross(point a, point b)``

- $2$ 点の外積を計算

## ``int ccw(point p0, p1, p2)``

$3$ 点の関係を判定

- ``COUNTER_CLOCKWISE : 1``
- ``CLOCKWISE : -1``
- ``ONLINE_BACK : 2``
- ``ONLINE_FRONT : -2``
- ``ON_SEGMENT : 0``

を返す

## ``bool intersect(segment s1, segment s2)``

- $2$ 直線の交差判定

## ``point project(line s, point p)``

- 直線と点の射影を返す

## ``point reflect(line s, point p)``

- 直線と点の反射を返す

## ``DOUBLE get_distance(line l, point p)``
## ``DOUBLE get_distance_sp(segment l, point p)``
## ``DOUBLE get_distance(segment s1, segment_s2)``

- 距離を返す

## ``vector<point> get_crosspoint(line l, line m)``

- $2$ 直線の交点を返す。ない場合は空の配列が返る

## ``is_orthogonal(point a, point b)``
## ``is_orthogonal(segment a, segment b)``

- 直交判定をする

## ``is_parallel(point a, point b)``
## ``is_parallel(segment a, segment b)``

- 平行判定をする

## ``DOUBLE area(polygon p)``

- (凸とは限らない)多角形 $p$ の面積を求める

## ``bool is_convex(polygon p, bool allow_colinear=false)``

- 多角形 $p$ の凸性判定を行う(``allow_colinear=true`` の時は、$3$ 点が同一直線状にあることを許す)

## ``int contains(polygon g, point p)``

- (凸とは限らない)多角形 $g$ と点 $p$ の包含関係を返す
  - 含まれる場合は 2
  - 辺上は 1
  - それ以外は 0

## ``polygon convex_hull(polygon p, bool allow_colinear=false)``

- 多角形 $p$ 凸包を返す(``allow_colinear=true`` の時は、$3$ 点が同一直線状にあることを許す) $O(N \log N)$

## ``DOUBLE diameter(polygon &p)``

- 多角形 $p$ の直径(最遠点対) を返す $O(N \log N)$

キャリパー法で求める。

凸法を求めたのち、辞書順最小 $p_i$ と辞書順最大 $p_j$ を用意。

ベクトル $p_{i+1}-p_i, p_{j+1}-p{j}$ の外積を基に進める頂点を決め、それぞれで距離を求める。


## ``polygon convex_cut(polygon &p, line s)``

- 多角形 $p$ を直線 $s$ で切った左側を返す $O(n)$
- 右側を返す際は $s$ で与える $2$ 点を入れ替えると良い

## ``DOUBLE closest_pair(vector<point> &p)``

- 事前に $x$ 座標でソートされた頂点集合 $p$ の最近点対の距離を返す $O(N \log N)$

分割統治法で求める

[参考](https://hcpc-hokudai.github.io/archive/algorithm_divide_and_conquer_001.pdf)

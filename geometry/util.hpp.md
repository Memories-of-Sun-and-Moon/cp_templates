---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/util.hpp\"\n\nusing DOUBLE = long double;\n\nconstexpr\
    \ DOUBLE EPS = 1e-9;\n\nstruct point {\n\tDOUBLE x, y;\n\n\tpoint(DOUBLE _x =\
    \ 0, DOUBLE _y = 0): x(_x), y(_y) {}\n\n\tpoint operator+(point p){ return point(x+p.x,\
    \ y+p.y); };\n\tpoint operator-(point p){ return point(x-p.x, y-p.y); };\n\tpoint\
    \ operator*(DOUBLE a) {return point(x*a, y*a); };\n\tpoint operator/(DOUBLE a)\
    \ {return point(x/a, y/a); };\n\n\tDOUBLE abs() {return sqrt(norm()); };\n\tDOUBLE\
    \ norm() {return x*x + y*y; };\n\n\tbool operator<(const point &p) const {\n\t\
    \treturn (not (fabs(x-p.x) < EPS)? x<p.x : y<p.y);\n\t}\n\n\tbool operator==(const\
    \ point &p) const {\n\t\treturn fabs(x-p.x) < EPS && fabs(y-p.y) < EPS;\n\t}\n\
    };\n\n\nstruct segment {point p1, p2; };\ntypedef segment line;\n\nstruct circle\
    \ {\n\tpoint c;\n\tDOUBLE r;\n\tcircle(point _c = point(), DOUBLE _r = 0.0): c(_c),\
    \ r(_r) {}\n};\n\nDOUBLE dot(point a, point b) {\n\treturn a.x*b.x + a.y*b.y;\n\
    }\n\nDOUBLE cross(point a, point b) {\n\treturn a.x*b.y - a.y*b.x;\n}\n\nconstexpr\
    \ int COUNTER_CLOCKWISE = 1;\nconstexpr int CLOCKWISE = -1;\nconstexpr int ONLINE_BACK\
    \ = 2;\nconstexpr int ONLINE_FRONT = -2;\nconstexpr int ON_SEGMENT = 0;\n\nint\
    \ ccw(point p0, point p1, point p2) {\n\tpoint a = p1 - p0;\n\tpoint b = p2 -\
    \ p0;\n\n\tif(p0 == p1)return ON_SEGMENT;\n\tif(p0 == p2)return ON_SEGMENT;\n\t\
    if(p1 == p2)return ON_SEGMENT;\n\n\tif(cross(a, b) > EPS)return COUNTER_CLOCKWISE;\n\
    \tif(cross(a, b) < -EPS)return CLOCKWISE;\n\tif(dot(a, b) < -EPS)return ONLINE_BACK;\n\
    \tif(a.norm() < b.norm())return ONLINE_FRONT;\n\n\treturn ON_SEGMENT;\n}\n\nbool\
    \ intersect(point p1, point p2, point p3, point p4) {\n\treturn (ccw(p1, p2, p3)*ccw(p1,\
    \ p2, p4) <= 0 && ccw(p3, p4, p1)*ccw(p3, p4, p2) <= 0);\n}\n\nbool intersect(segment\
    \ s1, segment s2) {\n\treturn intersect(s1.p1, s1.p2, s2.p1, s2.p2);\n}\n\npoint\
    \ project(line &s, point &p) {\n\tpoint base = s.p2 - s.p1;\n\tDOUBLE r = dot(p-s.p1,\
    \ base) / base.norm();\n\treturn s.p1 + base*r;\n}\n\nDOUBLE get_distance(point\
    \ &a, point &b){\n\treturn (a-b).abs();\n}\n\n// line, point\nDOUBLE get_distance_lp(line\
    \ &l, point &p){\n\treturn abs(cross(l.p2-l.p1, p-l.p1) / (l.p2-l.p1).abs());\n\
    }\n// segment, point\nDOUBLE get_distance_sp(segment &s, point &p){\n\tif(dot(s.p2-s.p1,\
    \ p-s.p1) < 0.0)return (p-s.p1).abs();\n\tif(dot(s.p1-s.p2, p-s.p2) < 0.0)return\
    \ (p-s.p2).abs();\n\treturn get_distance_lp(s, p);\n}\n\nDOUBLE get_distance(segment\
    \ &s1, segment &s2){\n\tif(intersect(s1, s2))return 0.0;\n\treturn min({get_distance_sp(s1,\
    \ s2.p1), get_distance_sp(s1, s2.p2), get_distance_sp(s2, s1.p1), get_distance_sp(s2,\
    \ s1.p2)});\n}\n\nvector<point> get_crosspoint(line &l, line &m){\n\tvector<point>\
    \ res;\n\tDOUBLE d = cross(m.p2-m.p1, l.p2-l.p1);\n\tif(abs(d) < EPS)return vector<point>();\n\
    \tres.push_back(l.p1 + (l.p1+l.p2) * cross(m.p2-m.p1, m.p2-l.p1) / d);\n\treturn\
    \ res;\n}\n\npair<point, point> get_crosspoints(circle &c, line &l){\n\tpoint\
    \ pr = project(l, c.c);\n\tpoint e = (l.p2-l.p1)/(l.p2-l.p1).abs();\n\tDOUBLE\
    \ base = sqrt(max<DOUBLE>(0.0, c.r*c.r - (pr-c.c).norm()));\n\treturn {pr+e*base,\
    \ pr-e*base};\n}\n\npoint polar (DOUBLE a, DOUBLE r){\n\treturn point(cos(r)*a,\
    \ sin(r)*a);\n}\n\npair<point, point> get_crosspoints(circle &c1, circle &c2){\n\
    \tDOUBLE d = (c1.c-c2.c).abs();\n\tDOUBLE a = acos((c1.r*c1.r + d*d - c2.r*c2.r)\
    \ / (2*c1.r*d));\n\tDOUBLE t = atan2((c2.c-c1.c).y, (c2.c-c1.c).x);\n\treturn\
    \ {c1.c+polar(c1.r, t+a), c1.c+polar(c1.r, t-a)};\n}\n\nDOUBLE deg_to_rad(const\
    \ DOUBLE &deg) {return deg*pi / 180.0; };\n"
  code: "\nusing DOUBLE = long double;\n\nconstexpr DOUBLE EPS = 1e-9;\n\nstruct point\
    \ {\n\tDOUBLE x, y;\n\n\tpoint(DOUBLE _x = 0, DOUBLE _y = 0): x(_x), y(_y) {}\n\
    \n\tpoint operator+(point p){ return point(x+p.x, y+p.y); };\n\tpoint operator-(point\
    \ p){ return point(x-p.x, y-p.y); };\n\tpoint operator*(DOUBLE a) {return point(x*a,\
    \ y*a); };\n\tpoint operator/(DOUBLE a) {return point(x/a, y/a); };\n\n\tDOUBLE\
    \ abs() {return sqrt(norm()); };\n\tDOUBLE norm() {return x*x + y*y; };\n\n\t\
    bool operator<(const point &p) const {\n\t\treturn (not (fabs(x-p.x) < EPS)? x<p.x\
    \ : y<p.y);\n\t}\n\n\tbool operator==(const point &p) const {\n\t\treturn fabs(x-p.x)\
    \ < EPS && fabs(y-p.y) < EPS;\n\t}\n};\n\n\nstruct segment {point p1, p2; };\n\
    typedef segment line;\n\nstruct circle {\n\tpoint c;\n\tDOUBLE r;\n\tcircle(point\
    \ _c = point(), DOUBLE _r = 0.0): c(_c), r(_r) {}\n};\n\nDOUBLE dot(point a, point\
    \ b) {\n\treturn a.x*b.x + a.y*b.y;\n}\n\nDOUBLE cross(point a, point b) {\n\t\
    return a.x*b.y - a.y*b.x;\n}\n\nconstexpr int COUNTER_CLOCKWISE = 1;\nconstexpr\
    \ int CLOCKWISE = -1;\nconstexpr int ONLINE_BACK = 2;\nconstexpr int ONLINE_FRONT\
    \ = -2;\nconstexpr int ON_SEGMENT = 0;\n\nint ccw(point p0, point p1, point p2)\
    \ {\n\tpoint a = p1 - p0;\n\tpoint b = p2 - p0;\n\n\tif(p0 == p1)return ON_SEGMENT;\n\
    \tif(p0 == p2)return ON_SEGMENT;\n\tif(p1 == p2)return ON_SEGMENT;\n\n\tif(cross(a,\
    \ b) > EPS)return COUNTER_CLOCKWISE;\n\tif(cross(a, b) < -EPS)return CLOCKWISE;\n\
    \tif(dot(a, b) < -EPS)return ONLINE_BACK;\n\tif(a.norm() < b.norm())return ONLINE_FRONT;\n\
    \n\treturn ON_SEGMENT;\n}\n\nbool intersect(point p1, point p2, point p3, point\
    \ p4) {\n\treturn (ccw(p1, p2, p3)*ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1)*ccw(p3,\
    \ p4, p2) <= 0);\n}\n\nbool intersect(segment s1, segment s2) {\n\treturn intersect(s1.p1,\
    \ s1.p2, s2.p1, s2.p2);\n}\n\npoint project(line &s, point &p) {\n\tpoint base\
    \ = s.p2 - s.p1;\n\tDOUBLE r = dot(p-s.p1, base) / base.norm();\n\treturn s.p1\
    \ + base*r;\n}\n\nDOUBLE get_distance(point &a, point &b){\n\treturn (a-b).abs();\n\
    }\n\n// line, point\nDOUBLE get_distance_lp(line &l, point &p){\n\treturn abs(cross(l.p2-l.p1,\
    \ p-l.p1) / (l.p2-l.p1).abs());\n}\n// segment, point\nDOUBLE get_distance_sp(segment\
    \ &s, point &p){\n\tif(dot(s.p2-s.p1, p-s.p1) < 0.0)return (p-s.p1).abs();\n\t\
    if(dot(s.p1-s.p2, p-s.p2) < 0.0)return (p-s.p2).abs();\n\treturn get_distance_lp(s,\
    \ p);\n}\n\nDOUBLE get_distance(segment &s1, segment &s2){\n\tif(intersect(s1,\
    \ s2))return 0.0;\n\treturn min({get_distance_sp(s1, s2.p1), get_distance_sp(s1,\
    \ s2.p2), get_distance_sp(s2, s1.p1), get_distance_sp(s2, s1.p2)});\n}\n\nvector<point>\
    \ get_crosspoint(line &l, line &m){\n\tvector<point> res;\n\tDOUBLE d = cross(m.p2-m.p1,\
    \ l.p2-l.p1);\n\tif(abs(d) < EPS)return vector<point>();\n\tres.push_back(l.p1\
    \ + (l.p1+l.p2) * cross(m.p2-m.p1, m.p2-l.p1) / d);\n\treturn res;\n}\n\npair<point,\
    \ point> get_crosspoints(circle &c, line &l){\n\tpoint pr = project(l, c.c);\n\
    \tpoint e = (l.p2-l.p1)/(l.p2-l.p1).abs();\n\tDOUBLE base = sqrt(max<DOUBLE>(0.0,\
    \ c.r*c.r - (pr-c.c).norm()));\n\treturn {pr+e*base, pr-e*base};\n}\n\npoint polar\
    \ (DOUBLE a, DOUBLE r){\n\treturn point(cos(r)*a, sin(r)*a);\n}\n\npair<point,\
    \ point> get_crosspoints(circle &c1, circle &c2){\n\tDOUBLE d = (c1.c-c2.c).abs();\n\
    \tDOUBLE a = acos((c1.r*c1.r + d*d - c2.r*c2.r) / (2*c1.r*d));\n\tDOUBLE t = atan2((c2.c-c1.c).y,\
    \ (c2.c-c1.c).x);\n\treturn {c1.c+polar(c1.r, t+a), c1.c+polar(c1.r, t-a)};\n\
    }\n\nDOUBLE deg_to_rad(const DOUBLE &deg) {return deg*pi / 180.0; };\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/util.hpp
  requiredBy: []
  timestamp: '2024-06-29 11:39:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/util.hpp
layout: document
redirect_from:
- /library/geometry/util.hpp
- /library/geometry/util.hpp.html
title: geometry/util.hpp
---
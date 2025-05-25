
using DOUBLE = long double;

constexpr DOUBLE EPS = 1e-9;

struct point {
	DOUBLE x, y;

	point(DOUBLE _x = 0, DOUBLE _y = 0): x(_x), y(_y) {}

	point operator+(point p){ return point(x+p.x, y+p.y); };
	point operator-(point p){ return point(x-p.x, y-p.y); };
	point operator*(DOUBLE a) {return point(x*a, y*a); };
	point operator/(DOUBLE a) {return point(x/a, y/a); };

	DOUBLE abs() {return sqrtl(norm()); };
	DOUBLE norm() {return x*x + y*y; };

	bool operator<(const point &p) const {
		return (not (fabs(x-p.x) < EPS)? x<p.x : y<p.y);
	}

	bool operator==(const point &p) const {
		return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS;
	}
};
istream& operator >> (istream &is, point &p){return is >> p.x >> p.y;}
ostream& operator << (ostream &os, const point &p){return os << p.x << " " << p.y;}

using polygon = vector<point>;

struct segment {point p1, p2; };
typedef segment line;
istream& operator >> (istream &is, segment &s){return is >> s.p1 >> s.p2;}
ostream& operator << (ostream &os, const segment &s){return os << s.p1 << " " << s.p2;}


struct circle {
	point c;
	DOUBLE r;
	circle(point _c = point(), DOUBLE _r = 0.0): c(_c), r(_r) {}
};

DOUBLE dot(point a, point b) {
	return a.x*b.x + a.y*b.y;
}

DOUBLE cross(point a, point b) {
	return a.x*b.y - a.y*b.x;
}

constexpr int COUNTER_CLOCKWISE = 1;
constexpr int CLOCKWISE = -1;
constexpr int ONLINE_BACK = 2;
constexpr int ONLINE_FRONT = -2;
constexpr int ON_SEGMENT = 0;

int ccw(point p0, point p1, point p2) {
	point a = p1 - p0;
	point b = p2 - p0;
	
	if(p0 == p1)return ON_SEGMENT;
	if(p0 == p2)return ON_SEGMENT;
	if(p1 == p2)return ON_SEGMENT;
	
	if(cross(a, b) > EPS)return COUNTER_CLOCKWISE;
	if(cross(a, b) < -EPS)return CLOCKWISE;
	if(dot(a, b) < -EPS)return ONLINE_BACK;
	if(a.norm() < b.norm())return ONLINE_FRONT;
	
	return ON_SEGMENT;
}

bool intersect(point p1, point p2, point p3, point p4) {
	return (ccw(p1, p2, p3)*ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1)*ccw(p3, p4, p2) <= 0);
}

bool intersect(segment s1, segment s2) {
	return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

point project(line &s, point &p) {
	point base = s.p2 - s.p1;
	DOUBLE r = dot(p-s.p1, base) / base.norm();
	return s.p1 + base*r;
}

point reflect(line s, point p) {
	return p + (project(s, p) - p) * 2.0;
}

DOUBLE get_distance(point &a, point &b){
	return (a-b).abs();
}

// line, point
DOUBLE get_distance_lp(line &l, point &p){
	return abs(cross(l.p2-l.p1, p-l.p1) / (l.p2-l.p1).abs());
}
// segment, point
DOUBLE get_distance_sp(segment &s, point &p){
	if(dot(s.p2-s.p1, p-s.p1) < 0.0)return (p-s.p1).abs();
	if(dot(s.p1-s.p2, p-s.p2) < 0.0)return (p-s.p2).abs();
	return get_distance_lp(s, p);
}

DOUBLE get_distance(segment &s1, segment &s2){
	if(intersect(s1, s2))return 0.0;
	return min({get_distance_sp(s1, s2.p1), get_distance_sp(s1, s2.p2), get_distance_sp(s2, s1.p1), get_distance_sp(s2, s1.p2)});
}

vector<point> get_crosspoint(line &l, line &m){
	vector<point> res;
	DOUBLE d = cross(m.p2-m.p1, l.p2-l.p1);
	if(abs(d) < EPS)return vector<point>();
	DOUBLE t = cross(m.p2-m.p1, m.p2-l.p1) / d;
	point r = l.p1 + (l.p2-l.p1) * t;
	res.push_back(r);
	return res;
}

pair<point, point> get_crosspoints(circle &c, line &l){
	point pr = project(l, c.c);
	point e = (l.p2-l.p1)/(l.p2-l.p1).abs();
	DOUBLE base = sqrt(max<DOUBLE>(0.0, c.r*c.r - (pr-c.c).norm()));
	return {pr+e*base, pr-e*base};
}

point polar (DOUBLE a, DOUBLE r){
	return point(cos(r)*a, sin(r)*a);
}

pair<point, point> get_crosspoints(circle &c1, circle &c2){
	DOUBLE d = (c1.c-c2.c).abs();
	DOUBLE a = acos((c1.r*c1.r + d*d - c2.r*c2.r) / (2*c1.r*d));
	DOUBLE t = atan2((c2.c-c1.c).y, (c2.c-c1.c).x);
	return {c1.c+polar(c1.r, t+a), c1.c+polar(c1.r, t-a)};
}

DOUBLE deg_to_rad(const DOUBLE &deg) {return deg*pi / 180.0; };

//a > 0ならば+1, a == 0ならば0, a < 0ならば-1　を返す。　基本的にEPS込みの評価はこれで行う。
//不等式は、加減算に直してこれに適用する。
int sgn(const double a) {
    return (a < -EPS ? -1 : (a > EPS ? +1 : 0));
}

//直交判定
bool is_orthogonal(point a, point b){
    return sgn(dot(a, b)) == 0;
}
bool is_orthogonal(segment s1, segment s2){
    return sgn(dot(s1.p2 - s1.p1, s2.p2 - s2.p1)) == 0;
}

//並行判定
bool is_parallel(point a, point b){
    return sgn(cross(a, b)) == 0;
}
bool is_parallel(segment s1, segment s2){
    return sgn(cross(s1.p2 - s1.p1, s2.p2 - s2.p1)) == 0;
}

DOUBLE area(polygon &p){
	DOUBLE s = 0.0;
	size_t n = p.size();
	for(size_t i = 0;i < n;i++){
		int nxt = (i+1)%n;
		s += p[i].x*p[nxt].y - p[nxt].x*p[i].y;
	}
	s = abs(s);
	s /= 2.0;
	return s;
}

bool __is_convex_allow_colinear(polygon &p){
	int n = ssize(p);
	assert(n >= 3);
	int base_ccw;
	{
		int idx = 0;
		int r;
		while(true){
			r = ccw(p[idx], p[(idx+1)%n], p[(idx+2)%n]);
			if(r == CLOCKWISE || r == COUNTER_CLOCKWISE){
				base_ccw = r;
				break;
			}
			idx++;
		}
	}
	for(int i = 0;i < n;i++){
		int r = ccw(p[i], p[(i+1)%n], p[(i+2)%n]);
		if(r != CLOCKWISE && r != COUNTER_CLOCKWISE)continue;
		if(r != base_ccw)return false;
	}
	return true;
}

bool is_convex(polygon &p, bool allow_colinear=false){
	if(allow_colinear)return __is_convex_allow_colinear(p);
	int n = ssize(p);
	assert(n >= 3);
	int base_ccw = ccw(p[0], p[1], p[2]);
	for(int i = 0;i < n;i++){
		int r = ccw(p[i], p[(i+1)%n], p[(i+2)%n]);
		if(r != base_ccw)return false;
	}
	return true;
}

/*
IN 2
ON 1
OUT 0
*/
int contains(polygon g, point p){
	int n = (int)g.size();
	bool x = false;
	for(int i = 0;i < n;i++){
		point a = g[i]-p, b = g[(i+1)%n]-p;
		if(abs(cross(a, b)) < EPS && dot(a, b) < EPS)return 1;
		if(a.y > b.y)swap(a, b);
		if(a.y < EPS && EPS < b.y && cross(a, b) > EPS)x = !x;
	}
	return (x ? 2 : 0);
}

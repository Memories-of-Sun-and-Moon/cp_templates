
using DOUBLE = long double;

constexpr DOUBLE EPS = 1e-9;

//a > 0ならば+1, a == 0ならば0, a < 0ならば-1　を返す。　基本的にEPS込みの評価はこれで行う。
//不等式は、加減算に直してこれに適用する。
int sgn(const double a) {
    return (a < -EPS ? -1 : (a > EPS ? +1 : 0));
}

struct point {
	DOUBLE x, y;

	point(DOUBLE _x = 0, DOUBLE _y = 0): x(_x), y(_y) {}

	point operator+(point p){ return point(x+p.x, y+p.y); }
	point operator+(const point &p) const { return point(x+p.x, y+p.y); }
	point operator-(point p){ return point(x-p.x, y-p.y); }
	point operator-(const point &p) const { return point(x-p.x, y-p.y); }
	point operator*(DOUBLE a) {return point(x*a, y*a); }
	point operator/(DOUBLE a) {return point(x/a, y/a); }
	

	DOUBLE abs() const {return sqrtl(norm()); }
	DOUBLE norm() const {return x*x + y*y; }

	point conjuacy() const {return point(x, -y); }

	point operator*(const point &p) const { return point(x*p.x - y*p.y, x*p.y + y*p.x); }
	point operator/(const point &p) const { return (*this * p.conjuacy()) / p.norm(); }

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
istream& operator >> (istream &is, circle &s){return is >> s.c >> s.r;}
ostream& operator << (ostream &os, const circle &s){return os << s.c << " " << s.r;}


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

// 共通接線の数を返す
int intersect(const circle &c1, const circle &c2) {
	DOUBLE r1 = c1.r + c2.r;
	DOUBLE r2 = abs(c1.r - c2.r);
	DOUBLE d = (c2.c-c1.c).abs();
	if(sgn(d-r1) == 1)return 4;
	if(sgn(d-r1) == 0)return 3;
	if(sgn(r2-d) == 0)return 1;
	if(sgn(r2-d) == 1)return 0;
	return 2;
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

pair<point, point> get_crosspoints(const circle &c1, const circle &c2){
	DOUBLE d = (c1.c-c2.c).abs();
	DOUBLE a = acos((c1.r*c1.r + d*d - c2.r*c2.r) / (2*c1.r*d));
	DOUBLE t = atan2((c2.c-c1.c).y, (c2.c-c1.c).x);
	return {c1.c+polar(c1.r, t+a), c1.c+polar(c1.r, t-a)};
}

DOUBLE deg_to_rad(const DOUBLE &deg) {return deg*pi / 180.0; };

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

DOUBLE area(const circle &c) {
	return c.r*c.r*acos(-1);
}

DOUBLE area(const circle &c, const DOUBLE &ang) {
	return c.r*c.r*acos(-1)*ang/(acos(-1)+acos(-1));
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

polygon convex_hull(polygon &ps, bool allow_colinear=false){
	int n = (int)ps.size();
	sort(ps.begin(), ps.end());
	int k = 0;
	polygon qs(n*2);
	for(int i = 0;i < n;i++){
		if(allow_colinear)while(k > 1 && cross(qs[k-1]-qs[k-2], ps[i]-qs[k-1]) <  0.0)k--;
		else              while(k > 1 && cross(qs[k-1]-qs[k-2], ps[i]-qs[k-1]) <= 0.0)k--;
		qs[k++] = ps[i];
	}
	for(int i = n-2, t=k;i >= 0;i--){
		if(allow_colinear)while(k > t && cross(qs[k-1]-qs[k-2], ps[i]-qs[k-1]) <  0.0)k--;
		else              while(k > t && cross(qs[k-1]-qs[k-2], ps[i]-qs[k-1]) <= 0.0)k--;
		qs[k++] = ps[i];
	}
	qs.resize(k-1);
	return qs;
}

DOUBLE diameter(polygon &ps) {
	polygon convex = convex_hull(ps, false);
	int n = (int)convex.size();

	if(n == 2)return get_distance(convex[0], convex[1]);

	int i = 0, j = 0;
	for(int k = 0;k < n;k++){
		if(convex[k] < convex[i])i = k;
		if(convex[j] < convex[k])j = k;
	}
	DOUBLE res = 0;
	int si = i, sj = j;
	while(i != sj || j != si){
		res = max(res, get_distance(convex[i], convex[j]));
		if(cross(convex[(i+1)%n]-convex[i], convex[(j+1)%n]-convex[j]) < 0.0){
			i = (i+1) % n;
		}else{
			j = (j+1) % n;
		}
	}
	return res;
}

polygon convex_cut(polygon &p, line s){
	polygon ret;
	int n = (int)p.size();
	for(int i = 0;i < n;i++){
		const point &now = p[i];
		const point &nxt = p[(i+1)%n];
		auto cf = cross(s.p1 - now, s.p2 - now);
		auto cs = cross(s.p1 - nxt, s.p2 - nxt);
		if(sgn(cf) >= 0){
			ret.emplace_back(now);
		}
		if(sgn(cf) * sgn(cs) < 0){
			line l = line{now, nxt};
			ret.emplace_back(get_crosspoint(l, s)[0]);
		}
	}
	return ret;
}

bool __compare_y(const point &a, const point &b){
	return a.y < b.y;
}

DOUBLE closest_pair(vector<point> &p, int l=0, int r=-1) {
	if(r == -1)r = (int)p.size();
	if(r-l <= 1)return 1e100;
	int mid = (l+r)/2;
	DOUBLE x = p[mid].x;
	DOUBLE d = min(closest_pair(p, l, mid), closest_pair(p, mid, r));
	auto iti = p.begin(), itl =iti+l, itm = iti+mid, itr = iti+r;
	inplace_merge(itl, itm, itr, __compare_y);

	vector<point> near_line;
	for(int i = l;i < r;i++){
		if(abs(p[i].x-x) >= d)continue;

		int sz = (int)near_line.size();
		for(int j = sz-1;j >= 0;j--){
			point delta = p[i]-near_line[j];
			if(delta.y >= d)break;
			d = min(d, delta.abs());
		}
		near_line.emplace_back(p[i]);
	}
	return d;
}

DOUBLE angle(const point &p) {
	DOUBLE ret = atan2(p.y, p.x);
	if(ret < 0.0)return ret += acos(-1) + acos(-1);
	return ret;
}

// [-π, π]
DOUBLE internal_angle(const point &a, const point &b, const point &c) {
    point ba = a - b;
    point bc = c - b;
    DOUBLE ret = angle(bc) - angle(ba);

    if (ret < 0) ret += 2 * acos(-1);
    if (ret > acos(-1)) ret = 2 * acos(-1) - ret;

    return ret;
}

point rotate(const point &p, DOUBLE angle) {
	return point(cos(angle)*p.x - sin(angle)*p.y, sin(angle)*p.x + cos(angle)*p.y);
}
point right_angle_rotate(const point &p) {
	return point(-p.y, p.x);
}

// 角の二等分線
line angle_bisector(point p1, point p2, point p3) {
	DOUBLE ang = angle((p3-p1)/(p2-p1));
	return line(p1, p1+rotate(p2-p1, ang/2.0));
}

// 垂直二等分線
line perpendicular_bisector(const point &p1, const point &p2) {
	return line((p1+p2)/2.0, (p1+p2)/2.0 + right_angle_rotate(p2-p1));
}
line perpendicular_bisector(const line &s) {
	return perpendicular_bisector(s.p1, s.p2);
}

// 内接円
circle incircle_of_a_triangle(const point &p1, const point &p2, const point &p3) {
	line s = angle_bisector(p1, p2, p3);
	line t = angle_bisector(p2, p1, p3);
	point c = get_crosspoint(s, t)[0];
	segment seg = segment{p1, p2};
	DOUBLE r = get_distance_sp(seg, c);
	return circle(c, r);
}

// 外接円
circle circumcircle_of_a_triangle(const point &p1, const point &p2, const point &p3) {
	line s = perpendicular_bisector(p1, p2);
	line t = perpendicular_bisector(p1, p3);
	point c = get_crosspoint(s, t)[0];
	DOUBLE r = (p1-c).abs();
	return circle(c, r);
}

//  p を通る c の接線
pair<point, point> tangent(const circle &c1, const point &p) {
	DOUBLE r = sqrtl((c1.c-p).norm()-c1.r*c1.r);
	const circle c2(p, r);
	return get_crosspoints(c1, c2);
}

DOUBLE intersection_of_areas(const circle &c1, const circle &c2) {
	int int_id = intersect(c1, c2);
	if(int_id == 0 || int_id == 1){
		DOUBLE r = min(c1.r, c2.r);
		return r*r*acos(-1);
	}
	if(int_id == 3 || int_id == 4){
		return 0.0;
	}

	
	auto [l, r] = get_crosspoints(c1, c2);
	polygon p = {c1.c, l, c2.c, r};
	DOUBLE s = area(p);
	DOUBLE a1 = abs(internal_angle(l, c1.c, r));
	DOUBLE a2 = abs(internal_angle(l, c2.c, r));
	return area(c1, a1) + area(c2, a2) - s;
}

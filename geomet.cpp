#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const double PI = acos(-1);
template<class T>constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T>constexpr T HINF() { return INF<T>() / 2; }
template <typename T_char>T_char TL(T_char cX) { return tolower(cX); };
template <typename T_char>T_char TU(T_char cX) { return toupper(cX); };
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
int popcnt(unsigned long long n) { int cnt = 0; for (int i = 0; i < 64; i++)if ((n >> i) & 1)cnt++; return cnt; }
int d_sum(LL n) { int ret = 0; while (n > 0) { ret += n % 10; n /= 10; }return ret; }
int d_cnt(LL n) { int ret = 0; while (n > 0) { ret++; n /= 10; }return ret; }
LL gcd(LL a, LL b) { if (b == 0)return a; return gcd(b, a%b); };
LL lcm(LL a, LL b) { LL g = gcd(a, b); return a / g*b; };
# define ALL(qpqpq)           (qpqpq).begin(),(qpqpq).end()
# define UNIQUE(wpwpw)        sort(ALL((wpwpw)));(wpwpw).erase(unique(ALL((wpwpw))),(wpwpw).end())
# define LOWER(epepe)         transform(ALL((epepe)),(epepe).begin(),TL<char>)
# define UPPER(rprpr)         transform(ALL((rprpr)),(rprpr).begin(),TU<char>)
# define FOR(i,tptpt,ypypy)   for(LL i=(tptpt);i<(ypypy);i++)
# define REP(i,upupu)         FOR(i,0,upupu)

struct INIT{
    INIT(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
        cout << fixed << setprecision(20);
    }
}INIT;

# define EPS 10e-9

//a > 0ならば+1, a == 0ならば0, a < 0ならば-1　を返す。　基本的にEPS込みの評価はこれで行う。
//不等式は、加減算に直してこれに適用する。
int sgn(const double a) {
    return (a < -EPS ? -1 : (a > EPS ? +1 : 0));
}

// sqrtに負数が入らないようにする

//とりあえず真似る

//点
struct Point {
    double x, y;

    Point(double _x = 0.0, double _y = 0.0): x(_x), y(_y) {}

    Point operator - () const{return Point(-x, -y);};

    Point operator + (const Point &p) const{return Point(x + p.x, y + p.y);}
    Point operator - (const Point &p) const{return Point(x - p.x, y - p.y);}
    Point operator * (double k) const{return Point(x * k, y * k);}
    Point operator / (double k) const{return Point(x / k, y / k);}

    double norm(){return x * x + y * y;}
    double abs(){return sqrt(max(0.0, norm()));};
};
istream& operator >> (istream &is, Point &p){return is >> p.x >> p.y;}
ostream& operator << (ostream &os, const Point &p){return os << p.x << " " << p.y;}


//ベクトル
typedef Point Vector;

//内積
double dot(Vector a, Vector b){
    return a.x * b.x + a.y * b.y;
}

//外積
double cross(Vector a, Vector b){
    return a.x * b.y - a.y * b.x;
}

//線分
struct Segment{
    Point p1, p2;
    Segment(Point _p1 = Point(), Point _p2 = Point()) : p1(_p1), p2(_p2) {}
};
istream& operator >> (istream &is, Segment &s){return is >> s.p1 >> s.p2;}
ostream& operator << (ostream &os, const Segment &s){return os << s.p1 << " " << s.p2;}

//直線←線分と区別
typedef Segment Line;

//円
struct Circle{
    Point c;
    double r;
    Circle(Point _c = Point(), double _r = 0.0): c(_c), r(_r) {}
};

//多角形
typedef vector<Point> Polygon;

//直交判定
bool isOrthogonal(Vector a, Vector b){
    return sgn(dot(a, b)) == 0;
}
bool isOrthogonal(Segment s1, Segment s2){
    return sgn(dot(s1.p2 - s1.p1, s2.p2 - s2.p1)) == 0;
}

//並行判定
bool isParallel(Vector a, Vector b){
    return sgn(cross(a, b)) == 0;
}
bool isParallel(Segment s1, Segment s2){
    return sgn(cross(s1.p2 - s1.p1, s2.p2 - s2.p1)) == 0;
}

//射影
Point project(Segment s, Point p){
    Vector base = s.p2 - s.p1;
    double r = dot(p - s.p1, base) / base.norm();
    return s.p1 + base * r;
}

//反射
Point reflect(Segment s, Point p){
    return p + (project(s, p) - p) * 2.0;
}

int main(){
    Line l;
    int q;
    cin >> l >> q;
    while(q--){
        Point p;
        cin >> p;
        cout << reflect(l, p) << endl;
    }
}
# include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
template<class T>constexpr T inf() { return ::std::numeric_limits<T>::max(); }
template<class T>constexpr T hinf() { return inf<T>() / 2; }
template <typename T_char>T_char TL(T_char cX) { return tolower(cX); }
template <typename T_char>T_char TU(T_char cX) { return toupper(cX); }
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
int popcnt(unsigned long long n) { int cnt = 0; for (int i = 0; i < 64; i++)if ((n >> i) & 1)cnt++; return cnt; }
int d_sum(ll n) { int ret = 0; while (n > 0) { ret += n % 10; n /= 10; }return ret; }
int d_cnt(ll n) { int ret = 0; while (n > 0) { ret++; n /= 10; }return ret; }
ll gcd(ll a, ll b) { if (b == 0)return a; return gcd(b, a%b); };
ll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g*b; };
ll MOD(ll x, ll m){return (x%m+m)%m; }
ll FLOOR(ll x, ll m) {ll r = (x%m+m)%m; return (x-r)/m; }
template<class T> using dijk = priority_queue<T, vector<T>, greater<T>>;
# define all(qpqpq)           (qpqpq).begin(),(qpqpq).end()
# define UNIQUE(wpwpw)        (wpwpw).erase(unique(all((wpwpw))),(wpwpw).end())
# define LOWER(epepe)         transform(all((epepe)),(epepe).begin(),TL<char>)
# define UPPER(rprpr)         transform(all((rprpr)),(rprpr).begin(),TU<char>)
# define rep(i,upupu)         for(ll i = 0, i##_len = (upupu);(i) < (i##_len);(i)++)
# define reps(i,opopo)        for(ll i = 1, i##_len = (opopo);(i) <= (i##_len);(i)++)
# define len(x)                ((ll)(x).size())
# define bit(n)               (1LL << (n))
# define pb push_back
# define eb emplace_back
# define exists(c, e)         ((c).find(e) != (c).end())

struct INIT{
	INIT(){
		std::ios::sync_with_stdio(false);
		std::cin.tie(0);
		cout << fixed << setprecision(20);
	}
}INIT;

namespace mmrz {
	void solve();
}

int main(){
	mmrz::solve();
}

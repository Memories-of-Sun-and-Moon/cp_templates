#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A" // DUMMY

#include "./../../template/template.hpp"
#include "./../../data_structure/segment_tree_2d.hpp"

class xor_shift_128 {
public:
	typedef uint32_t result_type;
	xor_shift_128(uint32_t seed = 42) {
		set_seed(seed);
	}
	void set_seed(uint32_t seed) {
		a = seed = 1812433253u * (seed ^ (seed >> 30));
		b = seed = 1812433253u * (seed ^ (seed >> 30)) + 1;
		c = seed = 1812433253u * (seed ^ (seed >> 30)) + 2;
		d = seed = 1812433253u * (seed ^ (seed >> 30)) + 3;
	}
	uint32_t operator() () {
		uint32_t t = (a ^ (a << 11));
		a = b; b = c; c = d;
		return d = (d ^ (d >> 19)) ^ (t ^ (t >> 8));
	}
	static constexpr uint32_t max() { return numeric_limits<result_type>::max(); }
	static constexpr uint32_t min() { return numeric_limits<result_type>::min(); }
private:
	uint32_t a, b, c, d;
};

xor_shift_128 gen;

//[_first, _second] の（たぶん）一様分布
#define RND(_first, _second)	uniform_int_distribution<int>(_first, _second)(gen)

void test_sum(int t){
	int h = RND(1, 1000), w = RND(1, 1000);
	int q = 100;
	vector a(h, vector(w, 0));
	rep(i, h)rep(j, w)a[i][j] = RND(1, 100);
	segment_tree_2d<int> seg(a, [](int l, int r){return l+r;}, 0);
	while(q--){
		// update
		{
			int y = RND(0, h-1), x = RND(0, w-1);
			a[y][x] = RND(1, 100);
			seg.set(y, x, a[y][x]);
		}
		// query
		{
			int li = RND(0, h-1), ri = RND(li+1, h);
			int lj = RND(0, w-1), rj = RND(lj+1, w);
			int ans_seg = seg.fold(li, lj, ri, rj);
			int ans_naive = 0;
			for(int i = li;i < ri;i++){
				for(int j = lj;j < rj;j++){
					ans_naive += a[i][j];
				}
			}

			assert(ans_seg == ans_naive);
		}
	}
	cerr << "test_sum : case " << t << " : passed" << endl;
}

void test_max(int t){
	int h = RND(1, 1000), w = RND(1, 1000);
	int q = 100;
	vector a(h, vector(w, 0));
	rep(i, h)rep(j, w)a[i][j] = RND(1, 100);
	segment_tree_2d<int> seg(a, [](int l, int r){return max(l, r);}, 0);
	while(q--){
		// update
		{
			int y = RND(0, h-1), x = RND(0, w-1);
			a[y][x] = RND(1, 100);
			seg.set(y, x, a[y][x]);
		}
		// query
		{
			int li = RND(0, h-1), ri = RND(li+1, h);
			int lj = RND(0, w-1), rj = RND(lj+1, w);
			int ans_seg = seg.fold(li, lj, ri, rj);
			int ans_naive = 0;
			for(int i = li;i < ri;i++){
				for(int j = lj;j < rj;j++){
					chmax(ans_naive, a[i][j]);
				}
			}
			
			assert(ans_seg == ans_naive);
		}
	}
	cerr << "test_max : case " << t << " : passed" << endl;
}

void test_min(int t){
	int h = RND(1, 1000), w = RND(1, 1000);
	int q = 100;
	vector a(h, vector(w, 0));
	rep(i, h)rep(j, w)a[i][j] = RND(1, 100);
	segment_tree_2d<int> seg(a, [](int l, int r){return min(l, r);}, hinf<int>());
	while(q--){
		// update
		{
			int y = RND(0, h-1), x = RND(0, w-1);
			a[y][x] = RND(1, 100);
			seg.set(y, x, a[y][x]);
		}
		// query
		{
			int li = RND(0, h-1), ri = RND(li+1, h);
			int lj = RND(0, w-1), rj = RND(lj+1, w);
			int ans_seg = seg.fold(li, lj, ri, rj);
			int ans_naive = hinf<int>();
			for(int i = li;i < ri;i++){
				for(int j = lj;j < rj;j++){
					chmin(ans_naive, a[i][j]);
				}
			}
			
			assert(ans_seg == ans_naive);
		}
	}
	cerr << "test_max : case " << t << " : passed" << endl;
}

void mmrz::solve(){
	// maybe verified with AOJ DSL 5-B
	rep(t, 100)test_sum(t);
	cerr << "test_sum : passed" << endl;
	rep(t, 100)test_max(t);
	cerr << "test_max : passed" << endl;
	rep(t, 100)test_min(t);
	cerr << "test_min : passed" << endl;

	// DUMMY PHASE
	cout << "Hello World\n";
}

#include "./lazy_segment_tree.hpp"

template<class T>
struct area_of_union_rectangles {
private:
	vector<T> ys;
	vector<tuple<T, int, int>>xs;
	vector<tuple<T, T, T, T>> rectangles;
	using S = pair<int, T>;
	using F = int;
	static S op(S a, S b){
		if(a.first < b.first)return a;
		if(a.first > b.first)return b;
		return make_pair(a.first, a.second+b.second);
	}
	static S e(){ return make_pair(numeric_limits<int>::max()/2, 0); }
	static S mapping(F f, S x){ return make_pair(x.first+f, x.second); }
	static F composition(F f, F g){ return f+g; }
	static F id(){ return 0; }
public:

	// l, d, r, u
	area_of_union_rectangles(vector<tuple<T, T, T, T>> _rectangles) : rectangles(_rectangles) {
		ys.reserve(rectangles.size()+rectangles.size());
		xs.reserve(rectangles.size()+rectangles.size());

		for(size_t i = 0;i < rectangles.size();i++){
			auto &[l, d, r, u] = rectangles[i];
			ys.emplace_back(d);
			ys.emplace_back(u);
			xs.emplace_back(l, i, 1);
			xs.emplace_back(r, i, -1);
		}

		sort(ys.begin(), ys.end());
		ys.erase(unique(ys.begin(), ys.end()), ys.end());
		sort(xs.begin(), xs.end());

		map<T, int> y_compress;
		for(size_t i = 0;i < ys.size();i++){
			y_compress[ys[i]] = i;
		}
		for(size_t i = 0;i < rectangles.size();i++){
			auto &[l, d, r, u] = rectangles[i];
			u = y_compress[u];
			d = y_compress[d];
		}
	};

	template<typename U>
	U solve(){
		vector<S> vs((int)ys.size()-1);
		for(size_t i = 0;i+1 < ys.size();i++){
			vs[i] = make_pair(0, ys[i+1]-ys[i]);
		}
		lazy_segment_tree<S, op, e, F, mapping, composition, id> seg(vs);
		
		U ret = 0;

		T total = ys.back() - ys.front();
		for(size_t i = 0;i+1 < xs.size();i++){
			auto &[X, idx, delta] = xs[i];
			auto &[l, d, r, u] = rectangles[idx];
			seg.apply(d, u, delta);

			auto [mn, cnt] = seg.all_fold();

			U dy = total - (mn == 0 ? cnt : 0);
			U dx = get<0>(xs[i+1]) - X;

			ret += dy*dx;
		}

		return ret;
	}
};

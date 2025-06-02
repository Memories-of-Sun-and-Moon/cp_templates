
namespace sbt{

	template<class T>
	tuple<T, T, T, T> child(T p, T q, T r, T s, T d, bool is_left){
		if(is_left){
			r += d*p;
			s += d*q;
		}else{
			p += d*r;
			q += d*s;
		}
		return make_tuple(p, q, r, s);
	}

	template<class T>
	tuple<T, T, T, T> parent(T p, T q, T r, T s){
		if(p == 0 && q == 1 && r == 1 && s == 0){
			return make_tuple(0, 0, 0, 0);
		}
		if(p < r || q < s){
			r -= p, s -= q;
		}else{
			p -= r, q -= s;
		}
		return make_tuple(p, q, r, s);
	}

	template<class T>
	vector<T> encode_path(T p, T q){
		vector<T> a;
		if(p < q){
			a.emplace_back(0);
			swap(p, q);
		}
		while(p != 1){
			a.emplace_back(p/q);
			p %= q;
			swap(p, q);
		}
		if(not a.empty()){
			if(a.back() == 1){
				a.pop_back();
			}else{
				a.back()--;
			}
		}
		return a;
	}

	template<class T>
	tuple<T, T, T, T> decode_path(const vector<T> &a){
		T p = 0, q = 1, r = 1, s = 0;
		for(int i = 0;i < ssize(a);i++){
			tie(p, q, r, s) = child(p, q, r, s, a[i], i&1);
		}
		return make_tuple(p, q, r, s);
	}

	template<class T>
	tuple<T, T, T, T> lca(T p, T q, T r, T s){
		vector<T> a = encode_path(p, q), b = encode_path(r, s);

		int n = min(ssize(a), ssize(b));

		T P = 0, Q = 1, R = 1, S = 0;
		for(int i = 0;i < n;i++){
			T c = min(a[i], b[i]);
			tie(P, Q, R, S) = child(P, Q, R, S, c, i&1);
			if(a[i] != b[i])break;
		}
		return make_tuple(P, Q, R, S);
	}

	template<class T>
	optional<tuple<T, T, T, T>> ancestor(T p, T q, T d){
		vector<T> a = encode_path(p, q);
		T P = 0, Q = 1, R = 1, S = 0;
		for(int i = 0;i < ssize(a);i++){
			T c = min(d, a[i]);
			tie(P, Q, R, S) = child(P, Q, R, S, c, i&1);
			d -= c;
			if(d == 0)break;
		}
		if(d == 0){
			return make_tuple(P, Q, R, S);
		}
		return nullopt;
	}

	template<class T>
	tuple<T, T, T, T> range(T p, T q){
		return decode_path(encode_path(p, q));
	}
}

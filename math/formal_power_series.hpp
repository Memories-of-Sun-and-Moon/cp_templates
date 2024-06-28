
template<typename mint998>
struct formal_power_series : vector<mint998> {
	using vector<mint998>::vector;
	using FPS = formal_power_series;

	FPS &operator+=(const FPS &r){
		if(r.size() > this->size()){
			this->resize(r.size());
		}
		for(size_t i = 0;i < r.size();i++){
			(*this)[i] += r[i];
		}
		return *this;
	}

	FPS &operator+=(const mint998 &v){
		if(this->empty())this->resize(1);
		(*this)[0] += v;
		return *this;
	}

	FPS &operator-=(const FPS &r){
		if(r.size() > this->size()){
			this->resize(r.size());
		}
		for(size_t i = 0;i < r.size();i++){
			(*this)[i] -= r[i];
		}
		return *this;
	}

	FPS &operator-=(const mint998 &v){
		if(this->empty())this->resize(1);
		(*this)[0] -= v;
		return *this;
	}

	FPS &operator*=(const FPS &g){
		size_t N = std::bit_ceil(this->size() + g.size() - 1);

		vector<mint998> F(N, 0), G(N, 0);

		for (size_t i = 0; i < this->size(); i++){
			F[i] = (*this)[i];
		}
		for (size_t i = 0; i < g.size(); i++){
			G[i] = g[i];
		}

		DFT(F);
		DFT(G);

		vector<mint998> FG(N);
		for (size_t i = 0; i < N; i++){
			FG[i] = F[i] * G[i];
		}
		IDFT(FG);

		FPS fg(this->size() + g.size() - 1);
		for (size_t i = 0; i < fg.size(); i++){
			fg[i] = FG[i];
		}
		return *this = fg;
	}

	FPS &operator*=(const mint998 &v){
		for(size_t k = 0;k < this->size();k++){
			(*this)[k] *= v;
			return *this;
		}
	}

	FPS operator+(const FPS &r) const { return FPS(*this) += r; }
	FPS operator+(const mint998 &v) const { return FPS(*this) += v; }
	FPS operator-(const FPS &r) const { return FPS(*this) -= r; }
	FPS operator-(const mint998 &v) const { return FPS(*this) -= v; }
	FPS operator*(const FPS &r) const { return FPS(*this) *= r; }
	FPS operator*(const mint998 &v) const { return FPS(*this) *= v; }
	FPS operator-() const {
		FPS ret(this->size());
		for(size_t i = 0;i < this->size();i++){
			ret[i] = -(*this)[i];
		}
		return ret;
	}

	void shrink(){
		while(this->size() && this->back() == mint998(0))this->pop_back();
	}

	mint998 eval(mint998 x) const {
		mint998 r = 0, w = 1;
		for(auto &v : *this){
			r += w*v;
			w *= x;
		}
		return r;
	}
};

#include "./power.hpp"

vector<vector<mint998>> zeta_table;

mint998 zeta(size_t n, int i){
	i += n;
	i %= n;
	if(zeta_table.empty()){
		zeta_table.resize(24);
		mint998 r = power<mint998>(3,119);
		for(int j = 23;j >= 0;j--){
			zeta_table[j].resize(1);
			zeta_table[j][0] = r;
			r *= r;
		}
	}
	int N_2 = __builtin_ctz(n);
	if(zeta_table[N_2].size() == 1){
		mint998 r = zeta_table[N_2][0];
		zeta_table[N_2][0] = 1;
		zeta_table[N_2].resize(n);
		for(size_t j = 1;j < n;j++){
			zeta_table[N_2][j] = r * zeta_table[N_2][j-1];
			if(j == n-1){
				assert((zeta_table[N_2][j] * r).a == 1);
			}
		}
	}
	return zeta_table[N_2][i];
}

void DFT(vector<mint998> &f, bool inverse = false){
	size_t N = f.size();
	if(N == 1)return;

	size_t n = N >> 1;

	vector<mint998> f0(n), f1(n);
	for (size_t i = 0; i < n; i++){
		f0[i] = f[2 * i];
		f1[i] = f[2 * i + 1];
	}

	DFT(f0, inverse);
	DFT(f1, inverse);

	for (size_t i = 0; i < n; i++){
		f[i] = f0[i] + (inverse ? zeta(N, -i) : zeta(N, i)) * f1[i];
		f[n + i] = f0[i] + (inverse ? zeta(N, -n - i) : zeta(N, n + i)) * f1[i];
	}
}

void IDFT(vector<mint998> &f){
	DFT(f, true);
	size_t N = f.size();
	for (mint998 &a : f){
		a /= N;
	}
}

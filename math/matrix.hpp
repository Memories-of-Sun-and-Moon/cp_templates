
template<typename T>
struct matrix {
	vector<vector<T>> mat;

	matrix(size_t r, size_t c) {
		mat.resize(r);
		for(size_t i = 0;i < r;i++){
			mat[i].resize(c);
		}
	}

	matrix(vector<vector<T>> _mat) : mat(_mat){}

	vector<T>& operator[](int i) {
		return mat[i];
	}
	const vector<T>& operator[](int i) const {
		return mat[i];
	}

	constexpr matrix operator+(const matrix rhs) const {
		return matrix(*this) += rhs;
	}
	constexpr matrix operator-(const matrix rhs) const {
		return matrix(*this) += rhs;
	}
	constexpr matrix operator*(const T rhs) const {
		return matrix(*this) *= rhs;
	}
	constexpr matrix operator*(const matrix rhs) const {
		return matrix(*this) *= rhs;
	}
	constexpr matrix operator+=(const matrix rhs) const {
		assert((*this).size() == rhs.size() && (*this)[0].size() == rhs[0].size());
		for(size_t i = 0;i < (*this).size();i++){
			for(size_t j = 0;j < (*this)[0].size();j++){
				mat += rhs[i][j];
			}
		}
		return *this;
	}
	constexpr matrix operator-=(const matrix rhs) const {
		for(size_t i = 0;i < (*this).size();i++){
			for(size_t j = 0;j < (*this)[0].size();j++){
				mat -= rhs[i][j];
			}
		}
		return *this;
	}

	constexpr matrix operator*=(const T rhs) const {
		for(size_t i = 0;i < (*this).size();i++){
			for(size_t j = 0;j < (*this)[0].size();j++){
				(*this)[i][j] *= rhs;
			}
		}
		return *this;
	}
	constexpr matrix operator*=(const matrix rhs) {
		assert((*this)[0].size() == rhs.mat.size());
		matrix c((*this).mat.size(), rhs[0].size());
		for(size_t i = 0;i < (*this).mat.size();i++){
			for(size_t k = 0;k < rhs.mat.size();k++){
				for(size_t j = 0;j < rhs[0].size();j++){
					c[i][j] += (*this)[i][k]*rhs[k][j];
				}
			}
		}
		return (*this) = c;
	}	
	
	matrix power(ll k) {
		assert(mat.size() == mat[0].size());
		matrix<T> b(mat.size(), mat[0].size());
		for(size_t i = 0;i < b.mat.size();i++){
			b[i][i] = 1;
		}

		while(k){
			if(k & 1){
				b *= (*this);
			}
			(*this) *= (*this);
			k >>= 1;
		}
		return b;
	}
};

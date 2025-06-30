
#pragma once

#include<cassert>
#include<vector>

template<typename T>
struct matrix {
	std::vector<std::vector<T>> a;

	matrix(){}
	matrix(int n, int m) : a(n, std::vector<T>(m, 0)){}
	matrix(int n) : a(n, std::vector<T>(n, 0)){}

	size_t height() const {return a.size(); }
	size_t width() const {return a[0].size(); }

	const std::vector<T> &operator[](int k) const {return a.at(k); }
	std::vector<T> &operator[](int k) {return a.at(k); }

	static matrix I(size_t n){
		matrix mat(n);
		for(size_t i = 0;i < n;i++){
			mat[i][i] = 1;
		}
		return mat;
	}

	matrix &operator+=(const matrix &b){
		size_t n = height(), m = width();
		assert(n == b.height() && m == b.width());
		for(size_t i = 0;i < n;i++){
			for(size_t j = 0;j < m;j++){
				(*this)[i][j] += b[i][j];
			}
		}
		return *this;
	}

	matrix &operator-=(const matrix &b){
		size_t n = height(), m = width();
		assert(n == b.height() && m == b.width());
		for(size_t i = 0;i < n;i++){
			for(size_t j = 0;j < m;j++){
				(*this)[i][j] -= b[i][j];
			}
		}
		return *this;
	}

	matrix &operator*=(const matrix &b){
		size_t n = height(), m = b.width(), p = width();
		assert(p == b.height());
		matrix c(n, m);
		for(size_t i = 0;i < n;i++){
			for(size_t k = 0;k < p;k++){
				for(size_t j = 0;j < m;j++){
					c[i][j] += (*this)[i][k] * b[k][j];
				}
			}
		}
		a.swap(c.a);
		return *this;
	}

	matrix &operator*=(const T &x){
		size_t n = height(), m = width();
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				(*this)[i][j] *= x;
			}
		}
		return *this;
	}

	matrix operator+(const matrix &b) const {return matrix(*this) += b; }
	matrix operator-(const matrix &b) const {return matrix(*this) -= b; }
	matrix operator*(const matrix &b) const {return matrix(*this) *= b; }
	matrix operator*(const T &x) const {return matrix(*this) *= x; }
};

template<typename T>
matrix<T> matrix_power(matrix<T> a, long long k){
	assert(a.height() == a.width());
	matrix<T> ret = matrix<T>::I(a.height());
	while(k > 0){
		if(k & 1)ret *= a;
		a = a*a;
		k >>= 1;
	}
	return ret;
}

#include<bits/stdc++.h>
using namespace std;

constexpr double EPS = 1e-7;

inline bool equal(const double &a, const double &b) {
	return fabs(a - b) < EPS;
}

template<typename T> struct Point {
public:
	complex<T> p;

	Point(T x=0, T y=0) : p(x, y) {}

	T& x() { return reinterpret_cast<T*>(&p)[0]; }
	T& y() { return reinterpret_cast<T*>(&p)[1]; }

	const T& x() const { return reinterpret_cast<const T*>(&p)[0]; }
	const T& y() const { return reinterpret_cast<const T*>(&p)[1]; }

	// point 同士の演算
	constexpr Point operator+(const Point rhs) const {
		return Point(this->x() + rhs.x(), this->y() + rhs.y());
	}
	constexpr Point operator-(const Point rhs) const {
		return Point(this->x() - rhs.x(), this->y() - rhs.y());
	}
	constexpr Point operator*(const Point rhs) const {
		return Point(this->x() * rhs.x() - this->y() * rhs.y(), this->x() * rhs.y() + this->y() * rhs.x());
	}
	constexpr Point operator/(const Point rhs) const {
		assert(not equal(0.0, rhs.abs()));
		return Point(this->x() * rhs.x() + this->y() * rhs.y(), rhs.x() * this->y() - this->x() * rhs.y()) / (rhs.abs()*rhs.abs());
	}

	// point を定数倍する
	constexpr Point operator*(const double rhs) const {
		assert(not equal(0.0, rhs));
		return Point(this->x() * rhs, this->y() * rhs);
	}
	constexpr Point operator/(const double rhs) const {
		assert(not equal(0.0, rhs));
		return Point(this->x() / rhs, this->y() / rhs);
	}

	// 絶対値
	double abs() const {
		return std::abs(p);
	}

	// 単位ベクトル
	Point get_unit_vector() const {
		double mag = this->abs();
		assert(not equal(0.0, mag));
		return *this / mag;
	}

	// 法線ベクトル
	Point get_normal_vector() const {
		// 90度回転した単位ベクトルをかける
		// TODO: どっちの方向に回転したいかを呼べるようにする
		return (*this * Point(0.0, 1.0)).get_unit_vector();
	}

	// 反時計回りにθ回転
	// θはラジアン
	Point rotate(const double &theta) {
		return Point(cos(theta)*this->x() - sin(theta)*this->y(), sin(theta)*this->x() + cos(theta)*this->y());
	}

	// デバッグ用出力
	friend std::ostream& operator<<(std::ostream& os, const Point& rhs) {
		os << "(" <<  rhs.x() << ", " << rhs.y() << ")";
		return os;
	}
};
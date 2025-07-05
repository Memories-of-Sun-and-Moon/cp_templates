#pragma once

#include<cstdint>
#include<iostream>

class dynamic_modint {
	using u64 = std::uint_fast64_t;
	static u64 Modulus;
public:
	u64 a;
	static void set_mod(u64 m) { Modulus = m; }

	u64 &value() { return a; }
	dynamic_modint(u64 x = 0) : a(x % Modulus) {}
	dynamic_modint operator+(const dynamic_modint rhs) const {
		return dynamic_modint(*this) += rhs;
	}
	dynamic_modint operator-(const dynamic_modint rhs) const {
		return dynamic_modint(*this) -= rhs;
	}
	dynamic_modint operator*(const dynamic_modint rhs) const {
		return dynamic_modint(*this) *= rhs;
	}
	dynamic_modint operator/(const dynamic_modint rhs) const {
		return dynamic_modint(*this) /= rhs;
	}
	dynamic_modint &operator+=(const dynamic_modint rhs) {
		a += rhs.a;
		if (a >= Modulus) {
			a -= Modulus;
		}
		return *this;
	}
	dynamic_modint &operator-=(const dynamic_modint rhs) {
		if (a < rhs.a) {
			a += Modulus;
		}
		a -= rhs.a;
		return *this;
	}
	dynamic_modint &operator*=(const dynamic_modint rhs) {
		a = a * rhs.a % Modulus;
		return *this;
	}
	dynamic_modint &operator/=(dynamic_modint rhs) {
		u64 exp = Modulus - 2;
		while (exp) {
			if (exp % 2) {
				*this *= rhs;
			}
			rhs *= rhs;
			exp /= 2;
		}
		return *this;
	}

	constexpr dynamic_modint& operator++() noexcept {
		if (++a == Modulus) a = 0;
		return *this;
	}
	constexpr dynamic_modint operator++(int) noexcept {
		dynamic_modint tmp(*this);
		++(*this);
		return tmp;
	}
	constexpr dynamic_modint& operator--() noexcept {
		if (a == 0) a = Modulus;
		--a;
		return *this;
	}
	constexpr dynamic_modint operator--(int) noexcept {
		dynamic_modint tmp(*this);
		--(*this);
		return tmp;
	}

	friend std::ostream& operator<<(std::ostream& os, const dynamic_modint& rhs) {
		os << rhs.a;
		return os;
	}
};

inline dynamic_modint::u64 dynamic_modint::Modulus = 1;

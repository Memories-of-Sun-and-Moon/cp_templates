#pragma once

#include<cstdint>
#include<iostream>

template <std::uint_fast64_t Modulus> class modint {
	using u64 = std::uint_fast64_t;
public:
	u64 a;
	constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
	constexpr u64 &value() noexcept { return a; }
	constexpr const u64 &value() const noexcept { return a; }
	constexpr modint operator+(const modint rhs) const noexcept {
		return modint(*this) += rhs;
	}
	constexpr modint operator-(const modint rhs) const noexcept {
		return modint(*this) -= rhs;
	}
	constexpr modint operator*(const modint rhs) const noexcept {
		return modint(*this) *= rhs;
	}
	constexpr modint operator/(const modint rhs) const noexcept {
		return modint(*this) /= rhs;
	}
	constexpr modint &operator+=(const modint rhs) noexcept {
		a += rhs.a;
		if (a >= Modulus) {
			a -= Modulus;
		}
		return *this;
	}
	constexpr modint &operator-=(const modint rhs) noexcept {
		if (a < rhs.a) {
			a += Modulus;
		}
		a -= rhs.a;
		return *this;
	}
	constexpr modint &operator*=(const modint rhs) noexcept {
		a = a * rhs.a % Modulus;
		return *this;
	}
	constexpr modint &operator/=(modint rhs) noexcept {
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

	constexpr modint& operator++() noexcept {
		if (++a == Modulus) a = 0;
		return *this;
	}
	constexpr modint operator++(int) noexcept {
		modint tmp(*this);
		++(*this);
		return tmp;
	}
	constexpr modint& operator--() noexcept {
		if (a == 0) a = Modulus;
		--a;
		return *this;
	}
	constexpr modint operator--(int) noexcept {
		modint tmp(*this);
		--(*this);
		return tmp;
	}

	friend std::ostream& operator<<(std::ostream& os, const modint& rhs) {
		os << rhs.a;
		return os;
	}
};

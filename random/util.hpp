#pragma once

#include<cstdint>
#include<numeric>

/*
# rng の定義
xorshift32 rng;

# 整数の一様分布 [a, b]
std::uniform_int_distribution<T> uid(a, b);
T random_number = uid(rng);

# 実数の一様分布 [a, b)
std::uniform_real_distribution<T> uid(a, b);
T random_number = uid(rng);

# 平均 μ, 標準偏差 σ の正規分布
std::normal_distribution<T> nd(μ, σ)
T random_number = nd(rng);

# n 試行中 p の確率で成功する二項分布の成功した回数(整数)
std::binomial_distribution<T> bd(n, p);
T random_number = bd(rng);
*/
struct xorshift32 {
private:
	uint32_t state;
public:
	xorshift32(uint32_t seed = 33122) : state(seed) {}

	static constexpr uint32_t min() { return 0; }
	static constexpr uint32_t max() { return std::numeric_limits<uint32_t>::max(); }

	uint32_t operator()() {
		state ^= state << 13;
		state ^= state >> 17;
		state ^= state << 5;
		return state;
	}
};

/*
# rng の定義
xorshift32 rng;

# 整数の一様分布 [a, b]
std::uniform_int_distribution<T> uid(a, b);
T random_number = uid(rng);

# 実数の一様分布 [a, b)
std::uniform_real_distribution<T> uid(a, b);
T random_number = uid(rng);

# 平均 μ, 標準偏差 σ の正規分布
std::normal_distribution<T> nd(μ, σ)
T random_number = nd(rng);

# n 試行中 p の確率で成功する二項分布の成功した回数(整数)
std::binomial_distribution<T> bd(n, p);
T random_number = bd(rng);
*/
struct xorshift64 {
private:
	uint64_t state;
public:
	xorshift64(uint64_t seed = 33122) : state(seed) {}

	static constexpr uint64_t min() { return 0; }
	static constexpr uint64_t max() { return std::numeric_limits<uint64_t>::max(); }

	uint64_t operator()() {
		state ^= state << 13;
		state ^= state >> 7;
		state ^= state << 17;
		return state;
	}
};


#pragma once

#include<bitset>
#include<cstdint>

template<typename Key, typename Val, uint32_t N, typename HashFunc = std::hash<Key>>
struct hash_map {
	static_assert(__builtin_popcount(N) == 1);
	Key key[N];
	Val val[N];
	std::bitset<N> use;
	
	static constexpr uint32_t shift = 64 - __builtin_ctz(N);
	static constexpr uint64_t r = 11995408973635179863ULL;

	Val& operator[](const Key & k) noexcept {
		uint64_t h = HashFunc{}(k);
		uint32_t hash = (h*r) >> shift;
		while(true){
			if(!use[hash]){
				key[hash] = k;
				use[hash] = 1;
				return val[hash];
			}
			if(key[hash] == k)return val[hash];
			(++hash) &= (N-1);
		}
	}
};

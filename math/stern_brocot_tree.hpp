#pragma once

#include<algorithm>
#include<optional>
#include<ranges>
#include<tuple>
#include<vector>

namespace sbt{

	template<class T>
	std::tuple<T, T, T, T> child(T p, T q, T r, T s, T d, bool is_left){
		if(is_left){
			r += d*p;
			s += d*q;
		}else{
			p += d*r;
			q += d*s;
		}
		return std::make_tuple(p, q, r, s);
	}

	template<class T>
	std::tuple<T, T, T, T> parent(T p, T q, T r, T s){
		if(p == 0 && q == 1 && r == 1 && s == 0){
			return std::make_tuple(0, 0, 0, 0);
		}
		if(p < r || q < s){
			r -= p, s -= q;
		}else{
			p -= r, q -= s;
		}
		return std::make_tuple(p, q, r, s);
	}

	template<class T>
	std::vector<T> encode_path(T p, T q){
		std::vector<T> a;
		if(p < q){
			a.emplace_back(0);
			std::swap(p, q);
		}
		while(p != 1){
			a.emplace_back(p/q);
			p %= q;
			std::swap(p, q);
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
	std::tuple<T, T, T, T> decode_path(const std::vector<T> &a){
		T p = 0, q = 1, r = 1, s = 0;
		for(int i = 0;i < std::ssize(a);i++){
			std::tie(p, q, r, s) = child(p, q, r, s, a[i], i&1);
		}
		return std::make_tuple(p, q, r, s);
	}

	template<class T>
	std::tuple<T, T, T, T> lca(T p, T q, T r, T s){
		std::vector<T> a = encode_path(p, q), b = encode_path(r, s);

		int n = std::min(std::ssize(a), std::ssize(b));

		T P = 0, Q = 1, R = 1, S = 0;
		for(int i = 0;i < n;i++){
			T c = std::min(a[i], b[i]);
			std::tie(P, Q, R, S) = child(P, Q, R, S, c, i&1);
			if(a[i] != b[i])break;
		}
		return std::make_tuple(P, Q, R, S);
	}

	template<class T>
	std::optional<std::tuple<T, T, T, T>> ancestor(T p, T q, T d){
		std::vector<T> a = encode_path(p, q);
		T P = 0, Q = 1, R = 1, S = 0;
		for(int i = 0;i < std::ssize(a);i++){
			T c = std::min(d, a[i]);
			std::tie(P, Q, R, S) = child(P, Q, R, S, c, i&1);
			d -= c;
			if(d == 0)break;
		}
		if(d == 0){
			return std::make_tuple(P, Q, R, S);
		}
		return std::nullopt;
	}

	template<class T>
	std::tuple<T, T, T, T> range(T p, T q){
		return decode_path(encode_path(p, q));
	}
}

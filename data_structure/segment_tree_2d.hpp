#pragma once
#include<bits/stdc++.h>
using namespace std;

template<typename T>struct segment_tree_2d {
	using F = function<T(T, T)>;
	int id(int r, int c) const {return r*2*w+c; }

	int h, w;
	vector<T> node;
	F combine;
	T identify;

	segment_tree_2d(int _h, int _w, F _combine, T _identify) : combine(_combine), identify(_identify){
		h = w = 1;
		while(h < _h) h <<= 1;
		while(w < _w) w <<= 1;
		node.assign(4*h*w, identify);
	}

	segment_tree_2d(vector<vector<T>> &v, F _combine, T _identify) : combine(_combine), identify(_identify){
		h = w = 1;
		while(h < (int)v.size()) h <<= 1;
		while(w < (int)v[0].size()) w <<= 1;
		node.assign(4*h*w, identify);
		for(int i = 0;i < (int)v.size(); i++){
			for(int j = 0;j < (int)v[0].size();j++){
				node[id(i+h-1, j+w-1)] = v[i][j];
			}
		}
		for(int i = 2*h-2; i > h-2;i--){
			for(int j = w-2; j >= 0;j--){
				node[id(i, j)] = combine(node[id(i, 2*j+1)], node[id(i, 2*j+2)]);
			}
		}
		for(int i = h-2;i >= 0;i--){
			for(int j = 0;j < 2*w-1;j++){
				node[id(i, j)] = combine(node[id(2*i+1, j)], node[id(2*i+2, j)]);
			}
		}
	}

	void set(int y, int x, T val){
		y += h-1;
		x += w-1;
		node[id(y, x)] = val;

		for(int j = (x+1)/2-1;j >= 0;j = (j+1)/2-1){
			node[id(y, j)] = combine(node[id(y, 2*j+1)], node[id(y, 2*j+2)]);
		}

		for(int i = (y+1)/2-1;i >= 0;i = (i+1)/2-1){
			for(int j = x;j >= 0;j = (j+1)/2-1){
				node[id(i, j)] = combine(node[id(2*i+1, j)], node[id(2*i+2, j)]);
			}
		}
	}

	T get(int y, int x){
		return node[id(y+h-1, x+w-1)];
	}

	T fold(int li, int lj, int ri, int rj){
		return fold_h(li, lj, ri, rj);
	}

	T fold_h(int li, int lj, int ri, int rj, int k=0, int si=0, int ti=-1){
		if(ti<0)ti = h;

		if(ri <= si || ti <= li)return identify;
		if(li <= si && ti <= ri)return fold_w(lj, rj, k);
		T vs = fold_h(li, lj, ri, rj, 2*k+1, si, (si+ti)/2);
		T vt = fold_h(li, lj, ri, rj, 2*k+2, (si+ti)/2, ti);
		return combine(vs, vt);
	}

	T fold_w(int lj, int rj, int i, int k=0, int sj=0, int tj=-1){
		if(tj<0) tj = w;

		if(rj <= sj || tj <= lj)return identify;
		if(lj <= sj && tj <= rj)return node[id(i, k)];
		T vs = fold_w(lj, rj, i, 2*k+1, sj, (sj+tj)/2);
		T vt = fold_w(lj, rj, i, 2*k+2, (sj+tj)/2, tj);
		return combine(vs, vt);
	}
};


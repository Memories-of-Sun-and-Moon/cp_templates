
#pragma once

#include<unordered_set>

template<typename T>
T generalized_discrete_logarithm(T x, T y, auto f, int n, auto f_m, int m){
	if(x == y){
		return 0;
	}

	std::unordered_set<T> baby_steps;
	T fy = y;
	for(int i = 0;i < m;i++){
		baby_steps.insert(fy);
		fy = f(fy);
	}

	T fx = x;
	bool is_first_loop = true;
	for(int i = 0;i <= n;i += m){
		T next_val = f_m(fx);
		if(baby_steps.contains(next_val)){
			for(int j = i+1;j <= i+m;j++){
				fx = f(fx);
				if(fx == y){
					return (j <= n ? j : -1);
				}
			}
			if(is_first_loop){
				is_first_loop = false;
			}else{
				return -1;
			}
		}
		fx = next_val;
	}
	return -1;
}

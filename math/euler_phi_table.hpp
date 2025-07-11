#pragma once

#include<vector>

std::vector<int> euler_phi_table(int n){
	std::vector<int> phi(n + 1);
	for(int i = 0;i <= n;i++){
		phi[i] = i;
	}
	for(int i = 2;i <= n;i++){
		if(phi[i] == i){
			for(int j = i;j <= n;j += i){
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}
	return phi;
}

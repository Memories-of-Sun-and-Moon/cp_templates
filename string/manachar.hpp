#pragma once

#include<string>
#include<vector>

std::vector<int> manachar(std::string _s){
	std::string t = "";
	int n = (int)_s.size();
	for(int i = 0;i < n;i++){
		if(i)t += '#';
		t += _s[i];
	}
	n = (int)t.size();
	int i = 0, j = 0;
	std::vector<int> r(n);
	while(i < n){
		while(i-j >= 0 && i+j < n && t[i-j] == t[i+j]) j++;
		r[i] = j;
		int k = 1;
		while(i-k >= 0 && k+r[i-k] < j) r[i+k] = r[i-k], k++;
		i += k, j -= k;
	}
	for(int k = 0;k < n;k++){
		if(k&1)r[k] >>= 1;
		else r[k] = (r[k]+1) >> 1;
	}
	return r;
}

/*
int i = 0, j = 0;
while (i < S.size()) {
  while (i-j >= 0 && i+j < S.size() && S[i-j] == S[i+j]) ++j;
  R[i] = j;
  int k = 1;
  while (i-k >= 0 && k+R[i-k] < j) R[i+k] = R[i-k], ++k;
  i += k; j -= k;
}
*/

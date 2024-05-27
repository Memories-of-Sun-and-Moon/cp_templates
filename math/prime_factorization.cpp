# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_A"
#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> prime_factorization(int val){
	assert(val >= 1);
	if(val == 1){
		return {};
	}
	vector<pair<int,int>> ans;
    int idx = 0;
	for(int i = 2;i * i <= val;i++){
		if(val % i != 0)continue;
		ans.push_back({i, 0});
		while(val % i == 0){
			ans[idx].second++;
			val /= i;
		}
        idx++;
	}
	if(val != 1) ans.push_back({val, 1});
	return ans;
}

int n;

int main(){
    cin >> n;
    auto ret = prime_factorization(n);
    cout << n << ":";
    for(int i = 0;i < (int)ret.size();i++){
        for(int j = 0;j < ret[i].second;j++)cout << " " << ret[i].first;
    }
    cout << endl;
}
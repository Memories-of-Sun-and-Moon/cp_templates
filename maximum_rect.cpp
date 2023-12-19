#include "bits/stdc++.h"
using namespace std;

using ll = long long;

ll maximum_rect(vector<ll> a){
	int n = (int)a.size();
	vector<ll> l(n), r(n);
	{
		stack<ll> st;
		for(int i = 0;i < n;i++){
			while(not st.empty() && a[st.top()] >= a[i])st.pop();
			l[i] = (st.empty() ? 0 : st.top() + 1);
			st.push(i);
		}
	}
	{
		stack<ll> st;
		for(int i = n - 1;i >= 0;i--){
			while(not st.empty() && a[st.top()] >= a[i])st.pop();
			r[i] = (st.empty() ? n : st.top());
			st.push(i);
		}
	}
	ll ans = 0;
	for(int i = 0;i < n;i++)ans = max(ans, a[i] * (r[i] - l[i]));
	return ans;
}
#include<bits/stdc++.h>
using namespace std;

// thx https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/lis

template <bool is_strict, class T> int LIS(const vector<T>& v){
    vector<T> dp;

    auto it = dp.begin();

    for(auto elem : v){
        if constexpr (is_strict){
            it = lower_bound(dp.begin(), dp.end(), elem);
        }else{
            it = upper_bound(dp.begin(), dp.end(), elem);
        }
        if(it == dp.end()){
            dp.push_back(elem);
        }else{
            *it = elem;
        }
    }

    return int(dp.size());
}

int main(){

    vector<int> v = {1, 3, 4, 4 ,5, 8, 3};

    // true: 狭義単調増加
    cout << LIS<true>(v) << endl;
    // false: 広義単調増加
    cout << LIS<false>(v) << endl;

}
template <bool is_strict, class T>
int longest_increasing_subsequences(const vector<T>& v){
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


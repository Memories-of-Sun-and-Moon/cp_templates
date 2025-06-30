
#include<algorithm>
#include<iterator>

// https://qiita.com/mdstoy/items/39104b686540c5f1dc6c
template <typename T> bool next_combination(const T first, const T last, int k) {
	const T subset = first + k;
	// empty container | k = 0 | k == n 
	if (first == last || first == subset || last == subset) {
		return false;
	}
	T src = subset;
	while (first != src) {
		src--;
		if (*src < *(last - 1)) {
			T dest = subset;
			while (*src >= *dest) {
				dest++;
			}
			iter_swap(src, dest);
			rotate(src + 1, dest + 1, last);
			rotate(subset, subset + (last - dest) - 1, last);
			return true;
		}
	}
	// restore
	rotate(first, subset, last);
	return false;
}



#include<istream>
#include<ostream>
#include<algorithm>

std::ostream& operator<<(std::ostream& os, __int128_t value) {
	if (value == 0) return os << '0';
	bool neg = false;
	if (value < 0) {
		neg = true;
		value = -value;
	}
	std::string s;
	while (value > 0) {
		s += '0' + value % 10;
		value /= 10;
	}
	if (neg) s += '-';
	std::reverse(s.begin(), s.end());
	return os << s;
}
std::istream& operator>>(std::istream& is, __int128_t& value) {
	std::string s;
	is >> s;
	value = 0;
	bool neg = false;
	size_t i = 0;
	if (s[0] == '-') {
		neg = true;
		i = 1;
	}
	for (; i < s.size(); ++i) {
		value = value * 10 + (s[i] - '0');
	}
	if (neg) value = -value;
	return is;
}
using bint = __int128_t;

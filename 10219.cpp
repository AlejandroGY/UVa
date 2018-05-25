#include <bits/stdc++.h>

std::string to_string(__uint128_t n) {
	std::string res;
	
	do {
		res += '0' + n % 10;
		n /= 10;
	} while (n != 0);
	
	std::reverse(res.begin( ), res.end( ));
	return res;
}

__uint128_t binomial(__uint128_t n, __uint128_t k) {
	__uint128_t res = 1, q = std::min(k, n - k);

	for (__uint128_t i = 0; i < k; ++i) {
		res *= (n - i);
		res /= (i + 1);
	}
	return res;
}

int main( ) {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int n, k;
	while (std::cin >> n >> k) {
		__uint128_t res = binomial(n, k);
		std::string ss(to_string(res));
		std::cout << ss.size( ) << "\n";
	}
}

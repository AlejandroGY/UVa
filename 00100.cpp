#include <cstdio>
#include <algorithm>
#define ull unsigned long long int
using namespace std;
 
int memo[1000000];

int f(ull n) {
	if(n == 1) return 1;
	int r = 0;
	while(n >= 1000000) {
		n = (n % 2 == 0 ? n / 2 : 3 * n + 1);
		r++;
	}
	if(memo[n] == 0) memo[n] = (n % 2 == 0 ? f(n / 2) : f(3 * n + 1)) + 1;
	return memo[n] + r;
}
 
int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) == 2) {
		int res = 0;
		printf("%d %d ", n, m);
		if (n > m) {
			std::swap(n, m);
		}
		for(int i = n; i <= m; ++i) {
			res = max(res, f(i));
		}
		printf("%d\n", res);
	}
}

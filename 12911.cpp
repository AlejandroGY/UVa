#include <bits/stdc++.h>

void subsetSums(long long arr[], int n, std::vector<long long>& v) {
    long long total = (1 << n);
    for (long long i = 0; i < total; ++i) {
        long long sum = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                sum += arr[j];
            }
        }
        v.push_back(sum);
    }
}

int main( ) {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long n, t;
    while (std::cin >> n >> t) {
        int an = (n / 2), bn = (n / 2) + (n & 1);

        long long a[an], b[bn];
        for (int i = 0; i < an; ++i) {
            std::cin >> a[i];
        }
        for (int i = 0; i < bn; ++i) {
            std::cin >> b[i];
        }

        std::vector<long long> suma_a, suma_b;
        subsetSums(a, an, suma_a);
        subsetSums(b, bn, suma_b);

        std::sort(suma_a.begin( ), suma_a.end( ));
        std::sort(suma_b.begin( ), suma_b.end( ));

        long long res = 0;
        for (int i = 0; i < suma_a.size( ); ++i) {
            long long falta = t - suma_a[i];
            auto ini_a = std::lower_bound(suma_a.begin( ), suma_a.end( ), suma_a[i]);
            auto fin_a = std::upper_bound(suma_a.begin( ), suma_a.end( ), suma_a[i]);
            auto ini_b = std::lower_bound(suma_b.begin( ), suma_b.end( ), falta);
            auto fin_b = std::upper_bound(suma_b.begin( ), suma_b.end( ), falta);

            res += (fin_a - ini_a) * (fin_b - ini_b);
            i += (fin_a - ini_a - 1);
        }
        std::cout << res - (t == 0) << "\n";
    }
}

#include<bits/stdc++.h>

using ll = long long;
constexpr ll MAX = 100010;

int main( ) {
   std::ios_base::sync_with_stdio(0);
   std::cin.tie(0);
   std::cout.tie(0);

   int n, m;
   while (std::cin >> n >> m) {
      std::pair<int, int> arr[n];
      for (int i = 1; i <= n; ++i) {
         std::cin >> arr[i - 1].first;
         arr[i - 1].second = i;
      }
      std::sort(arr, arr + n);

      for (int i = 0; i < m; ++i) {
         int k, v;
         std::cin >> k >> v;
         auto it = std::lower_bound(arr, arr + n, std::make_pair(v, 0)) - arr;
         if (it < n && arr[it].first == v && (it + k - 1) < n && arr[it + k - 1].first == v) {
            std::cout << arr[it + k - 1].second << "\n";
         } else {
            std::cout << "0\n";
         }
      }
   }
}

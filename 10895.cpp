#include <bits/stdc++.h>

int main( ) {
   std::ios_base::sync_with_stdio(0);
   std::cin.tie(0), std::cout.tie(0);

   int m, n;
   while (std::cin >> m >> n) {
      int* matriz = new int[m * n + 1];
      for (int i = 0, idx = 0; i < m; ++i, idx += n) {
         int r;
         std::cin >> r;

         int pos[r + 1];
         for (int j = 1; j <= r; ++j) {
            std::cin >> pos[j];
         }

         for (int j = 1; j <= r; ++j) {
            int val;
            std::cin >> val;
            matriz[idx + pos[j]] = val;
         }
      }

      std::cout << n << " " << m << "\n";
      for (int i = 1; i <= n; ++i) {
         std::vector<std::pair<int, int>> pos;
         for (int j = 1, idx = 0; j <= m; ++j, idx += n) {
            if (matriz[i + idx]) {
               pos.push_back({ j, matriz[i + idx] });
            }
         }

         int tam = pos.size( );
         std::cout << tam;
         if (tam == 0) {
            std::cout << "\n\n";
            continue;
         }

         int k = 0;
         std::cout << " ";
         for (auto act : pos) {
            std::cout << act.first;
            std::cout << (k < tam - 1 ? " " : "\n");
            k += 1;
         }

         int q = 0;
         for (auto act : pos) {
            std::cout << act.second;
            std::cout << (q < tam - 1 ? " " : "\n");
            q += 1;
         }
      }
   }
}

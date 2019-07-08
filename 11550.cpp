#include<bits/stdc++.h>

using ll = long long;

int main( ) {
   std::ios_base::sync_with_stdio(0);
   std::cin.tie(0);
   std::cout.tie(0);

   int t;
   std::cin >> t;
   while (t--) {
      int n, m;
      std::cin >> n >> m;

      int mat[n][m];
      for (int i = 0; i < n; ++i) {
         for (int j = 0; j < m; ++j) {
            std::cin >> mat[i][j];
         }
      }

      bool check = true;
      int memo[10][10] = { };
      for (int i = 0; i < m; ++i) {
         int x, y;
         int cont = 0;
         for (int j = 0; j < n; ++j) {
            if (mat[j][i]) {
               if (cont == 0) x = j;
               else y = j;
               cont += 1;
            }
         }

         if (cont != 2) {
            check = false;
         } else {
            if (memo[x][y]) check = false;
            memo[x][y] = memo[y][x] = 1;
         }
      }
      std::cout << (check == false ? "No\n" : "Yes\n");
   }
}

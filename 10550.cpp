#include <bits/stdc++.h>

int main( ) {
   std::ios_base::sync_with_stdio(0);
   std::cin.tie(0), std::cout.tie(0);
   int n, a, b, c;
   while (std::cin >> n >> a >> b >> c, n || a || b || c) {
      int giros = 80, pos = n;
      if (pos > a && pos != 0) {
         giros += pos - a;
      } else {
         giros += (40 - a) + pos;
      }
      pos = a;

      giros += 40;
      if (b > pos) {
         giros += (b - pos);
      } else {
         giros += (40 - pos) + b;
      }
      pos = b;

      if (pos > c && pos != 0) {
         giros += pos - c;
      } else {
         giros += (40 - c) + pos;
      }

      std::cout << (giros * 360) / 40 << "\n";
   }
}

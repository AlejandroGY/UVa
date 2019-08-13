#include <bits/stdc++.h>

struct union_find {
   std::vector<int> p, tam;

   union_find(int n) {
      p.resize(2 * n + 1), tam.resize(2 * n + 1);
      std::iota(p.begin( ), p.end( ), 0);
      std::fill(tam.begin( ), tam.end( ), 1);
   }
   int find(int a) {
      return (p[a] == a ? a : p[a] = find(p[a]));
   }
   bool same_set(int a, int b) {
      return find(a) == find(b);
   }
   void join(int a, int b) {
      if (!same_set(a, b)) {
         int ra = find(a), rb = find(b);
         p[ra] = p[rb];
         tam[rb] += tam[ra];
      }
   }
};

int main( ) {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(nullptr), std::cout.tie(nullptr);

   int n;
   std::cin >> n;
   union_find uf(n);

   int c, a, b;
   while (std::cin >> c >> a >> b, c || a || b) {
      if (c == 1) { //setFriends
         if (uf.find(a) == uf.find(b + n) || uf.find(b) == uf.find(a + n)) {
            std::cout << "-1\n";
         } else {
            uf.join(a, b);
            uf.join(a + n, b + n);
         }
      } else if (c == 2) { //setEnemies
         if (uf.find(a) == uf.find(b) || uf.find(a + n) == uf.find(b + n)) {
            std::cout << "-1\n";
         } else {
            uf.join(a, b + n);
            uf.join(b, a + n);
         }
      } else if (c == 3) { //areFriends
         std::cout << (uf.find(a) == uf.find(b) || uf.find(a + n) == uf.find(b + n)) << "\n";
      } else if (c == 4) { //areEnemies
         std::cout << (uf.find(a) == uf.find(b + n) || uf.find(a + n) == uf.find(b)) << "\n";
      }
   }
}

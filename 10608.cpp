#include <bits/stdc++.h>

struct union_find {
   std::vector<int> p;
   std::vector<int> tam;

   union_find(int n) {
      p.resize(n + 1);
      tam.resize(n + 1);
      std::iota(p.begin( ), p.end( ), 0);
      std::fill(tam.begin( ), tam.end( ), 1);
   }

   int find(int a) {
      return (p[a] == a ? a : p[a] = find(p[a]));
   }

   void join(int a, int b) {
      if (!same_set(a, b)) {
         int ra = find(a), rb = find(b);
         p[ra] = rb;
         tam[rb] += tam[ra];
      }
   }

   bool same_set(int a, int b) {
      return find(a) == find(b);
   }
};

int main( ) {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(nullptr), std::cout.tie(nullptr);

   int tc;
   std::cin >> tc;

   while (tc--) {
      int n, m;
      std::cin >> n >> m;

      union_find grafo(n);
      for (int i = 0; i < m; ++i) {
         int a, b;
         std::cin >> a >> b;
         grafo.join(a, b);
      }
      std::cout << *std::max_element(grafo.tam.begin( ), grafo.tam.end( )) << "\n";
   }
}

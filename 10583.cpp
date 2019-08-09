#include <bits/stdc++.h>

struct union_find {
   int tam;
   std::vector<int> p;

   union_find(int n) {
      tam = n;
      p.resize(n + 1);
      std::iota(p.begin( ), p.end( ), 0);
   }

   int find(int a) {
      return (p[a] == a ? a : p[a] = find(p[a]));
   }

   void join(int a, int b) {
      if (!same_set(a, b)) {
         tam -= 1;
         p[find(a)] = find(b);
      }
   }

   bool same_set(int a, int b) {
      return find(a) == find(b);
   }
};

int main( ) {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(nullptr), std::cout.tie(nullptr);

   int n, m, caso = 1;
   while (std::cin >> n >> m, n || m) {
      union_find grafo(n);
      for (int i = 0; i < m; ++i) {
         int a, b;
         std::cin >> a >> b;
         grafo.join(a, b);
      }
      std::cout << "Case " << caso++ << ": " << grafo.tam << "\n";
   }
}

#include <bits/stdc++.h>

struct union_find {
   std::vector<int> p, tam;

   union_find(int n) {
      p.resize(n + 1), tam.resize(n + 1);
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

   int t;
   std::cin >> t;
   while (t--) {
      int n;
      std::cin >> n;

      int idx = 0;
      std::map<std::string, int> persona;

      union_find grafo(n);
      for (int i = 0; i < n; ++i) {
         std::string a, b;
         std::cin >> a >> b;
         if (persona.count(a) == 0) persona[a] = idx++;
         if (persona.count(b) == 0) persona[b] = idx++;

         grafo.join(persona[a], persona[b]);
         std::cout << grafo.tam[grafo.find(persona[b])] << "\n";
      }
   }
}

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

   int c, r;
   while (std::cin >> c >> r, c || r) {
      int idx = 0;
      union_find grafo(c);
      std::map<std::string, int> animales;
      for (int i = 0; i < c; ++i) {
         std::string nombre;
         std::cin >> nombre;
         animales[nombre] = idx++;
      }
      for (int i = 0; i < r; ++i) {
         std::string a, b;
         std::cin >> a >> b;
         grafo.join(animales[a], animales[b]);
      }
      std::cout << *std::max_element(grafo.tam.begin( ), grafo.tam.end( )) << "\n";
   }
}

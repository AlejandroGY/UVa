#include <bits/stdc++.h>

struct union_find {
   int sets;
   std::vector<int> p, tam;
   std::set<int> fallen_set[100];

   union_find(int n) {
      sets = n;
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
         sets -= 1;
      }
   }
   void merge(int n) {
      for (int i = 0; i < n; ++i) {
         for (int j = i + 1; j < n; ++j) {
            if (!same_set(i, j)) {
               std::vector<int> res;
               std::set_symmetric_difference(fallen_set[i].begin( ), fallen_set[i].end( ), fallen_set[j].begin( ), fallen_set[j].end( ), std::back_inserter(res));
               if (res.empty( )) {
                  join(i, j);
               }
            }
         }
      }
   }
};

int main( ) {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(nullptr), std::cout.tie(nullptr);

   int t;
   std::cin >> t;
   for (int tc = 0; tc < t; ++tc) {
      int P, T;
      std::cin >> P >> T;

      union_find uf(P);
      std::string linea;
      std::getline(std::cin, linea);
      std::getline(std::cin, linea);
      while (linea.size( ) != 0) {
         std::stringstream ss(linea);
         int persona, arbol;
         ss >> persona;
         ss >> arbol;
         uf.fallen_set[persona - 1].insert(arbol);
         std::getline(std::cin, linea);
      }
      uf.merge(P);
      std::cout << uf.sets << "\n";
      std::cout << (tc + 1 < t ? "\n" : "");
   }
}

#include <bits/stdc++.h>

struct UnionFind {
   int n;
   std::vector<int> padre, tam;
   UnionFind(int N) : n(N), tam(N, 1), padre(N) {
      while (--N) padre[N] = N;
   }

   int raiz(int u) {
      if (padre[u] == u) return u;
      return padre[u] = raiz(padre[u]);
   }

   bool sonConexos(int u, int v) {
      return raiz(u) == raiz(v);
   }

   void unir(int u, int v) {
      int ru = raiz(u), rv = raiz(v);
      if (ru == rv) return;
      --n, padre[ru] = rv;
      tam[rv] += tam[ru];
   }

   int tamano(int u) {
      return tam[raiz(u)];
   }
};

int main( ) {
   std::ios_base::sync_with_stdio(0);
   std::cin.tie(0), std::cout.tie(0);

   int tc;
   std::cin >> tc;
   std::string linea;
   std::getline(std::cin, linea);
   while (tc--) {
      std::vector<int> adyacencia[26];
      while (std::getline(std::cin, linea)) {
         if (linea[0] == '*') break;
         int a = linea[1] - 'A', b = linea[3] - 'A';
         adyacencia[a].push_back(b);
         adyacencia[b].push_back(a);
      }

      std::vector<int> nodos;
      std::getline(std::cin, linea);
      for (int i = 0; i < linea.size( ); ++i) {
         if (i % 2 == 0) {
            nodos.push_back(linea[i] - 'A');
         }
      }

      UnionFind grafo(26);
      for (int i = 0; i < 26; ++i) {
         for (auto c : adyacencia[i]) {
            if (!grafo.sonConexos(i, c)) {
               grafo.unir(i, c);
            }
         }
      }

      int bosques = 0, bellotas = 0;
      for (int i : nodos) {
         if (grafo.padre[i] == i) {
            bosques += (grafo.tam[i] > 1);
            bellotas += (grafo.tam[i] == 1);
         }
      }
      std::cout << "There are " << bosques << " tree(s) and " << bellotas << " acorn(s).\n";
   }
}

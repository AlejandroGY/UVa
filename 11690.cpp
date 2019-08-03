#include<bits/stdc++.h>

struct UnionFind {
   std::vector<int> p;
   UnionFind(int N) {
      p.assign(N, 0);
      std::iota(p.begin( ), p.end( ), 0);
   }

   int find(int a) {
      return (p[a] == a ? a : p[a] = find(p[a]));
   }

   void join(int a, int b) {
      if (!sameSet(a, b)) {
         p[find(a)] = find(b);
      }
   }

   bool sameSet(int a, int b) {
      return (find(a) == find(b));
   }
};

int main( ) {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(nullptr), std::cout.tie(nullptr);

   int N;
   std::cin >> N;
   for (int tc = 0; tc < N; ++tc) {
      int n, m;
      std::cin >> n >> m;

      int sumas[n];
      for (int i = 0; i < n; ++i) {
         std::cin >> sumas[i];
      }

      UnionFind graph(n);   
      for (int i = 0; i < m; ++i) {
         int x, y;
         std::cin >> x >> y;
         graph.join(x, y);
      }

      std::map<int, int> acum;
      for (int i = 0; i < n; ++i) {
         if (acum.count(graph.find(i)) == 0) {
            acum[graph.find(i)] = sumas[i];
         } else {
            acum[graph.find(i)] += sumas[i];
         }
      }

      bool check = true;
      for (auto it = acum.begin( ); it != acum.end( ); ++it) {
         if (it->second != 0) {
            check = false;
            break;
         }
      }
      std::cout << (check == true ? "POSSIBLE\n" : "IMPOSSIBLE\n");
   }
}

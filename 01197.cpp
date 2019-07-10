#include<bits/stdc++.h>

class UnionFind {
private:
   std::vector<int> p, rank, tam;
   int numSets;
public:
   UnionFind(int N) {
      tam.assign(N, 1); numSets = N; rank.assign(N, 0);
      p.assign(N, 0); std::iota(p.begin( ), p.end( ), 0);
   }
   int find(int a) {
      return (p[a] == a ? a : (p[a] = find(p[a])));
   }
   bool sameSet(int a, int b) {
      return (find(a) == find(b));
   }
   void join(int a, int b) {
      if (!sameSet(a, b)) {
         numSets -= 1;
         int x = find(a), y = find(b);
         if (rank[x] > rank[y]) {
            p[y] = x; tam[x] += tam[y];
         } else {
            p[x] = y; tam[y] += tam[x];
            if (rank[x] == rank[y]) rank[y] += 1;
         }
      }
   }
   int tamSet(int a) {
      return tam[find(a)];
   }
};

int main( ) {
   std::ios_base::sync_with_stdio(0);
   std::cin.tie(0);
   std::cout.tie(0);

   int n, m;
   while (std::cin >> n >> m, n || m) {
      UnionFind uf(n + 1);
      for (int i = 0; i < m; ++i) {
         int num;
         std::cin >> num;

         int arr[num];
         for (int j = 0; j < num; ++j) {
            std::cin >> arr[j];
            if (j) {
               uf.join(arr[j], arr[j - 1]);
            }
         }
      }
      std::cout << uf.tamSet(0) << "\n";
   }
}

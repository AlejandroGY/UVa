#include <bits/stdc++.h>

int main( ) {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(nullptr), std::cout.tie(nullptr);

   int n, m;
   while (std::cin >> n) {
      std::cin >> m;
      
      int idx = 0;
      int num[26] = { };
      bool memo[26] = { };
      std::map<char, int> id;

      std::string inicial;
      std::cin >> inicial;

      id[inicial[0]] = idx++;
      id[inicial[1]] = idx++;
      id[inicial[2]] = idx++;

      num[id[inicial[0]]] = num[id[inicial[1]]] = num[id[inicial[2]]] = 3;
      memo[id[inicial[0]]] = memo[id[inicial[1]]] = memo[id[inicial[2]]] = true;

      bool adj[26][26] = { };
      for (int i = 0; i < m; ++i) {
         char a, b;
         std::cin >> a >> b;
         if (id.count(a) == 0) id[a] = idx++;
         if (id.count(b) == 0) id[b] = idx++;

         adj[id[a]][id[b]] = true;
         adj[id[b]][id[a]] = true;

         if (memo[id[a]] && !memo[id[b]]) {
            num[id[b]] += 1;
         } else if (!memo[id[a]] && memo[id[b]]) {
            num[id[a]] += 1;
         }
      }
      
      int res = 3, years = 0;
      int act = 0, ant = 0;
      do {
         std::vector<int> faltan;
         ant = act;
         for (auto it : id) {
            if (num[it.second] >= 3 && !memo[it.second]) {
               faltan.push_back(it.second);
            }
         }
         for (auto it : faltan) {
            memo[it] = true;
            act += 1;
            res += 1;
            for (int i = 0; i < 26; ++i) {
               if (adj[it][i]) {
                  num[i] += 1;
               }
            }
         }
         years += 1;
      } while (act != ant);
      
      if (res == n) {
         std::cout << "WAKE UP IN, "<< years - 1 << ", YEARS\n";
      } else {
         std::cout << "THIS BRAIN NEVER WAKES UP\n";
      }
   }
}

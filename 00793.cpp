#include<bits/stdc++.h>

std::vector<int> p;
struct solve {
   char tipo;
   int a, b;
   solve(char t, int a1, int b1) : tipo(t), a(a1), b(b1) {
   }
};

solve split(std::string linea) {
   std::string temp[3];
   std::stringstream ss(linea);
   ss >> temp[0];
   ss >> temp[1];
   ss >> temp[2];
   return solve(temp[0][0], std::atoi(temp[1].c_str( )), std::atoi(temp[2].c_str( )));
}

int find(int a) {
   return (p[a] == a ? a : p[a] = find(p[a]));
}
void Union(int a, int b) {
   p[find(a)] = find(b);
}
bool sameSet(int a, int b) {
   return (find(a) == find(b));
}

int main( ) {
   std::ios_base::sync_with_stdio(0);
   std::cin.tie(0);
   std::cout.tie(0);

   int t;
   std::cin >> t;

   for (int tc = 0; tc < t; ++tc) {
      if (tc) {
         std::cout << "\n";
      }

      int n;
      std::cin >> n;
      p.resize(n + 1);
      std::iota(p.begin( ), p.end( ), 0);

      int res[2] = { };

      std::string linea;
      std::getline(std::cin, linea);
      std::getline(std::cin, linea);
      while (linea.size( )) {
         solve s = split(linea);
         if (s.tipo == 'c') {
            Union(s.a, s.b);
         } else {
            bool test = sameSet(s.a, s.b);
            res[test] += 1;
         }
         std::getline(std::cin, linea);
      }
      std::cout << res[1] << "," << res[0] << "\n";
      p.clear( );
   }
}

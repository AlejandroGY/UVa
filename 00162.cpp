#include <bits/stdc++.h>

std::map<char, int> p = {
   { '2', 2 }, { '3', 3 }, { '4', 4 }, { '5', 5 }, { '6', 6 }, { '7', 7 },
   { '8', 8 }, { '9', 9 }, { 'T', 10 }, { 'J', 11 }, { 'Q', 12 }, { 'K', 13 }, { 'A', 14 }
};

bool isFace(int t) {
   return (t >= 11 && t <= 14);
}

void split(std::vector<int>& cards, std::string& line) {
   std::string word;
   std::stringstream ss(line);
   while (ss >> word) cards.push_back(word);
}

int main( ) {
   std::ios_base::sync_with_stdio(0);
   std::cin.tie(0), std::cout.tie(0);

   std::string line;
   while (std::getline(std::cin, line)) {
      if (linea == "#") {
         break;
      } else {
         std::vector<int> cards;
         split(cards, line);
         for (int i = 0; i < 3; ++i) {
            std::getline(std::cin, line)
            split(cards, line);
         }
      }
   }
}

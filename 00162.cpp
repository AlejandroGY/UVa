#include <bits/stdc++.h>

std::map<char, int> p = {
   { '2', 2 }, { '3', 3 }, { '4', 4 }, { '5', 5 }, { '6', 6 }, { '7', 7 },
   { '8', 8 }, { '9', 9 }, { 'T', 10 }, { 'J', 11 }, { 'Q', 12 }, { 'K', 13 }, { 'A', 14 }
};

bool isFace(int t) {
   return t >= 11;
}

void split(std::vector<int>& cards, std::string& line) {
   std::string word;
   std::stringstream ss(line);
   while (ss >> word) {
      cards.push_back(p[word[1]]);
   }
}

int calculate_miss(int type) {
   switch (type) {
   case 11: return 1;
   case 12: return 2;
   case 13: return 3;
   case 14: return 4;
   }
   return 1;
}

std::pair<int, bool> secuence(std::vector<int>& heap, std::deque<int>& A, std::deque<int>& B, int turn, int type) {
   bool end = false;
   int missing = calculate_miss(type);
   while (!end) {
      if (turn == 0) {
         for (int i = 0; i < missing; ++i) {
            if (A.size( ) == 0) {
               return { 1, false };
            }
            int a_front = A.front( );
            heap.push_back(a_front);
            A.pop_front( );
            if (isFace(a_front)) {
               turn = 1;
               end = false;
               missing = calculate_miss(a_front);
               break;
            } else {
               end = true;
            }
         }
      } else if (turn == 1) {
         for (int i = 0; i < missing; ++i) {
            if (B.size( ) == 0) {
               return { 0, false };
            }
            int b_front = B.front( );
            heap.push_back(b_front);
            B.pop_front( );
            if (isFace(b_front)) {
               turn = 0;
               end = false;
               missing = calculate_miss(b_front);
               break;
            } else {
               end = true;
            }
         }
      }
   }
   //std::reverse(heap.begin( ), heap.end( ));
   if (turn == 0) {
      for (int c : heap) {
         B.push_back(c);
      }
   } else {
      for (int c : heap) {
         A.push_back(c);
      }
   }
   heap.clear( );
   return { !turn, true };
}

int main( ) {
   std::ios_base::sync_with_stdio(0);
   std::cin.tie(0), std::cout.tie(0);

   std::string line;
   while (std::getline(std::cin, line)) {
      std::deque<int> Q[2];
      if (line == "#") {
         break;
      } else {
         std::vector<int> cards;
         split(cards, line);
         for (int i = 0; i < 3; ++i) {
            std::getline(std::cin, line);
            split(cards, line);
         }

         for (int i = 0, turn = 0; i < cards.size( ); ++i, turn ^= 1) {
            Q[turn].push_front(cards[i]);
         }

         int turn = 0, idx = 0;
         std::vector<int> heap;
         while (true) {
            if (Q[idx].size( )) {
               int a_front = Q[idx].front( );
               Q[idx].pop_front( );
               heap.push_back(a_front);
               bool enter = false;
               if (isFace(a_front)) {
                  auto r = secuence(heap, Q[0], Q[1], !idx, a_front);
                  if (r.second == false) {
                     break;
                  } else {
                     idx = r.first;
                     enter = true;
                  }
               }
               if (enter == false) idx ^= 1;
            } else {
               break;
            }
         }
      }
      if (Q[0].size( ) == 0) {
         std::printf("%d%3d\n", 1, Q[1].size( ));
      } else {
         std::printf("%d%3d\n", 2, Q[0].size( ));
      }
   }
}

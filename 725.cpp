#include <bits/stdc++.h>

int main( ) {
   int n;
   std::scanf("%d", &n);

   while (n != 0) {
      bool flag = false;
      for (int den = 1234; den <= 98765 / n; ++den) {
         int num = den * n;
         int usados = (den < 10000);

         int t1 = num; while (t1) { usados |= 1 << (t1 % 10); t1 /= 10; }
         int t2 = den; while (t2) { usados |= 1 << (t2 % 10); t2 /= 10; }

         if (usados == (1 << 10) - 1) {
            flag = true;
            std::printf("%0.5d / %0.5d = %d\n", num, den, n);
         }
      }

      if (flag == false) {
         std::printf("There are no solutions for %d.\n", n);
      }

      std::scanf("%d", &n);
      if (n != 0) {
         std::printf("\n");
      }
   }
}
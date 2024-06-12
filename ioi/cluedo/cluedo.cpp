#include "grader.h"
#include "cluedo.h"
void Solve(){
   // int r;
   // r = Theory(1,2,3);
   // if (r == 0) return;
   // r = Theory(3,2,1);
   // if (r == 0) return;
   // r = Theory(4,4,4);
   // if (r == 0) return;

   int r = -1, m = 1, l = 1, w = 1;
   int guess = 0;
   for (;;)
   {
      ++guess;
      r = Theory(m, l, w);
      if (r == 0) 
         break;
      switch (r)
      {
      case 1: ++m; continue;
      case 2: ++l; continue;
      case 3: ++w; continue;
      default:
         break;
      }
   }
}

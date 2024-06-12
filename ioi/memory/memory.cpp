#include "grader.h"
#include "memory.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
using pic = pair<int, char>;
using vp = vector<pic>;

void play() {
   // int i;
   // char a, b;
   // for (i=0; i<10; ++i) {
   //    a = faceup(42);
   //    b = faceup(47);
   // }

   char c;
   int pos;
   vp vc;
   for (pos = 1; pos <= 50; ++pos)
   {
      c = faceup(pos);
      vc.push_back(pic{pos, c});
   }
   sort(vc.begin(), vc.end(), 
        [](const pic& p1, const pic& p2){ return p1.second < p2.second; });
   for (const pic& p: vc)
      faceup(p.first);
}

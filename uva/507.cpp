#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    // FILEIO;
    int b, id = 1;
    scanf(" %d", &b);
    while(b--)
    {
        int s;
        scanf(" %d", &s);
        vector<int> niceness(s - 1);
        for (int i = 0; i < s - 1; ++i)
            scanf(" %d", &niceness[i]);
        
        int maxnice = 0, curnice = 0;
        pair<int, int> maxrange{0, 0}, currange{0, 0};
        for (int i = 0; i < s - 1; ++i)
        {
            currange.second = i + 1;
            curnice += niceness[i];
            bool surpass = false;
            if (curnice > maxnice)
                surpass = true;
            else if (curnice == maxnice)
            {
                if (currange.second - currange.first > maxrange.second - maxrange.first)
                    surpass = true;
                else if (currange.second - currange.first == maxrange.second - maxrange.first)
                    if (currange.first < maxrange.first)
                        surpass = true;
            }
            if (surpass)    
            {
                maxnice = curnice;
                maxrange = currange;
            }
            if (curnice < 0) 
            {
                curnice = 0;
                currange.first = i + 1;
            }
        }

        if (maxnice == 0)
            printf("Route %d has no nice parts\n", id);
        else
            printf("The nicest part of route %d is between stops %d and %d\n", id, maxrange.first + 1, maxrange.second + 1);
        ++id;
    }
        
    return 0;
}

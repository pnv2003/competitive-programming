#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(int argc, char const *argv[])
{
    FASTIO;
    int sz, pos;
    while (cin >> sz >> pos)
    {
        if (sz == 0 && pos == 0) break;

        int curpos = 1;
        int lin = sz/2, col = sz/2;

        const vector<pair<int, int>> dir{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int d = 0, rep = 1;
        while (true)
        {
            if (pos >= curpos && pos <= curpos + rep)
            {
                lin += (pos - curpos) * dir[d].first;
                col += (pos - curpos) * dir[d].second;
                break;
            }
            
            curpos += rep;
            lin += rep * dir[d].first;
            col += rep * dir[d].second;
            d = (d + 1) % 4;
            if (d == 0 || d == 2) ++rep;
        }
        
        cout << "Line = " << sz - lin << ", column = " << col + 1 << ".\n"; 
    }
    
    return 0;
}

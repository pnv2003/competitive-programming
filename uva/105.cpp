#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;
    vector<int> hmap(20000, 0);
    
    int l, h, r, xmin, xmax = 0, in = 0;
    while (cin >> l >> h >> r)
    {
        l*=2; r*=2;
        if (in++ == 0)
            xmin = l;
        xmax = max(xmax, r);
        for (int i = l; i <= r; ++i)
            hmap[i] = max(hmap[i], h);
    }

    int curh = hmap[xmin];
    cout << xmin/2 << " " << curh << " ";
    for (int x = xmin + 1; x <= xmax; ++x)
    {
        int h = hmap[x];
        if (h < curh)
            cout << (x - 1)/2 << " " << h << " ";
        else if (h > curh) 
            cout << x/2 << " " << h << " ";
        curh = h;   
    }    
    cout << xmax/2 << " 0\n";
    return 0;
}

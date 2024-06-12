#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;

    int nstation;
    while (cin >> nstation)
    {
        if (nstation == 0) break;

        vector<int> pos;
        int p;
        while (nstation--)
        {
            cin >> p;
            pos.push_back(p);
        }

        sort(pos.begin(), pos.end());
        int power = 0, loc = 0;
        // forward
        for (int i = 0; i < pos.size(); ++i)
        {
            power -= pos[i] - loc;
            if (power < 0)
                break;
            loc = pos[i];
            power = 200;
        }
        // reached end
        power -= 1422 - loc;
        loc = 1422;

        if (power >= 0) 
        {
            // backward
            for (int i = pos.size() - 1; i >= 0; --i)
            {
                power -= loc - pos[i];
                if (power < 0)
                    break;
                loc = pos[i];
                power = 200;
            }
            // reached begin
            power -= loc;
            loc = 0;
        }
        
        cout << (power < 0 ? "IM" : "") << "POSSIBLE\n";
    }
    
    return 0;
}

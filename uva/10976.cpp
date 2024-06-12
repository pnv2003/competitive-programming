#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;
    const int lim = 100000;
    vector<vector<int>> memo(10000);
    int k;
    while (cin >> k)
    {
        
        vector<int> vy = memo[k];

        if (vy.empty()) 
        {
            for (int y = k + 1; y < lim; ++y)
            {
                int x = floor(k*k*1.0/(y - k) + k);
                if (x == ceil(k*k*1.0/(y - k) + k) && x >= y)
                    vy.push_back(y);
            }
        }

        memo[k] = vy;
        cout << vy.size() << "\n";
        for (int y: vy)
        {
            int x = floor(k*k*1.0/(y - k) + k);
            cout << "1/" << k
                << " = "
                << "1/" << x
                << " + " 
                << "1/" << y << "\n";
        }
    }
    
    return 0;
}

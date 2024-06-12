#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;
    
    int t;
    cin >> t;
    while (t--)
    {
        set<vector<vector<int>>> log;
        vector<vector<int>> grid(3, vector<int>(3, 0));
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
            {
                char ch;
                cin >> ch;
                grid[i][j] = ch - '0';
            }

        int idx = 0;
        auto g = grid;
        bool last = false;
        while (true)
        {
            if (log.find(g) != log.end())
                break;

            ++idx;
            log.insert(g);
            grid = g;
            g.assign(3, vector<int>(3, 0));
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    if (grid[i][j] == 1)
                    {
                        if (i - 1 >= 0) g[i - 1][j] = 1 - g[i - 1][j];
                        if (j - 1 >= 0) g[i][j - 1] = 1 - g[i][j - 1];
                        if (i + 1 < 3)  g[i + 1][j] = 1 - g[i + 1][j];
                        if (j + 1 < 3)  g[i][j + 1] = 1 - g[i][j + 1];
                    }
                }
            }
            if (g == grid)
            {
                last = true;
                break;
            }
        }

        if (last) // duplicate on last
            cout << idx - 2 << "\n";
        else
            cout << idx - 1 << "\n";
    }
    
    return 0;
}

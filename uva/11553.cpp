#include <iostream>
#include <vector>
#include <algorithm>
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
        int n;
        cin >> n;

        vector<vector<int>> grid(n, vector<int>(n, 0));
        vector<int> col; // 0 1 2 .. n-1 (col choice order)
        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j < n; ++j)
                cin >> grid[i][j];
            col.push_back(i);
        }

        int minsum = 9999;

        do
        {
            int sum = 0;
            for (int i = 0; i < n; ++i) 
                sum += grid[i][col[i]];

            minsum = min(minsum, sum);
        } while (next_permutation(col.begin(), col.end()));
        
        cout << minsum << "\n";
    }
    
    return 0;
}

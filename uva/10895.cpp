#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

vector<vector<pair<int, int>>> adjlist;

int main(int argc, char const *argv[])
{
    FASTIO;
    int m, n;
    while (cin >> m >> n)
    {
        adjlist.assign(n, vector<pair<int, int>>());
        for (int v = 0; v < m; ++v)
        {
            int r; cin >> r;
            vector<int> neighbor(r);
            for (int i = 0; i < r; ++i)
            {
                int u;
                cin >> u; u--;
                neighbor[i]= u;
            }
            for (int i = 0; i < r; ++i)
            {
                int w;
                cin >> w;
                adjlist[neighbor[i]].push_back({v, w});
            }
        }

        cout << n << " " << m << "\n";
        for (int u = 0; u < n; ++u)
        {
            cout << adjlist[u].size();
            for (const auto& p: adjlist[u])
                cout << " " << p.first + 1;
            cout << "\n";
            for (int i = 0; i < adjlist[u].size(); ++i)
            {
                cout << adjlist[u][i].second;
                if (i + 1 != adjlist[u].size())
                    cout << " ";
            }
            cout << "\n";
        }
    }
    
    return 0;
}

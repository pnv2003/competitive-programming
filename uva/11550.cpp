#include <iostream>
#include <vector>
#include <set>
#include <utility>
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
        int n, m;
        cin >> n >> m;
        
        vector<pair<int, int>> edges(m, {-1, -1});
        bool check = true;
        for (int v = 0; v < n; ++v)
        {
            for (int e = 0; e < m; ++e)
            {
                int elem;
                cin >> elem;
                if (elem == 1) 
                {
                    if (edges[e].first == -1)
                        edges[e].first = v;
                    else if (edges[e].second == -1)
                        edges[e].second = v;
                    else 
                        check = false;
                }
            }
        }
        
        set<pair<int, int>> checkedge;        
        for (const auto& e: edges)
        {
            if (e.first == -1 || e.second == -1)
                check = false;
            else if (checkedge.count(e))
                check = false;
            else
                checkedge.insert(e);
        }

        check
            ? cout << "Yes\n"
            : cout << "No\n";
    }
    
    return 0;
}
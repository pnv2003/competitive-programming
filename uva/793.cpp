#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

#include <unordered_map>
namespace ufds
{
    std::unordered_map<int, int> parent;
    std::unordered_map<int, int> rank;

    void init()
    {
        parent.clear();
        rank.clear();
    }

    void make_set(int x)
    {
        parent[x] = x;
        rank[x] = 0;
    }

    int find_set(int x)
    {
        if (x != parent.at(x))
            parent[x] = find_set(parent.at(x));
        return parent.at(x);
    }

    bool same_set(int x, int y)
    {
        return find_set(x) == find_set(y);
    }

    void join(int x, int y)
    {
        int xr = find_set(x);
        int yr = find_set(y);
        if (xr != yr)
        {
            if (rank.at(xr) > rank.at(yr))
                parent[yr] = xr;
            else
            {
                parent[xr] = yr;
                if (rank.at(xr) == rank.at(yr))
                    ++rank[yr];
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    FASTIO;
    int t, id = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        ufds::init();
        for (int i = 0; i < n; ++i)
            ufds::make_set(i + 1);
        
        int success = 0, failed = 0;
        string cmd;
        getline(cin, cmd);
        while (getline(cin, cmd) && !cmd.empty())
        {
            stringstream ss{ cmd };
            char op; int c1, c2;
            ss >> op >> c1 >> c2;

            if (op == 'c')
            {
                ufds::join(c1, c2);
            }
            else 
            {
                ufds::same_set(c1, c2) 
                    ? ++success
                    : ++failed;
            }
        }
        
        if (id++ > 1) cout << "\n";
        cout << success << "," << failed << "\n";
    }

    return 0;
}

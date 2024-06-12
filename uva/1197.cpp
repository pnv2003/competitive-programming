#include <iostream>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

#include <unordered_map>
namespace ufds
{
    std::unordered_map<int, int> parent;
    std::unordered_map<int, int> rank;
    std::unordered_map<int, int> setsize;

    void init()
    {
        parent.clear();
        rank.clear();
        setsize.clear();
    }

    void make_set(int x)
    {
        parent[x] = x;
        rank[x] = 0;
        setsize[x] = 1;
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
            {
                parent[yr] = xr;
                setsize[xr] += setsize.at(yr);
                setsize.erase(yr);
            }
            else
            {
                parent[xr] = yr;
                setsize[yr] += setsize.at(xr);
                setsize.erase(xr);
                if (rank.at(xr) == rank.at(yr))
                    ++rank[yr];
            }
        }
    }

    int num_sets()
    {
        return setsize.size();
    }

    int set_size(int x)
    {
        return setsize.at(find_set(x));
    }
}

int main(int argc, char const *argv[])
{
    FASTIO;
    int n, m;
    while (cin >> n >> m && !(n == 0 && m == 0))
    {
        ufds::init();
        for (int i = 0; i < n; ++i)
            ufds::make_set(i);
        
        while (m--)
        {
            int k;
            cin >> k;

            int set = -1;
            while (k--)
            {
                int stu;
                cin >> stu;
                if (set == -1)
                    set = stu;
                else
                    ufds::join(set, stu);
            }
        }
        cout << ufds::set_size(0) << "\n";
    }
    
    return 0;
}

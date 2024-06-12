#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;
    int n;
    while (cin >> n && n != 0)
    {
        map<vector<int>, int> pop;
        while (n--)
        {
            vector<int> comb;
            for (int i = 0; i < 5; ++i)
            {
                int crs;
                cin >> crs;
                comb.push_back(crs);
            }
            sort(comb.begin(), comb.end());
            if (pop.find(comb) == pop.end())
                pop[comb] = 0;
            ++pop[comb];
        }

        int cnt = 0, maxpop = 0;
        for (auto it = pop.begin(); it != pop.end(); ++it)
        {
            if (it->second > maxpop)
            {
                maxpop = it->second;
                cnt = it->second;
            }
            else if (it->second == maxpop)
                cnt += it->second;
        }

        cout << cnt << "\n";
    }

    return 0;
}

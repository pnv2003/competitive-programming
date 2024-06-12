#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define ALL(x) x.begin(), x.end()

int main(int argc, char const *argv[])
{
    FASTIO;

    int t, id = 1;
    cin >> t;
    while (t--)
    {
        vector<int> v1, v2, v3;

        int n;
        cin >> n;
        while (n--)
        {
            int p;
            cin >> p;
            v1.push_back(p);
        }
        cin >> n;
        while (n--)
        {
            int p;
            cin >> p;
            v2.push_back(p);
        }
        cin >> n;
        while (n--)
        {
            int p;
            cin >> p;
            v3.push_back(p);
        }

        sort(ALL(v1));
        sort(ALL(v2));
        sort(ALL(v3));

        auto ulast = unique(ALL(v1));
        v1.erase(ulast, v1.end());
        ulast = unique(ALL(v2));
        v2.erase(ulast, v2.end());
        ulast = unique(ALL(v3));
        v3.erase(ulast, v3.end());

        vector<int> w1, w2, w3, x1, x2, x3;
        set_difference(ALL(v1), ALL(v2), back_inserter(w1));
        set_difference(ALL(w1), ALL(v3), back_inserter(x1));
        set_difference(ALL(v2), ALL(v1), back_inserter(w2));
        set_difference(ALL(w2), ALL(v3), back_inserter(x2));
        set_difference(ALL(v3), ALL(v1), back_inserter(w3));
        set_difference(ALL(w3), ALL(v2), back_inserter(x3));

        
        vector<pair<int, vector<int>>> psolved;

        int maxsolved = max({x1.size(), x2.size(), x3.size()});
        if (x1.size() == maxsolved)
            psolved.push_back({1, x1});
        if (x2.size() == maxsolved)
            psolved.push_back({2, x2});
        if (x3.size() == maxsolved)
            psolved.push_back({3, x3});
        
        cout << "Case #" << id++ << ":\n";

        for (const auto& p: psolved)
        {
            cout << p.first << " " << p.second.size();
            for (int prob: p.second)
                cout << " " << prob;
            cout << "\n";
        }
    }
    
    return 0;
}

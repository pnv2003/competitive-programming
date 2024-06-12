#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;

    int t, id = 1;
    cin >> t;
    while (t--)
    {
        vector<string> maker;
        vector<pair<int, int>> range;
        int d;
        cin >> d;
        while (d--)
        {
            string m;
            int l, h;
            cin >> m >> l >> h;
            maker.push_back(m);
            range.push_back({l, h});
        }

        if (id++ > 1)
            cout << "\n";

        vector<string> memo(1000000, "");
        int q, price;
        cin >> q;
        while (q--)
        {
            cin >> price;

            if (!memo[price].empty()) 
            {
                if (memo[price] == "???")
                    cout << "UNDETERMINED\n";
                else
                    cout << memo[price] << "\n";
                continue;
            }

            bool found = false;
            int pos;
            for (int i = 0; i < range.size(); ++i)
            {
                auto r = range[i];
                if (price >= r.first && price <= r.second)
                {
                    if (found)
                    {
                        found = false;
                        break;
                    }
                    else 
                    {
                        found = true;
                        pos = i;
                    }
                }
            }

            if (found) 
            {
                memo[price] = maker[pos];
                cout << maker[pos] << "\n";
            }
            else
            {
                memo[price] = "???";
                cout << "UNDETERMINED\n";
            }
        }
        
        
    }
    

    return 0;
}


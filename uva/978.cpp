#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;
    int n, id = 1;
    cin >> n;
    while (n--)
    {
        int b, sg, sb;
        cin >> b >> sg >> sb;

        multiset<int> green, blue;
        while (sg--)
        {
            int p; 
            cin >> p;
            green.insert(p);
        }
        while (sb--)
        {
            int p;
            cin >> p;
            blue.insert(p);
        }
        
        vector<pair<int, int>> battlefield;
        while (!green.empty() && !blue.empty())
        {
            battlefield.assign(b, {-1, -1});

            for (int i = 0; i < b; ++i)
            {
                auto& bf = battlefield[i];

                // send soldiers
                if (!green.empty())
                {
                    auto sol = prev(green.end());
                    bf.first = *sol;
                    green.erase(sol);
                }
                auto pb = blue.rbegin();
                if (distance(pb, blue.rend()) > 0)
                {
                    auto sol = prev(blue.end());
                    bf.second = *sol;
                    blue.erase(sol);
                }

                if (bf.first == -1 || bf.second == -1)
                    continue; // no battle here

                // battle!
                auto powerdown = min(bf.first, bf.second);
                bf.first -= powerdown;
                bf.second -= powerdown;
            }

            for (int i = 0; i < b; ++i)
            {
                auto bf = battlefield[i];
                // send survivors back to armies
                if (bf.first > 0)
                    green.insert(bf.first);
                if (bf.second > 0)
                    blue.insert(bf.second);
            }
        }
        
        if (id++ > 1) cout << "\n";
        if (green.empty() && blue.empty())
            cout << "green and blue died\n";
        else if (green.empty()) 
        {
            cout << "blue wins\n";
            for (auto it = blue.rbegin(); it != blue.rend(); ++it)
                    cout << *it << "\n";
        }
        else 
        {
            cout << "green wins\n";
            for (auto it = green.rbegin(); it != green.rend(); ++it)
                    cout << *it << "\n";
        }
    }
    
    return 0;
}

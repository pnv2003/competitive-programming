#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;
    int tc; cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        
        vector<int> sf;
        while (n--)
        {
            int s;
            cin >> s;
            sf.push_back(s);
        }

        unordered_set<int> package;
        size_t maxcap = 0;
        auto winl = sf.begin(), winr = sf.begin();
        while (winr < sf.end())
        {
            if (package.count(*winr) == 0)
            {
                package.insert(*winr);
                maxcap = max(maxcap, package.size());
                ++winr;
            }
            else
            {
                package.erase(*winl);
                ++winl;
            }
        }
        
        cout << maxcap << "\n";
    }
    
    return 0;
}

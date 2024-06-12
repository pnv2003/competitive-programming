#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;
    int n;
    while (cin >> n && n != 0)
    {
        multiset<int> bills;
        ll cost = 0;

        while (n--)
        {
            int k;
            cin >> k;
            while (k--)
            {
                int b;
                cin >> b;
                bills.insert(b);
            }
            cost += static_cast<ll>(*prev(bills.end()) - *bills.begin());
            bills.erase(prev(bills.end()));
            bills.erase(bills.begin());
        }
        
        cout << cost << "\n";
    }
    return 0;
}

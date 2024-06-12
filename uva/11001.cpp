#include <iostream>
#include <cmath>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

using ll = long long;
int main(int argc, char const *argv[])
{
    FASTIO;

    ll total, init;
    while (cin >> total >> init)
    {
        if (total == 0 && init == 0)
            break;
        
        ll numdisc = 0;
        ll maxlen = 0; // store 100p^2v^2
        ll maxcnt = 0;
        const ll maxn = static_cast<ll>(floor(total*1.0/init));
        for (ll n = 1; n <= maxn; ++n)
        {
            ll len = 9*(total*n - init*n*n);
            if (len > maxlen)
            {
                numdisc = n;
                maxlen = len;
                maxcnt = 1;
            }
            else if (len == maxlen)
                ++maxcnt;
        }

        if (maxcnt == 0 || maxcnt > 1)
            cout << "0\n";
        else
            cout << numdisc << "\n";
    }
       
    return 0;
}

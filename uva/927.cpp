#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

using ll = long long;
int main(int argc, char const *argv[])
{
    FASTIO;
    int c;
    cin >> c;
    while (c--)
    {
        vector<ll> coef;
        int deg;
        cin >> deg; deg++;
        while (deg--)
        {
            int co;
            cin >> co;
            coef.push_back(co);
        }
        
        ll d, k;
        cin >> d >> k;

        ll aidx = 1, bidx = 1, rep = d;
        while (true)
        {
            ll a = coef[0];
            for (int i = 1; i < coef.size(); ++i)
                a += coef[i] * static_cast<ll>(pow(aidx, i));

            if (k >= bidx && k < bidx + rep)
            {
                cout << a << "\n";
                break;
            }

            ++aidx;
            bidx += rep;
            rep += d;
        }
    }
    
    return 0;
}

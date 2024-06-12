#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vector<int>>;
#define EPS 1e-9
#define PI acos(-1.0)
#define FORI(i, a, b) for(int i = int(a); i < int(b); ++i)
#define FORIT(it, x) for(auto it = x.begin(); it != x.end(); ++it)
#define ALL(x) x.begin(), x.end()
#define GETI(a) scanf(" %d", &a)
#define GETII(a, b) scanf(" %d %d", &a, &b)
#define GETIII(a, b, c) scanf(" %d %d %d", &a ,&b, &c)
#define GETC(ch) scanf(" %c", &ch);
#define GETS(str) scanf(" %s", &str);
#define MEM(x, val) memset(x, val, sizeof(x))
#define PF first
#define PS second
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;

    ll n, x;
    cin >> n >> x;

    vector<ll> box(n);
    for (int i = 0; i < n; ++i)
        cin >> box[i];

    ll cnt = 0;
    ll l = 0, r = 0;
    ll sumdiff = 0;

    ll F;
    while (l < n - 1)
    {
        if (l == r)
        {
            sumdiff += abs(box[r] - box[r + 1]);
            ++r;
            continue;
        }

        F = sumdiff * (r - l);

        if (F >= x)
        {
            cnt += n - r;
            sumdiff -= abs(box[l] - box[l + 1]);
            ++l;
        }
        else
        {
            if (r < n - 1)
            {
                sumdiff += abs(box[r] - box[r + 1]);
                ++r;
            }
            else 
                break;
        }
    }

    cout << cnt << "\n";
        
    return 0;
}

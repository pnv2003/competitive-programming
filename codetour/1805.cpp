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
#include <list>
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
using vs = vector<string>;
#define EPS 1e-9
#define PI acos(-1.0)
#define ALL(x) x.begin(), x.end()
#define MEM(x, val) memset(x, val, sizeof(x))
#define PF first
#define PS second
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

ll calc(ll m, ll n, ll x)
{
    ld hexlen = sqrt(3) * x;
    ll lens = static_cast<ll>(ceil(n*1.0 / hexlen));
    ll lenl = static_cast<ll>(ceil((n - hexlen/2)*1.0 / hexlen) + 1);
    ll wid;
    if (m <= x)
        wid = 1;
    else 
        wid = static_cast<ll>(ceil((m - x)*1.0 / (x*1.5))) + 1;

    return (lens*(wid/2) + lenl*(wid % 2));
}

int main(int argc, char const *argv[])
{
    FASTIO;
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m, x;
        cin >> n >> m >> x;
        cout << min(calc(m, n, x), calc(n, m, x)) << "\n";
    }
    
    return 0;
}

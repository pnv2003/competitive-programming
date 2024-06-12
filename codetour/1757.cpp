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
#define EPS 1e-9
#define PI acos(-1.0)
#define ALL(x) x.begin(), x.end()
#define MEM(x, val) memset(x, val, sizeof(x))
#define PF first
#define PS second
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a,ll b) { return (a*b)/gcd(a,b); }
ll phi(ll n) // Euler's Totient Function
{
    ll result = n;
    for (ll p = 2; p * p <= n; ++p)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;
                 
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;  
    return result;
}

int main(int argc, char const *argv[])
{
    FASTIO;
    int n;
    cin >> n;
    ll val = 1;
    for (int i = 0; i < n; ++i)
    {
        int v;
        cin >> v;
        val *= v;
    }

    cout << phi(val) % 10000000007 << "\n";
    return 0;
}

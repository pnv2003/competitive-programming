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
#define OVERLAP(x1, y1, x2, y2) (((x1) <= (y2)) && ((y1) >= (x2)))
#define ALL(x) x.begin(), x.end()
#define MEM(x, val) memset(x, val, sizeof(x))
#define PF first
#define PS second
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a,ll b) { return (a*b)/gcd(a,b); }

int n, k;
int board[501];

ll maxval;

void backtrack(int idx)
{
    if (idx == k)
    {
        ll val = board[0];
        for (int i = 1; i < n; ++i)
            val = gcd(val, board[i]);
        maxval = max(maxval, val);
        return;
    }

    for (int inc = 0; inc < n; ++inc)
    {
        for (int dec = 0; dec < n; ++dec)
        {
            if (inc == dec) continue;

            ++board[inc];
            --board[dec];
            backtrack(idx + 1);
            --board[inc];
            ++board[dec];
        }
    }
}

int main(int argc, char const *argv[])
{
    FASTIO;
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
        cin >> board[i];

    maxval = LLONG_MIN;
    backtrack(0);
    cout << maxval << "\n";

    return 0;
}

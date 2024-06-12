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
    int m, n, k;
    cin >> m >> n >> k;

    vvi field(m, vi(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) 
        {
            cin >> field[i][j];

            if (i > 0) field[i][j] += field[i - 1][j];
            if (j > 0) field[i][j] += field[i][j - 1];
            if (i > 0 && j > 0) field[i][j] -= field[i - 1][j - 1];
        }

    int q, u, v;
    cin >> q;
    while (q--)
    {
        cin >> u >> v; --u; --v;

        ll val = 0;
        for (int col = v - k; col <= v + k; ++col)
        {
            if (col < 0 || col >= n) continue;
            int upr = u - (k - abs(v - col));
            if (upr < 0) 
                upr = 0;
            int downr = u + abs(k - abs(v - col));
            if (downr >= m) 
                downr = m - 1;
            
            ll bar = field[downr][col];
            if (upr > 0) bar -= field[upr - 1][col];
            if (col > 0) bar -= field[downr][col - 1];
            if (upr > 0 && col > 0) bar += field[upr - 1][col - 1];

            val += bar;
        }
        cout << val << "\n";
    }
    return 0;
}

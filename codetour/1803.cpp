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

int main(int argc, char const *argv[])
{
    FASTIO;
    int n, w1, w2;
    cin >> n >> w1 >> w2;
    vi seq(n);
    for (int i = 0; i < n; ++i)
        cin >> seq[i];
    
    vi coef{w1, w1, w2, w2, 1};

    sort(ALL(seq));
    sort(ALL(coef));

    int cl = 0, cr = 4, sr = n - 1;
    ll val = 0;
    while (cl < 5)
    {
        if (coef[cl] > 0)
            break;
        
        val += coef[cl] * seq[cl];
        ++cl;
    }
    while (cr >= 0)
    {
        if (coef[cr] <= 0)
            break;

        val += coef[cr] * seq[sr];
        --cr;
        --sr;
    }

    cout << val << "\n";
    return 0;
}

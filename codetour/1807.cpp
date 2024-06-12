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

int hextoint(const string& s)
{
    int val = 0;
    for (char c: s)
    {
        val *= 16;
        if (isdigit(c))
            val += c - '0';
        else
            val += c - 'A' + 10;
    }
    return val;
}

int main(int argc, char const *argv[])
{
    FASTIO;
    int n;
    cin >> n;
    vs pic1(n), pic2(n);
    for (int i = 0; i < n; ++i)
        cin >> pic1[i];
    for (int i = 0; i < n; ++i)
        cin >> pic2[i];

    map<iii, int> deltacnt;
    int maxcnt = 0;
    for (int i = 0; i < n; ++i)
    {
        auto px = pic1[i];
        iii d1 = 
        {
            hextoint(px.substr(1, 2)),
            hextoint(px.substr(3, 2)),
            hextoint(px.substr(5, 2))
        };
        px = pic2[i];
        iii d2 = 
        {
            hextoint(px.substr(1, 2)),
            hextoint(px.substr(3, 2)),
            hextoint(px.substr(5, 2))
        };

        iii d = 
        {
            (get<0>(d2) - get<0>(d1)) % 256,
            (get<1>(d2) - get<1>(d1)) % 256,
            (get<2>(d2) - get<2>(d1)) % 256
        };
        
        if (deltacnt.count(d) == 0)
            deltacnt[d] = 0;
        ++deltacnt[d];
        maxcnt = max(deltacnt[d], maxcnt);
    }

    printf("%.2f%%\n", maxcnt*100.0/n);

    return 0;
}

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
#define TOI(x) static_cast<int>(x)
#define TOLL(x) static_cast<long long>(x)
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int numround(int numpar, int k)
{
    if (numpar == 0)
        return 0;
    if (numpar <= k)
        return 1;

    int winner = TOI(ceil(numpar*1.0 / k));
    return winner + numround(winner, k);
}

int main(int argc, char const *argv[])
{
    FASTIO;
    int n, m, k;
    cin >> n >> m >> k;
    vi contest(m, 0);
    for (int i = 0; i < n; ++i) 
    {
        int c;
        cin >> c; c--;
        ++contest[c];
    }

    if (k == 1) 
    {
        cout << "0\n";
        return 0;
    }

    int total = 0;
    for (int i = 0; i < m; ++i)
        total += numround(contest[i], k);
    
    cout << total << "\n";
    return 0;
}

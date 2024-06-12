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

multiset<int> wallet;

int pushwallet(const vi& money)
{
    if (wallet.empty())
    {
        for (int m: money)
            wallet.insert(m);
        return 1;
    }

    if (money.size() == 1) 
    {
        wallet.insert(money[0]);
        return 1;
    }

    ii range;
    int maxcnt = 0;
    for (auto it = wallet.begin(); next(it) != wallet.end(); ++it)
    {
        int cnt = 0;
        for (int m: money)
        {
            if (m >= *it && m <= *next(it))
                ++cnt;
            maxcnt = max(maxcnt, cnt);
        }
    }

    // ...  
}

int main(int argc, char const *argv[])
{
    int q;
    cin >> q;
    while (q--)
    {
        int n; 
        cin >> n;

        vi money(n);
        for (int i = 0; i < n; ++i)
            cin >> money[i];

        cout << pushwallet(money);
    }
    

    return 0;
}

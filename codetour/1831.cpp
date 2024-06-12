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

int binsearch(const vi& arr, int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        if (arr[m] == x)
            return m;
 
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
 

int main(int argc, char const *argv[])
{
    FASTIO; FILEIO;
    vector<int> gamer;
    int a, b;
    while (cin >> a >> b && a != 0)
    {
        if (a == 1)
        {
            auto it = upper_bound(gamer.begin(), gamer.end(), b);
            if (gamer.empty())
                gamer.insert(it, b); 
            else if (it > gamer.begin())
            {
                if (*prev(it) != b)
                    gamer.insert(it, b);
            }
        }
        else 
        {
            int pos = binsearch(gamer, 0, gamer.size() - 1, b);
            cout << pos + 1 << "\n";
        }
    }
    
    return 0;
}

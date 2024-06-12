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
    const string direction = "NESW";
    const unordered_map<char, int> map_diridx =
    {
        {'N', 0},
        {'E', 1},
        {'S', 2},
        {'W', 3}
    };

    int n, q;
    string path;
    cin >> n >> q >> path;

    multiset<char> d;
    for (char c: path)
        d.insert(c);

    int cnt = 0;
    int cmd;
    while (q--)
    {
        cin >> cmd;
        if (cmd == 1)
        {
            int i; char c;
            cin >> i >> c; --i;
            d.erase(d.find(path[i]));
            d.insert(c);
            path[i] = c;
        }
        else
        {
            int i, j, k;
            cin >> i >> j >> k; --i; --j;
            for (int idx = i; idx <= j; ++idx)
            {
                char ch = path[idx];
                d.erase(d.find(ch));
                char newch = direction[(map_diridx.at(ch) + k) % 4];
                d.insert(newch);
                path[idx] = newch;
            }
        }

        if (d.count('N') == d.count('S') &&
            d.count('E') == d.count('W'))
            ++cnt;
    }

    cout << cnt << "\n";
    return 0;
}

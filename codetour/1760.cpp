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
    FASTIO; FILEIO;

    int n, m;
    cin >> n >> m;

    set<ii> match;
    vector<vii> fences(n, vii());

    while (n--)
    {
        int id, l, r; --id; --l; --r;
        cin >> id >> l >> r;

        fences[id].push_back({l, r});

        for (int i = 0; i < id; ++i)
        {
            for (auto& p: fences[i])
            {
                if (OVERLAP(l, r, p.first, p.second))
                    match.insert({min(id, i), max(id, i)});
            }
        }
    }

    
    

    return 0;
}

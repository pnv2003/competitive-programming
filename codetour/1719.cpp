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

int n;
vector<ll> a;
vector<vector<ll>> groups;

void group_patients(int k)
{
    groups.clear();
    int idx = 0;
    while (true)
    {
        vector<ll> g;
        bool stop = false;
        for (int i = 0; i < k; ++i)
        {
            if (idx >= n) 
            {
                stop = true;
                break;
            }
            g.push_back(a[idx++]);
        }
        if (!g.empty())
            groups.push_back(g);
        if (stop) break;
    }
}

ll calc(int k)
{
    ll sum = 0;
    for (int i = 0; i < groups.size(); ++i)
    {
        for (int p1 = 0; p1 < groups[i].size(); ++p1)
            for (int p2 = p1 + 1; p2 < groups[i].size(); ++p2)
            {
                if (p1 != p2)
                    sum += groups[i][p1] * groups[i][p2];
            }
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    FASTIO;
    cin >> n;
    a.assign(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    ll sumall = 0;
    for (int k = 1; k <= n; ++k)
    {
        group_patients(k);
        sumall += calc(k);
    }

    cout << sumall % 1000000007ULL << "\n";
    return 0;
}

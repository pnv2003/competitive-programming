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

    int n, q;
    cin >> n >> q;
    ll superpower = 0;
    vi power(n);
    for (int i = 0; i < n; ++i) 
    {
        cin >> power[i];
        superpower += abs(power[i]);
    }

    cout << superpower << "\n";
    char turn;
    int x;
    while (q--)
    {
        cin >> turn >> x;
        if (turn == 'B')
        {
            for (int i = 0; i < n; ++i)
            {
                int tmp = abs(power[i]);
                power[i] += x;
                superpower += abs(power[i]) - tmp;
            }
        }
        else 
        {
            for (int i = 0; i < n; ++i)
            {
                int tmp = abs(power[i]);
                power[i] -= x;
                superpower += abs(power[i]) - tmp;
            }
        }
        cout << superpower << "\n";
    }
    
    return 0;
}

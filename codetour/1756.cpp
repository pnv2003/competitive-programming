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
#define MEM(x, val) memset(x, val, sizeof(x))
#define PF first
#define PS second
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;
    int t;
    cin >> t;

    unordered_map<int, int> memo;
    while (t--)
    {
        int n;
        cin >> n;

        if (memo.count(n) > 0)
        {
            cout << memo[n] << "\n";
            continue;
        }

        int cnt = 0;
        for (int i = 1; i <= static_cast<int>(sqrt(n)); ++i)
        {
            int num = n / i - i + 1;
            if (num > 0)
                cnt += num;
        }

        memo[n] = cnt;
        cout << cnt << "\n";
    }
    
    return 0;
}
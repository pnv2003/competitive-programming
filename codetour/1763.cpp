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
    int n;
    cin >> n;

    unordered_set<int> mexcheck;
    vi arr(n);    
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        mexcheck.insert(arr[i]);
    }

    int mexall = 0;
    for (int i = 0; i <= 1000000000; ++i)
    {
        if (mexcheck.count(i) == 0)
        {
            mexall = i;
            break;
        }
    }

    sort(ALL(arr));

    mexcheck.clear();
    for (int i = 0; i < n; ++i)
    {
        bool uni = true;
        if (i > 0)
        {
            if (arr[i] == arr[i - 1])
                uni = false;
        }
        if (i < n - 1)
        {
            if (arr[i] == arr[i + 1])
                uni = false;
        }

        int mexb;
        if (uni)
            mexb = arr[i];
        else 
            mexb = mexall;
        mexcheck.insert(mexb);
    }

    for (int i = 0; i <= 1000000000; ++i)
    {
        if (mexcheck.count(i) == 0)
        {
            cout << i << "\n";
            break;
        }
    }
    
    return 0;
}

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
    string str;
    cin >> str;
    int len = str.size();

    bool pass = false;

    if (str[0] == '1' &&
        str[1] == '1' &&
        str[2] != '1')
        pass = true;
    if (str[len - 1] == '1' &&
        str[len - 2] == '1' &&
        str[len - 3] != '1')
        pass = true;
    for (int l = 0; l + 3 < str.size(); ++l)
    {
        if (pass)
            break;
        if (str[l + 1] == '1' && 
            str[l + 2] == '1' &&
            str[l] != '1' &&
            str[l + 3] != '1')
            pass = true;
    }

    pass 
        ? cout << "Yes\n"
        : cout << "No\n";
    return 0;
}

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

string s;
ll b, sum;
list<char> t;

void backtrack(int idx)
{
    if (idx == s.size())
    {
        ll num = 0;
        for (auto it = t.begin(); it != t.end(); ++it)
        {
            num *= 10;
            num += *it - '0';
        }
        if (num <= b)
            sum += num;
        return;
    }

    t.push_front(s[idx]);
    backtrack(idx + 1);
    t.pop_front();

    t.push_back(s[idx]);
    backtrack(idx + 1);
    t.pop_back();
}

int main(int argc, char const *argv[])
{
    FASTIO;
    int q;
    cin >> q;

    while (q--)
    {
        sum = 0;
        t.clear();

        getline(cin >> ws, s);
        cin >> b;

        t.push_back(s[0]);
        backtrack(1);

        cout << sum % 1000000007 << "\n";
    }
    
    return 0;
}

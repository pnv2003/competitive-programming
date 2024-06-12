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
ll k, order;
string brackets;
string s;
unordered_map<string, bool> memo;
bool valid;

string hashbr(int idx, const string& s)
{
    return to_string(idx) + s;
}

void backtrack(int idx)
{
    if (idx == n)
    {
        if (!s.empty())
        {
            valid = false;
            if (order++ == k - 1)
                cout << brackets << "\n";
        }
        else valid = true;
        return;
    }

    auto key = hashbr(idx, s);
    if (memo.count(key) > 0)
    {
        if (memo[key])
            return;
    }

    brackets[idx] = '(';
    s.push_back('(');
    backtrack(idx + 1);
    s.pop_back();

    brackets[idx] = ')';
    bool matched = false;
    if (!s.empty() && s.back() == '(') 
    {
        s.pop_back();
        matched = true;
    }
    else 
        s.push_back(')');
    backtrack(idx + 1);
    if (matched)
        s.push_back('(');
    else
        s.pop_back();

    memo[key] = valid;
}

int main(int argc, char const *argv[])
{
    FASTIO;
    cin >> n >> k;
    brackets.assign(n, ' ');
    order = 0;
    backtrack(0);

    return 0;
}

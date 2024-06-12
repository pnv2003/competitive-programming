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
#define ALL(x) x.begin(), x.end()
#define MEM(x, val) memset(x, val, sizeof(x))
#define PF first
#define PS second
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;
    int n, h;
    cin >> n >> h;
    
    vi card(n);
    bitset<1000001> winpos;

    int maxcard = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> card[i];
        maxcard = max(maxcard, card[i]);
    }

    // init
    for (int i = 1; i <= maxcard; ++i)
        winpos.set(i);
    
    // step
    sort(card.rbegin(), card.rend());
    for (int pos = maxcard + 1; pos <= h; ++pos)
    {
        if (!winpos.test(pos)) 
        {
            for (int c = 0; c < n; ++c) 
            {
                if (pos + card[c] > 1000000) continue;
                winpos.set(pos + card[c]);
            }
        }
    }
    
    int ypos = h, maxdmg = 0;
    if (!winpos.test(ypos))
    {
        cout << "-1\n";
        return 0;
    }
    while (ypos > maxcard)
    {
        for (int c = 0; c < n; ++c)
        {
            if (!winpos.test(ypos - card[c]))
            {
                ypos -= card[c] + card[n - 1];
                maxdmg += card[c];
                break;
            }
        }
    }
    maxdmg += card[0];
    cout << maxdmg << "\n";
    
    return 0;
}

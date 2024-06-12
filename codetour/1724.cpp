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
    int t;
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        vector<int> card(n);
        for (int i = 0; i < n; ++i)
            cin >> card[i];

        int mmax = INT_MIN;
        deque<int> winmax, winmin;
        
        for (int k = 2; k <= n; ++ k)
        {
            winmax.clear();
            winmin.clear();
            
            for (int l = 0, r = l + k - 1; r < n; ++l, ++r)
            {  
                if (l == 0) // init
                {
                    for (int i = 0; i < k; ++i)
                    {
                        while (!winmax.empty() && card[i] >= card[winmax.back()])
                            winmax.pop_back();
                        winmax.push_back(i);

                        while (!winmin.empty() && card[i] <= card[winmin.back()])
                            winmin.pop_back();
                        winmin.push_back(i);
                    }
                }
                else // step
                {
                    if (!winmax.empty() && winmax.front() < l)
                        winmax.pop_front();
                    if (!winmin.empty() && winmin.front() < l)
                        winmin.pop_front();

                    while (!winmax.empty() && card[r] >= card[winmax.back()])
                        winmax.pop_back();
                    winmax.push_back(r);

                    while (!winmin.empty() && card[r] <= card[winmin.back()])
                        winmin.pop_back();
                    winmin.push_back(r);                
                }

                if (!winmax.empty() && !winmin.empty())
                        mmax = max(mmax, card[winmax.front()] + card[winmin.front()]); 
            }
        }

        cout << mmax << "\n";
    }
    
    return 0;
}

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
    int m, n;
    cin >> m >> n;

    vvi mat(m, vi(n, 0));

    int fst = 0, snd = 0;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
        {
            int num;
            cin >> num;

            if (num == 1) 
            {
                mat[i][j] == 0;
                continue;
            }

            if (i == 0 && j == 0)
            {
                mat[i][j] = 1;
            }
            else
            {
                int up = 0;
                int left = 0;
                int upleft = 0;

                if (i > 0)
                    up = mat[i - 1][j];
                if (j > 0)
                    left = mat[i][j - 1];
                if (i > 0 && j > 0)
                    upleft = mat[i - 1][j - 1];

                if (upleft == 0)
                    mat[i][j] = max(up + 1, left + 1);
                else 
                    mat[i][j] = up + left + 1 - upleft;
            }

            int area = mat[i][j];
            if (area > fst)
            {
                snd = fst;
                fst = area;
            }
            else if (area > snd)
            {
                snd = area;
            }
        }

        cout << fst + snd << "\n";

    return 0;
}

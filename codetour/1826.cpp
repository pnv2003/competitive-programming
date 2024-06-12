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

using ddd = tuple<ld, ld, ld>;
ld dist(const ddd& p1, const ddd& p2)
{
    return 
    sqrt(
        (get<0>(p1) - get<0>(p2)) * (get<0>(p1) - get<0>(p2)) +
        (get<1>(p1) - get<1>(p2)) * (get<1>(p1) - get<1>(p2)) +
        (get<2>(p1) - get<2>(p2)) * (get<2>(p1) - get<2>(p2))
    );
}

struct Point
{
    ddd coordinate;
    ll val;
    ld distance;
};

int main(int argc, char const *argv[])
{
    FASTIO;
    int n, k;
    ld r, x0, y0, z0;

    cin >> n >> k >> r >> x0 >> y0 >> z0;

    ddd center{ x0, y0, z0 };

    vector<Point> points;
    for (int i = 0; i < n; ++i)
    {
        ld x, y, z;
        ll val;
        cin >> x >> y >> z >> val;   
        
        ddd coor{x, y, z};
        points.push_back(Point{ coor, val, dist(center, coor) });
    }

    sort(ALL(points), 
        [](Point p1, Point p2)
        { return (p1.distance - p2.distance) < EPS; });

    ll totalval = 0;
    for (int i = 0; i < k && i < n; ++i)
    {
        if (points[i].distance <= r)
            totalval += points[i].val;
    }

    cout << totalval << "\n";
    return 0;
}

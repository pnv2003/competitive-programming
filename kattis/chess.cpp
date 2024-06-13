#include <iostream>
#include <utility>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

using ii = pair<int, int>;

vector<ii> gen(const ii& p) {
    vector<ii> dir = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    vector<ii> res{};

    for (const ii& d: dir) {
        int x = p.first, y = p.second;
        
        for (;;) {
            x += d.first;
            y += d.second;
            if (x < 0 || x > 7 || y < 0 || y > 7) {
                break;
            }
            res.push_back({x, y});
        }
    }

    sort(res.begin(), res.end());
    return res;
}

int main(int argc, char const *argv[])
{
    FASTIO;
    // FILEIO;
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; ++i) {
        if (i > 0) {
            cout << "\n";
        }

        char x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;

        ii p1{ x1 - 'A', x2 - '1' };
        ii p2{ y1 - 'A', y2 - '1' };

        if ((abs(p1.first - p2.first) + abs(p1.second - p2.second)) % 2 != 0) {
            cout << "Impossible";
            continue;
        }

        if (p1.first == p2.first && p1.second == p2.second) {
            cout << "0 " << x1 << " " << x2;
            continue;
        }
        
        if (abs(p1.first - p2.first) == abs(p1.second - p2.second)) {
            cout << "1 " << x1 << " " << x2 << " " << y1 << " " << y2;
            continue;
        }

        vector<ii> pm1 = gen(p1);
        vector<ii> pm2 = gen(p2);

        vector<ii> intersect{};
        set_intersection(pm1.begin(), pm1.end(), pm2.begin(), pm2.end(), back_inserter(intersect));

        ii mid = intersect.front();
        cout << "2 " 
                << x1 << " " << x2 << " "
                << static_cast<char>('A' + mid.first) << " " << 1 + mid.second << " "
                << y1 << " " << y2;
    }
    return 0;
}

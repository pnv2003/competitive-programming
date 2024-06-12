#include <iostream>
#include <utility>
#include <cmath>
#include <vector>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

using ii = pair<int, int>;

vector<ii> gen(const ii& p) {
    vector<ii> dir = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    vector<ii> res{};

    for (const ii& d: dir) {
        int x, y;

        whi

    }


}

int main(int argc, char const *argv[])
{
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; ++i) {
        if (i > 0) {
            cout << "\n";
        }

        char x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;

        ii p1{ x1 - 'a', y1 - '1' };
        ii p2{ x2 - 'a', y2 - '1' };

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

        

    }
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

struct Constraint
{
    int t1;
    int t2;
    int cond;
};

int main(int argc, char const *argv[])
{
    FASTIO;

    int n, m;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0) break;

        vector<Constraint> cons;
        while (m--)
        {
            int a, b, c;
            cin >> a >> b >> c;
            cons.push_back(Constraint{a, b, c});
        }

        vector<int> seatarr(n);
        for (int i = 0; i < n; ++i)
            seatarr[i] = i;
        
        int count = 0;
        do
        {
            bool ok = true;
            for (int i = 0; i < cons.size(); ++i)
            {
                auto con = cons[i];
                if (con.cond > 0 &&
                    abs(seatarr[con.t1] - seatarr[con.t2]) > con.cond) {
                    ok = false;
                    break;
                }
                else if (con.cond < 0 &&
                         abs(seatarr[con.t1] - seatarr[con.t2]) < (-con.cond)) {
                    ok = false;
                    break;
                }
            }
            if (ok) ++count;
        } while (next_permutation(seatarr.begin(), seatarr.end()));

        cout << count << "\n";
    }
        
    return 0;
}

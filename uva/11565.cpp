#include <iostream>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;
    int n;
    cin >> n;
    while (n--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        bool sol = false;
        for (int x = -21; x <= 21; ++x) 
        {
            if (x*x >= c) continue;
            for (int y = -100; y <= 100; ++y) 
            {
                if (y == x || x*x + y*y >= c) continue;
                for (int z = -100; z <= 100; ++z) 
                {
                    if (z == y || z == x) continue;
                    if (x + y + z == a &&
                        x*y*z == b &&
                        x*x + y*y + z*z == c) 
                    {
                        sol = true;
                        cout << x << " " << y << " " << z << "\n";
                        break;
                    }
                }
                if (sol) break;
            }
            if (sol) break;
        }
        if (!sol) cout << "No solution.\n";
    }
    
    return 0;
}
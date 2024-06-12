#include <iostream>
#include <cmath>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    long a, b;
    while (cin >> a >> b)
    {
        cout << abs(a - b) << "\n";
    }
    
    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    int t, n, m;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> n >> m;
        cout << (int)(ceil((n - 2)*1.0 / 3)*ceil((m - 2)*1.0 / 3)) << "\n";
    }
    return 0;
}
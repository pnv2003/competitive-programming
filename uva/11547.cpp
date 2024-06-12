#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        n = (n * 567 / 9 + 7492) * 235 / 47 - 498;
        cout << abs((n / 10) % 10) << "\n";
    }
    return 0;
}

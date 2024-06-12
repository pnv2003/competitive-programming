#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int m, n;
    cin >> m >> n;
    int maxd = 0;
    maxd += (m / 2)*n;
    maxd += (m % 2)*n / 2;
    cout << maxd;
    return 0;
}

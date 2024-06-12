#include <iostream>
#include <cmath>
using namespace std;
typedef long long _t;
int main()
{
    _t n, m, a;
    cin >> n >> m >> a;
    _t x = 0, y = 0;
    x = ceil(n*1.0 / a);
    y = ceil(m*1.0 / a);
    cout << x*y;
    return 0;
}
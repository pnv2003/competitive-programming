#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    int a, b;
    for (;;)
    {
        cin >> a >> b;
        if (a == -1) break;

        if (abs(a - b) <= 50)
            cout << abs(a - b) << "\n";
        else
            cout << 100 - abs(a - b) << "\n";
    }
    return 0;
}

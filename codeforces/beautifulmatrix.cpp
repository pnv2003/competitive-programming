#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    int row = 0, col = 0;
    int x;
    for (;;)
    {
        cin >> x;
        if (x == 1) break;
        ++col;
        if (col == 5)
        {
            col = 0;
            ++row;
        }
    }

    cout << abs(row - 2) + abs(col - 2);
    return 0;
}

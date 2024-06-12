#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    int qx, qy, dstx, dsty;
    for (;;)
    {
        cin >> qx >> qy >> dstx >> dsty;
        if (qx == 0) break;

        if (qx == dstx && qy == dsty)
            cout << "0\n";
        else if (qx == dstx || qy == dsty)
            cout << "1\n";
        else if (abs(qx - dstx) == abs(qy - dsty))
            cout << "1\n";
        else
            cout << "2\n";
    }
    return 0;
}


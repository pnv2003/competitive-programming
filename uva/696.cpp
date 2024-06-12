#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    int m, n;
    for (;;)
    {
        cin >> m >> n;
        if (m == 0 && n == 0) break;

        int maxpieces = ceil(m * n * 1.0 / 2);

        if ((m == 2 || n == 2) && m*n > 2)
        {
            int len = 0;
            if (m == 2 && n >= 2) len = n;
            else if (n == 2 && m >= 2) len = m;

            if (len % 4 == 0)
                maxpieces = len;
            else if (len % 4 == 1)
                maxpieces = len + 1;
            else if (len % 4 == 2)
                maxpieces = len + 2;
            else
                maxpieces = len + 1;
        }

        if (maxpieces < m*n && (m == 1 || n == 1))
            maxpieces = m*n;

        cout << maxpieces
             << " knights may be placed on a " 
             << m << " row "
             << n << " column board.\n";
    }
    return 0;
}

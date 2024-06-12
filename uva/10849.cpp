#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int c;
    cin >> c;
    while (c--)
    {
        int t, n, brow, bcol, dstrow, dstcol;
        cin >> t >> n;
        while (t--)
        {
            cin >> brow >> bcol >> dstrow >> dstcol;
            if (brow == dstrow && bcol == dstcol)
                cout << "0\n";
            else if((abs(brow - bcol) % 2) == (abs(dstrow - dstcol) % 2))
            {
                if (abs(brow - dstrow) == abs(bcol - dstcol))
                    cout << "1\n";
                else
                    cout << "2\n";
            }
            else
                cout << "no move\n";
        }
    }        
    
    return 0;
}

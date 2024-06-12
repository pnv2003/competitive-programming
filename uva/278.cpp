#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{     
    int t;
    cin >> t;
    while (t--)
    {
        char chesspiece;
        int m, n;
        cin >> chesspiece >> m >> n; 

        int maxpieces;
        switch (chesspiece)
        {
        case 'r':
            maxpieces = min(m, n);
            break;
        case 'k':
            maxpieces = ceil(m * n * 1.0 / 2);
            break;
        case 'Q':
            maxpieces = min(m, n);
            break;
        case 'K':
            maxpieces = ceil(m*1.0/2)*ceil(n*1.0/2);
            break;
        default:
            break;
        }
        cout << maxpieces << "\n";
    }
    return 0;
}

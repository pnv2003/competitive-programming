#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int k, n, m, x, y;
    for (;;)
    {
        cin >> k;
        if (k == 0) 
            break;
        cin >> n >> m;
        while (k--)
        {
            cin >> x >> y;
            if (x == n || y == m)
                cout << "divisa\n";
            else if (x > n && y > m)
                cout << "NE\n";
            else if (x > n && y < m)    
                cout << "SE\n";
            else if (x < n && y > m)
                cout << "NO\n";
            else 
                cout << "SO\n";
        }
    }
    
    return 0;
}

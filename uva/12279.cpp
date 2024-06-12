#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, event, id = 1;
    for (;;)
    {
        int x = 0, y = 0;
        cin >> n;
        if (n == 0) break;
        while (n--)
        {
            cin >> event;
            if (event == 0)
                ++y;
            else 
                ++x;
        }
        cout << "Case " << id++ << ": " << x - y << "\n";
    }
    return 0;
}

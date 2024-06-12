#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int t, f;
    cin >> t;
    while (t--)
    {
        cin >> f;
        int sp, numa, deg;
        int prem = 0;
        while (f--)
        {
            cin >> sp >> numa >> deg;
            prem += sp*deg;
        }
        cout << prem << "\n";
    }
    return 0;
}

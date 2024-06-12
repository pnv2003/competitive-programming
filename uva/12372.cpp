#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int t, l, w, h, id = 1;
    cin >> t;
    while (cin >> l >> w >> h)
    {
        cout << "Case " << id++ << ": ";
        if (l > 20 || w > 20 || h > 20)
            cout << "bad\n";
        else
            cout << "good\n";
    }
    return 0;
}

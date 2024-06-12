#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int t, n, dur, id = 1;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int m = 0, j = 0;
        while (n--)
        {
            cin >> dur;
            m += 10 * (dur / 30 + 1);
            j += 15 * (dur / 60 + 1);
        }
        cout << "Case " << id++ << ": ";
        if (m < j) cout << "Mile " << m;
        else if (m > j) cout << "Juice " << j;
        else cout << "Mile Juice " << m;
        cout << "\n";
    }
    
    return 0;
}
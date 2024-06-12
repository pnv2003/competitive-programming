#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int b, n;
    for (;;)
    {
        cin >> b >> n;
        if (b == n && b == 0) break;
        vector<int> res(b);
        for (int i = 0; i < b; ++i)
            cin >> res[i];

        int d, c, v;
        while (n--)
        {   
            cin >> d >> c >> v;
            res[d - 1] -= v;
            res[c - 1] += v;
        }

        bool ok = true;
        for (int i = 0; i < b; ++i)
        {
            if (res[i] < 0)
                ok = false;
        }
        cout << (ok ? "S\n" : "N\n");
    }
    return 0;
}

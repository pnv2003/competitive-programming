#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, p;
        cin >> n >> p;
        vector<int> barlen;
        for (int i = 0; i < p; ++i)
        {
            int l;
            cin >> l;
            barlen.push_back(l);
        }

        int sum;
        bool ok = false;
        for (int i = 0; i < (1 << p); ++i)
        {
            sum = 0;
            for (int j = 0; j < p; ++j)
                if ((i >> j) & 1)
                    sum += barlen[j];
            if (sum == n)
            {
                ok = true;
                break;
            }       
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}

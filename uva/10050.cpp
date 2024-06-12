#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(int argc, char const *argv[])
{
    FASTIO;

    int t;
    cin >> t;
    while (t--)
    {
        int nday, nparty;
        cin >> nday >> nparty;

        vector<int> hparams;
        while (nparty--)
        {
            int h;
            cin >> h;
            hparams.push_back(h);
        }

        vector<bool> check(nday, false);
        for (int i = 0; i < hparams.size(); ++i)
        {
            for (int hday = hparams[i] - 1; hday < nday; hday += hparams[i])
            {
                if (hday % 7 != 5 && hday % 7 != 6) 
                    check[hday] = true;
            }
        }

        cout << count(check.begin(), check.end(), true) << "\n";
    }
    
    return 0;
}

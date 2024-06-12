#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

enum CoinCheck
{
    SUS,
    TRUE
};

int main(int argc, char const *argv[])
{
    int m, id = 1;
    cin >> m;
    while (m--)
    {
        int ncoin, nw;
        cin >> ncoin >> nw;

        vector<CoinCheck> check(ncoin, SUS);
        int nsus = ncoin;
        while (nw--)
        {
            int nside;
            cin >> nside;

            vector<int> wcoins;
            for (int i = 0; i < nside*2; ++i)
            {
                int c;
                cin >> c;
                wcoins.push_back(c);
            }

            char res;
            cin >> res;
            if (res == '=')
            {
                for (int c: wcoins) 
                {
                    if (check[c - 1] == SUS)
                        nsus--;
                    check[c - 1] = TRUE;
                }
            }
            else
            {
                vector<bool> susmark(ncoin, false);
                for (int c: wcoins)
                    susmark[c - 1] = true;
                for (int i = 0; i < ncoin; ++i)
                {
                    if (!susmark[i]) 
                    {
                        if (check[i] == SUS)
                            nsus--;
                        check[i] = TRUE;
                    }
                }
            }
        }

        if (id++ > 1)
            cout << "\n";
        if (nsus != 1)        
            cout << "0\n";
        else 
        {
            auto fpos = find(check.begin(), check.end(), SUS);
            cout << fpos - check.begin() + 1 << "\n";
        }
    }
    
    return 0;
}

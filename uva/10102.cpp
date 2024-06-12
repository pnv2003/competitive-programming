#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int m;
    while (cin >> m)
    {
        vector<string> field(m);
        for (int i = 0; i < m; ++i)
            cin >> field[i];
        
        int minstepall = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < m; ++j)
            {
                if (field[i][j] != '1') continue;
                int minstep = 2*m;
                for (int k = 0; k < m; ++k)
                    for (int l = 0; l < m; ++l)
                    {
                        if (field[k][l] != '3') continue;
                        minstep = min(minstep, abs(i - k) + abs(j - l));
                    }
                minstepall = max(minstepall, minstep);
            }

        cout << minstepall << "\n";
    }
    
    return 0;
}

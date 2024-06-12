#include <iostream>
#include <climits>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;
    
    map<char, int> map_color;
    map_color['B'] = 0;
    map_color['G'] = 1;
    map_color['C'] = 2;
    vector<vector<int>> bin(3, vector<int>(3, 0));

    int fst;
    while (cin >> fst)
    {
        int total = 0;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (i == 0 && j == 0)
                    bin[i][j] = fst;
                else
                    cin >> bin[i][j];
                total += bin[i][j];
            }
        }

        string bincolor = "BCG", mincolor;
        int minmove = INT_MAX;
        do
        {
            int nkeep = 0;
            for (int b = 0; b < 3; ++b)
                nkeep += bin[b][map_color[bincolor[b]]];

            bool pass = false;
            if (total - nkeep < minmove)
                pass = true;
            else if (total - nkeep == minmove)
            {
                if (bincolor < mincolor)
                    pass = true;
            }
            if (pass)
            {
                minmove = total - nkeep;
                mincolor = bincolor;
            }
        } while (next_permutation(bincolor.begin(), bincolor.end()));
        
        cout << mincolor << " " << minmove << "\n"; 
    }
    return 0;
}

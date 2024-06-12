#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int dist(int src, int dst)
{
    int srcrow = src / 5;
    int dstrow = dst / 5;
    int srccol = src % 5;
    int dstcol = dst % 5;

    return abs(srcrow - dstrow) + abs(srccol - dstcol);
}

int main(int argc, char const *argv[])
{
    FASTIO;
    int t;
    cin >> t;
    while (t--)
    {
        vector<vector<int>> citypop(5, vector<int>(5, 0));

        int n;
        cin >> n;
        while (n--)
        {
            int row, col, pop;
            cin >> row >> col >> pop;
            citypop[row][col] = pop;
        }
        
        int minval = INT_MAX;
        vector<int> office(5, 0);
        for (int a = 0; a < 25; ++a) 
        {
            for (int b = a + 1; b < 25; ++b) 
            {
                for (int c = b + 1; c < 25; ++c) 
                {
                    for (int d = c + 1; d < 25; ++d) 
                    {
                        for (int e = d + 1; e < 25; ++e)
                        {
                            int val = 0;
                            for (int area = 0; area < 25; ++area)
                            {
                                int pop = citypop[area / 5][area % 5];
                                if (pop == 0) continue;
                                vector<int> offdist
                                { 
                                    dist(area, a),
                                    dist(area, b),
                                    dist(area, c),
                                    dist(area, d),
                                    dist(area, e)
                                };
                                val += (*min_element(offdist.begin(), offdist.end())) * pop;
                            }
                            if (val < minval)
                            {
                                minval = val;
                                office[0] = a;
                                office[1] = b;
                                office[2] = c;
                                office[3] = d;
                                office[4] = e;
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < 5; ++i)
        {
            cout << office[i];
            if (i == 4) cout << "\n";
            else cout << " ";
        }
    }
    
    return 0;
}

#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    // FILEIO;
    int n;
    while (scanf(" %d", &n) != EOF)
    {
        int sq[100][100];
        memset(sq, 0, sizeof(sq));

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf(" %d", &sq[i][j]);

        int accumulate[100][100];
        int maxsum = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                memset(accumulate, 0, sizeof(accumulate));
                for (int x = i; x < n; ++x)
                {
                    for (int y = j; y < n; ++y)
                    {
                        accumulate[x][y] = sq[x][y];
                        if (x > i) 
                            accumulate[x][y] += accumulate[x - 1][y];
                        if (y > j)
                            accumulate[x][y] += accumulate[x][y - 1];
                        if (x > i && y > j)
                            accumulate[x][y] -= accumulate[x - 1][y - 1];
                        maxsum = max(maxsum, accumulate[x][y]);
                    }
                }
            }
        }

        printf("%d\n", maxsum);
    }
    
    return 0;
}

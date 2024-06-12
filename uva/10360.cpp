#include <cstdio>
#include <cstring>
using namespace std;
#define GETI(a) scanf(" %d", &a)
#define GETII(a, b) scanf(" %d %d", &a, &b)
#define GETIII(a, b, c) scanf(" %d %d %d", &a ,&b, &c)

int grid[1025][1025];

int main(int argc, char const *argv[])
{
    int t;
    GETI(t);
    while (t--)
    {
        int d, n;
        GETII(d, n);

        memset(grid, 0, 1025*1025*sizeof(int));
        while (n--)
        {
            int x, y, i;
            GETIII(x, y, i);
            for (int r = x - d; r <= x + d; ++r)
                for (int c = y - d; c <= y + d; ++c) 
                {
                    if (r >= 0 && r < 1025 && c >= 0 && c < 1025)
                    grid[r][c] += i;
                }
        }

        int maxrat = 0, r, c;
        for (int i = 0; i < 1025; ++i)
            for (int j = 0; j < 1025; ++j)
                if (grid[i][j] > maxrat) 
                {
                    maxrat = grid[i][j];
                    r = i;
                    c = j;
                }

        printf("%d %d %d\n", r, c, maxrat);
    }
    
    return 0;
}

#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m, c;
    scanf(" %d", &n);
    while (n--)
    {
        scanf(" %d %d", &m, &c);

        int garment[20][21], reachable[2][201];
        memset(garment, 0, sizeof(garment));
        memset(reachable, 0, sizeof(reachable));

        for (int i = 0; i < c; ++i)
        {
            scanf(" %d", &garment[i][0]);
            for (int j = 1; j <= garment[i][0]; ++j)
                scanf(" %d", &garment[i][j]);
        }

        // init
        for (int i = 1; i <= garment[0][0]; ++i)
            if (m - garment[0][i] >= 0)
                reachable[0][m - garment[0][i]] = 1;

        // step
        int curi = 1;
        for (int i = 1; i < c; ++i, curi = 1 - curi) 
        {
            memset(reachable[curi], 0, sizeof(reachable[curi]));
            for (int rem = 0; rem <= m; ++rem) 
            {
                if (reachable[1 - curi][rem] == 1)
                    for (int mod = 1; mod <= garment[i][0]; ++mod)
                        if (rem - garment[i][mod] >= 0)
                            reachable[curi][rem - garment[i][mod]] = 1;
            }
        }

        int maxm = -1;
        for (int rem = 0; rem <= m; ++rem)
        {
            if (reachable[1 - curi][rem] == 1)
            {
                maxm = m - rem;
                break;
            }
        }

        if (maxm == -1)
            printf("no solution\n");
        else
            printf("%d\n", maxm);
    }
    
    return 0;
}

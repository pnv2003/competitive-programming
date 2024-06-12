#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    int price[1000], weight[1000];
    int value[2][31];

    int t;
    scanf(" %d", &t);
    while (t--)
    {
        scanf(" %d", &n);
        for (int i = 0; i < n; ++i)
            scanf(" %d %d", &price[i], &weight[i]);
        
        int g;
        scanf(" %d", &g);

        int sumval = 0, maxw;
        while (g--)
        {
            scanf(" %d", &maxw);
            memset(value, -1, sizeof(value));

            // init
            if (maxw >= weight[0])
                value[0][maxw - weight[0]] = price[0];
            value[0][maxw] = 0;

            // step
            int curi = 1;
            for (int i = 1; i < n; ++i, curi = 1 - curi)
            {
                memset(value[curi], -1, sizeof(value[curi]));
                for (int remw = 0; remw <= maxw; ++remw)
                {
                    if (value[1 - curi][remw] != -1)
                    {
                        if (remw >= weight[i])
                            value[curi][remw - weight[i]] = max(value[curi][remw - weight[i]], 
                                                                value[1 - curi][remw] + price[i]);
                        value[curi][remw] = max(value[curi][remw],
                                                value[1 - curi][remw]);
                    }
                }
            }

            int maxval = -1;
            for (int remw = 0; remw <= maxw; ++remw)
            {
                if (value[1 - curi][remw] != -1)
                    maxval = max(maxval, value[1 - curi][remw]);
            }
            sumval += maxval;
        }
        printf("%d\n", sumval);
    }
    
    return 0;
}

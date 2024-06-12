#include <cstdio>
#include <cmath>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using bit_t = ull;
#define SETBIT(x,i) x |= (1ULL << i)
#define CLRBIT(x,i) x &= (~(1ULL << i))
#define TGLBIT(x,i) x ^= (1ULL << i)
#define GETBIT(x,i) ((x >> i) & 1ULL)
#define CLRALL(x) x = (x & 0)
#define SETALL(x) x = ((1ULL << (CHAR_BIT*sizeof(x))) - 1ULL)
#define GENMASK(l, r) (((1ULL << (r - l)) - 1) << l)
#define SETBITMASK(x, mask) x |= (mask)
#define CLRBITMASK(x, mask) x &= (~(mask))

int row[8]{};
int qrow, qcol, line;
bit_t checkrow, checkld, checkrd;

void backtrack(int col)
{
    if (col == 8 && row[qcol] == qrow)
    {
        printf("%2d      %d", line++, row[0] + 1);
        for (int i = 1; i < 8; ++i)
            printf(" %d", row[i] + 1);
        printf("\n");
        return;
    }

    for (int r = 0; r < 8; ++r)
    {
        if (col == qcol && r != qrow)
            continue;
        if (GETBIT(checkrow, r))
            continue;
        if (GETBIT(checkld, r - col + 7))
            continue;
        if (GETBIT(checkrd, r + col))
            continue;

        row[col] = r;
        SETBIT(checkrow, r);
        SETBIT(checkld, r - col + 7);
        SETBIT(checkrd, r + col);
        backtrack(col + 1);
        CLRBIT(checkrow, r);
        CLRBIT(checkld, r - col + 7);
        CLRBIT(checkrd, r + col);
    }
}

int main(int argc, char const *argv[])
{
    int t;
    scanf(" %d", &t);
    while (t--)
    {
        scanf(" %d %d", &qrow, &qcol);
        qrow--; qcol--;
        line = 1;
        checkrow = 0;
        checkld = 0;
        checkrd = 0;

        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        backtrack(0);
        if (t) printf("\n");
    }
    return 0;
}

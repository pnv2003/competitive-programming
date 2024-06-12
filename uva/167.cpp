#include <cstdio>
#include <cstring>
using namespace std;
using bit_t = unsigned long long;
#define SETBIT(x,i) x |= (1ULL << i)
#define CLRBIT(x,i) x &= (~(1ULL << i))
#define TGLBIT(x,i) x ^= (1ULL << i)
#define GETBIT(x,i) ((x >> i) & 1ULL)
#define CLRALL(x) x = (x & 0)
#define SETALL(x) x = ((1ULL << (CHAR_BIT*sizeof(x))) - 1ULL)
#define GENMASK(l, r) (((1ULL << (r - l)) - 1) << l)
#define SETBITMASK(x, mask) x |= (mask)
#define CLRBITMASK(x, mask) x &= (~(mask))
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int board[8][8];
bit_t checkrow, checkld, checkrd;
int sum, maxsum;

void backtrack(int col)
{
    if (col == 8)
    {
        if (sum > maxsum)
            maxsum = sum;
        return;
    }

    for (int row = 0; row < 8; ++row)
    {
        if (!GETBIT(checkrow, row) && 
            !GETBIT(checkld, row - col + 7) &&
            !GETBIT(checkrd, row + col))
        {
            SETBIT(checkrow, row);
            SETBIT(checkld, row - col + 7);
            SETBIT(checkrd, row + col);
            sum += board[row][col];
            backtrack(col + 1);
            CLRBIT(checkrow, row);
            CLRBIT(checkld, row - col + 7);
            CLRBIT(checkrd, row + col);
            sum -= board[row][col];
        }
    }
}

int main(int argc, char const *argv[])
{
    // FILEIO;
    int k;
    scanf(" %d", &k);

    while (k--)
    {
        memset(board, 0, 8*8*sizeof(int));
        checkrow = 0;
        checkld = 0;
        checkrd = 0;
        sum = 0; 
        maxsum = 0;

        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                scanf(" %d", &board[i][j]);
                
        backtrack(0);
        printf("%5d\n", maxsum);   
    }

    return 0;
}

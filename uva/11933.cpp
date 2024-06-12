#include <iostream>
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

int main(int argc, char const *argv[])
{
    bit_t n;
    while (cin >> n)
    {
        if (n == 0) break;

        bit_t a = 0, b = 0;
        int turn = 1;
        for (int i = 0; i < 32; ++i)
        {
            if (GETBIT(n, i)) 
            {
                CLRBIT(n, i);
                (turn % 2 == 0)
                    ? SETBIT(b, i)
                    : SETBIT(a, i);
                ++turn;
            }
        }
        cout << a << " " << b << "\n";
    }
    
    return 0;
}

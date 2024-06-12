#include <iostream>
#include <cstring>
#include <algorithm>
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
    int n;
    int weight[1 << 15];
    memset(weight, 0, sizeof(weight));
    while (cin >> n)
    {
        for (int i = 0; i < (1 << n); ++i)
            cin >> weight[i];
        
        int potency[1 << 15];
        memset(potency, 0, sizeof(potency));
        for (bit_t i = 0; i < (1 << n); ++i)
        {
            int pot = 0;
            for (int p = 0; p < n; ++p)
            {
                bit_t neighbor = i;
                TGLBIT(neighbor, p);
                pot += weight[neighbor];
            }
            potency[i] = pot;
        }

        int maxsum = 0;
        for (bit_t i = 0; i < (1 << n); ++i)
        {
            for (int p = 0; p < n; ++p)
            {
                bit_t neighbor = i;
                TGLBIT(neighbor, p);
                maxsum = max(maxsum, potency[i] + potency[neighbor]);
            }
        }
        cout << maxsum << "\n";
    }
    
    return 0;
}

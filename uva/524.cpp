#include <iostream>
#include <cstring>
#include <set>
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

int n;
bit_t primes;
int ring[17];
set<int> used;

void init()
{
    primes = 0;
    for (int i = 0; i <= 32; ++i)
    {
        if (i == 0 || i == 1) continue;

        bool check = true;
        for (int j = 2; j < i; ++j)
        {
            if (i % j == 0) 
            {
                check = false;
                break;
            }
        }
        if (check)
            SETBIT(primes, i);
    }
}

void backtrack(int idx)
{
    if (idx == n)
    {
        if (!GETBIT(primes, ring[n - 1] + ring[0])) return;
        for (int i = 0; i < n; ++i)
        {
            cout << ring[i];
            if (i == n - 1) cout << "\n";
            else cout << " ";
        }
        return;
    }

    for (int i = 2; i <= n; ++i)
    {
        if (used.count(i) > 0) continue;

        if (!GETBIT(primes, i + ring[idx - 1]))
            continue;
        
        ring[idx] = i;
        used.insert(i);
        backtrack(idx + 1);
        used.erase(i);
    }
}

int main(int argc, char const *argv[])
{
    init();

    int id = 1;
    while (cin >> n)
    {
        memset(ring, 0, sizeof(ring));
        used.clear();

        if (id > 1) cout << "\n";
        cout << "Case " << id++ << ":\n";

        ring[0] = 1;
        used.insert(1);
        backtrack(1);
    }
    
    return 0;
}

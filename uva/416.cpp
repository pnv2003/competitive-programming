#include <iostream>
#include <cstring>
#include <string>
// #include <map>
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
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

bit_t LED[10];
string LEDstr[10] =
{
    "1111110",
    "0110000",
    "1101101",
    "1111001",
    "0110011",
    "1011011",
    "1011111",
    "1110000",
    "1111111",
    "1111011"
};
// map<bit_t, int> decoder;

void init_LED()
{
    memset(LED, 0, sizeof(LED));
    for (int i = 0; i < 10; ++i) 
    {
        bit_t led = 0;
        for (int j = 0; j < 7; ++j)
        {
            if (LEDstr[i][j] == '1')
                SETBIT(led, j);
        }
        LED[i] = led;
        // decoder[LED[i]] = i;
    }
}

bit_t string_to_LED(const string& str)
{
    bit_t led = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == 'Y')
            SETBIT(led, i);
    }
    return led;
}

bit_t seq[10], test[10];
bit_t burned;
int n;

bool check()
{
    for (int i = 0; i < n; ++i)
    {
        auto s = seq[i], t = test[i];
        for (int j = 0; j < 7; ++j)
        {
            if (GETBIT(burned, j) && GETBIT(s, j))
                return false;
            
            if (GETBIT(s, j) && !GETBIT(t, j))
                return false;

            if (!GETBIT(s, j) && GETBIT(t, j))
                SETBIT(burned, j);
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    FASTIO;
    init_LED();
    
    while (cin >> n && n != 0)
    {
        for (int i = 0; i < n; ++i)
        {
            string s;
            cin >> s;
            seq[i] = string_to_LED(s);
        }

        bool match = false;
        for (int i = 9; i >= n - 1; --i)
        {
            burned = 0;
            for (int j = 0; j < n; ++j)
                test[j] = LED[i - j];

            if (check())
            {
                match = true;
                break;
            }
        }

        cout << 
        (
            match
                ? "MATCH\n"
                : "MISMATCH\n"
        );
    }
    
    return 0;
}

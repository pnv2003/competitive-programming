#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;
    
    int n;
    vector<int> input{2, 4, 6, 8};
    vector<vector<long>> result(10);

    for (int i = 0; i < 4; ++i)
    {
        n = input[i];
        long num = 0, maxnum, divisor;
        if (n == 2)     { maxnum = 100; divisor = 10; }
        else if (n == 4){ maxnum = 10000; divisor = 100; }
        else if (n == 6){ maxnum = 1000000; divisor = 1000; }
        else            { maxnum = 100000000; divisor = 10000; }
        for (int num = 0; num < maxnum; ++num)
        {
            long fst = num / divisor;
            long snd = num % divisor;
            if ((fst + snd) * (fst + snd) == num)
                result[n].push_back(num);
        }
    }
    
    while (cin >> n)
    {
        for (long num: result[n])
            cout << setw(n) << setfill('0') << num << "\n";
    }
    
    return 0;
}

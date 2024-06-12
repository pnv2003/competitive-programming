#include <iostream>
#include <vector>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int n;
vector<int> coin_types;
vector<bool> check;

void withdraw(int money)
{
    if (money == 0) return;
    for (int i = n - 1; i >= 0; --i)
    {
        if (coin_types[i] <= money) 
        {
            check[i] = true;
            withdraw(money - coin_types[i]);
            break;
        }
    }
}

int main(int argc, char const *argv[])
{
    FASTIO;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int total = 0;  
        coin_types.assign(n, 0);
        check.assign(n, false);
        for (int i = 0; i < n; ++i) 
        {
            cin >> coin_types[i];
            total += coin_types[i];
        }

        withdraw(total);
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            if (check[i])
                ++cnt;
        cout << cnt << "\n";
    }
    
    return 0;
}

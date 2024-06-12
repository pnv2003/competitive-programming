#include <iostream>
#include <vector>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> sales;
        while (n--)
        {
            int s;
            cin >> s;
            sales.push_back(s);
        }

        int total = 0;
        for (int i = 1; i < sales.size(); ++i)
        {
            int cnt = 0;   
            for (int j = 0; j < i; ++j)
            {
                if (sales[j] <= sales[i])
                    ++cnt;
            }
            total += cnt;
        }

        cout << total << "\n";
    }
    
    return 0;
}

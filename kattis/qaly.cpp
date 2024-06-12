#include <iostream>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    double total = 0;
    while (n--)
    {
        double q, y;
        cin >> q >> y;
        total += q*y;
    }
    cout << total;
    
    return 0;
}

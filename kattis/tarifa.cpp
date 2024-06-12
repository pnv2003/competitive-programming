#include <iostream>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;
    // FILEIO;
    int x, n;
    cin >> x >> n;

    int val = 0;
    while (n--)
    {
        int p;
        cin >> p;
        val += x - p;
    }
    cout << val + x;
    
    return 0;
}

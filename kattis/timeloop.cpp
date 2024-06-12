#include <iostream>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cout << i + 1 << " Abracadabra";
        if (i != n) {
            cout << "\n";
        }
    }
    
    return 0;
}

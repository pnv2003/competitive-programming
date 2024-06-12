#include <iostream>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    int a, b, c, n;
    cin >> a >> b >> c >> n;

    string res = "YES";
    if (a < 1 || b < 1 || c < 1 || a + b + c < n || n < 3) {
        res = "NO";
    }
    cout << res;
    
    return 0;
}

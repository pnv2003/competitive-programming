#include <iostream>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;

    string res = "";
    if (n <= m) {
        res = "Dr. Chaz will have " + to_string(m - n) + (m - n == 1 ? " piece" : " pieces") + " of chicken left over!";
    } else {
        res = "Dr. Chaz needs " + to_string(n - m) + " more" + (n - m == 1 ? " piece" : " pieces") + " of chicken!";
    }
    cout << res;
    return 0;
}

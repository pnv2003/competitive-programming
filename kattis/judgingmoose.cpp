#include <iostream>
#include <string>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    int l, r;
    cin >> l >> r;
    string res = "";

    if (l == 0 && r == 0) {
        res = "Not a moose";
    } else if (l == r) {
        res = "Even " + to_string(r*2);
    } else {
        res = "Odd " + to_string(l > r ? l*2 : r*2);
    }

    cout << res;
    return 0;
}

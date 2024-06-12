#include <iostream>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    string date;
    getline(cin >> ws, date);

    if (date == "OCT 31" || date == "DEC 25") {
        cout << "yup";
    } else {
        cout << "nope";
    }
    return 0;
}

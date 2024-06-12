#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;

    int ngroup;
    while (cin >> ngroup)
    {
        if (ngroup == 0) break;

        string str;
        cin >> str;

        int glen = str.size() / ngroup;
        auto it = str.begin();

        while (it != str.end())
        {
            reverse(it, it + glen);
            it += glen;
        }
        
        cout << str << "\n";
    }
    
    return 0;
}

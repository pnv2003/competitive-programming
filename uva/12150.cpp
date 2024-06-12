#include <iostream>
#include <vector>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;

    int ncar;
    while (cin >> ncar)
    {
        if (ncar == 0) break;

        vector<int> start(ncar, -1);
        int c, p;
        bool mal = false;
        for (int i = 0; i < ncar; ++i)
        {
            cin >> c >> p;
            if (i + p < 0 || 
                i + p >= ncar ||
                start[i + p] != -1) 
                mal = true;
            else if (!mal)
                start[i + p] = c;
        }

        if (mal)
            cout << "-1\n";
        else
            for (int i = 0; i < ncar; ++i)
            {
                cout << start[i];
                if (i + 1 == ncar)
                    cout << "\n";
                else
                    cout << " ";
            }
    }

    return 0;
}

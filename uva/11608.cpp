#include <iostream>
#include <vector>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;

    int s, id = 1;
    while (cin >> s)
    {
        if (s < 0) break;

        vector<int> prob_crt(12), prob_use(12);
        prob_crt[0] = s;
        int p;
        for (int i = 0; i < 12; ++i)
        {
            if (i == 11)
                cin >> p;
            else
                cin >> prob_crt[i + 1];
            
        }
        for (int i = 0; i < 12; ++i)
        {
            cin >> prob_use[i];
        }

        cout << "Case " << id++ << ":\n";

        int acc = 0;
        for (int i = 0; i < 12; ++i)
        {
            acc += prob_crt[i] - prob_use[i];
            if (acc < 0)
            {
                cout << "No problem. :(\n";
                acc += prob_use[i]; // reset;
            }
            else 
            {
                cout << "No problem! :D\n";
            }
        }
    }
    
    return 0;
}

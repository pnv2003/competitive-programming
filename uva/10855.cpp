#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;
    int N, n;
    while (cin >> N >> n)
    {
        if (N == 0 && n == 0) break;

        vector<string> bigsq, sq;
        for (int i = 0; i < N; ++i)
        {
            string s;
            cin >> s;
            bigsq.push_back(s);
        }
        for (int i = 0; i < n; ++i)
        {
            string s;
            cin >> s;
            sq.push_back(s);
        }

        vector<int> sqcount(4, 0);
        for (int I = 0; I < N; ++I)
        {
            for (int J = 0; J < N; ++J)
            {
                if (I + n > N || J + n > N) continue; // out

                vector<bool> check(4, true);
                for (int i = 0; i < n; ++i)
                {
                    for (int j = 0; j < n; ++j)
                    {
                        char cur = sq[i][j];
                        if (cur != bigsq[I + i][J + j])                check[0] = false;
                        if (cur != bigsq[J + j][I + n - 1 - i])        check[1] = false;
                        if (cur != bigsq[I + n - 1 - i][J + n - 1 - j])check[2] = false;
                        if (cur != bigsq[J + n - 1 - j][I + i])        check[3] = false;
                    }
                }
                for (int i = 0; i < 4; ++i)
                    if (check[i])
                        ++sqcount[i];
            }
        }

        for (int i = 0; i < 4; ++i)
        {
            cout << sqcount[i];
            if (i == 3) cout << "\n";
            else cout << " ";
        }
    }
    
    return 0;
}

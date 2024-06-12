#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;

    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;

        vector<int> front(k), side(k);
        for (int i = 0; i < k; ++i) cin >> front[i];
        for (int i = 0; i < k; ++i) cin >> side[i];

        sort(front.begin(), front.end()); // cols
        sort(side.begin(), side.end()); // rows

        vector<vector<int>> htable(k, vector<int>(k, 0));

        int n = 0, m = 0;
        for (int i = 0; i < k; ++i)
        {
            bool flag = false;
            for (int j = 0; j < k; ++j)
            {
                if (i == 0)
                {
                    htable[i][j] = front[j];
                    n += front[j];
                }

                if (htable[i][j] > side[i] || 
                    (htable[i][j] == side[i] && flag && i + 1 < k))
                {
                    htable[i + 1][j] = htable[i][j];
                    htable[i][j] = 0;
                }
                else if (htable[i][j] == side[i])
                    flag = true;
                
                m += min(side[i], front[j]) - htable[i][j];
            }
            if (!flag) 
            {
                n += side[i];
                m -= side[i];
            }
        }

        cout << "Matty needs at least "
             << n
             << " blocks, and can add at most "
             << m
             << " extra blocks.\n";
    }

    return 0;
}

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int post[12];
int s, d, maxs;

void backtrack(int month)
{
    if (month == 12)
    {
        int surplus5 = post[0] + post[1] + post[2] + post[3] + post[4];
        if (surplus5 >= 0) return;

        int totals = surplus5;
        for (int i = 5; i < 12; ++i)
        {
            surplus5 += post[i];
            surplus5 -= post[i - 5];
            if (surplus5 >= 0) return;

            totals += post[i];
        }

        maxs = max(maxs, totals);
        return;
    }

    post[month] = -d;
    backtrack(month + 1);
    post[month] = s;
    backtrack(month + 1);
}

int main(int argc, char const *argv[])
{
    FASTIO;
    while (cin >> s >> d)
    {
        maxs = -d*12;
        memset(post, 0, sizeof(post));
        backtrack(0);

        if (maxs < 0)
            cout << "Deficit\n";
        else 
            cout << maxs << "\n";
    }

    return 0;
}

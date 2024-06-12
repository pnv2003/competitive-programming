#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

vector<string> fst(6), snd(6), fstcol(5, string(6, ' '));
vector<set<char>> sndcol(5);
string pwd;
int k, order;
bool found;

void scan(int idx)
{
    if (idx == 5)
    {
        if (order++ == k - 1) 
        {
            found = true;
            cout << pwd << "\n";
        }
        return;
    }

    set<char> used;
    for (int i = 0; i < 6; ++i)
    {
        auto ch = fstcol[idx][i];
        if (used.count(ch) > 0) continue;
        if (sndcol[idx].count(ch) == 0) continue;

        pwd[idx] = ch;
        used.insert(ch);
        scan(idx + 1);
    }
}

int main(int argc, char const *argv[])
{
    FASTIO;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> k;
        for (int i = 0; i < 6; ++i) 
            cin >> fst[i];
        for (int i = 0; i < 6; ++i)
            cin >> snd[i];

        for (int i = 0; i < 5; ++i)
        {
            sndcol[i].clear();
            for (int j = 0; j < 6; ++j) 
            {
                fstcol[i][j] = fst[j][i];
                sndcol[i].insert(snd[j][i]);
            }
            sort(fstcol[i].begin(), fstcol[i].end());
        }

        order = 0;
        pwd.assign(5, ' ');
        found = false;
        scan(0);
        if (!found)
            cout << "NO\n";
    }
    return 0;
}


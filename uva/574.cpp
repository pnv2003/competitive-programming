#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int list[12];
vector<int> result;
int t, n, sum;
bool none;

void backtrack(int idx)
{
    if (sum == t)
    {
        none = false;
        for (int i = 0; i < result.size(); ++i)
        {
            cout << result[i];
            if (i == result.size() - 1) cout << "\n";
            else cout << "+";
        }
        return;
    }
    else if (sum > t || idx >= n)
        return;

    set<int> used;
    for (int i = idx; i < n; ++i)
    {
        if (used.count(list[i]) > 0) continue;
        if (sum + list[i] > t) continue;
        used.insert(list[i]);

        sum += list[i];
        result.push_back(list[i]);
        backtrack(i + 1);
        sum -= list[i];
        result.pop_back();
    }
}

int main(int argc, char const *argv[])
{
    FASTIO;
    
    while (cin >> t >> n && t != 0 && n != 0)
    {
        for (int i = 0; i < n; ++i)
            cin >> list[i];

        sum = 0; none = true;
        cout << "Sums of " << t << ":\n";
        backtrack(0);
        if (none)
            cout << "NONE\n";
    }
    
    return 0;
}

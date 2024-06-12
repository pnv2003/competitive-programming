#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int n, m;
pair<int, int> initl, initr;
vector<pair<int, int>> domino, solitaire;
set<pair<int, int>> used;
int cnt;

void fillspace(int idx)
{
    if (idx == n + 1)
    {
        if (solitaire[n].second == solitaire[n + 1].first)
            ++cnt;
        return;
    }

    if (cnt > 0) return;

    for (int i = 0; i < m; ++i)
    {
        pair<int, int> dom = domino[i];
        pair<int, int> revdom = { dom.second, dom.first };
        if (used.count(dom) > 0 || used.count(revdom) > 0) continue;
        
        bool match = false;
        pair<int, int> piece;
        if (dom.first == solitaire[idx - 1].second) 
        {
            match = true;
            piece = dom;
        }
        else if (revdom.first == solitaire[idx - 1].second)
        {
            match = true;
            piece = revdom;
        }
        else 
            match = false;

        if (match)
        {
            solitaire[idx] = piece;
            used.insert(dom);
            used.insert(revdom);
            fillspace(idx + 1);
            used.erase(dom);
            used.erase(revdom);
        } 
    }
}

int main(int argc, char const *argv[])
{
    FASTIO;
    while (cin >> n && n != 0)
    {
        cin >> m;
        solitaire.assign(n + 2, {});
        domino.assign(m, {});
        used.clear();
        cnt = 0;

        cin >> solitaire[0].first >> solitaire[0].second
            >> solitaire[n + 1].first >> solitaire[n + 1].second;
        for (int i = 0; i < m; ++i)        
            cin >> domino[i].first >> domino[i].second;
        fillspace(1);
        cout << 
        (
            cnt > 0
            ? "YES\n"
            : "NO\n"
        );
    }
    
    return 0;
}

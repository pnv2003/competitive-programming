#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;
    // FILEIO;
    string s, wp, bp;
    cin >> s >> wp;

    if (wp == "Black:") {
        wp = "";
        if (!(cin >> bp)) {
            bp = "";
        }
    } else {
        cin >> s;
        if (!(cin >> bp)) {
            bp = "";
        }
    }

    vector<vector<char>> pmap(8, vector<char>(8, '_'));

    stringstream ss(wp);
    string w;
    while (getline(ss, w, ','))
    {
        int r = w.back() - '1';
        int c = w[w.size() - 2] - 'a';
        pmap[r][c] = w.size() == 2 ? 'P' : w[0];
    }
    
    ss.clear();
    ss.str(bp);
    string b;
    while (getline(ss, b, ','))
    {
        int r = b.back() - '1';
        int c = b[b.size() - 2] - 'a';
        pmap[r][c] = b.size() == 2 ? 'p' : tolower(b[0]);
    }

    string rowsep = "+---+---+---+---+---+---+---+---+";

    
    for (int r = 7; r >= 0; --r) {
        cout << rowsep << "\n|";
        for (int c = 0; c < 8; ++c) {
            char fill = ((r + c) % 2 == 0) ? ':' : '.';

            cout << fill;
            char p = pmap[r][c];
            if (p == '_') {
                cout << fill;
            } else {
                cout << p;
            }
            cout << fill << "|";
        }
        cout << "\n";
    }
    cout << rowsep;

    return 0;
}

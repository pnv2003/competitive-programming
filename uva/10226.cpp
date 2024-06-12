#include <iostream>
#include <iomanip>
#include <string>
#include <map>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;
    int tc, id = 1; 
    cin >> tc;
    string s; getline(cin, s); getline(cin, s);
    while (tc--)
    {
        map<string, int> treepop;
        string tree;
        int treecnt = 0;
        while (getline(cin, tree) && !tree.empty())
        {
            if (treepop.find(tree) == treepop.end())
                treepop[tree] = 0;
            ++treepop[tree];
            ++treecnt;
        }

        if (id++ > 1) cout << "\n";
        for (auto it = treepop.begin(); it != treepop.end(); ++it)
            cout << it->first << " " 
                 << fixed << setprecision(4) 
                 << it->second * 100.0 / treecnt << "\n";
    }
    
    return 0;
}

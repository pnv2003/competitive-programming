#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

struct Info
{
    int id;
    int penalty;
    vector<int> attempt;
    vector<bool> solved;
    int nsolved;
};

int main(int argc, char const *argv[])
{
    FASTIO;
    int tc, id = 1;
    cin >> tc;
    string line; 
    getline(cin, line); // skip endline
    getline(cin, line); // skip blank line

    while (tc--)
    {
        vector<Info> scoreboard(101, Info{ -1, 0, vector<int>(), vector<bool>(), 0 });
        vector<int> scoreindex;
        int cont, prob, time;
        char verd;

        while (getline(cin, line))
        {
            if (line == "") break;

            stringstream ss{ line };
            ss >> cont >> prob >> time >> verd;
            
            if (scoreboard[cont].id == -1) 
            {
                scoreboard[cont] = 
                    Info
                    {   
                        cont, 
                        0, 
                        vector<int>(10, 0), 
                        vector<bool>(10, false), 
                        0 
                    };
                scoreindex.push_back(cont);
            }

            Info& info = scoreboard[cont];
            if (verd == 'I')
                info.attempt[prob]++;
            else if (verd == 'C')
            {
                if (!info.solved[prob]) 
                {
                    info.solved[prob] = true;
                    info.nsolved++;
                    info.penalty += time + info.attempt[prob]*20;
                }
            }
        }        

        sort(scoreindex.begin(), scoreindex.end(),
            [&scoreboard](int i1, int i2)
            {
                auto c1 = scoreboard[i1], c2 = scoreboard[i2];
                if (c1.nsolved > c2.nsolved) return true;
                if (c1.nsolved < c2.nsolved) return false;
                if (c1.penalty < c2.penalty) return true;
                if (c1.penalty > c2.penalty) return false;
                return (c1.id < c2.id);
            });

        if (id++ > 1) cout << "\n";
        for (int i: scoreindex)
        {
            auto c = scoreboard[i];
            cout << c.id << " "
                 << c.nsolved << " "
                 << c.penalty << "\n";
        }
    }
    
    return 0;
}

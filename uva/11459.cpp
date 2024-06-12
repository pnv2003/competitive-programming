#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct 
{
    int begin;
    int end;
} snake_ladder_t;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int nplayer, nobj, ndiceroll;
        cin >> nplayer >> nobj >> ndiceroll;

        vector<snake_ladder_t> vobj;
        vector<int> vpos(nplayer, 1);
        while (nobj--)
        {
            snake_ladder_t obj;
            cin >> obj.begin >> obj.end;
            vobj.push_back(obj);
        }

        int dicetop, turn = 0;
        bool stop = false;
        while (ndiceroll--)
        {
            cin >> dicetop;

            if (!stop && !vpos.empty())
            {
                vpos[turn] += dicetop;

                auto objfound = find_if(vobj.begin(), vobj.end(), 
                                    [&](snake_ladder_t obj)
                                    { return vpos[turn] == obj.begin; });
            
                if (objfound != vobj.end())
                    vpos[turn] = objfound->end;

                if (vpos[turn] >= 100)
                {
                    vpos[turn] = 100;
                    stop = true;
                }

                ++turn;
                if (turn == nplayer) 
                    turn = 0;
            }
        }

        for (size_t i = 0; i < vpos.size(); i++)
            cout << "Position of player " << i + 1 << " is " << vpos[i] << ".\n";
    }
    
    return 0;
}

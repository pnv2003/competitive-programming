#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using psi = pair<string, int>;
using vp = vector<psi>;
#define ALL(x) x.begin(), x.end()

int main(int argc, char const *argv[])
{
    int np;
    vp vper;
    int id = 0;
    while (cin >> np)
    {
        if (id > 0) cout << "\n";
        string name;
        for (int i = 0; i < np; ++i)
        {
            cin >> name;
            vper.push_back(psi{name, 0});
        }

        int money, nreceivers;
        for (int i = 0; i < np; ++i)
        {
            cin >> name >> money >> nreceivers;
            if (nreceivers == 0) continue;

            auto igiver = find_if(ALL(vper), 
                               [&](const psi& p) { return p.first == name; });

            int part = money / nreceivers;
            igiver->second -= nreceivers*part;

            while (nreceivers--)
            {
                cin >> name;
                auto ireceiver = find_if(ALL(vper), 
                                      [&](const psi& p){ return p.first == name; });
                ireceiver->second += part;
            }
        }

        for (const psi& p: vper)
            cout << p.first << " " << p.second << "\n";
        vper.clear();
        ++id;
    }
    return 0;
}

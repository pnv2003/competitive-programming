#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;

int main(int argc, char const *argv[])
{
    int ndevices, nops, fusecap, id = 1;

    for (;;)
    {
        cin >> ndevices >> nops >> fusecap;
        if (ndevices == 0) break;

        vi vcon;
        vi vstat;
        int cons;
        while (ndevices--)
        {
            cin >> cons;
            vcon.push_back(cons);
            vstat.push_back(0);
        }

        int op, power = 0, maxpower = 0;
        bool overheat = false;
        
        while (nops--)
        {
            cin >> op;
            op--;
            vstat[op] = 1 - vstat[op];

            if (vstat[op] == 1)
                power += vcon[op];
            else
                power -= vcon[op];

            if (power > fusecap)
                overheat = true;
            if (power > maxpower)
                maxpower = power;
        }
        cout << "Sequence " << id++ << "\n" <<
        (
            overheat ? 
            "Fuse was blown.\n\n" : 
            "Fuse was not blown.\n"
        );
        if (!overheat)
            cout << "Maximal power consumption was "
                    << maxpower << " amperes.\n\n";
    }
    return 0;
}

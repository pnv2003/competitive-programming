#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int pars, bud, hotels, weeks;
    while (cin >> pars >> bud >> hotels >> weeks)
    {
        bool stay = true;
        int hprice, slots, cost = -1;
        while (hotels--)
        {
            cin >> hprice;
            for (int w = 0; w < weeks; ++w)
            {
                cin >> slots;
                if (slots >= pars) 
                {
                    if (cost == -1 || hprice*pars < cost)
                        cost = hprice*pars;
                    if (cost <= bud)
                        stay = false;
                }
            }
        }
        if (stay)
            cout << "stay home\n";
        else
            cout << cost << "\n";
    }
    return 0;
}

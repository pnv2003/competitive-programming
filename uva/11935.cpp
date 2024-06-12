#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(int argc, char const *argv[])
{
    FASTIO;

    string line;
    double curloc = 0,
        cons_rate = 0,
        leak_rate = 0,
        fuel = 0,
        minfuel = 0; 
    double loc, amount;
    string event;
    while (getline(cin >> ws, line))
    {
        if (line == "0 Fuel consumption 0") break;

        stringstream ss{ line };
        ss >> loc >> event; 
        fuel -= (loc - curloc) * (cons_rate / 100 + leak_rate);
        curloc = loc;
        if (fuel < minfuel)
            minfuel = fuel;
        if (event == "Fuel")
        {
            ss >> event >> amount;
            cons_rate = amount;
        }
        else if (event == "Leak")
        {
            leak_rate++;
        }
        else if (event == "Gas")
        {
            ss >> event;
            fuel = 0;
        }
        else if (event == "Mechanic")
        {
            leak_rate = 0;
        }
        else // Goal 
        {
            printf("%.3f\n", -minfuel);
            curloc = 0;
            cons_rate = 0;
            leak_rate = 0;
            fuel = 0;
            minfuel = 0; 
            continue;
        }
    }
        
    return 0;
}

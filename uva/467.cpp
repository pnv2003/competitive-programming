#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Signal
{
    int cycle_time;
    int counter;
    bool green;
};

int main(int argc, char const *argv[])
{
    int id = 1;
    string line;
    while (getline(cin >> ws, line))
    {
        vector<Signal> signals;
        stringstream ss{ line };
        int ct, min_cycle_time = 1000;
        while (ss >> ct) 
        {
            Signal s;
            s.cycle_time = ct;
            s.green = true;
            s.counter = s.cycle_time - 5;
            signals.push_back(s);

            if (ct < min_cycle_time)
                min_cycle_time = ct;            
        }

        int sync_time = 0;
        // jump to unsync state
        sync_time += (min_cycle_time - 5);
        for (Signal& s: signals)
        {
            s.counter -= (min_cycle_time - 5);
            if (s.counter == 0)
            {
                s.green = false;
                s.counter = s.cycle_time + 5;
            }
        }

        // counters stop at sync state
        while (!all_of(signals.begin(), signals.end(), [](Signal s){ return s.green; }))
        {
            sync_time++;
            for (Signal& s: signals)
            {
                s.counter--;
                if (s.counter == 0)
                {
                    if (s.green)
                    {
                        s.green = false;
                        s.counter = s.cycle_time + 5;
                    }
                    else
                    {
                        s.green = true;
                        s.counter = s.cycle_time - 5;
                    }
                }
            }
        }

        cout << "Set " << id++ << " ";

        if (sync_time > 3600)
        {
            cout << "is unable to synch after one hour.\n";
        }
        else
        {
            cout << "synchs again at "
                 << sync_time / 60 
                 << " minute(s) and "
                 << sync_time % 60
                 << " second(s) after all turning green.\n";
        }
    }
    
    return 0;
}

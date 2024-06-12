#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n)
    {
        if (n == 0) break;

        int coach;
        while (cin >> coach)
        {
            if (coach == 0) break;

            stack<int> init; // n..1 (initial order)
            for (int i = 0; i < n; ++i)        
                init.push(n - i);
            stack<int> station;
            bool ok = true;

            for (int i = 0; i < n; ++i)
            {
                if (i > 0)
                    cin >> coach;
                if (!ok) 
                    continue;
                // wait for next coach in order
                while (station.empty() || station.top() != coach)
                {
                    // no more coaches (wrong order)
                    if (init.empty()) 
                    {
                        ok = false;
                        break;
                    }
                    // a coach enters the station
                    station.push(init.top());
                    init.pop();
                }
                if (ok)
                    // a coach leaves the station
                    station.pop();
            }

            cout << (ok ? "Yes\n" : "No\n");
        }
        cout << "\n";
    }
    
    return 0;
}

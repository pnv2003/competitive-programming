#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, s, q; // stations, stack cap, queue cap
        cin >> n >> s >> q;

        vector<queue<int>> cargo_queues;
        int cargo_count = 0;
        for (int i = 0; i < n; ++i)
        {
            int qi;
            cin >> qi;
            cargo_count += qi;

            queue<int> cq;
            while (qi--)
            {
                int dst;
                cin >> dst; dst--; // switch to 0-based
                cq.push(dst);
            }
            cargo_queues.push_back(cq);
        }

        stack<int> carrier;
        int station = 0, time = 0;

        while (cargo_count > 0)
        {
            auto& cq = cargo_queues[station];
            // unload
            while (!carrier.empty())
            {
                auto cargodst = carrier.top();
                carrier.pop();
                if (cargodst == station) // cargo reached its destination!
                {
                    --cargo_count;
                    ++time;
                }
                else
                {
                    if (cq.size() < q)
                    {
                        cq.push(cargodst);
                        ++time;
                    }
                    else
                    {
                        carrier.push(cargodst); // return back
                        break;
                    }
                }
            }
            
            // load
            while (carrier.size() < s)
            {
                if (cq.empty())
                    break; // failed
                auto cargodst = cq.front();
                cq.pop();
                carrier.push(cargodst);
                ++time;
            }   

            // move
            station = (station + 1) % n;
            time += 2;
        }  

        cout << time - 2 << "\n";      
    }
    
    return 0;
}

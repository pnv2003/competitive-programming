#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct
{
    const int rate;
    bool occupied;
} slot_t;

typedef struct
{
    const int weight;
    slot_t* slot;
} car_t;

int main(int argc, char const *argv[])
{
    int nspaces, ncars;
    cin >> nspaces >> ncars;

    vector<slot_t> vslot;
    vector<car_t> vcar;
    int rate;
    for (int i = 0; i < nspaces; ++i)
    {
        cin >> rate;
        vslot.push_back(slot_t{ rate, false });
    }

    int weight;
    for (int i = 0; i < ncars; ++i)
    {
        cin >> weight;
        vcar.push_back(car_t{ weight, nullptr });
    }

    int event;
    queue<int> q;
    int revenue = 0;
    for (int i = 0; i < 2*ncars; ++i)
    {
        cin >> event;
        if (event > 0)
            q.push(event);
        else 
        {
            vcar[(-event) - 1].slot->occupied = false;
            vcar[(-event) - 1].slot = nullptr;
        }

        while (!q.empty())
        {
            auto slot_found = find_if(vslot.begin(), vslot.end(), 
                                      [](const slot_t& s)
                                      {
                                        return s.occupied == false;
                                      });
            if (slot_found != vslot.end())
            {
                int carno = q.front();
                q.pop();
                vcar[carno - 1].slot = &(*slot_found);
                slot_found->occupied = true;
                revenue += vcar[carno - 1].weight * slot_found->rate;
            }
            else
                break;
        }
    }

    cout << revenue << "\n";

    return 0;
}

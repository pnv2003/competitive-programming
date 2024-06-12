#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#define ALL(x) x.begin(), x.end()
using namespace std;

int main(int argc, char const *argv[])
{
    int alice_ncards, betty_ncards;
    for (;;)
    {
        cin >> alice_ncards >> betty_ncards;
        if (alice_ncards == 0 && betty_ncards == 0) break;

        vector<int> alice_hand, betty_hand;
        int card;
        while (alice_ncards--)
        {
            cin >> card;
            alice_hand.push_back(card);
        }
        while (betty_ncards--)
        {
            cin >> card;
            betty_hand.push_back(card);
        }

        sort(ALL(alice_hand));
        sort(ALL(betty_hand));

        vector<int> alice_hand_unique = alice_hand,
                    betty_hand_unique = betty_hand;

        auto last = unique(ALL(alice_hand_unique));
        alice_hand_unique.erase(last, alice_hand_unique.end());
        last = unique(ALL(betty_hand_unique));
        betty_hand_unique.erase(last, betty_hand_unique.end());
        
        vector<int> alice_hand_tradable, betty_hand_tradable;
        set_difference(ALL(alice_hand_unique), 
                       ALL(betty_hand_unique), 
                       back_inserter(alice_hand_tradable));
        set_difference(ALL(betty_hand_unique),
                       ALL(alice_hand_unique),
                       back_inserter(betty_hand_tradable));

        cout << min(alice_hand_tradable.size(), betty_hand_tradable.size()) << "\n";
    }
    return 0;
}

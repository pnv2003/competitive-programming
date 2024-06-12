#include <iostream>
#include <vector>
#include <algorithm>
#define ALL(x) x.begin(), x.end()
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> princess_hand(3), prince_hand(2);
    
    for (;;)
    {
        cin >> princess_hand[0] 
            >> princess_hand[1]
            >> princess_hand[2]
            >> prince_hand[0]
            >> prince_hand[1];
        
        if (princess_hand[0] == 0) break;

        // worst play
        // princess: mid - max - min
        // prince:   min - mid - max

        sort(ALL(prince_hand));
        sort(ALL(princess_hand));
        princess_hand.push_back(princess_hand[0]);
        princess_hand.erase(princess_hand.begin());

        int card = 1;
        for (;;)
        {
            while (any_of(ALL(princess_hand), [card](int pc){ return pc == card; }))
                ++card;
            
            if (card > 52)
            {
                card = -1;
                break;
            }

            // case 1: min is dealt
            if (card < prince_hand[0])
            {
                if (prince_hand[0] > princess_hand[1]) // mid, max all won
                    break;
                if (prince_hand[1] > princess_hand[2] && card > princess_hand[0]) // only max won, need min to win
                    break;
            }
            // case 2: mid is dealt
            if (card > prince_hand[0] && card < prince_hand[1])
            {
                if (prince_hand[0] > princess_hand[0]) // min, max all won
                    break;
                if (prince_hand[1] > princess_hand[2] && card > princess_hand[1]) // only max won, need mid to win
                    break;
            }
            // case 3: max is dealt
            if (card > prince_hand[1])
            {
                if (prince_hand[0] > princess_hand[0] && prince_hand[1] > princess_hand[1]) // min, mid all won
                    break;
                if (prince_hand[0] > princess_hand[0] || prince_hand[1] > princess_hand[1]) // only min or mid won
                {
                    if (card > princess_hand[2]) // need max to win
                        break;
                }
            }
            ++card;
        }
        
        cout << card << "\n";
    }
        
    return 0;
}

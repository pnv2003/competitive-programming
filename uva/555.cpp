#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    string suit_order = "CDSH";
    string rank_order = "23456789TJQKA";

    unordered_map<char, int> umap_rank, umap_suit;
    for (int i = 0; i < rank_order.size(); ++i)
        umap_rank[rank_order[i]] = i;
    for (int i = 0; i < suit_order.size(); ++i)
        umap_suit[suit_order[i]] = i;

    char dealer;
    for (;;)
    {
        cin >> dealer;
        if (dealer == '#') break;

        string deal_order;
        switch (dealer)
        {
        case 'N':   deal_order = "ESWN";     break;
        case 'E':   deal_order = "SWNE";     break;
        case 'W':   deal_order = "NESW";     break;
        case 'S':   deal_order = "WNES";     break;
        default:
            break;
        }

        string deckstr, line;
        getline(cin >> ws, line);
        deckstr += line;
        getline(cin >> ws, line);
        deckstr += line;

        using hand_t = vector<string>;
        vector<hand_t> vhand(4);

        int turn = 0;
        while (!deckstr.empty())
        {
            string card = deckstr.substr(0, 2);
            deckstr = deckstr.substr(2, deckstr.size() - 2);
            
            vhand[turn].push_back(card);

            ++turn;
            if (turn == 4)
                turn = 0;
        }
        
        for (hand_t& hand: vhand)
        {
            sort(hand.begin(), hand.end(),
                 [&umap_rank, &umap_suit]
                 (const string& c1, const string& c2)
                 {
                    if (umap_suit[c1[0]] < umap_suit[c2[0]])
                        return true;
                    if (umap_suit[c1[0]] > umap_suit[c2[0]])
                        return false;

                    return (umap_rank[c1[1]] < umap_rank[c2[1]]);
                 });
        }
        
        string print_order = "SWNE";
        for (char player: print_order)
        {
            cout << player << ": ";
            auto index = deal_order.find(player);
            for (auto it = vhand[index].begin(); it != vhand[index].end(); ++it)
            {
                cout << *it;
                if (next(it) == vhand[index].end())
                    cout << "\n";
                else 
                    cout << " ";
            }
        }

    }
    return 0;
}

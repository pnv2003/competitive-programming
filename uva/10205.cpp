#include <iostream>
#include <string>
#include <vector>
using namespace std;
using deck_t = vector<string>;
using shuffle_t = vector<int>;
const string ranks = "23456789TJQKA";
const string suits = "CDHS";

void shuffleDeck(deck_t& deck, const shuffle_t& shuf)
{
    deck_t temp;
    for (size_t i = 0; i < deck.size(); ++i)
        temp.push_back(deck[i]);

    for (size_t newpos = 0; newpos < shuf.size(); ++newpos)
    {
        int oldpos = shuf[newpos] - 1;
        deck[newpos] = temp[oldpos];
    }
}

void printCard(const string& card)
{
    switch (card[0])
    {
    case 'T':   cout << 10;     break;
    case 'J':   cout << "Jack"; break;
    case 'Q':   cout << "Queen";break;
    case 'K':   cout << "King"; break;
    case 'A':   cout << "Ace";  break;
    default:    cout << card[0];break;
    }
    cout << " of ";
    switch (card[1])
    {
    case 'C':   cout << "Clubs";     break;
    case 'D':   cout << "Diamonds";  break;
    case 'H':   cout << "Hearts";    break;
    case 'S':   cout << "Spades";    break;
    default:
        break;
    }
    cout << "\n";
}

int main(int argc, char const *argv[])
{
    deck_t init_deck;
    for (char suit: suits)
    {
        for (char rank: ranks)
        {
            init_deck.push_back(string{ rank } + string{ suit });
        }
    }

    int t, id = 1;
    cin >> t;
    while (t--)
    {
        if (id > 1)
            cout << "\n";
        
        deck_t deck = init_deck;
        using shuffle_t = shuffle_t;
        vector<shuffle_t> vshuf;

        int nshufs;
        cin >> nshufs;
        while (nshufs--)
        {
            shuffle_t shuf;
            int num;
            for (int i = 0; i < 52; ++i)
            {
                cin >> num;
                shuf.push_back(num);
            }
            vshuf.push_back(shuf);
        }

        int shuf_id;
        cin.ignore();
        string line;
        while (getline(cin, line))    
        {
            if (line.empty())
                break;
            shuf_id = stoi(line);
            shuffleDeck(deck, vshuf[shuf_id - 1]);
        }
           
        for (const string& card: deck)
            printCard(card);

        ++id;
    }
    
    return 0;
}

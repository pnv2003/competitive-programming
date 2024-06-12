#include <iostream>
#include <string>
#include <vector>
#define DECK_SIZE 52
using namespace std;

typedef struct
{
    char rank;
    char suit;
} card_t;
using deck_t = vector<card_t>;

int card_value(card_t card)
{
    switch (card.rank)
    {
    case 'T':
    case 'J':
    case 'Q':
    case 'K':
    case 'A':
        return 10;
    default:
        break;
    }
    return (card.rank - '0');
}

int main(int argc, char const *argv[])
{
    int t, id = 1;
    cin >> t;
    while (t--)
    {
        deck_t deck, hand;
        string cardstr;
        for (int i = 0; i < DECK_SIZE; ++i)
        {
            cin >> cardstr;
            if (i < 25)
                deck.push_back(card_t{ cardstr[0], cardstr[1] });
            else
                hand.push_back(card_t{ cardstr[0], cardstr[1] });
        }

        int x = 0, y = 0;
        card_t card; 
        for (int i = 0; i < 3; ++i)
        {
            card = deck.back();
            deck.pop_back();

            x = card_value(card);
            y += x;
            for (int j = 0; j < (10 - x); ++j)
                deck.pop_back();
        }

        deck.insert(deck.end(), hand.begin(), hand.end());

        cout << "Case " << id++ << ": ";
        cout << deck[y - 1].rank << deck[y - 1].suit << "\n";
    }
    
    return 0;
}

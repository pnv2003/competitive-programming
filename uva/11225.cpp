#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
using std_rank_t = char;
using std_suit_t = char;
using trump_rank_t = int;
// const string std_ranks = "123456789TVCDR";
// const string std_suits = "SHDC";
const vector<string> numbers = 
{
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eightteen",
    "nineteen",
    "twenty",
    "twenty-one"
};
unordered_map<string, int> umap_num;

void init()
{
    for (int i = 0; i < numbers.size(); ++i)
        umap_num[numbers[i]] = i + 1;
}

typedef enum class CardType
{
    STANDARD,
    TRUMP,
    FOOL
} card_type_t;

typedef struct
{  
    card_type_t type;

    std_rank_t rank;
    std_suit_t suit;
    trump_rank_t trump_rank;
} card_t;

std_suit_t toSuit_std(const string& str)
{
    if (str == "spades")
        return 'S';
    if (str == "hearts")
        return 'H';
    if (str == "diamonds")
        return 'D';
    // if (str == "clubs")
    return 'C';
}

std_rank_t toRank_std(const string& str)
{
    if (str == "ace")
        return '1';
    if (str == "ten")
        return 'T';
    if (str == "jack")
        return 'V';
    if (str == "knight")
        return 'C';
    if (str == "queen")
        return 'D';
    if (str == "king")
        return 'R';
    
    return ('0' + umap_num[str]);
}

trump_rank_t toRank_trump(const string& str)
{
    return umap_num[str];
}

bool isOudler(card_t card)
{
    if (card.type == CardType::FOOL)
        return true;
    if (card.type == CardType::TRUMP && 
        (card.trump_rank == 1 || card.trump_rank == 21))
        return true;
    return false;
}

int main(int argc, char const *argv[])
{
    init();

    int t, id = 1;
    cin >> t;
    while (t--)
    {
        int taker_ncard;
        cin >> taker_ncard;

        vector<card_t> taker_hand;
        string card_line, card_rank, card_suit;
        while (taker_ncard--)
        {
            getline(cin >> ws, card_line);
            stringstream ss{ card_line };

            ss >> card_rank;
            if (card_rank == "fool")
            {
                taker_hand.push_back(card_t
                { 
                    CardType::FOOL, 
                    ' ', 
                    ' ', 
                    0 
                });
            }
            else
            {
                ss >> card_suit;
                ss >> card_suit;

                if (card_suit == "trumps")
                    taker_hand.push_back(card_t
                    { 
                        CardType::TRUMP, 
                        ' ', 
                        ' ', 
                        toRank_trump(card_rank) 
                    });
                else
                    taker_hand.push_back(card_t
                    { 
                        CardType::STANDARD, 
                        toRank_std(card_rank), 
                        toSuit_std(card_suit), 
                        0 
                    });
            }
        }

        double target_point, taker_point = 0.0;
        int oudlers_count = count_if(taker_hand.begin(), taker_hand.end(),
                                    [](card_t card){ return isOudler(card); });

        switch (oudlers_count)
        {
        case 3:
            target_point = 36;
            break;
        case 2:
            target_point = 41;
            break;
        case 1:
            target_point = 51;
            break;
        case 0:
            target_point = 56;
        default:
            break;
        }

        for (card_t card: taker_hand)
        {
            taker_point += 0.5;

            if (isOudler(card))
                taker_point += 4;
            if (card.type == CardType::STANDARD)
            {
                if (card.rank == 'R')
                    taker_point += 4;
                else if (card.rank == 'D')
                    taker_point += 3;
                else if (card.rank == 'C')
                    taker_point += 2;
                else if (card.rank == 'V')
                    taker_point += 1;
            }
        }

        if (id > 1)
            cout << "\n";
        cout << "Hand #" << id++ << "\nGame ";
        if (taker_point < target_point)
            cout << "lost by " << target_point - taker_point << " point(s).\n";
        else
            cout << "won by " << taker_point - target_point << " point(s).\n";
    }   
    
    return 0;
}

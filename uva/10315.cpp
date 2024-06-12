#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define POKER_HAND_SIZE 5
#define ALL(x) x.begin(), x.end()
using rank_t = char;
using suit_t = char;

const string ranks = "23456789TJQKA";
const string suits = "CDHS";
unordered_map<char, int> umap_rank;

void poker_init()
{
    for (int i = 0; i < ranks.size(); ++i)
        umap_rank[ranks[i]] = i;
}

typedef struct
{
    rank_t rank;
    suit_t suit;    
} card_t;

typedef enum class PokerRank: int
{                       // additional information
    HIGH_CARD,          // none
    PAIR,               // position/value of the pair
    TWO_PAIRS,          // position/value of 2 pairs
    THREE_OF_A_KIND,    // position/value of the three
    STRAIGHT,           // none
    FLUSH,              // none
    FULL_HOUSE,         // position/value of the three, position/value of the pair
    FOUR_OF_A_KIND,     // position/value of the four
    STRAIGHT_FLUSH      // none
} poker_rank_t;

typedef enum class PokerResult
{
    BLACK_WON,
    WHITE_WON,
    TIE
} result_t;

using poker_hand_t = vector<card_t>;
poker_rank_t rankPokerHand(poker_hand_t& hand)
{
    poker_rank_t pr;

    // sort by rank
    sort(ALL(hand), [](card_t c1, card_t c2) 
        { return (umap_rank[c1.rank] < umap_rank[c2.rank]); });
    

    // 2 / 2x2 / 3 / 2-3 / 4
    
    auto sameRank = [](card_t c1, card_t c2)
                    { return c1.rank == c2.rank; };

    auto fp = adjacent_find(ALL(hand), sameRank);
    
    if (fp != hand.end())
    {
        auto fq = adjacent_find(fp + 1, hand.end(), sameRank);
        
        if (fq == hand.end()) {
            pr = PokerRank::PAIR;

            poker_hand_t pair_cards{ *fp, *(fp + 1) };
            hand.erase(fp, fp + 2);
            hand.insert(hand.begin(), ALL(pair_cards));
        }
        else if (fq == fp + 1)
        {   
            auto fr = adjacent_find(fq + 1, hand.end(), sameRank);

            if (fr == hand.end()) {
                pr = PokerRank::THREE_OF_A_KIND;

                poker_hand_t three_cards{ *fp, *(fp + 1), *(fp + 2) };
                hand.erase(fp, fp + 3);
                hand.insert(hand.begin(), ALL(three_cards));
            }
            else if (fr == fq + 1) 
            {
                pr = PokerRank::FOUR_OF_A_KIND;

                poker_hand_t four_cards{ *fp, *(fp + 1), *(fp + 2), *(fp + 2) };
                hand.erase(fp, fp + 4);
                hand.insert(hand.begin(), ALL(four_cards));
            }
            else {
                pr = PokerRank::FULL_HOUSE;
            }
        }
        else
        {
            auto fr = adjacent_find(fq + 1, hand.end(), sameRank);

            if (fr == hand.end())
            {
                pr = PokerRank::TWO_PAIRS;

                poker_hand_t pair_cards_1{ *fp, *(fp + 1) }, 
                             pair_cards_2{ *fq, *(fq + 1) };
                rank_t rank_pair_1 = fp->rank, 
                       rank_pair_2 = fq->rank;
                
                hand.erase(fq, fq + 2);
                hand.erase(fp, fp + 2);
                if (umap_rank[rank_pair_1] < umap_rank[rank_pair_2])
                {
                    hand.insert(hand.begin(), ALL(pair_cards_1));
                    hand.insert(hand.begin(), ALL(pair_cards_2));
                }
                else
                {
                    hand.insert(hand.begin(), ALL(pair_cards_2));
                    hand.insert(hand.begin(), ALL(pair_cards_1));
                }
            }
            else
            {
                pr = PokerRank::FULL_HOUSE;

                poker_hand_t three_cards{ *fq, *(fq + 1), *(fq + 2) };
                hand.erase(fq, fq + 3);
                hand.insert(hand.begin(), ALL(three_cards));
            }
        }
    }
    else
    {
        bool straight = false, flush = false;
        // straight

        string hand_ranks;
        for (card_t card: hand)
            hand_ranks.push_back(card.rank);

        auto found = ranks.find(hand_ranks);
        
        if (found != string::npos)
            straight = true;

        // flush
        for (char suit: suits)
        {
            if (count_if(ALL(hand), 
                [suit](card_t card)
                { return card.suit == suit; }) == POKER_HAND_SIZE)
            {
                flush = true;
            }
        }

        if (straight && flush)
            pr = PokerRank::STRAIGHT_FLUSH;
        else if (straight)
            pr = PokerRank::STRAIGHT;
        else if (flush)
            pr = PokerRank::FLUSH;
        else
            pr = PokerRank::HIGH_CARD;        
    }
    return pr;    
}

PokerResult comparePokerCards(card_t cb, card_t cw)
{
    if (umap_rank[cb.rank] > umap_rank[cw.rank])
        return PokerResult::BLACK_WON;
    if (umap_rank[cb.rank] < umap_rank[cw.rank])
        return PokerResult::WHITE_WON;
    return PokerResult::TIE;
}

PokerResult comparePokerHands(const poker_hand_t& phb, const poker_hand_t& phw)
{
    for (int i = phb.size() - 1; i >= 0; i--)
    {
        auto comp = comparePokerCards(phb[i], phw[i]);
        if (comp != PokerResult::TIE)
            return comp;
    }
    return PokerResult::TIE;
}

int main(int argc, char const *argv[])
{
    poker_init();

    string line;
    while (getline(cin >> ws, line))
    {
        stringstream ss{ line };
        poker_hand_t black, white;
        string card;
        for (int i = 0; i < POKER_HAND_SIZE; ++i)
        {
            ss >> card;
            black.push_back(card_t{card[0], card[1]});
        }
        for (int i = 0; i < POKER_HAND_SIZE; ++i)
        {
            ss >> card;
            white.push_back(card_t{card[0], card[1]});
        }

        poker_rank_t rblack = rankPokerHand(black);
        poker_rank_t rwhite = rankPokerHand(white);

        result_t res; 

        if (rblack > rwhite)
            res = PokerResult::BLACK_WON;
        else if (rwhite > rblack)
            res = PokerResult::WHITE_WON;
        else
        {
            switch (rblack)
            {
            case PokerRank::HIGH_CARD:
            {
                res = comparePokerHands(black, white);
                break;
            }
            case PokerRank::PAIR:
            {
                res = comparePokerCards(black[0], white[0]);
                if (res == PokerResult::TIE)
                {
                    poker_hand_t rem_black(black.begin() + 2, black.end());
                    poker_hand_t rem_white(white.begin() + 2, white.end());
                    res = comparePokerHands(rem_black, rem_white);
                }
                break;
            }
            case PokerRank::TWO_PAIRS:
            {
                res = comparePokerCards(black[0], white[0]);
                if (res == PokerResult::TIE)
                {
                    res = comparePokerCards(black[2], white[2]);
                    if (res == PokerResult::TIE)
                        res = comparePokerCards(black[4], white[4]);
                }
                break;
            }
            case PokerRank::THREE_OF_A_KIND:
            {
                res = comparePokerCards(black[0], white[0]);
                break;
            }
            case PokerRank::STRAIGHT:
            {
                res = comparePokerCards(black[4], white[4]);
                break;
            }
            case PokerRank::FLUSH:
            {
                res = comparePokerHands(black, white);
                break;
            }
            case PokerRank::FULL_HOUSE:
            {
                res = comparePokerCards(black[0], white[0]);
                break;
            }
            case PokerRank::FOUR_OF_A_KIND:
            {
                res = comparePokerCards(black[0], white[0]);
                break;
            }
            case PokerRank::STRAIGHT_FLUSH:
            {
                res = comparePokerCards(black[4], white[4]);
                break;
            }
            default:
                break;
            }   
        }

        switch (res)
        {
        case PokerResult::BLACK_WON:
            cout << "Black wins.\n";
            break;
        case PokerResult::TIE:
            cout << "Tie.\n";
            break;
        case PokerResult::WHITE_WON:
            cout << "White wins.\n";
            break;
        default:
            break;
        }
    }

    return 0;
}

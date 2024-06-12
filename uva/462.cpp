#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
using rank_t = char;
using suit_t = char;
const string ranks = "_A23456789TJQK";
const string suits = "SHDC";

class Card
{
    rank_t m_rank;
    suit_t m_suit;

public:
    Card(rank_t rank, suit_t suit):
        m_rank{ rank },
        m_suit{ suit }
    {}

    Card(const string& str):
        m_rank{ str[0] },
        m_suit{ str[1] }
    {}

    rank_t rank() const { return m_rank; }
    suit_t suit() const { return m_suit; }

    int value() const 
    {
        switch (m_rank)
        {
        case 'A':   return 4;
        case 'K':   return 3;
        case 'Q':   return 2;
        case 'J':   return 1;
        default:
            break;
        }
        return 0;
    }
};

class BridgeHand
{
public:
    struct Point
    {
        int normal;
        int notrump;
    };

private:
    vector<Card> m_cards;

public:
    BridgeHand() = default;

    void add(const Card& card)
    {
        m_cards.push_back(card);
    }

    int countRank(rank_t rank) const
    {
        return count_if(m_cards.begin(), m_cards.end(), 
                        [rank](const Card& card)
                        { 
                            return card.rank() == rank; 
                        });
    }
    int countSuit(suit_t suit) const
    {
        return count_if(m_cards.begin(), m_cards.end(),
                        [suit](const Card& card)
                        { 
                            return card.suit() == suit; 
                        });
    }
    bool hasCard(rank_t rank, suit_t suit) const
    {
        auto found = find_if(m_cards.begin(), m_cards.end(),
                             [rank, suit](const Card& card)
                             { 
                                return 
                                (
                                    card.rank() == rank && 
                                    card.suit() == suit
                                );
                             });
        if (found == m_cards.end())
            return false;
        return true;
    }

    bool suitStopped(suit_t suit) const
    {
        if (this->hasCard(ranks[1], suit))
            return true;
        if (this->hasCard(ranks[13], suit) && this->countSuit(suit) >= 2)
            return true;
        if (this->hasCard(ranks[12], suit) && this->countSuit(suit) >= 3)
            return true;

        return false;
    }

    Point evaluate() const
    {
        Point p{ 0, 0 };
        // rule 1
        for (const Card& card: m_cards)
            p.normal += card.value();
        p.notrump = p.normal;
        // rule 2,3,4
        for (auto suit: suits)
        {
            if (this->hasCard(ranks[13], suit))
            {
                if (this->countSuit(suit) == 1) 
                {
                    --p.normal;
                    --p.notrump;
                }
            }
            if (this->hasCard(ranks[12], suit))
            {
                if (this->countSuit(suit) <= 2) 
                {
                    --p.normal;
                    --p.notrump;
                }
            }
            if (this->hasCard(ranks[11], suit))
            {
                if (this->countSuit(suit) <= 3) 
                {
                    --p.normal;
                    --p.notrump;
                }
            }
            // rule 5,6,7
            switch (this->countSuit(suit))
            {
            case 2:     p.normal += 1;      break;
            case 1:     p.normal += 2;      break;
            case 0:     p.normal += 2;      break;
            default:                        break;
            }
        }
        return p;
    }

    void printResult() const
    {
        auto point = this->evaluate();
        if (point.normal < 14)
            cout << "PASS\n";
        else
        {
            bool stopped = true;
            for (suit_t suit: suits)
            {
                if (!this->suitStopped(suit))
                    stopped = false;

            }
            if (point.notrump >= 16 && stopped)
                cout << "BID NO-TRUMP\n";
            else
            {
                suit_t bid_suit;
                int bid_suit_count = -1;
                for (suit_t suit: suits)
                {
                    int suit_count = this->countSuit(suit);
                    if (suit_count > bid_suit_count) {
                        bid_suit = suit;
                        bid_suit_count = suit_count;
                    }
                }

                cout << "BID " << bid_suit << "\n";
            }
        }
    }

};

int main(int argc, char const *argv[])
{
    string line;
    while (getline(cin >> ws, line))
    {
        BridgeHand hand;
        stringstream ss{ line };
        string card;
        for (int i = 0; i < 13; ++i)
        {
            ss >> card;
            hand.add(Card{ card });
        }
        hand.printResult();
    }

    return 0;
}

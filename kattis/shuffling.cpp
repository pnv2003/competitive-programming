#include <iostream>
#include <deque>
#include <cmath>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;
    int n;
    string shuf;
    cin >> n >> shuf;

    deque<int> initDeck{};
    for (int i = 0; i < n; ++i) {
        initDeck.push_back(i);
    }

    deque<int> deck = initDeck;
    
    int count = 0;
    for(;;) {
        count++;

        int split;
        int turn;

        if (shuf == "out") {
            turn = 0;
            split = static_cast<int>(ceil(n*1.0 / 2));
        } else {
            turn = 1;
            split = static_cast<int>(floor(n*1.0 / 2));
        }
        
        deque<int> fst(deck.begin(), deck.begin() + split);
        deque<int> snd(deck.begin() + split, deck.end());
        deck.clear();

        while (!fst.empty() || !snd.empty())
        {   
            if (turn == 0) {
                if (fst.empty()) throw logic_error("1");
                deck.push_back(fst.front());
                fst.pop_front();
            } else {
                if (snd.empty()) throw logic_error("2");
                deck.push_back(snd.front());
                snd.pop_front();
            }
            turn = 1 - turn;
        }
        
        if (deck == initDeck) {
            break;
        }
    }
    cout << count;
    
    return 0;
}

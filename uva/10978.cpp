#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void advance_counter(int& counter, int step, const vector<bool>& check)
{
    while (step--)
    {
        counter = (counter + 1) % check.size();
        while (check[counter]) 
            counter = (counter + 1) % check.size();
    }
}

int main(int argc, char const *argv[])
{
    FASTIO;
    int ncard;
    while (cin >> ncard)
    {
        if (ncard == 0) break;

        vector<string> cards, cards_arranged(ncard);
        vector<bool> cards_removed(ncard, false);
        vector<int> steps;
        for (int i = 0; i < ncard; ++i)
        {   
            string s;
            cin >> s;
            cards.push_back(s);
            cin >> s;
            steps.push_back(s.size() - 1);
        }

        int counter = 0;
        for (int i = 0; i < ncard; ++i)
        {
            advance_counter(counter, steps[i], cards_removed);
            cards_arranged[counter] = cards[i]; 
            cards_removed[counter] = true;
            if (i == ncard - 1)
                break;
            advance_counter(counter, 1, cards_removed);
        }
        
        for (auto it = cards_arranged.begin(); it != cards_arranged.end(); ++it)
        {
            if (it > cards_arranged.begin())
                cout << " ";
            cout << *it;
        }
        cout << "\n";
    }
    
    return 0;
}

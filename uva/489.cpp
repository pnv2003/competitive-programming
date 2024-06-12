#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int round, id = 1;
    while (cin >> round)
    {
        if (round == -1) break;

        string word, guess;
        cin >> word >> guess;
        
        int nstroke = 0;
        for (char c: guess)
        {
            if (nstroke == 7)
                break;
            bool hit = false;
            auto it = word.begin();
            while (it != word.end())
            {
                if (*it == c)
                {
                    hit = true;
                    it = word.erase(it);
                }
                else 
                    ++it;
            }
            if (!hit) ++nstroke;
        }

        cout << "Round " << round << "\n";
        if (word.empty())
            cout << "You win.\n";
        else
        {
            if (nstroke == 7)
                cout << "You lose.\n";
            else
                cout << "You chickened out.\n";
        }
    }
    
    return 0;
}

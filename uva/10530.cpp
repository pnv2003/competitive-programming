#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    for (;;)
    {
        int guess, lo = 0, hi = 11;
        string feedback;

        while (cin >> guess)
        {
            if (guess == 0) return 0;
            getline(cin >> ws, feedback);

            if (feedback[0] == 'r')
            {
                if (guess > lo && guess < hi)
                    cout << "Stan may be honest\n";
                else 
                    cout << "Stan is dishonest\n";
                break;
            }
            else if (feedback[4] == 'h')
            {
                if (guess < hi)
                    hi = guess;
            }
            else if (feedback[4] == 'l')
            {
                if (guess > lo)
                    lo = guess;
            }
        }
        
    }
    return 0;
}

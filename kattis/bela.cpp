#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    char b;
    cin >> n >> b;

    int pts = 0;
    for (int i = 0; i < 4*n; ++i) {
        char num, suit;
        cin >> num >> suit;   

        switch (num)
        {
        case 'A':   pts += 11;  break;
        case 'K':   pts += 4;   break;
        case 'Q':   pts += 3;   break;
        case 'J':   pts += (suit == b) ? 20 : 2; break;
        case 'T':   pts += 10;  break;
        case '9':   pts += (suit == b) ? 14 : 0; break;
        default:
            break;
        }
    }
    cout << pts << "\n";

    return 0;
}

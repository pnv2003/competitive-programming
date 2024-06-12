#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    using vs = vector<string>;
    int n;
    vs v;
    string name;
    cin >> n;

    while (n--)
    {
        cin >> name;
        v.push_back(name);
    }

    bool allsung = false;
    int iword = 0;
    int turn = 0;
    for (;;)
    {
        if (allsung && iword % 16 == 0) {
            break;
            cout << "I quit\n";
        }
        
        cout << v[turn] << ": ";
        switch (iword)
        {
        case 0:
        case 4:
        case 8:
        case 12:
            cout << "Happy\n";
            break;
        case 1:
        case 5:
        case 9:
        case 13:
            cout << "birthday\n";
            break;
        case 2:
        case 6:
        case 10:
        case 14:
            cout << "to\n";
            break;
        case 3:
        case 7:
        case 15:
            cout << "you\n";
            break;
        case 11:
            cout << "Rujia\n";
            break;
        default:
            break;
        }

        ++iword;
        ++turn;
        if (turn == v.size()) 
        {
            turn = 0;
            allsung = true;
        }
        if (iword == 16)
            iword = 0;
    }

    return 0;
}

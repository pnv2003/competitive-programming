#include <iostream>
#include <string>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(int argc, char const *argv[])
{
    FASTIO;
    char map_soundex['Z' + 1];
    for (char c = 'A'; c <= 'Z'; ++c)
    {
        switch (c)
        {
        case 'B':
        case 'F':
        case 'P':
        case 'V':   map_soundex[c] = '1';   break;
        case 'C':
        case 'G':
        case 'J':
        case 'K':
        case 'Q':
        case 'S':
        case 'X':
        case 'Z':   map_soundex[c] = '2';   break;
        case 'D':
        case 'T':   map_soundex[c] = '3';   break;
        case 'L':   map_soundex[c] = '4';   break;
        case 'M':
        case 'N':   map_soundex[c] = '5';   break;
        case 'R':   map_soundex[c] = '6';   break;
        default:    map_soundex[c] = ' ';    break;
        }
    }
    
    string word;
    while (cin >> word)
    {
        string sdx;
        char cprev;
        for (char c: word)
        {
            if (map_soundex[c] != ' ')
            {
                if (sdx.empty())
                {
                    sdx.push_back(map_soundex[c]);
                    cprev = map_soundex[c];
                }
                else
                {
                    if (map_soundex[c] != cprev)
                    {
                        sdx.push_back(map_soundex[c]);
                        cprev = map_soundex[c];
                    }
                }
            }
            else
                cprev = ' ';
        }
        cout << sdx << "\n";
    }
    
    return 0;
}

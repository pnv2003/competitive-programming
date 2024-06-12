#include <iostream>
#include <string>
using namespace std;

typedef struct
{
    int top;
    int bottom;
    int north;
    int south;
    int west;
    int east;
} dice_t;

int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n)
    {
        if (n == 0) break;

        dice_t dice{ 1, 6, 2, 5, 3, 4 };
        string cmd;
        while (n--)
        {
            int current_top = dice.top;
            cin >> cmd;
            switch (cmd[0])
            {
            case 'n':
            {
                dice.top = dice.south;
                dice.south = dice.bottom;
                dice.bottom = dice.north;
                dice.north = current_top;
                break;
            }    
            case 's':
            {
                dice.top = dice.north;
                dice.north = dice.bottom;
                dice.bottom = dice.south;
                dice.south = current_top;
                break;
            }
            case 'w':
            {
                dice.top = dice.east;
                dice.east = dice.bottom;
                dice.bottom = dice.west;
                dice.west = current_top;
                break;
            }
            case 'e':
            {
                dice.top = dice.west;
                dice.west = dice.bottom;
                dice.bottom = dice.east;
                dice.east = current_top;
                break;
            }
            default:
                break;
            }
        }
        cout << dice.top << "\n";
    }
    
    return 0;
}

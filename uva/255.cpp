#include <iostream>
#include <algorithm>
using namespace std;
#define CHESS_SIZE 8

bool outOfBoard(int pos)
{
    return (pos < 0 || pos > CHESS_SIZE*CHESS_SIZE - 1);
}

int main(int argc, char const *argv[])
{
    int kpos, qpos, qnewpos;
    while (cin >> kpos >> qpos >> qnewpos)
    {
        if (outOfBoard(kpos) || outOfBoard(qpos) || kpos == qpos)
        {
            cout << "Illegal state\n";
            continue;
        }

        if (outOfBoard(qnewpos) || kpos == qnewpos || qpos == qnewpos)
        {
            cout << "Illegal move\n";
            continue;
        }

        bool legal_move = true;
        if ((qnewpos - qpos) % CHESS_SIZE == 0) // vertical
        {
            if ((kpos - qpos) % CHESS_SIZE == 0)
            {
                if (min(qpos, qnewpos) <= kpos &&
                    max(qpos, qnewpos) >= kpos) 
                    legal_move = false;
            }
        }
        else if ((qpos - qpos % CHESS_SIZE) == (qnewpos - qnewpos % CHESS_SIZE))
        {
            if ((qpos - qpos % CHESS_SIZE) == (kpos - kpos % CHESS_SIZE))
            {
                if (min(qpos, qnewpos) <= kpos &&
                    max(qpos, qnewpos) >= kpos) 
                    legal_move = false;
            }
        }
        else
            legal_move = false;

        if (!legal_move)
        {
            cout << "Illegal move\n";
            continue;
        }

        if ((qnewpos == kpos - 1 && kpos % 8 != 0) ||
            (qnewpos == kpos + 1 && (kpos + 1) % 8 != 0) ||
            qnewpos == kpos - 8 ||
            qnewpos == kpos + 8)
        {
            cout << "Move not allowed\n";
            continue;
        }

        if ((kpos == 0 && qnewpos == 9) ||
            (kpos == 7 && qnewpos == 14) ||
            (kpos == 56 && qnewpos == 49) ||
            (kpos == 63 && qnewpos == 54))
            cout << "Stop\n";
        else 
            cout << "Continue\n";
    }


    return 0;
}

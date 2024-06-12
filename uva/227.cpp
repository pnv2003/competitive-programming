#include <iostream>
#include <string>
#include <vector>
using namespace std;
using frame_t = vector<string>;
#define FRAME_SIZE 5

typedef struct Position
{
    int row;
    int col;
} pos_t;

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int id = 1;
    while (true)
    {
        frame_t frame(FRAME_SIZE);
        pos_t blank;
        for (int i = 0; i < FRAME_SIZE; ++i)
        {
            getline(cin, frame[i]);
            if (frame[i] == "Z")
                return 0;

            if (frame[i].size() < FRAME_SIZE) 
            {
                frame[i].push_back(' ');
                blank = {i, FRAME_SIZE - 1};
            }
            else 
            {
                int space = frame[i].substr(0, FRAME_SIZE).find(' ');
                if (space != string::npos)
                    blank = {i, space};
            }
        }

        string moves, line;
        while (true)
        {
            getline(cin >> ws, line);
            moves.append(line);
            if (line[line.size() - 1] == '0')
                break;
        }

        pos_t sq;
        bool legal = true;
        for (char cmd: moves)
        {
            if (cmd == '0')
                break;
            switch (cmd)
            {
            case 'A':   sq = {blank.row - 1, blank.col};   break;
            case 'B':   sq = {blank.row + 1, blank.col};   break;
            case 'L':   sq = {blank.row, blank.col - 1};   break;
            case 'R':   sq = {blank.row, blank.col + 1};   break;
            default:    legal = false;                     break;
            }   

            if (sq.row < 0 || sq.row >= FRAME_SIZE || 
                sq.col < 0 || sq.col >= FRAME_SIZE) 
                legal = false;

            if (!legal)
                break;

            frame[blank.row][blank.col] = frame[sq.row][sq.col];
            frame[sq.row][sq.col] = ' ';
            blank = {sq.row, sq.col};
        }

        if (id > 1)
            cout << "\n";
        cout << "Puzzle #" << id++ << ":\n";
        if (legal)
        {
            for (const string& frow: frame)
            {
                for (auto it = frow.begin(); it != frow.end(); ++it)
                {
                    cout << *it;
                    if (next(it) == frow.end())
                        cout << "\n";
                    else 
                        cout << " ";
                }
            }
        }
        else 
            cout << "This puzzle has no final configuration.\n";
    }
    
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
    vector<vector<bool>> grid;
    int size;
    int nspot;
} board_t;

void init_board(board_t& b, int bsize)
{
    b = { vector<vector<bool>>(bsize, vector<bool>(bsize, false)), bsize, 0 };
}

bool identical_pattern(const board_t& b1, const board_t& b2)
{
    return equal(b1.grid.begin(), b1.grid.end(), b2.grid.begin(), 
                 [](const vector<bool>& row1, const vector<bool>& row2)
                 { return equal(row1.begin(), row1.end(), row2.begin()); });
}

bool repeated_pattern(const board_t& b1, const board_t& b2)
{   
    if (b1.nspot != b2.nspot)
        return false;

    // 0 deg
    if (identical_pattern(b1, b2))
        return true;

    // 90, 180, 270 deg clkw
    board_t b3, b4, b5;
    init_board(b3, b2.size);
    init_board(b4, b2.size);
    init_board(b5, b2.size);
    for (int i = 0; i < b2.size; ++i)
    {
        for (int j = 0; j < b2.size; ++j)
        {
            b3.grid[j][b2.size - 1 - i] = b2.grid[i][j];
            b4.grid[b2.size - 1 - i][b2.size - 1 - j] = b2.grid[i][j];
            b5.grid[b2.size - 1 - j][i] = b2.grid[i][j];
        }
    }
    
    if (identical_pattern(b1, b3))
        return true;
    if (identical_pattern(b1, b4))
        return true;
    if (identical_pattern(b1, b5))
        return true;

    return false;
}

int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n)
    {
        if (n == 0) break;

        int sqx, sqy;
        char c;
        board_t board;
        init_board(board, n);
        vector<board_t> gamelog;

        int turn = 1, imove = 1;
        bool draw = true;
        for (int i = 0; i < 2*n; ++i)
        {
            cin >> sqx >> sqy >> c; 
            sqx--; sqy--;

            if (!draw)
                continue;
            if (c == '+')
            {
                board.nspot++;
                board.grid[sqy][sqx] = true;
            }
            else 
            {
                board.nspot--;
                board.grid[sqy][sqx] = false;
            }

            auto repeat_found = find_if(gamelog.begin(), gamelog.end(),
                                        [&board](const board_t& b)
                                        { return repeated_pattern(board, b); });

            if (repeat_found != gamelog.end())
            {
                draw = false;
                cout << "Player " << 3 - turn 
                     << " wins on move " << imove << "\n";
            }

            gamelog.push_back(board);
            turn = 3 - turn;
            imove++;
        }

        if (draw)
            cout << "Draw\n";
    }
    
    return 0;
}

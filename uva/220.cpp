#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using board_t = vector<string>;
#define BOARD_SIZE 8
#define EMPTY_DISK '-'
#define BLACK_DISK 'B'
#define WHITE_DISK 'W'

char opponent(char disk)
{
    return BLACK_DISK + WHITE_DISK - disk;
}

bool out_of_board(const board_t& b, int row, int col)
{
    if (row < 0 || row >= b.size())
        return true;
    if (col < 0 || col >= b[0].size())
        return true;
    return false;
}

bool othello_bracketable(const board_t& b, 
                         int srcrow, 
                         int srccol, 
                         int dstrow, 
                         int dstcol)
{
    if (out_of_board(b, srcrow, srccol) ||
        out_of_board(b, dstrow, dstcol))
        return false;

    char src = b[srcrow][srccol];
    char dst = b[dstrow][dstcol];

    if (src == EMPTY_DISK)
        return false;

    pair<int, int> step;
    bool line = true;
    if (srcrow == dstrow)
    {
        if (abs(srccol - dstcol) < 2)   
            return false;

        if (dstcol < srccol)
            step = {0, -1};
        else 
            step = {0, 1};
    }
    // vertical line
    else if (srccol == dstcol)
    {
        if (abs(srcrow - dstrow) < 2)
            return false;

        if (dstrow < srcrow)
            step = {-1, 0};
        else 
            step = {1, 0};
    }
    // diagonal line
    else if (abs(srcrow - dstrow) == abs(srccol - dstcol))
    {
        if (abs(srcrow - dstrow) < 2)
            return false;

        if (srcrow < dstrow && srccol < dstcol)
            step = {1, 1};
        else if (srcrow < dstrow && srccol > dstcol)
            step = {1, -1};
        else if (srcrow > dstrow && srccol > dstcol)
            step = {-1, -1};
        else
            step = {-1, 1};
    }
    else 
        line = false;

    if (line)
    {
        for (int row = srcrow + step.first, col = srccol + step.second; 
             !(row == dstrow && col == dstcol); 
             row += step.first, col += step.second)
        {
            if (b[row][col] != opponent(src))
                return false;
        }
        return true;
    }

    return false;
}

void othello_bracket(board_t& b, 
                  int srcrow, 
                  int srccol, 
                  int dstrow, 
                  int dstcol,
                  int& bcount,
                  int& wcount)
{
    char src = b[srcrow][srccol];
    int count = 0;

    pair<int, int> step;
    if (srcrow == dstrow)
    {
        if (dstcol < srccol)
            step = {0, -1};
        else 
            step = {0, 1};
    }
    // vertical line
    else if (srccol == dstcol)
    {
        if (dstrow < srcrow)
            step = {-1, 0};
        else 
            step = {1, 0};
    }
    // diagonal line
    else if (abs(srcrow - dstrow) == abs(srccol - dstcol))
    {
        if (srcrow < dstrow && srccol < dstcol)
            step = {1, 1};
        else if (srcrow < dstrow && srccol > dstcol)
            step = {1, -1};
        else if (srcrow > dstrow && srccol > dstcol)
            step = {-1, -1};
        else
            step = {-1, 1};
    }

    for (int r = srcrow + step.first, c = srccol + step.second;
         !(r == dstrow && c == dstcol); 
         r += step.first, c += step.second)
    {
        b[r][c] = src;
        ++count;
    }

    if (src == BLACK_DISK) 
    {
        bcount += count;
        wcount -= count;
    }
    else 
    {
        wcount += count;
        bcount -= count;
    }
}

int main(int argc, char const *argv[])
{
    int ngames, id = 1;
    cin >> ngames;
    while (ngames--)
    {
        if (id > 1)
            cout << "\n";
        ++id;

        board_t board(BOARD_SIZE);
        int bcount = 0, wcount = 0;
        for (int i = 0; i < BOARD_SIZE; ++i) 
        {
            cin >> board[i];
            bcount += count(board[i].begin(), board[i].end(), BLACK_DISK);
            wcount += count(board[i].begin(), board[i].end(), WHITE_DISK);
        }

        char turn;
        cin >> turn;

        string cmd;
        while (true)
        {   
            cin >> cmd;
            if (cmd == "Q") break;

            if (cmd == "L")
            {
                vector<pair<int, int>> legalmoves;
                for (int i = 0; i < BOARD_SIZE; ++i)
                {
                    for (int j = 0; j < BOARD_SIZE; ++j)
                    {
                        if (board[i][j] == turn)
                        {
                            vector<pair<int, int>> step_directions = {{1,0}, {0,1}, {-1,0}, {0,-1}, {-1,-1}, {-1,1}, {1,-1}, {1,1}};
                            int r, c;
                            for (const auto& step: step_directions)
                            {
                                for (r = i, c = j; !out_of_board(board, r, c); r += step.first, c += step.second)
                                {
                                    if (board[r][c] != EMPTY_DISK)
                                        continue;
                                    if (othello_bracketable(board, i, j, r, c))
                                    {
                                        legalmoves.push_back({r + 1, c + 1});
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }

                sort(legalmoves.begin(), legalmoves.end(),
                     [](const pair<int, int>& p1, const pair<int, int>& p2)
                     {
                        if (p1.first < p2.first)
                            return true;
                        if (p1.first > p2.first)
                            return false;
                        return (p1.second < p2.second);
                     });
                auto lmlast = unique(legalmoves.begin(), legalmoves.end());
                legalmoves.erase(lmlast, legalmoves.end());

                if (legalmoves.empty()) 
                {
                    cout << "No legal move.\n";
                    turn = opponent(turn);
                }
                else
                {
                    for (auto it = legalmoves.begin(); it != legalmoves.end(); ++it)
                    {
                        cout << "(" << it->first << "," << it->second << ")";
                        if (next(it) != legalmoves.end())
                            cout << " ";
                    }
                    cout << "\n";
                }
            }
            else 
            {
                int mrow = (cmd[1] - '0') - 1;
                int mcol = (cmd[2] - '0') - 1;
                board[mrow][mcol] = turn;
                if (turn == BLACK_DISK) 
                    bcount++;
                else 
                    wcount++;
                for (int i = 0; i < BOARD_SIZE; ++i)
                {
                    for (int j = 0; j < BOARD_SIZE; ++j)
                    {
                        if (board[i][j] == turn && 
                            othello_bracketable(board, mrow, mcol, i, j))
                            othello_bracket(board, mrow, mcol, i, j, bcount, wcount);
                    }
                }

                printf("Black -%3d White -%3d\n", bcount, wcount);
                turn = opponent(turn);
            }
        }

        for (const string& row: board)
            cout << row << "\n";
    }
    
    return 0;
}

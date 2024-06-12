#include <iostream>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#define CHESSBOARD_SIZE 8
using namespace std;

class Position 
{
    int m_row{ 0 };
    int m_col{ 0 };

public:
    Position() = default;
    Position(int row, int col): m_row{ row }, m_col{ col } {}

    int row() const { return m_row; }
    int col() const { return m_col; }

    Position toNorth() const   { return Position{ m_row - 1, m_col}; }
    Position toEast() const    { return Position{ m_row, m_col + 1 }; }
    Position toWest() const    { return Position{ m_row, m_col - 1}; }
    Position toSouth() const   { return Position{ m_row + 1, m_col}; }

    int rowDistTo(const Position& pos) const { return abs(m_row - pos.row()); }
    int colDistTo(const Position& pos) const { return abs(m_col - pos.col()); }
};

bool operator== (const Position& p1, const Position& p2)
{
    return 
    (
        p1.row() == p2.row() &&
        p1.col() == p2.col()
    );
}
bool operator!= (const Position& p1, const Position& p2)
{
    return !(p1 == p2);
}

class Piece
{
public:
    typedef enum Type
    {
        EMPTY,
        PAWN,
        BISHOP,
        KNIGHT,
        ROOK,
        QUEEN,
        KING,
        OUT_OF_BOARD
    } piece_type_t;
    typedef enum Side
    {
        NONE,
        BLACK,
        WHITE
    } piece_side_t;

private:
    piece_type_t m_type{};
    piece_side_t m_side{};

public:
    Piece() = default;
    Piece(char c)
    {
        if (c == '.')
            m_side = NONE;
        else if (islower(c))
            m_side = BLACK;
        else
            m_side = WHITE;

        switch (c)
        {
        case 'p':
        case 'P':   m_type = PAWN;      break;
        case 'n':
        case 'N':   m_type = KNIGHT;    break;
        case 'b':
        case 'B':   m_type = BISHOP;    break;
        case 'r':
        case 'R':   m_type = ROOK;      break;
        case 'q':
        case 'Q':   m_type = QUEEN;     break;
        case 'k':
        case 'K':   m_type = KING;      break;
        default:
            break;
        }  
    }
    
    piece_side_t side() const { return m_side; }
    piece_type_t type() const { return m_type; }

    bool empty() const { return m_type == EMPTY; }
    bool isBlack() const { return m_side == BLACK; }
    bool isWhite() const { return m_side == WHITE; }
    bool isKing() const { return m_type == KING; }
};

class Chessboard 
{
    vector<vector<Piece>> m_board{};
    int m_nrow{ CHESSBOARD_SIZE };
    int m_ncol{ CHESSBOARD_SIZE };
    Position m_black_king_pos{};
    Position m_white_king_pos{};

public:
    Chessboard() = default;
    Chessboard(const string& str)
    {
        auto it = str.begin();
        for (int i = 0; i < m_nrow; ++i)
        {
            vector<Piece> row;
            for (int j = 0; j < m_ncol; ++j)
            {
                Piece piece{ *it };
                if (piece.isKing())
                {
                    if (piece.isBlack())
                        m_black_king_pos = Position(i, j);
                    else if (piece.isWhite())
                        m_white_king_pos = Position(i, j);
                }
                row.push_back(piece);
                ++it;
            }
            m_board.push_back(row);
        }
    }

    Position black_king_position() const { return m_black_king_pos; }
    Position white_king_position() const { return m_white_king_pos; }

    bool out_of_range(const Position& pos) const
    {
        if (pos.row() < 0 || pos.row() >= m_nrow)
            return true;
        if (pos.col() < 0 || pos.col() >= m_ncol)
            return true;
        return false;
    }

    Piece piece_at(const Position& pos) const
    {
        if (out_of_range(pos))
            return ' ';
        return m_board[pos.row()][pos.col()];
    }

    bool movable(const Position& src, const Position& dst) const
    {
        auto srcpiece = piece_at(src);
        Position trace;
        bool path_open = false;
        switch (srcpiece.type())
        {
        case Piece::Type::PAWN:
        {
            if (srcpiece.isBlack())
            {
                trace = src.toSouth().toWest();
                if (dst == trace) 
                    path_open = true;
                trace = src.toSouth().toEast();
                if (dst == trace) 
                    path_open = true;
            }
            else if (srcpiece.isWhite())
            {
                trace = src.toNorth().toWest();
                if (dst == trace) 
                    path_open = true;
                trace = src.toNorth().toEast();
                if (dst == trace) 
                    path_open = true;
            }
            break;
        }
        case Piece::Type::BISHOP:
        {
            if (src.rowDistTo(dst) == src.colDistTo(dst))
            {
                // to northwest
                if (dst.row() < src.row() && dst.col() < src.col())
                {
                    for (trace = src; trace != dst; trace = trace.toNorth().toWest())
                    {
                        if (trace != src && !piece_at(trace).empty())
                            return false;
                    }
                }
                // to northeast
                else if (dst.row() < src.row() && dst.col() > src.col())
                {
                   for (trace = src; trace != dst; trace = trace.toNorth().toEast())
                    {
                        if (trace != src && !piece_at(trace).empty())
                            return false;
                    }
                }
                // to southeast
                else if (dst.row() > src.row() && dst.col() > src.col())
                {
                   for (trace = src; trace != dst; trace = trace.toSouth().toEast())
                    {
                        if (trace != src && !piece_at(trace).empty())
                            return false;
                    }
                }
                // to southwest
                else
                {
                   for (trace = src; trace != dst; trace = trace.toSouth().toWest())
                    {
                        if (trace != src && !piece_at(trace).empty())
                            return false;
                    }
                }
                path_open = true;
            }
            break;
        }
        case Piece::Type::KNIGHT:
        {
            if (src.rowDistTo(dst) == 1 && src.colDistTo(dst) == 2) 
                path_open = true;
            if (src.rowDistTo(dst) == 2 && src.colDistTo(dst) == 1)
                path_open = true;
            break;
        }
        case Piece::Type::ROOK:
        {
            if (src.rowDistTo(dst) == 0)
            {
                if (dst.col() < src.col()) // to west
                {
                    for (trace = src; trace != dst; trace = trace.toWest())
                    {
                        if (trace != src && !piece_at(trace).empty())
                            return false;
                    }
                }
                else // to east
                {
                    for (trace = src; trace != dst; trace = trace.toEast())
                    {
                        if (trace != src && !piece_at(trace).empty())
                            return false;
                    }
                }
                path_open = true;
            }
            else if (src.colDistTo(dst) == 0)
            {
                if (dst.row() < src.row()) // to north
                {
                    for (trace = src; trace != dst; trace = trace.toNorth())
                    {
                        if (trace != src && !piece_at(trace).empty())
                            return false;
                    }
                }
                else // to south
                {
                    for (trace = src; trace != dst; trace = trace.toSouth())
                    {
                        if (trace != src && !piece_at(trace).empty())
                            return false;
                    }
                }
                path_open = true;
            }
            break;
        }
        case Piece::Type::QUEEN:
        { 
            // BISHOP
            if (src.rowDistTo(dst) == src.colDistTo(dst))
            {
                // to northwest
                if (dst.row() < src.row() && dst.col() < src.col())
                {
                    for (trace = src; trace != dst; trace = trace.toNorth().toWest())
                    {
                        if (trace != src && !piece_at(trace).empty())
                            return false;
                    }
                }
                // to northeast
                else if (dst.row() < src.row() && dst.col() > src.col())
                {
                   for (trace = src; trace != dst; trace = trace.toNorth().toEast())
                    {
                        if (trace != src && !piece_at(trace).empty())
                            return false;
                    }
                }
                // to southeast
                else if (dst.row() > src.row() && dst.col() > src.col())
                {
                   for (trace = src; trace != dst; trace = trace.toSouth().toEast())
                    {
                        if (trace != src && !piece_at(trace).empty())
                            return false;
                    }
                }
                // to southwest
                else
                {
                   for (trace = src; trace != dst; trace = trace.toSouth().toWest())
                    {
                        if (trace != src && !piece_at(trace).empty())
                            return false;
                    }
                }
                path_open = true;
            }
            // ROOK
            if (src.rowDistTo(dst) == 0)
            {
                if (dst.col() < src.col()) // to west
                {
                    for (trace = src; trace != dst; trace = trace.toWest())
                    {
                        if (trace != src && !piece_at(trace).empty())
                            return false;
                    }
                }
                else // to east
                {
                    for (trace = src; trace != dst; trace = trace.toEast())
                    {
                        if (trace != src && !piece_at(trace).empty())
                            return false;
                    }
                }
                path_open = true;
            }
            else if (src.colDistTo(dst) == 0)
            {
                if (dst.row() < src.row()) // to north
                {
                    for (trace = src; trace != dst; trace = trace.toNorth())
                    {
                        if (trace != src && !piece_at(trace).empty())
                            return false;
                    }
                }
                else // to south
                {
                    for (trace = src; trace != dst; trace = trace.toSouth())
                    {
                        if (trace != src && !piece_at(trace).empty())
                            return false;
                    }
                }
                path_open = true;
            }
            break;
        }
        case Piece::Type::KING:
        {
            if (src.rowDistTo(dst) <= 1 && src.colDistTo(dst) <= 1)
                path_open = true;
            break;
        }
        
        default:
            break;
        }

        if (path_open) // cannot take the piece with the same color
        {
            if (srcpiece.isBlack() && !piece_at(dst).isBlack())
                return true;
            if (srcpiece.isWhite() && !piece_at(dst).isWhite())
                return true;
        }

        return false;
    }
};

int main()
{
    int id = 1;
    for (;;)
    {
        string boardstr, line;
        int dotted_line_count = 0;
        for (int i = 0; i < CHESSBOARD_SIZE; ++i)
        {
            getline(cin >> ws, line);
            boardstr.append(line);
            if (line == "........")
                dotted_line_count++;
        }
        if (dotted_line_count == 8) break;

        Chessboard board{ boardstr };

        bool black_checked = false, 
             white_checked = false;
        for (int row = 0; row < CHESSBOARD_SIZE; ++row)
        {
            bool stop = false;
            for (int col = 0; col < CHESSBOARD_SIZE; ++col)
            {
                Position pos{ row, col };
                Piece piece = board.piece_at(pos);
                if (piece.isBlack())
                {
                    if (board.movable(pos, board.white_king_position())) {
                        white_checked = true;
                        stop = true;
                        break;
                    }
                }
                else
                {
                    if (board.movable(pos, board.black_king_position())) {
                        black_checked = true;
                        stop = true;
                        break;
                    }
                }
            }
            if (stop)
                break;
        }

        cout << "Game #" << id++ << ": ";
        if (black_checked)
            cout << "black";
        else if (white_checked)
            cout << "white";
        else 
            cout << "no";
        cout <<  " king is in check.\n";
    }
    return 0;
}

#include <iostream>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#define CHESSBOARD_SIZE 8

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
    bool m_marked{ false };

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
    bool marked() const { return m_marked; }

    void mark() { m_marked = true; }
    void unmark() { m_marked = false; }
    
    bool empty() const { return m_type == EMPTY; }
    bool isBlack() const { return m_side == BLACK; }
    bool isWhite() const { return m_side == WHITE; }
    bool isKing() const { return m_type == KING; }
};

class Chessboard 
{
    std::vector<std::vector<Piece>> m_board{};
    int m_nrow{ CHESSBOARD_SIZE };
    int m_ncol{ CHESSBOARD_SIZE };

public:
    Chessboard() = default;
    Chessboard(const std::string& str)
    {
        // FEN
        std::stringstream ss{ str };
        std::string row;
        for (int i = 0; i < m_nrow; ++i)
        {
            std::vector<Piece> vp;
            std::getline(ss, row, '/');

            for (char p: row)
            {
                if (std::isdigit(p))
                {
                    for (int j = 0; j < (p - '0'); ++j)
                        vp.push_back(Piece{ '.' });
                }
                else
                    vp.push_back(Piece{ p });
            }
            m_board.push_back(vp);
        }
    }

    int numrows() const { return m_nrow; }
    int numcols() const { return m_ncol; }

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

    void mark_piece_at(const Position& pos) { m_board[pos.row()][pos.col()].mark(); }
    void unmark_piece_at(const Position& pos) { m_board[pos.row()][pos.col()].unmark(); }
    void mark_piece_movable(const Position& src, const Position& dst)
    {
        if (!out_of_range(dst))
        {
            auto srcpiece = piece_at(src);
            auto dstpiece = piece_at(dst);

            if (srcpiece.isBlack())
            {
                if (!dstpiece.isBlack())
                    mark_piece_at(dst);
            }
            else if (srcpiece.isWhite())
            {
                if (!dstpiece.isWhite())
                    mark_piece_at(dst);
            }
        }
    }

    void trace_piece_at(const Position& pos)
    {
        auto piece = piece_at(pos);
        Position trace;

        switch (piece.type()) 
        {
        case Piece::Type::PAWN:
        {
            if (piece.isBlack())
            {
                trace = pos.toSouth().toWest();
                mark_piece_movable(pos, trace);
                trace = pos.toSouth().toEast();
                mark_piece_movable(pos, trace);
            }
            else if (piece.isWhite())
            {
                trace = pos.toNorth().toWest();
                mark_piece_movable(pos, trace);
                trace = pos.toNorth().toEast();
                mark_piece_movable(pos, trace);
            }
            break;
        }
        case Piece::Type::BISHOP:
        {
            // to northwest
            for (trace = pos; !out_of_range(trace); trace = trace.toNorth().toWest())
            {
                mark_piece_movable(pos, trace);
                if (trace != pos && !piece_at(trace).empty())
                    break;
            }
            // to northeast
            for (trace = pos; !out_of_range(trace); trace = trace.toNorth().toEast())
            {
                mark_piece_movable(pos, trace);
                if (trace != pos && !piece_at(trace).empty())
                    break;
            }
            // to southeast
            for (trace = pos; !out_of_range(trace); trace = trace.toSouth().toEast())
            {
                mark_piece_movable(pos, trace);
                if (trace != pos && !piece_at(trace).empty())
                    break;
            }
            // to southwest
            for (trace = pos; !out_of_range(trace); trace = trace.toSouth().toWest())
            {
                mark_piece_movable(pos, trace);
                if (trace != pos && !piece_at(trace).empty())
                    break;
            }
            break;
        }
        case Piece::Type::KNIGHT:
        {
            trace = pos.toNorth().toNorth().toWest();
            mark_piece_movable(pos, trace);
            trace = pos.toNorth().toNorth().toEast();
            mark_piece_movable(pos, trace);
            trace = pos.toEast().toEast().toNorth();
            mark_piece_movable(pos, trace);
            trace = pos.toEast().toEast().toSouth();
            mark_piece_movable(pos, trace);
            trace = pos.toSouth().toSouth().toEast();
            mark_piece_movable(pos, trace);
            trace = pos.toSouth().toSouth().toWest();
            mark_piece_movable(pos, trace);
            trace = pos.toWest().toWest().toSouth();
            mark_piece_movable(pos, trace);
            trace = pos.toWest().toWest().toNorth();
            mark_piece_movable(pos, trace);
            break;
        }
        case Piece::Type::ROOK:
        {
            // to west
            for (trace = pos; !out_of_range(trace); trace = trace.toWest())
            {
                mark_piece_movable(pos, trace);
                if (trace != pos && !piece_at(trace).empty())
                    break;
            }
            // to east
            for (trace = pos; !out_of_range(trace); trace = trace.toEast())
            {
                mark_piece_movable(pos, trace);
                if (trace != pos && !piece_at(trace).empty())
                    break;
            }
            // to north
            for (trace = pos; !out_of_range(trace); trace = trace.toNorth())
            {
                mark_piece_movable(pos, trace);
                if (trace != pos && !piece_at(trace).empty())
                    break;
            }
            // to south
            for (trace = pos; !out_of_range(trace); trace = trace.toSouth())
            {
                mark_piece_movable(pos, trace);
                if (trace != pos && !piece_at(trace).empty())
                    break;
            }
            break;
        }
        case Piece::Type::QUEEN:
        { 
            // mark like bishop and rook
            m_board[pos.row()][pos.col()] = Piece('b');
            trace_piece_at(pos);
            m_board[pos.row()][pos.col()] = Piece('r');
            trace_piece_at(pos);
            m_board[pos.row()][pos.col()] = piece;
        }
        case Piece::Type::KING:
        {
            trace = pos.toNorth();
            mark_piece_movable(pos, trace);
            trace = pos.toEast();
            mark_piece_movable(pos, trace);
            trace = pos.toSouth();
            mark_piece_movable(pos, trace);
            trace = pos.toWest();
            mark_piece_movable(pos, trace);

            trace = pos.toNorth().toWest();
            mark_piece_movable(pos, trace);
            trace = pos.toNorth().toEast();
            mark_piece_movable(pos, trace);
            trace = pos.toSouth().toEast();
            mark_piece_movable(pos, trace);
            trace = pos.toSouth().toWest();
            mark_piece_movable(pos, trace);
            break;
        }
        
        default:
            break;
        }
    }
};

int main(int argc, char const *argv[])
{
    std::string line;
    while (std::getline(std::cin >> std::ws, line))
    {
        Chessboard board{ line };
        int count = 0;
        
        for (int i = 0; i < board.numrows(); ++i)
        {
            for (int j = 0; j < board.numcols(); ++j)
            {
                Position piecepos{ i, j };
                if (!board.piece_at(piecepos).empty())
                    board.trace_piece_at(piecepos);
            }
        }

        for (int i = 0; i < board.numrows(); ++i)
        {
            for (int j = 0; j < board.numcols(); ++j)
            {
                Piece piece = board.piece_at({i, j});
                if (piece.empty() && !piece.marked())
                    ++count;
            }
        }

        std::cout << count << "\n";
    }

    return 0;
}

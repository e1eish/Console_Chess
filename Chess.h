#include <iostream>
#include <cmath>
#include <string>

enum Piece {KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, EMPTY};
enum Color {WHITE, BLACK, NONE};

class Tile {
    Piece piece;
    Color color;
    int file;
    int rank;
public:
    void setPiece(Piece p);
    Piece getPiece();
    void setColor(Color c);
    Color getColor();
    void setPieceAndColor(Piece p, Color c);
    void setFile(int newFile);
    int getFile();
    void setRank(int newRank);
    int getRank();
    void setEmpty();
    Tile();
};

class Board {
    Tile tile[8][8];
    Color currentTurn = WHITE;
    bool makeMove();
    bool isRankOrFileClear(int file1, int rank1, int file2, int rank2);
    bool isDiagonalClear(int file1, int rank1, int file2, int rank2);
    bool kingToMove(int file1, int rank1, int file2, int rank2);
    bool queenToMove(int file1, int rank1, int file2, int rank2);
    bool bishopToMove(int file1, int rank1, int file2, int rank2);
    bool knightToMove(int file1, int rank1, int file2, int rank2);
    bool rookToMove(int file1, int rank1, int file2, int rank2);
    bool pawnToMove(int file1, int rank1, int file2, int rank2);
public:
    void displayBoard();
    void playChess();
    Board();
};
#include <iostream>
#include <string>
//#include "Chess.h"

using namespace std;

enum Piece {KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, EMPTY};
enum Color {WHITE, BLACK, NONE};

class Tile {
    Piece piece;
    Color color;
    int x;
    int y;
public:
    void setPiece(Piece p);
    Piece getPiece();
    void setColor(Color c);
    Color getColor();
    void setPieceAndColor(Piece p, Color c);
    void setX(int newX);
    int getX();
    void setY(int newY);
    int getY();
    void setEmpty();
    Tile();
};

class Board {
    Tile tile[8][8];
    Color currentTurn = WHITE;
    void makeMove(int x1, int y1, int x2, int y2);
public:
    void displayBoard();
    Board();
};

Tile::Tile() {
    piece = EMPTY;
    color = NONE;
}

void Tile::setEmpty() {
    piece = EMPTY;
    color = NONE;
}

void Tile::setPiece(Piece p) {
    piece = p;
}

Piece Tile::getPiece() {
    return piece;
}

void Tile::setColor(Color c) {
    color = c;
}

Color Tile::getColor() {
    return color;
}

void Tile::setPieceAndColor(Piece p, Color c) {
    piece = p;
    color = c;
}

void Tile::setX(int newX) {
    x = newX;
}

int Tile::getX() {
    return x;
}

void Tile::setY(int newY) {
    y = newY;
}

int Tile::getY() {
    return y;
}

Board::Board() {
    tile[0][0].setPieceAndColor(ROOK, WHITE);
    tile[0][1].setPieceAndColor(KNIGHT, WHITE);
    tile[0][2].setPieceAndColor(BISHOP, WHITE);
    tile[0][3].setPieceAndColor(QUEEN, WHITE);
    tile[0][4].setPieceAndColor(KING, WHITE);
    tile[0][5].setPieceAndColor(BISHOP, WHITE);
    tile[0][6].setPieceAndColor(KNIGHT, WHITE);
    tile[0][7].setPieceAndColor(ROOK, WHITE);

    for (int i = 0; i < 8; i++) {
        tile[1][i].setPieceAndColor(PAWN, WHITE);
        tile[6][i].setPieceAndColor(PAWN, BLACK);
    }
    
    tile[7][0].setPieceAndColor(ROOK, BLACK);
    tile[7][1].setPieceAndColor(KNIGHT, BLACK);
    tile[7][2].setPieceAndColor(BISHOP, BLACK);
    tile[7][3].setPieceAndColor(QUEEN, BLACK);
    tile[7][4].setPieceAndColor(KING, BLACK);
    tile[7][5].setPieceAndColor(BISHOP, BLACK);
    tile[7][6].setPieceAndColor(KNIGHT, BLACK);
    tile[7][7].setPieceAndColor(ROOK, BLACK);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            tile[i][j].setX(i);
            tile[i][j].setY(j);
        }
    }
}

void Board::displayBoard() {
    /*
    +----+----+----+----+----+----+----+----+
    | BR | BN | BB | BQ | BK | BB | BN | BR | 1
    +----+----+----+----+----+----+----+----+
    | BP | BP | BP | BP | BP | BP | BP | BP | 2
    +----+----+----+----+----+----+----+----+
    |    |    |    |    |    |    |    |    | 3
    +----+----+----+----+----+----+----+----+
    |    |    |    |    |    |    |    |    | 4
    +----+----+----+----+----+----+----+----+
    |    |    |    |    |    |    |    |    | 5
    +----+----+----+----+----+----+----+----+
    |    |    |    |    |    |    |    |    | 6
    +----+----+----+----+----+----+----+----+
    | WP | WP | WP | WP | WP | WP | WP | WP | 7
    +----+----+----+----+----+----+----+----+
    | WR | WN | WB | WQ | WK | WB | WN | WR | 8
    +----+----+----+----+----+----+----+----+
      A    B    C    D    E    F    G    H
    */
    string horizontalLine = "+----+----+----+----+----+----+----+----+";
    cout << horizontalLine << endl;
    int rank = 8;
    for (int i = 7; i > -1; i--) {
        for (int j = 0; j < 8; j++) {
            Piece p = tile[i][j].getPiece();
            Color c = tile[i][j].getColor();
            cout << "| ";
            switch (p) {
                case KING:
                    if (c == WHITE) {
                        cout << "WK ";
                        break;
                    } else {
                        cout << "BK ";
                        break;
                    }
                case QUEEN:
                    if (c == WHITE) {
                        cout << "WQ ";
                        break;
                    } else {
                        cout << "BQ ";
                        break;
                    }
                case BISHOP:
                    if (c == WHITE) {
                        cout << "WB ";
                        break;
                    } else {
                        cout << "BB ";
                        break;
                    }
                case KNIGHT:
                    if (c == WHITE) {
                        cout << "WN ";
                        break;
                    } else {
                        cout << "BN ";
                        break;
                    }
                case ROOK:
                    if (c == WHITE) {
                        cout << "WR ";
                        break;
                    } else {
                        cout << "BR ";
                        break;
                    }
                case PAWN:
                    if (c == WHITE) {
                        cout << "WP ";
                        break;
                    } else {
                        cout << "BP ";
                        break;
                    }
                case EMPTY:
                    cout << "   ";
                    break;
            }
        }
        cout << "| " << rank << endl;
        rank -= 1;
        cout << horizontalLine << endl;
    }
    cout << "  A    B    C    D    E    F    G    H" << endl;
}



int main() {
    Board board;
    board.displayBoard();
    return 0;
}
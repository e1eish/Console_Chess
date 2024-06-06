#pragma once

#include <iostream>
#include <cmath>
#include <string>

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
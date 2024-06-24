#include <iostream>
#include <cmath>
#include <string>
//#include "chess.h"

using namespace std;

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

void Tile::setFile(int newFile) {
    file = newFile;
}

int Tile::getFile() {
    return file;
}

void Tile::setRank(int newRank) {
    rank = newRank;
}

int Tile::getRank() {
    return rank;
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
            tile[i][j].setFile(i);
            tile[i][j].setRank(j);
        }
    }
}

void Board::displayBoard() {
    /*
    +---+---+---+---+---+---+---+---+
    | ♖ | ♘ | ♗ | ♕ | ♔ | ♗ | ♘ | ♖ | 1
    +---+---+---+---+---+---+---+---+
    | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ | 2
    +---+---+---+---+---+---+---+---+
    |   |   |   |   |   |   |   |   | 3
    +---+---+---+---+---+---+---+---+
    |   |   |   |   |   |   |   |   | 4
    +---+---+---+---+---+---+---+---+
    |   |   |   |   |   |   |   |   | 5
    +---+---+---+---+---+---+---+---+
    |   |   |   |   |   |   |   |   | 6
    +---+---+---+---+---+---+---+---+
    | ♟ | ♟ | ♟ | ♟ | ♟ | ♟ | ♟ | ♟ | 7
    +---+---+---+---+---+---+---+---+
    | ♜ | ♞ | ♝ | ♛ | ♚ | ♝ | ♞ | ♜ | 8
    +---+---+---+---+---+---+---+---+
      A   B   C   D   E   F   G   H
    */
    // Unicode codes for all of the pieces
    string whiteKing = "\u265A";
    string whiteQueen = "\u265B";
    string whiteBishop = "\u265D";
    string whiteKnight = "\u265E";
    string whiteRook = "\u265C";
    string whitePawn = "\u265F";
    string blackKing = "\u2654";
    string blackQueen = "\u2655";
    string blackBishop = "\u2657";
    string blackKnight = "\u2658";
    string blackRook = "\u2656";
    string blackPawn = "\u2659";
    string horizontalLine = "+---+---+---+---+---+---+---+---+";
    cout << "" << endl;
    if (currentTurn == WHITE) {
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
                            cout << whiteKing << " ";
                            break;
                        } else {
                            cout << blackKing << " ";
                            break;
                        }
                    case QUEEN:
                        if (c == WHITE) {
                            cout << whiteQueen << " ";
                            break;
                        } else {
                            cout << blackQueen << " ";
                            break;
                        }
                    case BISHOP:
                        if (c == WHITE) {
                            cout << whiteBishop << " ";
                            break;
                        } else {
                            cout << blackBishop << " ";
                            break;
                        }
                    case KNIGHT:
                        if (c == WHITE) {
                            cout << whiteKnight<< " ";
                            break;
                        } else {
                            cout << blackKnight << " ";
                            break;
                        }
                    case ROOK:
                        if (c == WHITE) {
                            cout << whiteRook << " ";
                            break;
                        } else {
                            cout << blackRook << " ";
                            break;
                        }
                    case PAWN:
                        if (c == WHITE) {
                            cout << whitePawn << " ";
                            break;
                        } else {
                            cout << blackPawn << " ";
                            break;
                        }
                    case EMPTY:
                        cout << "  ";
                        break;
                }
            }
            cout << "| " << rank << endl;
            rank -= 1;
            cout << horizontalLine << endl;
        }
        cout << "  A   B   C   D   E   F   G   H" << endl;
    }
    if (currentTurn == BLACK) {
        cout << horizontalLine << endl;
        int rank = 1;
        for (int i = 0; i < 8; i++) {
            for (int j = 7; j > -1; j--) {
                Piece p = tile[i][j].getPiece();
                Color c = tile[i][j].getColor();
                cout << "| ";
                switch (p) {
                    case KING:
                        if (c == WHITE) {
                            cout << whiteKing << " ";
                            break;
                        } else {
                            cout << blackKing << " ";
                            break;
                        }
                    case QUEEN:
                        if (c == WHITE) {
                            cout << whiteQueen << " ";
                            break;
                        } else {
                            cout << blackQueen << " ";
                            break;
                        }
                    case BISHOP:
                        if (c == WHITE) {
                            cout << whiteBishop << " ";
                            break;
                        } else {
                            cout << blackBishop << " ";
                            break;
                        }
                    case KNIGHT:
                        if (c == WHITE) {
                            cout << whiteKnight<< " ";
                            break;
                        } else {
                            cout << blackKnight << " ";
                            break;
                        }
                    case ROOK:
                        if (c == WHITE) {
                            cout << whiteRook << " ";
                            break;
                        } else {
                            cout << blackRook << " ";
                            break;
                        }
                    case PAWN:
                        if (c == WHITE) {
                            cout << whitePawn << " ";
                            break;
                        } else {
                            cout << blackPawn << " ";
                            break;
                        }
                    case EMPTY:
                        cout << "  ";
                        break;
                }
            }
            cout << "| " << rank << endl;
            rank += 1;
            cout << horizontalLine << endl;
        }
        cout << "  H   G   F   E   D   C   B   A" << endl;
    }
    cout << "" << endl;
}

int letterToIntCoord(char letter) {    
    if (letter == 'A' || letter == 'a') {
        return 0;
    } else if (letter == 'B' || letter == 'b') {
        return 1;
    } else if (letter == 'C' || letter == 'c') {
        return 2;
    } else if (letter == 'D' || letter == 'd') {
        return 3;
    } else if (letter == 'E' || letter == 'e') {
        return 4;
    } else if (letter == 'F' || letter == 'f') {
        return 5;
    } else if (letter == 'G' || letter == 'g') {
        return 6;
    } else {
        return 7;
    }
}

bool Board::isRankOrFileClear(int file1, int rank1, int file2, int rank2) {
    if (rank1 == rank2) {
        if (file2 > file1) {
            for (int i = file1 + 1; i < file2; i++) {
                if (tile[rank1][i].getPiece() != EMPTY) {
                    return false;
                }
            }
        } else {
            for (int i = file2 + 1; i < file1; i++) {
                if (tile[rank1][i].getPiece() != EMPTY) {
                    return false;
                }
            }
        }
        return true;
    }
    if (file1 == file2) {
        if (rank2 > rank1) {
            for (int i = rank1 + 1; i < rank2; i++) {
                if (tile[i][file1].getPiece() != EMPTY) {
                    return false;
                }
            }
        } else {
            for (int i = rank2 + 1; i < rank1; i++) {
                if (tile[i][file1].getPiece() != EMPTY) {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

bool Board::isDiagonalClear(int file1, int rank1, int file2, int rank2) {
    // Up and right.
    if (file1 < file2 && rank1 < rank2) {
        for (int i = 1; i < rank2 - rank1; i++) {
            if (tile[rank1 + i][file1 + i].getPiece() != EMPTY) {
                return false;
            }
        }
    // Up and left.
    } else if (file1 > file2 && rank1 < rank2) {
        for (int i = 1; i < rank2 - rank1; i++) {
            if (tile[rank1 + i][file1 - i].getPiece() != EMPTY) {
                return false;
            }
        }
    // Down and right.
    } else if (file1 < file2 && rank1 > rank2) {
        for (int i = 1; i < rank1 - rank2; i++) {
            if (tile[rank1 - i][file1 + i].getPiece() != EMPTY) {
                return false;
            }
        }
    // Down and left.
    } else if (file1 > file2 && rank1 > rank2) {
        for (int i = 1; i < rank1 - rank2; i++) {
            if (tile[rank1 - i][file1 - i].getPiece() != EMPTY) {
                return false;
            }
        }
    }
    return true;
}

bool Board::kingToMove(int file1, int rank1, int file2, int rank2) {
    // Take care of castling.
    if ((tile[rank1][file1].getColor() == WHITE) && (file1 ==4 && rank1 == 0)) {
        // Castle king side.
        if ((file2 == 6 && rank2 == 0) && (tile[0][7].getPiece() == ROOK)) {
            tile[0][5].setPieceAndColor(ROOK, WHITE);
            tile[0][7].setEmpty();
            return true;
        // Castle queen side
        } else if ((file2 == 2 && rank2 == 0) && (tile[0][0].getPiece() == ROOK)) {
            tile[0][3].setPieceAndColor(ROOK, WHITE);
            tile[0][0].setEmpty();
            return true;
        }
    } else if ((tile[rank1][file1].getColor() == BLACK) && (file1 == 4 && rank1 == 7)) {
        // Castle king side.
        if ((file2 == 6 && rank2 == 7) && (tile[7][7].getPiece() == ROOK)) {
            tile[7][5].setPieceAndColor(ROOK, BLACK);
            tile[7][7].setEmpty();
            return true;
        // Castle queen side.
        } else if ((file2 == 2 && rank2 == 7) && (tile[7][0].getPiece() == ROOK)) {
            tile[7][3].setPieceAndColor(ROOK, BLACK);
            tile[7][0].setEmpty();
            return true;
        }
    }

    if ((file2 >= file1 - 1) && (file2 <= file1 + 1) && (rank2 >= rank1 - 1) && (rank2 <= rank1 + 1)) {
        return true;
    }
    
    return false;
}

bool Board::queenToMove(int file1, int rank1, int file2, int rank2) {
    // Check if the squares are diagonal to each other. |x2 - x1| = |y2 - y1|
    if (abs(file2 - file1) == abs(rank2 - rank1)) {
        return isDiagonalClear(file1, rank1, file2, rank2);
    }
    if (rank1 == rank2 || file1 == file2) {
        return isRankOrFileClear(file1, rank1, file2, rank2);
    }
    return false;
}

bool Board::bishopToMove(int file1, int rank1, int file2, int rank2) {
    // Check if the squares are diagonal to each other. |x2 - x1| = |y2 - y1|
    if (abs(file2 - file1) == abs(rank2 - rank1)) {
        return isDiagonalClear(file1, rank1, file2, rank2);
    }
    return false;
}

bool Board::knightToMove(int file1, int rank1, int file2, int rank2) {
    // Moving up.
    if ((rank2 == rank1 + 2) && (file2 == file1 + 1 || file2 == file1 - 1)) {
        return true;
    // Moving down.
    } else if ((rank2 == rank1 - 2) && (file2 == file1 + 1 || file2 == file1 - 1)) {
        return true;
    // Moving right.
    } else if ((file2 == file1 + 2) && (rank2 == rank1 + 1 || rank2 == rank1 - 1)) {
        return true;
    // Moving left.
    } else if ((file2 == file1 - 1) && (rank2 == rank1 + 1 || rank2 == rank1 - 1)) {
        return true;
    }
    return false;
}

bool Board::rookToMove(int file1, int rank1, int file2, int rank2) {
    // Must stay on rank or file.
    if (rank1 != rank2 && file1 != file2) {
        return false;
    }
    // Check rank or file for pieces in the way.
    return isRankOrFileClear(file1, rank1, file2, rank2);
}

bool Board::pawnToMove(int file1, int rank1, int file2, int rank2) {
    if (tile[rank1][file1].getColor() == WHITE) {
        // Starting possible two squares
        if (rank1 == 1 && rank2 == 3 && file1 == file2) {
            return true;
        }
        // Normal move.
        if (rank2 == rank1 + 1 && file1 == file2 && tile[rank2][file2].getPiece() == EMPTY) {
            return true;
        }
        // Capturing a piece.
        if (rank2 == rank1 + 1 && (file2 == file1 + 1 || file2 == file1 - 1)) {
            // Normal capture.
            if (tile[rank2][file2].getColor() == BLACK) {
                return true;
            }
            // En passant
            if (tile[rank2 - 1][file2].getColor() == BLACK && rank1 == 4) {
                tile[rank2 - 1][file2].setEmpty();
                return true;
            }
        }
    } else {
        // Starting possible two squares
        if (rank1 == 6 && rank2 == 4 && file1 == file2) {
            return true;
        }
        // Normal move.
        if (rank2 == rank1 - 1 && file1 == file2) {
            return true;
        }
        // Capturing a piece.
        if (rank2 == rank1 - 1 && (file2 == file1 + 1 || file2 == file1 - 1) && tile[rank2][file2].getColor() == WHITE) {
            // Normal capture.
            if (tile[rank2][file2].getColor() == WHITE) {
                return true;
            }
            // En passant
            if (tile[rank1][file2].getColor() == WHITE && rank1 == 3) {
                tile[rank1][file2].setEmpty();
                return true;
            }
        }
    }
    return false;
}

bool Board::makeMove() {
    string coordStart;
    string coordEnd;
    int file1;
    int rank1;
    int file2;
    int rank2;
    bool isValid = false;
    bool validMove = false;

    string turnName;
    if (currentTurn == WHITE) {
        turnName = "White";
    } else {
        turnName = "Black";
    }

    while (validMove == false) {
        // Getting coordinate of the piece to move.
        isValid = false;
        while (isValid == false) {
            cout << "What is the coordinate (A1) of the piece you want to move?\n" << turnName << "> ";
            cin >> coordStart;
            if (coordStart == "q" || coordStart == "Q") {
                exit(0);
            }

            file1 = letterToIntCoord(coordStart[0]);
            rank1 = coordStart[1] - 49;

            if (file1 < 0 || file1 > 7) {
                cout << "Please enter a coordinate within the board." << endl;
            } else if (rank1 < 0 || rank1 > 7) {
                cout << "Please enter a coordinate within the board." << endl;
            } else if (tile[rank1][file1].getColor() != currentTurn) {
                cout << "Please enter a coordinate that has your piece." << endl;
            } else {
                isValid = true;
            }
        }

        // Getting coordinate of the destination tile.
        isValid = false;
        while (isValid == false) {
            cout << "What is the coodinate the piece should be placed at?\n> ";
            cin >> coordEnd;
            if (coordEnd == "q" || coordEnd == "Q") {
                exit(0);
            }

            file2 = letterToIntCoord(coordEnd[0]);
            rank2 = coordEnd[1] - 49;

            if (file2 < 0 || file2 > 7) {
                cout << "Please enter a coordinate within the board." << endl;
            } else if (rank2 < 0 || rank2 > 7) {
                cout << "Please enter a coordinate within the board." << endl;
            } else if (tile[rank2][file2].getColor() == currentTurn) {
                cout << "That space already has a piece." << endl;
            } else {
                isValid = true;
            }
        }

        // King to move.
        if (tile[rank1][file1].getPiece() == KING) {
            if (kingToMove(file1, rank1, file2, rank2)) {
                validMove = true;
            } else {
                cout << "The king cannot move there." << endl;
            }
        }

        // Queen to move.
        if (tile[rank1][file1].getPiece() == QUEEN) {
            if (queenToMove(file1, rank1, file2, rank2)) {
                validMove = true;
            } else {
                cout << "The queen cannot move there." << endl;
            }
        }

        // Bishop to move.
        if (tile[rank1][file1].getPiece() == BISHOP) {
            if (bishopToMove(file1, rank1, file2, rank2)) {
                validMove = true;
            } else {
                cout << "The bishop cannot move there." << endl;
            }
        }

        // Knight to move.
        if (tile[rank1][file1].getPiece() == KNIGHT) {
            if (knightToMove(file1, rank1, file2, rank2)) {
                validMove = true;
            } else {
                cout << "The knight cannot move there." << endl;
            }
        }

        // Rook to move.
        if (tile[rank1][file1].getPiece() == ROOK) {
            if (rookToMove(file1, rank1, file2, rank2)) {
                validMove = true;
            } else {
                cout << "The rook cannot move there." << endl;
            }
        }

        // Pawn to move.
        if (tile[rank1][file1].getPiece() == PAWN) {
            if (pawnToMove(file1, rank1, file2, rank2)) {
                validMove = true;
                // Promotion
                if (rank2 == 0 || rank2 == 7) {
                    string promotionPieceString;
                    cout << "What piece would you like to promote to? (Q, B, N, R)\n> ";
                    cin >> promotionPieceString;
                    Piece promotionPiece;
                    if (promotionPieceString == "Q") {
                        promotionPiece = QUEEN;
                    } else if (promotionPieceString == "B") {
                        promotionPiece = BISHOP;
                    } else if (promotionPieceString == "N") {
                        promotionPiece = KNIGHT;
                    } else if (promotionPieceString == "R") {
                        promotionPiece = ROOK;
                    } else {
                        promotionPiece = QUEEN;
                    }
                    tile[rank1][file1].setPiece(promotionPiece);
                }
            } else {
                cout << "The pawn cannot move there." << endl;
            }
        }
    }

    // Check king captured.
    if (tile[rank2][file2].getPiece() == KING) {
        tile[rank2][file2].setPieceAndColor(tile[rank1][file1].getPiece(), tile[rank1][file1].getColor());
        tile[rank1][file1].setEmpty();
        if (currentTurn == WHITE) {
            cout << "White won!" << endl;
        } else {
            cout << "Black won!" << endl;
        }
        return true;
    }

    tile[rank2][file2].setPieceAndColor(tile[rank1][file1].getPiece(), tile[rank1][file1].getColor());
    tile[rank1][file1].setEmpty();
    if (currentTurn == WHITE) {
        currentTurn = BLACK;
    } else {
        currentTurn = WHITE;
    }
    return false;
}

void Board::playChess() {
    displayBoard();
    bool isPlaying = true;
    while (isPlaying) {
        if (makeMove()) {
            isPlaying = false;
        }
        displayBoard();
    }
}

void displayStartMessage() {
    /*
        . ..\n
       . ....\n
       . ....\n
        . ..\n
      . ......\n\n

       .  ...\n
       .  ...\n
       .  ...\n
       .  ...\n
      .   ....\n
     .   ......\n
     .  .......\n\n

    .  .........\n
    -----------------
    Welcome to Chess!
    Enter coordinates, in the form E6, to select and move pieces. Take turns until someone delivers checkmate to their opponent's king.
    Type "Q" to quit. 
    */
    string startArt = "    . ..\n   . ....\n   . ....\n    . ..\n  . ......\n\n   .  ...\n   .  ...\n   .  ...\n   .  ...\n  .   ....\n .   ......\n .  .......\n.  .........\n";
    string startMessage = "Welcome to Chess!\nEnter coordinates, in the form E6, to select and move pieces. Take turns until someone delivers checkmate to their opponent's king.\nType \"Q\" to quit.";
    cout << "\n" << startArt << "-----------------\n" << startMessage << endl;
}

int main() {
    Board board;
    displayStartMessage();
    board.playChess();
    return 0;
}
#include <iostream>
#include <string>
//#include "Chess.h"

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

int letterToIntCoord(char letter) {
    char first = 'A';
    char second = 'B';
    char third = 'C';
    char fourth = 'D';
    char fifth = 'E';
    char sixth = 'F';
    char seventh = 'G';
    char eighth = 'H';
    
    if (letter == first) {
        return 0;
    } else if (letter == second) {
        return 1;
    } else if (letter == third) {
        return 2;
    } else if (letter == fourth) {
        return 3;
    } else if (letter == fifth) {
        return 4;
    } else if (letter == sixth) {
        return 5;
    } else if (letter == seventh) {
        return 6;
    } else {
        return 7;
    }
}

bool Board::kingToMove(int file1, int rank1, int file2, int rank2) {
    // Take care of castling.
    if ((tile[rank1][file1].getColor() == WHITE) && (file1 ==4 && rank1 == 0)) {
        // Castle king side.
        if ((file2 == 6 && rank2 == 0) && (tile[0][7].getPiece() == ROOK)) {
            tile[0][5].setPieceAndColor(ROOK, WHITE);
            tile[0][7].setEmpty();
            return true;
        } else if ((file2 == 2 && rank2 == 0) && (tile[0][0].getPiece() == ROOK)) { // Castle queen side.
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
        } else if ((file2 == 2 && rank2 == 7) && (tile[7][0].getPiece() == ROOK)) { // Castle queen side.
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
    return true;
}

bool Board::bishopToMove(int file1, int rank1, int file2, int rank2) {
    return true;
}

bool Board::knightToMove(int file1, int rank1, int file2, int rank2) {
    return true;
}

bool Board::rookToMove(int file1, int rank1, int file2, int rank2) {
    return true;
}

bool Board::pawnToMove(int file1, int rank1, int file2, int rank2) {
    return true;
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

    while (validMove == false) {
        while (isValid == false) {
            cout << "What is the coordinate (A1) of the piece you want to move?\n> ";
            cin >> coordStart;
            if (coordStart == "q" || coordStart == "Q") {
                exit(0);
            }

            file1 = letterToIntCoord(coordStart[0]);
            rank1 = coordStart[1] - 49;

            //cout << "x:" << file1 << ", y:" << rank1 << endl;
            //cout << "piece:" << tile[rank1][file1].getPiece() << ", color:" << tile[rank1][file1].getColor() << endl;

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

        isValid = false;
        while (isValid == false) {
            cout << "What is the coodinate (A1) the piece should be placed at?\n> ";
            cin >> coordEnd;
            if (coordEnd == "q" || coordEnd == "Q") {
                exit(0);
            }

            file2 = letterToIntCoord(coordEnd[0]);
            rank2 = coordEnd[1] - 49;

            //cout << "x:" << file2 << "y:" << rank2 << endl;
            //cout << "piece:" << tile[rank2][file2].getPiece() << ", color:" << tile[rank2][file2].getColor() << endl;

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



int main() {
    Board board;
    board.playChess();
    return 0;
}
#include <iostream>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

struct ChessPiece {
    char type;
    int row, col;
};
const char PIECES[] = {'P', 'R', 'N', 'B', 'K', 'Q', 'X', 'O'};

int checkCell(ChessPiece &piece, int row, int col) {
    if (piece.row == row && piece.col == col)
        return 6;
    switch (piece.type) {
    case 'P':
        if (piece.row == row - 1 && abs(piece.col - col) == 1)
            return 0;
        break;
    case 'R':
        if (piece.row == row || piece.col == col)
            return 1;
        break;
    case 'N':
        if ((abs(piece.row - row) == 2 && abs(piece.col - col) == 1) || (abs(piece.row - row) == 1 && abs(piece.col - col) == 2))
            return 2;
        break;
    case 'B':
        if (abs(piece.row - row) == abs(piece.col - col))
            return 3;
        break;
    case 'K':
        if (abs(piece.row - row) <= 1 && abs(piece.col - col) <= 1)
            return 4;
        break;
    case 'Q':
        if (piece.row == row || piece.col == col || abs(piece.row - row) == abs(piece.col - col))
            return 5;
        break;
    default:
        break;
    }
    return -1;
}

int main() {
    ChessPiece board[64];
    int pieceCount = 0;
    for (int i = 0; i < 8; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < row.size(); j++) {
            if (row[j] != PIECES[7]) {
                board[pieceCount++] = {row[j], i + 1, j + 1};
            }
        }
    }
    int queries;
    cin >> queries;
    string* output = new string[queries];
    for (int i = 0; i < queries; i++) {
        set<char> attackingPieces;
        int row, col;
        cin >> row >> col;
        bool isEmpty = true;
        bool isPieceOnCell = false;
        for (int j = 0; j < pieceCount; j++) {
            int result = checkCell(board[j], row, col);
            if (result >= 0 && result <= 5) {
                attackingPieces.insert(PIECES[result]);
                isEmpty = false;
            } else if (result == 6) {
                isPieceOnCell = true;
                isEmpty = false;
            }
        }
        if (isPieceOnCell) {
            output[i] = "X";
        } else if (isEmpty) {
            output[i] = "O";
        } else {
            for (auto it = attackingPieces.begin(); it != attackingPieces.end(); ++it) {
                output[i] += *it;
            }
        }
    }
    for (int i = 0; i < queries; i++) {
        cout << output[i] << endl;
    }
    delete[] output;
    return 0;
}

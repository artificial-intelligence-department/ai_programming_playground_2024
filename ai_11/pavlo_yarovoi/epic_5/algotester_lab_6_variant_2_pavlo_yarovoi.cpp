#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int BOARD_SIZE = 8;

bool canAttack(char pieceType, int pieceRow, int pieceCol, int targetRow, int targetCol) {
    switch (pieceType) {
        case 'R': 
            return pieceRow == targetRow || pieceCol == targetCol;
        case 'B': 
            return abs(pieceRow - targetRow) == abs(pieceCol - targetCol);
        case 'N': 
            return (abs(pieceRow - targetRow) == 2 && abs(pieceCol - targetCol) == 1) ||
                   (abs(pieceRow - targetRow) == 1 && abs(pieceCol - targetCol) == 2);
        case 'P': 
            return pieceRow + 1 == targetRow && abs(pieceCol - targetCol) == 1;
        case 'K': 
            return abs(pieceRow - targetRow) <= 1 && abs(pieceCol - targetCol) <= 1;
        case 'Q': 
            return (pieceRow == targetRow || pieceCol == targetCol) ||
                   (abs(pieceRow - targetRow) == abs(pieceCol - targetCol));
        default: 
            return false;
    }
}

int main() {
    vector<string> chessBoard(BOARD_SIZE);
    for (int row = 0; row < BOARD_SIZE; row++) {
        cin >> chessBoard[row];
    }

    int queryCount;
    cin >> queryCount;
    vector<string> queryResults(queryCount);

    for (int query = 0; query < queryCount; query++) {
        int targetRow, targetCol;
        cin >> targetRow >> targetCol;
        targetRow--;
        targetCol--;

        if (chessBoard[targetRow][targetCol] != 'O') {
            queryResults[query] = "X";
            continue;
        }

        string threats;
        for (int row = 0; row < BOARD_SIZE; row++) {
            for (int col = 0; col < BOARD_SIZE; col++) {
                char currentPiece = chessBoard[row][col];
                if (currentPiece != 'O' && canAttack(currentPiece, row, col, targetRow, targetCol)) {
                    if (threats.find(currentPiece) == string::npos) {
                        threats += currentPiece;
                    }
                }
            }
        }

        if (threats.empty()) {
            queryResults[query] = "O";
        } else {
            sort(threats.begin(), threats.end());
            queryResults[query] = threats;
        }
    }

    for (const auto& result : queryResults) {
        cout << result << endl;
    }

    return 0;
}

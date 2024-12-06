#include <iostream>
#include <string>

using namespace std;

int main() {
    int gridSize, queryCount;
    cin >> gridSize;

    int grid[gridSize][gridSize];
    int possibleNumbers[gridSize + 1];

    for (int i = 1; i <= gridSize; i++) {
        possibleNumbers[i] = i;
    }

    for (int row = 0; row < gridSize; row++) {
        string inputRow;
        cin >> inputRow;
        for (int col = 0; col < gridSize; col++) {
            grid[row][col] = inputRow[col] - '0';
        }
    }

    cin >> queryCount;
    int queryCoordinates[queryCount][2];

    for (int i = 0; i < queryCount; i++) {
        cin >> queryCoordinates[i][0] >> queryCoordinates[i][1];
        queryCoordinates[i][0]--;
        queryCoordinates[i][1]--;
    }

    for (int i = 0; i < queryCount; i++) {
        int queryRow = queryCoordinates[i][0];
        int queryCol = queryCoordinates[i][1];

        if (grid[queryRow][queryCol] == 0) {
            int availableNumbers[gridSize + 1];
            for (int j = 1; j <= gridSize; j++) {
                availableNumbers[j] = possibleNumbers[j];
            }

            for (int j = 0; j < gridSize; j++) {
                if (grid[queryRow][j] > 0) {
                    availableNumbers[grid[queryRow][j]] = 0;
                }
                if (grid[j][queryCol] > 0) {
                    availableNumbers[grid[j][queryCol]] = 0;
                }
            }

            int count = 0;
            for (int j = 1; j <= gridSize; j++) {
                if (availableNumbers[j] != 0) {
                    count++;
                }
            }

            cout << count << endl;
            for (int j = 1; j <= gridSize; j++) {
                if (availableNumbers[j] != 0) {
                    cout << availableNumbers[j] << " ";
                }
            }
            cout << endl << endl;
        } else {
            cout << "1" << endl;
            cout << grid[queryRow][queryCol] << endl << endl;
        }
    }

    return 0;
}

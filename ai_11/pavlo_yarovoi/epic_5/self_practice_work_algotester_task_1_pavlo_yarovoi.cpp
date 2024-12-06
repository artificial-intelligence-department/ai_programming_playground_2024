#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

vector<int> getPossibleNumbers(const vector<string>& grid, int row, int col) {
    vector<int> availableNumbers;
    int size = grid.size();
    
    if (grid[row][col] != '0') {
        availableNumbers.push_back(grid[row][col] - '0');
        return availableNumbers;
    }

    set<int> usedDigits;
    for (int i = 0; i < size; ++i) {
        if (grid[row][i] != '0') usedDigits.insert(grid[row][i] - '0');
        if (grid[i][col] != '0') usedDigits.insert(grid[i][col] - '0');
    }

    for (int num = 1; num <= size; ++num) {
        if (usedDigits.find(num) == usedDigits.end()) {
            availableNumbers.push_back(num);
        }
    }
    return availableNumbers;
}

int main() {
    int gridSize;
    cin >> gridSize;
    vector<string> sudokuGrid(gridSize);

    for (int i = 0; i < gridSize; ++i) {
        cin >> sudokuGrid[i];
    }

    int numQueries;
    cin >> numQueries;
    vector<pair<int, int>> queries(numQueries);

    for (int i = 0; i < numQueries; ++i) {
        int row, col;
        cin >> row >> col;
        queries[i] = {row - 1, col - 1};  
    }

    for (const auto& query : queries) {
        int row = query.first, col = query.second;
        vector<int> possibleNumbers = getPossibleNumbers(sudokuGrid, row, col);
        
        cout << possibleNumbers.size() << endl;
        for (int num : possibleNumbers) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}


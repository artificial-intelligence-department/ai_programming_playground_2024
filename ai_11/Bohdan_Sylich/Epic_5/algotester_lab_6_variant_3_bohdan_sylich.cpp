#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

vector<int> findNumbers(const vector<string> &sudoku, int x, int y) {
    vector<int> possibleNumbers;
    int N = sudoku.size();
    if (sudoku[x][y] != '0') {
        possibleNumbers.push_back(sudoku[x][y] - '0');
        return possibleNumbers;
    }
    set<int> usedNumbers;
    for (int i = 0; i < N; i++) {
        if (sudoku[x][i] != '0') usedNumbers.insert(sudoku[x][i] - '0');
        if (sudoku[i][y] != '0') usedNumbers.insert(sudoku[i][y] - '0');
    }
    for (int num = 1; num <= N; num++) {
        if (usedNumbers.find(num) == usedNumbers.end()) {
            possibleNumbers.push_back(num);
        }
    }
    return possibleNumbers;
}

int main() {
    int N;
    cin >> N;
    vector<string> sudoku(N);
    for (int i = 0; i < N; i++) {
        cin >> sudoku[i];
    }
    int Q;
    cin >> Q;
    vector<pair<int, int>> queries(Q);
    
    for (int i = 0; i < Q; i++) {
        int x, y;
        cin >> x >> y;
        queries[i] = {x - 1, y - 1};
    }

    for (const auto &query : queries) {
        int x = query.first;
        int y = query.second;
        vector<int> result = findNumbers(sudoku, x, y);
        cout << result.size() << endl;
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
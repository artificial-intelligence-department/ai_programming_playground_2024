#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int size;
    cin >> size;

    if (size < 1 || size > 9) {
        cerr << "Помилка: Розмір має бути від 1 до 9." << endl;
        return 1;
    }

    vector<vector<int>> matrix(size, vector<int>(size));

    for (int row = 0; row < size; ++row) {
        string line;
        cin >> line;

        if (line.length() != size) {
            cerr << "Помилка: У кожному рядку має бути рівно " << size << " символів." << endl;
            return 1;
        }

        for (int col = 0; col < size; ++col) {
            matrix[row][col] = line[col] - '0';

            if (matrix[row][col] < 0 || matrix[row][col] > 9) {
                cerr << "Помилка: Кожна клітинка має містити цифру від 0 до 9." << endl;
                return 1;
            }
        }
    }

    int queriesCount;
    cin >> queriesCount;

    if (queriesCount < 1 || queriesCount > 1000) {
        cerr << "Помилка: Кількість запитів має бути від 1 до 1000." << endl;
        return 1;
    }

    vector<pair<int, int>> positions(queriesCount);

    for (int q = 0; q < queriesCount; ++q) {
        int row, col;
        cin >> row >> col;

        if (row < 1 || row > size || col < 1 || col > size) {
            cerr << "Помилка: Координати запиту мають бути в межах від 1 до " << size << "." << endl;
            return 1;
        }

        positions[q] = {row - 1, col - 1}; 
    }

    for (const auto& pos : positions) {
        int rowIdx = pos.first;
        int colIdx = pos.second;

        if (matrix[rowIdx][colIdx] != 0) {
            cout << "1\n" << matrix[rowIdx][colIdx] << "\n";
            continue;
        }

        vector<bool> available(size + 1, true);

        // Забороняємо числа з поточного рядка
        for (int col = 0; col < size; ++col) {
            if (matrix[rowIdx][col] != 0) {
                available[matrix[rowIdx][col]] = false;
            }
        }

        // Забороняємо числа з поточного стовпця
        for (int row = 0; row < size; ++row) {
            if (matrix[row][colIdx] != 0) {
                available[matrix[row][colIdx]] = false;
            }
        }

        vector<int> validNumbers;
        for (int num = 1; num <= size; ++num) {
            if (available[num]) {
                validNumbers.push_back(num);
            }
        }

        cout << validNumbers.size() << "\n";
        for (int num : validNumbers) {
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}

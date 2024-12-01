#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++) {
            matrix[i][j] = row[j] - '0';  // Перетворюємо символ у число
        }
    }

    int q;
    cin >> q;

    vector<pair<int, int>> coordinates(q);
    for (int i = 0; i < q; i++) {
        cin >> coordinates[i].first >> coordinates[i].second;
        coordinates[i].first--;  // Перетворюємо на 0-індексацію
        coordinates[i].second--;
    }

    for (const auto& [x, y] : coordinates) {
        // Якщо клітинка вже заповнена, виводимо 1 і саме значення
        if (matrix[x][y] != 0) {
            cout << "1 " << matrix[x][y] << "\n";
            continue;
        }

        // Знаходимо всі числа, які не можна вписати
        set<int> unavailable_num;
        for (int j = 0; j < n; j++) {
            if (matrix[x][j] != 0) {
                unavailable_num.insert(matrix[x][j]);  // Числа в рядку
            }
            if (matrix[j][y] != 0) {
                unavailable_num.insert(matrix[j][y]);  // Числа в стовпці
            }
        }

        // Знаходимо всі можливі числа
        vector<int> available_num;
        for (int num = 1; num <= n; num++) {
            if (unavailable_num.find(num) == unavailable_num.end()) {
                available_num.push_back(num);
            }
        }

        // Виводимо результат
        cout << available_num.size();
        for (int num : available_num) {
            cout << " " << num;
        }
        cout << "\n";
    }

    return 0;
}

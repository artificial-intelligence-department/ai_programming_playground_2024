#include <iostream>

using namespace std;

bool findElement(int matrix[][5], int rows, int cols, int target) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == target) {
                cout << "Елемент знайдено на позиції: (" << i << ", " << j << ")" << endl;
                return true;
            }
        }
    }
    cout << "Елемент не знайдено." << endl;
    return false;
}

int main() {
    int matrix[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    
    int target;
    cout << "Введіть число для пошуку: ";
    cin >> target;
    
    findElement(matrix, 5, 5, target);

    return 0;
}
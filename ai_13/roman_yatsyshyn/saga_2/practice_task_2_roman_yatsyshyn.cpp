#include <iostream>
#include <climits>

using namespace std;

bool findMinElement(int matrix[][5], int rows, int cols) {
    int minElement = INT_MAX;
    int x, y;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] < minElement) {
                minElement = matrix[i][j];    
                x = i;
                y = j;
            }
        }
    }
    cout << "Найменший елемент матриці = " << minElement << " на позиції (" << x+1 << " , " << y+1 << ")." << endl;
    return 0;
}

int main() {
    int matrix[5][5] = {
        {5, 8, 1, 3, 7},
        {2, 6, 4, 9, 10},
        {15, 12, 18, 14, 11},
        {20, 13, 19, 16, 17},
        {25, 24, 22, 21, 23}
};
    
    findMinElement(matrix, 5, 5);

    return 0;
}
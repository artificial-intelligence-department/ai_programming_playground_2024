#include <iostream>
#include <vector>

std::vector<std::vector<int>> matrix;
int rows, cols;

bool notIn(int k, std::vector<int> indeces) {
    for (const int& i : indeces) if (k == i) return false;
    return true;
}

void sort(std::vector<int> col) {

        std::vector<std::vector<int>> newMatrix;
        std::vector<int> indeces;
        int counter = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (int z = 0; z < rows; z++) {
                    if (matrix[z][j] == col[i]) {
                        indeces.push_back(z);
                        break;
                    }
                }
            }
            
        }
            
        for (int i = 0; i < rows; i++) {
            newMatrix.push_back(matrix[indeces[i]]);
        }
        matrix = newMatrix;
        return;
}

void showMatrix() {
    for (const std::vector<int>& vec : matrix) {
        for (const int& val : vec) std::cout << val << " ";
        std::cout << std::endl;
    }
}

int main() {

    std::cin >> rows >> cols;

    std::vector<int> vec(2 * rows * cols);
    std::cout << "Enter rows: \n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> vec[i * cols + j];
        }
    }
    int rc = rows * cols;
    std::cout << "Enter cols: \n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> vec[rc + i * cols + j];
        }
    }

    for (int i = 0; i < rows; i++) {
        std::vector<int> temp(cols);
        for (int j = 0; j < cols; j++) {
            temp[j] = vec[i * cols + j];
        }
        matrix.push_back(temp);
    }

    std::vector<int> col(rows);
    for (int j = 0; j < rows; j++) {
        col[j] = vec[rc + j];
    }
    sort(col);
    showMatrix();

}
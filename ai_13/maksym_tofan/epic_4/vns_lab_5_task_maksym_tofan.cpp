#include <iostream>
#include <vector>

bool canSplitArray(const std::vector<std::vector<int>>& arr) {
    int rows = arr.size();
    int cols = arr[0].size();
    
    int totalSum = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            totalSum += arr[i][j];
        }
    }
    
    for (int col = 0; col < cols; ++col) {
        int leftSum = 0;
        int rightSum = 0;
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < col; ++j) {
                leftSum += arr[i][j];
            }
            for (int j = col + 1; j < cols; ++j) {
                rightSum += arr[i][j];
            }
        }
        
        if (leftSum > rightSum) {
            return true;
        }
    }

    return false;
}

int main() {
    std::vector<std::vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    if (canSplitArray(arr)) {
        std::cout << "Можна знайти стовпець, який розбиває масив правильно." << std::endl;
    } else {
        std::cout << "Не можна знайти такий стовпець." << std::endl;
    }

    return 0;
}

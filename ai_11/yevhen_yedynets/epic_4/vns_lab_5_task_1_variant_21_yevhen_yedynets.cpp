#include <iostream>

using namespace std;

int findMaxRepeated(int arr[3][3], int rows, int cols) {
    int freq[100] = {0};
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            freq[arr[i][j]]++;
        }
    }
    
    int maxRepeated = -1;
    int maxCount = 1;
    
    for (int i = 0; i < 100; ++i) {
        if (freq[i] > maxCount) {
            maxCount = freq[i];
            maxRepeated = i;
        }
    }
    
    return maxRepeated;
}

int main() {
    int arr[3][3] = {
        {1, 2, 3},
        {3, 2, 4},
        {5, 3, 3}
    };
    
    int result = findMaxRepeated(arr, 3, 3);
    
    if (result != -1) {
        cout << "Максимальний з повторюваних елементів: " << result << endl;
    } else {
        cout << "Немає повторюваних елементів" << endl;
    }
    
    return 0;
}

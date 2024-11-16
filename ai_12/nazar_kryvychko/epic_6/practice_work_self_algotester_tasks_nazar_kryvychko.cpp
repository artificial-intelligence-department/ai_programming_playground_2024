#include <iostream>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;
    
    int* teeths = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> teeths[i];
    }

    int maxConsecutive = 0;
    int currentConsecutive = 0;

    for (int i = 0; i < n; i++) {
        if (teeths[i] >= k) {
            currentConsecutive++;
            maxConsecutive = std::max(maxConsecutive, currentConsecutive);
        } else {
            currentConsecutive = 0; 
        }
    }

    std::cout << maxConsecutive;

    delete[] teeths; 
    return 0;
}

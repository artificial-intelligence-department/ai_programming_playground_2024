#include <iostream>
#include <vector>
#include <limits.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> array(N);
    for (int i = 0; i < N; ++i)
        std::cin >> array[i];

    int biggest = array[0];
    int lowest = array[0];
    for (int i = 1; i < N; ++i) {
        if (array[i] > biggest)
            biggest = array[i];
        if (array[i] < lowest)
            lowest = array[i];
    }

    int result = INT_MAX;

    for (int i = 0; i < N; ++i) {
        std::vector<int> tempArray = array;
        tempArray.erase(tempArray.begin() + i);

        int tempBiggest = tempArray[0];
        int tempLowest = tempArray[0];
        for (int j = 1; j < tempArray.size(); ++j) {
            if (tempArray[j] > tempBiggest)
                tempBiggest = tempArray[j];
            if (tempArray[j] < tempLowest)
                tempLowest = tempArray[j];
        }

        int diff = tempBiggest - tempLowest;
        if (diff < result)
            result = diff;
    }

    std::cout << result << std::endl;

    return 0;
}

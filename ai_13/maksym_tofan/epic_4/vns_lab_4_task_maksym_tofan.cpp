#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int getSmallest(int array[], int length) {
    int smallest = array[0];
    for (int i = 1; i < length; i++) {
        if (array[i] < smallest) {
            smallest = array[i];
        }
    }
    return smallest;
}

void removeElement(int array[], int& length, int value) {
    for (int i = 0; i < length; i++) {
        if (array[i] == value) {
            for (int j = i; j < length - 1; j++) {
                array[j] = array[j + 1];
            }
            length--;
            i--;
        }
    }
}

void prependElement(int array[], int& length, int value) {
    for (int i = length; i > 0; i--) {
        array[i] = array[i - 1];
    }
    array[0] = value;
    length++;
}

void printArray(int array[], int length) {
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    
    int arraySize, totalSum = 0;
    int numbers[100];

    cin >> arraySize;

    for (int i = 0; i < arraySize; i++) {
        numbers[i] = rand() % 11;
        cout << numbers[i] << " ";
    }
    cout << endl;

    int smallest = getSmallest(numbers, arraySize);
    removeElement(numbers, arraySize, smallest);

    for (int i = 0; i < arraySize; i++) {
        totalSum += numbers[i];
    }
    int average = totalSum / arraySize;

    for (int i = 0; i < 3; i++) {
        prependElement(numbers, arraySize, average);
    }

    printArray(numbers, arraySize);

    return 0;
}

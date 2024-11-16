#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateRandomArray(int arr[], int size, int minValue, int maxValue) {
    for (int i = 0; i < size; ++i) {
        arr[i] = minValue + rand() % (maxValue - minValue + 1);
    }
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void removeLastZero(int arr[], int& size) {
    for (int i = size - 1; i >= 0; --i) {
        if (arr[i] == 0) {
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            size--;
            break;
        }
    }
}

void addElementAfterIndex(int arr[], int& size, int index, int value) {
    if (index >= 0 && index < size) {
        for (int i = size-1; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index + 1] = value;
        size++;
    }
}

int main() {
    srand(time(0)); 
    
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size = 10; 

    generateRandomArray(arr, size, -2, 2);
    cout << "Generated array: ";
    printArray(arr, size);
    removeLastZero(arr, size);
    printArray(arr, size);

    int index = 3;
    addElementAfterIndex(arr, size, index, 100);

    cout << "Modified array: ";
    printArray(arr, size);

    return 0;
}
#include <iostream>
using namespace std;

void quickSort (int arr[], int first, int last) {
    int i = first;
    int j = last;
    int middle = arr[(first + last) / 2];
    do {
    while (arr[i] < middle) {
        i++;
    }
    while (arr[j] > middle) {
        j--;
    }
    if (i <= j) {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }

    } while (i <= j);
    if (i < last) {
        quickSort(arr, i, last);
    }
    if (j > first) {
        quickSort(arr, first, j);
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int key = arr[i];
        int j;
        for (j = i - 1; j >= 0 && arr[j] > key; j--) {
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
    }

}

int main() {
    int arr[10];
    for (int i; i < 10; i++) {
        cin >> arr[i];
    }
    insertionSort(arr, 10);
    for (int j = 0; j < 10; j++) {
    cout << arr[j] << " ";
    }
    return 0;
}
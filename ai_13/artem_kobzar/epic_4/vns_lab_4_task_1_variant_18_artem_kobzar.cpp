#include <iostream>
using namespace std;

void printFromK(const int arr[], int n, int K) {
    for (int i = 0; i < n; i++) {
        cout << arr[((K-1) + i) % n] << " ";
    }
    cout << endl;
}

void addFirstAndLast(int arr[], int &n) {
    if (n == 0){
        return;
    }
    for (int i = n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = arr[1];
    arr[n + 1] = arr[n];
    n += 2;
}

void removeEven(int arr[], int &n) {
    int newSize = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            arr[newSize++] = arr[i];
        }
    }
    n = newSize;
}


int main() {
    int arr[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 9;
    int K = 3;

    cout << endl << "From K to K-1 (left to right):" << endl;
    printFromK(arr, n, K);

    addFirstAndLast(arr, n);

    removeEven(arr, n);
    cout << "From K to K+1 after removal (left to right):" << endl;
    printFromK(arr, n, K);

    return 0;
}
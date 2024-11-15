#include <iostream>
using namespace std;

void printFromK(const int arr[], int n, int K) {
    for (int i = 0; i < n; i++) {
        cout << arr[(K - i + n) % n] << " ";
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

void removeOdd(int arr[], int &n) {
    int newArr[100];
    int newSize = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            newArr[newSize++] = arr[i];
        }
    }
    for (int i = 0; i < newSize; i++) {
        arr[i] = newArr[i];
    }
    n = newSize;
}


int main() {
    int arr[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 9;
    int K = 3;

    cout << endl << "From K to K+1 (right to left):" << endl;
    printFromK(arr, n, K);

    addFirstAndLast(arr, n);

    removeOdd(arr, n);

    cout << "From K to K+1 after removal (right to left):" << endl;
    printFromK(arr, n, K);

    return 0;
}
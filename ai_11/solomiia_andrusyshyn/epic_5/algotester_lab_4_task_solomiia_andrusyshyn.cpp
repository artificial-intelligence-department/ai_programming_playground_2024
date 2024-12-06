#include <iostream>
using namespace std;

int removeDuplicates(int arr[], int n) {
    int temp[1000];
    int size = 0;

    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < size; j++) {
            if (arr[i] == temp[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            temp[size++] = arr[i];
        }
    }

    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }
    return size;
}

void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void rotateArray(int arr[], int n, int k) {
    int temp[1000];
    k = k % n; 

    for (int i = 0; i < n; i++) {
        temp[i] = arr[(i + k) % n];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

void printArray(int arr[], int n) {
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int N, K;
    cin >> N;
    if (N < 1 || N > 1000) return 1;

    cin >> K;
    if (K < 1 || K > 1000) return 1;

    int arr[1000];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (arr[i] < 0 || arr[i] > 100) return 1;
    }

    N = removeDuplicates(arr, N);

    sortArray(arr, N);

    rotateArray(arr, N, K);

    printArray(arr, N);

    return 0;
}
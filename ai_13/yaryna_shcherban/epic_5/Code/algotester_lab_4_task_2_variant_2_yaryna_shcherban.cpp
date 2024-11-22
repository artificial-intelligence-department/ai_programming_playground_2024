#include <iostream>
using namespace std;

int removeDuplicates(int arr[], int n) {
    int uniqueCount = 0;
    for (int i = 0; i < n; ++i) {
        bool isDuplicate = false;
        for (int j = 0; j < uniqueCount; ++j) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            arr[uniqueCount++] = arr[i];
        }
    }
    return uniqueCount;
}

void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void rotateArray(int arr[], int n, int k) {
    k = k % n; 
    int temp[k]; 
    for (int i = 0; i < k; ++i) {
        temp[i] = arr[i];
    }
    for (int i = 0; i < n - k; ++i) {
        arr[i] = arr[i + k];
    }
    for (int i = 0; i < k; ++i) {
        arr[n - k + i] = temp[i];
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    int arr[1000]; 
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    n = removeDuplicates(arr, n);
    sortArray(arr, n);
    rotateArray(arr, n, k);

    cout << n << endl;
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

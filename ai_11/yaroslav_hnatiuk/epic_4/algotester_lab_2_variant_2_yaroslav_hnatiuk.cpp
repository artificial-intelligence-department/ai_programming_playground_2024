#include <iostream>
using namespace std;

int main() {
    long long size;
    cin >> size;

    long long* arr = new long long[size];

    for (int i = 0; i < size; i++) cin >> arr[i];

    long long x, newSize;
    for (int i = 0; i < 3; i++) {
        cin >> x;

        newSize = 0;
        for (int j = 0; j < size; j++) {
            if (arr[j] != x) { 
                arr[newSize++] = arr[j];

            }
        }
        size = newSize;
    }

    for (int i = 0; i < size - 1; i++) {
        arr[i] += arr[i + 1];
    }   

    if (--size > 0) {
        cout << size << endl;

        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }

    } else cout << 0;

    delete[] arr;

    return 0;
}


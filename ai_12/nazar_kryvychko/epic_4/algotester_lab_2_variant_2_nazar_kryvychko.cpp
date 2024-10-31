#include <iostream>
using namespace std;

void delete_elements(int*& arr, int& size, int a, int b, int c) {
    int newSize = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] != a && arr[i] != b && arr[i] != c) {
            newSize++;
        }
    }

    int* newArr = new int[newSize];
    int newIndex = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] != a && arr[i] != b && arr[i] != c) {
            newArr[newIndex++] = arr[i];
        }
    }

    delete[] arr;
    arr = newArr;
    size = newSize;
}

int* sum_neighbors(const int* arr, int size) {
    if (size <= 1) return nullptr;

    int* sumNeibArray = new int[size - 1];
    for (int i = 1; i < size; i++) {
        sumNeibArray[i - 1] = arr[i - 1] + arr[i];
    }
    return sumNeibArray;
}

void print_array(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;

    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int a, b, c;
    cin >> a >> b >> c;

    delete_elements(arr, N, a, b, c);

    int* sumNeibArray = sum_neighbors(arr, N);

    if (sumNeibArray == nullptr) {
        cout << 0 << endl;
    } else {
        cout << N - 1 << endl;
        print_array(sumNeibArray, N - 1);
        delete[] sumNeibArray; 
    }

    delete[] arr; 
    return 0;
}

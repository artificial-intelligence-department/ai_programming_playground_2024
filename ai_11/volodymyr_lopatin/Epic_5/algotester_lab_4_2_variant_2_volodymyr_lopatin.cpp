#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    if (N < 1 || N > 1000 || K < 1 || K > 1000) return 0;
    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        int el;
        cin >> el;
        if (el < 0 || el > 100) {
            delete[] arr;
            return 0;
        }
        arr[i] = el;
    }

    int stack[1000];
    int top = -1;
    int low = 0, high = N - 1;
    stack[++top] = low;
    stack[++top] = high;

    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];

        int pivot = arr[high];
        int index = low - 1;
        for (int j = low; j < high; ++j) {
            if (arr[j] <= pivot) {
                index++;
                int temp = arr[index];
                arr[index] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[index + 1];
        arr[index + 1] = arr[high];
        arr[high] = temp;
        int pi = index + 1;

        if (pi - 1 > low) {
            stack[++top] = low;
            stack[++top] = pi - 1;
        }
        if (pi + 1 < high) {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }
    }

    int* deleted = new int[N];
    int newSize = 0;
    for (int j = 0; j < N; j++) {
        if (j == 0 || arr[j] != arr[j - 1]) {
            deleted[newSize++] = arr[j];
        }
    }

    N = newSize;
    K %= N;
    for (int i = 0; i < K; ++i) {
        int first = deleted[0];
        for (int j = 0; j < N - 1; ++j) {
            deleted[j] = deleted[j + 1];
        }
        deleted[N - 1] = first;
    }

    cout << N << endl;
    for (int s = 0; s < N; s++) {
        cout << deleted[s] << " ";
    }

    delete[] arr;
    delete[] deleted;
    return 0;
}

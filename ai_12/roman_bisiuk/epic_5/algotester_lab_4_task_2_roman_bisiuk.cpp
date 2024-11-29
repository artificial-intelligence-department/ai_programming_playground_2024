#include <iostream>
using namespace std;

void sortAsc(int arr[], int start, int end) {
    for (int i = start; i < end - 1; i++) {
        for (int j = i + 1; j < end; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void sortDesc(int arr[], int start, int end) {
    for (int i = start; i < end - 1; i++) {
        for (int j = i + 1; j < end; j++) {
            if (arr[i] < arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int removeDuplicates(int arr[], int n) {
    int newSize = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || arr[i] != arr[newSize - 1]) {
            arr[newSize++] = arr[i];
        }
    }
    return newSize;
}

int main() {
    int N;
    cin >> N;

    int* array = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }

    int* mod0 = new int[N];
    int* mod1 = new int[N];
    int* mod2 = new int[N];

    int count0 = 0, count1 = 0, count2 = 0;

    for (int i = 0; i < N; i++) {
        if (array[i] % 3 == 0) {
            mod0[count0++] = array[i];
        } else if (array[i] % 3 == 1) {
            mod1[count1++] = array[i];
        } else {
            mod2[count2++] = array[i];
        }
    }

    sortAsc(mod0, 0, count0);
    sortDesc(mod1, 0, count1);
    sortAsc(mod2, 0, count2);

    int newSize = 0;
    for (int i = 0; i < count0; i++) array[newSize++] = mod0[i];
    for (int i = 0; i < count1; i++) array[newSize++] = mod1[i];
    for (int i = 0; i < count2; i++) array[newSize++] = mod2[i];

    newSize = removeDuplicates(array, newSize);


    cout << newSize << endl;
    for (int i = 0; i < newSize; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    delete[] array;
    delete[] mod0;
    delete[] mod1;
    delete[] mod2;

    return 0;
}

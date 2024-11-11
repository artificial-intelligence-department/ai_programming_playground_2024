#include<iostream>
using namespace std;

const int MAX = 100;
int arr[MAX] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int arrSize = 10;
int k = 3;

int main() {
    cout << "Array rotated by " << k << " positions:\n";
    for (int i = k; i < arrSize + k; i++) {
        cout << arr[i % arrSize] << " ";
    }
    cout << endl;

    int first = -1;
    int last = 10;
    arrSize += 2;
    arr[arrSize - 1] = last;

    for (int i = arrSize - 3; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }
    arr[0] = first;

    int counter = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 == 0) {
            counter++;
        } else {
            arr[i - counter] = arr[i];
        }
    }
    arrSize -= counter;

    cout << "Array rotated by " << k << " positions after adding new first and last elements and deleting the even ones:\n";
    for (int i = k; i < arrSize + k; i++) {
        cout << arr[i % arrSize] << " ";
    }
    cout << endl;
}

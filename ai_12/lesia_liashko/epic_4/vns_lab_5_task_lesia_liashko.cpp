#include <iostream>
#include <algorithm> 
 using namespace std;
int main() {
    const int size = 9;
    int arr[size] = { 2, 3, 4, 5, 6, 7, 8, 9, 10}; 

    cout << "Початковий масив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    reverse(arr, arr + size);

    int new_size = size;
    if (new_size % 2 != 0) {
        new_size--;
    }

    int temp[new_size];
    int index = 0;
    for (int i = 0; i <size; i++) {
        if (size % 2 != 0 && i == size / 2) continue;
        temp[index++] = arr[i];
    }

    int result[new_size + 3];
    for (int i = 0; i < 3; i++) {
        result[i] = arr[i+10] - 2;
    }
    for (int i = 0; i < new_size; i++) {
        result[i + 3] = temp[i];
    }

    cout << "Масив після змін: ";
    for (int i = 0; i < new_size + 3; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

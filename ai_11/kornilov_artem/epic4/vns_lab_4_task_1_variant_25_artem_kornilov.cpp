#include <stdio.h>
#include <iostream>

using namespace std;

void print_l_to_r (int* arrey, int index, const int size) {
    int K = index % size;
    
    for (int i = K; i != K + 1; i--) {
            if (arrey[i] == arrey[size-1]) {
                i = size - 1;
            } 
            if (arrey[i] != 0) {
            cout << arrey[i] << " ";
            }
            
    } 
    cout << endl;
}

int main () {

    const int arrsz = 10;

    int arr[arrsz] = {0, 4, 6, 3, 8, 5, 2, 1, 7, 9};
    
    int *p = &arr[arrsz-1];
    arr[0] = *p;

    print_l_to_r(arr, 2, arrsz);

    arr[0] = 0;

    bool swapped;

    do {
        swapped = false;

        for (int i = 0; i < arrsz; i++) {
            for (int j = 1; j < arrsz - 1 - i; j++) {
                if (arr[j] < arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }
        }
    } while (swapped);

    for (int i = 1; i < arrsz - 1; i++) {
        if (arr[i] % 2 == 1) {
            arr[i] = 0;
        }

        for (int j = arrsz - 1; j > 1; j--) {
            if (arr[j] == 0) {
                arr[j] = arr[j-1];
                arr[j - 1] = 0;
            }
        }

    }

    p = &arr[arrsz-1];
    arr[0] = *p;

    print_l_to_r(arr, 2, arrsz);

    return 0;
}
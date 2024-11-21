#include <iostream>
using namespace std;

void insertionSort(int arr[], int n, bool ascending = true) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && ((ascending && arr[j] > key) || (!ascending && arr[j] < key))) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int removeDuplicates(int arr[], int n) {
    if (n == 0) return 0;
    int uniqueCount = 1; 
    for (int i = 1; i < n; ++i) {
        if (arr[i] != arr[uniqueCount - 1]) {
            arr[uniqueCount++] = arr[i];
        }
    }
    return uniqueCount;
}

int main() {
    int n;
    cin >> n;

    int arr[1000]; 
    int remainder0[1000], remainder1[1000], remainder2[1000];
    int n0 = 0, n1 = 0, n2 = 0;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; ++i) {
        if (arr[i] % 3 == 0) {
            remainder0[n0++] = arr[i];
        } else if (arr[i] % 3 == 1) {
            remainder1[n1++] = arr[i];
        } else {
            remainder2[n2++] = arr[i];
        }
    }

    insertionSort(remainder0, n0, true);  
    insertionSort(remainder2, n2, true); 
    insertionSort(remainder1, n1, false); 

    int combined[1000], total = 0;
    for (int i = 0; i < n0; ++i) combined[total++] = remainder0[i];
    for (int i = 0; i < n1; ++i) combined[total++] = remainder1[i];
    for (int i = 0; i < n2; ++i) combined[total++] = remainder2[i];

    total = removeDuplicates(combined, total);

    cout << total << endl;
    for (int i = 0; i < total; ++i) {
        cout << combined[i] << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
using namespace std;

//v3 NSTL

int checkD(int num) {
    return num % 3;
}

void createMas(int s, int start[], int ar0[], int ar1[], int ar2[]) {
    int s1 = 0, s2 = 0, s0 = 0;
    for(int i = 0; i < s; i++) {
        switch (checkD(start[i])) {
        case 0: ar0[s0] = start[i]; s0++; break;
        case 1: ar1[s1] = start[i]; s1++; break;
        case 2: ar2[s2] = start[i]; s2++; break;
        }
    }
}

void Quicksort(int *arr, int first, int last) {
    if (first >= last) return;
    int med = arr[(first + last) / 2];
    int i = first, j = last;
    
    while (i <= j) {
        while (arr[i] < med) i++;
        while (arr[j] > med) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++; j--;
        }
    }

    if (first < j) Quicksort(arr, first, j);
    if (i < last) Quicksort(arr, i, last);
}

void Quicksort(int *arr, int first, int last, char) {
    if (first >= last) return;
    int med = arr[(first + last) / 2];
    int i = first, j = last;
    
    while (i <= j) {
        while (arr[i] > med) i++;
        while (arr[j] < med) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++; j--;
        }
    }

    if (first < j) Quicksort(arr, first, j, 'c');
    if (i < last) Quicksort(arr, i, last, 'c');
}

bool checkifpresented(int *arr, int size, int key) {
    for(int i = 0; i < size; i++) {
        if(arr[i]==key) return true;
    }
    return false;
}

int delEl(int *arr, int *arrres, int size) {
    int truesize = 1;
    arrres[0] = arr[0];
    for(int i = 1; i < size; i++) {
        if(!checkifpresented(arrres, truesize, arr[i])) {
            arrres[truesize] = arr[i];
            truesize++;
        }
    }
    return truesize;
}

int main() {
    int N;
    cin >> N;
    int *arr = new int[N];
    int os1 = 0, os2 = 0, os0 = 0;
    for(int i = 0;i < N; i++) {
        cin >> arr[i];
        switch (checkD(arr[i])) {
        case 0: os0++; break;
        case 1: os1++; break;
        case 2: os2++; break;
        }
    }
    int *arr0 = new int[os0];
    int *arr1 = new int[os1];
    int *arr2 = new int[os2];
    createMas(N ,arr, arr0, arr1, arr2);
    Quicksort(arr2, 0, os2-1);
    Quicksort(arr1, 0, os1-1, 'c');
    Quicksort(arr0, 0, os0-1);
    int counter = 0;
    for(; counter < os0; counter++) {
        arr[counter] = arr0[counter];
    }
    for(; counter < os0 + os1; counter++) {
        arr[counter] = arr1[counter-os0];
    }
    for(; counter < N; counter++) {
        arr[counter] = arr2[counter-os0-os1];
    }
    int *arrres = new int[N];
    int s = delEl(arr, arrres, N);
    cout << s << "\n";
    for(int i = 0; i < s; i++)
        cout << arrres[i] << " ";
    delete[] arr0;
    delete[] arr1;
    delete[] arr2;
    delete[] arr;
    delete[] arrres;
    arr = nullptr;
    arrres = nullptr;
    arr0 = nullptr;
    arr1 = nullptr;
    arr2 = nullptr;
    return 0;
}
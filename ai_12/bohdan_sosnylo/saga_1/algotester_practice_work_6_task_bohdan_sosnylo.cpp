#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int median(int arr[], int n) {
    sort(arr, arr + n); 
    return arr[n / 2];  
}

int main() {
    int n;
    cin >> n;

    int* a = new int[n];
    int* b = new int[n];
    int* c = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    int borsch = median(a, n);
    int potato = median(b, n);
    int salad = median(c, n);

    long long mistrust = 0;
    for (int i = 0; i < n; i++) {
        mistrust += abs(borsch - a[i]) + abs(potato - b[i]) + abs(salad - c[i]);
    }

    cout << mistrust << endl;

    delete[] a;
    delete[] b;
    delete[] c;

    return 0;
}

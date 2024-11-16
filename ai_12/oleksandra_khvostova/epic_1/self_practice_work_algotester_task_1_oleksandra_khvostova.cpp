#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n; 
    int *array = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    long long sum = 0;

    for (int i = 0; i < n; i++) {
        int x = array[i];
        int y = x - 1;
        sum += y;
    }

    cout << sum << endl;

    delete[] array;
    array = nullptr;

    return 0;
}
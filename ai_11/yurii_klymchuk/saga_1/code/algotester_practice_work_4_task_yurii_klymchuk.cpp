#include <iostream>

using namespace std;

int TheCheapest(int array[], int size) {
    int min = 999;
    for (int i = 0; i < size; i++) {
        if(array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

int main () {
    int n, m;
    cin >> n >> m;

    int n_array[n];
    for (int i = 0; i < n; i++) {
        cin >> n_array[i];
    }

    int m_array[m];
    for (int i = 0; i < m; i++) {
        cin >> m_array[i];
    }

    int price = TheCheapest(n_array, n) + TheCheapest(m_array, m);

    cout << price;

    return 0;
}
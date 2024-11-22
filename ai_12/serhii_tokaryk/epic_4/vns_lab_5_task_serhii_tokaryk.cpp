#include <iostream>
#include <cstdlib>
#include <ctime>

#define N 10

using namespace std;

int count_biggers(int** a) {
    int max_on_diag = a[0][0]; 
    int count = 0;

    for (size_t i = 1; i < N; i++) {
        if (a[i][i] > max_on_diag) {
            max_on_diag = a[i][i];
        }
    }

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            if (a[i][j] > max_on_diag) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    srand(static_cast<unsigned>(time(0))); 

    int** arr = new int*[N];
    for (size_t i = 0; i < N; i++) {
        arr[i] = new int[N];
    }

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            arr[i][j] = rand() % 100; 
        }
    }

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            if (i == j) {
                cout << "*" << arr[i][j] << "*\t";
            } else {
                cout << arr[i][j] << "\t";
            }
        }
        cout << endl;
    }

    cout << "Кількість елементів, більших за максимальний елемент головної діагоналі: " 
         << count_biggers(arr) << endl;

    for (size_t i = 0; i < N; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}

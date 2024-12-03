#include <iostream>

using namespace std;

//використав цілочисельні змінні, ввід/вивід, двовимірний масив,
//цикл for i while, рекурсивну функцію, перевантаження функції,
//умовні оператори

void InsertRow(char** array, int row, int colIndex, int M) {
    if (colIndex == M) {
        return;
    }
    cin >> array[row][colIndex];
    InsertRow(array, row, colIndex + 1, M);
}

void Programme(char** array, int N, int M){
    for (int j = 0; j < M; j++) {
    for (int i = N - 2; i >= 0; i--) {
        if (array[i][j] == 'S') {
            int k = i;
            while (k + 1 < N && array[k + 1][j] == 'O') {
                array[k][j] = 'O';
                array[k + 1][j] = 'S';
                k++;
            }
        }
    }
}
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << array[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < N; i++) {
        delete[] array[i];
    }
    delete[] array;
    return;
}

void Programme(char** array, int rowIndex, int N, int M) {
    if (rowIndex == N){ 
        Programme(array, N, M);
        return;
    }
    InsertRow(array, rowIndex, 0, M);
    Programme(array, rowIndex + 1, N, M);
}

int main() {
    int N, M;
    cin >> N >> M;

    char** array = new char*[N];
    for (int i = 0; i < N; ++i) {
        array[i] = new char[M];
    }
    
    Programme(array, 0, N, M);
    return 0;
}
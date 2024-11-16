#include <iostream>
#include <ctime>

using namespace std;

//prototype of fucntion
void exchange_rows(int arr[5][5]);    
void print_matrix(int arr[5][5]);
void exchange_3rd_row(int arr[5][5]);
void filled_matrix(int arr[5][5]);

//for swapping
void exchange_rows(int arr[5][5], int row1, int row2){
    for(int col = 0; col < 5; col++){
        int temp = arr[row1][col];
        arr[row1][col] = arr[row2][col];
        arr[row2][col] = temp;
    }
}

//for swapping 3rd column
void exchange_by_3rd_row(int arr[5][5]){
    for (int i = 0; i < 4; i++){
        for (int j = i + 1; j < 5; j++){
            if (arr [i][2] > arr[j][2]){
                exchange_rows(arr, i, j);
            }
        }
    }
}

//for filled matrix with random numbers from 0 to 10
void filled_matrix(int arr[5][5]){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++) {
            arr[i][j] = rand() % 10;
        }
    }
}

void print_matrix(int arr[5][5]){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main (){

    srand(static_cast<unsigned> (time(nullptr)));

    int arr [5][5];

    cout << "Generated matrix 5x5 is: " << endl;
    filled_matrix(arr);
    print_matrix(arr);
    
    cout << "Swapped matrix is: " << endl;
    exchange_rows(arr, 0, 2);
    print_matrix(arr);
    
    cout << "Swapped by 3rd column: " << endl;
    exchange_by_3rd_row(arr);
    print_matrix(arr);

    return 0;
}

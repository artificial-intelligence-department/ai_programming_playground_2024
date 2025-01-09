#include <iostream>
using namespace std;

const int N = 5;

void MatrixWork(int arr[][N]){
    int min = 1000, max = 0;
    int minels_columns[N], maxels_columns[N];
    int minels_rows[N], maxels_rows[N];

    for(int j = 0; j < N; j++){
        min = 1000, max = 0;
        for(int i = 0; i < N; i++){
            if (arr[i][j] > max) max = arr[i][j];
            if (arr[i][j] < min) min = arr[i][j];
        }
        minels_columns[j] = min;
        maxels_columns[j] = max;
    }

    min = 1000, max = 0;
    for(int i = 0; i < N; i++){
        min = 1000, max = 0;
        for(int j = 0; j < N; j++){
            if (arr[i][j] > max) max = arr[i][j];
            if (arr[i][j] < min) min = arr[i][j];
        }
        minels_rows[i] = min;
        maxels_rows[i] = max;
    }

    cout << "Smallest element in each column: \n";
    for(int i = 0; i < N; i++){
        cout << minels_columns[i] << " ";
    }
    cout << endl;

    cout << "Biggest element in each column: \n";
    for(int i = 0; i < N; i++){
        cout << maxels_columns[i] << " ";
    }
    cout << endl;

    cout << "Smallest element in each row: \n";
    for(int i = 0; i < N; i++){
        cout << minels_rows[i] << " ";
    }
    cout << endl;

    cout << "Biggest element in each row: \n";
    for(int i = 0; i < N; i++){
        cout << maxels_rows[i] << " ";
    }
    cout << endl << endl;
}

void ArrLowerRightUpDown(int arr [][N]){
    cout << "Matrix from lower right corner by columns: \n";
    for (int j = N - 1; j >= 0; j--) {
        for (int i = N - 1; i >= 0; i--) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void ArrLowerRightLeftRight( int arr[N][N]){
    cout << "Matrix from lower right corner from left to right, up to down: \n";
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= 0; j--) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void ArrRotated90DegLeft(int arr[N][N]){
    cout << "Array rotated 90 degrees to the left: \n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[j][N - i - 1] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool SymmCheck(int arr[N][N]){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] != arr[j][i]) return false;
        }
    }
    return true;
}

void ArrTrans(int matrix[][6]){
    int result[6][N];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = matrix[j][i];
        }
    }

    cout << "Matrix after trans: \n";
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < N; j++) {
           cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arr[N][N] = {
        {9, 8, 7, 6, 5},
        {4, 3, 4, 9, 4},
        {2, 5, 1, 2, 3},
        {5, 7, 8, 7, 2},
        {8, 4, 9, 3, 1}
    };

    MatrixWork(arr);
    ArrLowerRightUpDown(arr);
    ArrLowerRightLeftRight(arr);
    ArrRotated90DegLeft(arr);

    bool symm = SymmCheck(arr);
    if(symm == true){
        cout << "Matrix is symmetrical\n";
    } else cout << "Matrix is not symmetrical\n";

    int arr2[N][6]{
        {4, 8, 2, 1, 2, 6},
        {5, 2, 4, 2, 5, 4},
        {3, 5, 1, 6, 7, 0},
        {7, 7, 1, 8, 2, 3},
        {5, 9, 0, 5, 4, 1}
    };

    cout << "Matrix before trans: \n";
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < N; j++) {
           cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    ArrTrans(arr2);

    return 0;
}
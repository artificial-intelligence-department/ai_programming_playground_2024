#include<bits/stdc++.h>

using namespace std;

void printMatrix(int matrix[5][5]){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printArr(int arr[5]){
    for(int i = 0; i < 5; i++){
        cout << setw(3) << arr[i] << " ";
    }
    cout << endl << endl;
}

void printRBC(int matrix[5][5]) {
    for(int i = 4; i >=0; i--) {
        for(int j = 4; j >=0; j--) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
}

void printRBR(int matrix[5][5]) {
    for(int i = 4; i >=0; i--) {
        for(int j = 4; j >=0; j--) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matrix[5][5];
    int arr[5];
    srand(static_cast<unsigned>(time(0)));
    for (size_t i = 0; i < 5; i++) {
        for (size_t j = 0; j < 5; j++) {
            matrix[i][j] = 1 + rand() % 21;
        }
    }
    cout << "Початкова матриця: " << endl;
    printMatrix(matrix);


    for(int i = 0; i < 5; i++) {
        arr[i] = matrix[0][i];
        for(int j = 0;  j < 5; j++) {
            if(matrix[j][i] > arr[i])
                arr[i] = matrix[j][i]; 
        }
    }
    cout << "Найбільші елементи в стовпцях: " << endl;
    printArr(arr);
    for(int i = 0; i < 5; i++) {
        arr[i] = matrix[0][i];
        for(int j = 0;  j < 5; j++) {
            if(matrix[j][i] < arr[i])
                arr[i] = matrix[j][i]; 
        }
    }
    cout << "Найменші елементи в стовпцях: " << endl;
    printArr(arr);

    for(int i = 0; i < 5; i++) {
        arr[i] = matrix[i][0];
        for(int j = 0;  j < 5; j++) {
            if(matrix[i][j] > arr[i])
                arr[i] = matrix[i][j]; 
        }
    }
    cout << "Найбільші елементи в рядках: " << endl;
    printArr(arr);

    for(int i = 0; i < 5; i++) {
        arr[i] = matrix[i][0];
        for(int j = 0;  j < 5; j++) {
            if(matrix[i][j] < arr[i])
                arr[i] = matrix[i][j]; 
        }
    }
    cout << "Найменші елементи в рядках: " << endl;
    printArr(arr);


    // Транспонуємо матрицю
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Змінюємо порядок стовпців
    for (int i = 0; i < 5; i++) {
        for (int j = 0, k = 4; j < k; j++, k--) {
            swap(matrix[i][j], matrix[i][k]);
        }
    }

    cout << "Матриця після обертання на 90 градусів: " << endl;
    printMatrix(matrix);

    bool isSymetric = true;
    for(int i = 0; i < 5; i++){
        for(int j = i + 1; j < 5; j++){
            if(matrix[i][j] != matrix[j][i]){
                isSymetric = false;
            }
        }
    }
    if(isSymetric){
        cout << "Матриця симетрична" << endl;
    }
    else{
        cout << "Матриця не симетрична" << endl;
    }
    int temp;
    for(int i = 0; i < 5; i++){
        for(int j = i; j < 5; j++){
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    printMatrix(matrix);
    


    //Матриця 5х6
    int matrix_1[5][6];
    int matrix_2[6][5];
    srand(static_cast<unsigned>(time(0)));
    for (size_t i = 0; i < 5; i++) {
        for (size_t j = 0; j < 6; j++) {
            matrix_1[i][j] = 1 + rand() % 21;
        }
    }
    //print matrix
    cout << "Matrix 5x6" << endl;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 6; j++){
            cout << setw(3) << matrix_1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    //transponing
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 6; j++){
            matrix_2[j][i] = matrix_1[i][j];
        }
    }
    //print transponed matrix
    cout << "transponed matrix 5x6" << endl;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 5; j++){
            cout << setw(3) << matrix_2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;

}
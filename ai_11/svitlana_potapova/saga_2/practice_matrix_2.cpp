#include <iostream>
using namespace std;

void printMatrix(int matrix[3][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
} 

void addMatrices(int matrix1[3][3], int matrix2[3][3]){
    cout << "Результат додавання:" << endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << matrix1[i][j] + matrix2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void multiplyMatrices(int matrix1[3][3], int matrix2[3][3]){
    int res[3][3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            res[i][j] = 0;
            for(int k=0; k<3; k++){
                res[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    cout << "Результат множення:" << endl;
    printMatrix(res);
}

void tr(int matrix[3][3]){
    int res[3][3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            res[j][i] = matrix[i][j];
        }
    }
    printMatrix(res);
}

int det(int A[3][3]){
    return A[0][0]*A[1][1]*A[2][2] + A[2][0]*A[0][1]*A[1][2] + A[1][0]*A[2][1]*A[0][2] - 
    (A[0][2]*A[1][1]*A[2][0]+A[2][2]*A[1][0]*A[0][1]+A[0][0]*A[2][1]*A[1][2]);
}

int findMax(int matrix[3][3]){
    int Max = matrix[0][0];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(matrix[i][j]>Max){
                Max = matrix[i][j];
            }
        }
    }

    return Max;
}

int findMin(int matrix[3][3]){
    int Min = matrix[0][0];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(matrix[i][j]<Min){
                Min = matrix[i][j];
            }
        }
    }

    return Min;
}

int main(){
    int matrix1[3][3] = {{1,4,5},
                         {2,2,1},
                         {6,5,3}};

    int matrix2[3][3] = {{0,1,1},
                         {4,3,2},
                         {7,5,1}};

    cout << "Перша матриця:" << endl;
    printMatrix(matrix1);

    cout << "Друга матриця:" << endl;
    printMatrix(matrix2);

    addMatrices(matrix1, matrix2);
    multiplyMatrices(matrix1, matrix2);

    cout << "Транспонування першої матриці:" << endl;
    tr(matrix1);

    cout << "Транспонування другої матриці:" << endl;
    tr(matrix2);

    cout << "Найбільший елемент першої матриці: " << findMax(matrix1) << ", найменший: " << findMin(matrix1) << endl;
    cout << "Найбільший елемент другої матриці: " << findMax(matrix2) << ", найменший: " << findMin(matrix2) << endl;
    
    cout << endl << "Визначний першої матриці: " << det(matrix1) << endl;
    cout << "Визначний другої матриці: " << det(matrix2) << endl;


    return 0;

                         
}
#include <iostream>

using namespace std;

void ruinMatrix (const int matrixSize, int* array, int matrix[][3], int a_1, int a_2, int a_3, int b_1, int b_2, int b_3) {
    if (a_1 >= 3 || a_1 < 0 || b_1 >= 3 || b_1 < 0 || a_2 >= 3 || a_2 < 0 || b_2 >= 3 || b_2 < 0 || a_3 >= 3 || a_3 < 0 || b_3 >= 3 || b_3 < 0) {
            cout << "wrong input!\n";
    }
   
    for (int j = 0; j < matrixSize; j++) {
            array[0+j] = matrix[a_1][j];
    }

    for (int j = matrixSize; j < matrixSize*2; j++) {
            array[0+j] = matrix[a_2][j - matrixSize];
    }

    for (int j = matrixSize * 2; j < matrixSize * 3; j++) {
    array[j] = matrix[a_3][j - matrixSize * 2];
    }

    for (int j = matrixSize*3; j < matrixSize*4; j++) {
            array[0+j] = matrix[j - matrixSize*3][b_1];
    }
    
    for (int j = matrixSize*4; j < matrixSize*5; j++) {
            array[0+j] = matrix[j - matrixSize*4][b_2];
    }

    for (int j = matrixSize*5; j < matrixSize*6; j++) {
            array[0+j] = matrix[j - matrixSize*5][b_3];
    }


    return;
}

void restoreMatrix (const int matrixSize, int* array, int matrix[][3]) {

    int** tempMatrix1 = new int*[matrixSize];
    int** tempMatrix2 = new int*[matrixSize];
    for (int i = 0; i < matrixSize; i++) {
        tempMatrix1[i] = new int[matrixSize];
        tempMatrix2[i] = new int[matrixSize];
    }
    
    for (int i = 0; i < matrixSize; i++) {
        for (int j = matrixSize*i; j < matrixSize + matrixSize*i; j++) {
            tempMatrix1[i][j - matrixSize*i] = array[j];
        }   
    }

    for (int i = 0; i < matrixSize; i++) {
        for (int j = matrixSize*i; j < matrixSize + matrixSize*i; j++) {
            tempMatrix2[i][j - matrixSize*i] = array[j + matrixSize*3];
        }   
    }

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
           for (int i1 = 0; i1 < matrixSize; i1++) {
            for (int j1 = 0; j1 < matrixSize; j1++) {
                if (tempMatrix1[i][j] == tempMatrix2[i1][j1]) {
                    matrix[j1][j] = tempMatrix1[i][j];
                }
            }
           }
        }
    }

    for (int i = 0; i < matrixSize; i++) {
        delete[] tempMatrix1[i];
        delete[] tempMatrix2[i];
    }
    delete[] tempMatrix1;
    delete[] tempMatrix2;

    return;
}



void print (const int size, int* array) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    
    cout << endl << endl;
    
    return;
}

void print (const int size, int matrix[][3]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
    
        cout << endl;
    }
    
    cout << endl;

    return;
}



int main () {
    const int matrixSize = 3;
    const int arrSz = matrixSize*matrixSize*2;
    int originalMatrix[matrixSize][matrixSize] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    print (matrixSize, originalMatrix);

    int ruinedArray[arrSz];

    ruinMatrix (matrixSize, ruinedArray, originalMatrix, 2, 1, 0, 2, 0, 1);

    print (arrSz, ruinedArray);

    int restoredMatrix[matrixSize][matrixSize];

    restoreMatrix (matrixSize, ruinedArray, restoredMatrix);

    print (matrixSize, restoredMatrix);
    
    
    return 0;
}
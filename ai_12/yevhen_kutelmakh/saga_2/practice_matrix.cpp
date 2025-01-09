#include <iostream>
#include <algorithm>
using namespace std;

void initialize(int arr[5][5]) {
    int count = 0;
    for(int i = 0; i < 5; i++) {
        for(int j = 0;  j < 5; j++)
            arr[i][j] = count++;
    }
}

void initialize(double arr[5][5]) {
    double count = 0.5;
    for(int i = 0; i < 5; i++) {
        for(int j = 0;  j < 5; j++)
            arr[i][j] = count++;
    }
}

void initialize(int **arr, int rows, int cols) {
    int count = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0;  j < cols; j++)
            arr[i][j] = count++;
    }
}

int* findBiggestInCol(int arr[5][5]) {
    int *ar = new int[5];
    for(int i = 0; i < 5; i++) {
        ar[i] = arr[0][i];
        for(int j = 0;  j < 5; j++) {
            if(arr[j][i] > ar[i])
                ar[i] = arr[j][i]; 
        }
    }
    return ar;
}

int* findSmallestInCol(int arr[5][5]) {
    static int ar[5]; //Так ми продовжуємо тривалість життя даного масиву, змінюємо її з автоматичної на файлову
    for(int i = 0; i < 5; i++) {
        ar[i] = arr[0][i];
        for(int j = 0;  j < 5; j++) {
            if(arr[j][i] < ar[i])
                ar[i] = arr[j][i]; 
        }
    }
    return ar;
}

int* findBiggestInRow(int arr[5][5]) {
    int *ar = new int[5];
    for(int i = 0; i < 5; i++) {
        ar[i] = arr[i][0];
        for(int j = 0;  j < 5; j++) {
            if(arr[i][j] > ar[i])
                ar[i] = arr[i][j]; 
        }
    }
    return ar;
}

int* findSmallestInRow(int arr[5][5]) {
    int *ar = new int[5];
    for(int i = 0; i < 5; i++) {
        ar[i] = arr[i][0];
        for(int j = 0;  j < 5; j++) {
            if(arr[i][j] < ar[i])
                ar[i] = arr[i][j]; 
        }
    }
    return ar;
}

void printM(int arr[5][5]) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0;  j < 5; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
}

void printM(double arr[5][5]) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0;  j < 5; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
}

void printM(int **arr, int rows = 5, int cols = 5) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0;  j < cols; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
}

void printA(int *arr, int size) {
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void printRBC(int arr[5][5]) {
    for(int i = 4; i >=0; i--) {
        for(int j = 4; j >=0; j--) {
            cout << arr[j][i] << " ";
        }
        cout << "\n";
    }
}

void printRBR(int arr[5][5]) {
    for(int i = 4; i >=0; i--) {
        for(int j = 4; j >=0; j--) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void transponuvannya(int arr[5][5]) {
    for(int i = 0; i < 5; i++) {
        for(int j = i; j < 5; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }
}

int** obernennya90(int arr[5][5]) {
    int **array = new int*[5];
    for(int i = 0; i < 5; i++)
        array[i] = new int[5];
    int col = 0;
    for(int i = 4; i >= 0; i--) {
        for(int j = 0; j < 5; j++) {
            array[j][col] = arr[i][j]; 
        }
        col++;
    }
    return array;
}

bool isSymetric(int arr[5][5]) {
    for(int i = 0; i < 5; i++) {
        for(int j = i; j < 5; j++) {
            if(arr[i][j]!=arr[j][i]) return false;
        }
    }
    return true;
}

int** transponuvannya(int **arr, int rows, int cols) {
    int **mat = new int*[cols];
    for(int i = 0; i < cols; i++) {
        mat[i] = new int[rows];
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            mat[j][i] = arr[i][j];
        }
    }
    return mat;
}

//Передбачається що матриці будуть однакового розміру
int** addition(int **mat1, int **mat2, int rows, int cols) {
    int **arr = new int*[rows];
    for(int i = 0; i < rows; i++)
        arr[i] = new int[cols];
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++)
            arr[i][j] = mat1[i][j] + mat2[i][j];
    }
    return arr;
}

int multHelp(int **mat1, int **mat2, int rows, int row, int col) {
    int res = 0;
    for(int i = 0; i < rows; i++) {
        res += mat1[row][i]*mat2[i][col];
    }
    return res;
}

//Передбачається що множаться квадратні матриці
int** mult(int **mat1, int **mat2, int rows) {
    int **arr = new int*[rows];
    for(int i = 0; i < rows; i++)
        arr[i] = new int[rows];

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < rows; j++)
            arr[i][j] = multHelp(mat1, mat2, rows, i, j);
    }

    return arr;
}

double determinant(double arr[5][5], int index = 0) {
    static int swaps = 0;
    if(index==4) {
        double det = 1;
        for(int i = 0; i < 5; i++)
            det *= arr[i][i];
        return (swaps%2==0)?det:(det*-1);
    }

    if(arr[index][index] == 0) {
        for(int row = index+1; row<5; row++) {
            if (arr[row][index] != 0) {
                for (int i = 0; i < 5; i++) 
                    swap(arr[index][i], arr[row][i]);
                swaps++;
                break;
            }
        }
        if(arr[index][index] == 0) return 0;
    }

    for(int row = index+1; row<5; row++) {
        double k = arr[row][index]/arr[index][index];
        for(int i = 0; i < 5; i++) {
            arr[row][i] -= k*arr[index][i];
        }
    }
    return determinant(arr, ++index);
}  

int main() {
    int matrix[5][5];
    initialize(matrix);
    cout << "Out matrix lookls like:\n";
    printM(matrix);

    int *armax = new int[5]; 
    armax = findBiggestInCol(matrix);
    cout << "List of biggest elements in columns:\n";
    printA(armax, 5);
    int *armin = new int[5]; 
    armin = findSmallestInCol(matrix);
    cout << "List of smallest elements in columns:\n";
    printA(armin, 5);

    int *armaxR = new int[5]; 
    armaxR = findBiggestInRow(matrix);
    cout << "List of biggest elements in rows:\n";
    printA(armaxR, 5);
    int *arminR = new int[5]; 
    arminR = findSmallestInRow(matrix);
    cout << "List of smallest elements in rows:\n";
    printA(arminR, 5);

    cout << "Printing our matrix from bottom right corner by columns(from bottom to top):\n";
    printRBC(matrix);
    cout << "Printing our matrix from bottom right corner by rows(from right to left):\n";
    printRBR(matrix);

    transponuvannya(matrix);
    cout << "Matrix after transponuvannya looks like:\n";
    printM(matrix);
    transponuvannya(matrix);

    cout << "Matrix after we turned it by 90:\n";
    int **matrix2 = obernennya90(matrix);
    printM(matrix2);

    if(isSymetric(matrix)) cout << "Matrix is symetric\n";
    else cout << "Matrix is not symetric\n";

    int **matrix3 = new int*[5];
    for(int i = 0; i < 5; i++) {
        matrix3[i] = new int[6];
    }
    initialize(matrix3, 5, 6);
    cout << "New matrix 5*6 looks likes:\n"; 
    printM(matrix3, 5, 6);
    cout << "New matrix after transponuvannya looks likes:\n"; 
    int** matrix4 = transponuvannya(matrix3, 5, 6);
    printM(matrix4, 6, 5);

    int** addMat = addition(matrix2, matrix2, 5, 5);
    cout << "Addition for some matrixes will result in:\n";
    printM(addMat);

    int** multMat = mult(matrix2, matrix2, 5);
    cout << "Multiplying for some matrixes will result in:\n";
    printM(multMat);

    double matrix1[5][5] = {
        1, 2, 3, 2, 1,
        1, 2, 1, 1, 1, 
        21, 7, 1, 2, 3, 
        1, 3, 4, 0, 2,
        1, 5, 6, 9, 2
    };
    cout << "Determinant of matrix equals = " << determinant(matrix1) << "\n";
    printM(matrix1);
    return 0;
}
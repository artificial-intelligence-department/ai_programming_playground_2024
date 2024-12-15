#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int** fillMatrixWithRandomNumbers(int** matrix, int n, int m) {
    srand(time(0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }
    
    return matrix;
}

int* findMaxInColumns(int** matrix, int n, int m) {
    int* maxnums = new int[m];
    int maxn;
    for (int j = 0; j < m; ++j) {
        maxn = matrix[0][j];
        for (int i = 0; i < n; ++i) {
            if (maxn < matrix[i][j]) {
                maxn = matrix[i][j];
            }
        }
        maxnums[j] = maxn;
    }

    return maxnums;
}


int* findMinInColumns(int** matrix, int n, int m) {
    int* minnums = new int[m];
    int minn;
    for (int j = 0; j < m; ++j) {
        minn = matrix[0][j];
        for (int i = 0; i < n; ++i) {
            if (minn > matrix[i][j]) {
                minn = matrix[i][j];
            }
        }
        minnums[j] = minn;
    }

    return minnums;
}

int* findMaxInRows(int** matrix, int n, int m) {
    int* maxnums = new int[m];
    int maxn;
    for (int i = 0; i < n; ++i) {
        maxn = matrix[i][0];
        for (int j = 0; j < n; ++j) {
            if (maxn < matrix[i][j]) {
                maxn = matrix[i][j];
            }
        }
        maxnums[i] = maxn;
    }

    return maxnums;
}

int* findMinInRows(int** matrix, int n, int m) {
    int* minnums = new int[m];
    int minn;
    for (int i = 0; i < n; ++i) {
        minn = matrix[i][0];
        for (int j = 0; j < n; ++j) {
            if (minn > matrix[i][j]) {
                minn = matrix[i][j];
            }
        }
        minnums[i] = minn;
    }

    return minnums;
}

void printMatrix(int** matrix, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void printArray(int* array, int n) {
    for (int i = 0; i < n; ++i) {
        cout << setw(5) << array[i]; 
    }
}

void printArrayDif1(int** matrix, int n, int m) {
    int i = n-1;
    for (int j = m-1; j >= 0; --j) {
        if (i==-1) {
            for (i = 0; i < n; ++i) {
                cout << setw(5) << matrix[i][j];
            }
            
        }
        else {
            for (i = n-1; i >= 0; --i) {
                cout << setw(5) << matrix[i][j];
            }
        }
    }
}

void printArrayDif2(int** matrix, int n, int m) {
    int j = m-1;
    for (int i = n-1; i >= 0; --i) {
        if (j==-1) {
            for (j = 0; j < m; ++j) {
                cout << setw(5) << matrix[i][j];
            }
            
        }
        else {
            for (j = m-1; j >= 0; --j) {
                cout << setw(5) << matrix[i][j];
            }
        }
    }
}

void printArraySpiral(int** matrix, int n, int m) {
    int i = 0, j = 0, k = 0, q = 0, min;
    (n < m)? min = n : min = m;

    while (k != min) {
        for (i = k; i < n-q; i++) cout << setw(5) << matrix[i][j];
        k++;
        i--;
        for (j = k; j < m-q; j++) cout << setw(5) << matrix[i][j];
        j--;
        for (i = n-k-1; i >= 0+q; i--) cout << setw(5) << matrix[i][j];
        i++;
        for (j = m-k-1; j > 0+q; j--) cout << setw(5) << matrix[i][j];
        q++;
        j++;
    } 
}

bool isSquare(int n, int m) {
    return n == m;
}

void SwapNumbers(int** matrix, int n, int m) {
    int temp;
    if (isSquare(n, m)) {
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < m; ++j) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    } 
}

void Rotateby90(int*** matrix, int n, int m) {
    int** matrixrot = new int*[m];
    for (int i = 0; i < m; ++i) {
        matrixrot[i] = new int[n];
    }
    for (int j = m-1; j >= 0; --j) {
        for (int i = 0; i < n; ++i) {
            matrixrot[m - j - 1][i] = (*matrix)[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        delete[] (*matrix)[i];
    }
    delete[] *matrix;

    *matrix = matrixrot;
}

void transpose(int*** matrix, int n, int m) {
    int** matrixt = new int*[m];
    for (int i = 0; i < m; ++i) {
        matrixt[i] = new int[n];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrixt[i][j] = (*matrix)[j][i];
        }
    }

    for (int i = 0; i < n; ++i) {
        delete[] (*matrix)[i];
    }
    delete[] *matrix;

    *matrix = matrixt;
}

bool isSymmetrical(int** matrix, int n, int m) {
    if (isSquare(n, m)) {
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < m; ++j) {
                if (matrix[i][j] != matrix[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    return false;
}

void makeSymmetrical(int** matrix, int n, int m) {
    if (isSquare(n, m)) {
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < m; ++j) {
                matrix[j][i] = matrix[i][j];
            }
        }
    } 
}

int main() {
    int n = 5, m = 5; 
    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[m];
    }

    matrix = fillMatrixWithRandomNumbers(matrix, n, m);
    printMatrix(matrix, n, m);    

    cout << endl << "Task 1 - Find max numbers from each column" << endl;
    int* arr1 = findMaxInColumns(matrix, n, m);
    printArray(arr1, n);

    cout << endl << "Task 2 - Find min numbers from each column" << endl;
    int* arr2 = findMinInColumns(matrix, n, m);
    printArray(arr2, n);

    cout << endl << "Task 3 - Find max numbers from each row" << endl;
    int* arr3 = findMaxInRows(matrix, n, m);
    printArray(arr3, n);

    cout << endl << "Task 4 - Find min numbers from each row" << endl;
    int* arr4 = findMinInRows(matrix, n, m);
    printArray(arr4, n);

    cout << endl << "Task 5 - Print the numbers from the lower right corner as a snake in columns" << endl;
    printArrayDif1(matrix, n, m);

    cout << endl << "Task 6 - Print the numbers from the lower right corner as a snake in rows" << endl;
    printArrayDif2(matrix, n, m);

    cout << endl << "Task 7 - Print the numbers in spiral" << endl;
    printArraySpiral(matrix, n, m);

    cout << endl << "Task 8 - Swap numbers relative to the diagonal" << endl;
    SwapNumbers(matrix, n, m);
    printMatrix(matrix, n, m);

    cout << endl << "Task 9 - Rotate by 90 degrees" << endl;
    Rotateby90(&matrix, n, m);
    int temp = m;
    m = n;
    n = temp;
    printMatrix(matrix, n, m);

    cout << endl << "Task 10 - Is symmetrical?" << endl;
    // makeSymmetrical(matrix, n, m);
    if (isSymmetrical(matrix, n, m)) {
        cout << "Yes!";
    }
    else {
        cout << "No!";
    }


    cout << endl << "Task 11 - Transpose matrix" << endl;
    transpose(&matrix, n, m);
    printMatrix(matrix, n, m);
    
}
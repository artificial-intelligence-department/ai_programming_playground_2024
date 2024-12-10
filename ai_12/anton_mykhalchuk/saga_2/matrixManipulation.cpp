#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int** createMatrix(int m, int n) {
    int** matrix = new int*[m];

    for (int i = 0; i < m; ++i) {
        matrix[i] = new int[n];
    }
    return matrix;
}

void fillRandom(int** matrix, int m, int n) {
    srand(time(0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void fillZeroes(int** matrix, int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = 0;
        }
    }
}

void printMatrix(int** matrix, int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void deleteMatrix(int** matrix, int m) {
    for (int i = 0; i < m; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int** sumMatrices(int** A, int** B, int m, int n) {
    int** C = createMatrix(m, n);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}

int ** multiplyMatrices(int** A, int** B, int m, int n, int k, int q) {
    int** C = createMatrix(m, q);
    fillZeroes(C, m, q);
    int Sum;
    if (n==k) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < q; ++j) {
                for (int s = 0; s < n; ++s) {
                    C[i][j] += A[i][s] * B[s][j];
                }
            }
        }

        return C;
    }

    return C;
}

void transposeMatrix(int*** matrix, int n, int m) {
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

// Існує кращий алгоритм (приведення матриці до трикутного вигляду), але вирішив використати формулу алгебраїчного доповнення для того щоб використати рекурсію
int getDeterminant(int** matrix, int order) {
    int det = 0;
    if (order == 1) {
        return matrix[0][0];
    }
    else if (order == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    else if (order == 3) {
        for (int i = 0; i < order; ++i) {
            int positive = 1, negative = 1;
            for (int j = 0; j < order; ++j) {
                positive *= matrix[j][(i + j) % order]; 
                negative *= matrix[j][(order - 1) - ((i + j) % order)];
            }
            det += positive - negative;
        }
        
        return det;
    }

    int** minor = createMatrix(order-1, order-1);
    for (int k = 0; k < order; ++k) {
        int it = 0, jt = 0;
        for (int i = 1; i < order; ++i) {
            jt = 0;
             for (int j = 0; j < k; ++j) {
                minor[it][jt] = matrix[i][j];
                ++jt;
            }
            for (int j = k + 1; j < order; ++j) {
                minor[it][jt] = matrix[i][j];
                ++jt;
            }
            ++it;
        }
        if (k % 2) {
            det += matrix[0][k] * (-1) * getDeterminant(minor, order - 1);
        }
        else {
            det += matrix[0][k] * getDeterminant(minor, order - 1);
        }
    }

    return det;

}

int** findValueIndex(int** matrix, int m, int n, int value) {
    int fullOrder = m*n;
    int** indeces = createMatrix(fullOrder, 2);
    fillZeroes(indeces, fullOrder, 2);
    int it = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (value == matrix[i][j]) {
                indeces[it][0] = i;
                indeces[it][1] = j;
                ++it;
            }
        }
    }
    

    indeces[it][0] = -1;
    indeces[it][1] = -1;

    return indeces;
      
}

int main() {
    int am = 4, an = 4, bm = 4, bn = 4;
    int** A = createMatrix(am, an);
    int** B = createMatrix(bm, bn);
    
    cout << "First Matrix - A(" << am << '*' << an << ')' << endl;
    fillRandom(A, am, an);
    printMatrix(A, am, an);
    cout << endl << "Second Matrix - B(" << bm << '*' << bn << ')' << endl;
    fillRandom(B, bm, bn);
    printMatrix(B, bm, bn);

    cout << endl << "Task 1  C = A + B" << endl;
    int** C = sumMatrices(A, B, am, an);
    printMatrix(C, am, an);

    cout << endl << "Task 2  D = A * B" << endl;
    int** D = multiplyMatrices(A, B, am, an, bm, bn);
    printMatrix(D, am, bn);
    deleteMatrix(A, am);
    deleteMatrix(B, bm);

    cout << endl << "Task 3  Transpose matrix D" << endl;
    transposeMatrix(&D, am, bn);
    printMatrix(D, am, bn);

    cout << endl << "Task 4  Get Determinant" << endl;
    int em = 3, en = 3;
    int** E = createMatrix(em, en);
    fillRandom(E, em, en);
    printMatrix(E, em, en);

    cout << endl << getDeterminant(E, em) << endl << endl;

    int fm = 2, fn = 2;
    int** F = createMatrix(fm, fn);
    fillRandom(F, fm, fn);
    printMatrix(F, fm, fn);

    cout << endl << getDeterminant(F, fm) << endl << endl;

    int gm = 5, gn = 5;
    int** G = createMatrix(gm, gn);
    fillRandom(G, gm, gn);
    printMatrix(G, gm, gn);

    cout << endl << getDeterminant(G, gm) << endl << endl;

    cout << endl << "Task 5  Find special value index" << endl;
    G[3][2] = 4;
    int** FV = findValueIndex(G, gm, gn, 4);

    for (int i = 0; FV[i][0] != -1; ++i) {
        cout << "Index: (" << FV[i][0] << ", " << FV[i][1] << ")\n";
    }

    return 0;
}
// зайняло 1.5 год
#include <iostream>
#include <cmath>
using namespace std;

int multiply(int i, int j, int mat1[3][3], int mat2[3][3]) {
    int res = 0;
    for(int k = 0; k < 3; k++) {
        res += mat1[i][k] * mat2[k][j];
    }

    return res;
}

int determinant(int matrix[3][3], int n) {
    if(n == 1) {
        return matrix[0][0];
    } else if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    int nr = 0;
    int nc = 0;

    int det = 0;

    for(int i = 0; i < n; i++) {
        int rowminor = i;
        int newmatrix[3][3];
        for(int r = 0; r < n; r++) {
            if(r != i) {
                for(int c = 0; c < n; c++) {
                    if(c != 0) {
                        newmatrix[nr][nc] = matrix[r][c];
                        nc++;
                    }
                }
                nc = 0;
                nr++;
            }
        }
        nr=0;
        det += matrix[i][0] * pow(-1,i + 2) * determinant(newmatrix, n - 1);
    }

    return det;
}

int main() {

    //різне виведення 
    int matrix[6][5] = {{1,2,3,4,5}, {6,6,6,6,6}, {0,1,0,1,0}, {1,4,9,16,25}, {1,2,3,3,4}, {9,8,7,6,5}};
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 6; j++) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }

    //робота з матрицями
    cout << "First matrix" << endl;
    int mat1[3][3] = {{1,1,2}, {2,3,0}, {2,1,0}};
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << mat1[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << "Second matrix" << endl;
    int mat2[3][3] = {{5,7,4}, {1,0,0}, {9,1,11}};
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << mat2[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << "Sum" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << mat1[i][j] + mat2[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Multiply" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << multiply(i,j,mat1,mat2) << " ";
        }
        cout << endl;
    }
    cout << determinant(mat1,3);


    return 0;

}
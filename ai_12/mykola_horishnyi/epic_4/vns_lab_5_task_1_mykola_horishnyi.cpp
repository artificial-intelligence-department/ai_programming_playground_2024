#include <iostream>
using namespace std;


void sumMatrices(int mat1[3][3], int mat2[3][3], int result[3][3])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j) 
        {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}


void transposeMatrix(int mat[3][3], int result[3][3])
{
    for (int i = 0; i < 3; ++i) 
    {

        for (int j = 0; j < 3; ++j)
        {
            result[j][i] = mat[i][j];
        }
    }
}


void printMatrix(int mat[3][3]) 
{
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int mat1[3][3], mat2[3][3];
    int sumResult[3][3]; 
    int transposeResult[3][3];


    cout << " Enter elemements for first matrix 3x3:" << endl;
    for (int i = 0; i < 3; ++i) 
    {
        cout << "Row : " ;
        for (int j = 0; j < 3; ++j)
        {
            cin >> mat1[i][j];
        }
    }

    cout << " Enter elemements for second matrix 3x3:" << endl;
    for (int i = 0; i < 3; ++i) 
    {
        cout << "Row  : " ;
        for (int j = 0; j < 3; ++j)
        {
            cin >> mat2[i][j];
        }
    }


    sumMatrices(mat1, mat2, sumResult);
    cout << "Result for sum of two matrix:" << endl;
    printMatrix(sumResult);

 
    transposeMatrix(sumResult, transposeResult);
    cout << "Transposed matrix :" << endl;
    printMatrix(transposeResult);







    return 0;
}



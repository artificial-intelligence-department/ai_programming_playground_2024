#include <iostream>

using namespace std;

void printArr(int *arr, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void printArr(int **arr, int n, int k)
{
    cout << "---Martix---\n";
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < k; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "------------\n";
}

int *findMaxInRows(int **matrix, int n, int k)
{
    int *result = new int[n];
    int max;
    for (size_t i = 0; i < n; i++)
    {
        max = matrix[i][0];
        for (size_t j = 1; j < k; j++)
        {
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
            }
        }
        result[i] = max;
    }
    return result;
}

int *findMinInRows(int **matrix, int n, int k)
{
    int *result = new int[n];
    int min;
    for (size_t i = 0; i < n; i++)
    {
        min = matrix[i][0];
        for (size_t j = 1; j < k; j++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
            }
        }
        result[i] = min;
    }
    return result;
}

int *findMaxInColumns(int **matrix, int n, int k)
{
    int *result = new int[k];
    int max;
    for (size_t i = 0; i < k; i++)
    {
        max = matrix[0][i];
        for (size_t j = 1; j < n; j++)
        {
            if (matrix[j][i] > max)
            {
                max = matrix[j][i];
            }
        }
        result[i] = max;
    }
    return result;
}

int *findMinInColumns(int **matrix, int n, int k)
{
    int *result = new int[k];
    int min;
    for (size_t i = 0; i < k; i++)
    {
        min = matrix[0][i];
        for (size_t j = 1; j < n; j++)
        {
            if (matrix[j][i] < min)
            {
                min = matrix[j][i];
            }
        }
        result[i] = min;
    }
    return result;
}

void printMatrixFromRightToLeft(int **matrix, int n, int k)
{
    cout << "---Martix---\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = k - 1; j >= 0; j--)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "------------\n";
}

void printMatrixFromBottomToTop(int **matrix, int n, int k)
{
    cout << "---Martix---\n";
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < k; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "------------\n";
}

void reverseMatrixByMainDiagonale(int **matrix, int n, int k)
{
    if (n != k)
    {
        cout << "Its not a square matrix, cant reverse it by diagonale";
        return;
    }
    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int ** rotatedMatrixBy90Dergees(int **matrix, int n, int k)
{
    int **result = new int *[k];
    for (size_t i = 0; i < k; i++)
    {
        result[i] = new int[n];
    }

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < k; j++)
        {
            result[j][n-1-i] = matrix[i][j];
        }
    }

    return result;
}

bool checkMatrixForSymmetricity(int **matrix, int n, int k)
{
    if (n != k)
    {
        return false;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    const int n = 5, k = 5;
    int **matrix = new int *[n];
    for (size_t i = 0; i < n; i++)
    {
        matrix[i] = new int[k];
        for (size_t j = 0; j < k; j++)
        {
            matrix[i][j] = rand() % 100 + 1;
        }
    }

    printArr(matrix, n, k);

    printArr(findMaxInRows(matrix, n, k), n);
    printArr(findMinInRows(matrix, n, k), n);
    printArr(findMaxInColumns(matrix, n, k), k);
    printArr(findMinInColumns(matrix, n, k), k);

    printMatrixFromBottomToTop(matrix, n, k);
    printMatrixFromRightToLeft(matrix, n, k);

    reverseMatrixByMainDiagonale(matrix, n, k);
    printArr(matrix, n, k);

    printArr(rotatedMatrixBy90Dergees(matrix, n, k), n, k);

    cout << (checkMatrixForSymmetricity(matrix, n, k) ? "Matrix is symmetrical" : "Matrix is not symmetrical") << endl;

    return 0;
}
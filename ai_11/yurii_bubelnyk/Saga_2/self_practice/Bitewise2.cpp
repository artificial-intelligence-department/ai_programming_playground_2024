#include <iostream>
#include <ctime>

using namespace std;
const int M = 5;

struct Array
{
    int *mR;
    int *mC;
};
Array find_max_rows_cols(int **matrix, int rows, int cols);
Array find_min_rows_cols(int **matrix, int rows, int cols);
void Delete(Array result);
int **initMatrix(int rows, int cols);
int *findMax(int **matrix, int rows, int cols);
int *findMin(int **matrix, int rows, int cols);
void Show(int **matrix, int rows, int cols);
void Show(int *matrix, int rows);
void Delete(int **matrix, int rows);

int main()
{
    srand(time(NULL));    
    int **array = initMatrix(M, M);
    Show(array, M, M);
    cout << endl;
    cout << "\nMax elements: " << endl;
    Show(findMax(array, M, M), M);
    cout << "\nMin elements: " << endl;
    Show(findMin(array, M, M), M);

    Array length_max = find_max_rows_cols(array, M, M);
    cout << "\n\nMax elements in rows: " << endl;
    Show(length_max.mR, M);
    cout << "\n\nMax elements in cols: " << endl;
    Show(length_max.mC, M);

    Array length_min = find_min_rows_cols(array, M, M);
    cout << "\n\nMix elements in rows: " << endl;
    Show(length_min.mR, M);
    cout << "\n\nMix elements in cols: " << endl;
    Show(length_min.mC, M);

    Delete(length_max);
    Delete(length_min);
    Delete(array, M);
    return 0;
}
Array find_max_rows_cols(int **matrix, int rows, int cols)
{
    Array result;
    result.mR = new int[rows];
    result.mC = new int[cols];

    for (int i = 0; i < rows; i++)
    {
        int max_r = matrix[i][0];
        for (int j = 0; j < cols; j++)
        {
            if (max_r < matrix[i][j])
            {
                max_r = matrix[i][j];
            }
            result.mR[i] = max_r;
        }  
    }
    
    for (int i = 0; i < cols; i++)
    {
        int max_c = matrix[0][i];
        for (int j = 0; j < rows; j++)
        {
            if (max_c < matrix[j][i])
            {
                max_c = matrix[j][i];
            }
            result.mC[i] = max_c;
        }  
    }
    return result;
}
Array find_min_rows_cols(int **matrix, int rows, int cols)
{
    Array result;
    result.mR = new int[rows];
    result.mC = new int[cols];

    for (int i = 0; i < rows; i++)
    {
        int min_r = matrix[i][0];
        for (int j = 0; j < cols; j++)
        {
            if (min_r > matrix[i][j])
            {
                min_r = matrix[i][j];
            }
            result.mR[i] = min_r;
        }  
    }
    
    for (int i = 0; i < cols; i++)
    {
        int min_c = matrix[0][i];
        for (int j = 0; j < rows; j++)
        {
            if (min_c > matrix[j][i])
            {
                min_c = matrix[j][i];
            }
            result.mC[i] = min_c;
        }  
    }
    return result;
}
void Delete(Array result)
{
    delete[] result.mR; 
    delete[] result.mC; 
}
int **initMatrix(int rows, int cols)
{
    int **matrix = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = rand() % 50 + 1;
        }       
    }
    return matrix;
}
int *findMax(int **matrix, int rows, int cols)
{
    int *maxElement_rows = new int[rows];
    for (int i = 0; i < rows; i++)
    {
        int max = matrix[i][0];
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
            }
        }
        maxElement_rows[i] = max;
    }
    return maxElement_rows;
}
int *findMin(int **matrix, int rows, int cols)
{
    int *minElement = new int[rows];
    for (int i = 0; i < rows; i++)
    {
        int min = matrix[i][0];
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
            }
        }
        minElement[i] = min;
    }
    return minElement;
}
void Show(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void Show(int *matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        cout << matrix[i] << " ";
    }
}
void Delete(int **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
} 
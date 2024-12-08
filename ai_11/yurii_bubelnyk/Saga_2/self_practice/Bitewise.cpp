#include <iostream>
#include <ctime>

using namespace std;
const int M = 5;

int **initMatrix(int rows, int cols);
int *findMax(int **matrix, int rows, int cols);
int *findMin(int **matrix, int rows, int cols);
void Show(int **matrix, int rows, int cols);
void Show(int *matrix, int rows);
void Delete(int **matrix, int rows);

int main()
{
    //srand(time(NULL));    
    int **array = initMatrix(M, M);
    Show(array, M, M);
    cout << endl;
    cout << "\nMax elements: " << endl;
    Show(findMax(array, M, M), M);
    cout << "\nMin elements: " << endl;
    Show(findMin(array, M, M), M);

    Delete(array, M);
    return 0;
}

int **initMatrix(int rows, int cols)
{
    int **matrix = new int*[rows];
    for (int i = 0; i < cols; i++)
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
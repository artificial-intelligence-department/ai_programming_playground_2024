#include <iostream>
#include <ctime>

using namespace std;
const int M = 5;
struct Array
{
    int rows;
    int cols;
    int **rotated;   
};

Array rotate_90(int **matrix, int rows, int cols);
Array transpose(int **matrix, int rows, int cols);
void Show(int **matrix, int rows, int cols);
int **initMatrix(int rows, int cols);
void Delete(int **matrix, int rows);

int main()
{
    srand(time(NULL));
    int **array = initMatrix(M, M);

    cout << "Original Matrix:" << endl;
    Show(array, M, M);

    Array rotated = rotate_90(array, M, M);

    cout << "\nRotated Matrix (90 degrees):" << endl;
    Show(rotated.rotated, rotated.rows, rotated.cols);

    Array transposed = transpose(array, M, M);
    cout << "\nTransposed Matrix:" << endl;
    Show(transposed.rotated, transposed.rows, transposed.cols);
    
    // Free memory
    Delete(array, M);
    Delete(rotated.rotated, rotated.rows);
    Delete(transposed.rotated, transposed.rows);
    return 0;
}
Array rotate_90(int **matrix, int rows, int cols)
{
    Array matrix1;
    matrix1.rows = cols;
    matrix1.cols = rows;

    matrix1.rotated = new int*[matrix1.rows];
    for (int i = 0; i < matrix1.rows; i++)
    {
        matrix1.rotated[i] = new int[matrix1.cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix1.rotated[j][rows - 1 - i] = matrix[i][j];
        }
    }
    return matrix1;
}
Array transpose(int **matrix, int rows, int cols)
{
    Array matrix1;
    matrix1.rows = cols;
    matrix1.cols = rows;

    matrix1.rotated = new int*[matrix1.rows];
    for (int i = 0; i < matrix1.rows; i++)
    {
        matrix1.rotated[i] = new int[matrix1.cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix1.rotated[j][i] = matrix[i][j];
        }
    }
    return matrix1;
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
void Delete(int **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
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
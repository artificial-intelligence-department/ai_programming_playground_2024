#include <iostream>
#include <cstdlib>

int** delete_row(int** matrix, int& rows, int cols, int target);
int** create_dynamic_matrix(int rows, int cols);
void delete_dynamic_matrix(int** matrix, int rows, int cols);
void print_dynamic_matrix(int** matrix, int rows, int cols);


int main()
{
    int rows, cols;
    std::cout << "Enter the number of rows and cols respectively:" << std::endl;
    std::cin >> rows >> cols;
    int** matrix = create_dynamic_matrix(rows, cols);
    std::cout << "Before deliting:" << std::endl;
    print_dynamic_matrix(matrix, rows, cols);


    std::cout << "Enter how many rows you want to delete. Enter the first one to delete and the last one:" << std::endl;
    int first, last;
    std::cin >> first >> last;
    for(int i = first - 1; i < last; i++)
        {
            matrix = delete_row(matrix, rows, cols, i);  
            i--;
            last--;
        }

    std::cout << "After deliting: " << std::endl;
    print_dynamic_matrix(matrix, rows, cols);
    delete_dynamic_matrix(matrix, rows, cols);

    return 0;  
    
}


int** delete_row(int** matrix, int& rows, int cols, int target)
{
    int new_rows = rows - 1;
    int** new_matrix = new int*[new_rows];
    int new_index = 0;

    for(int i = 0; i < rows; i++)
    {
        if (i == target)
                continue;
        new_matrix[new_index] = new int [cols];

        for(int j = 0; j < cols; j++)
            new_matrix[new_index][j] = matrix[i][j];
        new_index++;
    }

    for(int i = 0; i < rows; i++)
        delete[] matrix[i];

    delete[] matrix;
    rows = new_rows;
    return new_matrix;

}

int** create_dynamic_matrix(int rows, int cols)
{
    int** matrix = new int* [rows];
    for(int i = 0; i < rows; i++)
        matrix[i] = new int[cols] {};

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            matrix[i][j] = rand() % 21;
    return matrix;
}

void delete_dynamic_matrix(int** matrix, int rows, int cols)
{
    for(int i = 0; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;
}

void print_dynamic_matrix(int** matrix, int rows, int cols)
{
    for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
                std::cout << matrix[i][j] << " ";

            std::cout << std::endl;
        }
}
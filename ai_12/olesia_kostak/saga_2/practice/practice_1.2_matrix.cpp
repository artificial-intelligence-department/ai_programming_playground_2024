#include <iostream>
#include <limits>

const int SIZE_R = 3, SIZE_C = 3;

int find_det(int matrix[][SIZE_C], int SIZE);
int main()
{
    ////////////////
    std::cout << "Matrix initialization: " << std::endl;
    int matrix_1[SIZE_R][SIZE_C];
    for (int i = 0; i < SIZE_R; i++)
        for (int j = 0; j < SIZE_C; j++)
            std::cin >> matrix_1[i][j];
    
    int matrix_2[SIZE_R][SIZE_C];
    for (int i = 0; i < SIZE_R; i++)
        for (int j = 0; j < SIZE_C; j++)
            std::cin >> matrix_2[i][j];

    std::cout << "Matrix_1: " << std::endl;
    for (int i = 0; i < SIZE_R; i++)
    {
        for (int j = 0; j < SIZE_C; j++)
            std::cout << matrix_1[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << "Matrix_2: " << std::endl;
    for (int i = 0; i < SIZE_R; i++)
    {
        for (int j = 0; j < SIZE_C; j++)
            std::cout << matrix_2[i][j] << " ";
        std::cout << std::endl;
    }
    //Matrix adding///////////////
    int matrix_1_added_2[SIZE_R][SIZE_C];
    for (int i = 0; i < SIZE_R; i++)
        for (int j = 0; j < SIZE_C; j++)
            matrix_1_added_2[i][j] = matrix_1[i][j] + matrix_2[i][j];
    
    //Matrix multiclication//////
    int matrix_1_multiple_2[SIZE_R][SIZE_C];
    for (int i = 0; i < SIZE_R; i++)
    {
        for (int j = 0; j < SIZE_C; j++)
        {
            matrix_1_multiple_2[i][j] = 0;
            for (int k = 0; k < SIZE_C; k++)
                matrix_1_multiple_2[i][j] += matrix_1[i][k] * matrix_2[k][j];
        }
    }
    std::cout << std::endl << "Matrix multiplication: " << std::endl;
    for (int i = 0; i < SIZE_R; i++)
    {
        for (int j = 0; j < SIZE_C; j++)
            std::cout << matrix_1_multiple_2[i][j] << " ";
        std::cout << std::endl;
    }

    //Finding max value in matrix/////
    int max_val = std::numeric_limits<int>::min();
    for (int i = 0; i < SIZE_R; i++)
        for (int j = 0; j < SIZE_C; j++)
            if (matrix_1[i][j] > max_val)
                max_val = matrix_1[i][j];
    std::cout << "Max value in matrix 1: " << max_val << std::endl;

    //Finding min value in matrix/////
    int min_val = std::numeric_limits<int>::max();
    for (int i = 0; i < SIZE_R; i++)
        for (int j = 0; j < SIZE_C; j++)
            if (matrix_1[i][j] < min_val)
                min_val = matrix_1[i][j];
    std::cout << "Min value in matrix 1: " << min_val << std::endl;

    //Finding determinant
    int det = find_det(matrix_1, SIZE_C);
    std::cout << "Determinant: " << det << std::endl;


    return 0;
}


int find_det(int matrix[][SIZE_C], int SIZE)
{
    int det = 0;
    if (SIZE == 1)
        return matrix[0][0];
    if (SIZE == 2)
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);

    for (int i = 0; i < SIZE; i++)
    {   
        int minors[SIZE_C][SIZE_C] = {0};
        int minor_r = 0;
        for (int j = 1; j < SIZE_C; j++)
        {
            int minor_c = 0; 
            for (int k = 0; k < SIZE_C; k++)
            {
                if (i != k)
                {
                    minors[minor_r][minor_c] = matrix[j][k];
                    minor_c++;
                }
            }
            minor_r++;
        }
        if ( i % 2 == 0)
            det += matrix[0][i] * find_det(minors, SIZE - 1);
        else
            det -= matrix[0][i] * find_det(minors, SIZE - 1);
        }
    return det;
}
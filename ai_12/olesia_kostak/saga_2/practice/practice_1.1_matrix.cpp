#include <iostream>

const int SIZE = 5;
template<typename T>
void print_matrix (T matrix);

int main()
{
    int matrix[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            std::cin >> matrix[i][j];
    
    std::cout << "Current matrix: " << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }


    /////////////////////////////////////////////////////////////////
    int max_cols[SIZE], min_cols[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        int min_value = 999999999, max_value = -999999999;
        for (int j = 0; j < SIZE; j++)
        {
            if (matrix[j][i] < min_value)
                min_value = matrix[j][i];
            if (matrix[j][i] > max_value)
                max_value = matrix[j][i];            
        }
        max_cols[i] = max_value;
        min_cols[i] = min_value;
    }
    std::cout << "Max cols: " << std::endl;
    for (int i = 0; i < SIZE; i++)
        std::cout << max_cols[i] << " ";
    std::cout << std::endl;
    std::cout << "Min cols: " << std::endl;
    for (int i = 0; i < SIZE; i++)
        std::cout << min_cols[i] << " ";
    std::cout << std::endl;
    
    //////////////////////////////////////////////////////////////
    int max_rows[SIZE], min_rows[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        int min_value = 999999999, max_value = -999999999;
        for (int j = 0; j < SIZE; j++)
        {
            if (matrix[i][j] < min_value)
                min_value = matrix[i][j];
            if (matrix[i][j] > max_value)
                max_value = matrix[i][j];            
        }
        max_rows[i] = max_value;
        min_rows[i] = min_value;
    }
    std::cout << "Max rows: " << std::endl;
    for (int i = 0; i < SIZE; i++)
        std::cout << max_rows[i] << " ";
    std::cout << std::endl;
    std::cout << "Min rows: " << std::endl;
    for (int i = 0; i < SIZE; i++)
        std::cout << min_rows[i] << " ";
    std::cout << std::endl;

    ////////////////////////////////////////////////////////////
    bool flag = true;
    std::cout << "Snake matrix 1: " << std::endl;
    for (int i = SIZE - 1; i >= 0; i--)
    {
        if (flag)
        {
            for (int j = SIZE - 1; j >= 0; j--)
                std::cout << matrix[j][i] << " ";
            flag = false;
        }
        else
        {
            for (int j = 0; j < SIZE; j++)
                std::cout << matrix[j][i] << " ";
            flag = true;
        }
        std::cout << std::endl;
    }

    ////////////////////////////////////////////////////////////
    flag = true;
    std::cout << "Snake matrix 2: " << std::endl;
    for (int i = SIZE - 1; i >= 0; i--)
    {
        if (flag)
        {
            for (int j = SIZE - 1; j >= 0; j--)
                std::cout << matrix[i][j] << " ";
            flag = false;
        }
        else
        {
            for (int j = 0; j < SIZE; j++)
                std::cout << matrix[i][j] << " ";
            flag = true;
        }
        std::cout << std::endl;
    }

    // ////////////////////////////////////////////////////////////
    std::cout << "Turn around main diagonal: " << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = i; j < SIZE; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp; 
        }
    }
    print_matrix(matrix);
    

    //////////////////////////////////////
    int matrix_2[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix_2[i][j] = matrix[i][j];

    std::cout << "Turning the matrix: " << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            matrix_2[i][j] = matrix[j][SIZE - i - 1];
        }
    }
    print_matrix(matrix_2);

    //////////
    std::cout << "Enter values of matrix to check if it's symmetric: " << std::endl;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            std::cin >> matrix[i][j];
    bool is_symmetric = true;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (matrix[i][j] != matrix[j][i])
                is_symmetric = false;
        }
    }
    std::cout << "Is matrix symmetric: "; 
    if (is_symmetric)
        std::cout << "Yes";
    else std::cout << "No";
    std::cout << std::endl;

    ///////////////////////////////////////////
    int matrix_3[5][6];
    std::cout << "Enter the values of matrix 5 x 6: " << std::endl;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 6; j++)
            std::cin >> matrix_3[i][j];

    std::cout << "Before: " << std::endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
            std::cout << matrix_3[i][j] << " ";
        std::cout << std::endl;
    }

    std::cout << "After: " << std::endl;
    int matrix_3_T[6][5];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix_3_T[i][j] = matrix_3[j][i];
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
            std::cout << matrix_3_T[i][j] << " ";
        std::cout << std::endl;
    }

    return 0;
}

template<typename T>
void print_matrix (T matrix)
{
    std::cout << "The matrix: " << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            std::cout<< *(*(matrix+i) + j)<< " ";
        std::cout << std::endl;
    }
}
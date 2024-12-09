#include <iostream>
#include <limits>

const int SIZE = 3;

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

    /////////////////
    std::cout << "Enter an element you want to find: " << std::endl;
    int el_to_find;
    bool flag = false;
    std::cin >> el_to_find;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (matrix[i][j] == el_to_find)
                flag = true;
    std::cout << "Is an element in the matrix: ";
    if (flag)
        std::cout << "YES";
    else std::cout << "NO";
    std::cout << std::endl;

    //Finding max value in matrix/////
    int max_val = std::numeric_limits<int>::min();
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (matrix[i][j] > max_val)
                max_val = matrix[i][j];
    std::cout << "Max value in matrix 1: " << max_val << std::endl;

    //Finding min value in matrix/////
    int min_val = std::numeric_limits<int>::max();
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (matrix[i][j] < min_val)
                min_val = matrix[i][j];
    std::cout << "Min value in matrix 1: " << min_val << std::endl;


    //Finding the sum of all elements
    int sum = 0;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            sum += matrix[i][j];
    std::cout << "Sum of all elements: " << sum << std::endl;

    //Average value
    std::cout << "Average value: " << (sum / (SIZE*SIZE)) << std::endl;

    ///Diagonal values
    int diag_values[SIZE];
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (i == j)
                diag_values[i] = matrix[i][j];
    std::cout << "Diagonal values: " << std::endl;
    for (int i = 0; i < SIZE; i++)
        std::cout << diag_values[i] << " ";
    std::cout << std::endl;

    ///Finding the row with max sum
    int max_row_sum = 0;
    int max_row_sum_index = -1;
    for (int i = 0; i < SIZE; i++)
    {
        int row_sum = 0;
        for (int j = 0; j < SIZE; j++)
            row_sum += matrix[i][j];
        if (row_sum > max_row_sum)
        {
            max_row_sum = row_sum;
            max_row_sum_index = i;
        }
    }
    std::cout << "Index of row with max sum: " << max_row_sum_index << std::endl;

    ///Finding an element which is met in the matrix the most times
    int element_index_i = -1;
    int element_index_j = -1;
    int max_times = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            int counter = 0;
            for (int k = 0; k < SIZE; k++)
                for (int m = 0; m < SIZE; m++)
                    if (matrix[i][j] == matrix[k][m])
                        counter++;
            if (counter > max_times)
            {
                max_times = counter;
                element_index_i = i;
                element_index_j = j;
            }

        }
    }

    ////Finding even elements:
    int even_elements[SIZE*SIZE];
    int index = 0;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (matrix[i][j] % 2 == 0)
                even_elements[index++] = matrix[i][j];

                
    return 0;
}
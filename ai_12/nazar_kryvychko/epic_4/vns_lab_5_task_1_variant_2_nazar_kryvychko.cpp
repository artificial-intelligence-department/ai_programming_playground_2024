#include<iostream>


// 2. Написати функцію для обміну рядків двовимірного масиву з її допомогою
// відсортувати масив по елементах третього стовпця.


void swap_row(int matrix[4][4], int row1, int row2)
{
    if(row1 > 4 || row1 < 1 || row2 > 4 || row2 < 1)  return;


    row1--; row2--;   
    int temp[4];
    for (int j = 0; j < 4; j++) {
        temp[j] = matrix[row1][j];
    }

    for (int j = 0; j < 4; j++) {
        matrix[row1][j] = matrix[row2][j];
        matrix[row2][j] = temp[j];
    }
}


void sort_matrix_by_3nd_column(int matrix[4][4])
{
    //Considering bubble sort for 3nd column element
    for (size_t i = 0; i < 4-1; i++)
    {
        if(matrix[i][2] > matrix[i+1][2])
        {
            swap_row(matrix, i+1,i+2);
            i--;
        }
    }
    swap_row(matrix,1,2);
}

void print_matrix(int matrix[][4],const size_t& rows, const size_t& cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main(void)
{
    int matrix[4][4] = { {1,6,3,9}, {9,0,5,4} , {4,5,1,8}, {1,5,8,2} };
    print_matrix(matrix,4,4);
    sort_matrix_by_3nd_column(matrix);
    print_matrix(matrix,4,4);
    
    return 0;
}
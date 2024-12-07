#include<iostream>
#include<time.h>
using namespace std;
const int rows = 5, columns = 5;

void print_matrix(int* matrix)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout<<*(matrix + i*columns + j)<<"\t";
        }
        cout<<endl;
    }
}

void print_arr(int* arr)
{
    for (int i = 0; i < 5; i++)
    {
        cout<<*(arr + i)<<" ";
    }
    cout<<endl;
}

//Виведення матриці звероху вниз по стовпцям, полчинаючи з правого стовпця
void print_matrix_from_top_to_bottom(int* matrix)
{
    cout<<"Matrix from top to bottom:"<<endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 4; j >= 0; j--)
        {
            cout<<*(matrix + i*5 + j)<<"\t";
        } 
        cout<<endl;
    }
    
    cout<<endl;
}

//Виведення матриці знизу вверх по стовпцям, полчинаючи з правого стовпця
void print_matrix_from_bottom_to_top(int* matrix)
{
    cout<<"Matrix from bottom to top:"<<endl;
    for (int i = 4; i >= 0; i--)
    {
        for (int j = 4; j >= 0; j--)
        {
            cout<<*(matrix + i*5 + j)<<"\t";
        } 
        cout<<endl;
    }
    
    cout<<endl;
}

//Виведення матриці зліва на право по рядкам, полчинаючи з нижнього рядка
void print_matrix_from_left_to_right(int* matrix)
{
    cout<<"Matrix from left to right:"<<endl;
    for (int i = 4; i >= 0; i--)
    {
        for (int j = 0; j < 5; j++)
        {
            cout<<*(matrix + i*5 + j)<<"\t";
        }
        cout<<endl;
    }
}

//Виведення матриці справа на ліво по рядкам, полчинаючи з нижнього рядка
void print_matrix_from_right_to_left(int* matrix)
{
    cout<<"Matrix from right to left:"<<endl;
    for (int i = 4; i >= 0; i--)
    {
        for (int j = 4; j >= 0; j--)
        {
            cout<<*(matrix + i*5 + j)<<"\t";
        }
        cout<<endl;
    }
}


//Обчислення визначника 
void get_minor (int matrix[rows][columns], int minor[rows][columns], int n, int row, int column)
{
    int r = 0, c = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == row) continue;

        c = 0;
        for (int j = 0; j < n; j++)
        {
            if (j == column) continue;
            else
            {
                minor[r][c] = matrix[i][j];
                c++;
            }
        }
        r++; 
    }
}

int determinant (int matrix[rows][columns], int n)
{
    if (n == 1)
    {
        return matrix[0][0];
    }

    int det = 0;
    int sign = 1;
    int minor[rows][columns]{};

    for (int i = 0; i < n; i++)
    {
        get_minor(matrix, minor, n, 0, i);
        det += sign * matrix[0][i] * determinant(minor, n - 1);
        sign = -sign;
    }
    
    return det;
}


int main()
{
    srand(time(0));
    
    int matrix[rows][columns]{};

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] = rand() % 10 + 1;
        }
    }

    cout<<"Matrix: "<<endl;
    print_matrix(&matrix[0][0]);


    //Максимальні та мінімальні елементи в колонках
    int max_elements_in_columns[5], min_elements_in_columns[5];

    for (int i = 0; i < 5; i++)
    {
        int max_element = matrix[0][i], min_element = matrix[0][i];
        for (int j = 1; j < 5; j++)
        {
            if (max_element < matrix[j][i]) max_element = matrix[j][i];

            if (min_element > matrix[j][i]) min_element = matrix[j][i];
        }

        max_elements_in_columns[i] = max_element;
        min_elements_in_columns[i] = min_element;        
    }

    cout<<"Max elements in columns: ";
    print_arr(max_elements_in_columns);
    
    cout<<"Min elements in columns: ";
    print_arr(min_elements_in_columns);
    
    //Максимальні та мінімальні елементи в рядках
    int max_elements_in_rows[5], min_elements_in_rows[5];

    for (int i = 0; i < 5; i++)
    {
        int max_element = matrix[i][0], min_element = matrix[i][0];
        for (int j = 1; j < 5; j++)
        {
            if (max_element < matrix[i][j]) max_element = matrix[i][j];

            if (min_element > matrix[i][j]) min_element = matrix[i][j];
        }

        max_elements_in_rows[i] = max_element;
        min_elements_in_rows[i] = min_element;        
    }

    cout<<"Max elements in rows: ";
    print_arr(max_elements_in_rows);
    
    cout<<"Min elements in rows: ";
    print_arr(min_elements_in_rows);

    //Повернута матриця на 90 градусів за годинниковою стрілкою
    cout<<"Rotated matrix: "<<endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 4; j >= 0; j--)
        {
            cout<<matrix[j][i]<<"\t";
        }
        cout<<endl;
    }
    

    //ініціалізація двох матриць для суми та множення
    int matrix_1[5][5]{}, matrix_2[5][5]{};

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix_1[i][j] = rand() % 10 + 1;
            matrix_2[i][j] = rand() % 10 + 1;

        }
    }
    cout<<"Matrix_1: "<<endl;
    print_matrix(&matrix_1[0][0]);
    cout<<"Matrix_2: "<<endl;
    print_matrix(&matrix_2[0][0]);

    //Сума матриць
    int sum_matrix[5][5]{};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            sum_matrix[i][j] += matrix_1[i][j] + matrix_2[i][j];
        } 
    }

    cout<<"Sum_matrix: "<<endl;
    print_matrix(&sum_matrix[0][0]);

    //Множення матриць
    int mult_matrix[5][5]{};

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                mult_matrix[i][j] += matrix_1[i][k] * matrix_2[k][j];
            }
            
        }
    }
    

    cout<<"Multiplicated matrix: "<<endl;
    print_matrix(&mult_matrix[0][0]);

    int n = 5;

    int num_of_max_row = 0, max_sum_in_row = 0;

    for (int i = 0; i < 5; i++)
    {
        int sum_in_row = 0;
        for (int j = 0; j < 5; j++)
        {
            sum_in_row += matrix[i][j];
        }

        if (sum_in_row > max_sum_in_row)
        {
            max_sum_in_row = sum_in_row;
            num_of_max_row = i + 1;
        }
    }

    cout<<"Number of row with max sum of elements: "<<num_of_max_row<<endl;
    

    

    return 0;
}
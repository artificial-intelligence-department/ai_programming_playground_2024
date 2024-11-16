#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef unsigned int uint;

//заповнення матриці випадковими числами
int rand_matrix (uint* arr, uint rows, uint columns)
{
    srand(static_cast<unsigned int>(std::time(0)));
    for (int i = 0; i < rows; i++)
    {
        for (int  j = 0; j < columns; j++)
        {
            *(arr + i * columns + j) = 1 + rand() % 100;
        }
        
    }
    
    return 0;
}
//заповнення матриці випадковими числами

// функція для виведення матриці
int print_matrix (uint* arr, uint rows, uint columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int  j = 0; j < columns; j++)
        {
            cout<<*(arr + i * columns + j)<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
//функція для виведення матриці

//знаходження максимального елемента в заданому рядку
int max_element_in_row(uint* arr, uint num_row, uint columns)
{
    uint max = *(arr + (num_row - 1) * columns);
    for (int i = 0; i < columns; i++)
    {
        if (max < *(arr + (num_row - 1) * columns + i)) 
        {
            max = *(arr + (num_row - 1) * columns + i);
        }
    }
    
    return max;
}
//знаходження максимального елемента в заданому рядку

//циклічний зсув рядка
int new_row(uint* arr, uint* new_arr, uint num_row, uint columns, uint max)
{
    max %= columns; 

    uint i = 0, j = columns - max;
    while (i < columns)
    {
        if (j < columns)
        {
            *(new_arr + (num_row - 1) * columns + i) = *(arr + (num_row - 1) * columns + j);
            j++;
            i++;
        }
        else j = 0;

    }

    return 0;
}
//циклічний зсув рядка

int main()
{
    uint arr[100][100];
    uint rows, columns;
    cout<<"Введіть кількість рядків: ";
    cin>>rows;

    cout<<"Введіть кількість стовпців: ";
    cin>>columns;
    cout<<endl;

    rand_matrix(&arr[0][0], rows, columns);

    cout<<"Початкова матриця: \n";
    print_matrix(&arr[0][0], rows, columns);

    uint num_row;
    cout<<"Введіть номер рядка в якому хочете знайти максимум: ";
    cin>>num_row;
    printf("Максимальний елемент в %d рядку: %d\n", num_row, max_element_in_row(&arr[0][0], num_row, columns));
    
    uint new_arr[rows][columns]{}, max;

    for (uint i = 1; i <= rows; i++)
    {
        max = max_element_in_row(&arr[0][0], i, columns);
        new_row(&arr[0][0], &new_arr[0][0], i, columns, max);
    }
    
    cout<<"Змінена матриця: \n";
    print_matrix(&new_arr[0][0], rows, columns);


    return 0;
}
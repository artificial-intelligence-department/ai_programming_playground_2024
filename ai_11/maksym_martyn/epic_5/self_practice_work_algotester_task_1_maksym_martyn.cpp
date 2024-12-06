//створити функцію яка визначає добуток елементів заданого рядка
#include <iostream>
using namespace std;
int** create_matrix(int rows, int columns)
{
  int**matrix=nullptr;
  matrix = new int*[rows];
  for (size_t i = 0; i < rows; i++)
  {
    matrix[i]=new int[columns];
  }
  return matrix;
}


void delete_matrix(int**matrix, int rows , int columns)
{
  for (size_t i = 0; i < rows; i++)
  {
    delete[] matrix[i];
  }
  delete[] matrix;
}


void input_matrix(int** matrix,int rows, int columns)
{
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < columns; j++)
    {
      cout<<'['<<i+1<<"]["<<j+1<<"] = ";
      cin>>matrix[i][j];
    }
  }
}


void output_matrix(int**matrix,int rows, int columns)
{
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < columns; j++)
    {
      std::cout<<matrix[i][j]<<'\t';
    }
    std::cout<<'\n';
  }
}

int product_numbers(int**matrix,int columns,int us_row_num)
{
  int pr = 1;
  for (size_t j = 0; j < columns; j++)
  {
    pr *= matrix[us_row_num][j];
  }
  return pr;
}


int main()
{
  int** matrix;
  int r,c,user_number;
  cout<<"Enter number of rows then columns ";
  cin>>r>>c;
  cout<<'\n';
  matrix=create_matrix(r,c);
  input_matrix(matrix,r,c);
  output_matrix(matrix,r,c);
  cout<<"Enter number row: ";
  cin>>user_number;
  cout<<"Product of elements in row "<<user_number<<'='<<product_numbers(matrix,c,user_number-1);
  delete_matrix(matrix,r,c);
  return 0;
}
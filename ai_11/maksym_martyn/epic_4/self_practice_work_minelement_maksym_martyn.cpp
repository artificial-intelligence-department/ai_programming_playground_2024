#include <iostream>
using namespace std;
int main ()
{
  int rows, columns;
  int** matrix=nullptr;
  int user_num;
  cout<<"Enter number of rows and columns ";
  cin>>rows>>columns;
  cout<<'\n';

  matrix=new int*[rows];
  for (size_t i = 0; i < rows; i++)
  {
    matrix[i]=new int[columns];
  }
  
 for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < columns; j++)
    {
      cout<<'['<<i+1<<"]["<<j+1<<"] = ";
      cin>>matrix[i][j];
    }
  }
  int min_element = matrix[0][0];
  int idx_min_row = 0;
  int idx_min_column = 0;

 for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < columns; j++)
    {
      cout<<matrix[i][j]<<'\t';
    }
    cout<<'\n';
  }

  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < columns; j++)
    {
      if (min_element>matrix[i][j])
      {
        idx_min_row = i;
        idx_min_column=j;
      }
    }
  }

  cout<<"coordinates of min element is : "<<idx_min_row+1<<' '<<idx_min_column+1;
  
  for (size_t i = 0; i < rows; i++)
  {
    delete[] matrix[i];
  }
  delete[] matrix;
  return 0;
}
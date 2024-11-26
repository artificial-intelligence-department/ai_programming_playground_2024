#include <iostream>
using namespace std;

  bool isAscending(int row[], int column){
    for(int i = 0; i < column-1;i++){
      if(row[i] > row[i+1]){
        return false;
      }
    }
    return true;
  }

  bool isDescending(int row[], int column){
    for(int i = 0; i < column-1;i++){
      if(row[i] < row[i+1]){
        return false;
      }
    }
    return true;
  }

  void sortAscending (int row[], int column){
    int temp;
    for (int i = 0; i < column-1; i++){
      for(int j = 0;j < column - i - 1; j++){
        if(row[j] > row[j+1]){
        temp = row[j];
        row[j] = row[j+1];
        row[j+1] = temp;
        }
      }
    }
  }

int main (){
  const int rows = 5;
  const int columns = 5;
  int arr[rows][columns] = {
    {5, 3, 1, 2, 4},
    {10, 9, 8, 7, 6},
    {5, 4, 3, 2, 1},
    {1, 2, 3, 4, 5},
    {44, 41, 54, 14, 4}
  };

  cout << "Initial array: " << '\n';
  for(int i = 0; i < rows; i++){
    for(int j = 0;j < columns; j++){
      cout << arr[i][j] << ' ';
    }
    cout << '\n';
  }

  for(int i = 0; i < rows ;i++){
    if(!isAscending(arr[i],columns) && !isDescending(arr[i],columns)){
      sortAscending(arr[i],columns);
    }
  }
  cout << "Array after changing " << '\n';
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < columns; j++){
      cout << arr[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}
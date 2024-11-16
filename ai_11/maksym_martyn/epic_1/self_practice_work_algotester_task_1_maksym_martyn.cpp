// https://algotester.com/en/ArchiveProblem/DisplayWithEditor/40699
#include <iostream>
using namespace std;

void inputArray(int arr[] , int size)
{
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }
}

void outputArray(int arr[] , int size)
{
  for (int i = 0; i < size; i++) 
  {
    cout << arr[i] << " ";
  }
    cout << endl;
}

void reversedArray(int arr[] , int size , int reversedArr[])
{
  for (int i = 0; i < size; i++)
  {
    reversedArr[i] = arr[size - 1 - i];
  }
}

bool areChangedArraysEquals (int arr1[], int arr2[], int size)
{
  for (int i = 0; i < size; i++)
  {
    if(arr1[i] != arr2[i])
    {
      return false;
    }
  }
  return true;
}



int main()
{
  int N = 0; // Number of elves
  int *initial_lineup_arr , *changed_lineup_arr ,*true_changed_arr;
  cin >> N;

  if (N < 1 || N > 1000)
  {
    return 1;
  }

  initial_lineup_arr = new int [N]; // початковий порядок 
  inputArray(initial_lineup_arr , N);
  
  changed_lineup_arr = new int [N]; // поміняний порядок 
  inputArray(changed_lineup_arr , N);
  
  true_changed_arr = new int [N];
  reversedArray (initial_lineup_arr , N , true_changed_arr );

  if(areChangedArraysEquals(changed_lineup_arr , true_changed_arr , N))
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
    outputArray(true_changed_arr , N);
  }

  delete[]initial_lineup_arr;
  delete[]changed_lineup_arr;
  delete[]true_changed_arr;

  return 0;
}
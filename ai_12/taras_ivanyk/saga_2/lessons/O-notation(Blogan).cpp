#include <iostream>
using namespace std;

// O(1):   (constant O-notation)
int Get_element(const int arr[], int index)
{
    return  arr[index];
}

// O(n) (linear O-notation)
int Sum(const int arr[], int size){
    int sum = 0; 
    for(int i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum;
}

// O(n^2): (Square O-notation)
void Show(int** arr, int rows, int cols){
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){

    int arr1[10] = {};
    int arr2[10000] = {};
//***************************************************** */

    Get_element(arr1, 5);     // same time of get element, so O-notation
    Get_element(arr2, 5000);  // is O(1)

//*************************************************** */

    Sum(arr1, 10);       // time = 10x
    Sum (arr2, 10000);   // time = 10000x  
    // time increase in propotion to amount of elements [linear]

//*************************************************** */

// O(n^2) = O(rows * cols)

int rows = 5;
int cols = 3;

int** arr = new int*[rows];
    for(int i = 0; i < rows; ++i){
        arr[i] = new int[cols];
    }

    for(int i = 0; i < rows; ++i){               // time = cols * rows (n^2)
        for(int j = 0; j < cols; ++j){
            arr[i][j] = 1;
        }
    }

    Show(arr, rows, cols);

    for(int i = 0; i < rows; ++i){
        delete[] arr[i];
    }
    delete[] arr;

    // Operations in binary tree = O(log n)

    return 0;
}
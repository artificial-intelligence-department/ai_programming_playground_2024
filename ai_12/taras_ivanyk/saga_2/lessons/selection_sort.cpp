#include <iostream>
#include <ctime>
using namespace std;

void selection_sort(int arr[], int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = i + 1; j < size; j++){
            if(arr[j] < arr[i]){
            swap(arr[j], arr[i]);
            }
        }
    }
}

void print_arr(int arr[], int size){
    for(int i = 0; i < size; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    srand(static_cast<unsigned>(time(nullptr)));
   
    int size = 10;
    int arr1[size] = {};
    for(int i = 0; i < size; ++i){
        arr1[i] = rand() % 100;
    }
    
    print_arr(arr1, size);
    selection_sort(arr1, size);
    print_arr(arr1, size);

    return 0;
}
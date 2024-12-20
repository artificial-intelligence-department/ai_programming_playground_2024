#include <iostream>
#include <ctime>
using namespace std;

void print(int arr[], int size){
    for(int i = 0; i < size; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

template<typename T>
void insertion_sort(T arr[], int size){
    for(int i = 1; i < size; i++){
        int key = arr[i];
        int j;
        for(j = i - 1; j >= 0 && arr[j] > key; j--){
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}

int main(){
    srand(static_cast<unsigned>(time(nullptr)));
    
    int size = 10;
    int arr[size] = {};
    for(int i = 0; i < size; ++i){
        arr[i] = rand() % 100;
    }

    print(arr, size);
    insertion_sort(arr, size);
    print(arr, size);


    return 0;
}
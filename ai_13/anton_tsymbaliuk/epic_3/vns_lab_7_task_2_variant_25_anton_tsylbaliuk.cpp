#include <iostream>

template <typename T>
int deleteEvenRows(T**& arr, int size1){
    T** newArr = new T*[size1 / 2 + 1];
    int count = 0;
    for(int i = 0; i < size1; i++){
        if((i + 1) % 2 == 0) delete[] arr[i];
        else {
            newArr[count++] = arr[i];
        }
    }
    delete[] arr;
    arr = newArr;
    return count;
}

template <typename T>
int deleteElem(T*& arr, int size){
    int count = size;
    for(int i = 1; i < size -1; i++)if(arr[i-1] == 0 && arr[i + 1] == 0) count--;
    T* newArr = new T[count];
    newArr[0] = arr[0];
    newArr[count - 1] = arr[size - 1];
    for(int i = 1, j = 1; i < size -1; i++)if(!(arr[i-1] == 0 && arr[i + 1] == 0)) newArr[j++] = arr[i];
    delete[] arr;
    arr = newArr;
    return count;
}

template <typename T>
void showElems(T* arr, int size){
    for(int i = 0; i < size; i++)std::cout << arr[i] << " ";
    std::cout << std::endl;
}

template <typename T>
void showElems(T** arr, int size1, int size2){
    for(int i = 0; i < size1; i++) {
        for(int j = 0; j < size2; j++) std::cout << arr[i][j] << " ";
        std::cout << std::endl;
    }
}


int main(){
    int initSize = 10;
    float** arr1 = new float*[initSize];
    for(int i = 0; i < initSize; i++) arr1[i] = new float[initSize];
    for(int i = 0; i < initSize; i++) for(int j = 0; j < initSize; j++) arr1[i][j] = (i + 1) * (j + 1);
    int* arr2 = new int[initSize];
    for(int i = 0; i < initSize; i++) arr2[i] = i;
    arr2[2] = 0;
    arr2[4] = 0;
    arr2[6] = 0;
    showElems(arr1, initSize, initSize);
    showElems(arr2, initSize);
    int size1 = deleteEvenRows(arr1, initSize);
    int size2 = deleteElem(arr2, initSize);
    showElems(arr1, size1, initSize);
    showElems(arr2, size2);

    for(int i = 0; i < size1; i++) delete[] arr1[i];
    delete[] arr1;
    delete[] arr2;
    return 0;
}
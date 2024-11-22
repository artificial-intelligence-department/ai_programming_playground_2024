#include <iostream>
using namespace std;
int findMin(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}
void deleateElem (int arr[], int& size, int value){
    for(int i = 0; i < size; i++){
        if (arr[i] == value){
            for (int j = i; j < size - 1; j++){
                arr[j] = arr[j+1];
            }
            size--;
            i--;
        } 
    }
}
void addElem(int arr[], int &size, int value){
    size++;
    for(int i = size; i > 0; i--){
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
}   


int main() {
    srand(static_cast<unsigned int>(time(0)));
    int size, sum = 0;
    int arr[100];
    cin >> size;
    for (int i = 0; i < size; i++){
        arr[i] = rand() % 11;
        cout << arr[i] << " ";
    }
    cout << endl;
    deleateElem(arr, size, findMin(arr, size));
    for(int i = 0; i < size; i++){
        sum += arr[i];
        cout << arr[i] << " ";
    }
    cout << endl;    
    int avarege = sum / size;
    addElem(arr, size, avarege);
    addElem(arr, size, avarege);
    addElem(arr, size, avarege);
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }    
    return 0;
}
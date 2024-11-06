#include<iostream>
#include<ctime>
using namespace std;

void Show(int arr[], int size);
void delK(int arr[], int &size, int k);
void addNull(int arr[], int size, int nArr[], int &nSize);

int main(){
    srand(time(NULL));
    const int SIZE = 100;

    int arr[SIZE];
    int nArr[100];

    int size = 0, k = 0, nSize = 0;

    cout << "Enter size of array" << endl;
    cin >> size;

    cout << "Enter index of the element to be deleted" << endl;
    cin >> k;

    for(int i = 0; i < size; i++){
        arr[i] = rand()% 100 + 1;
    }

    Show(arr, size);

    delK(arr, size, k);

    Show(arr, size);

    addNull(arr, size, nArr, nSize);

    Show(nArr, nSize);


    return 0;
}

void Show(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << "[" << arr[i] << "] ";
    }
    cout << endl;
}

void delK(int arr[], int &size, int k){
    for(int i = k; i < size - 1; i++){
            arr[i] = arr[i+1];
    }
    size--;
}

void addNull(int arr[], int size, int nArr[], int &nSize) {
    int j = 0; 
    for (int i = 0; i < size; i++) {
        nArr[j] = arr[i];
        j++;
        nSize++;
        
        if (arr[i] % 2 == 0) {
            nArr[j] = 0;
            j++;
            nSize++;
        }
    }
}

#include <iostream>
#include <ctime>
using namespace std;

void Display(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    srand(time(NULL));

    const int tsize = 100;
    int arr[tsize];
    int nArr[100];

    int size = 0, k = 0, nSize = 0;

    cout << "Enter size of array: ";
    cin >> size;

    for(int i = 0; i < size; i++){
        arr[i] = rand()% 100 + 1;
    }

    Display(arr, size);

    for (int i = 0; i < size;){
        if (arr[i] % 7 == 0) {
            for (int j = i; j < size - 1; j++){
                arr[j] = arr[j + 1];
            }
            size--;
        } else {
            i++;
        }
    }

    Display(arr, size);

    for (int i = 0; i < size;){
        if (arr[i] % 2 == 1){
            if (size < tsize){
                for (int j = size; j > i + 1; j--){
                    arr[j] = arr[j - 1];
                }
                arr[i + 1] = 0;
                size++;
                i += 2;
            } else break;
        } else i++;
    }

    Display(arr, size);

    return 0;
}
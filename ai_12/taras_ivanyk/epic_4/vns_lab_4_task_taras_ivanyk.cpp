#include <iostream>
#include <cstdlib>   
#include <ctime>     

using namespace std;

int main() {
    const int n = 10;
    int arr[n];
    int delete_value;

    srand(time(0));

    cout << "Start array: ";
    for (int i = 0; i < n; ++i){
        arr[i] = rand() % 10;
        cout << arr[i] << " ";
        }
    cout << "\n";

    cout << "Enter a value that we should delete: ";
    cin >> delete_value;

    int newSize = 0;
    for (int i = 0; i < n; ++i){
        if(arr[i] != delete_value){
            arr[newSize++] = arr[i];
        }
    }

    int newArr[2 * newSize]; // maximum size of new array with 0 before pair integers
    int NEWSIZE = 0;

    for (int i = 0; i < newSize; ++i){
        if(arr[i] % 2 == 0 && arr[i] != 0){
            newArr[NEWSIZE++] = 0;
        }
        newArr[NEWSIZE++] = arr[i];
    }

    cout << "Array after deleting numbers and adding zeros: ";
    for (int i = 0; i < NEWSIZE ; ++i){
        cout << newArr[i] << " ";
    }
    cout << "\n";

    return 0;
}

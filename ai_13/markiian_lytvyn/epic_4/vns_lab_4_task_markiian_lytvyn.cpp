#include <iostream>
using namespace std;

void print_left(int* array, int n, int k) {
    cout << "Масив по кільцю вліво від K: ";
    for (int i = 0; i < n; i++) {
        int index = k - i; 
        if (index < 0){
        index += n;
        }
        cout << array[index] << " ";
    }
    cout << endl;
}

void print_right(int* array, int n, int k) {
    cout << "Масив по кільцю вправо від K: ";
    for (int i = 0; i < n; i++) {
        int index = k + i;
         if(index >= n){
            index -= n;
        }
        cout << array[index] << " ";
    }
    cout << endl;
}


void add(int*& array, int& n) {
    int* new_array = new int[n + 2]; 
    new_array[0] = array[n - 1];     
    for (int i = 0; i < n; i++) {
        new_array[i + 1] = array[i]; 
    }
    new_array[n + 1] = array[0];     
    n += 2;                          
    delete[] array;                  
    array = new_array;               
}

int main() {
    int n, k;
    cout << "Введіть розмір масиву: ";
    cin >> n;

    int* array = new int[n]; 
    cout << "Введіть елементи масиву:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    cout << "Введіть K (індекс стартового елемента): ";
    cin >> k;

    if (k < 0 || k >= n) {
        cout << "K має бути в діапазоні [0, " << n - 1 << "]." << endl;
        delete[] array; 
        return 0;
    }
    print_left(array, n, k);
    add(array, n);
    print_right(array, n, k);
    delete[] array;
    return 0;
}

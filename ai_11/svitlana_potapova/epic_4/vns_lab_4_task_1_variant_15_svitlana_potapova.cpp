#include <iostream>
using namespace std;

void print_left(int* array, int n, int k){
    for(int i=0; i<n; i++){
        int index = k-i;
        if (index<0){
        index +=n;
        }
        cout << array[index] << " ";
    }
    cout << endl;
}

void print_right(int* array, int n, int k){
    for (int i=0; i<n; i++){
        int index = k+i;
        if(index>n-1){
            index -= n;
        }
        cout << array[index] << " ";
    }
    cout << endl;
}

void deleteEl(int* array, int& n){
    for(int i=0; i<n-1; i++){
        array[i] = array[i+1];
    }
    n -= 2;
}

int main(){
    int array[100];
    int n, k;
    cout << "Введіть розмір масиву:" << endl;
    cin >> n;
    cout << "Введіть елементи масиву:" << endl;
    for (int i=0; i<n; i++){
        cin >> array[i];
    }
    cout << "Введіть k номер елемента:" << endl;
    cin >> k;
    cout << "Масив по кільцю вліво від елемента k:" << endl;
    print_left(array, n, k);
    cout << "Масив(з видаленим першим та останнім елементом) по кільцю вправо від елемента k:" << endl;
    deleteEl(array,n);
    print_right(array, n, k);

    return 0;
}


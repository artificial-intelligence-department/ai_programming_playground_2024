#include <iostream>
#include <ctime>
using namespace std;

void Initialize(int arr[], int size);           
void Show(int arr[], int size);                 
void DeleteElement(int*& arr, int& size, int index); 
bool AddAfterFirstEven(int*& arr, int& size);  
int main() {
    srand(static_cast<unsigned>(time(nullptr))); 

    int size;
    cout << "Введіть кількість елементів у масиві: ";
    cin >> size;

    if (size <= 0) {
        cout << "Непраивильно введено.Введіть число більше за 0." << endl;
        return 1;
    }

    int* arr = new int[size]; 

    Initialize(arr, size); 
    cout << "Початковий масив: ";
    Show(arr, size);

    int indexToDelete;
    cout << "Введіть індекс елемента для видалення (від 0 до " << size - 1 << "): ";
    cin >> indexToDelete;

    if (indexToDelete >= 0 && indexToDelete < size) {
        DeleteElement(arr, size, indexToDelete);
        cout << "Масив після видалення елемента: ";
        Show(arr, size);
    } else {
        cout << "Непраивильно введено.Видалення не виконане." << endl;
    }

    if (AddAfterFirstEven(arr, size)) {
        cout << "Масив після додавання нового елемента: ";
        Show(arr, size);
    } else {
        cout << "Парного елемента не знайдено. Додавання не виконане." << endl;
    }

    delete[] arr; 
    return 0;     
}

void Initialize(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; 
    }
}

void Show(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void DeleteElement(int*& arr, int& size, int index) {
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1]; 
    }
    size--; 
}

bool AddAfterFirstEven(int*& arr, int& size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) { 
            int newSize = size + 1;
            int* newArr = new int[newSize];

            for (int j = 0; j <= i; j++) {
                newArr[j] = arr[j];
            }

            newArr[i + 1] = arr[i] + 2;

            for (int j = i + 1; j < size; j++) {
                newArr[j + 1] = arr[j];
            }

            delete[] arr; 
            arr = newArr; 
            size = newSize;
            return true; 
        }
    }
    return false; 
}

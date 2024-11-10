#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    
    int a[100];
    int size;
    cout << "Введіть довжину масиву : ";
    cin >> size;
    
    for (int i = 0; i < size; i++) {
        a[i] = rand() % 100; 
    }

    cout << "Початковий масив: ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    if (size > 5) {
        size -= 5;
        for (int i = 0; i < size; i++) {
            a[i] = a[i + 5];
        }
    } else {
        cout << "Масив занадто малий для видалення 5 елементів." << endl;
    }

    cout << "Введіть 3 нових числа для додавання в кінець масиву: ";
    for (int i = 0; i < 3; i++) {
        cin >> a[size + i];
    }
    size += 3;

    cout << "Кінцевий масив: ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

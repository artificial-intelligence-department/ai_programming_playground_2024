#include <iostream>

using namespace std;


const int N = 100;

void printLeft(int a[], int size, int start) {
    int i = start;
    do {
        cout << a[i] << " ";
        i = (i + 1) % size;
    } while (i != (start - 1 + size) % size);
    cout << a[i] << endl;
}

void printRight(int a[], int size, int start) {
    int i = start;
    do {
        cout << a[i] << " ";
        i = (i - 1 + size) % size;
    } while (i != (start + 1) % size);
    cout << a[i] << endl;
}

void addElements(int a[], int& size, int firstElement, int lastThreeElements[]) {
    if (size + 4 > N) {
        cout << "Перевищено максимальний розмір масиву" << endl;
        return;
    }
    
    for (int i = size; i > 0; --i) {
        a[i] = a[i - 1];
    }
    a[0] = firstElement;
    ++size;

    for (int i = 0; i < 3; ++i) {
        a[size++] = lastThreeElements[i];
    }
}

int main() {
    int a[N];
    int size;
    
    cout << "Введіть довжину масиву: ";
    cin >> size;

    if (size > N) {
        cout << "Неправильна довжина масиву!" << endl;
        return 1;
    }
    
    cout << "Введіть елементи масиву: ";
    for (int i = 0; i < size; ++i) {
        cin >> a[i];
    }

    int K;
    cout << "Введіть номер K (від 0 до " << size - 1 << "): ";
    cin >> K;
    
    if (K < 0 || K >= size) {
        cout << "Неправильне значення K!" << endl;
        return 1;
    }

    cout << "Масив вліво від K до K-1: ";
    printLeft(a, size, K);

    int firstElement = a[0];
    int lastThreeElements[] = {a[size - 3], a[size - 2], a[size - 1]};
    addElements(a, size, firstElement, lastThreeElements);

    cout << "Масив вправо від K до K+1: ";
    printRight(a, size, K);

    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

void print(const int massive[], int realSize, int startIndex) {
    for (int i = 0; i < realSize; i++) {
        cout << massive[(startIndex + i) % realSize] << " ";
    }
    cout << endl;
}

int main() {
   
    const int N = 100;
    int massive[N];

    int realSize;
    cout << "Введіть кількість елементів у масиві (не більше 100): ";
    cin >> realSize;
    if (realSize > N) {
        cout << "Помилка: розмір масиву перевищує максимальний розмір (" << N << ")." << endl;
        return 1;
    }

    cout << "Введіть елементи масиву: ";
    for (int i = 0; i < realSize; i++) {
        cin >> massive[i];
    }

    int K;
    cout << "Введіть елемент K: ";
    cin >> K;

    cout << "Масив зі зсувом K: ";
    print(massive, realSize, K);

    sort(massive, massive + realSize);
    cout << "Відсортований масив: ";
    for (int i = 0; i < realSize; i++) {
        cout << massive[i] << " ";
    }
    cout << endl;

    int newSize = 0; 
    for (int i = 0; i < realSize; i++) {
        if (massive[i] % 2 != 0) {
            massive[newSize++] = massive[i]; 
        }
    }
    realSize = newSize;
   
    cout << "Масив після видалення парних чисел: ";
    print(massive, realSize, K);

    return 0;
}

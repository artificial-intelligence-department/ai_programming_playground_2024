#include <iostream>
using namespace std;

int main() {
    const int N = 103; 
    int a[N];
    int realLength;

    cout << "Введіть реальну довжину масиву (не більше 100): ";
    cin >> realLength;
    if (realLength > N) {
        cout << "Задана довжина перевищує максимальну, завершення програми.\n";
        return 0;
    }

    srand(time(0));
    cout << "Початковий масив: ";
    for (int i = 0; i < realLength; i++) {
        a[i] = rand() % 101; 
        cout << a[i] << " ";
    }
    cout << endl;

    /* Крок 3: Перевертаємо масив*/
    for (int i = 0; i < realLength / 2; i++) {
        int temp = a[i];
        a[i] = a[realLength - i - 1];
        a[realLength - i - 1] = temp;
    }

    /* Якщо кількість елементів непарна, видаляємо середній елемент*/
    if (realLength % 2 != 0) {
        int mid = realLength / 2;
        for (int i = mid; i < realLength - 1; i++) {
            a[i] = a[i + 1];
        }
        realLength--; 
    }

    if(realLength >= 10){
        /*зміщення елементів на 3 вправо*/
        for (int i = realLength - 1; i >= 0; i--) {
            a[i + 3] = a[i]; 
        }
        for (int i = 0; i < 3; i++) {
            a[i] = a[i + 10] - 2; 
        }
        realLength += 3;
    }else{
        cout << "Недостатня кількість елементів для обчислення за формолою a[i + 10] - 2. Мінімальна кількість це 10.\n";
    }

    cout << "Отриманий масив: ";
    for (int i = 0; i < realLength; i++) {
        cout << a[i] << " ";
    }
    return 0;
}

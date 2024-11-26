#include <iostream>
#include <algorithm> 
using namespace std;

const int N = 100; 

void printRing(int arr[], int length, int K) {
    cout << "Елементи кільця з індексу " << K << " до " << (K + 1) % length << " (у зворотньому порядку):\n";
    int index = K;
    do {
        cout << arr[index] << " ";
        index = (index - 1 + length) % length; 
    } while (index != ((K + 1) % length));
    cout << arr[index] << " ";
    cout << endl;
}

int removeOdd(int arr[], int length) {
    int newLength = 0;
    for (int i = 0; i < length; ++i) {
        if (arr[i] % 2 == 0) {
            arr[newLength++] = arr[i]; 
        }
    }
    return newLength;
}

int main() {
    int a[N];
    int realLength;

    wrongLength:
    cout << "Введіть реальну довжину масиву (не більше " << N << "): ";
    cin >> realLength;
    if (realLength > N || realLength <= 0) {
        cout << "Невірна довжина масиву!" << endl;
        goto wrongLength;
        return 1;
    }

    for (int i = 0; i < realLength; ++i) {
        cout << "Введіть " << i << " елемент масиву: ";
        cin >> a[i];
    }


    int K;
    wrongIndex:
    cout << "Введіть індекс K (0 <= K < " << realLength << "): ";
    cin >> K;
    if (K < 0 || K >= realLength) {
        cout << "Невірний індекс K!" << endl;
        goto wrongIndex;
        return 1;
    }

    printRing(a, realLength, K);

    sort(a, a + realLength, greater<int>());

    realLength = removeOdd(a, realLength);

    cout << "Посортований масив без непарних елементів: " << endl;
    for(int i = 0; i < realLength; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    printRing(a, realLength, K);

    return 0;
}
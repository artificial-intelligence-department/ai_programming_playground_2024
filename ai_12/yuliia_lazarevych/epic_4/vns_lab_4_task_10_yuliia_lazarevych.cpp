#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int MAX_SIZE = 100;
    int array[MAX_SIZE];
    int realLength;

    cout << "Enter the size of the array (max " << MAX_SIZE << "): ";
    cin >> realLength;

    if (realLength > MAX_SIZE || realLength <= 0) {
        cout << "Invalid array size!" << endl;
        return 1;
    }

    srand(time(0));
    for (int i = 0; i < realLength; i++) {
        array[i] = rand() % 100000;
    }

    cout << "Initial array:" << endl;
    for (int i = 0; i < realLength; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    if (realLength > 5) {
        for (int i = 0; i < realLength - 5; i++) {
            array[i] = array[i + 5];
        }
        realLength -= 5;
    } else {
        realLength = 0;
    }

    int newElements[3];
    for (int i = 0; i < 3; i++) {
        newElements[i] = rand() % 100000;
        array[realLength + i] = newElements[i];
    }
    realLength += 3;

    cout << "Resulting array:" << endl;
    for (int i = 0; i < realLength; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}

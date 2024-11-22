#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    const int SIZE = 10;

    int масив1[SIZE] = {};
    int масив2[SIZE] = {};
    int масив3[SIZE] = {};

    srand(time(NULL));

    cout << "Масив 1: ";
    for (int i = 0; i < SIZE; i++) {
        масив1[i] = 10 + rand() % 21;
        cout << масив1[i] << " | ";
    }
    cout << endl << endl;

    cout << "Масив 2: ";
    for (int i = 0; i < SIZE; i++) {
        масив2[i] = 10 + rand() % 21;
        cout << масив2[i] << " | ";
    }
    cout << endl << endl;

    cout << "Масив 3 (сума масивів 1 і 2): ";
    for (int i = 0; i < SIZE; i++) {
        масив3[i] = масив1[i] + масив2[i];
        cout << масив3[i] << " | ";
    }
    cout << endl << endl;

    int середнєЗначення = 0;
    int сума = 0;
    int мінЗначення = масив3[0];
    int максЗначення = масив3[0];

    for (int i = 0; i < SIZE; i++) {
        сума += масив3[i];

        if (масив3[i] < мінЗначення) {
            мінЗначення = масив3[i];
        }

        if (масив3[i] > максЗначення) {
            максЗначення = масив3[i];
        }
    }

    середнєЗначення = сума / SIZE;

    cout << "Середнє арифметичне = " << середнєЗначення << endl;
    cout << "Мінімальне значення = " << мінЗначення << endl;
    cout << "Максимальне значення = " << максЗначення << endl;
    cout << endl << endl;

    return 0;
}

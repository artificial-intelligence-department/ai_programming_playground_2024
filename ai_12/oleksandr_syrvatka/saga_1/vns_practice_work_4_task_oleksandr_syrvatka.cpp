#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    const int size = 10;
    int numbers[size];
    double sum = 0;  

    cout << "Згенерована послідовність чисел: ";

    for (int i = 0; i < size; i++) {
        numbers[i] = rand() % 10 + 1;
        cout << numbers[i] << " ";
        sum += numbers[i];
    }

    double average = sum / size;

    cout << "\nСереднє арифметичне: " << average << endl;

    return 0;
}

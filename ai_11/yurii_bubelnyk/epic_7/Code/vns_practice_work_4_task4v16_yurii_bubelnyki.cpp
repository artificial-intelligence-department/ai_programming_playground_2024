#include <iostream>
#include <ctime> //підключив бібліотеку для srand та rand

using namespace std;

const int SIZE = 10; //задаю розмір масив 

void Initialize(int arr[]);

int main(){
    srand(time(NULL)); //для генерації псевдовипадкових чисел при повторному запуску програми

    int arr[SIZE];

    Initialize(arr); // викликаю функцію для обробки масиву

    return 0;
}
// функція для обрахунку середнього арифметичного послідовності з 10 числе в діапазоні від 1 до 10
void Initialize(int arr[]){

    int sum = 0; // ініціалізація змінної для запису суми послідовості

    for (int i = 0; i < SIZE; i++){
        arr[i] = rand() % 10 + 1; //  обмежую діапазон від [1, 10]
        sum += arr[i]; // сумую значення послідовності
        cout << arr[i] << " "; //  вивід значеннь послідовності
    }

    cout << "\nAverage: " << static_cast<double>(sum) / SIZE << endl; //переведення типу int в double для обчислення середнього арифметичного
}

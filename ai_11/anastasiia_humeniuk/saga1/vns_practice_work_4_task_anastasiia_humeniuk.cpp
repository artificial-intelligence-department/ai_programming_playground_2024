#include <iostream>
using namespace std;

// Оголошення структури для зберігання числа та суми
struct SumCalculator {
    int n;     
    int sum;     
};

int main() {
    SumCalculator calculator;  //Створення об'єкта структури

    cout << "n = ";
    cin >> calculator.n;

    calculator.sum = 0; 

    int i = 1; 

    // Цикл do-while для обчислення суми перших n чисел
    do {
        calculator.sum += i; 
        i++; 
    } while (i <= calculator.n);  // Перевірка умови продовження циклу

    cout << "Сума перших " << calculator.n << " цілих позитивних чисел: " << calculator.sum << endl;

    return 0;
}

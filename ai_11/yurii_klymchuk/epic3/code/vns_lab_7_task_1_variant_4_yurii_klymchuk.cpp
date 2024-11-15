#include <iostream>
#include <cstdarg>//бібліотека для variadic functions

using namespace std;

//функція з невизначеною кількістю елементів
int sum(int count, ...){
    va_list args;//створюємо список для збереження уведених значень
    va_start(args, count);//задаємо посаток цього списку і записуємо введені значення
    int s = 0;
    for (int i = 0; i < count; i+=2){
        int a = va_arg(args, int);//дістаємо 4 біта(розмір типу int) інформації з цього списку
        int b = va_arg(args, int);
        s += a*b;
    }
    va_end(args);//завершення роботи з списком аргументів
    return s;
}

int main(){
    cout << "The sum of 8 elements is "<< sum(8, 24, 3, 8, 11, 5, -6, 8, 2) << "\n";
    cout << "The sum of 10 elements is "<< sum(10, 5, 41, 60, 2, 2, -4, 3, -7, 5, 1) << "\n";
    cout << "The sum of 12 elements is "<< sum(12, 1, 1, 0, 4, 5, -7, 3, 25, 6, 11, 6, 8) << "\n";
    return 0;
}
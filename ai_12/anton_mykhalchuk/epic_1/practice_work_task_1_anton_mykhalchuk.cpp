#include <iostream>   // Підключення бібліотеки для роботи з потоками введення-виведення
#include <cmath>      // Підключення бібліотеки для математичних операцій (для функції pow)

using namespace std;

int main() {
    // Оголошення змінних для збереження значень
    float a, p, r;   // a - загальна сума інвестицій, p - початкова сума (principal), r - річна процентна ставка
    int n, t;        // n - кількість нарахувань процентів в рік, t - кількість років інвестування

    // Введення початкової суми інвестицій від користувача
    printf("Enter principal amount of investment: ");
    scanf("%f", &p);   // Зчитування введеної користувачем початкової суми (float)

    // Введення річної процентної ставки від користувача
    printf("Enter annual percentage rate: ");
    scanf("%f", &r);   // Зчитування введеної процентної ставки (float)

    // Введення кількості нарахувань процентів за рік
    printf("Enter number of interest charges per year: ");
    scanf("%d", &n);   // Зчитування кількості нарахувань процентів (int)

    // Введення часу інвестування в роках
    printf("Enter time for which the money is invested, in years: ");
    scanf("%d", &t);   // Зчитування кількості років інвестування (int)

    // Обчислення загальної суми інвестицій за формулою складних процентів
    a = p * pow(1 + r / n / 100, n * t);  
    // pow(1 + r / n / 100, n * t) - підрахунок складних процентів
    // r/n/100 - розрахунок процентної ставки на кожне нарахування
    // n * t - загальна кількість нарахувань за весь час

    // Виведення результату
    printf("\n\n\nThe total amount of the investment, given:\nPrincipal amount of the investment %.2f\nThe annual interest rate %.2f\%\nThe number of interest accruals per year %d\nand the time for which the money is invested %d years\nWill be equal: %.2f\n", p, r, n, t, a);
    // Виведення введених даних користувача і загальної суми інвестицій

    // Виведення прибутку (сума інвестицій мінус початкова сума)
    printf("The amount of the earnings themselves: %.2f", a - p);  
    // a - p - це чистий дохід від інвестицій

    return 0;
}

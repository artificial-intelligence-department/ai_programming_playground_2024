#include <iostream>

using namespace std;

int main() {
    // 1. обчислення вартості покупки
    cout << "Обчислення вартості покупки." << endl;
    cout << "Введіть початкові дані:" << endl;

    double priceNotebook, priceCover;
    int numSets;

    cout << "Ціна зошита (грн.) > ";
    cin >> priceNotebook;
    cout << "Ціна обкладинок (грн.) > ";
    cin >> priceCover;
    cout << "Кількість комплектів > ";
    cin >> numSets;

    double totalCost = numSets * (priceCover + priceNotebook);

    cout << "Вартість покупки: " << totalCost << " грн." << endl;


    // 2. розрахунок кількості шайб
    cout << "Розрахунок кількості виготовлених шайб." << endl;

    int KOL;
    cout << "Введіть кількість шайб, які верстат виготовляє за годину > ";
    cin >> KOL;

    int hourPerShift = 8 - 1;
    int shiftsPerDay = 2;
    int workingDays = 30 - 4;

    int prodPerShift = KOL * hourPerShift;
    int prodPerDay = prodPerShift * shiftsPerDay;
    int prodPerMonth = prodPerDay * workingDays;

    cout << "За 8-годинну зміну: " << prodPerShift << " шайб." << endl;
    cout << "За робочий день: " << prodPerDay << " шайб." << endl;
    cout << "За 30-денний місяць: " << prodPerMonth << " шайб." << endl;

    return 0;
}
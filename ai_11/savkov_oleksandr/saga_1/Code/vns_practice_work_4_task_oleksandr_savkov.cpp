
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double pricePerKg;
    cout << "Введіть ціну за 1 кг яблук: ";
    cin >> pricePerKg;
    cout << "Таблиця вартості яблук:\n";
    cout << "Вага (г)\tВартість (грн)\n";
    for (int weight = 100; weight <= 1000; weight += 100) {
        double cost = (pricePerKg / 1000) * weight;
        cout << weight << "\t" << fixed << setprecision(2) << cost << endl; }
    return 0; }

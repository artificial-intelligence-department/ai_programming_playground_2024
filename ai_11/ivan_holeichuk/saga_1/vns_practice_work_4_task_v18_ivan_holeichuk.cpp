#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8");

    const double pricePerKg = 30.5; // Константа для ціни за кілограм
    double weights[10]; // Масив для зберігання ваги

    for (int i = 0; i < 10; i++) {
        weights[i] = (i + 1) * 0.1; // Розрахунок ваги у кг
    }

    ofstream fout("result4.txt"); // Робота з файлами: запис таблиці
    fout << setw(10) << "Вага (кг)" << setw(20) << "Ціна (грн)" << endl;
    fout << fixed << setprecision(2);
    for (int i = 0; i < 10; i++) {
        fout << setw(10) << weights[i] << setw(20) << weights[i] * pricePerKg << endl;
    }
    fout.close();

    cout << "Таблицю записано у файл result4.txt" << endl;
    return 0;
}

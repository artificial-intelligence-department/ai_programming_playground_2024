#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double calculateZ(double m, double x) { // Функція з параметрами для обчислення Z
    return log(sin(m * x)) / sin(x); // Математичні функції
}

int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8");

    double m = 0.7, x = 1.77;

    double Z = calculateZ(m, x);

    ofstream fout("result2.txt"); // Робота з файлами: запис результатів
    fout << "Z = " << Z << endl;
    fout.close();

    cout << "Результат записано у файл result2.txt" << endl;
    return 0;
}

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8"); // Додає підтримку української мови для виводу

    const int n = 5; // Використання константи для розміру масиву
    double x[n] = { 1.2, -0.8, 2.3, 4.0, 3.1 }; // Одновимірний масив для чисел

    double S = 0; // Використання змінної з подвійною точністю для зберігання суми
    for (int i = 0; i < n; i++) {
        S += x[i];
    }

    double Z = sin(x[1]) + cos(x[2]); // Математичні функції для обчислення значення

    ofstream fout("result1.txt"); // Робота з файлами: запис результатів
    fout << "S = " << S << endl;
    fout << "Z = " << Z << endl;
    fout.close();

    cout << "Результати записано у файл result1.txt" << endl;
    return 0;
}

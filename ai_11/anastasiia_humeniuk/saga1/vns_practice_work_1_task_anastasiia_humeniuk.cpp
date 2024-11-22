#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    double x, y, z;

    ifstream inFile("input.txt"); // Відкриття файлу для зчитування вхідних даних

    if (!inFile.is_open()) {
        cout << "Не вдалося відкрити вхідний файл!" << endl;
        return 1;
    }

    inFile >> x >> y >> z; // Оператор введення даних

    if (inFile.fail()) {
        cout << "Помилка при зчитуванні даних!" << endl;
        return 1;
    }

    inFile.close();

    double numeratorP = 1 + pow(sin(x + 1), 2); // Математична операція (піднесення до квадрату)
    double denominatorP = 2 + abs(x - 2 * pow(x, 3) / (1 + pow(x, 2) * pow(y, 3))); // Математичні операції
    double P = numeratorP / denominatorP + pow(x, 4); // Математична операція (ділення, додавання, піднесення до ступеня)

    double Q = pow(cos(atan(1 / z)), 2); // Математична операція (атангент, косинус, піднесення до квадрату)

    ofstream outFile("result.txt"); // Створення і відкриття файлу для запису результатів

    if (outFile.is_open()) {
        outFile << "P = " << P << endl; // Оператор виведення даних
        outFile << "Q = " << Q << endl;
        outFile.close();
    } else {
        cout << "Не вдалося відкрити файл для запису!" << endl;
    }

    return 0;
}

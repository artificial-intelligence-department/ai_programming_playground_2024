#include <iostream>
#include <cmath>
using namespace std;
#define M_PI 3.14159265358979323846 // Визначення числа пі вручну
int main() {
    double notebookPrice, pencilPrice;
    int notebookCount, pencilCount;
    cout << "Обчислення вартості покупки.\n";
    cout << "Введіть початкові дані:\n";
    cout << "Ціна зошита (грн.): ";
    cin >> notebookPrice;
    cout << "Кількість зошитів: ";
    cin >> notebookCount;
    cout << "Ціна олівців (грн.): ";
    cin >> pencilPrice;
    cout << "Кількість олівців: ";
    cin >> pencilCount;
    double totalCost = (notebookPrice * notebookCount) + (pencilPrice * pencilCount);
    cout << "Вартість покупки: " << totalCost << " грн.\n";
    double r1, r2, h;
    cout << "\nОбчислення об'єму порожнистого циліндра.\n";
    cout << "Радіус зовнішнього циліндра (r1): ";
    cin >> r1;
    cout << "Радіус внутрішнього отвору (r2): ";
    cin >> r2;
    cout << "Висота циліндра (h): ";
    cin >> h;

    if (r1 <= r2) {
        cout << "Радіус зовнішнього циліндра має бути більшим за радіус внутрішнього отвору.\n";
    } else {
        double volume = M_PI * h * (pow(r1, 2) - pow(r2, 2));
        cout << "Об'єм порожнистого циліндра: " << volume << " куб. од.\n";
    }

    return 0;
}

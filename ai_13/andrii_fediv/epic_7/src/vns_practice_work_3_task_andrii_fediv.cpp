#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>
#include <sstream>

using namespace std;

void overloadedFn() // №12 перевантаження функції // для виклику однієї і тієї самої функції з різними вхідними даними
{
    int U, R; // #1 одна цілочисельна змінна | для збереження напруги та опору
    cout << "Обчислення сили струму в електричному ланцюзі.\n\nВведіть початкові дані:\nНапруга (вольт) > ";
    cin >> U;
    cin.ignore();
    cout << "Опір (Ом) > ";
    cin >> R;
    cin.ignore();
    cout << "Сила струму: " << U / R << " Ампер.\n";
}

void overloadedFn(string line) // №12 перевантаження функції // для виклику однієї і тієї самої функції з різними вхідними даними
{
    replace(line.begin(), line.end(), ',', '.');
    stringstream ss(line);
    double a, b, c, d;
    ss >> a >> b >> c >> d;
    double diff = (a * b) - (c * d);
    cout << "difference is " << diff;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    overloadedFn();
    cout << "\nenter a, b, c & d\n";
    string line;
    getline(cin, line);
    overloadedFn(line);
    // 2,1265123 3,1116743 1,5224222 4,346372
    return 0;
}
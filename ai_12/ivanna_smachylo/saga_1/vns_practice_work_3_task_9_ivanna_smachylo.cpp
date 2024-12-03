#include <iostream>
#include <iomanip> 
#include <fstream>

using namespace std;

int main() 
{

    double r1, r2, r;

    cout << "Обчислення опору електричного ланцюга при паралельному з'єднанні елементів:" << "\n";
    cout << "Введіть початкові дані:" << "\n";
    cout << "Величина першого опору (Ом) > ";
    cin >> r1;
    cout << "Величина другого опору (Ом) > ";
    cin >> r2;

    ofstream file("result.txt");
    while(!file.is_open())
    {
        cerr << "Помилка відкриття файлу!" << "\n";
        return 1;
    }

    //розрахунок загального опору
    if (r1 > 0 && r2 > 0) 
    {
        r = r1 + r2;

        cout << fixed << setprecision(2);
        cout << "Опір ланцюга: " << r << " Ом" << "\n";

        file << fixed << setprecision(2);
        file << "Обчислення опору електричного ланцюга при паралельному з'єднанні елементів:" << "\n";
        file << "Величина першого опору (Ом): " << r1 << "\n";
        file << "Величина другого опору (Ом): " << r2 << "\n";
        file << "Опір ланцюга: " << r << " Ом" << "\n";
    } 

    int pagesTotal = 948;
    int words = 30;
    int letters = 5;
    double width = 2.0;

    int totalWords = pagesTotal * words;
    int totalLetters = totalWords * letters;
    double totalLength = totalLetters * width;

    cout << "Кількість російських слів у словнику: " << totalWords << "\n";
    cout << "Довжина відрізку російських слів(мм): " << totalLength << " мм" << "\n";
    cout << "Довжина відрізку російських слів(м): " << totalLength / 1000 << " м" << "\n";

    file << "Кількість російських слів у словнику: " << totalWords << "\n";
    file << "Довжина відрізку російських слів(мм): " << totalLength << " мм" << "\n";
    file << "Довжина відрізку російських слів(м): " << totalLength / 1000 << " м" << "\n";

    file.close();

    cout << "Ваші результати було записано у файл result.txt" << "\n";

    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int NumofHryvnias = 0; // Оголошуємо змінну, яка позначатиме кількість копюр, й ініцілізуємо.

    int Price; // Введення ціни подарунку.
    cin >> Price;

    int Hryvnias[9] = {500, 200, 100, 50, 20, 10, 5, 2, 1}; // Масив номіналів.

    for (int i = 0; i < 9; i++)
    {
        NumofHryvnias += Price / Hryvnias[i]; // Обраховуємо скільки разів номінав поміщається в ціну. Цикл for,
                                              // щоб перевірити кожен номінал.
                                              // Кількість разів додається до кількості копюр.
        Price %= Hryvnias[i];                 // Решта, яка залишилась після використання більшого номіналу.
    }
    cout << NumofHryvnias;
    return 0;
}
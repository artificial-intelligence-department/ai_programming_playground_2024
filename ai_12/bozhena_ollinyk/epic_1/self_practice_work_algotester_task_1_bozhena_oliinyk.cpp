#include <iostream>
#include <iomanip>   //підключення файлів з бібліотеки
using namespace std; // простір імен для логічного їх групування

int main()
{
    int packs;
    int number;

    cout << "Введіть скільки є пачок печення: (до ста)" << endl;
    cin >> number;
    if (number >= 100)
    {
        cout << "Забагато печива! Введіть іншу кількість" << endl;
        cin >> number;
        packs = number;
    }
    else
    {
        packs = number;
    }

    int cookies[100];
    for (int i = 0; i < packs; ++i)
    {
        cout << "Введіть скільки печення в пачці №" << i << ":" << endl;
        cin >> cookies[i];
    }

    cout << "Кількість печива яку може з'їсти Марічка:" << endl;
    int result = 0;
    for (int i = 0; i < packs; i++)
    {
        result = result + (cookies[i] - 1);
    }
    cout << result;

    return 0;
}
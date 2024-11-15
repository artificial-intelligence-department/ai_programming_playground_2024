#include <iostream>
#include <cmath>

using namespace std;

int power(int number, int n) // рекурсівна функція; number, n - параметри функції
{
    if (n == 1)
    {
        return number;
    }
    return number * power(number, n - 1);
}

int main()
{
    float notebookCost; // Дійсна змінна без подвійної точності бо така точність не потрібна
    float coverCost;
    int setsCount;
    double totalCost;
    do // do while щоб була можливість повторювати поки нормально не введуть дані
    {
        cout << "Enter the notebook cost (in hrivnas) > ";
        cin >> notebookCost;
        cout << "Enter the covers cost (in hrivnas) > ";
        cin >> coverCost;
        cout << "Enter the sets count (in hrivnas) > ";
        cin >> setsCount;
        if (notebookCost < 0 || coverCost < 0)
        {
            cout << "Wrong input. Try again.\n";
        }
        else
        {
            break; // break щоб вийти з циклу
        }
    } while (true);
    totalCost = (notebookCost + coverCost) * setsCount;
    cout << "The total cost is " << totalCost << endl;

    const int r = 3;
    const double V = 3 / 4. * M_PI * power(r, 3); // r - аргумент функції
    const double S = 4 * M_PI * power(r, 2);

    cout << "V = " << V << "\nS = " << S;
}
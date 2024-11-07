#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n); // масив де n - це кількість пачок
    {
        for (int i = 0; i < n; ++i) // i - це порядок елементу(пачки)в цьому масиві
        {
            cin >> a[i];
        }
    }
    long long maxCookies = 0; // ініцілізуємо змінну
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > 0) // перевірка чи в i пачці є печиво, бо Марчіка не зможе з'їсти печиво з порожньої пачки
        {
            maxCookies += a[i] - 1; // визначаємо максимальну кількість печиав, яку Марічка може з'їсти з пачки
        }
    }
    cout << maxCookies << endl; // виводимо максимальну кількість печива, яку Марічка може з'їсти
    return 0;
}
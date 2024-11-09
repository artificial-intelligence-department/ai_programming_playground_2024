#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int N;
    cin >> N;
    vector<int> r(N);

    for (int i = 0; i < N; i++) 
    {
        cin >> r[i];
    }

    if (N == 1) 
    {
        cout << 0 << endl;
        return 0;
    }

    // Ініціалізуємо змінні для найменших та найбільших елементів
    int min1 = 100000, min2 = 100000;
    int max1 = 0, max2 = 0;

    for (int i = 0; i < N; i++) 
    {
        // Оновлюємо найменші елементи
        if (r[i] < min1) 
        {
            min2 = min1;
            min1 = r[i];
        } 
        else if (r[i] < min2)
        {
            min2 = r[i];
        }

        // Оновлюємо найбільші елементи
        if (r[i] > max1) 
        {
            max2 = max1;
            max1 = r[i];
        } 
        else if (r[i] > max2) 
        {
            max2 = r[i];
        }
    }

    // Обчислюємо можливі варіанти мінімальної втоми
    int option1 = max1 - min2; // Видаляємо min1
    int option2 = max2 - min1; // Видаляємо max1

    // Знаходимо мінімальне значення між двома варіантами
    int m = min(option1, option2);

    cout << m << endl;

    return 0;
}

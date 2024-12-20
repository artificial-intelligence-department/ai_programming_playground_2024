// Варіант 14
#include <iostream>
#define MAX 5

using namespace std;

int main()
{
    double number[MAX];
    double sum = 0.0;

    for (int i = 0; i < MAX; i++)
    {
        cout << "Введіть число " << i + 1 << " : ";
        cin >> number[i];

        sum += number[i]; 
        double average = sum / (i + 1); 
        cout << "Середнє значення чисел = " << average << endl;
    }

    return 0;
}

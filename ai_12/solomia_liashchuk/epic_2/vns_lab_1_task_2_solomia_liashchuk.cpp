#include <iostream>
using namespace std;

int main()
{
    float n;
    double m;

    cout << "Введіть число для n: "<< endl;
    cin >> n;
    cout << "Введіть число для m: "<< endl;
    cin >> m;

    double result1D = - -m- ++n;
    float result1F = - -m- ++n;

    double result2D = m * n < n++;
    bool result2F = m * n < n++;

    double result3D = n-- > m++;
    bool result3F = n-- > m++;

    cout << "Результат 1 (double): " << result1D << endl;
    cout << "Результат 1 (float): " << result1F << endl;

    cout << "Результат 2 (double): " << result2D << endl;
    cout << "Результат 2 (float): " << result2F << endl;

    cout << "Результат 3 (double): " << result3D << endl;
    cout << "Результат 3 (float): " << result3F << endl;

    return 0;

}